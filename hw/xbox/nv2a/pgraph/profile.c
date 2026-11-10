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
    memset(&g_nv2a_stats.frame_working, 0, sizeof(g_nv2a_stats.frame_working));
}

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
