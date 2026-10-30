/*
 * xemu libretro core wrapper
 *
 * Copyright (c) 2025
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "qemu/osdep.h"
#include "qemu/main-loop.h"
#include "qemu/thread.h"
#include "system/system.h"
#include "system/runstate.h"
#include "qapi/error.h"
#include "system/cpus.h"
#include "migration/snapshot.h"
#include "ui/console.h"
#include "hw/xbox/nv2a/nv2a.h"
#include "hw/xbox/xemu-anisotropy.h"
#include "hw/xbox/chihiro/chihiro.h"
#include "libretro-crosshair.h"
#include "ui/xemu-widescreen.h"
#include "system/blockdev.h"
#include "system/block-backend.h"
#include "block/block.h"
#include "block/snapshot.h"
#include "block/graph-lock.h"
#include "qobject/qdict.h"
#include <glib/gstdio.h>
#include <zlib.h>
#include "ui/libretro-widescreen-titles.h"
#include "ui/libretro-xdb-titles.h"
#include "xemu-xbe.h"
#include "qemu/bswap.h"
#include "data/xbox_hdd.qcow2.h"

#include <epoxy/gl.h>
#ifndef _WIN32
#include <dlfcn.h>
#endif

#include "libretro.h"
#if defined(_WIN32) && !defined(VK_USE_PLATFORM_WIN32_KHR)
#define VK_USE_PLATFORM_WIN32_KHR
#endif
#include "libretro_vulkan.h"
#include "hw/xbox/nv2a/pgraph/vk/libretro_shared.h"
#include "libretro_core_options.h"
#include "xemu-settings.h"
#include "xemu-version.h"

/* ========================================================================= */
/* Libretro callback storage                                                 */
/* ========================================================================= */

static retro_environment_t        environ_cb   = NULL;
static retro_video_refresh_t      video_cb     = NULL;
static retro_audio_sample_t       audio_cb     = NULL;
static retro_audio_sample_batch_t audio_batch_cb = NULL;
/* Audio > Audio Thread: taken at load; whether RetroArch then calls
 * audio_thread_callback on its audio thread (SET_AUDIO_CALLBACK) */
static bool opt_audio_thread = true;
static bool audio_async = false;
static bool audio_async_enabled = false;
static retro_input_poll_t         input_poll_cb  = NULL;
retro_input_state_t               input_state_cb = NULL; /* non-static: used by libretro-stubs.c */
static retro_log_printf_t         log_cb       = NULL;

/* ========================================================================= */
/* Libretro log wrapper - use this instead of fprintf(stderr, ...)           */
/* ========================================================================= */

#define LRLOG_INFO(...)  do { if (log_cb) log_cb(RETRO_LOG_INFO,  __VA_ARGS__); } while(0)
#define LRLOG_WARN(...)  do { if (log_cb) log_cb(RETRO_LOG_WARN,  __VA_ARGS__); } while(0)
#define LRLOG_ERROR(...) do { if (log_cb) log_cb(RETRO_LOG_ERROR, __VA_ARGS__); } while(0)
#define LRLOG_DEBUG(...) do { if (log_cb) log_cb(RETRO_LOG_DEBUG, __VA_ARGS__); } while(0)

/* ========================================================================= */
/* VFS interface (optional)                                                  */
/* ========================================================================= */

/* also read by block/libretro-vfs.c, the DVD drive's driver for saf:// */
struct retro_vfs_interface *xemu_libretro_vfs = NULL;

/* ========================================================================= */
/* Hardware rendering state                                                  */
/* ========================================================================= */

static struct retro_hw_render_callback hw_render;
/* The largest frame the frontend was told to expect: the Xbox's largest
 * output, 1920x1080, times the Internal Resolution Scale (xemu_max_geometry).
 * Not the 10x of the highest scale for everyone: RetroArch sizes its shader
 * passes' framebuffers by it, and at 6400x4800 a multi-pass preset took
 * gigabytes of video memory (8192x8192 passes; NNshi: Dead or Alive 3 black,
 * Panzer Dragoon Orta stuck loading). */
static unsigned declared_max_width = 1920;
static unsigned declared_max_height = 1080;

static bool use_vulkan = false;
static struct retro_rumble_interface rumble;
/* Graphics API option: Vulkan unless set to OpenGL (read at load) */
static bool opt_renderer_vulkan = true;
static bool context_ready = false;
static bool game_loaded = false;

/* GL blit shader state */
static GLuint blit_program = 0;
static GLuint blit_vao = 0;
static GLint  blit_tex_loc = -1;

/* Vulkan HW render interface from RetroArch */
static struct retro_hw_render_interface_vulkan *vulkan_if = NULL;

/* RA-side VK resources: xemu's display image imported into RA's VkDevice */
static VkImage ra_vk_image = VK_NULL_HANDLE;
static VkImageView ra_vk_image_view = VK_NULL_HANDLE;
static VkDeviceMemory ra_vk_memory = VK_NULL_HANDLE;
static uint32_t ra_vk_width = 0, ra_vk_height = 0;
static void *ra_last_handle = NULL;
static struct retro_vulkan_image retro_vk_image;
/* The Vulkan renderer is off the shared device (vk_park_renderer) */
static bool vk_renderer_parked;
static VkImageViewCreateInfo ra_vk_view_ci;

/* VK function pointers from RA's device (not xemu's) */
static PFN_vkCreateImage ra_vkCreateImage;
static PFN_vkDestroyImage ra_vkDestroyImage;
static PFN_vkCreateImageView ra_vkCreateImageView;
static PFN_vkDestroyImageView ra_vkDestroyImageView;
static PFN_vkAllocateMemory ra_vkAllocateMemory;
static PFN_vkFreeMemory ra_vkFreeMemory;
static PFN_vkBindImageMemory ra_vkBindImageMemory;
static PFN_vkGetImageMemoryRequirements ra_vkGetImageMemoryRequirements;
static PFN_vkGetPhysicalDeviceMemoryProperties ra_vkGetPhysicalDeviceMemoryProperties;
static PFN_vkCreateCommandPool ra_vkCreateCommandPool;
static PFN_vkDestroyCommandPool ra_vkDestroyCommandPool;
static PFN_vkAllocateCommandBuffers ra_vkAllocateCommandBuffers;
static PFN_vkFreeCommandBuffers ra_vkFreeCommandBuffers;
static PFN_vkBeginCommandBuffer ra_vkBeginCommandBuffer;
static PFN_vkEndCommandBuffer ra_vkEndCommandBuffer;
static PFN_vkQueueSubmit ra_vkQueueSubmit;
static PFN_vkQueueWaitIdle ra_vkQueueWaitIdle;
static PFN_vkCmdPipelineBarrier ra_vkCmdPipelineBarrier;
static PFN_vkCreateFence ra_vkCreateFence;
static PFN_vkDestroyFence ra_vkDestroyFence;
static PFN_vkWaitForFences ra_vkWaitForFences;
static PFN_vkResetFences ra_vkResetFences;
static PFN_vkResetCommandBuffer ra_vkResetCommandBuffer;
static VkCommandPool ra_vk_cmd_pool = VK_NULL_HANDLE;
static VkCommandBuffer ra_vk_cmds[2] = { VK_NULL_HANDLE, VK_NULL_HANDLE };
static VkFence ra_vk_fences[2] = { VK_NULL_HANDLE, VK_NULL_HANDLE };
static uint32_t ra_vk_frame_idx = 0;
static bool ra_vk_funcs_resolved = false;

/* Standalone GL for VK renderer's internal GL interop (PFIFO thread) */
typedef struct _GloContext GloContext;
extern GloContext *glo_context_create(void);
extern void glo_set_current(GloContext *context);

/* ========================================================================= */
/* Emulation state                                                           */
/* ========================================================================= */

static bool emu_initialized = false;
/* QEMU was started in this process (retro_load_game), and with which
 * renderer: the machine stays built, and the next content runs on it */
static bool emu_started_once = false;
static bool emu_started_vulkan = false;
/* and whether that machine is a Chihiro rather than an Xbox, and the
 * Chihiro's game */
static bool emu_started_chihiro = false;
static char emu_started_image[4096];
static QemuThread emu_thread;
static volatile bool emu_thread_running = false;

/* When retro_run last started, and whether the machine is stopped because
 * it did not come: the frontend's menu or pause. The guest's vblank comes
 * with retro_run, so while the menu was open the CPU ran on without frames,
 * and a game coming back from it could take its disc reads for failed
 * (Akrido: Ninja Gaiden's dirty disc error after the menu). Stopped the way
 * standalone pauses, and started again with the next retro_run. */
static int64_t last_run_us;
static bool frontend_paused;
/* about 3 frames: the guest runs on that long after the frontend stopped,
 * as RetroArch says nothing of its menu or pause (NNshi) */
#define FRONTEND_PAUSE_US 50000

/* Snapshot dispatch: RetroArch thread requests, QEMU thread executes */
enum {
    SNAPSHOT_NONE = 0,
    SNAPSHOT_SAVE,
    SNAPSHOT_LOAD,
};
static volatile int snapshot_request = SNAPSHOT_NONE;
static volatile bool snapshot_done = false;
static volatile bool snapshot_result = false;
/* The emu thread posts it when it has handled a snapshot request. QEMU's
 * semaphore rather than a Win32 event, so it builds everywhere. */
static QemuSemaphore snapshot_done_sem;
static bool snapshot_sem_initialized = false;

/* ========================================================================= */
/* Core option values                                                        */
/* ========================================================================= */

static char opt_bootrom_path[4096] = "";
static char opt_bios_path[4096] = "";
static char opt_hdd_path[4096] = "";
/* Trim HDD on Close (hdd_trim) */
static bool opt_hdd_trim = false;
static void hdd_trim(void);
static char opt_eeprom_path[4096] = "";
static char opt_dvd_path[4096] = "";
static char system_dir[4096] = "";
bool xemu_libretro_has_xbe_patches(const char *image);
static int  opt_memory_mb = 64;
static bool opt_skip_boot_anim = true;
static bool opt_hard_fpu = true;
/* The fork's CPU boost and smooth first play (Tovarichtch/xemu), on by
 * default there */
static bool opt_cpu_boost = true;
static bool opt_smooth_first_play = true;
static bool opt_chihiro_freeplay = true;
/* Video > Vulkan Fast Paths: which of the renderer's fast-path features the
 * shared device may get (xemu_vk_create_device) */
static bool opt_vk_gpl = false, opt_vk_dynamic = true;
static int opt_chihiro_ffb = 100; /* percent, 0 = off */
extern bool libretro_chihiro_aim_stick;   /* libretro-chihiro.c */
extern bool libretro_chihiro_crosshair;
static bool opt_use_dsp = false;
static int  opt_surface_scale = 1;
static int  opt_avpack = CONFIG_SYS_AVPACK_HDTV;
/* OpenGL's shader cache, always on, as Vulkan's is (NNshi): turning it off
 * only made the next start compile everything again */
static const bool opt_cache_shaders = true;
/* audio.use_dsp_jit, audio.hrtf and audio.vp.num_workers, as standalone's
 * defaults; the JIT and HRTF are read as the audio runs, the threads when the
 * voice processor starts */
static bool opt_dsp_jit = false;
static bool opt_hrtf = true;
static int  opt_vp_workers = 0;
static int  opt_audio_volume = 100;
static int  opt_network_backend = 0; /* 0=disabled, 1=nat */

/* ========================================================================= */
/* Forward declarations                                                      */
/* ========================================================================= */

static void context_reset(void);
static void context_destroy(void);
static void update_variables(void);
static void xemu_max_geometry(int scale, unsigned *width, unsigned *height);
static void create_blit_resources(void);
static void destroy_blit_resources(void);
static void blit_nv2a_texture(GLuint tex, unsigned width, unsigned height, uintptr_t fbo);

/* ========================================================================= */
/* GL Blit Shader (fullscreen triangle, Y-flip for libretro top-left origin) */
/* ========================================================================= */

static const char *blit_vs_src =
    "#version 330 core\n"
    "out vec2 vTexCoord;\n"
    "void main() {\n"
    "    float x = -1.0 + float((gl_VertexID & 1) << 2);\n"
    "    float y = -1.0 + float((gl_VertexID & 2) << 1);\n"
    "    gl_Position = vec4(x, y, 0.0, 1.0);\n"
    "    vTexCoord = vec2((x + 1.0) * 0.5, (y + 1.0) * 0.5);\n"
    "}\n";

static const char *blit_fs_src =
    "#version 330 core\n"
    "in vec2 vTexCoord;\n"
    "uniform sampler2D uTex;\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "    FragColor = texture(uTex, vTexCoord);\n"
    "}\n";

static GLuint compile_shader(GLenum type, const char *src)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    GLint status = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (!status) {
        char info[512];
        glGetShaderInfoLog(shader, sizeof(info), NULL, info);
        LRLOG_ERROR("[xemu] Shader compile error: %s\n", info);
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

static void create_blit_resources(void)
{
    LRLOG_INFO("[xemu] Creating GL blit resources\n");

    GLuint vs = compile_shader(GL_VERTEX_SHADER, blit_vs_src);
    GLuint fs = compile_shader(GL_FRAGMENT_SHADER, blit_fs_src);
    if (!vs || !fs) {
        LRLOG_ERROR("[xemu] Failed to compile blit shaders\n");
        if (vs) glDeleteShader(vs);
        if (fs) glDeleteShader(fs);
        return;
    }

    blit_program = glCreateProgram();
    glAttachShader(blit_program, vs);
    glAttachShader(blit_program, fs);
    glLinkProgram(blit_program);

    GLint status = 0;
    glGetProgramiv(blit_program, GL_LINK_STATUS, &status);
    if (!status) {
        char info[512];
        glGetProgramInfoLog(blit_program, sizeof(info), NULL, info);
        LRLOG_ERROR("[xemu] Shader link error: %s\n", info);
        glDeleteProgram(blit_program);
        blit_program = 0;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    blit_tex_loc = glGetUniformLocation(blit_program, "uTex");

    glGenVertexArrays(1, &blit_vao);

    LRLOG_INFO("[xemu] GL blit resources created (program=%u, vao=%u)\n",
               blit_program, blit_vao);
}

static void destroy_blit_resources(void)
{
    if (blit_program) {
        glDeleteProgram(blit_program);
        blit_program = 0;
    }
    if (blit_vao) {
        glDeleteVertexArrays(1, &blit_vao);
        blit_vao = 0;
    }
}

static void blit_nv2a_texture(GLuint tex, unsigned width, unsigned height, uintptr_t fbo)
{
    if (!blit_program || !blit_vao || !tex) return;

    glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)fbo);
    glViewport(0, 0, width, height);

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_STENCIL_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    glDisable(GL_SCISSOR_TEST);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(blit_program);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glUniform1i(blit_tex_loc, 0);

    glBindVertexArray(blit_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    /* Clean up state per libretro docs */
    glBindVertexArray(0);
    glUseProgram(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

/* The gun games' crosshairs (libretro-crosshair.h) over the OpenGL frame, as
 * the Vulkan frame copy draws them (pgraph/vk/display.c): a plus sign with a
 * black outline, player 1 red, player 2 blue. The frame's origin is bottom
 * left. */
static void draw_gl_crosshairs(unsigned width, unsigned height, uintptr_t fbo)
{
    static const float colors[3][3] = {
        { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.16f, 0.16f }, { 0.16f, 0.55f, 1.0f },
    };
    if (!xemu_libretro_crosshairs[0].shown &&
        !xemu_libretro_crosshairs[1].shown) {
        return;
    }
    const int arm = MIN(MAX((int)height / 40, 6), 40);
    const int thick = MIN(MAX((int)height / 240, 2), 6);

    glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)fbo);
    glEnable(GL_SCISSOR_TEST);
    for (int pass = 0; pass < 2; pass++) {
        for (int p = 0; p < 2; p++) {
            const XemuLibretroCrosshair *c = &xemu_libretro_crosshairs[p];
            if (!c->shown) {
                continue;
            }
            const int cx = (int)(c->x * width);
            const int cy = (int)((1.0f - c->y) * height);
            const int edge = pass ? 0 : 1;
            const float *rgb = colors[pass ? 1 + p : 0];
            const int len = 2 * arm + 1 + 2 * edge, t = thick + 2 * edge;
            glClearColor(rgb[0], rgb[1], rgb[2], 1.0f);
            glScissor(cx - arm - edge, cy - t / 2, len, t);
            glClear(GL_COLOR_BUFFER_BIT);
            glScissor(cx - t / 2, cy - arm - edge, t, len);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
    glDisable(GL_SCISSOR_TEST);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

/* ========================================================================= */
/* Vulkan HW render helpers                                                  */
/* ========================================================================= */

static void ra_vk_resolve_functions(void)
{
    if (!vulkan_if || ra_vk_funcs_resolved) return;

    PFN_vkGetDeviceProcAddr gdpa = vulkan_if->get_device_proc_addr;
    PFN_vkGetInstanceProcAddr gipa = vulkan_if->get_instance_proc_addr;
    VkDevice dev = vulkan_if->device;
    VkInstance inst = vulkan_if->instance;

    ra_vkCreateImage = (PFN_vkCreateImage)gdpa(dev, "vkCreateImage");
    ra_vkDestroyImage = (PFN_vkDestroyImage)gdpa(dev, "vkDestroyImage");
    ra_vkCreateImageView = (PFN_vkCreateImageView)gdpa(dev, "vkCreateImageView");
    ra_vkDestroyImageView = (PFN_vkDestroyImageView)gdpa(dev, "vkDestroyImageView");
    ra_vkAllocateMemory = (PFN_vkAllocateMemory)gdpa(dev, "vkAllocateMemory");
    ra_vkFreeMemory = (PFN_vkFreeMemory)gdpa(dev, "vkFreeMemory");
    ra_vkBindImageMemory = (PFN_vkBindImageMemory)gdpa(dev, "vkBindImageMemory");
    ra_vkGetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)gdpa(dev, "vkGetImageMemoryRequirements");
    ra_vkGetPhysicalDeviceMemoryProperties = (PFN_vkGetPhysicalDeviceMemoryProperties)gipa(inst, "vkGetPhysicalDeviceMemoryProperties");
    ra_vkCreateCommandPool = (PFN_vkCreateCommandPool)gdpa(dev, "vkCreateCommandPool");
    ra_vkDestroyCommandPool = (PFN_vkDestroyCommandPool)gdpa(dev, "vkDestroyCommandPool");
    ra_vkAllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)gdpa(dev, "vkAllocateCommandBuffers");
    ra_vkFreeCommandBuffers = (PFN_vkFreeCommandBuffers)gdpa(dev, "vkFreeCommandBuffers");
    ra_vkBeginCommandBuffer = (PFN_vkBeginCommandBuffer)gdpa(dev, "vkBeginCommandBuffer");
    ra_vkEndCommandBuffer = (PFN_vkEndCommandBuffer)gdpa(dev, "vkEndCommandBuffer");
    ra_vkQueueSubmit = (PFN_vkQueueSubmit)gdpa(dev, "vkQueueSubmit");
    ra_vkQueueWaitIdle = (PFN_vkQueueWaitIdle)gdpa(dev, "vkQueueWaitIdle");
    ra_vkCmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)gdpa(dev, "vkCmdPipelineBarrier");
    ra_vkCreateFence = (PFN_vkCreateFence)gdpa(dev, "vkCreateFence");
    ra_vkDestroyFence = (PFN_vkDestroyFence)gdpa(dev, "vkDestroyFence");
    ra_vkWaitForFences = (PFN_vkWaitForFences)gdpa(dev, "vkWaitForFences");
    ra_vkResetFences = (PFN_vkResetFences)gdpa(dev, "vkResetFences");
    ra_vkResetCommandBuffer = (PFN_vkResetCommandBuffer)gdpa(dev, "vkResetCommandBuffer");

    ra_vk_funcs_resolved = (ra_vkCreateImage && ra_vkDestroyImage &&
                            ra_vkCreateImageView && ra_vkDestroyImageView &&
                            ra_vkAllocateMemory && ra_vkFreeMemory &&
                            ra_vkBindImageMemory && ra_vkGetImageMemoryRequirements &&
                            ra_vkGetPhysicalDeviceMemoryProperties &&
                            ra_vkCreateCommandPool && ra_vkAllocateCommandBuffers &&
                            ra_vkBeginCommandBuffer && ra_vkEndCommandBuffer &&
                            ra_vkQueueSubmit && ra_vkCmdPipelineBarrier &&
                            ra_vkCreateFence && ra_vkWaitForFences &&
                            ra_vkResetFences && ra_vkResetCommandBuffer);

    if (ra_vk_funcs_resolved && ra_vk_cmd_pool == VK_NULL_HANDLE) {
        VkCommandPoolCreateInfo pool_ci = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
            .flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
            .queueFamilyIndex = vulkan_if->queue_index,
        };
        ra_vkCreateCommandPool(dev, &pool_ci, NULL, &ra_vk_cmd_pool);

        VkCommandBufferAllocateInfo cmd_ai = {
            .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
            .commandPool = ra_vk_cmd_pool,
            .level = VK_COMMAND_BUFFER_LEVEL_PRIMARY,
            .commandBufferCount = 2,
        };
        ra_vkAllocateCommandBuffers(dev, &cmd_ai, ra_vk_cmds);

        VkFenceCreateInfo fence_ci = {
            .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
            .flags = VK_FENCE_CREATE_SIGNALED_BIT,
        };
        ra_vkCreateFence(dev, &fence_ci, NULL, &ra_vk_fences[0]);
        ra_vkCreateFence(dev, &fence_ci, NULL, &ra_vk_fences[1]);
    }
}

static uint32_t ra_vk_find_memory_type(uint32_t type_bits, VkMemoryPropertyFlags props)
{
    VkPhysicalDeviceMemoryProperties mem_props;
    ra_vkGetPhysicalDeviceMemoryProperties(vulkan_if->gpu, &mem_props);
    for (uint32_t i = 0; i < mem_props.memoryTypeCount; i++) {
        if ((type_bits & (1 << i)) &&
            (mem_props.memoryTypes[i].propertyFlags & props) == props) {
            return i;
        }
    }
    return 0;
}

static void ra_vk_transition_layout(VkImage image, VkImageLayout old_layout, VkImageLayout new_layout)
{
    if (!vulkan_if || !ra_vk_funcs_resolved) return;

    uint32_t idx = ra_vk_frame_idx;
    VkCommandBuffer cmd = ra_vk_cmds[idx];
    VkFence fence = ra_vk_fences[idx];
    if (!cmd || !fence) return;

    VkDevice dev = vulkan_if->device;

    /* Wait for THIS slot's fence (from 2 frames ago — should be instant) */
    ra_vkWaitForFences(dev, 1, &fence, VK_TRUE, UINT64_MAX);
    ra_vkResetFences(dev, 1, &fence);
    ra_vkResetCommandBuffer(cmd, 0);

    VkCommandBufferBeginInfo begin_info = {
        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        .flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT,
    };
    ra_vkBeginCommandBuffer(cmd, &begin_info);

    VkImageMemoryBarrier barrier = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,
        .oldLayout = old_layout,
        .newLayout = new_layout,
        .srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED,
        .image = image,
        .subresourceRange = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .levelCount = 1,
            .layerCount = 1,
        },
        .srcAccessMask = 0,
        .dstAccessMask = VK_ACCESS_SHADER_READ_BIT,
    };

    ra_vkCmdPipelineBarrier(cmd,
        VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
        VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
        0, 0, NULL, 0, NULL, 1, &barrier);

    ra_vkEndCommandBuffer(cmd);

    VkSubmitInfo submit = {
        .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
        .commandBufferCount = 1,
        .pCommandBuffers = &cmd,
    };

    vulkan_if->lock_queue(vulkan_if->handle);
    ra_vkQueueSubmit(vulkan_if->queue, 1, &submit, fence);
    vulkan_if->unlock_queue(vulkan_if->handle);

    /* Flip to other slot for next frame */
    ra_vk_frame_idx = 1 - idx;
}

static void ra_vk_cleanup_display(void)
{
    if (!vulkan_if) return;
    VkDevice dev = vulkan_if->device;

    if (ra_vk_image_view != VK_NULL_HANDLE) {
        ra_vkDestroyImageView(dev, ra_vk_image_view, NULL);
        ra_vk_image_view = VK_NULL_HANDLE;
    }
    if (ra_vk_image != VK_NULL_HANDLE) {
        ra_vkDestroyImage(dev, ra_vk_image, NULL);
        ra_vk_image = VK_NULL_HANDLE;
    }
    if (ra_vk_memory != VK_NULL_HANDLE) {
        ra_vkFreeMemory(dev, ra_vk_memory, NULL);
        ra_vk_memory = VK_NULL_HANDLE;
    }
    ra_vk_width = 0;
    ra_vk_height = 0;
    ra_last_handle = NULL;
}

static bool ra_vk_import_display(void *ext_handle, int width, int height)
{
    if (!vulkan_if || !ra_vk_funcs_resolved || !ext_handle || !width || !height)
        return false;

    VkDevice dev = vulkan_if->device;

    /* Cleanup old resources if size changed */
    if (ra_vk_image != VK_NULL_HANDLE &&
        ((uint32_t)width != ra_vk_width || (uint32_t)height != ra_vk_height)) {
        ra_vk_cleanup_display();
    }

    /* Already imported this handle at this size */
    if (ra_vk_image != VK_NULL_HANDLE && ext_handle == ra_last_handle)
        return true;

    ra_vk_cleanup_display();

    /* Create VkImage on RA's device with external memory import */
    VkExternalMemoryImageCreateInfo ext_img_ci = {
        .sType = VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO,
#ifdef _WIN32
        .handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT,
#else
        .handleTypes = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT,
#endif
    };

    VkImageCreateInfo img_ci = {
        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
        .pNext = &ext_img_ci,
        .flags = VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT,
        .imageType = VK_IMAGE_TYPE_2D,
        .format = VK_FORMAT_R8G8B8A8_UNORM,
        .extent = { width, height, 1 },
        .mipLevels = 1,
        .arrayLayers = 1,
        .samples = VK_SAMPLE_COUNT_1_BIT,
        .tiling = VK_IMAGE_TILING_OPTIMAL,
        .usage = VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
        .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
        .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
    };

    VkResult res = ra_vkCreateImage(dev, &img_ci, NULL, &ra_vk_image);
    if (res != VK_SUCCESS) {
        return false;
    }

    VkMemoryRequirements mem_reqs;
    ra_vkGetImageMemoryRequirements(dev, ra_vk_image, &mem_reqs);

    /* Import the external memory handle */
#ifdef _WIN32
    VkImportMemoryWin32HandleInfoKHR import_info = {
        .sType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR,
        .handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT,
        .handle = (HANDLE)ext_handle,
    };
#else
    /* ext_handle only says which image this is; the fd is taken now, and a
     * successful import makes it the driver's to close. */
    const int import_fd = nv2a_take_vk_display_fd();
    if (import_fd < 0) {
        ra_vkDestroyImage(dev, ra_vk_image, NULL);
        ra_vk_image = VK_NULL_HANDLE;
        return false;
    }
    VkImportMemoryFdInfoKHR import_info = {
        .sType = VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR,
        .handleType = VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT,
        .fd = import_fd,
    };
#endif

    VkMemoryAllocateInfo alloc_info = {
        .sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
        .pNext = &import_info,
        .allocationSize = mem_reqs.size,
        .memoryTypeIndex = ra_vk_find_memory_type(mem_reqs.memoryTypeBits,
                                                   VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT),
    };

    res = ra_vkAllocateMemory(dev, &alloc_info, NULL, &ra_vk_memory);
    if (res != VK_SUCCESS) {
#ifndef _WIN32
        close(import_fd); /* still ours: the import failed */
#endif
        ra_vkDestroyImage(dev, ra_vk_image, NULL);
        ra_vk_image = VK_NULL_HANDLE;
        return false;
    }

    res = ra_vkBindImageMemory(dev, ra_vk_image, ra_vk_memory, 0);
    if (res != VK_SUCCESS) {
        ra_vk_cleanup_display();
        return false;
    }

    /* Create VkImageView */
    ra_vk_view_ci = (VkImageViewCreateInfo){
        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        .image = ra_vk_image,
        .viewType = VK_IMAGE_VIEW_TYPE_2D,
        .format = VK_FORMAT_R8G8B8A8_UNORM,
        .components = { VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY,
                        VK_COMPONENT_SWIZZLE_IDENTITY, VK_COMPONENT_SWIZZLE_IDENTITY },
        .subresourceRange = {
            .aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
            .levelCount = 1,
            .layerCount = 1,
        },
    };

    res = ra_vkCreateImageView(dev, &ra_vk_view_ci, NULL, &ra_vk_image_view);
    if (res != VK_SUCCESS) {
        ra_vk_cleanup_display();
        return false;
    }

    ra_vk_width = width;
    ra_vk_height = height;
    ra_last_handle = ext_handle;

    return true;
}

/* ========================================================================= */
/* Vulkan device negotiation                                                 */
/* ========================================================================= */

XemuLibretroVk xemu_libretro_vk;
bool xemu_libretro_vk_context_ready;

static const VkApplicationInfo xemu_vk_app_info = {
    .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
    .pApplicationName = "xemu",
    .pEngineName = "xemu",
    .apiVersion = VK_API_VERSION_1_3,
};

/*
 * The core makes the device RetroArch draws with, and the renderer draws on
 * it too (pgraph/vk/libretro_shared.h): RetroArch's required extensions,
 * layers and features plus the renderer's. A frame is then an image on that
 * one device, handed over as it is - where the renderer had a device of its
 * own, its display image was exported and imported into RetroArch's, with
 * nothing to say when it was complete.
 */
static bool xemu_vk_has_ext(const VkExtensionProperties *props, uint32_t count, const char *name)
{
    for (uint32_t i = 0; i < count; i++) {
        if (!strcmp(props[i].extensionName, name)) {
            return true;
        }
    }
    return false;
}

static bool xemu_vk_create_device(struct retro_vulkan_context *context,
    VkInstance instance, VkPhysicalDevice gpu, VkSurfaceKHR surface,
    PFN_vkGetInstanceProcAddr gipa,
    const char **required_exts, unsigned num_required_exts,
    const char **required_layers, unsigned num_required_layers,
    const VkPhysicalDeviceFeatures *required_features)
{
#define XEMU_VK_LOAD(name) PFN_##name p_##name = (PFN_##name)gipa(instance, #name)
    XEMU_VK_LOAD(vkEnumeratePhysicalDevices);
    XEMU_VK_LOAD(vkGetPhysicalDeviceFeatures);
    XEMU_VK_LOAD(vkGetPhysicalDeviceQueueFamilyProperties);
    XEMU_VK_LOAD(vkGetPhysicalDeviceSurfaceSupportKHR);
    XEMU_VK_LOAD(vkEnumerateDeviceExtensionProperties);
    XEMU_VK_LOAD(vkCreateDevice);
    XEMU_VK_LOAD(vkGetDeviceProcAddr);
    XEMU_VK_LOAD(vkGetPhysicalDeviceProperties);
    XEMU_VK_LOAD(vkGetPhysicalDeviceFeatures2);
#undef XEMU_VK_LOAD
    memset(&xemu_libretro_vk, 0, sizeof(xemu_libretro_vk));
    if (!p_vkEnumeratePhysicalDevices || !p_vkGetPhysicalDeviceFeatures ||
        !p_vkGetPhysicalDeviceQueueFamilyProperties ||
        !p_vkEnumerateDeviceExtensionProperties || !p_vkCreateDevice || !p_vkGetDeviceProcAddr) {
        return false;
    }

    if (gpu == VK_NULL_HANDLE) {
        uint32_t n = 1;
        if (p_vkEnumeratePhysicalDevices(instance, &n, &gpu) < 0 || n == 0) {
            return false;
        }
    }

    /* One queue for graphics, compute and, if there is a surface, present */
    uint32_t qcount = 0;
    p_vkGetPhysicalDeviceQueueFamilyProperties(gpu, &qcount, NULL);
    VkQueueFamilyProperties *qprops = g_new0(VkQueueFamilyProperties, qcount);
    p_vkGetPhysicalDeviceQueueFamilyProperties(gpu, &qcount, qprops);
    uint32_t family = UINT32_MAX;
    uint32_t family_queues = 1;
    for (uint32_t i = 0; i < qcount && family == UINT32_MAX; i++) {
        const VkQueueFlags want = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT;
        if ((qprops[i].queueFlags & want) != want) {
            continue;
        }
        VkBool32 present = VK_TRUE;
        if (surface != VK_NULL_HANDLE && p_vkGetPhysicalDeviceSurfaceSupportKHR) {
            p_vkGetPhysicalDeviceSurfaceSupportKHR(gpu, i, surface, &present);
        }
        if (present) {
            family = i;
            family_queues = qprops[i].queueCount;
        }
    }
    g_free(qprops);
    if (family == UINT32_MAX) {
        LRLOG_ERROR("[xemu] Vulkan: no queue family for graphics, compute and present\n");
        return false;
    }

    uint32_t ecount = 0;
    p_vkEnumerateDeviceExtensionProperties(gpu, NULL, &ecount, NULL);
    VkExtensionProperties *eprops = g_new0(VkExtensionProperties, ecount);
    p_vkEnumerateDeviceExtensionProperties(gpu, NULL, &ecount, eprops);

    /* The renderer's optional extensions (create_logical_device in
     * pgraph/vk/instance.c) */
    enum {
        EXT_CUSTOM_BORDER, EXT_MEMORY_BUDGET, EXT_EDS, EXT_EDS3,
        EXT_VERTEX_INPUT, EXT_PIPELINE_LIBRARY, EXT_GPL,
    };
    static const char *const own_exts[] = {
        [EXT_CUSTOM_BORDER] = VK_EXT_CUSTOM_BORDER_COLOR_EXTENSION_NAME,
        [EXT_MEMORY_BUDGET] = VK_EXT_MEMORY_BUDGET_EXTENSION_NAME,
        [EXT_EDS] = VK_EXT_EXTENDED_DYNAMIC_STATE_EXTENSION_NAME,
        [EXT_EDS3] = VK_EXT_EXTENDED_DYNAMIC_STATE_3_EXTENSION_NAME,
        [EXT_VERTEX_INPUT] = VK_EXT_VERTEX_INPUT_DYNAMIC_STATE_EXTENSION_NAME,
        [EXT_PIPELINE_LIBRARY] = VK_KHR_PIPELINE_LIBRARY_EXTENSION_NAME,
        [EXT_GPL] = VK_EXT_GRAPHICS_PIPELINE_LIBRARY_EXTENSION_NAME,
    };
    bool own_ext_enabled[G_N_ELEMENTS(own_exts)] = { false };
    const char **exts = g_new0(const char *, num_required_exts + G_N_ELEMENTS(own_exts));
    uint32_t nexts = 0;
    for (unsigned i = 0; i < num_required_exts; i++) {
        exts[nexts++] = required_exts[i];
    }
    for (unsigned i = 0; i < G_N_ELEMENTS(own_exts); i++) {
        bool listed = false;
        for (uint32_t j = 0; j < nexts; j++) {
            listed |= !strcmp(exts[j], own_exts[i]);
        }
        if (listed) {
            own_ext_enabled[i] = true;
            continue;
        }
        if (xemu_vk_has_ext(eprops, ecount, own_exts[i])) {
            exts[nexts++] = own_exts[i];
            own_ext_enabled[i] = true;
        }
    }
    g_free(eprops);

    /* A queue of its own for the renderer where the family has a second
     * one: it submits many times a frame, and the frontend holds its queue's
     * lock while it presents */
    const bool own_queue = family_queues >= 2;
    const float priorities[2] = { 1.0f, 1.0f };
    VkDeviceQueueCreateInfo queue_ci = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
        .queueFamilyIndex = family,
        .queueCount = own_queue ? 2 : 1,
        .pQueuePriorities = priorities,
    };

    /* The frontend's features and the renderer's (create_logical_device) */
    VkPhysicalDeviceFeatures available = {0};
    p_vkGetPhysicalDeviceFeatures(gpu, &available);
    VkPhysicalDeviceFeatures features = {0};
    if (required_features) {
        features = *required_features;
    }
    bool renderer_features = true;
#define XEMU_VK_FEATURE(name, required) \
    do { \
        if (available.name) { \
            features.name = VK_TRUE; \
        } else if (required) { \
            LRLOG_ERROR("[xemu] Vulkan: the GPU has no " #name "\n"); \
            renderer_features = false; \
        } \
    } while (0)
    XEMU_VK_FEATURE(depthClamp, true);
    XEMU_VK_FEATURE(fillModeNonSolid, true);
    XEMU_VK_FEATURE(geometryShader, true);
    XEMU_VK_FEATURE(occlusionQueryPrecise, true);
    XEMU_VK_FEATURE(samplerAnisotropy, false);
    XEMU_VK_FEATURE(shaderClipDistance, true);
    XEMU_VK_FEATURE(shaderTessellationAndGeometryPointSize, true);
    XEMU_VK_FEATURE(wideLines, false);
#undef XEMU_VK_FEATURE
    if (!renderer_features) {
        g_free(exts);
        return false;
    }

    /* The dynamic states, pipeline libraries and 1.2/1.3 features the
     * renderer's fast paths use, decided as create_logical_device does
     * (pgraph/vk/instance.c): an extension alone does not promise its
     * features. Without them every new state compiled a whole pipeline on
     * the draw path, the shader stutter NNshi measured against standalone. */
    VkPhysicalDeviceProperties props;
    p_vkGetPhysicalDeviceProperties(gpu, &props);
    const uint32_t api = MIN(xemu_vk_app_info.apiVersion, props.apiVersion);
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT eds_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT,
    };
    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT eds3_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT,
        .pNext = &eds_q,
    };
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT vids_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT,
        .pNext = &eds3_q,
    };
    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT gpl_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT,
        .pNext = &vids_q,
    };
    VkPhysicalDeviceHostQueryResetFeatures hqr_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES,
        .pNext = &gpl_q,
    };
    VkPhysicalDeviceVulkan13Features v13_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES,
        .pNext = &hqr_q,
    };
    const bool query_v13 = api >= VK_API_VERSION_1_3;
    VkPhysicalDeviceFeatures2 features2_q = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2,
        .pNext = query_v13 ? (void *)&v13_q : (void *)&hqr_q,
    };
    if (p_vkGetPhysicalDeviceFeatures2) {
        p_vkGetPhysicalDeviceFeatures2(gpu, &features2_q);
    }
    const bool shader_demote = query_v13 && v13_q.shaderDemoteToHelperInvocation;
    const bool host_query_reset = api >= VK_API_VERSION_1_2 && hqr_q.hostQueryReset;
    const bool dyn_cull_front = opt_vk_dynamic && own_ext_enabled[EXT_EDS] &&
                                eds_q.extendedDynamicState;
    const bool dyn_blend = opt_vk_dynamic && own_ext_enabled[EXT_EDS3] &&
                           eds3_q.extendedDynamicState3ColorBlendEnable &&
                           eds3_q.extendedDynamicState3ColorBlendEquation &&
                           eds3_q.extendedDynamicState3ColorWriteMask;
    const bool dyn_vertex_input = opt_vk_dynamic && own_ext_enabled[EXT_VERTEX_INPUT] &&
                                  vids_q.vertexInputDynamicState;
    const bool pipeline_library = opt_vk_gpl && own_ext_enabled[EXT_PIPELINE_LIBRARY] &&
                                  own_ext_enabled[EXT_GPL] &&
                                  gpl_q.graphicsPipelineLibrary;

    void *next = NULL;
    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT eds_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT,
        .extendedDynamicState = VK_TRUE,
    };
    if (dyn_cull_front) {
        eds_features.pNext = next;
        next = &eds_features;
    }
    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT eds3_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT,
        .extendedDynamicState3ColorBlendEnable = VK_TRUE,
        .extendedDynamicState3ColorBlendEquation = VK_TRUE,
        .extendedDynamicState3ColorWriteMask = VK_TRUE,
    };
    if (dyn_blend) {
        eds3_features.pNext = next;
        next = &eds3_features;
    }
    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT gpl_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT,
        .graphicsPipelineLibrary = VK_TRUE,
    };
    if (pipeline_library) {
        gpl_features.pNext = next;
        next = &gpl_features;
    }
    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT vids_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT,
        .vertexInputDynamicState = VK_TRUE,
    };
    if (dyn_vertex_input) {
        vids_features.pNext = next;
        next = &vids_features;
    }
    VkPhysicalDeviceVulkan13Features v13_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES,
        .shaderDemoteToHelperInvocation = VK_TRUE,
    };
    if (shader_demote) {
        v13_features.pNext = next;
        next = &v13_features;
    }
    VkPhysicalDeviceHostQueryResetFeatures hqr_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES,
        .hostQueryReset = VK_TRUE,
    };
    if (host_query_reset) {
        hqr_features.pNext = next;
        next = &hqr_features;
    }
    VkPhysicalDeviceCustomBorderColorFeaturesEXT custom_border_features = {
        .sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT,
        .customBorderColors = VK_TRUE,
    };
    if (own_ext_enabled[EXT_CUSTOM_BORDER]) {
        custom_border_features.pNext = next;
        next = &custom_border_features;
    }
    VkDeviceCreateInfo device_ci = {
        .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
        .pNext = next,
        .queueCreateInfoCount = 1,
        .pQueueCreateInfos = &queue_ci,
        .enabledLayerCount = num_required_layers,
        .ppEnabledLayerNames = required_layers,
        .enabledExtensionCount = nexts,
        .ppEnabledExtensionNames = exts,
        .pEnabledFeatures = &features,
    };
    VkDevice device = VK_NULL_HANDLE;
    VkResult res = p_vkCreateDevice(gpu, &device_ci, NULL, &device);
    g_free(exts);
    if (res != VK_SUCCESS) {
        LRLOG_ERROR("[xemu] Vulkan: vkCreateDevice failed (%d)\n", res);
        return false;
    }

    PFN_vkGetDeviceQueue p_vkGetDeviceQueue =
        (PFN_vkGetDeviceQueue)p_vkGetDeviceProcAddr(device, "vkGetDeviceQueue");
    VkQueue queue = VK_NULL_HANDLE;
    p_vkGetDeviceQueue(device, family, 0, &queue);

    context->gpu = gpu;
    context->device = device;
    context->queue = queue;
    context->queue_family_index = family;
    context->presentation_queue = queue;
    context->presentation_queue_family_index = family;

    /* The renderer takes this device over (pgraph/vk/instance.c) */
    xemu_libretro_vk.get_instance_proc_addr = gipa;
    xemu_libretro_vk.instance = instance;
    xemu_libretro_vk.gpu = gpu;
    xemu_libretro_vk.device = device;
    xemu_libretro_vk.api_version = xemu_vk_app_info.apiVersion;
    xemu_libretro_vk.queue_family = family;
    xemu_libretro_vk.queue = queue;
    xemu_libretro_vk.queue_shared = !own_queue;
    if (own_queue) {
        p_vkGetDeviceQueue(device, family, 1, &xemu_libretro_vk.queue);
    }
    xemu_libretro_vk.features = features;
    xemu_libretro_vk.custom_border_color = own_ext_enabled[EXT_CUSTOM_BORDER];
    xemu_libretro_vk.memory_budget = own_ext_enabled[EXT_MEMORY_BUDGET];
    xemu_libretro_vk.dyn_cull_front = dyn_cull_front;
    xemu_libretro_vk.dyn_blend = dyn_blend;
    xemu_libretro_vk.dyn_vertex_input = dyn_vertex_input;
    xemu_libretro_vk.pipeline_library = pipeline_library;
    xemu_libretro_vk.host_query_reset = host_query_reset;
    xemu_libretro_vk.shader_demote = shader_demote;
    xemu_libretro_vk.active = true;

    LRLOG_INFO("[xemu] Vulkan: device shared with the frontend, queue family %u (%s), %u extensions\n",
               family, own_queue ? "a queue of its own" : "the frontend's queue", nexts);
    LRLOG_INFO("[xemu] Vulkan: dynamic state cull/front %d, blend %d, vertex input %d | pipeline library %d | host query reset %d | shader demote %d\n",
               dyn_cull_front, dyn_blend, dyn_vertex_input, pipeline_library,
               host_query_reset, shader_demote);
    return true;
}

/* Vulkan 1.3 where there is one: the renderer wants 1.1 at least, and the
 * device's own version caps it */
static const VkApplicationInfo *xemu_vk_get_application_info(void)
{
    return &xemu_vk_app_info;
}

void xemu_libretro_vk_lock_queue(void)
{
    if (xemu_libretro_vk.queue_shared && vulkan_if && vulkan_if->lock_queue) {
        vulkan_if->lock_queue(vulkan_if->handle);
    }
}

void xemu_libretro_vk_unlock_queue(void)
{
    if (xemu_libretro_vk.queue_shared && vulkan_if && vulkan_if->unlock_queue) {
        vulkan_if->unlock_queue(vulkan_if->handle);
    }
}

static const struct retro_hw_render_context_negotiation_interface_vulkan xemu_vk_negotiation = {
    RETRO_HW_RENDER_CONTEXT_NEGOTIATION_INTERFACE_VULKAN,
    RETRO_HW_RENDER_CONTEXT_NEGOTIATION_INTERFACE_VULKAN_VERSION,
    xemu_vk_get_application_info,
    xemu_vk_create_device,
    NULL, /* destroy_device: nothing of our own on the device */
};

/* ========================================================================= */
/* Context callbacks                                                         */
/* ========================================================================= */

static void context_reset(void)
{
    if (!use_vulkan) {
        LRLOG_INFO("[xemu] OpenGL context ready, creating blit resources\n");
        create_blit_resources();

        extern void libretro_gl_prepare(void);
        extern void libretro_gl_wake_pfifo(void);

        libretro_gl_prepare();
        nv2a_context_init();
        libretro_gl_wake_pfifo();
    } else {
        if (environ_cb) {
            struct retro_hw_render_interface *iface = NULL;
            if (environ_cb(RETRO_ENVIRONMENT_GET_HW_RENDER_INTERFACE, &iface) && iface &&
                iface->interface_type == RETRO_HW_RENDER_INTERFACE_VULKAN) {
                vulkan_if = (struct retro_hw_render_interface_vulkan *)iface;
                LRLOG_INFO("[xemu] Got Vulkan HW render interface (version %u, device=%p)\n",
                           vulkan_if->interface_version, (void*)vulkan_if->device);
                ra_vk_resolve_functions();
            } else {
                LRLOG_ERROR("[xemu] Failed to get Vulkan HW render interface\n");
                vulkan_if = NULL;
            }
        }

        extern void libretro_gl_set_standalone_mode(void);
        extern void libretro_gl_wake_pfifo(void);

        /* The renderers' contexts are made once: they are the machine's,
         * and it outlives the content and RetroArch's context */
        static bool renderer_contexts_made = false;
        libretro_gl_set_standalone_mode();
        if (!renderer_contexts_made) {
            nv2a_context_init();
            renderer_contexts_made = true;
        }
        /* the renderer may start now (pgraph_vk_init waits for this) */
        qatomic_set(&xemu_libretro_vk_context_ready, true);
        libretro_gl_wake_pfifo();

        /* After a context_destroy took the renderer off the old device:
         * back onto this one (no renderer yet at the first reset) */
        if (xemu_libretro_vk.active && vk_renderer_parked) {
            if (!nv2a_libretro_switch_renderer(CONFIG_DISPLAY_RENDERER_VULKAN)) {
                LRLOG_ERROR("[xemu] Vulkan: the renderer did not start on the new device\n");
            }
            vk_renderer_parked = false;
        }
    }

    context_ready = true;
}

/* The Vulkan renderer taken off the device shared with the frontend, before
 * the frontend destroys it: its objects are destroyed while the device still
 * exists, and nothing of it runs on a device that is gone */
static void vk_park_renderer(void)
{
    if (!xemu_libretro_vk.active || vk_renderer_parked) {
        return;
    }
    if (nv2a_libretro_switch_renderer(CONFIG_DISPLAY_RENDERER_NULL)) {
        vk_renderer_parked = true;
    } else if (emu_initialized) {
        LRLOG_ERROR("[xemu] Vulkan: the renderer did not leave the device\n");
    }
}

static void context_destroy(void)
{
    context_ready = false;

    if (use_vulkan) {
        vk_park_renderer();
        xemu_libretro_vk.active = false;
        qatomic_set(&xemu_libretro_vk_context_ready, false);
    }

    if (!use_vulkan) {
        destroy_blit_resources();
    }

    if (use_vulkan && vulkan_if) {
        ra_vk_cleanup_display();
        for (int i = 0; i < 2; i++) {
            if (ra_vk_fences[i] != VK_NULL_HANDLE && ra_vkDestroyFence) {
                ra_vkWaitForFences(vulkan_if->device, 1, &ra_vk_fences[i], VK_TRUE, UINT64_MAX);
                ra_vkDestroyFence(vulkan_if->device, ra_vk_fences[i], NULL);
                ra_vk_fences[i] = VK_NULL_HANDLE;
            }
            ra_vk_cmds[i] = VK_NULL_HANDLE;
        }
        ra_vk_frame_idx = 0;
        if (ra_vk_cmd_pool != VK_NULL_HANDLE && ra_vkDestroyCommandPool) {
            ra_vkDestroyCommandPool(vulkan_if->device, ra_vk_cmd_pool, NULL);
            ra_vk_cmd_pool = VK_NULL_HANDLE;
        }
        ra_vk_funcs_resolved = false;
    }
    vulkan_if = NULL;
}

/* ========================================================================= */
/* Core option helpers                                                       */
/* ========================================================================= */

static void get_option_string(const char *key, char *buf, size_t buf_sz)
{
    struct retro_variable var = { key, NULL };
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        snprintf(buf, buf_sz, "%s", var.value);
    }
}

/* The Aspect Ratio option: 4:3 and 16:9 say it outright, auto works it out
 * (wants_widescreen) */
static int opt_aspect = 0; /* 0 auto, 1 4:3, 2 16:9 */

/* The running title's ID and the dashboard's video settings, as the guest
 * has them now: read on the emulation thread, which holds the BQL the
 * guest's memory and the EEPROM device need (poll_guest_title) */
static uint32_t guest_title_id;
static uint32_t guest_video_flags;

/* The EEPROM's video settings (user section, 0x94), and their Widescreen
 * bit */
#define EEPROM_VIDEO_FLAGS 0x94
#define EEPROM_VIDEO_WIDESCREEN 0x00010000
#define EEPROM_VIDEO_LETTERBOX 0x00100000
/* The user section the video flags are in, and its checksum */
#define EEPROM_USER_CHECKSUM 0x60
#define EEPROM_USER_SECTION 0x64
#define EEPROM_USER_SECTION_LEN 0x5C

/* System Aspect Ratio: what the dashboard's video settings say to the game,
 * set in the emulated EEPROM at each start - 0 as the EEPROM has it, 1 4:3,
 * 2 16:9, 3 letterbox - so that it no longer takes the dashboard to change
 * (NNshi). In memory only: the EEPROM file keeps the dashboard's. */
static int opt_video_aspect = 2;

extern bool smbus_storage_peek(uint32_t offset, void *buf, uint32_t len);
extern bool smbus_storage_poke(uint32_t offset, const void *buf, uint32_t len);

/* The EEPROM's checksum over a section (eeprom_generation.c) */
static uint32_t eeprom_checksum(const uint8_t *data, size_t len)
{
    uint32_t high = 0, low = 0;
    for (size_t i = 0; i < len / 4; i++) {
        uint32_t val = ldl_le_p(data + i * 4);
        uint64_t sum = ((uint64_t)high << 32) | low;
        high = (sum + val) >> 32;
        low += val;
    }
    return ~(high + low);
}

static void apply_video_aspect(void)
{
    if (opt_video_aspect == 0) {
        return;
    }
    uint8_t user[EEPROM_USER_SECTION_LEN];
    if (!smbus_storage_peek(EEPROM_USER_SECTION, user, sizeof(user))) {
        return;
    }
    uint32_t *flags = (uint32_t *)(user + EEPROM_VIDEO_FLAGS - EEPROM_USER_SECTION);
    uint32_t value = le32_to_cpu(*flags) & ~(EEPROM_VIDEO_WIDESCREEN | EEPROM_VIDEO_LETTERBOX);
    if (opt_video_aspect == 2) {
        value |= EEPROM_VIDEO_WIDESCREEN;
    } else if (opt_video_aspect == 3) {
        value |= EEPROM_VIDEO_LETTERBOX;
    }
    *flags = cpu_to_le32(value);
    uint32_t sum = cpu_to_le32(eeprom_checksum(user, sizeof(user)));
    smbus_storage_poke(EEPROM_USER_SECTION, user, sizeof(user));
    smbus_storage_poke(EEPROM_USER_CHECKSUM, &sum, sizeof(sum));
    LRLOG_INFO("[xemu] System Aspect Ratio: the EEPROM's video settings set to %08X\n", value);
}

static void poll_guest_title(void)
{
    extern bool smbus_storage_peek(uint32_t offset, void *buf, uint32_t len);
    struct xbe *xbe = xemu_get_xbe_info();
    uint32_t flags = 0;

    qatomic_set(&guest_title_id,
                xbe && xbe->cert ? ldl_le_p(&xbe->cert->m_titleid) : 0);
    if (smbus_storage_peek(EEPROM_VIDEO_FLAGS, &flags, sizeof(flags))) {
        qatomic_set(&guest_video_flags, le32_to_cpu(flags));
    }
}

static int compare_title_id(const void *a, const void *b)
{
    const uint32_t x = *(const uint32_t *)a, y = *(const uint32_t *)b;
    return x < y ? -1 : x > y;
}

static bool title_renders_widescreen(uint32_t title_id)
{
    return bsearch(&title_id, libretro_widescreen_titles,
                   ARRAY_SIZE(libretro_widescreen_titles),
                   sizeof(libretro_widescreen_titles[0]),
                   compare_title_id) != NULL;
}

/* Auto: 16:9 with Widescreen on in the dashboard's video settings and a
 * title that renders 16:9 then - one on the list, or one that sets the AV
 * pack's aspect line (acpi_xbox.c), which few do - and 4:3 for the rest
 * and on a Chihiro (NNshi) */
static bool wants_widescreen(void)
{
    if (opt_aspect != 0) {
        return opt_aspect == 2;
    }
    if (emu_started_chihiro ||
        !(qatomic_read(&guest_video_flags) & EEPROM_VIDEO_WIDESCREEN)) {
        return false;
    }
    return title_renders_widescreen(qatomic_read(&guest_title_id)) ||
           xemu_get_widescreen();
}

/* RetroArch is told whenever the aspect changes, as standalone's display
 * follows the title */
static void update_aspect(void)
{
    static int last = -1;
    const int widescreen = wants_widescreen() ? 1 : 0;

    /* What Auto goes by, whenever the title or the settings change */
    static uint32_t last_title = UINT32_MAX, last_flags = UINT32_MAX;
    const uint32_t title = qatomic_read(&guest_title_id);
    const uint32_t flags = qatomic_read(&guest_video_flags);
    if (title != last_title || flags != last_flags) {
        last_title = title;
        last_flags = flags;
        LRLOG_INFO("[xemu] Title ID %08X (%s), dashboard video settings "
                   "%08X (Widescreen %s)\n", title,
                   title_renders_widescreen(title) ? "on the 16:9 list"
                                                   : "not on the 16:9 list",
                   flags, flags & EEPROM_VIDEO_WIDESCREEN ? "on" : "off");
    }

    /* What the title writes to the aspect line, whenever it changes: 5 is
     * widescreen, and a log then says why a title stayed at 4:3 */
    static int last_gpio = -1;
    const int gpio = qatomic_read(&xemu_aspect_gpio_value);
    if (gpio != last_gpio) {
        last_gpio = gpio;
        LRLOG_INFO("[xemu] Aspect line (PM GPIO 0x16) written: %d\n", gpio);
    }

    if (widescreen == last) {
        return;
    }
    last = widescreen;

    struct retro_game_geometry geometry = {
        .base_width = 640,
        .base_height = 480,
        .max_width = declared_max_width,
        .max_height = declared_max_height,
        .aspect_ratio = widescreen ? 16.0f / 9.0f : 4.0f / 3.0f,
    };
    environ_cb(RETRO_ENVIRONMENT_SET_GEOMETRY, &geometry);
    LRLOG_INFO("[xemu] Aspect ratio %s\n", widescreen ? "16:9" : "4:3");
}

static void update_variables(void)
{
    struct retro_variable var;

    get_option_string("xemu_bootrom_path", opt_bootrom_path, sizeof(opt_bootrom_path));
    get_option_string("xemu_bios_path", opt_bios_path, sizeof(opt_bios_path));
    get_option_string("xemu_hdd_path", opt_hdd_path, sizeof(opt_hdd_path));
    get_option_string("xemu_eeprom_path", opt_eeprom_path, sizeof(opt_eeprom_path));

    var.key = "xemu_renderer";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_renderer_vulkan = strcmp(var.value, "opengl") != 0;
    }

    var.key = "xemu_aspect_ratio";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_aspect = !strcmp(var.value, "4:3") ? 1 : !strcmp(var.value, "16:9") ? 2 : 0;
    }

    var.key = "xemu_hdd_trim";
    var.value = NULL;
    opt_hdd_trim = environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value &&
                   !strcmp(var.value, "enabled");

    var.key = "xemu_video_aspect";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_video_aspect = !strcmp(var.value, "4:3") ? 1 : !strcmp(var.value, "16:9") ? 2 :
                           !strcmp(var.value, "letterbox") ? 3 : 0;
    }

    var.key = "xemu_memory";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_memory_mb = atoi(var.value);
    }

    var.key = "xemu_skip_boot_anim";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_skip_boot_anim = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_network_backend";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        if (!strcmp(var.value, "nat")) opt_network_backend = 1;
        else                           opt_network_backend = 0;
    }

    var.key = "xemu_hard_fpu";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_hard_fpu = !strcmp(var.value, "enabled");
    }

    /* Internal Resolution Scale (Restart): taken when the content starts
     * only. A scale above the one the frontend was told at the start made it
     * rebuild its video context, which the core crashed in, and declaring the
     * highest scale for everyone costs video memory nobody uses (NNshi). */
    var.key = "xemu_surface_scale";
    var.value = NULL;
    if (!emu_initialized && environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_surface_scale = atoi(var.value);
        if (opt_surface_scale < 1) opt_surface_scale = 1;
        if (opt_surface_scale > 10) opt_surface_scale = 10;
    }

    var.key = "xemu_use_dsp";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_use_dsp = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_avpack";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        if (!strcmp(var.value, "hdtv"))           opt_avpack = CONFIG_SYS_AVPACK_HDTV;
        else if (!strcmp(var.value, "composite")) opt_avpack = CONFIG_SYS_AVPACK_COMPOSITE;
        else if (!strcmp(var.value, "svideo"))    opt_avpack = CONFIG_SYS_AVPACK_SVIDEO;
        else if (!strcmp(var.value, "scart"))     opt_avpack = CONFIG_SYS_AVPACK_SCART;
        else if (!strcmp(var.value, "vga"))       opt_avpack = CONFIG_SYS_AVPACK_VGA;
    }

    /* Anisotropic Filtering: read as textures are bound, so on the fly */
    var.key = "xemu_anisotropic_filtering";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        const int aniso = atoi(var.value);
        qatomic_set(&xemu_min_anisotropy, aniso == 2 || aniso == 4 || aniso == 8 || aniso == 16 ? aniso : 1);
    }

    var.key = "xemu_cpu_boost";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_cpu_boost = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_chihiro_freeplay";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_chihiro_freeplay = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_vk_fast_paths";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_vk_gpl = !strcmp(var.value, "all") || !strcmp(var.value, "no_dyn");
        opt_vk_dynamic = !strcmp(var.value, "all") || !strcmp(var.value, "no_gpl");
    }

    var.key = "xemu_chihiro_gun_aim";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        libretro_chihiro_aim_stick = !strcmp(var.value, "stick");
    }

    var.key = "xemu_chihiro_crosshair";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        libretro_chihiro_crosshair = strcmp(var.value, "disabled") != 0;
    }

    var.key = "xemu_chihiro_ffb";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_chihiro_ffb = atoi(var.value);
    }
    /* read by retro_run's rumble (libretro-chihiro.c), so it applies at once */
    g_config.chihiro.settings.force_feedback = opt_chihiro_ffb > 0;
    g_config.chihiro.settings.ffb_strength = opt_chihiro_ffb;

    var.key = "xemu_smooth_first_play";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_smooth_first_play = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_dsp_jit";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_dsp_jit = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_hrtf";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_hrtf = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_vp_workers";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_vp_workers = atoi(var.value);
    }

    /* Controls: per player, read by the input and rumble code
     * (libretro-stubs.c) as they run */
    {
        extern int libretro_deadzone_percent[4];
        extern bool libretro_rumble_enabled[4];
        for (unsigned p = 0; p < 2; p++) {
            char key[32];
            snprintf(key, sizeof(key), "xemu_rumble_p%u", p + 1);
            var.key = key;
            var.value = NULL;
            if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
                libretro_rumble_enabled[p] = strcmp(var.value, "disabled") != 0;
            }
            snprintf(key, sizeof(key), "xemu_deadzone_p%u", p + 1);
            var.key = key;
            var.value = NULL;
            if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
                libretro_deadzone_percent[p] = MIN(MAX(atoi(var.value), 0), 30);
            }
        }
    }

    var.key = "xemu_audio_thread";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_audio_thread = !strcmp(var.value, "enabled");
    }

    var.key = "xemu_audio_volume";
    var.value = NULL;
    if (environ_cb && environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
        opt_audio_volume = atoi(var.value);
        if (opt_audio_volume < 0) opt_audio_volume = 0;
        if (opt_audio_volume > 100) opt_audio_volume = 100;
    }

    LRLOG_INFO("[xemu] Options: memory=%dMB, scale=%d, avpack=%d, cache=%d, volume=%d%%, network=%s\n",
               opt_memory_mb, opt_surface_scale,
               opt_avpack, opt_cache_shaders, opt_audio_volume,
               opt_network_backend == 1 ? "nat" : "disabled");

    /* Apply runtime-safe options */
    if (emu_initialized) {
        g_config.audio.volume_limit = opt_audio_volume / 100.0f;
        g_config.audio.use_dsp = opt_use_dsp;
        g_config.audio.use_dsp_jit = opt_dsp_jit;
        g_config.audio.hrtf = opt_hrtf;
    }
}

/* ========================================================================= */
/* QEMU init helpers                                                         */
/* ========================================================================= */

static void populate_config(const char *dvd_path)
{
    LRLOG_INFO("[xemu] Populating g_config from core options\n");

    /* Set file paths in g_config */
    if (opt_bootrom_path[0]) {
        xemu_settings_set_string(&g_config.sys.files.bootrom_path, opt_bootrom_path);
    }
    if (opt_bios_path[0]) {
        xemu_settings_set_string(&g_config.sys.files.flashrom_path, opt_bios_path);
    }
    if (opt_hdd_path[0]) {
        xemu_settings_set_string(&g_config.sys.files.hdd_path, opt_hdd_path);
    }
    if (opt_eeprom_path[0]) {
        xemu_settings_set_string(&g_config.sys.files.eeprom_path, opt_eeprom_path);
    }

    /* Chihiro files live in system/xemu/Chihiro/. The media board flash and
     * the EEPROMs are found next to the BIOS by their MAME names; only the
     * optional network firmware needs its own path. */
    if (system_dir[0]) {
        char path[4096];
        snprintf(path, sizeof(path), "%s/xemu/Chihiro/chihiro_xbox_bios.bin",
                 system_dir);
        xemu_settings_set_string(&g_config.chihiro.roms.bios_path, path);
        snprintf(path, sizeof(path), "%s/xemu/Chihiro/ver1305.bin", system_dir);
        if (g_file_test(path, G_FILE_TEST_IS_REGULAR)) {
            xemu_settings_set_string(&g_config.chihiro.roms.net_firmware_path,
                                     path);
        }
    }
    /* The Chihiro settings the machine reads, at config_spec.yml's defaults:
     * g_config starts zeroed in the core (no xemu.toml), which leaves its
     * strings NULL - the snapshot store setup takes strlen of one at a
     * Chihiro boot - and some enums off their default (DIMM size 128 MB
     * rather than auto). */
    {
        const char **paths[] = {
            &g_config.chihiro.roms.mediaboard_path,
            &g_config.chihiro.roms.ic10_path,
            &g_config.chihiro.roms.ic11_path,
            &g_config.chihiro.roms.pc20_path,
            &g_config.chihiro.roms.snapshot_store_path,
            &g_config.chihiro.roms.net_firmware_path,
            &g_config.chihiro.link.host,
            &g_config.chihiro.card_reader.hw210.slot1,
            &g_config.chihiro.card_reader.hw210.slot2,
            &g_config.chihiro.card_reader.hw210.gundam,
            &g_config.chihiro.card_reader.crp1231.mt1,
            &g_config.chihiro.card_reader.crp1231.mt2,
            &g_config.chihiro.card_reader.card1_path,
            &g_config.chihiro.card_reader.card2_path,
        };
        for (size_t i = 0; i < G_N_ELEMENTS(paths); i++) {
            if (!*paths[i]) {
                xemu_settings_set_string(paths[i], "");
            }
        }
        g_config.chihiro.settings.dimm_size = CONFIG_CHIHIRO_SETTINGS_DIMM_SIZE_AUTO;
        g_config.chihiro.settings.freeplay = opt_chihiro_freeplay;
        g_config.chihiro.settings.force_feedback = opt_chihiro_ffb > 0;
        g_config.chihiro.settings.ffb_strength = opt_chihiro_ffb;
        g_config.chihiro.settings.region = CONFIG_CHIHIRO_SETTINGS_REGION_EX;
        g_config.chihiro.card_reader.enable = true;
        g_config.chihiro.link.cabinets = 2;
        g_config.chihiro.link.cabinet = 1;
        g_config.chihiro.link.port = 9100;
    }

    /* also when empty: a load without content after one with it */
    xemu_settings_set_string(&g_config.sys.files.dvd_path, dvd_path ? dvd_path : "");
    /* Xbox or Chihiro and the image, decided for this content (an Xbox disc
     * image boots an Xbox, any other image - a .bin netboot image - a
     * Chihiro; retro_load_game has refused the other machine's content) */
    extern void libretro_chihiro_mode_reset(void);
    libretro_chihiro_mode_reset();

    /* Set renderer */
    if (use_vulkan) {
        g_config.display.renderer = CONFIG_DISPLAY_RENDERER_VULKAN;
    } else {
        g_config.display.renderer = CONFIG_DISPLAY_RENDERER_OPENGL;
    }

    /* Set memory (mem_limit is an int: 0=64MB, 1=128MB) */
    g_config.sys.mem_limit = (opt_memory_mb == 128) ? 1 : 0;

    /* Critical defaults for libretro mode */
    g_config.general.show_welcome = false;
    g_config.audio.volume_limit = opt_audio_volume / 100.0f;
    g_config.perf.cache_shaders = opt_cache_shaders;

    /* Set other options */
    g_config.general.skip_boot_anim = opt_skip_boot_anim;
    g_config.perf.hard_fpu = opt_hard_fpu;
    g_config.perf.native_sse = opt_cpu_boost;
    g_config.perf.shader_seeding = opt_smooth_first_play;
    /* GPU boost is the renderer the core is made for: the stock one the fork
     * keeps for it being off (hw/xbox/nv2a-stock) has none of the core's
     * frontend handover. Real hardware speed paces the machine itself, which
     * in the core is the frontend's job. */
    g_config.perf.optimizations = true;
    g_config.perf.real_hw_speed = false;
    g_config.audio.use_dsp = opt_use_dsp;
    g_config.audio.use_dsp_jit = opt_dsp_jit;
    g_config.audio.hrtf = opt_hrtf;
    g_config.audio.vp.num_workers = opt_vp_workers;
    g_config.display.quality.surface_scale = opt_surface_scale;
    g_config.sys.avpack = opt_avpack;

    /* Set network configuration */
    g_config.net.enable = (opt_network_backend == 1);
    if (opt_network_backend == 1) {
        g_config.net.backend = CONFIG_NET_BACKEND_NAT;
    }

    LRLOG_INFO("[xemu] Config populated: bootrom=%s, bios=%s, hdd=%s, dvd=%s\n",
               g_config.sys.files.bootrom_path ? g_config.sys.files.bootrom_path : "(null)",
               g_config.sys.files.flashrom_path ? g_config.sys.files.flashrom_path : "(null)",
               g_config.sys.files.hdd_path ? g_config.sys.files.hdd_path : "(null)",
               g_config.sys.files.dvd_path ? g_config.sys.files.dvd_path : "(null)");
}

/* Thread function for running QEMU main loop */
extern GMainContext *qemu_main_context;

static void *emu_thread_func(void *opaque)
{
    /* Build QEMU argv */
    const char *argv[] = {
        "xemu",
        "-device", "lpc47m157",
        "-serial", "null",
        NULL,
    };
    int argc = 5;

    /* QEMU's machine is built once in a process and never taken down (see
     * retro_init). The first content builds it; each one after that gets
     * the machine the last one left stopped: its disc is put in the drive
     * and the console is reset and started again, as a power cycle with
     * another disc. This thread takes over as QEMU's main thread by holding
     * the BQL, which the last one released when it ended. */
    static bool machine_built = false;
    static char machine_image[4096]; /* the content the machine holds */
    if (!machine_built) {
        qemu_init(argc, (char **)argv);

        /* Create XID USB gamepad devices for all 4 ports (BQL is held) */
        extern void libretro_input_create_xid_devices(void);
        libretro_input_create_xid_devices();
        apply_video_aspect();
        machine_built = true;
        /* default.xbe patched: the drive gets the overlay before the
         * dashboard reads the disc (the vCPUs need the BQL this holds) */
        if (!xemu_chihiro_mode() && xemu_libretro_has_xbe_patches(opt_dvd_path)) {
            extern void xemu_libretro_change_disc(const char *path, Error **errp);
            Error *err = NULL;
            xemu_libretro_change_disc(opt_dvd_path, &err);
            if (err) {
                LRLOG_ERROR("[xemu] Patched disc not loaded: %s\n", error_get_pretty(err));
                error_free(err);
            }
        }
    } else {
        extern void xemu_libretro_change_disc(const char *path, Error **errp);
        extern void qemu_libretro_clear_shutdown_request(void);
        Error *err = NULL;

        bql_lock();
        /* xemu's main loop runs on the thread's default GLib context
         * (g_main_context_get_thread_default, util/main-loop.c), which
         * qemu_init pushed on the first thread only: without it the loop
         * handed GLib a null context and RetroArch crashed in ntdll on the
         * second content (NNshi's dump). The thread before this one popped
         * it when it ended, which also gave up its ownership. */
        g_main_context_push_thread_default(qemu_main_context);
        /* A Chihiro has no disc drive: its game is in its media board's
         * memory, where another one is put (the same one stays as it is).
         * Asked before anything touches the DVD path, which the machine
         * type and the image are worked out from: the drive's disc change
         * clears it first, and failed on the Chihiro's missing drive, so
         * the switch took the machine for an Xbox and never ran (NNshi). */
        if (xemu_chihiro_mode()) {
            if (strcmp(opt_dvd_path, machine_image)) {
                chihiro_change_game();
                LRLOG_INFO("[xemu] Chihiro: the media board holds %s now\n", opt_dvd_path);
            }
        } else {
            xemu_libretro_change_disc(opt_dvd_path, &err);
            if (err) {
                LRLOG_ERROR("[xemu] Disc not loaded: %s\n", error_get_pretty(err));
                error_free(err);
            }
        }
        qemu_libretro_clear_shutdown_request();
        apply_video_aspect();
        qemu_system_reset(SHUTDOWN_CAUSE_HOST_QMP_SYSTEM_RESET);
        if (!runstate_check(RUN_STATE_PRELAUNCH)) {
            runstate_set(RUN_STATE_PRELAUNCH);
        }
        vm_start();
        LRLOG_INFO("[xemu] The machine is reset and started with the new disc\n");
    }
    snprintf(machine_image, sizeof(machine_image), "%s", opt_dvd_path);

    emu_initialized = true;

    extern bool runstate_is_running(void);

    /* Run main loop */
    while (emu_thread_running) {
        /* Check for reset requests */
        ShutdownCause reset_request = qemu_reset_requested_consume();
        if (reset_request) {
            pause_all_vcpus();
            qemu_system_reset(reset_request);
            resume_all_vcpus();
            /*
             * runstate can change in pause_all_vcpus()
             * as iothread mutex is unlocked
             */
            if (!runstate_check(RUN_STATE_RUNNING) &&
                    !runstate_check(RUN_STATE_INMIGRATE) &&
                    !runstate_check(RUN_STATE_FINISH_MIGRATE)) {
                runstate_set(RUN_STATE_PRELAUNCH);
            }
        }
        
        /* Check for shutdown requests */
        if (qemu_shutdown_requested_get()) {
            emu_thread_running = false;
            break;
        }

        /* No retro_run for a while: the menu is open, or the frontend paused */
        const int64_t last_run = qatomic_read(&last_run_us);
        const bool frontend_idle =
            last_run && g_get_monotonic_time() - last_run > FRONTEND_PAUSE_US;
        if (!qatomic_read(&frontend_paused) && frontend_idle &&
            runstate_is_running()) {
            vm_stop(RUN_STATE_PAUSED);
            qatomic_set(&frontend_paused, true);
        } else if (qatomic_read(&frontend_paused) && !frontend_idle) {
            if (runstate_check(RUN_STATE_PAUSED)) {
                vm_start();
            }
            qatomic_set(&frontend_paused, false);
        }

        main_loop_wait(false);

        /* Check for snapshot requests from RetroArch thread */
        if (snapshot_request != SNAPSHOT_NONE) {
            int req = snapshot_request;
            snapshot_request = SNAPSHOT_NONE;
            bool ok = false;
            Error *snap_err = NULL;

            if (req == SNAPSHOT_SAVE) {
                ok = save_snapshot("libretro_save", true, NULL, false, NULL, &snap_err);
                if (!ok && snap_err) {
                    error_free(snap_err);
                }
            } else if (req == SNAPSHOT_LOAD) {
                bool was_running = runstate_is_running();
                vm_stop(RUN_STATE_RESTORE_VM);
                ok = load_snapshot("libretro_save", NULL, false, NULL, &snap_err);
                if (ok && was_running) {
                    vm_start();
                } else if (!ok) {
                    if (snap_err) {
                        error_free(snap_err);
                    }
                    if (was_running) vm_start();
                }
            }

            snapshot_result = ok;
            snapshot_done = true;
            if (snapshot_sem_initialized) qemu_sem_post(&snapshot_done_sem);
        }
    }

    /* The first step of upstream's qemu_cleanup(): the vCPUs are stopped and
     * every block device drained and flushed. Without it the guest ran on
     * after its content was closed and was cut off mid-write when RetroArch
     * exited, which left the HDD image's cache partitions broken (NNshi:
     * Panzer Dragoon Orta stuck loading, in standalone too with that image) */
    vm_shutdown();

    if (opt_hdd_trim && !xemu_chihiro_mode()) {
        hdd_trim();
    }

    /* The main loop's GLib context goes to the next content's thread, which
     * cannot take it while this one still owns it as its default */
    g_main_context_pop_thread_default(qemu_main_context);

    bql_unlock();
    return NULL;
}

/* Trim HDD on Close (experimental, NNshi, Akrido): when the content closes,
 * the cache partitions X, Y and Z are emptied - games format them again
 * when they need them - and the image is written anew without the clusters
 * nothing uses, so the file shrinks. Skipped while the image holds a
 * savestate (a snapshot keeps its clusters, and copying the disk alone
 * would drop it). The copy needs as much free space as the data for a
 * moment. Runs on the emulator thread with the VM shut down. */

#define HDD_CACHE_START 0x00080000LL           /* X, then Y and Z */
#define HDD_CACHE_LEN   (3 * 0x2EE00000LL)     /* 750 MB each */
#define HDD_COPY_CHUNK  (1024 * 1024)

/* xemu-dashboard's pre-formatted HDD, which the core carries
 * (data/xbox_hdd.qcow2, MIT): written where the HDD is looked for when there
 * is none, so only the boot ROM and the BIOS have to come from the user
 * (NNshi). The image is small and grows as games use the disk. */
static bool write_bundled_hdd(const char *path)
{
    g_autofree char *dir = g_path_get_dirname(path);
    g_autoptr(GError) err = NULL;
    if (g_mkdir_with_parents(dir, 0755) != 0 ||
        !g_file_set_contents(path, (const char *)xbox_hdd_data,
                             xbox_hdd_size, &err)) {
        LRLOG_ERROR("[xemu] Cannot write the bundled HDD to %s: %s\n", path,
                    err ? err->message : g_strerror(errno));
        return false;
    }
    LRLOG_INFO("[xemu] No HDD: wrote the bundled one (xemu-dashboard) to %s\n",
               path);
    return true;
}

/* Patch Manager (NNshi): IPS and Jay's Magic Patcher (.jmp) patches for a
 * game's default.xbe in system/xemu/patches, named after the game as
 * XboxGraphicalPatches names them ("Game (16-9 Widescreen Patch).ips"). The
 * game's name in its XBE certificate, or any of its title ID's names in
 * xemu-project/xdb (libretro-xdb-titles.h), picks the ones that are its;
 * each gets an option in the Patch Manager category, off by default and
 * taken when the game starts. The image stays as it is: the drive gets a
 * qcow2 overlay over it (system/xemu/patched_disc.qcow2) holding the
 * patched clusters of default.xbe, the rest read from the image. A patch
 * that writes past the XBE's end is skipped, as the file cannot grow, and
 * one for another file ("Apply to intro_17.lvl") is not listed. A .jmp
 * applies every line in it (xbe_apply_jmp): its groups that exclude each
 * other (one language or another) are deleted from the file to choose. */

#define XISO_SECTOR 2048
#define XBE_PATCH_CLUSTER 65536
#define PATCH_OPTIONS_MAX 64

typedef bool (*xiso_read_fn)(void *ctx, int64_t off, size_t len, void *buf);

/* the patches of the content loaded, and the ones switched on */
static GPtrArray *patch_files;
static GPtrArray *patch_enabled;

/* A name as the Patch Manager compares them: lower case letters and digits,
 * "&" as "and", without "the", II to IV and "vs" spelled as xdb mostly has
 * them (scripts/gen_xdb_titles.py does the same) */
static char *patch_name_norm(const char *name)
{
    static const char *const words[][2] = {
        {"ii", "2"}, {"iii", "3"}, {"iv", "4"}, {"vs", "versus"},
    };
    GString *out = g_string_new(NULL);
    GString *w = g_string_new(NULL);
    for (const char *p = name;; p++) {
        if (*p == '&') {
            g_string_append(out, "and");
        }
        if (*p && g_ascii_isalnum(*p)) {
            g_string_append_c(w, g_ascii_tolower(*p));
            continue;
        }
        if (w->len && strcmp(w->str, "the")) {
            const char *s = w->str;
            for (size_t i = 0; i < ARRAY_SIZE(words); i++) {
                if (!strcmp(s, words[i][0])) {
                    s = words[i][1];
                }
            }
            g_string_append(out, s);
        }
        g_string_truncate(w, 0);
        if (!*p) {
            break;
        }
    }
    g_string_free(w, true);
    return g_string_free(out, false);
}

/* default.xbe in an XISO's root directory, whose entries form a binary
 * tree of 4-byte offsets: its sector and size */
static bool xiso_find_xbe(xiso_read_fn rd, void *ctx, uint32_t *sector, uint32_t *size)
{
    uint8_t hdr[28];
    if (!rd(ctx, 32 * XISO_SECTOR, sizeof(hdr), hdr) ||
        memcmp(hdr, "MICROSOFT*XBOX*MEDIA", 20)) {
        return false;
    }
    const uint32_t root = ldl_le_p(hdr + 20), root_size = ldl_le_p(hdr + 24);
    if (!root_size || root_size > 16 * 1024 * 1024) {
        return false;
    }
    g_autofree uint8_t *dir = g_malloc(root_size);
    if (!rd(ctx, (int64_t)root * XISO_SECTOR, root_size, dir)) {
        return false;
    }
    uint32_t stack[256];
    int depth = 0;
    stack[depth++] = 0;
    for (int visited = 0; depth > 0 && visited < 65536; visited++) {
        const uint32_t off = stack[--depth];
        if (off + 14 > root_size) {
            continue;
        }
        const uint8_t *e = dir + off;
        const uint16_t left = lduw_le_p(e), right = lduw_le_p(e + 2);
        if (left == 0xFFFF && right == 0xFFFF) {
            continue;
        }
        const uint8_t len = e[13];
        if (off + 14 + len <= root_size && len == 11 &&
            !g_ascii_strncasecmp((const char *)e + 14, "default.xbe", 11)) {
            *sector = ldl_le_p(e + 4);
            *size = ldl_le_p(e + 8);
            return true;
        }
        if (left && depth < 256) {
            stack[depth++] = (uint32_t)left * 4;
        }
        if (right && depth < 256) {
            stack[depth++] = (uint32_t)right * 4;
        }
    }
    return false;
}

struct xiso_file {
    FILE *f;
    int64_t base;
};

static bool xiso_file_read(void *ctx, int64_t off, size_t len, void *buf)
{
    struct xiso_file *x = ctx;
    return fseeko(x->f, (off_t)(x->base + off), SEEK_SET) == 0 &&
           fread(buf, 1, len, x->f) == len;
}

static bool xiso_blk_read(void *ctx, int64_t off, size_t len, void *buf)
{
    return blk_pread(ctx, off, len, buf, 0) >= 0;
}

/* The title ID, name and regions (XBE_REGION_*) in the certificate of an
 * XISO's default.xbe */
#define XBE_REGION_NORTH_AMERICA 0x1
#define XBE_REGION_JAPAN 0x2
#define XBE_REGION_REST_OF_WORLD 0x4
static bool xiso_title(const char *image, uint32_t *title_id, char **title_name,
                       uint32_t *regions)
{
    static const int64_t offsets[] = { 0, 0x18300000, 0xFD90000, 0x2080000 };
    FILE *f = fopen(image, "rb");
    if (!f) {
        return false;
    }
    bool ok = false;
    for (size_t i = 0; i < ARRAY_SIZE(offsets) && !ok; i++) {
        struct xiso_file x = { f, offsets[i] };
        uint32_t sector, size;
        uint8_t hdr[0x120], cert[0xA4];
        if (!xiso_find_xbe(xiso_file_read, &x, &sector, &size) ||
            !xiso_file_read(&x, (int64_t)sector * XISO_SECTOR, sizeof(hdr), hdr) ||
            memcmp(hdr, "XBEH", 4)) {
            continue;
        }
        const uint32_t base = ldl_le_p(hdr + 0x104), cert_va = ldl_le_p(hdr + 0x118);
        if (cert_va < base || cert_va - base + sizeof(cert) > size ||
            !xiso_file_read(&x, (int64_t)sector * XISO_SECTOR + (cert_va - base),
                            sizeof(cert), cert)) {
            continue;
        }
        *title_id = ldl_le_p(cert + 8);
        *regions = ldl_le_p(cert + 0xA0);
        gunichar2 name[41] = { 0 };
        for (int c = 0; c < 40; c++) {
            name[c] = lduw_le_p(cert + 0xC + 2 * c);
        }
        *title_name = g_utf16_to_utf8(name, -1, NULL, NULL, NULL);
        ok = *title_name != NULL;
    }
    fclose(f);
    return ok;
}

/* The game a patch file is for: its name up to " (" or the extension */
/* The game's name in a patch's file name: before " (" as XboxGraphicalPatches
 * names them, before " {" or " [" as Jay's Magic Patches do ("Dynasty
 * Warriors 3 {Widescreen} (All Regions) [Esppiral].JMP") */
static char *patch_game(const char *file)
{
    char *g = g_strdup(file);
    char *cut = NULL;
    static const char *const marks[] = { " (", " {", " [" };
    for (size_t i = 0; i < ARRAY_SIZE(marks); i++) {
        char *m = strstr(g, marks[i]);
        if (m && (!cut || m < cut)) {
            cut = m;
        }
    }
    if (!cut) {
        cut = strrchr(g, '.');
    }
    if (cut) {
        *cut = '\0';
    }
    return g;
}

static bool patch_is_for(const char *file, uint32_t title_id, const char *title_norm)
{
    g_autofree char *game = patch_game(file);
    g_autofree char *norm = patch_name_norm(game);
    if (!norm[0]) {
        return false;
    }
    if (title_norm && !strcmp(norm, title_norm)) {
        return true;
    }
    for (size_t i = 0; i < ARRAY_SIZE(libretro_xdb_titles); i++) {
        if (libretro_xdb_titles[i].title_id == title_id &&
            !strcmp(libretro_xdb_titles[i].name, norm)) {
            return true;
        }
    }
    return false;
}

/* g_ptr_array_sort hands pointers to the elements */
static gint patch_name_cmp(gconstpointer a, gconstpointer b)
{
    return g_strcmp0(*(char *const *)a, *(char *const *)b);
}

static char *patch_option_key(const char *file)
{
    return g_strdup_printf("xemu_patch_%08x", g_str_hash(file));
}

/* The options as at start, with one per patch of this game in the Patch
 * Manager category; RetroArch keeps each one's value by its key, made from
 * the file's name */
static void patch_options_register(void)
{
    static struct retro_core_option_v2_definition *defs;
    static struct retro_core_option_v2_category *cats;
    static struct retro_core_options_v2 opts;
    static bool registered;
    unsigned version = 0;

    if (!environ_cb || !environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version) ||
        version < 2 || (!registered && !patch_files->len)) {
        return;
    }
    size_t n_defs = 0, n_cats = 0;
    while (option_defs_us[n_defs].key) {
        n_defs++;
    }
    while (option_cats_us[n_cats].key) {
        n_cats++;
    }
    if (defs) {
        for (size_t i = n_defs; defs[i].key; i++) {
            g_free((char *)defs[i].key);
            g_free((char *)defs[i].desc);
            g_free((char *)defs[i].info);
        }
    }
    g_free(defs);
    g_free(cats);
    defs = g_new0(struct retro_core_option_v2_definition, n_defs + patch_files->len + 1);
    memcpy(defs, option_defs_us, n_defs * sizeof(*defs));
    for (guint i = 0; i < patch_files->len; i++) {
        const char *file = patch_files->pdata[i];
        struct retro_core_option_v2_definition *d = &defs[n_defs + i];
        g_autofree char *game = patch_game(file);
        const char *label = file + strlen(game);
        d->key = patch_option_key(file);
        /* "16-9 Widescreen Patch" out of "Game (16-9 Widescreen Patch).ips",
         * "Widescreen (All Regions) [Esppiral]" out of "Game {Widescreen}
         * (All Regions) [Esppiral].JMP" */
        if (!strncmp(label, " {", 2)) {
            const char *ext = strrchr(label, '.');
            GString *desc = g_string_new(NULL);
            for (const char *c = label + 2; c < (ext ? ext : label + strlen(label)); c++) {
                if (*c != '{' && *c != '}') {
                    g_string_append_c(desc, *c);
                }
            }
            d->desc = g_string_free(desc, false);
        } else if (!strncmp(label, " (", 2)) {
            d->desc = g_strndup(label + 2, strcspn(label + 2, ")"));
        } else {
            d->desc = g_strdup(game);
        }
        d->info = g_strdup(file);
        d->category_key = "patches";
        d->values[0].value = "disabled";
        d->values[0].label = "Disabled";
        d->values[1].value = "enabled";
        d->values[1].label = "Enabled";
        d->default_value = "disabled";
    }
    cats = g_new0(struct retro_core_option_v2_category, n_cats + 2);
    memcpy(cats, option_cats_us, n_cats * sizeof(*cats));
    if (patch_files->len) {
        cats[n_cats].key = "patches";
        cats[n_cats].desc = "Patch Manager (Restart)";
        cats[n_cats].info = "This game's patches in system/xemu/patches, applied to its default.xbe when it starts.";
    }
    opts.categories = cats;
    opts.definitions = defs;

    struct retro_core_options_v2_intl intl = { &opts, NULL };
#ifndef HAVE_NO_LANGEXTRA
    unsigned language = 0;
    if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
        language < RETRO_LANGUAGE_LAST && language != RETRO_LANGUAGE_ENGLISH) {
        intl.local = options_intl[language];
    }
#endif
    environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL, &intl);
    registered = patch_files->len > 0;
}

/* Whether a .jmp is listed for a release of these regions (XBE_REGION_*): one
 * that only finds and replaces bytes checks the XBE itself, as each pattern
 * has to be in it; one that writes at offsets is for the regions its
 * "region=" line names ("All Regions", "GLOBAL", "NTSC+PAL", "JPN"...), any
 * when it names none it knows */
static bool jmp_listed(const char *path, uint32_t regions)
{
    g_autofree char *text = NULL;
    if (!g_file_get_contents(path, &text, NULL, NULL)) {
        return false;
    }
    g_auto(GStrv) lines = g_strsplit_set(text, "\r\n", -1);
    g_autofree char *region = NULL;
    bool offsets = false;
    for (char **l = lines; *l; l++) {
        char *s = g_strstrip(*l);
        if (!g_ascii_strncasecmp(s, "region=", 7)) {
            g_free(region);
            region = g_ascii_strdown(s + 7, -1);
        } else if (s[0] != '#' && strchr(s, ':')) {
            offsets = true;
        }
    }
    if (!offsets || !region || strstr(region, "all") || strstr(region, "global") ||
        strstr(region, "multi")) {
        return true;
    }
    uint32_t named = 0;
    if (strstr(region, "ntsc") || strstr(region, "usa")) {
        named |= XBE_REGION_NORTH_AMERICA;
    }
    if (strstr(region, "pal") || strstr(region, "eur")) {
        named |= XBE_REGION_REST_OF_WORLD;
    }
    if (strstr(region, "jp") || strstr(region, "japan") || strstr(region, "ntsc-j")) {
        named |= XBE_REGION_JAPAN;
    }
    return !named || (named & regions);
}

/* The content's patches and the ones switched on; at load, before the
 * machine takes its disc */
static void patch_manager_load(const char *image, bool chihiro)
{
    g_clear_pointer(&patch_files, g_ptr_array_unref);
    g_clear_pointer(&patch_enabled, g_ptr_array_unref);
    patch_files = g_ptr_array_new_with_free_func(g_free);
    patch_enabled = g_ptr_array_new_with_free_func(g_free);

    uint32_t title_id = 0, regions = 0;
    g_autofree char *title_name = NULL;
    g_autofree char *dir = system_dir[0] ? g_strdup_printf("%s/xemu/patches", system_dir) : NULL;
    GDir *d = dir ? g_dir_open(dir, 0, NULL) : NULL;
    if (d && !chihiro && image && image[0] && !strstr(image, "://") &&
        xiso_title(image, &title_id, &title_name, &regions)) {
        g_autofree char *title_norm = patch_name_norm(title_name);
        /* XboxGraphicalPatches' IPS patches are for the North American
         * releases: on a PAL or Japanese one, which can have the same title
         * ID, they kept games from booting or did nothing (NNshi). A BPS
         * patch carries the CRC of the XBE it is for and checks it itself;
         * a .jmp says its region (jmp_listed). */
        const bool north_america = regions & XBE_REGION_NORTH_AMERICA;
        LRLOG_INFO("[xemu] Patch Manager: %08X \"%s\", regions %X\n", title_id, title_name, regions);
        const char *n;
        while ((n = g_dir_read_name(d))) {
            g_autofree char *lower = g_ascii_strdown(n, -1);
            g_autofree char *path = g_strdup_printf("%s/%s", dir, n);
            if (((g_str_has_suffix(lower, ".ips") && north_america) ||
                 (g_str_has_suffix(lower, ".jmp") && jmp_listed(path, regions)) ||
                 g_str_has_suffix(lower, ".bps")) &&
                !strstr(lower, "apply to") && patch_is_for(n, title_id, title_norm)) {
                g_ptr_array_add(patch_files, g_strdup(n));
            }
            if (patch_files->len >= PATCH_OPTIONS_MAX) {
                break;
            }
        }
        g_ptr_array_sort(patch_files, patch_name_cmp);
    }
    if (d) {
        g_dir_close(d);
    }
    patch_options_register();
    for (guint i = 0; i < patch_files->len; i++) {
        const char *file = patch_files->pdata[i];
        g_autofree char *key = patch_option_key(file);
        struct retro_variable var = { key, NULL };
        if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value &&
            !strcmp(var.value, "enabled")) {
            g_ptr_array_add(patch_enabled, g_strdup_printf("%s/%s", dir, file));
        }
    }
}

static int xbe_apply_ips(uint8_t *xbe, size_t size, const uint8_t *p, size_t n)
{
    if (n < 8 || memcmp(p, "PATCH", 5)) {
        return -1;
    }
    int records = 0;
    for (size_t i = 5; i + 3 <= n;) {
        const uint32_t off = (p[i] << 16) | (p[i + 1] << 8) | p[i + 2];
        i += 3;
        if (off == 0x454F46) { /* EOF */
            return records;
        }
        if (i + 2 > n) {
            return -1;
        }
        uint32_t len = (p[i] << 8) | p[i + 1];
        i += 2;
        if (len) {
            if (i + len > n || off + len > size) {
                return -1;
            }
            memcpy(xbe + off, p + i, len);
            i += len;
        } else {
            if (i + 3 > n) {
                return -1;
            }
            len = (p[i] << 8) | p[i + 1];
            if (off + len > size) {
                return -1;
            }
            memset(xbe + off, p[i + 2], len);
            i += 3;
        }
        records++;
    }
    return -1;
}

static uint64_t bps_number(const uint8_t *p, size_t n, size_t *i)
{
    uint64_t data = 0, shift = 1;
    while (*i < n) {
        const uint8_t x = p[(*i)++];
        data += (x & 0x7f) * shift;
        if (x & 0x80) {
            break;
        }
        shift <<= 7;
        data += shift;
    }
    return data;
}

/* A BPS patch, for an XBE of its size and CRC alone: -2 when the XBE is
 * another one, -1 when the patch is not valid or would change the size */
static int xbe_apply_bps(uint8_t *xbe, size_t size, const uint8_t *p, size_t n)
{
    if (n < 4 + 12 || memcmp(p, "BPS1", 4)) {
        return -1;
    }
    const size_t end = n - 12;
    size_t i = 4;
    const uint64_t source_size = bps_number(p, end, &i);
    const uint64_t target_size = bps_number(p, end, &i);
    i += bps_number(p, end, &i); /* metadata */
    if (source_size != size || target_size != size || i > end) {
        return -1;
    }
    if (crc32(0, xbe, size) != ldl_le_p(p + end)) {
        return -2;
    }
    g_autofree uint8_t *target = g_malloc(size);
    size_t out = 0;
    int64_t source_rel = 0, target_rel = 0;
    int actions = 0;
    while (i < end) {
        const uint64_t d = bps_number(p, end, &i);
        const uint64_t len = (d >> 2) + 1;
        if (out + len > size) {
            return -1;
        }
        switch (d & 3) {
        case 0: /* SourceRead */
            memcpy(target + out, xbe + out, len);
            break;
        case 1: /* TargetRead */
            if (i + len > end) {
                return -1;
            }
            memcpy(target + out, p + i, len);
            i += len;
            break;
        case 2: { /* SourceCopy */
            const uint64_t o = bps_number(p, end, &i);
            source_rel += (o & 1 ? -1 : 1) * (int64_t)(o >> 1);
            if (source_rel < 0 || source_rel + len > size) {
                return -1;
            }
            memcpy(target + out, xbe + source_rel, len);
            source_rel += len;
            break;
        }
        case 3: { /* TargetCopy, byte by byte as it may overlap */
            const uint64_t o = bps_number(p, end, &i);
            target_rel += (o & 1 ? -1 : 1) * (int64_t)(o >> 1);
            if (target_rel < 0 || target_rel + len > out + len) {
                return -1;
            }
            for (uint64_t k = 0; k < len; k++) {
                target[out + k] = target[target_rel++];
            }
            break;
        }
        }
        out += len;
        actions++;
    }
    if (out != size || crc32(0, target, size) != ldl_le_p(p + end + 4)) {
        return -1;
    }
    memcpy(xbe, target, size);
    return actions;
}

static bool jmp_hex(const char *hex, GByteArray *out)
{
    const size_t n = strlen(hex);
    if (!n || n % 2) {
        return false;
    }
    for (size_t i = 0; i < n; i += 2) {
        const int hi = g_ascii_xdigit_value(hex[i]);
        const int lo = g_ascii_xdigit_value(hex[i + 1]);
        if (hi < 0 || lo < 0) {
            return false;
        }
        const guint8 byte = (guint8)(hi << 4 | lo);
        g_byte_array_append(out, &byte, 1);
    }
    return true;
}

/* A Jay's Magic Patcher patch: lines "0xOFFSET:BYTES" write the bytes at
 * that offset of the XBE; the other lines go in pairs, bytes to find and the
 * bytes of the same length to put in their place, at the first place they
 * are found (a patch that changes two places of the same bytes has the pair
 * twice). -2 when bytes to find are not in the XBE: the patch is for
 * another release's. */
static int xbe_apply_jmp(uint8_t *xbe, size_t size, const char *text, const char *name)
{
    g_auto(GStrv) lines = g_strsplit_set(text, "\r\n", -1);
    g_autoptr(GByteArray) find = NULL;
    int records = 0;
    for (char **l = lines; *l; l++) {
        char *s = g_strstrip(*l);
        if (!s[0] || s[0] == '#' || strchr(s, '=')) {
            continue; /* comments and key=value lines */
        }
        g_autoptr(GByteArray) bytes = g_byte_array_new();
        char *colon = strchr(s, ':');
        if (colon) {
            *colon = '\0';
            char *end;
            const char *off_text = g_ascii_strncasecmp(s, "0x", 2) ? s : s + 2;
            const guint64 off = g_ascii_strtoull(off_text, &end, 16);
            if (*end || end == off_text || !jmp_hex(g_strstrip(colon + 1), bytes) ||
                off + bytes->len > size) {
                return -1;
            }
            memcpy(xbe + off, bytes->data, bytes->len);
            records++;
            continue;
        }
        if (!jmp_hex(s, bytes)) {
            return -1;
        }
        if (!find) {
            find = g_steal_pointer(&bytes);
            continue;
        }
        if (bytes->len != find->len) {
            return -1;
        }
        if (memcmp(find->data, bytes->data, find->len)) {
            const uint8_t *at = NULL;
            for (size_t i = 0; !at && i + find->len <= size; i++) {
                if (xbe[i] == find->data[0] && !memcmp(xbe + i, find->data, find->len)) {
                    at = xbe + i; /* memmem, which MinGW lacks */
                }
            }
            if (!at) {
                LRLOG_ERROR("[xemu] XBE patch %s: bytes to find on line %u are not in "
                            "this default.xbe\n", name, (unsigned)(l - lines));
                return -2;
            }
            memcpy((uint8_t *)at, bytes->data, bytes->len);
            records++;
        }
        g_clear_pointer(&find, g_byte_array_unref);
    }
    return find ? -1 : records;
}

/* The overlay with image's default.xbe patched, for the drive to open
 * (system/vl.c, xemu_libretro_change_disc); its path, or NULL without
 * patches or when none applied. offset is the game partition's in a Redump
 * image. Under the BQL. */
char *xemu_libretro_xbe_patched(const char *image, uint64_t offset)
{
    if (!patch_enabled || !patch_enabled->len || !system_dir[0]) {
        return NULL;
    }
    GPtrArray *files = patch_enabled;
    Error *err = NULL;
    QDict *opts = qdict_new();
    qdict_put_str(opts, "driver", "raw");
    qdict_put_int(opts, "offset", (int64_t)offset);
    qdict_put_str(opts, "file.driver", "file");
    qdict_put_str(opts, "file.filename", image);
    BlockBackend *iso = blk_new_open(NULL, NULL, opts, 0, &err);
    if (!iso) {
        LRLOG_ERROR("[xemu] XBE patches: cannot open %s: %s\n", image, error_get_pretty(err));
        error_free(err);
        return NULL;
    }
    char *overlay = NULL;
    uint8_t *buf = NULL;
    uint32_t sector, size;
    if (!xiso_find_xbe(xiso_blk_read, iso, &sector, &size) || !size) {
        LRLOG_ERROR("[xemu] XBE patches: no default.xbe found in %s\n", image);
        goto out;
    }
    const int64_t xbe_off = (int64_t)sector * XISO_SECTOR;
    const int64_t start = xbe_off & ~(int64_t)(XBE_PATCH_CLUSTER - 1);
    const int64_t total = blk_getlength(iso);
    int64_t end = (xbe_off + size + XBE_PATCH_CLUSTER - 1) & ~(int64_t)(XBE_PATCH_CLUSTER - 1);
    end = MIN(end, total);
    buf = g_malloc(end - start);
    if (blk_pread(iso, start, end - start, buf, 0) < 0) {
        goto out;
    }
    uint8_t *xbe = buf + (xbe_off - start);
    int applied = 0;
    for (guint i = 0; i < files->len; i++) {
        const char *f = files->pdata[i];
        g_autofree char *data = NULL;
        gsize n;
        if (!g_file_get_contents(f, &data, &n, NULL)) {
            continue;
        }
        /* each patch on a copy, so one that fails leaves no half of itself */
        g_autofree uint8_t *copy = g_memdup2(xbe, size);
        g_autofree char *lower = g_ascii_strdown(f, -1);
        const int r = g_str_has_suffix(lower, ".jmp") ? xbe_apply_jmp(copy, size, data, f)
                    : g_str_has_suffix(lower, ".bps") ? xbe_apply_bps(copy, size, (const uint8_t *)data, n)
                    : xbe_apply_ips(copy, size, (const uint8_t *)data, n);
        if (r == -2) {
            LRLOG_ERROR("[xemu] XBE patch %s not applied: it is for another release's "
                        "default.xbe (%s)\n", f, g_str_has_suffix(lower, ".jmp") ? "bytes not found" : "CRC");
            continue;
        }
        if (r < 0) {
            LRLOG_ERROR("[xemu] XBE patch %s not applied: not a valid patch, or it "
                        "writes past default.xbe's end\n", f);
            continue;
        }
        memcpy(xbe, copy, size);
        applied++;
        LRLOG_INFO("[xemu] XBE patch %s applied (%d changes)\n", f, r);
    }
    if (!applied) {
        goto out;
    }

    overlay = g_strdup_printf("%s/xemu/patched_disc.qcow2", system_dir);
    g_remove(overlay);
    bdrv_img_create(overlay, "qcow2", NULL, NULL, NULL, total, 0, true, &err);
    if (err) {
        LRLOG_ERROR("[xemu] XBE patches: cannot create %s: %s\n", overlay, error_get_pretty(err));
        error_free(err);
        g_clear_pointer(&overlay, g_free);
        goto out;
    }
    QDict *oopts = qdict_new();
    qdict_put_str(oopts, "driver", "qcow2");
    BlockBackend *out_blk = blk_new_open(overlay, NULL, oopts, BDRV_O_RDWR, &err);
    /* whole clusters with the image's own bytes around the XBE: a partial
     * one would read as zeros where it was not written */
    if (!out_blk || blk_pwrite(out_blk, start, end - start, buf, 0) < 0 ||
        blk_flush(out_blk) < 0) {
        LRLOG_ERROR("[xemu] XBE patches: cannot write %s\n", overlay);
        if (err) {
            error_free(err);
        }
        g_clear_pointer(&overlay, g_free);
    }
    if (out_blk) {
        blk_unref(out_blk);
    }
out:
    g_free(buf);
    blk_unref(iso);
    return overlay;
}

bool xemu_libretro_has_xbe_patches(const char *image)
{
    (void)image;
    return patch_enabled && patch_enabled->len > 0;
}

static bool hdd_has_snapshot(BlockDriverState *bs)
{
    GRAPH_RDLOCK_GUARD_MAINLOOP();
    QEMUSnapshotInfo *sn = NULL;
    int n = bdrv_snapshot_list(bs, &sn);
    g_free(sn);
    return n > 0;
}

static bool hdd_is_zero(const uint8_t *buf, size_t len)
{
    return buf[0] == 0 && !memcmp(buf, buf + 1, len - 1);
}

/* Every chunk of blk that is not all zero, into a new qcow2 image at path */
static bool hdd_copy_used(BlockBackend *blk, const char *path, int64_t size)
{
    Error *err = NULL;
    bdrv_img_create(path, "qcow2", NULL, NULL, NULL, size, 0, true, &err);
    if (err) {
        LRLOG_ERROR("[xemu] Trim HDD: cannot create %s: %s\n", path, error_get_pretty(err));
        error_free(err);
        return false;
    }
    QDict *opts = qdict_new();
    qdict_put_str(opts, "driver", "qcow2");
    BlockBackend *out = blk_new_open(path, NULL, opts, BDRV_O_RDWR, &err);
    if (!out) {
        LRLOG_ERROR("[xemu] Trim HDD: cannot open %s: %s\n", path, error_get_pretty(err));
        error_free(err);
        return false;
    }
    uint8_t *buf = g_malloc(HDD_COPY_CHUNK);
    bool ok = true;
    for (int64_t off = 0; off < size && ok; off += HDD_COPY_CHUNK) {
        const int64_t len = MIN(HDD_COPY_CHUNK, size - off);
        if (blk_pread(blk, off, len, buf, 0) < 0) {
            ok = false;
        } else if (!hdd_is_zero(buf, len) && blk_pwrite(out, off, len, buf, 0) < 0) {
            ok = false;
        }
    }
    g_free(buf);
    if (ok && blk_flush(out) < 0) {
        ok = false;
    }
    blk_unref(out);
    if (!ok) {
        LRLOG_ERROR("[xemu] Trim HDD: copying the image failed (free space?), the image stays as it was\n");
    }
    return ok;
}

static BlockDriverState *hdd_open(const char *path, int flags)
{
    Error *err = NULL;
    QDict *opts = qdict_new();
    qdict_put_str(opts, "driver", "qcow2");
    BlockDriverState *bs = bdrv_open(path, NULL, opts, flags, &err);
    if (!bs) {
        LRLOG_ERROR("[xemu] Trim HDD: cannot open %s: %s\n", path, error_get_pretty(err));
        error_free(err);
    }
    return bs;
}

static void hdd_trim(void)
{
    const char *path = g_config.sys.files.hdd_path;
    DriveInfo *dinfo = drive_get(IF_IDE, 0, 0);
    BlockBackend *blk = dinfo ? blk_by_legacy_dinfo(dinfo) : NULL;
    BlockDriverState *bs = blk ? blk_bs(blk) : NULL;
    if (!bs || !path || !path[0]) {
        return;
    }
    if (hdd_has_snapshot(bs)) {
        LRLOG_INFO("[xemu] Trim HDD: skipped, the image holds a savestate\n");
        return;
    }
    const int64_t size = blk_getlength(blk);
    if (size < HDD_CACHE_START + HDD_CACHE_LEN) {
        return;
    }
    struct stat before;
    const bool had_size = stat(path, &before) == 0;

    if (blk_pwrite_zeroes(blk, HDD_CACHE_START, HDD_CACHE_LEN, BDRV_REQ_MAY_UNMAP) < 0 ||
        blk_flush(blk) < 0) {
        LRLOG_ERROR("[xemu] Trim HDD: emptying X, Y and Z failed, the image stays as it was\n");
        return;
    }

    char *tmp = g_strdup_printf("%s.trim", path);
    char *bak = g_strdup_printf("%s.untrimmed", path);
    if (!hdd_copy_used(blk, tmp, size)) {
        g_remove(tmp);
        goto out;
    }

    /* The new image in the old one's place, under the same drive */
    const int flags = bdrv_get_flags(bs);
    blk_remove_bs(blk);
    bool replaced = g_rename(path, bak) == 0;
    if (replaced && g_rename(tmp, path) != 0) {
        g_rename(bak, path);
        replaced = false;
    }
    if (!replaced) {
        LRLOG_ERROR("[xemu] Trim HDD: cannot replace the image, the old one is kept\n");
        g_remove(tmp);
    }
    BlockDriverState *nbs = hdd_open(path, flags);
    Error *err = NULL;
    if (!nbs || blk_insert_bs(blk, nbs, &err) < 0) {
        if (err) {
            LRLOG_ERROR("[xemu] Trim HDD: %s\n", error_get_pretty(err));
            error_free(err);
        }
        if (nbs) {
            bdrv_unref(nbs);
            nbs = NULL;
        }
        if (replaced) {
            /* back to the image as it was */
            LRLOG_ERROR("[xemu] Trim HDD: the new image did not open, the old one is put back\n");
            g_remove(path);
            g_rename(bak, path);
            nbs = hdd_open(path, flags);
            if (nbs) {
                blk_insert_bs(blk, nbs, NULL);
            }
        }
    } else if (replaced) {
        g_remove(bak);
        struct stat after;
        if (had_size && stat(path, &after) == 0) {
            LRLOG_INFO("[xemu] Trim HDD: X, Y and Z emptied, the image went from %lld to %lld MB\n",
                       (long long)(before.st_size >> 20), (long long)(after.st_size >> 20));
        }
    }
    if (nbs) {
        bdrv_unref(nbs);
    }
out:
    g_free(tmp);
    g_free(bak);
}

/* ========================================================================= */
/* Libretro API implementation                                               */
/* ========================================================================= */

RETRO_API void retro_set_environment(retro_environment_t cb)
{
    environ_cb = cb;

    /* Set core options v2 */
    bool categories_supported = false;
    libretro_set_core_options(environ_cb, &categories_supported);

    /* Get log interface */
    struct retro_log_callback log;
    if (environ_cb(RETRO_ENVIRONMENT_GET_LOG_INTERFACE, &log)) {
        log_cb = log.log;
    }
    LRLOG_INFO("[xemu] retro_set_environment called\n");

    /* Get system directory for BIOS files */
    const char *sys_dir = NULL;
    if (environ_cb(RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY, &sys_dir) && sys_dir) {
        snprintf(system_dir, sizeof(system_dir), "%s", sys_dir);
        LRLOG_INFO("[xemu] System directory: %s\n", system_dir);
    } else {
        LRLOG_WARN("[xemu] Could not get system directory\n");
    }

    /* Started without content ("Start Core"), the Xbox boots with an empty
     * tray into its dashboard - the BIOS settings, the HDD's contents - as
     * standalone does with no disc (NNshi) */
    bool no_game = true;
    environ_cb(RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME, &no_game);

    /* Get VFS interface */
    struct retro_vfs_interface_info vfs_info = { 3, NULL };
    if (environ_cb(RETRO_ENVIRONMENT_GET_VFS_INTERFACE, &vfs_info)) {
        xemu_libretro_vfs = vfs_info.iface;
        LRLOG_INFO("[xemu] VFS interface obtained (version %u)\n", vfs_info.required_interface_version);
    }

    /* Set pixel format */
    enum retro_pixel_format fmt = RETRO_PIXEL_FORMAT_XRGB8888;
    environ_cb(RETRO_ENVIRONMENT_SET_PIXEL_FORMAT, &fmt);

    /* Set input descriptors — Xbox controller button labels */
    {
        struct retro_input_descriptor desc[] = {
#define PORT_DESCS(p) \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_B,      "A" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_A,      "B" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_Y,      "X" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_X,      "Y" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_L,      "White" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_R,      "Black" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_L2,     "Left Trigger" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_R2,     "Right Trigger" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_L3,     "Left Stick" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_R3,     "Right Stick" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_SELECT, "Back" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_START,  "Start" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_UP,     "D-Pad Up" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_DOWN,   "D-Pad Down" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_LEFT,   "D-Pad Left" }, \
            { p, RETRO_DEVICE_JOYPAD, 0, RETRO_DEVICE_ID_JOYPAD_RIGHT,  "D-Pad Right" }, \
            { p, RETRO_DEVICE_ANALOG, RETRO_DEVICE_INDEX_ANALOG_LEFT,  RETRO_DEVICE_ID_ANALOG_X, "Left Stick X" }, \
            { p, RETRO_DEVICE_ANALOG, RETRO_DEVICE_INDEX_ANALOG_LEFT,  RETRO_DEVICE_ID_ANALOG_Y, "Left Stick Y" }, \
            { p, RETRO_DEVICE_ANALOG, RETRO_DEVICE_INDEX_ANALOG_RIGHT, RETRO_DEVICE_ID_ANALOG_X, "Right Stick X" }, \
            { p, RETRO_DEVICE_ANALOG, RETRO_DEVICE_INDEX_ANALOG_RIGHT, RETRO_DEVICE_ID_ANALOG_Y, "Right Stick Y" },
            PORT_DESCS(0)
            PORT_DESCS(1)
            PORT_DESCS(2)
            PORT_DESCS(3)
#undef PORT_DESCS
            { 0 },
        };
        environ_cb(RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS, desc);
    }
}

RETRO_API void retro_set_video_refresh(retro_video_refresh_t cb)   { video_cb = cb; }
RETRO_API void retro_set_audio_sample(retro_audio_sample_t cb)     { audio_cb = cb; }
RETRO_API void retro_set_audio_sample_batch(retro_audio_sample_batch_t cb) { audio_batch_cb = cb; }
RETRO_API void retro_set_input_poll(retro_input_poll_t cb)         { input_poll_cb = cb; }
RETRO_API void retro_set_input_state(retro_input_state_t cb)       { input_state_cb = cb; }

RETRO_API unsigned retro_api_version(void)
{
    return RETRO_API_VERSION;
}

RETRO_API void retro_get_system_info(struct retro_system_info *info)
{
    memset(info, 0, sizeof(*info));
    info->library_name     = "xemu";
    info->library_version  = xemu_libretro_version;
    info->valid_extensions = "iso|xiso|bin";
    info->need_fullpath    = true;
    info->block_extract    = true;
}

/* 1920x1080 times the scale, within what a GPU takes for an image */
static void xemu_max_geometry(int scale, unsigned *width, unsigned *height)
{
    *width = MIN(1920u * (unsigned)MAX(scale, 1), 8192u);
    *height = MIN(1080u * (unsigned)MAX(scale, 1), 8192u);
}

RETRO_API void retro_get_system_av_info(struct retro_system_av_info *info)
{
    memset(info, 0, sizeof(*info));
    info->geometry.base_width   = 640;
    info->geometry.base_height  = 480;
    xemu_max_geometry(opt_surface_scale, &declared_max_width, &declared_max_height);
    info->geometry.max_width    = declared_max_width;
    info->geometry.max_height   = declared_max_height;
    info->geometry.aspect_ratio = wants_widescreen() ? 16.0f / 9.0f : 4.0f / 3.0f;
    info->timing.fps            = 59.94;
    info->timing.sample_rate    = 48000.0;
}

RETRO_API void retro_init(void)
{
    LRLOG_INFO("[xemu] retro_init\n");
    /* Which commit of this repository the core was built from, so a
     * tester's log says which build it came from (xemu_commit, from
     * scripts/xemu-version.py at configure time) */
    LRLOG_INFO("[xemu] xemu libretro core %s, built from commit %.9s\n",
               xemu_version, xemu_commit[0] ? xemu_commit : "unknown");

    /* The core stays in memory once loaded. retro_unload_game joins only the
     * emulation thread; QEMU's other threads (RCU, vCPU, nv2a) keep running
     * - upstream never joins them either, its exit() ends them - and its
     * atexit handlers stay registered, so when the frontend unloaded the
     * core they ran on unmapped code and RetroArch crashed on close (and
     * hung while the crash was dumped). Pinned, they end with the process,
     * as in standalone. */
    {
#ifdef _WIN32
        HMODULE self;
        if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                                GET_MODULE_HANDLE_EX_FLAG_PIN,
                                (LPCWSTR)(void *)retro_init, &self)) {
            LRLOG_WARN("[xemu] could not keep the core loaded: error %lu\n",
                       GetLastError());
        }
#else
        Dl_info info;
        /* A reference that is never dropped; RTLD_NODELETE keeps the
         * object even past it */
        if (!dladdr((void *)retro_init, &info) || !info.dli_fname ||
            !dlopen(info.dli_fname, RTLD_NOW | RTLD_NOLOAD | RTLD_NODELETE)) {
            LRLOG_WARN("[xemu] could not keep the core loaded\n");
        }
#endif
    }

    /* Initialize Windows TLS keys for __thread replacements */
#if defined(LIBRETRO) && defined(_WIN32)
    {
        extern unsigned long tls_key_tcg_ctx;
        extern unsigned long tls_key_current_cpu;
        unsigned long __stdcall TlsAlloc(void);
        if (tls_key_tcg_ctx == 0xFFFFFFFF)
            tls_key_tcg_ctx = TlsAlloc();
        if (tls_key_current_cpu == 0xFFFFFFFF)
            tls_key_current_cpu = TlsAlloc();
        LRLOG_INFO("[xemu] TLS keys initialized: tcg_ctx=%lu current_cpu=%lu\n",
                   tls_key_tcg_ctx, tls_key_current_cpu);
    }
#endif

#ifdef _WIN32
    /* Set Windows timer resolution to 1ms for accurate APU throttle sleeps.
     * Default is ~15.6ms which causes bursty audio production. */
    {
        typedef unsigned int (__stdcall *timeBeginPeriod_t)(unsigned int);
        HMODULE winmm = LoadLibraryA("winmm.dll");
        if (winmm) {
            timeBeginPeriod_t fn = (timeBeginPeriod_t)GetProcAddress(winmm, "timeBeginPeriod");
            if (fn) {
                fn(1);
                LRLOG_INFO("[xemu] Set Windows timer resolution to 1ms\n");
            }
        }
    }
#endif

    /* Initialize the GL readiness wait event early */
    extern void libretro_gl_init_wait_event(void);
    libretro_gl_init_wait_event();
}

RETRO_API void retro_deinit(void)
{
    LRLOG_INFO("[xemu] retro_deinit\n");
    game_loaded = false;
    emu_initialized = false;
    context_ready = false;
    use_vulkan = false;
}

/* A content refused at load: the reason as a notification and in the log */
static void load_refused(const char *text)
{
    struct retro_message_ext msg = {
        .msg = text,
        .duration = 6000,
        .priority = 3,
        .level = RETRO_LOG_ERROR,
        .target = RETRO_MESSAGE_TARGET_ALL,
        .type = RETRO_MESSAGE_TYPE_NOTIFICATION,
        .progress = -1,
    };
    unsigned msg_version = 0;
    if (environ_cb(RETRO_ENVIRONMENT_GET_MESSAGE_INTERFACE_VERSION, &msg_version) &&
        msg_version >= 1) {
        environ_cb(RETRO_ENVIRONMENT_SET_MESSAGE_EXT, &msg);
    } else {
        struct retro_message old = { text, 360 };
        environ_cb(RETRO_ENVIRONMENT_SET_MESSAGE, &old);
    }
    LRLOG_ERROR("[xemu] %s\n", text);
}

/* Audio > Audio Thread: RetroArch's audio thread asks for the sound, and gets
 * what the APU has mixed as it comes, at the sound card's pace as standalone
 * plays it, so the sound keeps going while retro_run stalls (shaders being
 * compiled). The APU still waits once about 64 ms is queued (apu.c). The
 * ring has one reader, this thread now; retro_run leaves it alone. RetroArch
 * stops calling while it pauses (audio_thread_set_state). */
static void audio_thread_callback(void)
{
    extern int libretro_audio_pull(int16_t *out_buf, int max_frames);
    extern void libretro_audio_flush(void);
    static bool flushed = false;
    int16_t buf[1024 * 2];

    if (!emu_initialized || !audio_async_enabled || !audio_batch_cb) {
        g_usleep(2000);
        return;
    }
    if (!flushed) {
        /* the stale boot audio, as the frame-paced path drops it */
        libretro_audio_flush();
        flushed = true;
    }
    const int frames = libretro_audio_pull(buf, 1024);
    if (frames > 0) {
        audio_batch_cb(buf, frames);
    } else {
        g_usleep(1000);
    }
}

static void audio_thread_set_state(bool enabled)
{
    qatomic_set(&audio_async_enabled, enabled);
}

RETRO_API bool retro_load_game(const struct retro_game_info *game)
{
    /* The pads' motors (retro_run); without one, no rumble */
    memset(&rumble, 0, sizeof(rumble));
    if (!environ_cb(RETRO_ENVIRONMENT_GET_RUMBLE_INTERFACE, &rumble)) {
        memset(&rumble, 0, sizeof(rumble));
    }


    LRLOG_INFO("[xemu] retro_load_game called\n");

    /* QEMU starts once in a process: its machine, devices and threads are
     * not taken down when content is closed (the core stays loaded, see
     * retro_init), and starting them again crashed RetroArch (NNshi). The
     * next content runs on the machine that is there (emu_thread_func). On
     * Vulkan that is: the renderer was taken off RetroArch's device when the
     * content was closed (vk_park_renderer) and is put on the new one in
     * context_reset, as after any loss of the context. On OpenGL the
     * renderer's contexts share with RetroArch's context of the first
     * content, which is gone by the second, so there another content is
     * still refused, with a message, rather than loaded into a black
     * screen. */
    if (emu_started_once && !emu_started_vulkan) {
        load_refused("xemu: on OpenGL, restart RetroArch to load another game");
        return false;
    }

    const char *content = (game && game->path) ? game->path : "";

    /* The machine that is there is an Xbox or a Chihiro, and the next
     * content only gets its disc swapped: a Chihiro game after an Xbox one
     * booted the Xbox dashboard with the netboot image in the drive (NNshi).
     * The other machine needs RetroArch started again. An Xbox disc image
     * boots an Xbox, any other image a Chihiro, no content an Xbox. */
    const bool chihiro = content[0] && !xemu_media_is_xbox_disc(content);
    if (emu_started_once && chihiro != emu_started_chihiro) {
        load_refused(chihiro
            ? "xemu: restart RetroArch to load a Chihiro game after an Xbox one"
            : "xemu: restart RetroArch to load an Xbox game after a Chihiro one");
        return false;
    }
    /* A Chihiro's game is in its media board's memory, which another game
     * fills again (chihiro_change_game, when the machine is started); one
     * larger than the memory the machine was built with needs RetroArch
     * started again (NNshi) */
    if (emu_started_once && chihiro && strcmp(content, emu_started_image) &&
        !chihiro_netboot_image_fits(content)) {
        load_refused("xemu: restart RetroArch to load this Chihiro game, larger than the last one's media board memory");
        return false;
    }
    if (content[0]) {
        LRLOG_INFO("[xemu] Loading game: %s\n", content);
    } else {
        LRLOG_INFO("[xemu] No content: booting the dashboard, tray empty\n");
    }

    /* Read core options */
    update_variables();

    /* Patch Manager: this game's patches, and its options */
    patch_manager_load(content, chihiro);

    /* Audio > Audio Thread, for this load */
    audio_async = false;
    if (opt_audio_thread) {
        struct retro_audio_callback audio_callback = {
            audio_thread_callback, audio_thread_set_state
        };
        audio_async = environ_cb(RETRO_ENVIRONMENT_SET_AUDIO_CALLBACK, &audio_callback);
        LRLOG_INFO("[xemu] Audio: %s\n", audio_async ? "on RetroArch's audio thread"
                                                   : "a frame's worth each frame (no audio thread to be had)");
    }

    /* Store the DVD path (empty: no disc) */
    snprintf(opt_dvd_path, sizeof(opt_dvd_path), "%s", content);

    /* Set shader cache base path */
    if (system_dir[0]) {
        char base_path[4096];
        snprintf(base_path, sizeof(base_path), "%s/xemu/", system_dir);
        extern void libretro_settings_set_base_path(const char *path);
        libretro_settings_set_base_path(base_path);
        LRLOG_INFO("[xemu] Shader cache base path: %s\n", base_path);
    }

    /* Auto-populate BIOS paths from system directory if not set by options.
     * Each file is looked for in system/xemu/ and then in system/ itself,
     * where an older core info file had them (boardsofcanada), and the BIOS
     * under both of the names it goes by. The first one there is used; when
     * none is, the path stays the first place, for the message below. */
    if (system_dir[0]) {
        static const char *const dirs[] = { "xemu/", "" };
        static const char *const bootrom_names[] = { "mcpx_1.0.bin", NULL };
        static const char *const bios_names[] = { "Complex_4627v1.03.bin", "Complex_4627.bin", NULL };
        static const char *const hdd_names[] = { "xbox_hdd.qcow2", NULL };
        static const char *const eeprom_names[] = { "xbox_eeprom.bin", NULL };
        const struct {
            char *path;
            size_t size;
            const char *const *names;
            const char *what;
        } files[] = {
            { opt_bootrom_path, sizeof(opt_bootrom_path), bootrom_names, "bootrom" },
            { opt_bios_path, sizeof(opt_bios_path), bios_names, "bios" },
            { opt_hdd_path, sizeof(opt_hdd_path), hdd_names, "hdd" },
            { opt_eeprom_path, sizeof(opt_eeprom_path), eeprom_names, "eeprom" },
        };
        for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); i++) {
            bool found = false;
            if (files[i].path[0]) {
                continue;
            }
            for (size_t d = 0; d < sizeof(dirs) / sizeof(dirs[0]) && !found; d++) {
                for (size_t n = 0; files[i].names[n] && !found; n++) {
                    FILE *probe;
                    snprintf(files[i].path, files[i].size, "%s/%s%s",
                             system_dir, dirs[d], files[i].names[n]);
                    probe = fopen(files[i].path, "rb");
                    if (probe) {
                        fclose(probe);
                        found = true;
                    }
                }
            }
            if (!found) {
                snprintf(files[i].path, files[i].size, "%s/xemu/%s",
                         system_dir, files[i].names[0]);
            }
            LRLOG_INFO("[xemu] Auto-set %s: %s\n", files[i].what, files[i].path);
        }
    }

    /* Validate required files exist */
    {
        FILE *f;
        f = fopen(opt_bootrom_path, "rb");
        if (!f) {
            LRLOG_ERROR("[xemu] MCPX Boot ROM not found: %s\n", opt_bootrom_path);
            LRLOG_ERROR("[xemu] Place mcpx_1.0.bin in RetroArch system/xemu/ directory\n");
            return false;
        }
        fclose(f);
        LRLOG_INFO("[xemu] Found bootrom: %s\n", opt_bootrom_path);

        f = fopen(opt_bios_path, "rb");
        if (!f) {
            LRLOG_ERROR("[xemu] Xbox BIOS not found: %s\n", opt_bios_path);
            LRLOG_ERROR("[xemu] Place Complex_4627v1.03.bin in RetroArch system/xemu/ directory\n");
            return false;
        }
        fclose(f);
        LRLOG_INFO("[xemu] Found bios: %s\n", opt_bios_path);

        f = fopen(opt_hdd_path, "rb");
        if (!f && write_bundled_hdd(opt_hdd_path)) {
            f = fopen(opt_hdd_path, "rb");
        }
        if (!f) {
            LRLOG_ERROR("[xemu] Xbox HDD image not found: %s\n", opt_hdd_path);
            LRLOG_ERROR("[xemu] Place xbox_hdd.qcow2 in RetroArch system/xemu/ directory\n");
            return false;
        }
        fclose(f);
        LRLOG_INFO("[xemu] Found hdd: %s\n", opt_hdd_path);
    }

    /* Query the frontend's preferred HW render context */
    unsigned preferred_hw = RETRO_HW_CONTEXT_OPENGL_CORE;
    if (environ_cb) {
        environ_cb(RETRO_ENVIRONMENT_GET_PREFERRED_HW_RENDER, &preferred_hw);
    }
    LRLOG_INFO("[xemu] Frontend preferred HW render: %u\n", preferred_hw);

    /* The Graphics API option decides, not the frontend's video driver:
     * RetroArch's preferred context only follows its own driver setting */
    bool want_vulkan = opt_renderer_vulkan;
#ifdef __ANDROID__
    /* No GL renderer in the Android build: Vulkan, whatever is preferred */
    want_vulkan = true;
#endif
#ifdef __APPLE__
    /* MoltenVK has no geometry shaders, which the Vulkan renderer needs: GL,
     * whatever is preferred */
    want_vulkan = false;
#endif
    if (emu_started_once) {
        /* the machine was started on Vulkan (checked above) and stays on it,
         * whatever the option says now */
        want_vulkan = true;
    }

    /* Setup hardware rendering based on frontend preference */
    memset(&hw_render, 0, sizeof(hw_render));
    hw_render.context_reset      = context_reset;
    hw_render.context_destroy    = context_destroy;
    hw_render.depth              = true;
    hw_render.stencil            = true;
    hw_render.bottom_left_origin = true;
    hw_render.cache_context      = true;

    if (want_vulkan) {
        LRLOG_INFO("[xemu] Requesting Vulkan HW context\n");
        hw_render.context_type = RETRO_HW_CONTEXT_VULKAN;
        hw_render.version_major = 1;
        hw_render.version_minor = 3;
    } else {
        LRLOG_INFO("[xemu] Requesting OpenGL Core 4.0 HW context\n");
        hw_render.context_type = RETRO_HW_CONTEXT_OPENGL_CORE;
        hw_render.version_major = 4;
        hw_render.version_minor = 0;
    }

    if (!environ_cb(RETRO_ENVIRONMENT_SET_HW_RENDER, &hw_render)) {
        /* Preferred context failed - try the other one */
        LRLOG_INFO("[xemu] Preferred context failed, trying fallback\n");
        memset(&hw_render, 0, sizeof(hw_render));
        hw_render.context_reset      = context_reset;
        hw_render.context_destroy    = context_destroy;
        hw_render.depth              = true;
        hw_render.stencil            = true;
        hw_render.bottom_left_origin = true;
        hw_render.cache_context      = true;

        if (want_vulkan) {
            hw_render.context_type = RETRO_HW_CONTEXT_OPENGL_CORE;
            hw_render.version_major = 4;
            hw_render.version_minor = 0;
            want_vulkan = false;
        } else {
            hw_render.context_type = RETRO_HW_CONTEXT_VULKAN;
            hw_render.version_major = 1;
            hw_render.version_minor = 3;
            want_vulkan = true;
        }

        if (!environ_cb(RETRO_ENVIRONMENT_SET_HW_RENDER, &hw_render)) {
            LRLOG_ERROR("[xemu] Failed to set HW render (neither GL nor VK available)\n");
            return false;
        }
    }

    if (emu_started_once && !want_vulkan) {
        /* the machine's renderer is Vulkan and cannot be changed under it */
        LRLOG_ERROR("[xemu] No Vulkan context for the next content; the machine was started on Vulkan\n");
        return false;
    }

    use_vulkan = want_vulkan;
    if (use_vulkan) {
        LRLOG_INFO("[xemu] Using Vulkan HW rendering\n");
        environ_cb(RETRO_ENVIRONMENT_SET_HW_RENDER_CONTEXT_NEGOTIATION_INTERFACE,
                   (void *)&xemu_vk_negotiation);
    } else {
        LRLOG_INFO("[xemu] Using OpenGL HW rendering\n");
        environ_cb(RETRO_ENVIRONMENT_SET_HW_SHARED_CONTEXT, NULL);
    }

    /* Populate xemu config from core options */
    populate_config(opt_dvd_path);

    /* Start emulation thread */
    emu_thread_running = true;
    emu_started_once = true;
    emu_started_vulkan = use_vulkan;
    emu_started_chihiro = chihiro;
    snprintf(emu_started_image, sizeof(emu_started_image), "%s", content);
    qemu_thread_create(&emu_thread, "xemu-emu", emu_thread_func,
                       NULL, QEMU_THREAD_JOINABLE);

    game_loaded = true;

    LRLOG_INFO("[xemu] retro_load_game completed successfully\n");
    return true;
}

RETRO_API bool retro_load_game_special(unsigned type,
                                        const struct retro_game_info *info,
                                        size_t num_info)
{
    (void)type; (void)info; (void)num_info;
    return false;
}

RETRO_API void retro_unload_game(void)
{
    LRLOG_INFO("[xemu] retro_unload_game\n");

    if (emu_thread_running) {
        /* while the guest still runs: the switch needs its CPU, and the
         * frontend destroys the device after this */
        if (use_vulkan) {
            vk_park_renderer();
        }
        emu_thread_running = false;
        qemu_system_shutdown_request(SHUTDOWN_CAUSE_HOST_SIGNAL);
        qemu_thread_join(&emu_thread);
        LRLOG_INFO("[xemu] Emulation thread joined\n");
    }
    qatomic_set(&last_run_us, 0);
    qatomic_set(&frontend_paused, false);

    game_loaded = false;
    emu_initialized = false;
}

/* The vblank's trip to the emulator thread: when retro_run asked for it, and
 * how late it was raised (in the 300-run log line) */
static int64_t vblank_asked_us;
static int64_t vblank_delay_sum_us, vblank_delay_max_us;

/* The picture is taken once the guest has handled the vblank this run
 * raised: its handler is what points the display at the frame it just
 * flipped. Taken before, the race with it showed about a quarter of the
 * frames twice and skipped as many, the game itself flipping every vblank
 * (NNshi's log: 300 flips, 224 new pictures in 300 runs). A guest that does
 * not acknowledge its vblanks (early boot) is not waited for: after a
 * timeout the wait is off for a second. */
extern uint64_t xemu_lr_vblanks_raised, xemu_lr_vblanks_acked;
static uint64_t vblank_target;
static int vblank_wait_off;
static int64_t vblank_wait_sum_us;
static int vblank_wait_timeouts;
static void wait_for_vblank_handled(void)
{
    if (vblank_wait_off > 0) {
        vblank_wait_off--;
        return;
    }
    const int64_t t0 = g_get_monotonic_time();
    int64_t t = t0;
    while (qatomic_read(&xemu_lr_vblanks_acked) < vblank_target) {
        if (t - t0 > 4000) {
            vblank_wait_timeouts++;
            vblank_wait_off = 60;
            break;
        }
        g_usleep(100);
        t = g_get_monotonic_time();
    }
    vblank_wait_sum_us += t - t0;
}
static void libretro_vblank_bh(void *opaque)
{
    const int64_t delay = g_get_monotonic_time() - qatomic_read(&vblank_asked_us);
    qatomic_set(&vblank_delay_sum_us, qatomic_read(&vblank_delay_sum_us) + delay);
    if (delay > qatomic_read(&vblank_delay_max_us)) {
        qatomic_set(&vblank_delay_max_us, delay);
    }
    graphic_hw_update(opaque);

    /* about once a second */
    static int title_poll;
    if (++title_poll >= 60) {
        title_poll = 0;
        poll_guest_title();
    }
}

RETRO_API void retro_run(void)
{
    static int run_count = 0;
    /* Where the time of a run goes, over the last 300 runs: the whole run
     * from the previous one's start, the wait for the renderer to draw the
     * display, and the frontend's video and audio callbacks. For telling a
     * slow guest from a slow hand-over in a tester's log. */
    static int64_t st_last_start, st_period_sum, st_period_max;
    static int64_t st_sync_sum, st_sync_max, st_video_sum, st_video_max;
    static int64_t st_audio_sum, st_audio_max;
    static int st_new_frames;
    static uint64_t st_guest_frames;
    int64_t st_t;
    const int64_t st_start = g_get_monotonic_time();

    if (st_last_start) {
        const int64_t period = st_start - st_last_start;
        st_period_sum += period;
        st_period_max = MAX(st_period_max, period);
    }
    st_last_start = st_start;

    /* a stopped machine is started again by the main loop, woken here */
    qatomic_set(&last_run_us, st_start);
    if (qatomic_read(&frontend_paused)) {
        qemu_notify_event();
    }

    run_count++;
    if (run_count <= 5 || (run_count % 300) == 0) {
        LRLOG_INFO("[xemu] retro_run #%d (emu_init=%d ctx_ready=%d game=%d)\n",
                   run_count, emu_initialized, context_ready, game_loaded);
    }
    if ((run_count % 300) == 0 && use_vulkan && xemu_libretro_vk.active) {
        const uint64_t guest_frames = nv2a_vk_libretro_guest_frames();
        LRLOG_INFO("[xemu] last 300 runs: %d guest frames; %d new frames; run every %.2f ms "
                   "(max %.2f); renderer wait %.2f ms (max %.2f); video "
                   "callback %.2f ms (max %.2f); audio callback %.2f ms "
                   "(max %.2f)\n",
                   (int)(guest_frames - st_guest_frames), st_new_frames,
                   st_period_sum / 300000.0,
                   st_period_max / 1000.0, st_sync_sum / 300000.0,
                   st_sync_max / 1000.0, st_video_sum / 300000.0,
                   st_video_max / 1000.0, st_audio_sum / 300000.0,
                   st_audio_max / 1000.0);
        /* The guest's own flips (FLIP_STALL), by when they were issued after
         * the vblank they wait for, and how long the pusher waited for them
         * (nv2a.c); a flip issued after 16.7 ms misses its vblank */
        {
            extern uint64_t xemu_lr_flips, xemu_lr_flip_phase[4];
            extern int64_t xemu_lr_flip_wait_sum_ns, xemu_lr_flip_wait_max_ns;
            const uint64_t flips = qatomic_xchg(&xemu_lr_flips, 0);
            uint64_t ph[4];
            for (int i = 0; i < 4; i++) {
                ph[i] = qatomic_xchg(&xemu_lr_flip_phase[i], 0);
            }
            const int64_t wsum = qatomic_xchg(&xemu_lr_flip_wait_sum_ns, 0);
            const int64_t wmax = qatomic_xchg(&xemu_lr_flip_wait_max_ns, 0);
            const int64_t vsum = qatomic_xchg(&vblank_delay_sum_us, 0);
            const int64_t vmax = qatomic_xchg(&vblank_delay_max_us, 0);
            LRLOG_INFO("[xemu] last 300 runs: %d flips, issued after the vblank "
                       "<8 ms %d, 8-14 %d, 14-16.7 %d, later %d; flip wait %.2f ms "
                       "(max %.2f); vblank raised %.2f ms after retro_run (max %.2f), "
                       "handled by the guest %.2f ms after it (%d not within 4 ms)\n",
                       (int)flips, (int)ph[0], (int)ph[1], (int)ph[2], (int)ph[3],
                       flips ? wsum / 1e6 / flips : 0.0, wmax / 1e6,
                       vsum / 300000.0, vmax / 1000.0,
                       vblank_wait_sum_us / 300000.0, vblank_wait_timeouts);
            vblank_wait_sum_us = 0;
            vblank_wait_timeouts = 0;
        }
        st_guest_frames = guest_frames;
        st_new_frames = 0;
        st_period_sum = st_period_max = 0;
        st_sync_sum = st_sync_max = 0;
        st_video_sum = st_video_max = 0;
        st_audio_sum = st_audio_max = 0;
    }

    /* Schedule vblank (graphic_hw_update) on emu thread. Before the picture
     * is taken, not after: raised after it, the wait for the renderer in the
     * game's heavy scenes grew from 2-4 ms to 6-7 ms and RetroArch's presents
     * came in pairs, a late one and an early one (NNshi's captures). */
    {
        QemuConsole *con = nv2a_get_vga_console();
        if (con) {
            qatomic_set(&vblank_asked_us, g_get_monotonic_time());
            vblank_target = qatomic_read(&xemu_lr_vblanks_raised) + 1;
            aio_bh_schedule_oneshot(qemu_get_aio_context(), libretro_vblank_bh,
                                    con);
        }
    }

    /* Check if variables have been updated */
    bool updated = false;
    if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE, &updated) && updated) {
        update_variables();
    }

    /* Poll input */
    if (input_poll_cb) {
        input_poll_cb();
    }

    /* A Chihiro's cabinet controls (libretro-chihiro.c) */
    {
        extern void libretro_chihiro_update_input(void);
        libretro_chihiro_update_input();
    }

    /* The motors the guest set since the last run (libretro-stubs.c) */
    {
        extern void libretro_input_apply_rumble(retro_set_rumble_state_t);
        libretro_input_apply_rumble(rumble.set_rumble_state);
    }

    if (!emu_initialized || !context_ready) {
        /* Emulator not ready yet, draw black frame */
        if (!use_vulkan && hw_render.get_current_framebuffer) {
            uintptr_t fbo = hw_render.get_current_framebuffer();
            glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)fbo);
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
            video_cb(RETRO_HW_FRAME_BUFFER_VALID, 640, 480, 0);
        } else if (use_vulkan) {
            /* VK mode: pass NULL frame (no HW framebuffer concept) */
            video_cb(NULL, 640, 480, 0);
        } else {
            video_cb(RETRO_HW_FRAME_BUFFER_VALID, 640, 480, 0);
        }

        /* Push silence for audio (the audio thread, when it has it, does
         * its own) */
        if (audio_batch_cb && !audio_async) {
            int16_t silence[1600] = {0}; /* ~800 samples stereo */
            audio_batch_cb(silence, 800);
        }
        return;
    }

    update_aspect();

    /* ---- OpenGL path ---- */
    if (!use_vulkan) {
        /* Get NV2A framebuffer texture */
        GLuint tex = nv2a_get_framebuffer_surface();
        uintptr_t fbo = hw_render.get_current_framebuffer();

        unsigned width = 640;
        unsigned height = 480;

        if (tex) {
            /* The frame at the size it was rendered at - Internal
             * Resolution Scale times the guest's output - not squeezed back
             * into 640x480, which undid the scaling on GL (NNshi) */
            GLint tex_w = 0, tex_h = 0;
            glBindTexture(GL_TEXTURE_2D, tex);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &tex_w);
            glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &tex_h);
            glBindTexture(GL_TEXTURE_2D, 0);
            if (tex_w > 0 && tex_h > 0 &&
                (unsigned)tex_w <= declared_max_width &&
                (unsigned)tex_h <= declared_max_height) {
                width = (unsigned)tex_w;
                height = (unsigned)tex_h;
            }
            blit_nv2a_texture(tex, width, height, fbo);
            draw_gl_crosshairs(width, height, fbo);
        } else {
            /* No framebuffer yet */
            glBindFramebuffer(GL_FRAMEBUFFER, (GLuint)fbo);
            glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        nv2a_release_framebuffer_surface();
        video_cb(RETRO_HW_FRAME_BUFFER_VALID, width, height, 0);
    }
    /* ---- Vulkan path ---- */
    else if (use_vulkan) {
        unsigned width = 640;
        unsigned height = 480;

        if (!vulkan_if) {
            video_cb(NULL, width, height, 0);
            goto vk_audio;
        }

        if (xemu_libretro_vk.active) {
            /* The frame rendered now, on the device shared with the
             * frontend, and handed over in this run: the renderer draws the
             * display, copies it into the image of the frontend's current
             * sync index and waits for the GPU (pgraph/vk/display.c) */
            static uint64_t last_count;
            static unsigned last_w = 640, last_h = 480;
            const int index =
                (int)vulkan_if->get_sync_index(vulkan_if->handle);
            VkImage image;
            VkImageView view;
            VkFormat format;
            int frame_w, frame_h;
            uint64_t count = last_count;

            xemu_libretro_vk.frame_index = index;
            if (!vk_renderer_parked) {
                wait_for_vblank_handled();
                st_t = g_get_monotonic_time();
                nv2a_get_framebuffer_surface();
                nv2a_release_framebuffer_surface();
                st_t = g_get_monotonic_time() - st_t;
                st_sync_sum += st_t;
                st_sync_max = MAX(st_sync_max, st_t);
            }

            if (!vk_renderer_parked &&
                nv2a_vk_libretro_get_frame(index, &image, &view, &format,
                                           &frame_w, &frame_h, &count) &&
                count != last_count) {
                last_count = count;
                last_w = (unsigned)frame_w;
                last_h = (unsigned)frame_h;

                retro_vk_image.image_view = view;
                retro_vk_image.image_layout =
                    VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                retro_vk_image.create_info = (VkImageViewCreateInfo){
                    .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
                    .image = image,
                    .viewType = VK_IMAGE_VIEW_TYPE_2D,
                    .format = format,
                    .subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT,
                    .subresourceRange.levelCount = 1,
                    .subresourceRange.layerCount = 1,
                };
                vulkan_if->set_image(vulkan_if->handle, &retro_vk_image, 0,
                                     NULL, VK_QUEUE_FAMILY_IGNORED);
                st_new_frames++;
                st_t = g_get_monotonic_time();
                video_cb(RETRO_HW_FRAME_BUFFER_VALID, last_w, last_h, 0);
            } else {
                /* nothing new drawn: the frontend repeats its last frame */
                st_t = g_get_monotonic_time();
                video_cb(NULL, last_w, last_h, 0);
            }
            st_t = g_get_monotonic_time() - st_t;
            st_video_sum += st_t;
            st_video_max = MAX(st_video_max, st_t);
            goto vk_audio;
        }

        static bool vk_display_initialized = false;

        if (!vk_display_initialized) {
            /* First frame: blocking sync to initialize display image */
            int tex = nv2a_get_framebuffer_surface();
            nv2a_release_framebuffer_surface();
            if (tex) {
                vk_display_initialized = true;
            }
        } else {
            /* Subsequent frames: trigger async render (non-blocking) */
            nv2a_trigger_display_render();
        }

        /* Get VK display info */
        void *ext_handle = NULL;
        int disp_w = 0, disp_h = 0;
        nv2a_get_vk_display_info(&ext_handle, &disp_w, &disp_h);

        if (ext_handle && disp_w > 0 && disp_h > 0) {
            /* Import xemu's display image into RA's VkDevice */
            static bool vk_layout_set = false;
            if (ra_vk_import_display(ext_handle, disp_w, disp_h)) {
                if (!vk_layout_set) {
                    ra_vk_transition_layout(ra_vk_image,
                        VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_GENERAL);
                    vk_layout_set = true;
                }
                ra_vk_transition_layout(ra_vk_image,
                    VK_IMAGE_LAYOUT_GENERAL, VK_IMAGE_LAYOUT_GENERAL);

                /* Set the image for RetroArch to display */
                retro_vk_image.image_view = ra_vk_image_view;
                retro_vk_image.image_layout = VK_IMAGE_LAYOUT_GENERAL;
                retro_vk_image.create_info = ra_vk_view_ci;

                vulkan_if->set_image(vulkan_if->handle, &retro_vk_image,
                                     0, NULL, VK_QUEUE_FAMILY_IGNORED);

                width = disp_w;
                height = disp_h;

                video_cb(RETRO_HW_FRAME_BUFFER_VALID, width, height, 0);
            } else {
                video_cb(NULL, width, height, 0);
            }
        } else {
            video_cb(NULL, width, height, 0);
        }
    }

vk_audio:
    /* Pull audio from the APU ring buffer, unless RetroArch's audio thread
     * does (audio_thread_callback) */
    if (audio_batch_cb && !audio_async) {
        extern int libretro_audio_pull(int16_t *out_buf, int max_frames);
        extern void libretro_audio_flush(void);

        /* One-time flush: discard stale boot audio on first active pull */
        static bool audio_flushed = false;
        if (!audio_flushed) {
            libretro_audio_flush();
            audio_flushed = true;
        }

        /* Exactly one frame's worth a call - 48000 / 59.94, 800 or 801 -
         * so RetroArch's audio sync paces retro_run, and with it the guest's
         * vblank, at the display's rate. Handing over whatever was queued
         * let a short queue send retro_run on early, 160 times a second
         * and more: the guest ran in bursts and stalls (a stuttering boot
         * animation). The APU waits once about 64 ms is queued (apu.c), so
         * nothing has to be dropped here; a short queue is filled up with
         * silence. */
        static double audio_frac = 0.0;
        audio_frac += 48000.0 / 59.94;
        int want = (int)audio_frac;
        audio_frac -= want;

        int16_t audio_buf[1602]; /* 801 stereo frames */
        int frames = libretro_audio_pull(audio_buf, want);
        if (frames < want) {
            memset(&audio_buf[frames * 2], 0,
                   (size_t)(want - frames) * 2 * sizeof(int16_t));
        }
        st_t = g_get_monotonic_time();
        audio_batch_cb(audio_buf, want);
        st_t = g_get_monotonic_time() - st_t;
        st_audio_sum += st_t;
        st_audio_max = MAX(st_audio_max, st_t);
    }
}

RETRO_API void retro_reset(void)
{
    LRLOG_INFO("[xemu] retro_reset\n");
    if (emu_initialized) {
        qemu_system_reset_request(SHUTDOWN_CAUSE_GUEST_RESET);
    }
}

/* ========================================================================= */
/* Save states via QEMU snapshot system                                      */
/* ========================================================================= */

/*
 * Save state header for RetroArch's .state file.
 * Actual VM state lives in the qcow2 HDD image via QEMU snapshots.
 */
#define LIBRETRO_SAVESTATE_SIZE  4096
#define LIBRETRO_SAVESTATE_MAGIC 0x58454D55 /* 'XEMU' */

struct libretro_savestate_header {
    uint32_t magic;
    uint32_t version;
    uint64_t timestamp;
};

static bool snapshot_dispatch(int request_type, int timeout_ms)
{
    if (!snapshot_sem_initialized) {
        qemu_sem_init(&snapshot_done_sem, 0);
        snapshot_sem_initialized = true;
    }
    /* A post from a request that timed out would end this wait at once */
    while (qemu_sem_timedwait(&snapshot_done_sem, 0) == 0) {
    }

    snapshot_done = false;
    snapshot_result = false;
    snapshot_request = request_type;

    /* Wait for the emu thread to process it */
    if (qemu_sem_timedwait(&snapshot_done_sem, timeout_ms) != 0) {
        LRLOG_INFO("[xemu] snapshot dispatch: timeout after %dms\n", timeout_ms);
        snapshot_request = SNAPSHOT_NONE;
        return false;
    }

    return snapshot_result;
}

RETRO_API size_t retro_serialize_size(void)
{
    if (!emu_initialized) return 0;
    return LIBRETRO_SAVESTATE_SIZE;
}

RETRO_API bool retro_serialize(void *data, size_t size)
{
    if (!emu_initialized || !data || size < LIBRETRO_SAVESTATE_SIZE)
        return false;

    memset(data, 0, LIBRETRO_SAVESTATE_SIZE);

    bool ok = snapshot_dispatch(SNAPSHOT_SAVE, 30000);

    if (!ok) {
        LRLOG_INFO("[xemu] retro_serialize: save failed\n");
        return false;
    }

    struct libretro_savestate_header *hdr = (struct libretro_savestate_header *)data;
    hdr->magic = LIBRETRO_SAVESTATE_MAGIC;
    hdr->version = 1;
    hdr->timestamp = (uint64_t)time(NULL);

    LRLOG_INFO("[xemu] retro_serialize: snapshot saved to HDD image\n");
    return true;
}

RETRO_API bool retro_unserialize(const void *data, size_t size)
{
    if (!emu_initialized || !data || size < LIBRETRO_SAVESTATE_SIZE)
        return false;

    const struct libretro_savestate_header *hdr =
        (const struct libretro_savestate_header *)data;
    if (hdr->magic != LIBRETRO_SAVESTATE_MAGIC) {
        LRLOG_INFO("[xemu] retro_unserialize: invalid magic 0x%08x\n", hdr->magic);
        return false;
    }

    bool ok = snapshot_dispatch(SNAPSHOT_LOAD, 30000);

    if (!ok) {
        LRLOG_INFO("[xemu] retro_unserialize: load failed\n");
        return false;
    }

    LRLOG_INFO("[xemu] retro_unserialize: snapshot loaded from HDD image\n");
    return true;
}

/* ========================================================================= */
/* Memory stubs                                                              */
/* ========================================================================= */

RETRO_API void  *retro_get_memory_data(unsigned id) { (void)id; return NULL; }
RETRO_API size_t retro_get_memory_size(unsigned id) { (void)id; return 0; }

/* ========================================================================= */
/* Misc                                                                      */
/* ========================================================================= */

RETRO_API unsigned retro_get_region(void) { return RETRO_REGION_NTSC; }
RETRO_API void retro_cheat_reset(void) {}
RETRO_API void retro_cheat_set(unsigned index, bool enabled, const char *code)
{
    (void)index; (void)enabled; (void)code;
}

RETRO_API void retro_set_controller_port_device(unsigned port, unsigned device)
{
    LRLOG_INFO("[xemu] Port %u device %u\n", port, device);
}
