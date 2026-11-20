/*
 * Geforce NV2A PGRAPH Vulkan Renderer
 *
 * Copyright (c) 2024-2025 Matt Borgerson
 *
 * Based on GL implementation:
 *
 * Copyright (c) 2012 espes
 * Copyright (c) 2015 Jannik Vogel
 * Copyright (c) 2018-2024 Matt Borgerson
 * Copyright (c) 2026 Réda Chérif-Touil
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

#include "hw/xbox/nv2a/nv2a_int.h"
#include "hw/xbox/nv2a/pgraph/swizzle.h"
#include "qemu/compiler.h"
#include "ui/xemu-settings.h"
#include "renderer.h"
#include <math.h>

#ifdef LIBRETRO
extern unsigned int xemu_libretro_scale_threshold;
#else
static unsigned int xemu_libretro_scale_threshold;
#endif

const int num_invalid_surfaces_to_keep = 10;  // FIXME: Make automatic
const int max_surface_frame_time_delta = 5;

void pgraph_vk_set_surface_scale_factor(NV2AState *d, unsigned int scale)
{
    g_config.display.quality.surface_scale = scale < 1 ? 1 : scale;

    qemu_mutex_lock(&d->pfifo.lock);
    qatomic_set(&d->pfifo.halt, true);
    qemu_mutex_unlock(&d->pfifo.lock);

    // FIXME: It's just flush
    nv2a_pgraph_lock_ext(d);
    qemu_event_reset(&d->pgraph.vk_renderer_state->dirty_surfaces_download_complete);
    qatomic_set(&d->pgraph.vk_renderer_state->download_dirty_surfaces_pending, true);
    qemu_mutex_unlock(&d->pgraph.lock);
    qemu_mutex_lock(&d->pfifo.lock);
    pfifo_kick(d);
    qemu_mutex_unlock(&d->pfifo.lock);
    qemu_event_wait(&d->pgraph.vk_renderer_state->dirty_surfaces_download_complete);

    nv2a_pgraph_lock_ext(d);
    qemu_event_reset(&d->pgraph.flush_complete);
    qatomic_set(&d->pgraph.flush_pending, true);
    qemu_mutex_unlock(&d->pgraph.lock);
    qemu_mutex_lock(&d->pfifo.lock);
    pfifo_kick(d);
    qemu_mutex_unlock(&d->pfifo.lock);
    qemu_event_wait(&d->pgraph.flush_complete);

    qemu_mutex_lock(&d->pfifo.lock);
    qatomic_set(&d->pfifo.halt, false);
    pfifo_kick(d);
    qemu_mutex_unlock(&d->pfifo.lock);
}

unsigned int pgraph_vk_get_surface_scale_factor(NV2AState *d)
{
    return d->pgraph.surface_scale_base; // FIXME: Move internal to renderer
}

void pgraph_vk_reload_surface_scale_factor(PGRAPHState *pg)
{
    int factor = g_config.display.quality.surface_scale;
    pg->surface_scale_base = MAX(factor, 1);
    pg->surface_scale_factor = pg->surface_scale_base;
    pg->surface_scale_threshold =
        qatomic_read(&xemu_libretro_scale_threshold);
}

/* The scale a new render target of this size gets: the internal
 * resolution, or 1x when its larger side is within the threshold. */
static unsigned int scale_for_size(PGRAPHState *pg, unsigned int w,
                                   unsigned int h)
{
    unsigned int t = pg->surface_scale_threshold;
    if (t == UINT_MAX) {
        /* Auto: below the game's frame, as display.c settled it (nothing
         * until then) */
        t = pg->auto_threshold;
    }
    return (t && pg->surface_scale_base > 1 && MAX(w, h) <= t) ?
               1 : pg->surface_scale_base;
}

/* Draws, viewports, scissors, clears and the shader uniforms read
 * surface_scale_factor: it follows the bound target. */
static void update_draw_scale(PGRAPHState *pg)
{
    PGRAPHVkState *r = pg->vk_renderer_state;
    const SurfaceBinding *b = r->color_binding ? r->color_binding :
                                                 r->zeta_binding;
    pg->surface_scale_factor = b ? b->scale : pg->surface_scale_base;
}

static inline void surface_scale_dims(const SurfaceBinding *s,
                                      unsigned int *w, unsigned int *h)
{
    *w *= s->scale;
    *h *= s->scale;
}

// FIXME: Move to common
static void get_surface_dimensions(PGRAPHState const *pg, unsigned int *width,
                                   unsigned int *height)
{
    bool swizzle = (pg->surface_type == NV097_SET_SURFACE_FORMAT_TYPE_SWIZZLE);
    if (swizzle) {
        *width = 1 << pg->surface_shape.log_width;
        *height = 1 << pg->surface_shape.log_height;
    } else {
        *width = pg->surface_shape.clip_width;
        *height = pg->surface_shape.clip_height;
    }
}

// FIXME: Move to common
static bool framebuffer_dirty(PGRAPHState const *pg)
{
    bool shape_changed = memcmp(&pg->surface_shape, &pg->last_surface_shape,
                                sizeof(SurfaceShape)) != 0;
    if (!shape_changed || (!pg->surface_shape.color_format
            && !pg->surface_shape.zeta_format)) {
        return false;
    }
    return true;
}

static void memcpy_image(void *dst, void const *src, int dst_stride,
                         int src_stride, int height)
{
    if (dst_stride == src_stride) {
        memcpy(dst, src, dst_stride * height);
        return;
    }

    uint8_t *dst_ptr = (uint8_t *)dst;
    uint8_t const *src_ptr = (uint8_t *)src;

    size_t copy_stride = MIN(src_stride, dst_stride);

    for (int i = 0; i < height; i++) {
        memcpy(dst_ptr, src_ptr, copy_stride);
        dst_ptr += dst_stride;
        src_ptr += src_stride;
    }
}

static bool check_surface_overlaps_range(const SurfaceBinding *surface,
                                         hwaddr range_start, hwaddr range_len)
{
    hwaddr surface_end = surface->vram_addr + surface->size;
    hwaddr range_end = range_start + range_len;
    return !(surface->vram_addr >= range_end || range_start >= surface_end);
}

static void parked_materialize_range(NV2AState *d, hwaddr start,
                                     hwaddr size);
static void parked_owed_settled(NV2AState *d, SurfaceBinding *s);

__thread const char *vk_surf_site_func;
__thread int vk_surf_site_line;

void (pgraph_vk_download_surfaces_in_range_if_dirty)(PGRAPHState *pg,
                                                   hwaddr start, hwaddr size)
{
    PGRAPHVkState *r = pg->vk_renderer_state;
    SurfaceBinding *surface;

    /* A texture is built from this RAM: settle its owed lazy writebacks,
     * first, as a parked image is older than any live target over it. */
    parked_materialize_range(container_of(pg, NV2AState, pgraph), start,
                             size);
    QTAILQ_FOREACH(surface, &r->surfaces, entry) {
        if (check_surface_overlaps_range(surface, start, size)) {
            /* not the macro: the site stays the caller's */
            (pgraph_vk_surface_download_if_dirty)(
                container_of(pg, NV2AState, pgraph), surface);
        }
    }
}

static void download_surface_to_buffer(NV2AState *d, SurfaceBinding *surface,
                                       uint8_t *pixels)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    if (!surface->width || !surface->height) {
        return;
    }

    nv2a_profile_inc_counter(NV2A_PROF_SURF_DOWNLOAD);
    nv2a_surf_site_note(0, vk_surf_site_func, vk_surf_site_line,
                        surface->vram_addr, surface->width, surface->height,
                        surface->shape.color_format, surface->color);

    bool use_compute_to_convert_depth_stencil_format =
        surface->host_fmt.vk_format == VK_FORMAT_D24_UNORM_S8_UINT ||
        surface->host_fmt.vk_format == VK_FORMAT_D32_SFLOAT_S8_UINT;

    bool no_conversion_necessary =
        surface->color || use_compute_to_convert_depth_stencil_format ||
        surface->host_fmt.vk_format == VK_FORMAT_D16_UNORM;

    assert(no_conversion_necessary);

    bool compute_needs_finish = (use_compute_to_convert_depth_stencil_format &&
                                 pgraph_vk_compute_needs_finish(r));

    if (compute_needs_finish) {
        /* Only a synchronous finish resets the compute descriptor sets: an
         * asynchronous SURFACE_DOWN would leave them full. */
        pgraph_vk_finish(pg, VK_FINISH_REASON_NEED_BUFFER_SPACE);
    } else if (r->in_command_buffer &&
        (surface->draw_time >= r->command_buffer_start_time ||
         pgraph_vk_surface_borrow_pending(r, surface))) {
        pgraph_vk_finish(pg, VK_FINISH_REASON_SURFACE_DOWN);
    }

    bool downscale = (surface->scale != 1);

    trace_nv2a_pgraph_surface_download(
        surface->color ? "COLOR" : "ZETA",
        surface->swizzle ? "sz" : "lin", surface->vram_addr,
        surface->width, surface->height, surface->pitch,
        surface->fmt.bytes_per_pixel);

    // Read surface into memory
    uint8_t *gl_read_buf = pixels;

    uint8_t *swizzle_buf = pixels;
    if (surface->swizzle) {
        // FIXME: Swizzle in shader
        assert(surface->scale == 1 || downscale);
        swizzle_buf = (uint8_t *)g_malloc(surface->size);
        gl_read_buf = swizzle_buf;
    }

    unsigned int scaled_width = surface->width,
                 scaled_height = surface->height;
    surface_scale_dims(surface, &scaled_width, &scaled_height);
    if (use_compute_to_convert_depth_stencil_format) {
        /* Depth and stencil planes side by side, before the aux recording
         * that reads them. */
        pgraph_vk_buffer_ensure_capacity(pg, BUFFER_COMPUTE_DST,
                                         (VkDeviceSize)scaled_width *
                                             scaled_height * 8);
    }

    VkCommandBuffer cmd = pgraph_vk_begin_single_time_commands(pg);
    pgraph_vk_begin_debug_marker(r, cmd, RGBA_RED, __func__);

    /* In-place sampling: recorded draws may sample this surface in place;
     * the copy only reads, so the image goes back to where it rests (a
     * borrow transition still in the recording was drained above). */
    bool sampled_in_place = surface->in_shader_read;
    pgraph_vk_transition_image_layout(
        pg, cmd, surface->image, surface->host_fmt.vk_format,
        pgraph_vk_surface_base_layout(surface),
        VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    if (!sampled_in_place) {
        pgraph_vk_surface_left_shader_read(&d->pgraph, surface);
    }

    int num_copy_regions = 1;
    VkBufferImageCopy copy_regions[2];
    copy_regions[0] = (VkBufferImageCopy){
        .imageSubresource.aspectMask = surface->color ?
                                           VK_IMAGE_ASPECT_COLOR_BIT :
                                           VK_IMAGE_ASPECT_DEPTH_BIT,
        .imageSubresource.layerCount = 1,
    };

    VkImage surface_image_loc;
    if (downscale && !use_compute_to_convert_depth_stencil_format) {
        copy_regions[0].imageExtent =
            (VkExtent3D){ surface->width, surface->height, 1 };

        if (surface->image_scratch_current_layout !=
            VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
            pgraph_vk_transition_image_layout(
                pg, cmd, surface->image_scratch, surface->host_fmt.vk_format,
                surface->image_scratch_current_layout,
                VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
            surface->image_scratch_current_layout =
                VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        }

        VkImageBlit blit_region = {
            .srcSubresource.aspectMask = surface->host_fmt.aspect,
            .srcSubresource.mipLevel = 0,
            .srcSubresource.baseArrayLayer = 0,
            .srcSubresource.layerCount = 1,
            .srcOffsets[0] = (VkOffset3D){0, 0, 0},
            .srcOffsets[1] = (VkOffset3D){scaled_width, scaled_height, 1},

            .dstSubresource.aspectMask = surface->host_fmt.aspect,
            .dstSubresource.mipLevel = 0,
            .dstSubresource.baseArrayLayer = 0,
            .dstSubresource.layerCount = 1,
            .dstOffsets[0] = (VkOffset3D){0, 0, 0},
            .dstOffsets[1] = (VkOffset3D){surface->width, surface->height, 1},
        };

        vkCmdBlitImage(cmd, surface->image,
                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                       surface->image_scratch,
                       surface->image_scratch_current_layout, 1, &blit_region,
                       VK_FILTER_NEAREST);

        pgraph_vk_transition_image_layout(pg, cmd, surface->image_scratch,
                                          surface->host_fmt.vk_format,
                                          surface->image_scratch_current_layout,
                                          VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
        surface->image_scratch_current_layout =
            VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        surface_image_loc = surface->image_scratch;
    } else {
        copy_regions[0].imageExtent =
            (VkExtent3D){ scaled_width, scaled_height, 1 };
        surface_image_loc = surface->image;
    }

    if (surface->host_fmt.aspect & VK_IMAGE_ASPECT_STENCIL_BIT) {
        size_t depth_size = scaled_width * scaled_height * 4;
        copy_regions[num_copy_regions++] = (VkBufferImageCopy){
            .bufferOffset = ROUND_UP(
                depth_size,
                r->device_props.limits.minStorageBufferOffsetAlignment),
            .imageSubresource.aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT,
            .imageSubresource.layerCount = 1,
            .imageExtent = (VkExtent3D){ scaled_width, scaled_height, 1 },
        };
    }

    //
    // Copy image to staging buffer, or to compute_dst if we need to pack it
    //

    size_t downloaded_image_size = surface->host_fmt.host_bytes_per_pixel *
                                   surface->width * surface->height;
    assert((downloaded_image_size) <=
           r->storage_buffers[BUFFER_STAGING_DST].buffer_size);

    int copy_buffer_idx = use_compute_to_convert_depth_stencil_format ?
                             BUFFER_COMPUTE_DST :
                             BUFFER_STAGING_DST;
    VkBuffer copy_buffer = r->storage_buffers[copy_buffer_idx].buffer;

    {
        VkBufferMemoryBarrier pre_copy_dst_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = copy_buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &pre_copy_dst_barrier, 0, NULL);
    }
    vkCmdCopyImageToBuffer(cmd, surface_image_loc,
                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, copy_buffer,
                           num_copy_regions, copy_regions);

    pgraph_vk_transition_image_layout(
        pg, cmd, surface->image, surface->host_fmt.vk_format,
        VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
        pgraph_vk_surface_base_layout(surface));

    // FIXME: Verify output of depth stencil conversion
    // FIXME: Track current layout and only transition when required

    if (use_compute_to_convert_depth_stencil_format) {
        size_t bytes_per_pixel = 4;
        size_t packed_size =
            downscale ? (surface->width * surface->height * bytes_per_pixel) :
                        (scaled_width * scaled_height * bytes_per_pixel);

        //
        // Pack the depth-stencil image into compute_src buffer
        //

        VkBufferMemoryBarrier pre_compute_src_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_SHADER_READ_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = copy_buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, 0, 0, NULL,
                             1, &pre_compute_src_barrier, 0, NULL);

        VkBuffer pack_buffer = r->storage_buffers[BUFFER_COMPUTE_SRC].buffer;

        VkBufferMemoryBarrier pre_compute_dst_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .dstAccessMask = VK_ACCESS_SHADER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = pack_buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, 0, 0, NULL,
                             1, &pre_compute_dst_barrier, 0, NULL);

        pgraph_vk_pack_depth_stencil(pg, surface, cmd, copy_buffer, pack_buffer,
                                     downscale);

        VkBufferMemoryBarrier post_compute_src_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_SHADER_READ_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = copy_buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &post_compute_src_barrier, 0, NULL);

        VkBufferMemoryBarrier post_compute_dst_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = pack_buffer,
            .size = packed_size
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &post_compute_dst_barrier, 0, NULL);

        //
        // Copy packed image over to staging buffer for host download
        //

        copy_buffer = r->storage_buffers[BUFFER_STAGING_DST].buffer;

        VkBufferMemoryBarrier pre_copy_dst_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = copy_buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &pre_copy_dst_barrier, 0, NULL);

        VkBufferCopy buffer_copy_region = {
            .size = packed_size,
        };
        vkCmdCopyBuffer(cmd, pack_buffer, copy_buffer, 1, &buffer_copy_region);

        VkBufferMemoryBarrier post_copy_src_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = pack_buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &post_copy_src_barrier, 0, NULL);
    }

    //
    // Download image data to host
    //

    VkBufferMemoryBarrier post_copy_dst_barrier = {
        .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
        .srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
        .dstAccessMask = VK_ACCESS_HOST_READ_BIT,
        .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .buffer = copy_buffer,
        .size = VK_WHOLE_SIZE
    };
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                         VK_PIPELINE_STAGE_HOST_BIT, 0, 0, NULL, 1,
                         &post_copy_dst_barrier, 0, NULL);

    nv2a_profile_inc_counter(NV2A_PROF_QUEUE_SUBMIT_1);
    pgraph_vk_end_debug_marker(r, cmd);

    pgraph_vk_end_single_time_commands(pg, cmd);

    void *mapped_memory_ptr = NULL;
    VK_CHECK(vmaMapMemory(r->allocator,
                          r->storage_buffers[BUFFER_STAGING_DST].allocation,
                          &mapped_memory_ptr));

    vmaInvalidateAllocation(r->allocator,
                            r->storage_buffers[BUFFER_STAGING_DST].allocation,
                            0, VK_WHOLE_SIZE);

    memcpy_image(gl_read_buf, mapped_memory_ptr, surface->pitch,
                 surface->width * surface->fmt.bytes_per_pixel,
                 surface->height);

    vmaUnmapMemory(r->allocator,
                   r->storage_buffers[BUFFER_STAGING_DST].allocation);

    if (surface->swizzle) {
        // FIXME: Swizzle in shader
        swizzle_rect(swizzle_buf, surface->width, surface->height, pixels,
                     surface->pitch, surface->fmt.bytes_per_pixel);
        nv2a_profile_inc_counter(NV2A_PROF_SURF_SWIZZLE);
        g_free(swizzle_buf);
    }
}

static void download_surface(NV2AState *d, SurfaceBinding *surface, bool force)
{
    if (!(surface->download_pending || force) || !surface->width ||
        !surface->height) {
        return;
    }

    // FIXME: Respect write enable at last TOU?

    download_surface_to_buffer(d, surface, d->vram_ptr + surface->vram_addr);

    memory_region_set_client_dirty(d->vram, surface->vram_addr,
                                   surface->pitch * surface->height,
                                   DIRTY_MEMORY_VGA);
    memory_region_set_client_dirty(d->vram, surface->vram_addr,
                                   surface->pitch * surface->height,
                                   DIRTY_MEMORY_NV2A_TEX);
    pgraph_writeback_clear_discard(&d->pgraph, surface->vram_addr,
                                   surface->pitch * surface->height);

    surface->download_pending = false;
    surface->draw_dirty = false;
}

void pgraph_vk_wait_for_surface_download(SurfaceBinding *surface)
{
    NV2AState *d = g_nv2a;

    if (qatomic_read(&surface->draw_dirty)) {
        qemu_mutex_lock(&d->pfifo.lock);
        qemu_event_reset(&d->pgraph.vk_renderer_state->downloads_complete);
        qatomic_set(&surface->download_pending, true);
        qatomic_set(&d->pgraph.vk_renderer_state->downloads_pending, true);
        pfifo_kick(d);
        qemu_mutex_unlock(&d->pfifo.lock);
        qemu_event_wait(&d->pgraph.vk_renderer_state->downloads_complete);
    }
}

void pgraph_vk_process_pending_downloads(NV2AState *d)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;
    SurfaceBinding *surface, *prev;

    /* Owed lazy writebacks the CPU access callback queued, oldest first and
     * before the live targets: those are newer where they overlap. */
    QTAILQ_FOREACH_REVERSE_SAFE(surface, &r->invalid_surfaces, entry, prev) {
        if (surface->writeback_owed && surface->download_pending) {
            VK_SURF_SITE();
            download_surface(d, surface, false);
            parked_owed_settled(d, surface);
        }
    }
    QTAILQ_FOREACH(surface, &r->surfaces, entry) {
        VK_SURF_SITE();
        download_surface(d, surface, false);
    }

    qatomic_set(&r->downloads_pending, false);
    qemu_event_set(&r->downloads_complete);
}

void pgraph_vk_download_dirty_surfaces(NV2AState *d)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    SurfaceBinding *surface, *prev;
    /* Settle every owed lazy writeback: a snapshot must find RAM exact.
     * Oldest first, then the live targets, which are newer. */
    QTAILQ_FOREACH_REVERSE_SAFE(surface, &r->invalid_surfaces, entry, prev) {
        if (surface->writeback_owed) {
            pgraph_vk_surface_download_if_dirty(d, surface);
            parked_owed_settled(d, surface);
        }
    }
    QTAILQ_FOREACH(surface, &r->surfaces, entry) {
        pgraph_vk_surface_download_if_dirty(d, surface);
    }

    qatomic_set(&r->download_dirty_surfaces_pending, false);
    qemu_event_set(&r->dirty_surfaces_download_complete);
}

static void surface_access_callback(void *opaque, MemoryRegion *mr, hwaddr addr,
                                    hwaddr len, bool write)
{
    NV2AState *d = (NV2AState *)opaque;
    nv2a_pgraph_lock_ext(d);

    PGRAPHVkState *r = d->pgraph.vk_renderer_state;
    bool wait_for_downloads = false;

    SurfaceBinding *surface;
    QTAILQ_FOREACH(surface, &r->surfaces, entry) {
        if (!check_surface_overlaps_range(surface, addr, len)) {
            continue;
        }

        hwaddr offset = addr - surface->vram_addr;

        if (qatomic_read(&nv2a_prof_surf_on)) {
            CPUState *cs = current_cpu;
            nv2a_surf_cpu_note(surface->vram_addr, surface->width,
                               surface->height, surface->color, write,
                               surface->draw_dirty,
                               cs && cs->cc->get_pc ? cs->cc->get_pc(cs) : 0);
        }

        if (write) {
            trace_nv2a_pgraph_surface_cpu_write(surface->vram_addr, offset);
        } else {
            trace_nv2a_pgraph_surface_cpu_read(surface->vram_addr, offset);
            surface->cpu_reads++;
        }

        if (surface->draw_dirty) {
            surface->download_pending = true;
            wait_for_downloads = true;
        }

        if (write) {
            surface->upload_pending = true;
            /* One write is enough to know a re-upload is needed: stop
             * watching until the upload consumes it (RAM is the truth), as
             * the OpenGL renderer does. Otherwise every store of a CPU-drawn
             * frame (an FMV) is a trap. */
            if (!surface->watch_off && surface->access_cb) {
                surface->watch_off = true;
                mem_access_callback_set_flags(qemu_get_cpu(0),
                                              surface->access_cb, 0);
            }
        }
    }

    /* RAM still owed a lazy writeback: queue it on the pfifo thread (no VK
     * work here) and learn the range live, so its evictions stay eager. */
    QTAILQ_FOREACH(surface, &r->invalid_surfaces, entry) {
        if (surface->writeback_owed &&
            check_surface_overlaps_range(surface, addr, len)) {
            surface->download_pending = true;
            wait_for_downloads = true;
            pgraph_writeback_learn_live(&d->pgraph, surface->vram_addr,
                                        surface->size);
        }
    }

    qemu_mutex_unlock(&d->pgraph.lock);

    if (wait_for_downloads) {
        qemu_mutex_lock(&d->pfifo.lock);
        qemu_event_reset(&r->downloads_complete);
        qatomic_set(&r->downloads_pending, true);
        pfifo_kick(d);
        qemu_mutex_unlock(&d->pfifo.lock);
        /* A DMA write from the main loop arrives here holding the BQL, which
         * the pfifo thread may need before it can download (NO_OPERATION
         * raises an interrupt): let go of it while waiting, as a reset does. */
        bool bql = bql_locked();
        if (bql) {
            bql_unlock();
        }
        qemu_event_wait(&r->downloads_complete);
        if (bql) {
            bql_lock();
        }
    }
}

/* RAM stops being the truth (an upload or a draw): watch CPU access again. */
void pgraph_vk_surface_watch_on(SurfaceBinding *surface)
{
    if (surface->watch_off) {
        surface->watch_off = false;
        mem_access_callback_set_flags(qemu_get_cpu(0), surface->access_cb,
                                      BP_MEM_READ | BP_MEM_WRITE);
    }
}

static void register_cpu_access_callback(NV2AState *d, SurfaceBinding *surface)
{
    surface->watch_off = false;
    if (tcg_enabled()) {
        if (surface->width && surface->height) {
            surface->access_cb = mem_access_callback_insert(
                qemu_get_cpu(0), d->vram, surface->vram_addr, surface->size,
                &surface_access_callback, d);
        } else {
            surface->access_cb = NULL;
        }
    }
}

static void unregister_cpu_access_callback(NV2AState *d,
                                           SurfaceBinding *surface)
{
    if (tcg_enabled() && surface->access_cb) {
        mem_access_callback_remove_by_ref(qemu_get_cpu(0), surface->access_cb);
        surface->access_cb = NULL;
    }
}

/* An owed writeback keeps its parked binding's CPU access callback armed:
 * the first guest access settles the debt before it lands, as on the
 * hardware, and the callback goes with the debt. Otherwise a later
 * materialisation would overwrite RAM the guest reused (Crazy Taxi puts
 * its pushbuffer where SEGABOOT's framebuffers were). */
static void parked_owed_settled(NV2AState *d, SurfaceBinding *s)
{
    s->writeback_owed = false;
    unregister_cpu_access_callback(d, s);
}

static void bind_surface(PGRAPHVkState *r, SurfaceBinding *surface)
{
    if (surface->color) {
        r->color_binding = surface;
    } else {
        r->zeta_binding = surface;
    }

    r->framebuffer_dirty = true;
    update_draw_scale(&g_nv2a->pgraph);
}

static void unbind_surface(NV2AState *d, bool color)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    if (color) {
        if (r->color_binding) {
            r->color_binding = NULL;
            r->framebuffer_dirty = true;
        }
    } else {
        if (r->zeta_binding) {
            r->zeta_binding = NULL;
            r->framebuffer_dirty = true;
        }
    }
    update_draw_scale(pg);
}

static void invalidate_surface(NV2AState *d, SurfaceBinding *surface)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    trace_nv2a_pgraph_surface_invalidated(surface->vram_addr);

    /* The trash keeps an image the open recording used alive, and a recycled
     * image is drawn after those draws, on the same queue. */

    if (surface == r->color_binding) {
        assert(d->pgraph.surface_color.buffer_dirty);
        unbind_surface(d, true);
    }
    if (surface == r->zeta_binding) {
        assert(d->pgraph.surface_zeta.buffer_dirty);
        unbind_surface(d, false);
    }

    /* In-place sampling: bindings aliasing this image lose it now (the
     * image heads to the invalid pool and may change owner). */
    pgraph_vk_texture_drop_borrowed(d, surface);

    /* A parked binding that still owes its writeback keeps the callback
     * (parked_owed_settled). */
    if (!surface->writeback_owed) {
        unregister_cpu_access_callback(d, surface);
    }

    pgraph_rt_memo_forget(&r->rt_memo, surface);

    QTAILQ_REMOVE(&r->surfaces, surface, entry);
    QTAILQ_INSERT_HEAD(&r->invalid_surfaces, surface, entry);
}

void pgraph_vk_surface_ensure_attachment_layout(PGRAPHState *pg,
                                                SurfaceBinding *surface)
{
    if (!surface->in_shader_read) {
        return;
    }
    VkCommandBuffer cmd = pgraph_vk_begin_nondraw_commands(pg);
    pgraph_vk_transition_image_layout(
        pg, cmd, surface->image, surface->host_fmt.vk_format,
        VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
        surface->color ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL :
                         VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
    pgraph_vk_end_nondraw_commands(pg, cmd);
    pgraph_vk_surface_left_shader_read(pg, surface);
}

static bool check_surfaces_overlap(const SurfaceBinding *surface,
                                   const SurfaceBinding *other_surface)
{
    return check_surface_overlaps_range(surface, other_surface->vram_addr,
                                        other_surface->size);
}

/* Lazy writeback: a skipped eviction parks its image in invalid_surfaces
 * with writeback_owed; the first reader of the RAM (texture, CPU access,
 * create, snapshot) materialises it, and a newer dead eviction of the same
 * range supersedes it. Materialising alone does not learn the range live,
 * since pruning and recycling materialise too: only real readers do. */
static void parked_materialize(NV2AState *d, SurfaceBinding *s)
{
    pgraph_vk_surface_download_if_dirty(d, s);
    parked_owed_settled(d, s);
}

static void parked_materialize_range(NV2AState *d, hwaddr start,
                                     hwaddr size)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;
    SurfaceBinding *s, *prev;
    /* oldest first: invalid_surfaces is head-inserted */
    QTAILQ_FOREACH_REVERSE_SAFE(s, &r->invalid_surfaces, entry, prev) {
        if (s->writeback_owed && check_surface_overlaps_range(s, start, size)) {
            parked_materialize(d, s);
            /* a texture read this RAM: proven live, stay eager */
            pgraph_writeback_learn_live(&d->pgraph, s->vram_addr, s->size);
        }
    }
}

static void parked_supersede_owed(PGRAPHVkState *r, hwaddr addr,
                                  size_t size)
{
    SurfaceBinding *s;
    QTAILQ_FOREACH(s, &r->invalid_surfaces, entry) {
        if (s->writeback_owed && s->vram_addr == addr && s->size == size) {
            parked_owed_settled(g_nv2a, s); /* superseded */
        }
    }
}

/* A create's upload reads the evicted range too, as on GL. Only the latest
 * parked eviction can feed it (an older one was overwritten on the
 * hardware), i.e. the first owed overlap in the head-inserted
 * invalid_surfaces, and only with the same address, size, pitch and
 * swizzle: the color and zeta views of one allocation (OutRun 2's drift
 * smoke). Anything else stays dead. */
static bool parked_settle_for_create(NV2AState *d, SurfaceBinding *neu)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    SurfaceBinding *s, *latest = NULL;
    QTAILQ_FOREACH(s, &r->invalid_surfaces, entry) {
        if (s->writeback_owed &&
            check_surface_overlaps_range(s, neu->vram_addr, neu->size)) {
            latest = s;
            break; /* head-insertion order: first hit = newest */
        }
    }
    if (!latest || latest->vram_addr != neu->vram_addr ||
        latest->size != neu->size || latest->pitch != neu->pitch ||
        latest->swizzle != neu->swizzle) {
        return false; /* no owed content, or layout-incompatible (dead) */
    }
    parked_materialize(d, latest);
    pgraph_writeback_learn_live(&d->pgraph, latest->vram_addr, latest->size);
    return true;
}

/* A quick checksum of a surface's RAM (64-bit words, then the tail). */
static uint64_t surface_ram_hash(NV2AState *d, const SurfaceBinding *s)
{
    const uint8_t *p = d->vram_ptr + s->vram_addr;
    size_t n = s->size;
    uint64_t h = 0x9E3779B97F4A7C15ull ^ n;
    size_t i = 0;
    for (; i + 8 <= n; i += 8) {
        uint64_t w;
        memcpy(&w, p + i, 8);
        h = (h ^ w) * 0x100000001B3ull;
        h ^= h >> 29;
    }
    for (; i < n; i++) {
        h = (h ^ p[i]) * 0x100000001B3ull;
    }
    return h;
}

/* Evict a binding: its content is written back to RAM now, or, when that
 * writeback looks dead, owed to the first reader of the RAM instead. */
static void evict_surface(NV2AState *d, SurfaceBinding *s)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    s->shelf_valid = false;
    if (!pgraph_writeback_dead(d, s->vram_addr, s->size, s->cpu_reads)) {
        pgraph_vk_surface_download_if_dirty(d, s);
        /* Scaled: RAM only holds the 1x picture of the image. Remember
         * it, so the same buffer bound again with that RAM untouched gets
         * this image back (get_shelved_surface) rather than a 1x upload.
         * Conker binds its 640x480 depth buffer's memory as a 32x32 depth
         * buffer about twice a frame: the round trip through RAM brought
         * the depth back at 1x precision and surfaces z-fought (xemu#575,
         * as hakuX bbbcf13 shelves them). */
        if (s->scale != 1 && s->width && s->height) {
            s->shelf_hash = surface_ram_hash(d, s);
            s->shelf_valid = true;
        }
    } else {
        pgraph_writeback_record_discard(&d->pgraph, s->vram_addr, s->size);
        parked_supersede_owed(r, s->vram_addr, s->size);
        /* Nothing is owed if RAM already holds the content. */
        s->writeback_owed = s->draw_dirty;
    }
    invalidate_surface(d, s);
}

/* Depth and color views of one buffer. A game that binds the same memory
 * as its depth buffer and as a color target in turn (Jade Empire: one
 * 640x480 buffer, about 14 times a frame each way) made Vulkan write the
 * old view to RAM, waiting for the GPU and converting the depth, and build
 * the new one from RAM, every time. The two views of a linear 32-bit
 * buffer hold the same bits (Z24S8 as depth << 8 | stencil, read as
 * A8R8G8B8), so the old view is converted into the new one on the GPU, at
 * the scaled size, with the compute packing the RAM path uses, and nothing
 * goes to RAM until something reads it. */
/* Which kind pipeline renders into this view (renderer.h, r->kind). */
static int kind_dst_index(const SurfaceBinding *s)
{
    switch (s->host_fmt.vk_format) {
    case VK_FORMAT_B8G8R8A8_UNORM:
        return s->color ? 0 : -1;
    case VK_FORMAT_D24_UNORM_S8_UINT:
        return 1;
    case VK_FORMAT_D32_SFLOAT_S8_UINT:
        return 2;
    default:
        return -1;
    }
}

static bool kind_sampled_ok(PGRAPHVkState *r, VkFormat f)
{
    VkFormatProperties props;
    vkGetPhysicalDeviceFormatProperties(r->physical_device, f, &props);
    return props.optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT;
}

static bool surface_kind_switch_ok(PGRAPHVkState *r, const SurfaceBinding *old,
                                   const SurfaceBinding *t)
{
    if (old->color == t->color || old->vram_addr != t->vram_addr ||
        old->width != t->width || old->height != t->height ||
        old->scale != t->scale ||
        old->pitch != t->pitch || old->swizzle || t->swizzle ||
        old->shape.anti_aliasing != t->shape.anti_aliasing ||
        old->fmt.bytes_per_pixel != 4 || t->fmt.bytes_per_pixel != 4 ||
        old->upload_pending || !old->image) {
        return false;
    }
    const SurfaceBinding *depth = old->color ? t : old;
    const SurfaceBinding *color = old->color ? old : t;
    if (kind_dst_index(color) != 0 || kind_dst_index(depth) < 1) {
        return false;
    }
    /* the old view is sampled */
    static int sampled[3] = { -1, -1, -1 };
    int i = kind_dst_index(old);
    if (sampled[i] < 0) {
        sampled[i] = kind_sampled_ok(r, old->host_fmt.vk_format);
    }
    return sampled[i];
}

/* The shaders pack and unpack exactly as the RAM path does
 * (surface-compute.c): Z24S8 is depth << 8 | stencil, which as B8G8R8A8 is
 * R = depth[15:8], G = depth[7:0], B = stencil, A = depth[23:16] (OpenGL's
 * alias_convert, gl/surface.c, the same bytes). A float depth (D32S8) takes
 * the compute shaders' conversions. The stencil cannot be written from a
 * fragment shader without VK_EXT_shader_stencil_export: color to depth
 * clears it, as OpenGL loses it. */
static const char *kind_frag_glsl(int idx)
{
    switch (idx) {
    case 0:
        return "#version 450\n"
               "layout(set = 0, binding = 0) uniform sampler2D depth_tex;\n"
               "layout(set = 0, binding = 1) uniform usampler2D stencil_tex;\n"
               "layout(constant_id = 0) const bool depth_float = false;\n"
               "layout(location = 0) out vec4 out_color;\n"
               "void main()\n"
               "{\n"
               "    ivec2 p = ivec2(gl_FragCoord.xy);\n"
               "    float z = texelFetch(depth_tex, p, 0).r;\n"
               "    uint d = depth_float ? uint(int(z * float(0xffffff)))\n"
               "                         : uint(z * 16777215.0 + 0.5);\n"
               "    uint s = texelFetch(stencil_tex, p, 0).r & 0xffu;\n"
               "    out_color = vec4(float((d >> 8) & 0xffu),\n"
               "                     float(d & 0xffu),\n"
               "                     float(s),\n"
               "                     float((d >> 16) & 0xffu)) / 255.0;\n"
               "}\n";
    case 1:
        return "#version 450\n"
               "layout(set = 0, binding = 0) uniform sampler2D color_tex;\n"
               "void main()\n"
               "{\n"
               "    vec4 c = floor(texelFetch(color_tex,\n"
               "        ivec2(gl_FragCoord.xy), 0) * 255.0 + 0.5);\n"
               "    uint d = (uint(c.a) << 16) | (uint(c.r) << 8) | uint(c.g);\n"
               "    gl_FragDepth = float(d) / 16777215.0;\n"
               "}\n";
    default:
        return "#version 450\n"
               "layout(set = 0, binding = 0) uniform sampler2D color_tex;\n"
               "void main()\n"
               "{\n"
               "    vec4 c = floor(texelFetch(color_tex,\n"
               "        ivec2(gl_FragCoord.xy), 0) * 255.0 + 0.5);\n"
               "    uint d = (uint(c.a) << 16) | (uint(c.r) << 8) | uint(c.g);\n"
               "    gl_FragDepth = uintBitsToFloat(\n"
               "        floatBitsToUint(float(d) / 16777216.0) + 1u);\n"
               "}\n";
    }
}

static void kind_init_common(PGRAPHVkState *r)
{
    if (r->kind.pipeline_layout) {
        return;
    }
    VkDescriptorSetLayoutBinding bindings[2];
    for (int i = 0; i < 2; i++) {
        bindings[i] = (VkDescriptorSetLayoutBinding){
            .binding = i,
            .descriptorCount = 1,
            .descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
            .stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT,
        };
    }
    VkDescriptorSetLayoutCreateInfo lci = {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
        .bindingCount = 2,
        .pBindings = bindings,
    };
    VK_CHECK(vkCreateDescriptorSetLayout(r->device, &lci, NULL,
                                         &r->kind.set_layout));

    VkDescriptorPoolSize ps = {
        .type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
        .descriptorCount = 2 * ARRAY_SIZE(r->kind.sets),
    };
    VkDescriptorPoolCreateInfo pci = {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
        .poolSizeCount = 1,
        .pPoolSizes = &ps,
        .maxSets = ARRAY_SIZE(r->kind.sets),
    };
    VK_CHECK(vkCreateDescriptorPool(r->device, &pci, NULL, &r->kind.pool));
    VkDescriptorSetLayout layouts[ARRAY_SIZE(r->kind.sets)];
    for (int i = 0; i < ARRAY_SIZE(layouts); i++) {
        layouts[i] = r->kind.set_layout;
    }
    VkDescriptorSetAllocateInfo ai = {
        .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
        .descriptorPool = r->kind.pool,
        .descriptorSetCount = ARRAY_SIZE(r->kind.sets),
        .pSetLayouts = layouts,
    };
    VK_CHECK(vkAllocateDescriptorSets(r->device, &ai, r->kind.sets));
    r->kind.set_index = 0;

    VkPipelineLayoutCreateInfo plci = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
        .setLayoutCount = 1,
        .pSetLayouts = &r->kind.set_layout,
    };
    VK_CHECK(vkCreatePipelineLayout(r->device, &plci, NULL,
                                    &r->kind.pipeline_layout));

    VkSamplerCreateInfo sci = {
        .sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO,
        .magFilter = VK_FILTER_NEAREST,
        .minFilter = VK_FILTER_NEAREST,
        .mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST,
        .addressModeU = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        .addressModeV = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        .addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE,
        .maxLod = 0.0f,
    };
    VK_CHECK(vkCreateSampler(r->device, &sci, NULL, &r->kind.sampler));
}

/* Render pass and pipeline that render the view of kind idx. */
static void kind_init_pipeline(PGRAPHVkState *r, int idx)
{
    if (r->kind.pipeline[idx]) {
        return;
    }
    kind_init_common(r);

    static const VkFormat formats[3] = { VK_FORMAT_B8G8R8A8_UNORM,
                                         VK_FORMAT_D24_UNORM_S8_UINT,
                                         VK_FORMAT_D32_SFLOAT_S8_UINT };
    bool depth = idx > 0;
    VkImageLayout layout = depth ?
        VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL :
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    /* every texel is written: nothing to load; the stencil is cleared */
    VkAttachmentDescription att = {
        .format = formats[idx],
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        .storeOp = VK_ATTACHMENT_STORE_OP_STORE,
        .stencilLoadOp = depth ? VK_ATTACHMENT_LOAD_OP_CLEAR :
                                 VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        .stencilStoreOp = depth ? VK_ATTACHMENT_STORE_OP_STORE :
                                  VK_ATTACHMENT_STORE_OP_DONT_CARE,
        .initialLayout = layout,
        .finalLayout = layout,
    };
    VkAttachmentReference ref = { 0, layout };
    VkSubpassDescription subpass = {
        .pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS,
        .colorAttachmentCount = depth ? 0 : 1,
        .pColorAttachments = depth ? NULL : &ref,
        .pDepthStencilAttachment = depth ? &ref : NULL,
    };
    /* after whatever used the memory before, before whatever uses it next */
    VkSubpassDependency deps[2] = {
        {
            .srcSubpass = VK_SUBPASS_EXTERNAL,
            .dstSubpass = 0,
            .srcStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
            .dstStageMask = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT |
                            VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT |
                            VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT |
                            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
            .srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_SHADER_READ_BIT |
                             VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT |
                             VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT |
                             VK_ACCESS_COLOR_ATTACHMENT_READ_BIT |
                             VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
        },
        {
            .srcSubpass = 0,
            .dstSubpass = VK_SUBPASS_EXTERNAL,
            .srcStageMask = VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT |
                            VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
            .dstStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
            .srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT |
                             VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_MEMORY_READ_BIT |
                             VK_ACCESS_MEMORY_WRITE_BIT,
        },
    };
    VkRenderPassCreateInfo rpci = {
        .sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
        .attachmentCount = 1,
        .pAttachments = &att,
        .subpassCount = 1,
        .pSubpasses = &subpass,
        .dependencyCount = 2,
        .pDependencies = deps,
    };
    VK_CHECK(vkCreateRenderPass(r->device, &rpci, NULL,
                                &r->kind.render_pass[idx]));

    ShaderModuleInfo *frag = pgraph_vk_create_shader_module_from_glsl(
        r, VK_SHADER_STAGE_FRAGMENT_BIT, kind_frag_glsl(idx));
    /* color from a float depth (D32S8): the compute packing's conversion */
    VkBool32 depth_float =
        idx == 0 && r->kind.zeta_float;
    VkSpecializationMapEntry spec_entry = { 0, 0, sizeof(VkBool32) };
    VkSpecializationInfo spec = { 1, &spec_entry, sizeof(VkBool32),
                                  &depth_float };
    VkPipelineShaderStageCreateInfo stages[2] = {
        {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .stage = VK_SHADER_STAGE_VERTEX_BIT,
            .module = r->quad_vert_module->module,
            .pName = "main",
        },
        {
            .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
            .stage = VK_SHADER_STAGE_FRAGMENT_BIT,
            .module = frag->module,
            .pName = "main",
            .pSpecializationInfo = idx == 0 ? &spec : NULL,
        },
    };
    VkPipelineVertexInputStateCreateInfo vi = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
    };
    VkPipelineInputAssemblyStateCreateInfo ia = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
        .topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
    };
    VkPipelineViewportStateCreateInfo vp = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
        .viewportCount = 1,
        .scissorCount = 1,
    };
    VkPipelineRasterizationStateCreateInfo rs = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
        .polygonMode = VK_POLYGON_MODE_FILL,
        .cullMode = VK_CULL_MODE_NONE,
        .frontFace = VK_FRONT_FACE_CLOCKWISE,
        .lineWidth = 1.0f,
    };
    VkPipelineMultisampleStateCreateInfo ms = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
        .rasterizationSamples = VK_SAMPLE_COUNT_1_BIT,
    };
    VkPipelineDepthStencilStateCreateInfo ds = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO,
        .depthTestEnable = VK_TRUE,
        .depthWriteEnable = VK_TRUE,
        .depthCompareOp = VK_COMPARE_OP_ALWAYS,
    };
    VkPipelineColorBlendAttachmentState cba = {
        .colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT |
                          VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT,
    };
    VkPipelineColorBlendStateCreateInfo cb = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
        .attachmentCount = depth ? 0 : 1,
        .pAttachments = depth ? NULL : &cba,
    };
    VkDynamicState dyn[] = { VK_DYNAMIC_STATE_VIEWPORT,
                             VK_DYNAMIC_STATE_SCISSOR };
    VkPipelineDynamicStateCreateInfo dy = {
        .sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,
        .dynamicStateCount = 2,
        .pDynamicStates = dyn,
    };
    VkGraphicsPipelineCreateInfo gci = {
        .sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
        .stageCount = 2,
        .pStages = stages,
        .pVertexInputState = &vi,
        .pInputAssemblyState = &ia,
        .pViewportState = &vp,
        .pRasterizationState = &rs,
        .pMultisampleState = &ms,
        .pDepthStencilState = depth ? &ds : NULL,
        .pColorBlendState = &cb,
        .pDynamicState = &dy,
        .layout = r->kind.pipeline_layout,
        .renderPass = r->kind.render_pass[idx],
    };
    VK_CHECK(vkCreateGraphicsPipelines(r->device, r->vk_pipeline_cache, 1,
                                       &gci, NULL, &r->kind.pipeline[idx]));
    pgraph_vk_destroy_shader_module(r, frag);
}

static void kind_finalize(PGRAPHVkState *r)
{
    for (int i = 0; i < 3; i++) {
        if (r->kind.pipeline[i]) {
            vkDestroyPipeline(r->device, r->kind.pipeline[i], NULL);
            vkDestroyRenderPass(r->device, r->kind.render_pass[i], NULL);
            r->kind.pipeline[i] = VK_NULL_HANDLE;
            r->kind.render_pass[i] = VK_NULL_HANDLE;
        }
    }
    if (r->kind.pipeline_layout) {
        vkDestroyPipelineLayout(r->device, r->kind.pipeline_layout, NULL);
        vkDestroyDescriptorPool(r->device, r->kind.pool, NULL);
        vkDestroyDescriptorSetLayout(r->device, r->kind.set_layout, NULL);
        vkDestroySampler(r->device, r->kind.sampler, NULL);
        r->kind.pipeline_layout = VK_NULL_HANDLE;
        r->kind.pool = VK_NULL_HANDLE;
        r->kind.set_layout = VK_NULL_HANDLE;
        r->kind.sampler = VK_NULL_HANDLE;
    }
}

bool pgraph_vk_kind_needs_finish(PGRAPHVkState *r)
{
    return r->kind.set_index >= ARRAY_SIZE(r->kind.sets);
}

void pgraph_vk_kind_finish_complete(PGRAPHVkState *r)
{
    r->kind.set_index = 0;
}

static VkImageView kind_aspect_view(PGRAPHVkState *r, SurfaceBinding *s,
                                    VkImageAspectFlags aspect)
{
    VkImageViewCreateInfo ci = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .image = s->image,
        .viewType = VK_IMAGE_VIEW_TYPE_2D,
        .format = s->host_fmt.vk_format,
        .subresourceRange.aspectMask = aspect,
        .subresourceRange.levelCount = 1,
        .subresourceRange.layerCount = 1,
    };
    VkImageView v;
    VK_CHECK(vkCreateImageView(r->device, &ci, NULL, &v));
    return v;
}

/* src's content into dst, the other view of the same buffer, in the open
 * recording after the draws that wrote src: one draw that samples src and
 * renders dst, one read and one write per texel at the scaled size, as
 * OpenGL's alias_convert does. */
static void surface_kind_switch(PGRAPHState *pg, SurfaceBinding *src,
                                SurfaceBinding *dst)
{
    PGRAPHVkState *r = pg->vk_renderer_state;
    int idx = kind_dst_index(dst);
    assert(idx >= 0);

    if (r->kind.pipeline_layout && pgraph_vk_kind_needs_finish(r)) {
        pgraph_vk_finish(pg, VK_FINISH_REASON_NEED_BUFFER_SPACE);
    }
    r->kind.zeta_float = src->color ? false :
        src->host_fmt.vk_format == VK_FORMAT_D32_SFLOAT_S8_UINT;
    kind_init_pipeline(r, idx);
    nv2a_profile_inc_counter(NV2A_PROF_SURF_KIND_SWITCH);

    unsigned int w = dst->width, h = dst->height;
    surface_scale_dims(dst, &w, &h);

    /* sampled views of src: depth and stencil apart, or its color view */
    VkImageView v0, v1 = VK_NULL_HANDLE;
    if (src->color) {
        v0 = src->image_view;
    } else {
        v0 = kind_aspect_view(r, src, VK_IMAGE_ASPECT_DEPTH_BIT);
        v1 = kind_aspect_view(r, src, VK_IMAGE_ASPECT_STENCIL_BIT);
    }
    VkDescriptorSet set = r->kind.sets[r->kind.set_index++];
    VkDescriptorImageInfo ii[2] = {
        { r->kind.sampler, v0, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
        { r->kind.sampler, v1, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL },
    };
    VkWriteDescriptorSet wr[2];
    for (int i = 0; i < 2; i++) {
        wr[i] = (VkWriteDescriptorSet){
            .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
            .dstSet = set,
            .dstBinding = i,
            .descriptorCount = 1,
            .descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
            .pImageInfo = &ii[i],
        };
    }
    vkUpdateDescriptorSets(r->device, src->color ? 1 : 2, wr, 0, NULL);

    VkFramebufferCreateInfo fci = {
        .sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
        .renderPass = r->kind.render_pass[idx],
        .attachmentCount = 1,
        .pAttachments = &dst->image_view,
        .width = w,
        .height = h,
        .layers = 1,
    };
    VkFramebuffer fb;
    VK_CHECK(vkCreateFramebuffer(r->device, &fci, NULL, &fb));

    VkCommandBuffer cmd = pgraph_vk_begin_nondraw_commands(pg);
    pgraph_vk_begin_debug_marker(r, cmd, RGBA_GREEN, __func__);

    bool src_in_place = src->in_shader_read;
    if (!src_in_place) {
        pgraph_vk_transition_image_layout(
            pg, cmd, src->image, src->host_fmt.vk_format,
            src->color ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL :
                         VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,
            VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
    }
    if (dst->in_shader_read) {
        pgraph_vk_transition_image_layout(
            pg, cmd, dst->image, dst->host_fmt.vk_format,
            VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            dst->color ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL :
                         VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
        pgraph_vk_surface_left_shader_read(pg, dst);
    }

    VkClearValue clear = { .depthStencil = { 0.0f, 0 } };
    VkRenderPassBeginInfo rbi = {
        .sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
        .renderPass = r->kind.render_pass[idx],
        .framebuffer = fb,
        .renderArea.extent = { w, h },
        .clearValueCount = 1,
        .pClearValues = &clear,
    };
    vkCmdBeginRenderPass(cmd, &rbi, VK_SUBPASS_CONTENTS_INLINE);
    vkCmdBindPipeline(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS,
                      r->kind.pipeline[idx]);
    vkCmdBindDescriptorSets(cmd, VK_PIPELINE_BIND_POINT_GRAPHICS,
                            r->kind.pipeline_layout, 0, 1, &set, 0, NULL);
    VkViewport viewport = { 0, 0, w, h, 0.0f, 1.0f };
    VkRect2D scissor = { { 0, 0 }, { w, h } };
    vkCmdSetViewport(cmd, 0, 1, &viewport);
    vkCmdSetScissor(cmd, 0, 1, &scissor);
    vkCmdDraw(cmd, 3, 1, 0, 0);
    vkCmdEndRenderPass(cmd);

    /* src back to its attachment layout, as it was */
    if (!src_in_place) {
        pgraph_vk_transition_image_layout(
            pg, cmd, src->image, src->host_fmt.vk_format,
            VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
            src->color ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL :
                         VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);
    }
    pgraph_vk_end_debug_marker(r, cmd);
    pgraph_vk_end_nondraw_commands(pg, cmd);

    /* in use by the recording: freed once it settled */
    struct XemuVkTrashEntry e = { .framebuffer = fb };
    pgraph_vk_trash_push(r, &e);
    if (!src->color) {
        struct XemuVkTrashEntry e0 = { .image_view = v0 };
        struct XemuVkTrashEntry e1 = { .image_view = v1 };
        pgraph_vk_trash_push(r, &e0);
        pgraph_vk_trash_push(r, &e1);
    }
    dst->draw_time = src->draw_time;
}

static void invalidate_overlapping_surfaces(NV2AState *d,
                                            SurfaceBinding const *surface)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    SurfaceBinding *other_surface, *next_surface;
    QTAILQ_FOREACH_SAFE (other_surface, &r->surfaces, entry, next_surface) {
        if (check_surfaces_overlap(surface, other_surface)) {
            trace_nv2a_pgraph_surface_evict_overlapping(
                other_surface->vram_addr, other_surface->width,
                other_surface->height, other_surface->pitch);
            nv2a_surf_evict_note(
                "overlapped", other_surface->vram_addr, other_surface->width,
                other_surface->height, other_surface->pitch,
                other_surface->shape.color_format,
                other_surface->shape.zeta_format, other_surface->color,
                other_surface->shape.anti_aliasing, surface->vram_addr,
                surface->width, surface->height, surface->pitch,
                surface->shape.color_format, surface->shape.zeta_format,
                surface->color, surface->shape.anti_aliasing, 0, 0);
            evict_surface(d, other_surface);
        }
    }
}

/* Render targets that share memory with the same pitch, handed over on the
 * GPU. Forza Motorsport's bumper view draws the rear view into a 320x120
 * target inside its 640x480 frame buffer, and uses one depth buffer with
 * 2x AA (1280x480) and without (640x480) in turn, with one pitch; each
 * switch evicted the old target, read it back to RAM waiting for the GPU,
 * and uploaded the new one from RAM (NNshi's profiles: 123 waits a second).
 * The bytes of such targets map onto each other row by row, so the new
 * target is built from the old images instead: the newest image that holds
 * all of it, then the newer ones that hold a part, each copied at the
 * internal resolution where the RAM path would have carried it. An old
 * target that the new one does not cover keeps its image parked with its
 * writeback owed, settled before any reader of the RAM, oldest first. */
#define HANDOFF_MAX 8

typedef struct HandoffSrc {
    SurfaceBinding *s;
    int dx, dy; /* s's top-left in the new target, in guest pixels */
    bool live;
} HandoffSrc;

/* Where s lies in t's rows, if their bytes map onto each other. */
static bool handoff_place(const SurfaceBinding *s, const SurfaceBinding *t,
                          int *dx, int *dy)
{
    if (s->color != t->color || s->swizzle || t->swizzle ||
        s->scale != t->scale ||
        s->pitch != t->pitch || !t->pitch ||
        s->fmt.bytes_per_pixel != t->fmt.bytes_per_pixel ||
        s->host_fmt.vk_format != t->host_fmt.vk_format ||
        !s->width || !s->height) {
        return false;
    }
    int64_t o = (int64_t)s->vram_addr - (int64_t)t->vram_addr;
    int64_t p = t->pitch;
    int64_t row = o >= 0 ? o / p : -((-o + p - 1) / p);
    int64_t rem = o - row * p;
    unsigned int bpp = t->fmt.bytes_per_pixel;
    if (rem % bpp || rem + (int64_t)s->width * bpp > p ||
        (int64_t)t->width * bpp > p) {
        return false; /* rows would wrap: not a rectangle of t */
    }
    *dx = rem / bpp;
    *dy = row;
    return true;
}

static bool handoff_covers(const HandoffSrc *h, const SurfaceBinding *t)
{
    return h->dx <= 0 && h->dy <= 0 &&
           h->dx + (int)h->s->width >= (int)t->width &&
           h->dy + (int)h->s->height >= (int)t->height;
}

/* t covers all of s */
static bool handoff_inside(const HandoffSrc *h, const SurfaceBinding *t)
{
    return h->dx >= 0 && h->dy >= 0 &&
           h->dx + (int)h->s->width <= (int)t->width &&
           h->dy + (int)h->s->height <= (int)t->height;
}

/* The old targets the new one t can be built from: the live targets and
 * owed parked images overlapping t that are placeable, from the newest of
 * them that covers t (the base) on. One that cannot be placed only stops
 * it when it is newer than the base: an older one is overwritten by the
 * base where it overlaps t, and left as it is (evicted by surface_put, or
 * still owed). A cold start of Forza kept such an old parked image over
 * the depth buffer until a snapshot settled it (NNshi). old is the target
 * t replaces at its address, already out of the live list. Returns the
 * count, 0 for the RAM path. */
static int handoff_plan(PGRAPHVkState *r, SurfaceBinding *t,
                        SurfaceBinding *old, HandoffSrc *hs, bool *dirty,
                        int *draw_time)
{
    int n = 0;
    int block_time = INT_MIN; /* newest overlapping one that cannot be used */
    SurfaceBinding *s;

    if (old) {
        if (old->upload_pending || !old->image ||
            old == r->color_binding || old == r->zeta_binding ||
            !handoff_place(old, t, &hs[n].dx, &hs[n].dy)) {
            return 0;
        }
        hs[n].s = old;
        hs[n++].live = true;
    }
    QTAILQ_FOREACH(s, &r->surfaces, entry) {
        if (!check_surface_overlaps_range(s, t->vram_addr, t->size)) {
            continue;
        }
        if (n == HANDOFF_MAX) {
            return 0;
        }
        if (s->upload_pending || !s->image ||
            s == r->color_binding || s == r->zeta_binding ||
            !handoff_place(s, t, &hs[n].dx, &hs[n].dy)) {
            block_time = MAX(block_time, s->draw_time);
            continue;
        }
        hs[n].s = s;
        hs[n++].live = true;
    }
    QTAILQ_FOREACH(s, &r->invalid_surfaces, entry) {
        if (!s->writeback_owed ||
            !check_surface_overlaps_range(s, t->vram_addr, t->size)) {
            continue;
        }
        if (n == HANDOFF_MAX) {
            return 0;
        }
        if (!s->image || !handoff_place(s, t, &hs[n].dx, &hs[n].dy)) {
            block_time = MAX(block_time, s->draw_time);
            continue;
        }
        hs[n].s = s;
        hs[n++].live = false;
    }
    if (!n) {
        return 0;
    }
    /* oldest first: each copy overwrites what came before it */
    for (int i = 1; i < n; i++) {
        HandoffSrc h = hs[i];
        int j = i;
        while (j > 0 && hs[j - 1].s->draw_time > h.s->draw_time) {
            hs[j] = hs[j - 1];
            j--;
        }
        hs[j] = h;
    }
    int base = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (handoff_covers(&hs[i], t)) {
            base = i;
            break;
        }
    }
    if (base < 0 || block_time > hs[base].s->draw_time) {
        return 0;
    }
    /* what came before the base is overwritten by it */
    memmove(hs, hs + base, (n - base) * sizeof(*hs));
    n -= base;
    /* t is behind the RAM if any source is; read now, as recycling the
     * base's image into t (get_any_compatible_invalid_surface) settles it */
    *dirty = false;
    *draw_time = 0;
    for (int i = 0; i < n; i++) {
        *dirty |= hs[i].live ? hs[i].s->draw_dirty : hs[i].s->writeback_owed;
        *draw_time = MAX(*draw_time, hs[i].s->draw_time);
    }
    return n;
}

static void handoff_copy(PGRAPHState *pg, VkCommandBuffer cmd,
                         const HandoffSrc *h, SurfaceBinding *t)
{
    SurfaceBinding *s = h->s;
    int x0 = MAX(h->dx, 0), y0 = MAX(h->dy, 0);
    int x1 = MIN(h->dx + (int)s->width, (int)t->width);
    int y1 = MIN(h->dy + (int)s->height, (int)t->height);
    if (x1 <= x0 || y1 <= y0) {
        return;
    }
    unsigned int sf = t->scale;
    VkImageCopy region = {
        .srcSubresource.aspectMask = s->host_fmt.aspect,
        .srcSubresource.layerCount = 1,
        .srcOffset = { (x0 - h->dx) * sf, (y0 - h->dy) * sf, 0 },
        .dstSubresource.aspectMask = t->host_fmt.aspect,
        .dstSubresource.layerCount = 1,
        .dstOffset = { x0 * sf, y0 * sf, 0 },
        .extent = { (x1 - x0) * sf, (y1 - y0) * sf, 1 },
    };
    pgraph_vk_transition_image_layout(pg, cmd, s->image,
                                      s->host_fmt.vk_format,
                                      pgraph_vk_surface_base_layout(s),
                                      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    vkCmdCopyImage(cmd, s->image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                   t->image, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1,
                   &region);
    pgraph_vk_transition_image_layout(pg, cmd, s->image,
                                      s->host_fmt.vk_format,
                                      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                      pgraph_vk_surface_base_layout(s));
    /* the next copy may write the same texels */
    VkMemoryBarrier b = {
        .sType = VK_STRUCTURE_TYPE_MEMORY_BARRIER,
        .srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
        .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
    };
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                         VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 1, &b, 0, NULL, 0,
                         NULL);
}

/* t, just made (its image in place, not yet in the live list), filled from
 * hs. The live sources are out of the live list; they leave parked. */
static void handoff_run(NV2AState *d, SurfaceBinding *t, HandoffSrc *hs,
                        int n, bool dirty, int draw_time)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    nv2a_profile_inc_counter(NV2A_PROF_SURF_HANDOFF);

    VkCommandBuffer cmd = pgraph_vk_begin_nondraw_commands(pg);
    pgraph_vk_begin_debug_marker(r, cmd, RGBA_GREEN, __func__);
    pgraph_vk_transition_image_layout(pg, cmd, t->image,
                                      t->host_fmt.vk_format,
                                      pgraph_vk_surface_base_layout(t),
                                      VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    for (int i = 0; i < n; i++) {
        SurfaceBinding *s = hs[i].s;
        /* A base parked at t's range and shape may have become t itself:
         * its image, recycled, already holds the content. */
        if (s != t && s->image) {
            handoff_copy(pg, cmd, &hs[i], t);
        }
    }
    pgraph_vk_transition_image_layout(pg, cmd, t->image,
                                      t->host_fmt.vk_format,
                                      VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                      pgraph_vk_surface_base_layout(t));
    pgraph_vk_end_debug_marker(r, cmd);
    pgraph_vk_end_nondraw_commands(pg, cmd);

    t->upload_pending = false;
    t->initialized = true;
    t->draw_dirty = dirty;
    t->draw_time = draw_time;

    for (int i = 0; i < n; i++) {
        SurfaceBinding *s = hs[i].s;
        if (s == t) {
            continue;
        }
        s->handoff_src = false;
        bool inside = handoff_inside(&hs[i], t);
        if (hs[i].live) {
            /* Its content went into t where t covers it; the rest is
             * owed to the RAM, as a dead eviction would be. */
            if (inside) {
                s->draw_dirty = false;
                s->writeback_owed = false;
            } else {
                parked_supersede_owed(r, s->vram_addr, s->size);
                s->writeback_owed = s->draw_dirty;
            }
            QTAILQ_INSERT_HEAD(&r->surfaces, s, entry);
            invalidate_surface(d, s);
        } else if (inside && s->writeback_owed) {
            parked_owed_settled(d, s);
        }
    }
}

static void surface_put(NV2AState *d, SurfaceBinding *surface)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    assert(pgraph_vk_surface_get(d, surface->vram_addr) == NULL);

    invalidate_overlapping_surfaces(d, surface);
    register_cpu_access_callback(d, surface);

    QTAILQ_INSERT_HEAD(&r->surfaces, surface, entry);
}

/* The parked image a texture at addr can be taken from: the newest owed
 * content over the texture's memory starts there, and no live target lies
 * over it (a live one is newer). Forza's mirror texture is the top-left of
 * a frame buffer parked while the rear view is drawn inside it; taking it
 * from RAM settled the frame buffer through a download and a GPU wait. */
SurfaceBinding *pgraph_vk_surface_get_parked(NV2AState *d, hwaddr addr,
                                             hwaddr len)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;
    SurfaceBinding *s;

    QTAILQ_FOREACH(s, &r->surfaces, entry) {
        if (check_surface_overlaps_range(s, addr, len)) {
            return NULL;
        }
    }
    QTAILQ_FOREACH(s, &r->invalid_surfaces, entry) {
        if (s->writeback_owed && check_surface_overlaps_range(s, addr, len)) {
            return (s->vram_addr == addr && s->image) ? s : NULL;
        }
    }
    return NULL;
}

SurfaceBinding *pgraph_vk_surface_get(NV2AState *d, hwaddr addr)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    SurfaceBinding *surface;
    QTAILQ_FOREACH (surface, &r->surfaces, entry) {
        if (surface->vram_addr == addr) {
            /* Move to front: a few addresses are looked up many times a
             * frame. Callers do not iterate the list across this call. */
            if (surface != QTAILQ_FIRST(&r->surfaces)) {
                QTAILQ_REMOVE(&r->surfaces, surface, entry);
                QTAILQ_INSERT_HEAD(&r->surfaces, surface, entry);
            }
            return surface;
        }
    }

    return NULL;
}

SurfaceBinding *pgraph_vk_surface_get_within(NV2AState *d, hwaddr addr)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    SurfaceBinding *surface;
    QTAILQ_FOREACH (surface, &r->surfaces, entry) {
        if (addr >= surface->vram_addr &&
            addr < (surface->vram_addr + surface->size)) {
            return surface;
        }
    }

    return NULL;
}

static void set_surface_label(PGRAPHState *pg, SurfaceBinding const *surface)
{
    PGRAPHVkState *r = pg->vk_renderer_state;

    g_autofree gchar *label = g_strdup_printf(
        "Surface %" HWADDR_PRIx "h fmt:%s,%02xh %dx%d aa:%d",
        surface->vram_addr, surface->color ? "Color" : "Zeta",
        surface->color ? surface->shape.color_format :
                         surface->shape.zeta_format,
        surface->width, surface->height, pg->surface_shape.anti_aliasing);

    VkDebugUtilsObjectNameInfoEXT name_info = {
        .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT,
        .objectType = VK_OBJECT_TYPE_IMAGE,
        .objectHandle = (uint64_t)surface->image,
        .pObjectName = label,
    };

    if (r->debug_utils_extension_enabled) {
        vkSetDebugUtilsObjectNameEXT(r->device, &name_info);
    }
    vmaSetAllocationName(r->allocator, surface->allocation, label);

    if (surface->image_scratch) {
        g_autofree gchar *label_scratch =
            g_strdup_printf("%s (scratch)", label);
        name_info.objectHandle = (uint64_t)surface->image_scratch;
        name_info.pObjectName = label_scratch;
        if (r->debug_utils_extension_enabled) {
            vkSetDebugUtilsObjectNameEXT(r->device, &name_info);
        }
        vmaSetAllocationName(r->allocator, surface->allocation_scratch,
                             label_scratch);
    }
}

static void create_surface_image(PGRAPHState *pg, SurfaceBinding *surface)
{
    PGRAPHVkState *r = pg->vk_renderer_state;

    unsigned int width = surface->width ? surface->width : 1;
    unsigned int height = surface->height ? surface->height : 1;
    surface_scale_dims(surface, &width, &height);

    assert(!surface->image);
    assert(!surface->image_scratch);

    NV2A_VK_DPRINTF(
        "Creating new surface image width=%d height=%d @ %08" HWADDR_PRIx,
        width, height, surface->vram_addr);

    VkImageCreateInfo image_create_info = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .imageType = VK_IMAGE_TYPE_2D,
        .extent.width = width,
        .extent.height = height,
        .extent.depth = 1,
        .mipLevels = 1,
        .arrayLayers = 1,
        .format = surface->host_fmt.vk_format,
        .tiling = VK_IMAGE_TILING_OPTIMAL,
        .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
        .usage = VK_IMAGE_USAGE_SAMPLED_BIT |
                 VK_IMAGE_USAGE_TRANSFER_DST_BIT |
                 VK_IMAGE_USAGE_TRANSFER_SRC_BIT | surface->host_fmt.usage,
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
    };

    VmaAllocationCreateInfo alloc_create_info = {
        .usage = VMA_MEMORY_USAGE_AUTO_PREFER_DEVICE,
    };

    VK_CHECK(vmaCreateImage(r->allocator, &image_create_info,
                            &alloc_create_info, &surface->image,
                            &surface->allocation, NULL));

    VK_CHECK(vmaCreateImage(r->allocator, &image_create_info,
                            &alloc_create_info, &surface->image_scratch,
                            &surface->allocation_scratch, NULL));
    surface->image_scratch_current_layout = VK_IMAGE_LAYOUT_UNDEFINED;

    VkImageViewCreateInfo image_view_create_info = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .image = surface->image,
        .viewType = VK_IMAGE_VIEW_TYPE_2D,
        .format = surface->host_fmt.vk_format,
        .subresourceRange.aspectMask = surface->host_fmt.aspect,
        .subresourceRange.levelCount = 1,
        .subresourceRange.layerCount = 1,
    };
    VK_CHECK(vkCreateImageView(r->device, &image_view_create_info, NULL,
                               &surface->image_view));

    // FIXME: Go right into main command buffer
    VkCommandBuffer cmd = pgraph_vk_begin_single_time_commands(pg);
    pgraph_vk_begin_debug_marker(r, cmd, RGBA_RED, __func__);

    pgraph_vk_transition_image_layout(
        pg, cmd, surface->image, surface->host_fmt.vk_format,
        VK_IMAGE_LAYOUT_UNDEFINED,
        surface->color ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL :
                         VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

    nv2a_profile_inc_counter(NV2A_PROF_QUEUE_SUBMIT_3);
    pgraph_vk_end_debug_marker(r, cmd);
    /* No readback: queue order sequences this init before any later
     * consumer; the next aux user waits the fence before reuse. */
    pgraph_vk_end_single_time_commands_async(pg, cmd);
    nv2a_profile_inc_counter(NV2A_PROF_SURF_CREATE);
}

static void migrate_surface_image(SurfaceBinding *dst, SurfaceBinding *src)
{
    dst->image = src->image;
    dst->image_view = src->image_view;
    dst->allocation = src->allocation;
    dst->image_scratch = src->image_scratch;
    dst->image_scratch_current_layout = src->image_scratch_current_layout;
    dst->allocation_scratch = src->allocation_scratch;

    src->image = VK_NULL_HANDLE;
    src->image_view = VK_NULL_HANDLE;
    src->allocation = VK_NULL_HANDLE;
    src->image_scratch = VK_NULL_HANDLE;
    src->image_scratch_current_layout = VK_IMAGE_LAYOUT_UNDEFINED;
    src->allocation_scratch = VK_NULL_HANDLE;
}

static void destroy_surface_image(PGRAPHVkState *r, SurfaceBinding *surface)
{
    pgraph_vk_framebuffer_drop_view(r, surface->image_view);

    /* Submissions in flight and the open recording may still use this
     * image (copies, framebuffers): the trash keeps it until all settle. */
    struct XemuVkTrashEntry e = { .image_view = surface->image_view,
                                  .image = surface->image,
                                  .allocation = surface->allocation };
    pgraph_vk_trash_push(r, &e);
    surface->image_view = VK_NULL_HANDLE;
    surface->image = VK_NULL_HANDLE;
    surface->allocation = VK_NULL_HANDLE;
    if (surface->image_scratch) {
        struct XemuVkTrashEntry e2 = {
            .image = surface->image_scratch,
            .allocation = surface->allocation_scratch,
        };
        pgraph_vk_trash_push(r, &e2);
        surface->image_scratch = VK_NULL_HANDLE;
        surface->allocation_scratch = VK_NULL_HANDLE;
    }
}

static bool check_invalid_surface_is_compatibile(SurfaceBinding *surface,
                                                 SurfaceBinding *target)
{
    return surface->host_fmt.vk_format == target->host_fmt.vk_format &&
           surface->width == target->width &&
           surface->height == target->height &&
           surface->host_fmt.usage == target->host_fmt.usage;
}

/* An evicted image of exactly this buffer whose RAM nobody changed since
 * (evict_surface): its scaled content is still the truth. */
static SurfaceBinding *get_shelved_surface(NV2AState *d,
                                           SurfaceBinding *target)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;
    SurfaceBinding *s, *next;
    QTAILQ_FOREACH_SAFE(s, &r->invalid_surfaces, entry, next) {
        if (!s->shelf_valid || s->writeback_owed || s->handoff_src ||
            !s->image || s->vram_addr != target->vram_addr ||
            s->size != target->size || s->pitch != target->pitch ||
            s->color != target->color || s->swizzle != target->swizzle ||
            !check_invalid_surface_is_compatibile(s, target)) {
            continue;
        }
        s->shelf_valid = false;
        if (surface_ram_hash(d, s) != s->shelf_hash) {
            return NULL; /* RAM changed: upload from it as before */
        }
        pgraph_vk_surface_ensure_attachment_layout(&d->pgraph, s);
        QTAILQ_REMOVE(&r->invalid_surfaces, s, entry);
        return s;
    }
    return NULL;
}

static SurfaceBinding *
get_any_compatible_invalid_surface(PGRAPHVkState *r, SurfaceBinding *target)
{
    SurfaceBinding *surface, *next;
    QTAILQ_FOREACH_SAFE(surface, &r->invalid_surfaces, entry, next) {
        /* a handoff source's image is copied from after this */
        if (surface->handoff_src &&
            (surface->vram_addr != target->vram_addr ||
             surface->size != target->size)) {
            continue;
        }
        if (check_invalid_surface_is_compatibile(surface, target)) {
            /* Recycling would destroy owed content: the same range's is
             * superseded, another range's is materialised first. */
            if (surface->writeback_owed) {
                if (surface->vram_addr == target->vram_addr &&
                    surface->size == target->size) {
                    parked_owed_settled(g_nv2a, surface);
                } else {
                    parked_materialize(g_nv2a, surface);
                }
            }
            /* In-place sampling: a recycled image must hand its new
             * owner the attachment layout every consumer assumes. */
            pgraph_vk_surface_ensure_attachment_layout(&g_nv2a->pgraph,
                                                       surface);
            QTAILQ_REMOVE(&r->invalid_surfaces, surface, entry);
            return surface;
        }
    }

    return NULL;
}

static void prune_invalid_surfaces(PGRAPHVkState *r, int keep)
{
    int num_surfaces = 0;

    SurfaceBinding *surface, *next;
    QTAILQ_FOREACH_SAFE(surface, &r->invalid_surfaces, entry, next) {
        num_surfaces += 1;
        if (num_surfaces > keep) {
            /* Never destroy owed content silently. */
            if (surface->writeback_owed) {
                parked_materialize(g_nv2a, surface);
            }
            QTAILQ_REMOVE(&r->invalid_surfaces, surface, entry);
            destroy_surface_image(r, surface);
            g_free(surface);
        }
    }
}

static void expire_old_surfaces(NV2AState *d)
{
    PGRAPHVkState *r = d->pgraph.vk_renderer_state;

    SurfaceBinding *s, *next;
    QTAILQ_FOREACH_SAFE(s, &r->surfaces, entry, next) {
        int last_used = d->pgraph.frame_time - s->frame_time;
        if (last_used >= max_surface_frame_time_delta) {
            trace_nv2a_pgraph_surface_evict_reason("old", s->vram_addr);
            pgraph_vk_surface_download_if_dirty(d, s);
            invalidate_surface(d, s);
        }
    }
}

static bool check_surface_compatibility(SurfaceBinding const *s1,
                                        SurfaceBinding const *s2, bool strict)
{
    bool format_compatible =
        (s1->color == s2->color) && (s1->scale == s2->scale) &&
        (s1->host_fmt.vk_format == s2->host_fmt.vk_format) &&
        (s1->pitch == s2->pitch);
    if (!format_compatible) {
        return false;
    }

    if (!strict) {
        return (s1->width >= s2->width) && (s1->height >= s2->height);
    } else {
        return (s1->width == s2->width) && (s1->height == s2->height);
    }
}

void (pgraph_vk_surface_download_if_dirty)(NV2AState *d,
                                           SurfaceBinding *surface)
{
    if (surface->draw_dirty) {
        download_surface(d, surface, true);
    }
}

void (pgraph_vk_upload_surface_data)(NV2AState *d, SurfaceBinding *surface,
                                   bool force)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    if (!(surface->upload_pending || force)) {
        return;
    }

    nv2a_profile_inc_counter(NV2A_PROF_SURF_UPLOAD);
    nv2a_surf_site_note(1, vk_surf_site_func, vk_surf_site_line,
                        surface->vram_addr, surface->width, surface->height,
                        surface->shape.color_format, surface->color);

    /* An aux upload runs before the open recording: when draws recorded
     * there wrote this surface or sample it in place,
     * the recording is drained first, or they would see content newer than
     * their record point. */
    if (r->in_command_buffer &&
        (surface->draw_time >= r->command_buffer_start_time ||
         surface->in_shader_read)) {
        pgraph_vk_finish(pg, VK_FINISH_REASON_SURFACE_UP);
    }

    trace_nv2a_pgraph_surface_upload(
                 surface->color ? "COLOR" : "ZETA",
                 surface->swizzle ? "sz" : "lin", surface->vram_addr,
                 surface->width, surface->height, surface->pitch,
                 surface->fmt.bytes_per_pixel);

    surface->upload_pending = false;
    pgraph_vk_surface_watch_on(surface);
    surface->draw_time = pg->draw_time;

    if (!surface->width || !surface->height) {
        surface->initialized = true;
        return;
    }

    uint8_t *data = d->vram_ptr;
    uint8_t *buf = data + surface->vram_addr;

    g_autofree uint8_t *swizzle_buf = NULL;
    uint8_t *gl_read_buf = NULL;

    if (surface->swizzle) {
        swizzle_buf = (uint8_t*)g_malloc(surface->size);
        gl_read_buf = swizzle_buf;
        unswizzle_rect(data + surface->vram_addr,
                       surface->width, surface->height,
                       swizzle_buf,
                       surface->pitch,
                       surface->fmt.bytes_per_pixel);
        nv2a_profile_inc_counter(NV2A_PROF_SURF_SWIZZLE);
    } else {
        gl_read_buf = buf;
    }

    //
    // Upload image data from host to staging buffer
    //

    StorageBuffer *copy_buffer = &r->storage_buffers[BUFFER_STAGING_SRC];
    size_t uploaded_image_size = surface->height * surface->width *
                                 surface->fmt.bytes_per_pixel;
    assert(uploaded_image_size <= copy_buffer->buffer_size);

    if (surface->host_fmt.vk_format == VK_FORMAT_D24_UNORM_S8_UINT ||
        surface->host_fmt.vk_format == VK_FORMAT_D32_SFLOAT_S8_UINT) {
        /* The unpacked planes, before the aux recording that writes them. */
        unsigned int cw = surface->width, ch = surface->height;
        surface_scale_dims(surface, &cw, &ch);
        pgraph_vk_buffer_ensure_capacity(pg, BUFFER_COMPUTE_DST,
                                         (VkDeviceSize)cw * ch * 8);
        /* The unpack takes a compute descriptor set: with none left, a
         * synchronous finish frees them, as on the download path. */
        if (pgraph_vk_compute_needs_finish(r)) {
            pgraph_vk_finish(pg, VK_FINISH_REASON_NEED_BUFFER_SPACE);
        }
    }

    /* Begin before touching the staging buffer: it waits out an earlier
     * async aux submission still reading it. Recording ahead of the memcpy
     * is fine: only the submission needs the data, ordered by the host
     * barrier below. */
    VkCommandBuffer cmd = pgraph_vk_begin_single_time_commands(pg);
    pgraph_vk_begin_debug_marker(r, cmd, RGBA_RED, __func__);

    void *mapped_memory_ptr = NULL;
    VK_CHECK(vmaMapMemory(r->allocator, copy_buffer->allocation,
                          &mapped_memory_ptr));

    bool use_compute_to_convert_depth_stencil_format =
        surface->host_fmt.vk_format == VK_FORMAT_D24_UNORM_S8_UINT ||
        surface->host_fmt.vk_format == VK_FORMAT_D32_SFLOAT_S8_UINT;

    bool no_conversion_necessary =
        surface->color || surface->host_fmt.vk_format == VK_FORMAT_D16_UNORM ||
        use_compute_to_convert_depth_stencil_format;
    assert(no_conversion_necessary);

    memcpy_image(mapped_memory_ptr, gl_read_buf,
                 surface->width * surface->fmt.bytes_per_pixel, surface->pitch,
                 surface->height);

    vmaFlushAllocation(r->allocator, copy_buffer->allocation, 0, VK_WHOLE_SIZE);
    vmaUnmapMemory(r->allocator, copy_buffer->allocation);

    VkBufferMemoryBarrier host_barrier = {
        .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
        .srcAccessMask = VK_ACCESS_HOST_WRITE_BIT,
        .dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
        .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .buffer = copy_buffer->buffer,
        .size = VK_WHOLE_SIZE
    };
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_HOST_BIT,
                         VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                         &host_barrier, 0, NULL);

    // Set up image copy regions (which may be modified by compute unpack)

    VkBufferImageCopy regions[2];
    int num_regions = 0;

    regions[num_regions++] = (VkBufferImageCopy){
        .imageSubresource.aspectMask = surface->color ?
                                           VK_IMAGE_ASPECT_COLOR_BIT :
                                           VK_IMAGE_ASPECT_DEPTH_BIT,
        .imageSubresource.layerCount = 1,
        .imageExtent = (VkExtent3D){ surface->width, surface->height, 1 },
    };

    if (surface->host_fmt.aspect & VK_IMAGE_ASPECT_STENCIL_BIT) {
        regions[num_regions++] = (VkBufferImageCopy){
            .imageSubresource.aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT,
            .imageSubresource.layerCount = 1,
            .imageExtent = (VkExtent3D){ surface->width, surface->height, 1 },
        };
    }


    unsigned int scaled_width = surface->width, scaled_height = surface->height;
    surface_scale_dims(surface, &scaled_width, &scaled_height);

    if (use_compute_to_convert_depth_stencil_format) {

        //
        // Copy packed image buffer to compute_dst for unpacking
        //

        size_t packed_size = uploaded_image_size;
        VkBufferCopy buffer_copy_region = {
            .size = packed_size,
        };
        vkCmdCopyBuffer(cmd, copy_buffer->buffer,
                        r->storage_buffers[BUFFER_COMPUTE_DST].buffer, 1,
                        &buffer_copy_region);

        size_t num_pixels = scaled_width * scaled_height;
        size_t unpacked_depth_image_size = num_pixels * 4;
        size_t unpacked_stencil_image_size = num_pixels;
        size_t unpacked_size =
            unpacked_depth_image_size + unpacked_stencil_image_size;

        VkBufferMemoryBarrier post_copy_src_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = copy_buffer->buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &post_copy_src_barrier, 0, NULL);

        //
        // Unpack depth-stencil image into compute_src
        //

        VkBufferMemoryBarrier pre_unpack_src_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_SHADER_READ_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = r->storage_buffers[BUFFER_COMPUTE_DST].buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, 0, 0, NULL,
                             1, &pre_unpack_src_barrier, 0, NULL);

        StorageBuffer *unpack_buffer = &r->storage_buffers[BUFFER_COMPUTE_SRC];

        VkBufferMemoryBarrier pre_unpack_dst_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .dstAccessMask = VK_ACCESS_SHADER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = unpack_buffer->buffer,
            .size = unpacked_size
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                             VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT, 0, 0, NULL, 1,
                             &pre_unpack_dst_barrier, 0, NULL);

        pgraph_vk_unpack_depth_stencil(
            pg, surface, cmd, r->storage_buffers[BUFFER_COMPUTE_DST].buffer,
            unpack_buffer->buffer);

        VkBufferMemoryBarrier post_unpack_src_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_SHADER_READ_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = r->storage_buffers[BUFFER_COMPUTE_DST].buffer,
            .size = VK_WHOLE_SIZE
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &post_unpack_src_barrier, 0, NULL);

        VkBufferMemoryBarrier post_unpack_dst_barrier = {
            .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
            .srcAccessMask = VK_ACCESS_SHADER_WRITE_BIT,
            .dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
            .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
            .buffer = unpack_buffer->buffer,
            .size = unpacked_size
        };
        vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                             VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                             &post_unpack_dst_barrier, 0, NULL);

        // Already scaled during compute. Adjust copy regions.
        regions[0].imageExtent = (VkExtent3D){ scaled_width, scaled_height, 1 };
        regions[1].imageExtent = regions[0].imageExtent;
        regions[1].bufferOffset =
            ROUND_UP(unpacked_depth_image_size,
                     r->device_props.limits.minStorageBufferOffsetAlignment);

        copy_buffer = unpack_buffer;
    }

    //
    // Copy image data from buffer to staging image
    //

    if (surface->image_scratch_current_layout !=
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
        pgraph_vk_transition_image_layout(pg, cmd, surface->image_scratch,
                                          surface->host_fmt.vk_format,
                                          surface->image_scratch_current_layout,
                                          VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
        surface->image_scratch_current_layout =
            VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    }

    vkCmdCopyBufferToImage(cmd, copy_buffer->buffer, surface->image_scratch,
                           VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, num_regions,
                           regions);

    VkBufferMemoryBarrier post_copy_src_buffer_barrier = {
        .sType = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,
        .srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT,
        .dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT,
        .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .buffer = copy_buffer->buffer,
        .size = VK_WHOLE_SIZE
    };
    vkCmdPipelineBarrier(cmd, VK_PIPELINE_STAGE_TRANSFER_BIT,
                         VK_PIPELINE_STAGE_TRANSFER_BIT, 0, 0, NULL, 1,
                         &post_copy_src_buffer_barrier, 0, NULL);

    //
    // Copy staging image to final image
    //

    pgraph_vk_transition_image_layout(pg, cmd, surface->image_scratch,
                                      surface->host_fmt.vk_format,
                                      surface->image_scratch_current_layout,
                                      VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL);
    surface->image_scratch_current_layout =
        VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

    pgraph_vk_transition_image_layout(
        pg, cmd, surface->image, surface->host_fmt.vk_format,
        pgraph_vk_surface_base_layout(surface),
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
    pgraph_vk_surface_left_shader_read(&d->pgraph, surface);

    bool upscale = surface->scale > 1 &&
                   !use_compute_to_convert_depth_stencil_format;

    if (upscale) {
        VkImageBlit blitRegion = {
            .srcSubresource.aspectMask = surface->host_fmt.aspect,
            .srcSubresource.mipLevel = 0,
            .srcSubresource.baseArrayLayer = 0,
            .srcSubresource.layerCount = 1,
            .srcOffsets[0] = (VkOffset3D){0, 0, 0},
            .srcOffsets[1] = (VkOffset3D){surface->width, surface->height, 1},

            .dstSubresource.aspectMask = surface->host_fmt.aspect,
            .dstSubresource.mipLevel = 0,
            .dstSubresource.baseArrayLayer = 0,
            .dstSubresource.layerCount = 1,
            .dstOffsets[0] = (VkOffset3D){0, 0, 0},
            .dstOffsets[1] = (VkOffset3D){scaled_width, scaled_height, 1},
        };

        vkCmdBlitImage(cmd, surface->image_scratch,
                       surface->image_scratch_current_layout, surface->image,
                       VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &blitRegion,
                       VK_FILTER_NEAREST);
    } else {
        // Note: We should be able to vkCmdCopyBufferToImage directly into
        // surface->image, but there is an apparent AMD Windows driver
        // synchronization bug we'll hit when doing this. For this reason,
        // always use a staging image.

        for (int i = 0; i < num_regions; i++) {
            VkImageAspectFlags aspect = regions[i].imageSubresource.aspectMask;
            VkImageCopy copy_region = {
                .srcSubresource.aspectMask = aspect,
                .srcSubresource.layerCount = 1,
                .dstSubresource.aspectMask = aspect,
                .dstSubresource.layerCount = 1,
                .extent = regions[i].imageExtent,
            };
            vkCmdCopyImage(cmd, surface->image_scratch,
                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, surface->image,
                           VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1,
                           &copy_region);
        }
    }

    pgraph_vk_transition_image_layout(
        pg, cmd, surface->image, surface->host_fmt.vk_format,
        VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
        surface->color ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL :
                         VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL);

    nv2a_profile_inc_counter(NV2A_PROF_QUEUE_SUBMIT_2);
    pgraph_vk_end_debug_marker(r, cmd);
    /* Upload only, no readback: the aux wait at begin, which precedes the
     * staging memcpy, protects the staging source. */
    pgraph_vk_end_single_time_commands_async(pg, cmd);

    surface->initialized = true;
}

static void compare_surfaces(SurfaceBinding const *a, SurfaceBinding const *b)
{
    #define DO_CMP(fld) \
        if (a->fld != b->fld) \
            trace_nv2a_pgraph_surface_compare_mismatch( \
                #fld, (long int)a->fld, (long int)b->fld);
    DO_CMP(shape.clip_x)
    DO_CMP(shape.clip_width)
    DO_CMP(shape.clip_y)
    DO_CMP(shape.clip_height)
    DO_CMP(fmt.bytes_per_pixel)
    DO_CMP(host_fmt.vk_format)
    DO_CMP(color)
    DO_CMP(swizzle)
    DO_CMP(vram_addr)
    DO_CMP(width)
    DO_CMP(height)
    DO_CMP(pitch)
    DO_CMP(size)
    DO_CMP(dma_addr)
    DO_CMP(dma_len)
    DO_CMP(frame_time)
    DO_CMP(draw_time)
    #undef DO_CMP
}

static void populate_surface_binding_target_sized(NV2AState *d, bool color,
                                                  unsigned int width,
                                                  unsigned int height,
                                                  SurfaceBinding *target)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    Surface *surface;
    hwaddr dma_address;
    BasicSurfaceFormatInfo fmt;
    SurfaceFormatInfo host_fmt;

    if (color) {
        surface = &pg->surface_color;
        dma_address = pg->dma_color;
        assert(pg->surface_shape.color_format != 0);
        assert(pg->surface_shape.color_format <
               ARRAY_SIZE(kelvin_surface_color_format_vk_map));
        fmt = kelvin_surface_color_format_map[pg->surface_shape.color_format];
        host_fmt = kelvin_surface_color_format_vk_map[pg->surface_shape.color_format];
        if (host_fmt.host_bytes_per_pixel == 0) {
            fprintf(stderr, "nv2a: unimplemented color surface format 0x%x\n",
                    pg->surface_shape.color_format);
            abort();
        }
    } else {
        surface = &pg->surface_zeta;
        dma_address = pg->dma_zeta;
        assert(pg->surface_shape.zeta_format != 0);
        assert(pg->surface_shape.zeta_format <
               ARRAY_SIZE(r->kelvin_surface_zeta_vk_map));
        fmt = kelvin_surface_zeta_format_map[pg->surface_shape.zeta_format];
        host_fmt = r->kelvin_surface_zeta_vk_map[pg->surface_shape.zeta_format];
        // FIXME: Support float 16,24b float format surface
    }

    DMAObject dma = nv_dma_load(d, dma_address);
    // There's a bunch of bugs that could cause us to hit this function
    // at the wrong time and get a invalid dma object.
    // Check that it's sane.
    assert(dma.dma_class == NV_DMA_IN_MEMORY_CLASS);
    // assert(dma.address + surface->offset != 0);
    assert(surface->offset <= dma.limit);
    assert(surface->offset + surface->pitch * height <= dma.limit + 1);
    assert(surface->pitch % fmt.bytes_per_pixel == 0);
    assert((dma.address & ~0x07FFFFFF) == 0);

    target->shape = (color || !r->color_binding) ? pg->surface_shape :
                                                   r->color_binding->shape;
    target->fmt = fmt;
    target->host_fmt = host_fmt;
    target->color = color;
    target->swizzle =
        (pg->surface_type == NV097_SET_SURFACE_FORMAT_TYPE_SWIZZLE);
    target->vram_addr = dma.address + surface->offset;
    target->width = width;
    target->height = height;
    target->pitch = surface->pitch;
    /* a depth buffer is drawn with its colour target: it takes its scale */
    target->scale = (!color && r->color_binding) ? r->color_binding->scale :
                    scale_for_size(pg, width, height);
    if (target->scale == 1 && pg->surface_scale_base > 1) {
        nv2a_surf_1x_note(target->vram_addr, width, height, color);
    }
    target->size = height * MAX(surface->pitch, width * fmt.bytes_per_pixel);
    target->upload_pending = true;
    target->download_pending = false;
    target->draw_dirty = false;
    target->dma_addr = dma.address;
    target->dma_len = dma.limit;
    target->frame_time = pg->frame_time;
    target->draw_time = pg->draw_time;
    target->cleared = false;
    target->cpu_reads = 0;

    target->initialized = false;
}

static void populate_surface_binding_target(NV2AState *d, bool color,
                                            SurfaceBinding *target)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    unsigned int width, height;

    if (color || !r->color_binding) {
        get_surface_dimensions(pg, &width, &height);
        pgraph_apply_anti_aliasing_factor(pg, &width, &height);

        // Since we determine surface dimensions based on the clipping
        // rectangle, make sure to include the surface offset as well.
        if (pg->surface_type != NV097_SET_SURFACE_FORMAT_TYPE_SWIZZLE) {
            width += pg->surface_shape.clip_x;
            height += pg->surface_shape.clip_y;
        }
        pgraph_bound_surface_to_format(pg, &width, &height);
    } else {
        width = r->color_binding->width;
        height = r->color_binding->height;
    }

    populate_surface_binding_target_sized(d, color, width, height, target);
}

/* HEURISTIC: submit at render-target switches so the GPU starts while the
 * frame is recorded, as the NV2A consumes its pushbuffer continuously.
 * n submissions a frame cost n*c and leave a flip tail of about T/n, least
 * at n = sqrt(T/c), with T (frame GPU time) and c (one submission) measured
 * here. Switches count color and zeta parts apart. */
static void eager_submit_at_switch(PGRAPHState *pg)
{
    PGRAPHVkState *r = pg->vk_renderer_state;

    r->rt_switches++;
    if (!r->in_command_buffer) {
        return;
    }
    unsigned interval = r->eager_interval;
    if (!interval) {
        return;
    }
    if (++r->eager_count >= interval) {
        r->eager_count = 0;
        pgraph_vk_finish(pg, VK_FINISH_REASON_EAGER);
    }
}

/* At the flip: choose next frame's eager interval from this frame's
 * switch count and the measured costs. */
void pgraph_vk_eager_frame_update(PGRAPHState *pg)
{
    PGRAPHVkState *r = pg->vk_renderer_state;

    unsigned switches = r->rt_switches;
    r->rt_switches = 0;
    r->eager_count = 0;
    r->eager_interval = 0;
    /* One submission costs its issue, the next buffer's begin and the
     * wait when its slot comes round again, two submissions later. */
    double c = r->submit_us + r->cb_begin_us + r->reuse_wait_us;
    double t = r->frame_gpu.busy_us;
    if (switches && c > 0.0 && t > 0.0) {
        double n = sqrt(t / c);
        if (n >= 1.0) {
            unsigned interval = (unsigned)(switches / n);
            r->eager_interval = interval ? interval : 1;
        }
    }
}

/* Compatibility with the requested zeta format/address/pitch is checked by
 * the caller (or the memo). A larger linear depth image can cover a smaller
 * color pass without making a RAM roundtrip. Swizzled layouts and different
 * AA modes cannot share that interpretation. */
static inline bool zeta_covers_color(PGRAPHVkState *r, const SurfaceBinding *zeta)
{
    const SurfaceBinding *color = r->color_binding;
    if (!color) {
        return true;
    }
    /* one framebuffer: both attachments at the same resolution scale */
    if (zeta->scale != color->scale) {
        return false;
    }
    if (zeta->width < color->width || zeta->height < color->height) {
        return false;
    }
    if (zeta->width == color->width && zeta->height == color->height) {
        return true;
    }
    /* Same scale (checked above): only the anti-aliasing mode has to
     * match. */
    return !zeta->swizzle && !color->swizzle &&
           zeta->shape.anti_aliasing == color->shape.anti_aliasing;
}

/* The color attachment defines the render area when both are present.
 * Keep its clip too: a memoized larger zeta must not expand the pass. */
static void set_surface_binding_dimensions(PGRAPHState *pg, bool color,
                                            const SurfaceBinding *surface)
{
    PGRAPHVkState *r = pg->vk_renderer_state;
    if (!color && r->color_binding) {
        surface = r->color_binding;
    }
    pgraph_set_surface_binding_dim(pg, surface->width, surface->height,
                                   &surface->shape);
}

static void update_surface_part(NV2AState *d, bool upload, bool color)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    /* Render-target memo, as on GL: registers that resolved to a binding
     * under the same shape generation swap it in without the full pass;
     * a zeta binding must still cover the color target. */
    if (upload && tcg_enabled()) {
        Surface *sf = color ? &pg->surface_color : &pg->surface_zeta;
        if (sf->buffer_dirty) {
            hwaddr dma = color ? pg->dma_color : pg->dma_zeta;
            for (int i = 0; i < 2; i++) {
                SurfaceBinding *m = pgraph_rt_memo_match(
                    &r->rt_memo, color, i, dma, sf->offset, sf->pitch);
                if (m && m != (color ? r->zeta_binding : r->color_binding) &&
                    (color || zeta_covers_color(r, m))) {
                    eager_submit_at_switch(pg);
                    pgraph_vk_ensure_not_in_render_pass(pg);
                    set_surface_binding_dimensions(pg, color, m);
                    if (color) {
                        pg->surface_zeta.buffer_dirty = true;
                    }
                    bind_surface(r, m);
                    sf->buffer_dirty = false;
                    return;
                }
            }
        }
    }

    SurfaceBinding target;
    memset(&target, 0, sizeof(target));
    populate_surface_binding_target(d, color, &target);

    Surface *pg_surface = color ? &pg->surface_color : &pg->surface_zeta;

    bool mem_dirty = !tcg_enabled() && memory_region_test_and_clear_dirty(
                                           d->vram, target.vram_addr,
                                           target.size, DIRTY_MEMORY_NV2A);
    if (mem_dirty) {
        /* This consumed the range's NV2A dirty bit: the vertex mirror must
         * still learn of the guest write. */
        pgraph_vk_vertex_mark_stale(pg, target.vram_addr, target.size);
    }

    SurfaceBinding *current_binding = color ? r->color_binding
                                            : r->zeta_binding;

    if (!current_binding ||
        (upload && (pg_surface->buffer_dirty || mem_dirty))) {
        eager_submit_at_switch(pg);
        pgraph_vk_ensure_not_in_render_pass(pg);

        unbind_surface(d, color);

        SurfaceBinding *surface = pgraph_vk_surface_get(d, target.vram_addr);
        if (surface != NULL) {
            // FIXME: Support same color/zeta surface target? In the mean time,
            // if the surface we just found is currently bound, just unbind it.
            SurfaceBinding *other = (color ? r->zeta_binding
                                           : r->color_binding);
            if (surface == other) {
                NV2A_UNIMPLEMENTED("Same color & zeta surface offset");
                unbind_surface(d, !color);
            }
        }

        trace_nv2a_pgraph_surface_target(
            color ? "COLOR" : "ZETA", target.vram_addr,
            target.swizzle ? "sz" : "ln",
            pg->surface_shape.anti_aliasing,
            pg->surface_shape.clip_x,
            pg->surface_shape.clip_width, pg->surface_shape.clip_y,
            pg->surface_shape.clip_height);

        bool should_create = true;
        SurfaceBinding *handoff_old = NULL;
        const char *evict_why = NULL;
        /* the other view of this buffer, converted on the GPU below
         * (surface_kind_switch) instead of evicted through RAM */
        SurfaceBinding *kind_src = NULL;

        if (surface != NULL) {
            bool is_compatible =
                check_surface_compatibility(surface, &target, false);
            /* for the profile: the first check the binding failed */
            const char *why = is_compatible ? NULL : "shape";

            void (*trace_fn)(uint32_t addr, uint32_t width, uint32_t height,
                             const char *layout, uint32_t anti_aliasing,
                             uint32_t clip_x, uint32_t clip_width,
                             uint32_t clip_y, uint32_t clip_height,
                             uint32_t pitch) =
                surface->color ? trace_nv2a_pgraph_surface_match_color :
                               trace_nv2a_pgraph_surface_match_zeta;

            trace_fn(surface->vram_addr, surface->width, surface->height,
                     surface->swizzle ? "sz" : "ln", surface->shape.anti_aliasing,
                     surface->shape.clip_x, surface->shape.clip_width,
                     surface->shape.clip_y, surface->shape.clip_height,
                     surface->pitch);

            assert(!(target.swizzle && pg->clearing));

#if 0
            if (surface->swizzle != target.swizzle) {
                // Clears should only be done on linear surfaces. Avoid
                // synchronization by allowing (1) a surface marked swizzled to
                // be cleared under the assumption the entire surface is
                // destined to be cleared and (2) a fully cleared linear surface
                // to be marked swizzled. Strictly match size to avoid
                // pathological cases.
                is_compatible &= (pg->clearing || surface->cleared) &&
                    check_surface_compatibility(surface, &target, true);
                if (is_compatible) {
                    trace_nv2a_pgraph_surface_migrate_type(
                        target.swizzle ? "swizzled" : "linear");
                }
            }
#endif

            if (is_compatible && color &&
                !check_surface_compatibility(surface, &target, true)) {
                SurfaceBinding zeta_entry;
                populate_surface_binding_target_sized(
                    d, !color, surface->width, surface->height, &zeta_entry);
                hwaddr color_end = surface->vram_addr + surface->size;
                hwaddr zeta_end = zeta_entry.vram_addr + zeta_entry.size;
                is_compatible &= surface->vram_addr >= zeta_end ||
                                 zeta_entry.vram_addr >= color_end;
                if (!is_compatible) {
                    why = "color over zeta";
                }
            }

            if (is_compatible && !color && r->color_binding) {
                is_compatible &= zeta_covers_color(r, surface);
                if (!is_compatible) {
                    why = "zeta smaller than color";
                }
            }

            if (is_compatible) {
                set_surface_binding_dimensions(pg, color, surface);
                surface->upload_pending |= mem_dirty;
                pg->surface_zeta.buffer_dirty |= color;
                should_create = false;
            } else {
                trace_nv2a_pgraph_surface_evict_reason(
                    "incompatible", surface->vram_addr);
                compare_surfaces(surface, &target);
                evict_why = why;
                if (!mem_dirty && surface_kind_switch_ok(r, surface, &target)) {
                    /* out of the live list while the new view is made, so
                     * that it is not evicted as an overlap */
                    kind_src = surface;
                    QTAILQ_REMOVE(&r->surfaces, kind_src, entry);
                } else if (!mem_dirty) {
                    /* maybe handed over on the GPU below (handoff_plan) */
                    handoff_old = surface;
                    QTAILQ_REMOVE(&r->surfaces, surface, entry);
                } else {
                    nv2a_surf_evict_note(
                        why, surface->vram_addr, surface->width, surface->height,
                        surface->pitch, surface->shape.color_format,
                        surface->shape.zeta_format, surface->color,
                        surface->shape.anti_aliasing, target.vram_addr,
                        target.width, target.height, target.pitch,
                        target.shape.color_format, target.shape.zeta_format,
                        target.color, target.shape.anti_aliasing,
                        (!color && r->color_binding) ? r->color_binding->width : 0,
                        (!color && r->color_binding) ? r->color_binding->height : 0);
                    evict_surface(d, surface);
                }
            }
        }

        HandoffSrc hs[HANDOFF_MAX];
        int hn = 0;
        bool h_dirty = false;
        int h_time = 0;
        if (should_create && !mem_dirty && !kind_src) {
            hn = handoff_plan(r, &target, handoff_old, hs, &h_dirty, &h_time);
        }
        if (!hn && handoff_old) {
            /* for the profile: only an eviction through RAM is listed */
            nv2a_surf_evict_note(
                evict_why, handoff_old->vram_addr, handoff_old->width,
                handoff_old->height,
                handoff_old->pitch, handoff_old->shape.color_format,
                handoff_old->shape.zeta_format, handoff_old->color,
                handoff_old->shape.anti_aliasing, target.vram_addr,
                target.width, target.height, target.pitch,
                target.shape.color_format, target.shape.zeta_format,
                target.color, target.shape.anti_aliasing,
                (!color && r->color_binding) ? r->color_binding->width : 0,
                (!color && r->color_binding) ? r->color_binding->height : 0);
            QTAILQ_INSERT_HEAD(&r->surfaces, handoff_old, entry);
            evict_surface(d, handoff_old);
        }
        for (int i = 0; i < hn; i++) {
            hs[i].s->handoff_src = true;
            if (hs[i].live && hs[i].s != handoff_old) {
                /* out of the live list, so that surface_put does not
                 * evict it through the RAM */
                QTAILQ_REMOVE(&r->surfaces, hs[i].s, entry);
            }
        }

        if (should_create) {
            if (kind_src) {
                /* the content comes from the other view, not from RAM */
                target.upload_pending = false;
                target.initialized = true;
                target.draw_dirty = kind_src->draw_dirty;
            }
            /* Settle an owed writeback first: the create's upload must read
             * the refreshed RAM, and a settle cancels the dead-upload skip.
             * A handoff or a view conversion takes the content from the old
             * images instead. */
            bool settled = !hn && !kind_src &&
                           parked_settle_for_create(d, &target);
            if (settled) {
                target.upload_pending = true;
            }
            if (!hn && !settled && target.upload_pending &&
                pgraph_writeback_discarded(&d->pgraph, target.vram_addr,
                                           target.size)) {
                if (memory_region_test_and_clear_dirty(d->vram,
                                                       target.vram_addr,
                                                       target.size,
                                                       DIRTY_MEMORY_NV2A)) {
                    /* The guest wrote the range: it is uploaded, and the
                     * vertex mirror learns of the dirty bit consumed here. */
                    pgraph_vk_vertex_mark_stale(&d->pgraph, target.vram_addr,
                                                target.size);
                } else {
                    /* Dead upload skipped: the image keeps whatever it
                     * holds, as stale as the RAM. It counts as initialized
                     * (draw.c) since the game clears or overdraws it first. */
                    target.upload_pending = false;
                    target.initialized = true;
                }
            }
            surface = NULL;
            if (!hn && !kind_src && target.upload_pending) {
                surface = get_shelved_surface(d, &target);
                if (surface) {
                    /* its image holds the content: no upload */
                    migrate_surface_image(&target, surface);
                    target.upload_pending = false;
                    target.initialized = true;
                }
            }
            if (surface) {
                /* the shelved binding's memory is reused below */
            } else if ((surface = get_any_compatible_invalid_surface(
                            r, &target))) {
                migrate_surface_image(&target, surface);
            } else {
                surface = g_malloc(sizeof(SurfaceBinding));
                create_surface_image(pg, &target);
            }

            *surface = target;
            set_surface_label(pg, surface);
            surface_put(d, surface);
            if (hn) {
                handoff_run(d, surface, hs, hn, h_dirty, h_time);
            }

            if (kind_src) {
                surface_kind_switch(pg, kind_src, surface);
                /* its content now lives in the new view: nothing owed */
                QTAILQ_INSERT_HEAD(&r->surfaces, kind_src, entry);
                kind_src->draw_dirty = false;
                kind_src->download_pending = false;
                kind_src->writeback_owed = false;
                invalidate_surface(d, kind_src);
            }

            set_surface_binding_dimensions(pg, color, &target);

            if (color && r->zeta_binding &&
                (r->zeta_binding->width != target.width ||
                 r->zeta_binding->height != target.height)) {
                pg->surface_zeta.buffer_dirty = true;
            }
        }

        void (*trace_fn)(uint32_t addr, uint32_t width, uint32_t height,
                         const char *layout, uint32_t anti_aliasing,
                         uint32_t clip_x, uint32_t clip_width, uint32_t clip_y,
                         uint32_t clip_height, uint32_t pitch) =
            color ? (should_create ? trace_nv2a_pgraph_surface_create_color :
                                     trace_nv2a_pgraph_surface_hit_color) :
                    (should_create ? trace_nv2a_pgraph_surface_create_zeta :
                                     trace_nv2a_pgraph_surface_hit_zeta);
        trace_fn(surface->vram_addr, surface->width, surface->height,
                 surface->swizzle ? "sz" : "ln", surface->shape.anti_aliasing,
                 surface->shape.clip_x, surface->shape.clip_width,
                 surface->shape.clip_y, surface->shape.clip_height, surface->pitch);

        bind_surface(r, surface);

        pgraph_rt_memo_store(&r->rt_memo, color,
                             color ? pg->dma_color : pg->dma_zeta,
                             pg_surface->offset, pg_surface->pitch, surface);
        pg_surface->buffer_dirty = false;
    }

    if (!upload && pg_surface->draw_dirty) {
        if (!tcg_enabled()) {
            // FIXME: Cannot monitor for reads/writes; flush now
            VK_SURF_SITE();
            download_surface(d, color ? r->color_binding : r->zeta_binding,
                             true);
        }

        pg_surface->write_enabled_cache = false;
        pg_surface->draw_dirty = false;
    }
}

// FIXME: Move to common?
static void touch_bound_surface(NV2AState *d, SurfaceBinding *s, bool upload,
                                bool swizzle)
{
    s->frame_time = d->pgraph.frame_time;
    if (upload) {
        pgraph_vk_upload_surface_data(d, s, false);
        s->draw_time = d->pgraph.draw_time;
        s->swizzle = swizzle;
    }
}

/* The bound surfaces serve this frame, and on upload this draw, with their
 * RAM content brought in. */
static void touch_bound_surfaces(NV2AState *d, bool upload)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    if (upload) {
        pg->draw_time++;
    }
    bool swizzle = (pg->surface_type == NV097_SET_SURFACE_FORMAT_TYPE_SWIZZLE);
    if (r->color_binding) {
        touch_bound_surface(d, r->color_binding, upload, swizzle);
    }
    if (r->zeta_binding) {
        touch_bound_surface(d, r->zeta_binding, upload, swizzle);
    }
}

void pgraph_vk_surface_update(NV2AState *d, bool upload, bool color_write,
                              bool zeta_write)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    pg->surface_shape.z_format =
        GET_MASK(pgraph_reg_r(pg, NV_PGRAPH_SETUPRASTER),
                 NV_PGRAPH_SETUPRASTER_Z_FORMAT);

    color_write = color_write &&
            (pg->clearing || pgraph_color_write_enabled(pg));
    zeta_write = zeta_write && (pg->clearing || pgraph_zeta_write_enabled(pg));

    if (upload) {
        bool fb_dirty = framebuffer_dirty(pg);
        /* Fast path, as on GL: registers, buffers, write masks, surface
         * type and bindings unchanged, so the full pass would change
         * nothing. TCG only: otherwise the dirty-memory test must run. */
        if (tcg_enabled() && !fb_dirty &&
            !pg->surface_color.buffer_dirty &&
            !pg->surface_zeta.buffer_dirty &&
            color_write == r->last_color_write &&
            zeta_write == r->last_zeta_write &&
            pg->surface_type == r->last_surface_type &&
            (!color_write || r->color_binding) &&
            (!zeta_write || r->zeta_binding)) {
            touch_bound_surfaces(d, true);
            return;
        }
        r->last_color_write = color_write;
        r->last_zeta_write = zeta_write;
        r->last_surface_type = pg->surface_type;
        if (fb_dirty) {
            memcpy(&pg->last_surface_shape, &pg->surface_shape,
                   sizeof(SurfaceShape));
            pg->surface_color.buffer_dirty = true;
            pg->surface_zeta.buffer_dirty = true;
            r->rt_memo.shape_gen++;
        }

        if (pg->surface_color.buffer_dirty) {
            unbind_surface(d, true);
        }

        if (color_write) {
            update_surface_part(d, true, true);
        }

        if (pg->surface_zeta.buffer_dirty) {
            unbind_surface(d, false);
        }

        if (zeta_write) {
            update_surface_part(d, true, false);
        }
    } else {
        if ((color_write || pg->surface_color.write_enabled_cache)
            && pg->surface_color.draw_dirty) {
            update_surface_part(d, false, true);
        }
        if ((zeta_write || pg->surface_zeta.write_enabled_cache)
            && pg->surface_zeta.draw_dirty) {
            update_surface_part(d, false, false);
        }
    }

    touch_bound_surfaces(d, upload);

    /* A larger zeta kept for a smaller color target can stop covering it:
     * a color target bound by the draw pass (no upload: nothing unbinds the
     * zeta there) can be swizzled, of another AA or larger than the zeta,
     * and the touch above marks both bound surfaces with the surface type
     * now set, so a linear zeta becomes swizzled when the game switches to
     * a swizzled target (Virtua Cop 3, NFL Fever 2004, NNshi). The zeta is
     * bound again for it, as the upload pass does after a color change. */
    if (r->color_binding && r->zeta_binding &&
        !zeta_covers_color(r, r->zeta_binding)) {
        pg->surface_zeta.buffer_dirty = true;
        unbind_surface(d, false);
        if (zeta_write || pg->surface_zeta.write_enabled_cache) {
            update_surface_part(d, upload, false);
            if (r->zeta_binding) {
                touch_bound_surface(d, r->zeta_binding, upload,
                                    pg->surface_type ==
                                        NV097_SET_SURFACE_FORMAT_TYPE_SWIZZLE);
            }
        }
    }

    /* A retained zeta may be larger; the framebuffer uses the color size. */
    if (r->color_binding && r->zeta_binding) {
        assert(zeta_covers_color(r, r->zeta_binding));
    }

    /* Expiry counts in frames, so once per frame decides the same; the
     * pruning rides along, letting the invalid list grow within a frame. */
    if (r->expire_frame_time != pg->frame_time) {
        r->expire_frame_time = pg->frame_time;
        expire_old_surfaces(d);
        prune_invalid_surfaces(r, num_invalid_surfaces_to_keep);
    }
}

static bool check_format_and_usage_supported(PGRAPHVkState *r, VkFormat format,
                                             VkImageUsageFlags usage)
{
    VkPhysicalDeviceImageFormatInfo2 pdif2 = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2,
        .format = format,
        .type = VK_IMAGE_TYPE_2D,
        .tiling = VK_IMAGE_TILING_OPTIMAL,
        .usage = usage,
    };
    VkImageFormatProperties2 props = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2,
    };
    VkResult result = vkGetPhysicalDeviceImageFormatProperties2(
        r->physical_device, &pdif2, &props);
    return result == VK_SUCCESS;
}

static bool check_surface_internal_formats_supported(
    PGRAPHVkState *r, const SurfaceFormatInfo *fmts, size_t count)
{
    bool all_supported = true;
    for (int i = 0; i < count; i++) {
        const SurfaceFormatInfo *f = &fmts[i];
        if (f->host_bytes_per_pixel) {
            all_supported &=
                check_format_and_usage_supported(r, f->vk_format, f->usage);
        }
    }
    return all_supported;
}

void pgraph_vk_init_surfaces(PGRAPHState *pg)
{
    PGRAPHVkState *r = pg->vk_renderer_state;

    // Make sure all surface format types are supported. We don't expect issue
    // with these, and therefore have no fallback mechanism.
    bool color_formats_supported = check_surface_internal_formats_supported(
        r, kelvin_surface_color_format_vk_map,
        ARRAY_SIZE(kelvin_surface_color_format_vk_map));
    assert(color_formats_supported);

    // Check if the device supports preferred VK_FORMAT_D24_UNORM_S8_UINT
    // format, fall back to D32_SFLOAT_S8_UINT otherwise.
    r->kelvin_surface_zeta_vk_map[NV097_SET_SURFACE_FORMAT_ZETA_Z16] = zeta_d16;
    if (check_surface_internal_formats_supported(r, &zeta_d24_unorm_s8_uint,
                                                 1)) {
        r->kelvin_surface_zeta_vk_map[NV097_SET_SURFACE_FORMAT_ZETA_Z24S8] =
            zeta_d24_unorm_s8_uint;
    } else if (check_surface_internal_formats_supported(
                   r, &zeta_d32_sfloat_s8_uint, 1)) {
        r->kelvin_surface_zeta_vk_map[NV097_SET_SURFACE_FORMAT_ZETA_Z24S8] =
            zeta_d32_sfloat_s8_uint;
    } else {
        assert(!"No suitable depth-stencil format supported");
    }

    QTAILQ_INIT(&r->surfaces);
    QTAILQ_INIT(&r->invalid_surfaces);

    r->downloads_pending = false;
    qemu_event_init(&r->downloads_complete, false);
    qemu_event_init(&r->dirty_surfaces_download_complete, false);

    r->color_binding = NULL;
    r->zeta_binding = NULL;
    r->framebuffer_dirty = true;
    memset(&r->rt_memo, 0, sizeof(r->rt_memo));
    r->rt_switches = 0;
    r->eager_interval = r->eager_count = 0;

    pgraph_vk_reload_surface_scale_factor(pg); // FIXME: Move internal
}

void pgraph_vk_finalize_surfaces(PGRAPHState *pg)
{
    pgraph_vk_surface_flush(container_of(pg, NV2AState, pgraph));
    kind_finalize(pg->vk_renderer_state);
}

void pgraph_vk_surface_flush(NV2AState *d)
{
    PGRAPHState *pg = &d->pgraph;
    PGRAPHVkState *r = pg->vk_renderer_state;

    // Clear last surface shape to force recreation of buffers at next draw
    pg->surface_color.draw_dirty = false;
    pg->surface_zeta.draw_dirty = false;
    memset(&pg->last_surface_shape, 0, sizeof(pg->last_surface_shape));
    unbind_surface(d, true);
    unbind_surface(d, false);

    SurfaceBinding *s, *next;
    QTAILQ_FOREACH_SAFE(s, &r->surfaces, entry, next) {
        // FIXME: We should download all surfaces to ram, but need to
        //        investigate corruption issue
        pgraph_vk_surface_download_if_dirty(d, s);
        invalidate_surface(d, s);
    }
    /* After a snapshot load or a reset RAM is authoritative: an owed
     * writeback goes without being written, and what was learnt of the old
     * RAM is forgotten. A scale change has settled them all beforehand; at
     * a renderer switch RAM is live, and the prune below writes them back. */
    if (pg->renderer_switch_phase != PGRAPH_RENDERER_SWITCH_PHASE_CPU_WAITING) {
        QTAILQ_FOREACH(s, &r->invalid_surfaces, entry) {
            if (s->writeback_owed) {
                parked_owed_settled(d, s);
            }
        }
    }
    pgraph_writeback_reset(pg);
    prune_invalid_surfaces(r, 0);

    pgraph_vk_reload_surface_scale_factor(pg);
    pgraph_vk_reserve_compute_buffers(pg, pg->surface_scale_base);
}
