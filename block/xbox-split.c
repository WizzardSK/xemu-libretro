/*
 * xbox-split: the Xbox hard disk from two images (libretro core, NNshi).
 *
 * The Xbox finds its partitions at fixed offsets of its one IDE disk: the
 * config area at 0, the cache partitions X, Y and Z (750 MB each) from
 * 0x80000, then C, E and F. This driver shows the guest one disk and sends
 * every request in the cache range to the "game" image (one per game) and
 * everything else to "file", the common image (dashboard, saves, F:). Both
 * images keep the disk's offsets, so they are sparse qcow2 images of at least
 * the range they serve.
 *
 * The common image is the primary child: the disk's length, and QEMU's own
 * snapshots (savevm), are its. The game's child is not called "cache":
 * "cache." is the prefix of the block layer's own options (cache.direct,
 * cache.no-flush), which would end up in that child's options.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qapi/error.h"
#include "block/block-io.h"
#include "block/block_int.h"
#include "qobject/qdict.h"
#include "qemu/cutils.h"
#include "qemu/module.h"
#include "qemu/option.h"

#define XBOX_CACHE_START 0x00080000LL              /* X, then Y and Z */
#define XBOX_CACHE_END   (XBOX_CACHE_START + 3 * 0x2EE00000LL)

typedef struct {
    BdrvChild *cache;
} BDRVXboxSplitState;

static int xbox_split_open(BlockDriverState *bs, QDict *options, int flags,
                           Error **errp)
{
    BDRVXboxSplitState *s = bs->opaque;
    int ret;

    ret = bdrv_open_file_child(NULL, options, "file", bs, errp);
    if (ret < 0) {
        return ret;
    }
    s->cache = bdrv_open_child(NULL, options, "game", bs, &child_of_bds,
                               BDRV_CHILD_DATA, false, errp);
    if (!s->cache) {
        return -EINVAL;
    }
    bs->supported_write_flags = BDRV_REQ_FUA;
    bs->supported_zero_flags = BDRV_REQ_MAY_UNMAP;
    return 0;
}

static void xbox_split_close(BlockDriverState *bs)
{
    BDRVXboxSplitState *s = bs->opaque;

    bdrv_graph_wrlock_drained();
    bdrv_unref_child(bs, s->cache);
    s->cache = NULL;
    bdrv_graph_wrunlock();
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
    if (offset < XBOX_CACHE_END) {
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
        int ret = bdrv_co_pwrite_zeroes(c, offset + done, len, flags);
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
    int ret = bdrv_co_flush(s->cache->bs);
    int ret2 = bdrv_co_flush(bs->file->bs);

    return ret < 0 ? ret : ret2;
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
};

static void bdrv_xbox_split_init(void)
{
    bdrv_register(&bdrv_xbox_split);
}

block_init(bdrv_xbox_split_init);
