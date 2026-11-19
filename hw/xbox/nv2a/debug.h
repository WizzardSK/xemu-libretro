/*
 * QEMU Geforce NV2A profiling and debug helpers
 *
 * Copyright (c) 2012 espes
 * Copyright (c) 2015 Jannik Vogel
 * Copyright (c) 2018-2025 Matt Borgerson
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

#ifndef HW_XBOX_NV2A_DEBUG_H
#define HW_XBOX_NV2A_DEBUG_H

#include <stdint.h>

#define NV2A_XPRINTF(x, ...) do { \
    if (x) { \
        fprintf(stderr, "nv2a: " __VA_ARGS__); \
    } \
} while (0)

#ifndef DEBUG_NV2A
# define DEBUG_NV2A 0
#endif

#if DEBUG_NV2A
# define NV2A_DPRINTF(format, ...)       printf("nv2a: " format, ## __VA_ARGS__)
#else
# define NV2A_DPRINTF(format, ...)       do { } while (0)
#endif

/* Debug prints to identify when unimplemented or unconfirmed features
 * are being exercised. These cases likely result in graphical problems of
 * varying degree, but should otherwise not crash the system. Enable this
 * macro for debugging.
 */
#ifndef DEBUG_NV2A_FEATURES
# define DEBUG_NV2A_FEATURES 0
#endif

#if DEBUG_NV2A_FEATURES

/* Feature which has not yet been confirmed */
#define NV2A_UNCONFIRMED(format, ...) do { \
    fprintf(stderr, "nv2a: Warning unconfirmed feature: " format "\n", ## __VA_ARGS__); \
} while (0)

/* Feature which is not implemented */
#define NV2A_UNIMPLEMENTED(format, ...) do { \
    fprintf(stderr, "nv2a: Warning unimplemented feature: " format "\n", ## __VA_ARGS__); \
} while (0)

#else

#define NV2A_UNCONFIRMED(...) do {} while (0)
#define NV2A_UNIMPLEMENTED(...) do {} while (0)

#endif

#define NV2A_PROF_COUNTERS_XMAC \
    _X(NV2A_PROF_FINISH_VERTEX_BUFFER_DIRTY) \
    _X(NV2A_PROF_FINISH_SURFACE_CREATE) \
    _X(NV2A_PROF_FINISH_SURFACE_DOWN) \
    _X(NV2A_PROF_FINISH_NEED_BUFFER_SPACE) \
    _X(NV2A_PROF_FINISH_FRAMEBUFFER_DIRTY) \
    _X(NV2A_PROF_FINISH_PRESENTING) \
    _X(NV2A_PROF_FINISH_FLIP_STALL) \
    _X(NV2A_PROF_FINISH_FLUSH) \
    _X(NV2A_PROF_FINISH_STALLED) \
    _X(NV2A_PROF_FINISH_SURFACE_UP) \
    _X(NV2A_PROF_FINISH_TEXTURE_UP) \
    _X(NV2A_PROF_FINISH_EAGER) \
    _X(NV2A_PROF_CLEAR) \
    _X(NV2A_PROF_QUEUE_SUBMIT) \
    _X(NV2A_PROF_QUEUE_SUBMIT_AUX) \
    _X(NV2A_PROF_PIPELINE_NOTDIRTY) \
    _X(NV2A_PROF_PIPELINE_GEN) \
    _X(NV2A_PROF_PIPELINE_BIND) \
    _X(NV2A_PROF_VERTEX_INPUT_SET) \
    _X(NV2A_PROF_PIPELINE_RENDERPASSES) \
    _X(NV2A_PROF_BEGIN_ENDS) \
    _X(NV2A_PROF_DRAW_ARRAYS) \
    _X(NV2A_PROF_INLINE_BUFFERS) \
    _X(NV2A_PROF_INLINE_ARRAYS) \
    _X(NV2A_PROF_INLINE_ELEMENTS) \
    _X(NV2A_PROF_QUERY) \
    _X(NV2A_PROF_SHADER_GEN) \
    _X(NV2A_PROF_SHADER_FALLBACK) \
    _X(NV2A_PROF_UNIFORM_UP) \
    _X(NV2A_PROF_SHADER_BIND) \
    _X(NV2A_PROF_SHADER_BIND_NOTDIRTY) \
    _X(NV2A_PROF_SHADER_UBO_DIRTY) \
    _X(NV2A_PROF_SHADER_UBO_NOTDIRTY) \
    _X(NV2A_PROF_ATTR_BIND) \
    _X(NV2A_PROF_TEX_UPLOAD) \
    _X(NV2A_PROF_GEOM_BUFFER_UPDATE_1) \
    _X(NV2A_PROF_GEOM_BUFFER_UPDATE_2) \
    _X(NV2A_PROF_GEOM_BUFFER_UPDATE_3) \
    _X(NV2A_PROF_GEOM_BUFFER_UPDATE_4) \
    _X(NV2A_PROF_GEOM_BUFFER_UPDATE_4_NOTDIRTY) \
    _X(NV2A_PROF_SURF_SWIZZLE) \
    _X(NV2A_PROF_SURF_CREATE) \
    _X(NV2A_PROF_SURF_DOWNLOAD) \
    _X(NV2A_PROF_SURF_UPLOAD) \
    _X(NV2A_PROF_SURF_TO_TEX) \
    _X(NV2A_PROF_SURF_TO_TEX_FALLBACK) \
    _X(NV2A_PROF_QUEUE_SUBMIT_1) \
    _X(NV2A_PROF_QUEUE_SUBMIT_2) \
    _X(NV2A_PROF_QUEUE_SUBMIT_3) \
    _X(NV2A_PROF_QUEUE_SUBMIT_4) \
    _X(NV2A_PROF_QUEUE_SUBMIT_5) \

enum NV2A_PROF_COUNTERS_ENUM {
    #define _X(x) x,
    NV2A_PROF_COUNTERS_XMAC
    #undef _X
    NV2A_PROF__COUNT
};

#define NV2A_PROF_NUM_FRAMES 300

typedef struct NV2AStats {
    int64_t last_flip_time;
    unsigned int frame_count;
    unsigned int increment_fps;
    /* Displayed frame rate: distinct guest frames that reached the screen
     * per second, counted at the UI present (nv2a_profile_present) -- the
     * same on a 60 Hz or a 320 Hz monitor, vsync on or off. increment_fps
     * counts NV097_FLIP submissions and overreads under GPU load. */
    unsigned int display_fps;
    /* Identity of the frame the renderer handed to the UI (draw_time). */
    unsigned int presented_frame_id;
    struct {
        int mspf;
        int counters[NV2A_PROF__COUNT];
    } frame_working, frame_history[NV2A_PROF_NUM_FRAMES];
    unsigned int frame_ptr;
} NV2AStats;

#ifdef __cplusplus
extern "C" {
#endif

extern NV2AStats g_nv2a_stats;

const char *nv2a_profile_get_counter_name(unsigned int cnt);
/* Textures that sit on render-target memory but are not taken from the render
 * target (a texture/surface mismatch): each distinct case with its count, for
 * the profile file */
void nv2a_s2t_miss_note(int why, uint32_t tex_addr, uint32_t tex_len,
                        unsigned tex_fmt, unsigned tw, unsigned th,
                        unsigned tpitch, unsigned levels, bool cube,
                        uint32_t surf_addr, size_t surf_size, unsigned sfmt,
                        bool color, bool swizzle, unsigned sw, unsigned sh,
                        unsigned spitch, unsigned sbpp);
void nv2a_s2t_miss_reset(void);
/* Debug > Profiler: Missed Render Targets / Surface Downloads and Uploads:
 * whether the two lists are kept (off, the notes return at once) */
extern bool nv2a_prof_s2t_on, nv2a_prof_surf_on;
/* With the surface list on: why a render target was evicted (its shape
 * against the target that evicted it; cw/ch the bound color target's size
 * for a zeta that does not cover it) */
void nv2a_surf_evict_note(const char *why, uint32_t addr, unsigned w,
                          unsigned h, unsigned pitch, unsigned cfmt,
                          unsigned zfmt, bool color, unsigned aa,
                          uint32_t naddr, unsigned nw, unsigned nh,
                          unsigned npitch, unsigned ncfmt, unsigned nzfmt,
                          bool ncolor, unsigned naa, unsigned cw, unsigned ch);
/* surface downloads (kind 0) and uploads (1) by the renderer function and
 * line that asked for them, with the surface */
void nv2a_surf_site_note(int kind, const char *func, int line, uint32_t addr,
                         unsigned w, unsigned h, unsigned fmt, bool color);
/* With the surface list on: the CPU (or a DMA from the main loop, pc 0)
 * touching a render target's memory, by target, read/write and guest code
 * address (the start of the translated block, so near the access) */
void nv2a_surf_cpu_note(uint32_t addr, unsigned w, unsigned h, bool color,
                        bool write, bool dirty, uint64_t pc);
void nv2a_s2t_miss_dump(FILE *f);
int nv2a_profile_get_counter_value(unsigned int cnt);
void nv2a_profile_increment(void);
void nv2a_profile_flip_stall(void);

static inline void nv2a_profile_inc_counter(enum NV2A_PROF_COUNTERS_ENUM cnt)
{
    g_nv2a_stats.frame_working.counters[cnt] += 1;
}

#ifdef CONFIG_RENDERDOC
void nv2a_dbg_renderdoc_init(void);
void *nv2a_dbg_renderdoc_get_api(void);
bool nv2a_dbg_renderdoc_available(void);
void nv2a_dbg_renderdoc_capture_frames(int num_frames, bool trace);
extern int renderdoc_capture_frames;
extern bool renderdoc_trace_frames;
#endif

#ifdef __cplusplus
}
#endif

#endif
