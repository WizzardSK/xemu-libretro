/*
 * QEMU Geforce NV2A profiling helpers
 *
 * Copyright (c) 2020-2024 Matt Borgerson
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
#include "ui/libretro-osd.h"

NV2AStats g_nv2a_stats;

void nv2a_profile_increment(void)
{
    int64_t now = qemu_clock_get_us(QEMU_CLOCK_REALTIME);
    const int64_t fps_update_interval = 250000;
    g_nv2a_stats.last_flip_time = now;

    static int64_t frame_count = 0;
    frame_count++;

    /*
     * Performance Overlay's FPS, in hundredths: the span of the last 60
     * flips, so a 59.94 Hz game reads 59.94 rather than the whole-number
     * count of a quarter second (NNshi)
     */
    {
        static int64_t flips[60];
        static unsigned int n, head;
        flips[head] = now;
        head = (head + 1) % 60;
        if (n < 60) {
            n++;
        }
        if (n > 1) {
            int64_t oldest = flips[(head + 60 - n) % 60];
            if (now > oldest) {
                __atomic_store_n(&xemu_libretro_osd_guest_fps100,
                                 (unsigned int)((int64_t)(n - 1) * 100000000 /
                                                (now - oldest)),
                                 __ATOMIC_RELAXED);
            }
        }
    }

    static int64_t ts = 0;
    int64_t delta = now - ts;
    if (delta >= fps_update_interval) {
        g_nv2a_stats.increment_fps = frame_count * 1000000 / delta;
        ts = now;
        frame_count = 0;
    }
}

/* Displayed FPS: distinct guest frames that reached the screen, counted at
 * the UI present. Rolling span of the last 60 distinct presents, rounded
 * to nearest: a stretched present interval or a single dropped frame does
 * not flip the reading, a sustained drop reads exactly. A fixed window with
 * truncating division reads 56-59 at a true 60. */
void nv2a_profile_present(void)
{
    if (nv2a_stock_active()) {
        stock_nv2a_profile_present();
        return;
    }
    static unsigned int last_id = (unsigned int)-1;
    static int64_t ring[128];
    static unsigned ring_n, ring_w;
    int64_t now = qemu_clock_get_us(QEMU_CLOCK_REALTIME);

    unsigned int id = g_nv2a_stats.presented_frame_id;
    if (id != last_id) {
        last_id = id;
        ring[ring_w] = now;
        ring_w = (ring_w + 1) % ARRAY_SIZE(ring);
        if (ring_n < ARRAY_SIZE(ring)) {
            ring_n++;
        }
    }
    if (ring_n >= 2) {
        unsigned frames = MIN(ring_n - 1, 60u);
        int64_t newest = ring[(ring_w + ARRAY_SIZE(ring) - 1) % ARRAY_SIZE(ring)];
        int64_t oldest =
            ring[(ring_w + ARRAY_SIZE(ring) - 1 - frames) % ARRAY_SIZE(ring)];
        /* A stall (no distinct frame for a while) lowers the reading as it
         * lasts instead of freezing the last good value. */
        int64_t span = MAX(newest - oldest, now - oldest - 100000);
        if (span > 0) {
            g_nv2a_stats.display_fps =
                (unsigned int)((frames * 1000000LL + span / 2) / span);
        }
    }
}

extern uint64_t nv2a_profile_totals[NV2A_PROF__COUNT];

void nv2a_profile_flip_stall(void)
{
    int64_t now = qemu_clock_get_us(QEMU_CLOCK_REALTIME);
    int64_t render_time = (now-g_nv2a_stats.last_flip_time)/1000;

    xemu_libretro_osd_frame(now - g_nv2a_stats.last_flip_time);
    g_nv2a_stats.frame_working.mspf = render_time;
    g_nv2a_stats.frame_history[g_nv2a_stats.frame_ptr] =
        g_nv2a_stats.frame_working;
    g_nv2a_stats.frame_ptr =
        (g_nv2a_stats.frame_ptr + 1) % NV2A_PROF_NUM_FRAMES;
    g_nv2a_stats.frame_count++;
    for (int i = 0; i < NV2A_PROF__COUNT; i++) {
        nv2a_profile_totals[i] += g_nv2a_stats.frame_working.counters[i];
    }
    memset(&g_nv2a_stats.frame_working, 0, sizeof(g_nv2a_stats.frame_working));
}

/* The renderer's counters (host GPU syncs by reason, pipeline and shader
 * binds...) summed over the frames since the last reset, for the profile
 * the libretro core writes while its overlay is on */
uint64_t nv2a_profile_totals[NV2A_PROF__COUNT];

const char *nv2a_profile_get_counter_name(unsigned int cnt)
{
    if (nv2a_stock_active()) {
        return stock_nv2a_profile_get_counter_name(cnt);
    }
    const char *default_names[NV2A_PROF__COUNT] = {
        #define _X(x) stringify(x),
        NV2A_PROF_COUNTERS_XMAC
        #undef _X
    };

    assert(cnt < NV2A_PROF__COUNT);
    return default_names[cnt] + 10; /* 'NV2A_PROF_' */
}

int nv2a_profile_get_counter_value(unsigned int cnt)
{
    if (nv2a_stock_active()) {
        return stock_nv2a_profile_get_counter_value(cnt);
    }
    assert(cnt < NV2A_PROF__COUNT);
    unsigned int idx = (g_nv2a_stats.frame_ptr + NV2A_PROF_NUM_FRAMES - 1) %
                       NV2A_PROF_NUM_FRAMES;
    return g_nv2a_stats.frame_history[idx].counters[cnt];
}

/* nv2a_s2t_miss_note: the distinct texture/render-target mismatches since the
 * last reset. Only the miss path calls it, at most a few times a draw. */
typedef struct S2TMiss {
    int why;
    uint32_t tex_addr, tex_len;
    unsigned tex_fmt, tw, th, tpitch, levels;
    bool cube;
    uint32_t surf_addr;
    size_t surf_size;
    unsigned sfmt;
    bool color, swizzle;
    unsigned sw, sh, spitch, sbpp;
    uint64_t count;
} S2TMiss;
bool nv2a_prof_s2t_on, nv2a_prof_surf_on;
static S2TMiss s2t_miss[48];
static int s2t_miss_n;
static QemuMutex s2t_miss_lock;
static bool s2t_miss_lock_init;

static void s2t_miss_lock_once(void)
{
    if (!qatomic_read(&s2t_miss_lock_init)) {
        static gsize once;
        if (g_once_init_enter(&once)) {
            qemu_mutex_init(&s2t_miss_lock);
            qatomic_set(&s2t_miss_lock_init, true);
            g_once_init_leave(&once, 1);
        }
    }
}

void nv2a_s2t_miss_note(int why, uint32_t tex_addr, uint32_t tex_len,
                        unsigned tex_fmt, unsigned tw, unsigned th,
                        unsigned tpitch, unsigned levels, bool cube,
                        uint32_t surf_addr, size_t surf_size, unsigned sfmt,
                        bool color, bool swizzle, unsigned sw, unsigned sh,
                        unsigned spitch, unsigned sbpp)
{
    if (!qatomic_read(&nv2a_prof_s2t_on)) {
        return;
    }
    S2TMiss m = { why, tex_addr, tex_len, tex_fmt, tw, th, tpitch, levels,
                  cube, surf_addr, surf_size, sfmt, color, swizzle, sw, sh,
                  spitch, sbpp, 0 };
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    for (int i = 0; i < s2t_miss_n; i++) {
        S2TMiss *e = &s2t_miss[i];
        if (e->why == why && e->tex_addr == tex_addr && e->tex_len == tex_len &&
            e->tex_fmt == tex_fmt && e->tw == tw && e->th == th &&
            e->tpitch == tpitch && e->surf_addr == surf_addr &&
            e->sw == sw && e->sh == sh && e->sfmt == sfmt) {
            e->count++;
            qemu_mutex_unlock(&s2t_miss_lock);
            return;
        }
    }
    if (s2t_miss_n < (int)ARRAY_SIZE(s2t_miss)) {
        m.count = 1;
        s2t_miss[s2t_miss_n++] = m;
    }
    qemu_mutex_unlock(&s2t_miss_lock);
}

typedef struct SurfSite {
    int kind;
    const char *func;
    int line;
    uint32_t addr;
    unsigned w, h, fmt;
    bool color;
    uint64_t count;
} SurfSite;
static SurfSite surf_site[64];
static int surf_site_n;

void nv2a_surf_site_note(int kind, const char *func, int line, uint32_t addr,
                         unsigned w, unsigned h, unsigned fmt, bool color)
{
    if (!qatomic_read(&nv2a_prof_surf_on)) {
        return;
    }
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    for (int i = 0; i < surf_site_n; i++) {
        SurfSite *e = &surf_site[i];
        if (e->kind == kind && e->func == func && e->line == line &&
            e->addr == addr && e->w == w && e->h == h && e->fmt == fmt) {
            e->count++;
            qemu_mutex_unlock(&s2t_miss_lock);
            return;
        }
    }
    if (surf_site_n < (int)ARRAY_SIZE(surf_site)) {
        surf_site[surf_site_n++] = (SurfSite){ kind, func, line, addr, w, h,
                                              fmt, color, 1 };
    }
    qemu_mutex_unlock(&s2t_miss_lock);
}

typedef struct SurfCpu {
    uint32_t addr;
    unsigned w, h;
    bool color, write, dirty;
    uint64_t pc, count;
} SurfCpu;
static SurfCpu surf_cpu[48];
static int surf_cpu_n;

void nv2a_surf_cpu_note(uint32_t addr, unsigned w, unsigned h, bool color,
                        bool write, bool dirty, uint64_t pc)
{
    if (!qatomic_read(&nv2a_prof_surf_on)) {
        return;
    }
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    for (int i = 0; i < surf_cpu_n; i++) {
        SurfCpu *e = &surf_cpu[i];
        if (e->addr == addr && e->w == w && e->h == h && e->write == write &&
            e->dirty == dirty && e->pc == pc) {
            e->count++;
            qemu_mutex_unlock(&s2t_miss_lock);
            return;
        }
    }
    if (surf_cpu_n < (int)ARRAY_SIZE(surf_cpu)) {
        surf_cpu[surf_cpu_n++] = (SurfCpu){ addr, w, h, color, write, dirty,
                                            pc, 1 };
    }
    qemu_mutex_unlock(&s2t_miss_lock);
}

typedef struct Surf1x {
    uint32_t addr;
    unsigned w, h;
    bool color;
    uint64_t count;
} Surf1x;
static Surf1x surf_1x[64];
static int surf_1x_n;

void nv2a_surf_1x_note(uint32_t addr, unsigned w, unsigned h, bool color)
{
    if (!qatomic_read(&nv2a_prof_surf_on)) {
        return;
    }
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    for (int i = 0; i < surf_1x_n; i++) {
        Surf1x *e = &surf_1x[i];
        if (e->addr == addr && e->w == w && e->h == h && e->color == color) {
            e->count++;
            qemu_mutex_unlock(&s2t_miss_lock);
            return;
        }
    }
    if (surf_1x_n < (int)ARRAY_SIZE(surf_1x)) {
        surf_1x[surf_1x_n++] = (Surf1x){ addr, w, h, color, 1 };
    }
    qemu_mutex_unlock(&s2t_miss_lock);
}

typedef struct SurfEvict {
    const char *why;
    uint32_t addr, naddr;
    unsigned w, h, pitch, cfmt, zfmt, aa, nw, nh, npitch, ncfmt, nzfmt, naa;
    unsigned cw, ch;
    bool color, ncolor;
    uint64_t count;
} SurfEvict;
static SurfEvict surf_evict[32];
static int surf_evict_n;

void nv2a_surf_evict_note(const char *why, uint32_t addr, unsigned w,
                          unsigned h, unsigned pitch, unsigned cfmt,
                          unsigned zfmt, bool color, unsigned aa,
                          uint32_t naddr, unsigned nw, unsigned nh,
                          unsigned npitch, unsigned ncfmt, unsigned nzfmt,
                          bool ncolor, unsigned naa, unsigned cw, unsigned ch)
{
    if (!qatomic_read(&nv2a_prof_surf_on)) {
        return;
    }
    SurfEvict n = { why, addr, naddr, w, h, pitch, cfmt, zfmt, aa, nw, nh,
                    npitch, ncfmt, nzfmt, naa, cw, ch, color, ncolor, 1 };
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    for (int i = 0; i < surf_evict_n; i++) {
        SurfEvict *e = &surf_evict[i];
        if (e->why == why && e->addr == addr && e->naddr == naddr &&
            e->w == w && e->h == h && e->nw == nw && e->nh == nh &&
            e->pitch == pitch && e->npitch == npitch && e->color == color &&
            e->ncolor == ncolor && e->zfmt == zfmt && e->nzfmt == nzfmt &&
            e->cfmt == cfmt && e->ncfmt == ncfmt && e->aa == aa &&
            e->naa == naa && e->cw == cw && e->ch == ch) {
            e->count++;
            qemu_mutex_unlock(&s2t_miss_lock);
            return;
        }
    }
    if (surf_evict_n < (int)ARRAY_SIZE(surf_evict)) {
        surf_evict[surf_evict_n++] = n;
    }
    qemu_mutex_unlock(&s2t_miss_lock);
}

void nv2a_s2t_miss_reset(void)
{
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    s2t_miss_n = 0;
    surf_site_n = 0;
    surf_evict_n = 0;
    surf_cpu_n = 0;
    surf_1x_n = 0;
    qemu_mutex_unlock(&s2t_miss_lock);
}

void nv2a_s2t_miss_dump(FILE *f)
{
    static const char *const whys[] = {
        "same address, shape or format differs",
        "inside a render target, not at its start",
        "overlaps a render target",
    };
    s2t_miss_lock_once();
    qemu_mutex_lock(&s2t_miss_lock);
    /* An enabled list with no entries says so, so that "none" and "off"
     * read differently in the file */
    if (qatomic_read(&nv2a_prof_s2t_on) && !s2t_miss_n) {
        fprintf(f, "# textures on render-target memory not taken from it: "
                   "none\n");
    }
    if (s2t_miss_n) {
        fprintf(f, "# textures on render-target memory not taken from it "
                   "(count over the run; tex/surf: address+length, format, "
                   "width x height, pitch)\n");
    }
    for (int i = 0; i < s2t_miss_n; i++) {
        S2TMiss *e = &s2t_miss[i];
        fprintf(f, "s2t-miss %" PRIu64 " %s: tex %08x+%x fmt %02x %ux%u "
                   "pitch %u levels %u%s | surf %08x+%zx fmt %02x %s%s "
                   "%ux%u pitch %u bpp %u\n",
                e->count, whys[e->why], e->tex_addr, e->tex_len, e->tex_fmt,
                e->tw, e->th, e->tpitch, e->levels, e->cube ? " cube" : "",
                e->surf_addr, e->surf_size, e->sfmt,
                e->color ? "color" : "zeta", e->swizzle ? " swizzled" : "",
                e->sw, e->sh, e->spitch, e->sbpp);
    }
    if (qatomic_read(&nv2a_prof_surf_on) && !surf_site_n) {
        fprintf(f, "# surface downloads and uploads: none\n");
    }
    if (qatomic_read(&nv2a_prof_surf_on) && !surf_evict_n) {
        fprintf(f, "# render targets evicted: none\n");
    }
    if (qatomic_read(&nv2a_prof_surf_on)) {
        fprintf(f, "# render targets drawn at 1x by the Upscaling Threshold "
                   "(count of creations over the run; address, size, "
                   "color/zeta)%s\n", surf_1x_n ? "" : ": none");
        for (int i = 0; i < surf_1x_n; i++) {
            Surf1x *e = &surf_1x[i];
            fprintf(f, "surf-1x %" PRIu64 " %08x %ux%u %s\n", e->count,
                    e->addr, e->w, e->h, e->color ? "color" : "zeta");
        }
    }
    if (qatomic_read(&nv2a_prof_surf_on) && !surf_cpu_n) {
        fprintf(f, "# CPU access to render-target memory: none\n");
    }
    if (surf_cpu_n) {
        fprintf(f, "# CPU access to render-target memory (count over the "
                   "run; target address and size, read/write, whether the "
                   "GPU had drawn it since RAM was last current, guest code "
                   "address, 0 = DMA)\n");
    }
    for (int i = 0; i < surf_cpu_n; i++) {
        SurfCpu *e = &surf_cpu[i];
        fprintf(f, "surf-cpu %" PRIu64 " %s: surf %08x %ux%u %s%s pc %08"
                   PRIx64 "\n",
                e->count, e->write ? "write" : "read", e->addr, e->w, e->h,
                e->color ? "color" : "zeta", e->dirty ? " gpu-drawn" : "",
                e->pc);
    }
    if (surf_site_n) {
        fprintf(f, "# surface downloads (GPU to RAM) and uploads (RAM to "
                   "GPU) by the renderer code that asked for them (count "
                   "over the run; surface address, size, format)\n");
    }
    for (int i = 0; i < surf_site_n; i++) {
        SurfSite *e = &surf_site[i];
        fprintf(f, "surf-%s %" PRIu64 " %s:%d surf %08x %ux%u fmt %02x %s\n",
                e->kind ? "upload" : "download", e->count,
                e->func ? e->func : "?", e->line, e->addr, e->w, e->h, e->fmt,
                e->color ? "color" : "zeta");
    }
    if (surf_evict_n) {
        fprintf(f, "# render targets evicted (each a download if dirty and a "
                   "new target): why, the evicted one, the target that "
                   "evicted it (address size pitch color/zeta format AA)\n");
    }
    for (int i = 0; i < surf_evict_n; i++) {
        SurfEvict *e = &surf_evict[i];
        fprintf(f, "surf-evict %" PRIu64 " %s: %08x %ux%u pitch %u %s %02x "
                   "aa %u -> %08x %ux%u pitch %u %s %02x aa %u",
                e->count, e->why, e->addr, e->w, e->h, e->pitch,
                e->color ? "color" : "zeta", e->color ? e->cfmt : e->zfmt,
                e->aa, e->naddr, e->nw, e->nh, e->npitch,
                e->ncolor ? "color" : "zeta", e->ncolor ? e->ncfmt : e->nzfmt,
                e->naa);
        if (e->cw) {
            fprintf(f, " (color bound %ux%u)", e->cw, e->ch);
        }
        fputc('\n', f);
    }
    qemu_mutex_unlock(&s2t_miss_lock);
}
