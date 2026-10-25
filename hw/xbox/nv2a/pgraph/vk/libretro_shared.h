/*
 * The Vulkan device the libretro core shares with its frontend
 *
 * RetroArch lets a core make the device it then draws with (context
 * negotiation). ui/libretro.c makes it with what RetroArch asks for and what
 * this renderer needs, and the renderer takes it over here in place of an
 * instance and device of its own - so a frame is handed to RetroArch as an
 * image on the same device, without exporting memory to a second one.
 *
 * Include after the Vulkan headers (volk.h or libretro_vulkan.h).
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef HW_XBOX_NV2A_PGRAPH_VK_LIBRETRO_SHARED_H
#define HW_XBOX_NV2A_PGRAPH_VK_LIBRETRO_SHARED_H

#ifdef LIBRETRO

#include <stdbool.h>
#include <stdint.h>

/* A frame's image for each of the frontend's sync indices at most */
#define XEMU_LIBRETRO_VK_FRAMES 8

typedef struct XemuLibretroVk {
    /* Set by create_device (ui/libretro.c) once the device is made; the
     * renderer starts after it */
    bool active;

    PFN_vkGetInstanceProcAddr get_instance_proc_addr;
    VkInstance instance;
    VkPhysicalDevice gpu;
    VkDevice device;
    uint32_t api_version;

    /* The renderer's queue: one of its own where the family has two, else
     * the frontend's, taken under its lock */
    uint32_t queue_family;
    VkQueue queue;
    bool queue_shared;

    /* What the device was made with */
    VkPhysicalDeviceFeatures features;
    bool custom_border_color;
    bool memory_budget;
    /* and the fast paths' extensions and features (create_logical_device
     * decides the same for a device of the renderer's own) */
    bool dyn_cull_front, dyn_blend, dyn_vertex_input;
    bool pipeline_library;
    bool host_query_reset;
    bool shader_demote;

    /* Which of the frame images the next display render fills: the
     * frontend's sync index, set by retro_run before it asks for a frame */
    int frame_index;
} XemuLibretroVk;

/* The frontend's context is set up (context_reset has run): the renderer
 * starts only then, as the emulation thread is started before the frontend
 * has made its device. Not part of the struct, which create_device clears. */
extern bool xemu_libretro_vk_context_ready;

extern XemuLibretroVk xemu_libretro_vk;

/* The frontend's queue lock, around every use of a shared queue; no-ops
 * while the renderer has a queue of its own */
void xemu_libretro_vk_lock_queue(void);
void xemu_libretro_vk_unlock_queue(void);

/* The frame image of a sync index: an image on the shared device, in
 * SHADER_READ_ONLY_OPTIMAL, its GPU work finished (ui/libretro.c hands it to
 * the frontend). False until a frame was rendered for that index. *count is
 * the number of frames rendered so far: unchanged since the last call, the
 * display was not rendered again and the image holds an older frame. */
/* The count of pictures handed over that showed another guest frame than the
 * one before them */
uint64_t nv2a_vk_libretro_guest_frames(void);
bool nv2a_vk_libretro_get_frame(int index, VkImage *image, VkImageView *view,
                                VkFormat *format, int *width, int *height,
                                uint64_t *count);

#endif /* LIBRETRO */

#endif
