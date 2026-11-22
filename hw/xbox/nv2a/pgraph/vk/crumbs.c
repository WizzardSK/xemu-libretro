/*
 * Geforce NV2A PGRAPH Vulkan Renderer: the device lost report
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/*
 * With Debug > Vulkan: Device Lost Report on, every piece of work the
 * renderer records (the debug markers' labels: draws, clears, uploads,
 * downloads, conversions, the display render, and every render pass begun)
 * gets a breadcrumb: an id, numbered across all command buffers, and its
 * label kept here. Where the device has VK_AMD_buffer_marker, the GPU writes
 * the id into host-visible memory twice per command buffer: when the work
 * reaches the top of the pipe (started) and when all work before it has
 * finished (finished). With VK_NV_device_diagnostic_checkpoints the queue
 * keeps the last checkpoints itself. When a Vulkan call returns
 * VK_ERROR_DEVICE_LOST (VK_CHECK), the report lists the call, the last
 * submits with their command buffers' breadcrumb ranges, the work between
 * finished and started in each (what the GPU was doing when it was lost),
 * and VK_EXT_device_fault's description where the driver has one.
 */

#include "qemu/osdep.h"
#include "qemu/thread.h"
#include "renderer.h"
#include "debug.h"

#define CRUMB_RING 8192
#define CRUMB_TEXT 120
#define SUBMIT_RING 16
/* main and staging-sync per slot, aux, and any other command buffer */
#define CRUMB_BUFS (2 * PGRAPH_VK_SLOTS + 2)

typedef struct Crumb {
    uint32_t id;
    uint8_t buf;
    uint32_t submit;    /* the renderer's submit count when recorded */
    char text[CRUMB_TEXT];
} Crumb;

typedef struct SubmitRec {
    uint64_t seq;
    int64_t time_us;
    uint32_t submit;
    uint8_t nbuf;
    uint8_t buf[4];
    uint32_t first[4], last[4]; /* breadcrumb ids; first > last: none */
} SubmitRec;

static struct {
    bool on;
    PGRAPHVkState *r;
    QemuMutex lock;
    Crumb *ring;
    uint32_t next_id;
    /* per command buffer: breadcrumbs recorded since its last submit */
    bool open[CRUMB_BUFS];
    uint32_t first[CRUMB_BUFS], last[CRUMB_BUFS];
    SubmitRec submits[SUBMIT_RING];
    uint64_t submit_seq;
    /* the GPU's writes: started and finished id per command buffer */
    VkBuffer marker_buf;
    VmaAllocation marker_alloc;
    volatile uint32_t *markers;
    PFN_vkCmdWriteBufferMarkerAMD write_marker;
    PFN_vkCmdSetCheckpointNV set_checkpoint;
    PFN_vkGetQueueCheckpointDataNV get_checkpoints;
#ifdef VK_EXT_device_fault
    PFN_vkGetDeviceFaultInfoEXT get_fault;
#endif
    char *path;
    bool reported;
} cr;

static const char *const buf_names[] = {
    "main", "staging-sync", "aux", "other",
};

static int buf_index(PGRAPHVkState *r, VkCommandBuffer cmd)
{
    for (int s = 0; s < PGRAPH_VK_SLOTS; s++) {
        if (cmd == r->slot_main[s]) {
            return s;
        }
        if (cmd == r->slot_sync[s]) {
            return PGRAPH_VK_SLOTS + s;
        }
    }
    return cmd == r->aux_command_buffer ? 2 * PGRAPH_VK_SLOTS
                                        : 2 * PGRAPH_VK_SLOTS + 1;
}

/* "main 0", "staging-sync 1", "aux", "other" */
static const char *buf_label(int b, char *out, size_t n)
{
    if (b < 2 * PGRAPH_VK_SLOTS) {
        snprintf(out, n, "%s %d", buf_names[b < PGRAPH_VK_SLOTS ? 0 : 1],
                 b % PGRAPH_VK_SLOTS);
    } else {
        snprintf(out, n, "%s", buf_names[b == 2 * PGRAPH_VK_SLOTS ? 2 : 3]);
    }
    return out;
}

bool pgraph_vk_crumbs_on(void)
{
    return cr.on;
}

void pgraph_vk_crumbs_init(PGRAPHVkState *r)
{
#ifdef LIBRETRO
    const XemuLibretroVk *s = &xemu_libretro_vk;

    if (!s->active || !s->lost_report) {
        return;
    }
    memset(&cr, 0, sizeof(cr));
    cr.r = r;
    qemu_mutex_init(&cr.lock);
    cr.ring = g_new0(Crumb, CRUMB_RING);
    cr.next_id = 1;
    cr.path = g_strdup(s->lost_report_path);

    if (s->buffer_marker) {
        cr.write_marker = (PFN_vkCmdWriteBufferMarkerAMD)vkGetDeviceProcAddr(
            r->device, "vkCmdWriteBufferMarkerAMD");
    }
    if (s->checkpoints) {
        cr.set_checkpoint = (PFN_vkCmdSetCheckpointNV)vkGetDeviceProcAddr(
            r->device, "vkCmdSetCheckpointNV");
        cr.get_checkpoints =
            (PFN_vkGetQueueCheckpointDataNV)vkGetDeviceProcAddr(
                r->device, "vkGetQueueCheckpointDataNV");
        if (!cr.set_checkpoint || !cr.get_checkpoints) {
            cr.set_checkpoint = NULL;
            cr.get_checkpoints = NULL;
        }
    }
#ifdef VK_EXT_device_fault
    if (s->device_fault) {
        cr.get_fault = (PFN_vkGetDeviceFaultInfoEXT)vkGetDeviceProcAddr(
            r->device, "vkGetDeviceFaultInfoEXT");
    }
#endif

    if (cr.write_marker) {
        VkBufferCreateInfo bci = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
            .size = CRUMB_BUFS * 2 * sizeof(uint32_t),
            .usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT,
            .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
        };
        VmaAllocationCreateInfo aci = {
            .usage = VMA_MEMORY_USAGE_AUTO,
            .flags = VMA_ALLOCATION_CREATE_HOST_ACCESS_RANDOM_BIT |
                     VMA_ALLOCATION_CREATE_MAPPED_BIT,
            .requiredFlags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                             VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        };
        VmaAllocationInfo info;
        if (vmaCreateBuffer(r->allocator, &bci, &aci, &cr.marker_buf,
                            &cr.marker_alloc, &info) == VK_SUCCESS) {
            cr.markers = info.pMappedData;
            memset((void *)cr.markers, 0, bci.size);
        } else {
            cr.write_marker = NULL;
        }
    }
    cr.on = true;
    fprintf(stderr,
            "Vulkan device lost report on: buffer markers %s, checkpoints %s, "
            "device fault %s, report to %s\n",
            cr.write_marker ? "yes" : "no", cr.set_checkpoint ? "yes" : "no",
#ifdef VK_EXT_device_fault
            cr.get_fault ? "yes" : "no",
#else
            "not in this build's headers",
#endif
            cr.path ? cr.path : "(none)");
#endif
}

void pgraph_vk_crumbs_finalize(PGRAPHVkState *r)
{
    if (!cr.on) {
        return;
    }
    cr.on = false;
    if (cr.marker_buf) {
        vmaDestroyBuffer(r->allocator, cr.marker_buf, cr.marker_alloc);
    }
    g_free(cr.ring);
    g_free(cr.path);
    qemu_mutex_destroy(&cr.lock);
    memset(&cr, 0, sizeof(cr));
}

void pgraph_vk_crumb_v(PGRAPHVkState *r, VkCommandBuffer cmd,
                       const char *fmt, va_list ap)
{
    if (!cr.on || cmd == VK_NULL_HANDLE) {
        return;
    }
    int b = buf_index(r, cmd);

    qemu_mutex_lock(&cr.lock);
    uint32_t id = cr.next_id++;
    Crumb *c = &cr.ring[id % CRUMB_RING];
    c->id = id;
    c->buf = b;
    c->submit = r->submit_count;
    vsnprintf(c->text, sizeof(c->text), fmt, ap);
    if (!cr.open[b]) {
        cr.open[b] = true;
        cr.first[b] = id;
    }
    cr.last[b] = id;
    qemu_mutex_unlock(&cr.lock);

    if (cr.write_marker) {
        VkDeviceSize off = b * 2 * sizeof(uint32_t);
        cr.write_marker(cmd, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                        cr.marker_buf, off, id);
        cr.write_marker(cmd, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                        cr.marker_buf, off + sizeof(uint32_t), id);
    }
    if (cr.set_checkpoint) {
        cr.set_checkpoint(cmd, (void *)(uintptr_t)id);
    }
}

void pgraph_vk_crumb(PGRAPHVkState *r, VkCommandBuffer cmd,
                     const char *fmt, ...)
{
    va_list ap;

    if (!cr.on) {
        return;
    }
    va_start(ap, fmt);
    pgraph_vk_crumb_v(r, cmd, fmt, ap);
    va_end(ap);
}

void pgraph_vk_crumbs_submit(PGRAPHVkState *r, uint32_t count,
                             const VkSubmitInfo *submits)
{
    if (!cr.on) {
        return;
    }
    qemu_mutex_lock(&cr.lock);
    SubmitRec *s = &cr.submits[cr.submit_seq % SUBMIT_RING];
    memset(s, 0, sizeof(*s));
    s->seq = ++cr.submit_seq;
    s->time_us = g_get_monotonic_time();
    s->submit = r->submit_count;
    for (uint32_t i = 0; i < count; i++) {
        for (uint32_t j = 0; j < submits[i].commandBufferCount; j++) {
            int b = buf_index(r, submits[i].pCommandBuffers[j]);
            if (s->nbuf < ARRAY_SIZE(s->buf)) {
                s->buf[s->nbuf] = b;
                s->first[s->nbuf] = cr.open[b] ? cr.first[b] : 1;
                s->last[s->nbuf] = cr.open[b] ? cr.last[b] : 0;
                s->nbuf++;
            }
            cr.open[b] = false;
        }
    }
    qemu_mutex_unlock(&cr.lock);
}

static const Crumb *crumb_get(uint32_t id)
{
    const Crumb *c = &cr.ring[id % CRUMB_RING];
    return c->id == id ? c : NULL;
}

static void print_crumb(FILE *f, const char *mark, uint32_t id)
{
    const Crumb *c = crumb_get(id);
    char name[32];

    if (!c) {
        fprintf(f, "  %s #%u (no longer kept)\n", mark, id);
        return;
    }
    fprintf(f, "  %s #%u [%s, submit %u] %s\n", mark, id,
            buf_label(c->buf, name, sizeof(name)), c->submit, c->text);
}

static const char *result_name(int res)
{
    switch (res) {
    case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
    case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
    case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
    default: return "VkResult";
    }
}

static void report_markers(FILE *f, PGRAPHVkState *r)
{
    if (!cr.markers) {
        fprintf(f, "\nNo buffer markers (VK_AMD_buffer_marker): the GPU's "
                   "progress per command buffer is unknown.\n");
        return;
    }
    fprintf(f, "\nGPU progress per command buffer (the latest submit of "
               "each):\n");
    bool seen[CRUMB_BUFS] = { false };
    for (int k = 0; k < SUBMIT_RING; k++) {
        if (cr.submit_seq < (uint64_t)k + 1) {
            break;
        }
        const SubmitRec *s = &cr.submits[(cr.submit_seq - 1 - k) % SUBMIT_RING];
        for (int i = 0; i < s->nbuf; i++) {
            int b = s->buf[i];
            char name[32];
            if (seen[b] || s->first[i] > s->last[i]) {
                continue;
            }
            seen[b] = true;
            uint32_t started = cr.markers[2 * b];
            uint32_t finished = cr.markers[2 * b + 1];
            fprintf(f, "\n%s, submit %" PRIu64 " (breadcrumbs #%u-#%u): "
                       "started #%u, finished #%u: ",
                    buf_label(b, name, sizeof(name)), s->seq, s->first[i], s->last[i], started, finished);
            if (finished >= s->last[i]) {
                fprintf(f, "all done\n");
                continue;
            }
            if (started < s->first[i]) {
                fprintf(f, "not begun\n");
                continue;
            }
            fprintf(f, "IN FLIGHT\n");
            uint32_t from = MAX(s->first[i], finished > 3 ? finished - 3 : 1);
            uint32_t to = MIN(s->last[i], started + 2);
            for (uint32_t id = from; id <= to; id++) {
                const Crumb *c = crumb_get(id);
                if (c && c->buf != b) {
                    continue;
                }
                print_crumb(f,
                            id <= finished ? "done   " :
                            id <= started  ? "RUNNING" : "next   ", id);
            }
        }
    }
}

static void report_checkpoints(FILE *f, PGRAPHVkState *r)
{
    if (!cr.get_checkpoints) {
        return;
    }
    uint32_t n = 0;
    cr.get_checkpoints(r->queue, &n, NULL);
    fprintf(f, "\nQueue checkpoints (VK_NV_device_diagnostic_checkpoints): "
               "%u\n", n);
    if (!n) {
        return;
    }
    VkCheckpointDataNV *d = g_new0(VkCheckpointDataNV, n);
    for (uint32_t i = 0; i < n; i++) {
        d[i].sType = VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV;
    }
    cr.get_checkpoints(r->queue, &n, d);
    for (uint32_t i = 0; i < n; i++) {
        char mark[48];
        snprintf(mark, sizeof(mark), "stage 0x%x",
                 (unsigned)d[i].stage);
        print_crumb(f, mark, (uint32_t)(uintptr_t)d[i].pCheckpointMarker);
    }
    g_free(d);
}

static void report_fault(FILE *f, PGRAPHVkState *r)
{
#ifdef VK_EXT_device_fault
    if (!cr.get_fault) {
        fprintf(f, "\nNo VK_EXT_device_fault on this device.\n");
        return;
    }
    VkDeviceFaultCountsEXT counts = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT,
    };
    VkResult res = cr.get_fault(r->device, &counts, NULL);
    if (res != VK_SUCCESS && res != VK_INCOMPLETE) {
        fprintf(f, "\nvkGetDeviceFaultInfoEXT: %d\n", res);
        return;
    }
    VkDeviceFaultInfoEXT info = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT,
    };
    counts.vendorBinarySize = 0;
    info.pAddressInfos = g_new0(VkDeviceFaultAddressInfoEXT,
                                counts.addressInfoCount + 1);
    info.pVendorInfos = g_new0(VkDeviceFaultVendorInfoEXT,
                               counts.vendorInfoCount + 1);
    res = cr.get_fault(r->device, &counts, &info);
    fprintf(f, "\nDevice fault (VK_EXT_device_fault, %d): %s\n", res,
            info.description);
    for (uint32_t i = 0; i < counts.addressInfoCount; i++) {
        const VkDeviceFaultAddressInfoEXT *a = &info.pAddressInfos[i];
        fprintf(f, "  address type %d: 0x%" PRIx64 " +/- 0x%" PRIx64 "\n",
                a->addressType, (uint64_t)a->reportedAddress,
                (uint64_t)a->addressPrecision);
    }
    for (uint32_t i = 0; i < counts.vendorInfoCount; i++) {
        const VkDeviceFaultVendorInfoEXT *v = &info.pVendorInfos[i];
        fprintf(f, "  vendor: %s (code 0x%" PRIx64 ", data 0x%" PRIx64 ")\n",
                v->description, (uint64_t)v->vendorFaultCode,
                (uint64_t)v->vendorFaultData);
    }
    g_free(info.pAddressInfos);
    g_free(info.pVendorInfos);
#else
    fprintf(f, "\nVK_EXT_device_fault is not in this build's headers.\n");
#endif
}

void pgraph_vk_device_lost(const char *call, const char *file, int line,
                           int result)
{
    g_autofree char *msg = g_strdup_printf("Vulkan: %s (%d) from %s at %s:%d",
                                           result_name(result), result, call,
                                           file, line);
    fprintf(stderr, "%s\n", msg);
#ifdef LIBRETRO
    xemu_libretro_vk_log_error(msg);
#endif
    if (!cr.on || cr.reported) {
        return;
    }
    cr.reported = true;

    PGRAPHVkState *r = cr.r;
    FILE *f = cr.path ? g_fopen(cr.path, "w") : NULL;
    if (!f) {
        fprintf(stderr, "Vulkan device lost report: cannot write %s\n",
                cr.path ? cr.path : "(no path)");
        return;
    }
    qemu_mutex_lock(&cr.lock);
    fprintf(f, "# xemu Vulkan device lost report\n");
    fprintf(f, "# GPU %s, driver version 0x%x, API 0x%x\n",
            r->device_props.deviceName, r->device_props.driverVersion,
            r->device_props.apiVersion);
    fprintf(f, "# %s (%d) returned by %s\n#   at %s:%d\n",
            result_name(result), result, call, file, line);
    fprintf(f, "# renderer submits %u, breadcrumbs %u, render pass open %d, "
               "aux in flight %d\n",
            r->submit_count, cr.next_id - 1, r->in_render_pass,
            r->aux_in_flight);

    int64_t now = g_get_monotonic_time();
    fprintf(f, "\nLast submits, newest first:\n");
    for (int k = 0; k < SUBMIT_RING; k++) {
        if (cr.submit_seq < (uint64_t)k + 1) {
            break;
        }
        const SubmitRec *s = &cr.submits[(cr.submit_seq - 1 - k) % SUBMIT_RING];
        fprintf(f, "  submit %" PRIu64 ", %.1f ms ago:", s->seq,
                (now - s->time_us) / 1000.0);
        for (int i = 0; i < s->nbuf; i++) {
            char name[32];
            fprintf(f, " %s", buf_label(s->buf[i], name, sizeof(name)));
            if (s->first[i] <= s->last[i]) {
                fprintf(f, " (#%u-#%u)", s->first[i], s->last[i]);
            } else {
                fprintf(f, " (no breadcrumbs)");
            }
        }
        fprintf(f, "\n");
    }

    report_markers(f, r);
    report_checkpoints(f, r);
    report_fault(f, r);

    fprintf(f, "\nLast 40 breadcrumbs recorded:\n");
    uint32_t last = cr.next_id - 1;
    for (uint32_t id = last > 40 ? last - 39 : 1; id <= last; id++) {
        print_crumb(f, "", id);
    }
    qemu_mutex_unlock(&cr.lock);
    fclose(f);
    g_autofree char *done =
        g_strdup_printf("Vulkan device lost report written to %s", cr.path);
    fprintf(stderr, "%s\n", done);
#ifdef LIBRETRO
    xemu_libretro_vk_log_error(done);
#endif
}
