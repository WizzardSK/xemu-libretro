/*
 * xbox-split: the Xbox hard disk from two images (libretro core, NNshi).
 *
 * The Xbox finds its partitions at fixed offsets of its one IDE disk: the
 * config area at 0, the cache partitions X, Y and Z (750 MB each) from
 * 0x80000, then C, E and F. This driver shows the guest one disk and sends
 * every request in the cache range to the "game" image (one per game) and
 * everything else to "file", the common image (dashboard, saves, F:). Both
 * images keep the disk's offsets, so they are sparse qcow2 images of at least
 * the range they serve. Without a game image (the dashboard) the cache range
 * is the common image's own.
 *
 * QEMU's machine is built once in the core's process, so the game image is
 * swapped when the next content starts (xbox_split_set_game), with the
 * machine stopped.
 *
 * The common image is the primary child: the disk's length, and QEMU's own
 * qcow2 snapshots (savevm; Trim HDD looks for them), are its. The snapshot
 * calls are passed to it here: QEMU's own fallback refuses a node with a
 * second data child, and would reopen the game image the disk was opened
 * with. The game's child is not called "cache":
 * "cache." is the prefix of the block layer's own options (cache.direct,
 * cache.no-flush), which would end up in that child's options.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qapi/error.h"
#include "block/block-io.h"
#include "block/block_int.h"
#include "block/snapshot.h"
#include "qobject/qdict.h"
#include "qemu/cutils.h"
#include "qemu/module.h"
#include "qemu/option.h"

#define XBOX_CACHE_START 0x00080000LL              /* X, then Y and Z */
#define XBOX_CACHE_END   (XBOX_CACHE_START + 3 * 0x2EE00000LL)

typedef struct {
    BdrvChild *cache;
} BDRVXboxSplitState;

/* Profiler: Game Cache Disk (ui/libretro.c): per cache partition (X, Y, Z),
 * the bytes read, the bytes read where the image holding the partition has
 * nothing (never written: a game that does not find its cache reads there),
 * the bytes written and the bytes zeroed. Counted while
 * xbox_split_stats_on. */
int xbox_split_stats_on;
uint64_t xbox_split_stats[3][4];
enum { XS_READ, XS_FRESH, XS_WRITE, XS_ZERO };

static int xbox_split_part(int64_t offset)
{
    return MIN(2, (offset - XBOX_CACHE_START) / 0x2EE00000LL);
}

static void xbox_split_count(int64_t offset, int64_t bytes, int what)
{
    if (offset >= XBOX_CACHE_START && offset < XBOX_CACHE_END) {
        __atomic_add_fetch(&xbox_split_stats[xbox_split_part(offset)][what],
                           bytes, __ATOMIC_RELAXED);
    }
}

/* the part of [offset, offset + bytes) the child holds no data for */
static int64_t coroutine_fn GRAPH_RDLOCK
xbox_split_unallocated(BdrvChild *c, int64_t offset, int64_t bytes)
{
    int64_t fresh = 0;
    while (bytes > 0) {
        int64_t pnum = 0;
        int ret = bdrv_co_is_allocated(c->bs, offset, bytes, &pnum);
        if (ret < 0 || pnum <= 0) {
            break;
        }
        if (!ret) {
            fresh += pnum;
        }
        offset += pnum;
        bytes -= pnum;
    }
    return fresh;
}

static int xbox_split_open(BlockDriverState *bs, QDict *options, int flags,
                           Error **errp)
{
    ERRP_GUARD();
    BDRVXboxSplitState *s = bs->opaque;
    int ret;

    ret = bdrv_open_file_child(NULL, options, "file", bs, errp);
    if (ret < 0) {
        return ret;
    }
    s->cache = bdrv_open_child(NULL, options, "game", bs, &child_of_bds,
                               BDRV_CHILD_DATA, true, errp);
    if (*errp) {
        return -EINVAL;
    }
    bs->supported_write_flags = BDRV_REQ_FUA;
    bs->supported_zero_flags = BDRV_REQ_MAY_UNMAP;
    return 0;
}

static void xbox_split_close(BlockDriverState *bs)
{
    BDRVXboxSplitState *s = bs->opaque;

    if (s->cache) {
        bdrv_graph_wrlock_drained();
        bdrv_unref_child(bs, s->cache);
        s->cache = NULL;
        bdrv_graph_wrunlock();
    }
}

static int64_t coroutine_fn GRAPH_RDLOCK
xbox_split_co_getlength(BlockDriverState *bs)
{
    return bdrv_co_getlength(bs->file->bs);
}

/* The child that serves offset, and how many of bytes it serves from there */
static BdrvChild *xbox_split_route(BlockDriverState *bs, int64_t offset,
                                   int64_t bytes, int64_t *len)
{
    BDRVXboxSplitState *s = bs->opaque;

    if (offset < XBOX_CACHE_START) {
        *len = MIN(bytes, XBOX_CACHE_START - offset);
        return bs->file;
    }
    if (offset < XBOX_CACHE_END && s->cache) {
        *len = MIN(bytes, XBOX_CACHE_END - offset);
        return s->cache;
    }
    *len = bytes;
    return bs->file;
}

static int coroutine_fn GRAPH_RDLOCK
xbox_split_co_preadv(BlockDriverState *bs, int64_t offset, int64_t bytes,
                     QEMUIOVector *qiov, BdrvRequestFlags flags)
{
    int64_t done = 0;

    while (done < bytes) {
        int64_t len;
        BdrvChild *c = xbox_split_route(bs, offset + done, bytes - done, &len);
        QEMUIOVector part;
        int ret;

        if (qatomic_read(&xbox_split_stats_on)) {
            xbox_split_count(offset + done, len, XS_READ);
            if (offset + done >= XBOX_CACHE_START &&
                offset + done < XBOX_CACHE_END) {
                xbox_split_count(offset + done,
                                 xbox_split_unallocated(c, offset + done, len),
                                 XS_FRESH);
            }
        }
        qemu_iovec_init_slice(&part, qiov, done, len);
        ret = bdrv_co_preadv(c, offset + done, len, &part, flags);
        qemu_iovec_destroy(&part);
        if (ret < 0) {
            return ret;
        }
        done += len;
    }
    return 0;
}

static int coroutine_fn GRAPH_RDLOCK
xbox_split_co_pwritev(BlockDriverState *bs, int64_t offset, int64_t bytes,
                      QEMUIOVector *qiov, BdrvRequestFlags flags)
{
    int64_t done = 0;

    while (done < bytes) {
        int64_t len;
        BdrvChild *c = xbox_split_route(bs, offset + done, bytes - done, &len);
        QEMUIOVector part;
        int ret;

        if (qatomic_read(&xbox_split_stats_on)) {
            xbox_split_count(offset + done, len, XS_WRITE);
        }
        qemu_iovec_init_slice(&part, qiov, done, len);
        ret = bdrv_co_pwritev(c, offset + done, len, &part, flags);
        qemu_iovec_destroy(&part);
        if (ret < 0) {
            return ret;
        }
        done += len;
    }
    return 0;
}

static int coroutine_fn GRAPH_RDLOCK
xbox_split_co_pwrite_zeroes(BlockDriverState *bs, int64_t offset,
                            int64_t bytes, BdrvRequestFlags flags)
{
    int64_t done = 0;

    while (done < bytes) {
        int64_t len;
        BdrvChild *c = xbox_split_route(bs, offset + done, bytes - done, &len);
        int ret;
        if (qatomic_read(&xbox_split_stats_on)) {
            xbox_split_count(offset + done, len, XS_ZERO);
        }
        ret = bdrv_co_pwrite_zeroes(c, offset + done, len, flags);
        if (ret < 0) {
            return ret;
        }
        done += len;
    }
    return 0;
}

static int coroutine_fn GRAPH_RDLOCK
xbox_split_co_pdiscard(BlockDriverState *bs, int64_t offset, int64_t bytes)
{
    int64_t done = 0;

    while (done < bytes) {
        int64_t len;
        BdrvChild *c = xbox_split_route(bs, offset + done, bytes - done, &len);
        int ret = bdrv_co_pdiscard(c, offset + done, len);
        if (ret < 0) {
            return ret;
        }
        done += len;
    }
    return 0;
}

static int coroutine_fn GRAPH_RDLOCK xbox_split_co_flush(BlockDriverState *bs)
{
    BDRVXboxSplitState *s = bs->opaque;
    int ret = s->cache ? bdrv_co_flush(s->cache->bs) : 0;
    int ret2 = bdrv_co_flush(bs->file->bs);

    return ret < 0 ? ret : ret2;
}

/* A game's cache image, created empty when it is not there yet: the Xbox
 * formats a cache partition it does not recognise when the game mounts it.
 * Sparse, as long as the range it serves. Needs QEMU's main loop. */
int xbox_split_create_game(const char *path, Error **errp)
{
    ERRP_GUARD();

    if (g_file_test(path, G_FILE_TEST_EXISTS)) {
        return 0;
    }
    bdrv_img_create(path, "qcow2", NULL, NULL, NULL, XBOX_CACHE_END, 0, true,
                    errp);
    return *errp ? -1 : 0;
}

/* Puts the game image at path (NULL: none, the dashboard) in place of the
 * one the disk has, for the next content on the machine that is there.
 * Called with the BQL held and the machine stopped. */
int xbox_split_set_game(BlockDriverState *bs, const char *path, Error **errp)
{
    BDRVXboxSplitState *s;
    BlockDriverState *game = NULL;

    GLOBAL_STATE_CODE();
    if (!bs || !bs->drv || strcmp(bs->drv->format_name, "xbox-split")) {
        error_setg(errp, "the hard disk is not an xbox-split node");
        return -1;
    }
    s = bs->opaque;
    if (path) {
        QDict *opts;

        if (xbox_split_create_game(path, errp) < 0) {
            return -1;
        }
        opts = qdict_new();
        qdict_put_str(opts, "driver", "qcow2");
        game = bdrv_open(path, NULL, opts, BDRV_O_RDWR, errp);
        if (!game) {
            return -1;
        }
    }

    bdrv_graph_wrlock_drained();
    if (s->cache) {
        bdrv_unref_child(bs, s->cache);
        s->cache = NULL;
    }
    if (game) {
        /* takes over the reference bdrv_open gave */
        s->cache = bdrv_attach_child(bs, game, "game", &child_of_bds,
                                     BDRV_CHILD_DATA, errp);
    }
    bdrv_graph_wrunlock();
    return game && !s->cache ? -1 : 0;
}

static int GRAPH_RDLOCK
xbox_split_snapshot_create(BlockDriverState *bs, QEMUSnapshotInfo *sn_info)
{
    return bdrv_snapshot_create(bs->file->bs, sn_info);
}

static int GRAPH_UNLOCKED
xbox_split_snapshot_goto(BlockDriverState *bs, const char *snapshot_id)
{
    Error *err = NULL;
    BlockDriverState *file;
    int ret;

    bdrv_graph_rdlock_main_loop();
    file = bs->file->bs;
    bdrv_graph_rdunlock_main_loop();
    ret = bdrv_snapshot_goto(file, snapshot_id, &err);
    error_free(err);
    return ret;
}

static int GRAPH_RDLOCK
xbox_split_snapshot_delete(BlockDriverState *bs, const char *snapshot_id,
                           const char *name, Error **errp)
{
    return bdrv_snapshot_delete(bs->file->bs, snapshot_id, name, errp);
}

static int GRAPH_RDLOCK
xbox_split_snapshot_list(BlockDriverState *bs, QEMUSnapshotInfo **psn_info)
{
    return bdrv_snapshot_list(bs->file->bs, psn_info);
}

static int GRAPH_RDLOCK
xbox_split_snapshot_load_tmp(BlockDriverState *bs, const char *snapshot_id,
                             const char *name, Error **errp)
{
    return bdrv_snapshot_load_tmp(bs->file->bs, snapshot_id, name, errp);
}

static char *xbox_split_dirname(BlockDriverState *bs, Error **errp)
{
    error_setg(errp, "Cannot generate a base directory for xbox-split nodes");
    return NULL;
}

static BlockDriver bdrv_xbox_split = {
    .format_name                = "xbox-split",
    .instance_size              = sizeof(BDRVXboxSplitState),

    .bdrv_open                  = xbox_split_open,
    .bdrv_close                 = xbox_split_close,
    .bdrv_child_perm            = bdrv_default_perms,
    .bdrv_co_getlength          = xbox_split_co_getlength,
    .bdrv_dirname               = xbox_split_dirname,

    .bdrv_co_preadv             = xbox_split_co_preadv,
    .bdrv_co_pwritev            = xbox_split_co_pwritev,
    .bdrv_co_pwrite_zeroes      = xbox_split_co_pwrite_zeroes,
    .bdrv_co_pdiscard           = xbox_split_co_pdiscard,
    .bdrv_co_flush              = xbox_split_co_flush,

    .bdrv_snapshot_create       = xbox_split_snapshot_create,
    .bdrv_snapshot_goto         = xbox_split_snapshot_goto,
    .bdrv_snapshot_delete       = xbox_split_snapshot_delete,
    .bdrv_snapshot_list         = xbox_split_snapshot_list,
    .bdrv_snapshot_load_tmp     = xbox_split_snapshot_load_tmp,
};

static void bdrv_xbox_split_init(void)
{
    bdrv_register(&bdrv_xbox_split);
}

block_init(bdrv_xbox_split_init);
