/*
 * The core's savestates: the machine's state as QEMU's migration stream
 * (the CPU, every device and all of the guest's RAM, the GPU's pending work
 * flushed into it when the machine stops), written into the frontend's
 * buffer and read back from it, so RetroArch's state files and slots hold
 * the whole state. The same stream xemu's snapshots write, here into
 * memory instead of the HDD image (after parallel-xbox's
 * ui/libretro-state.c, NNshi).
 *
 * The HDD's contents are not in it: a state would otherwise carry every
 * write the game made to the disk (its cache partitions alone are 2.25 GB).
 * A state loaded after the game has written to the disk since it was saved
 * meets a disk newer than the guest's view of it, as on a real console
 * whose memory was rewound.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/cutils.h"
#include "qapi/error.h"
#include "exec/cpu-common.h"
#include "exec/target_page.h"
#include "io/channel-buffer.h"
#include "migration/qemu-file.h"
#include "migration/savevm.h"
#include "migration/migration.h"
#include "migration/global_state.h"
#include "system/runstate.h"
#include "system/system.h"
#include "block/block.h"
#include "libretro-state.h"

/*
 * The state: a header, then the migration stream. Little-endian.
 */
#define LR_STATE_MAGIC   "XEMUSTAT"
#define LR_STATE_VERSION 1

typedef struct LRStateHeader {
    char magic[8];
    uint32_t version;
    uint32_t reserved;
    uint64_t stream_len;
} LRStateHeader;

/* Room for everything but RAM: the devices' sections, about 5.5 MB in
 * parallel-xbox (the GPU 4.3 MB, the APU 1.1 MB), nearly all of it arrays
 * of fixed size */
#define LR_STATE_DEVICES_MAX (8 * 1024 * 1024)

int qemu_savevm_state_libretro(QEMUFile *f, Error **errp);

static int lr_state_ram_bound(RAMBlock *rb, void *opaque)
{
    size_t *sum = opaque;
    uint64_t pages = DIV_ROUND_UP(qemu_ram_get_used_length(rb),
                                  qemu_target_page_size());

    /* each page as its header and its data, at worst; and the block's id
     * where the stream turns to it */
    *sum += pages * (qemu_target_page_size() + 16) + 512;
    return 0;
}

size_t lr_state_size(void)
{
    size_t sum = sizeof(LRStateHeader) + LR_STATE_DEVICES_MAX;

    RCU_READ_LOCK_GUARD();
    foreach_not_ignored_block(lr_state_ram_bound, &sum);
    return sum;
}

bool lr_state_save(void *data, size_t size, Error **errp)
{
    LRStateHeader hdr;
    QIOChannelBuffer *bioc;
    QEMUFile *f;
    RunState saved_state = runstate_get();
    size_t stream_len = 0;
    int ret, ret2;

    if (size < sizeof(hdr)) {
        error_setg(errp, "no room for the state's header");
        return false;
    }

    global_state_store();
    /* the GPU halts and puts what it drew back in the guest's RAM */
    vm_stop(RUN_STATE_SAVE_VM);
    bdrv_drain_all_begin();

    bioc = qio_channel_buffer_new(size - sizeof(hdr));
    f = qemu_file_new_output(QIO_CHANNEL(bioc));
    ret = qemu_savevm_state_libretro(f, errp);
    ret2 = qemu_fflush(f);
    if (ret == 0 && ret2 < 0) {
        error_setg_errno(errp, -ret2, "writing the state failed");
        ret = ret2;
    }
    if (ret == 0) {
        stream_len = bioc->usage;
        if (stream_len > size - sizeof(hdr)) {
            error_setg(errp, "the state (%zu bytes) is bigger than the "
                       "frontend's buffer (%zu)", stream_len,
                       size - sizeof(hdr));
            ret = -ENOSPC;
        } else {
            memcpy((uint8_t *)data + sizeof(hdr), bioc->data, stream_len);
        }
    }
    qemu_fclose(f);
    object_unref(OBJECT(bioc));

    bdrv_drain_all_end();
    vm_resume(saved_state);

    if (ret == 0) {
        memcpy(hdr.magic, LR_STATE_MAGIC, sizeof(hdr.magic));
        hdr.version = cpu_to_le32(LR_STATE_VERSION);
        hdr.reserved = 0;
        hdr.stream_len = cpu_to_le64(stream_len);
        memcpy(data, &hdr, sizeof(hdr));
        /* the frontend's buffer is as big as the state can get: the rest
         * is zero, not whatever was in it */
        memset((uint8_t *)data + sizeof(hdr) + stream_len, 0,
               size - sizeof(hdr) - stream_len);
    }
    return ret == 0;
}

bool lr_state_load(const void *data, size_t size, Error **errp)
{
    MigrationIncomingState *mis = migration_incoming_get_current();
    LRStateHeader hdr;
    QIOChannelBuffer *bioc;
    QEMUFile *f;
    bool was_running = runstate_is_running();
    uint64_t len;
    int ret;

    if (size < sizeof(hdr)) {
        error_setg(errp, "not a state of this core");
        return false;
    }
    memcpy(&hdr, data, sizeof(hdr));
    len = le64_to_cpu(hdr.stream_len);
    if (memcmp(hdr.magic, LR_STATE_MAGIC, sizeof(hdr.magic)) != 0) {
        error_setg(errp, "not a state of this core (states of earlier "
                   "builds were kept in the HDD image)");
        return false;
    }
    if (le32_to_cpu(hdr.version) != LR_STATE_VERSION ||
        len > size - sizeof(hdr)) {
        error_setg(errp, "the state is of another version or cut short");
        return false;
    }

    vm_stop(RUN_STATE_RESTORE_VM);
    bdrv_drain_all_begin();
    qemu_system_reset(SHUTDOWN_CAUSE_SNAPSHOT_LOAD);

    bioc = qio_channel_buffer_new(len);
    memcpy(bioc->data, (const uint8_t *)data + sizeof(hdr), len);
    bioc->usage = len;
    f = qemu_file_new_input(QIO_CHANNEL(bioc));
    object_unref(OBJECT(bioc)); /* the file holds the channel now */
    mis->from_src_file = f;
    ret = qemu_loadvm_state(f, errp);
    /* closes f, as load_snapshot() has it */
    migration_incoming_state_destroy();

    bdrv_drain_all_end();
    if (was_running) {
        vm_start();
    }
    return ret == 0;
}
