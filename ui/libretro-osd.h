/*
 * Internal Framerate (NNshi): two readings in the top left corner of the
 * picture handed to the frontend.
 *
 * GPU: the guest's frame rate from its render time, the MSPF of standalone
 * xemu's video debug overlay: hw/xbox/nv2a/pgraph/profile.c hands each
 * frame's time from the flip before to its FLIP_STALL to
 * xemu_libretro_osd_frame. It sees the frame's GPU commands only, and a game
 * that does not wait at FLIP_STALL gives it nothing ("-").
 *
 * CPU: how much of the time the guest CPU was busy, from the time the vCPU
 * spent halted waiting for an interrupt (system/cpus.c, accel/tcg), over the
 * last 60 runs. It covers what the game does on the CPU, whatever it waits on.
 *
 * ui/libretro.c keeps the readings; the Vulkan frame copy
 * (hw/xbox/nv2a/pgraph/vk/display.c) and the OpenGL blit (ui/libretro.c)
 * draw them with xemu_libretro_osd_draw.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef UI_LIBRETRO_OSD_H
#define UI_LIBRETRO_OSD_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* Whether the readings are shown (the option), and the readings: the GPU one
 * in hundredths of a frame per second (0 for none yet), the CPU one in
 * percent plus one (0 for none yet). Written by the nv2a thread and
 * retro_run, read where the frame is handed over. */
extern int xemu_libretro_osd_shown;
extern unsigned int xemu_libretro_osd_fps100;
extern unsigned int xemu_libretro_osd_cpu1;

/* One guest frame's render time, in microseconds: from the flip of the frame
 * before to this frame's FLIP_STALL, where it starts to wait for the vblank */
void xemu_libretro_osd_frame(int64_t render_us);

/* One rectangle of the text, in pixels from the picture's top left corner:
 * white, or black for the outline */
typedef void (*XemuLibretroOsdRect)(void *ctx, int x, int y, int w, int h,
                                    bool white);

/* 3x5 cells, a row's bits from the left */
static inline const uint8_t *xemu_libretro_osd_glyph(char c)
{
    static const uint8_t digits[10][5] = {
        { 7, 5, 5, 5, 7 }, { 2, 6, 2, 2, 7 }, { 7, 1, 7, 4, 7 },
        { 7, 1, 7, 1, 7 }, { 5, 5, 7, 1, 1 }, { 7, 4, 7, 1, 7 },
        { 7, 4, 7, 5, 7 }, { 7, 1, 1, 1, 1 }, { 7, 5, 7, 5, 7 },
        { 7, 5, 7, 1, 7 },
    };
    static const uint8_t point[5] = { 0, 0, 0, 0, 4 };
    static const uint8_t g[5] = { 7, 4, 5, 5, 7 }, p[5] = { 7, 5, 7, 4, 4 },
                         u[5] = { 5, 5, 5, 5, 7 }, cc[5] = { 7, 4, 4, 4, 7 },
                         pct[5] = { 5, 1, 2, 4, 5 }, dash[5] = { 0, 0, 7, 0, 0 },
                         space[5] = { 0, 0, 0, 0, 0 };
    if (c >= '0' && c <= '9') {
        return digits[c - '0'];
    }
    switch (c) {
    case '.': return point;
    case 'G': return g;
    case 'P': return p;
    case 'U': return u;
    case 'C': return cc;
    case '%': return pct;
    case '-': return dash;
    case ' ': return space;
    }
    return NULL;
}

/* The text's rectangles for one pass: 0 is the black outline, 1 the white
 * cells over it (the caller orders the second after the first). A cell is a
 * 200th of the picture's height, 2 to 10 pixels; the largest rectangle is a
 * row of three cells with its outline, 36x16 pixels. */
static inline void xemu_libretro_osd_draw(int height, int pass,
                                          XemuLibretroOsdRect rect, void *ctx)
{
    if (!__atomic_load_n(&xemu_libretro_osd_shown, __ATOMIC_RELAXED)) {
        return;
    }
    const unsigned int fps100 =
        __atomic_load_n(&xemu_libretro_osd_fps100, __ATOMIC_RELAXED);
    const unsigned int cpu1 =
        __atomic_load_n(&xemu_libretro_osd_cpu1, __ATOMIC_RELAXED);
    char lines[2][24];
    if (fps100) {
        snprintf(lines[0], sizeof(lines[0]), "GPU %u.%02u", fps100 / 100,
                 fps100 % 100);
    } else {
        snprintf(lines[0], sizeof(lines[0]), "GPU -");
    }
    if (cpu1) {
        snprintf(lines[1], sizeof(lines[1]), "CPU %u%%", cpu1 - 1);
    } else {
        snprintf(lines[1], sizeof(lines[1]), "CPU -");
    }
    int s = height / 200;
    s = s < 2 ? 2 : (s > 10 ? 10 : s);
    const int o = s / 3 > 0 ? s / 3 : 1;
    for (int line = 0; line < 2; line++) {
        int x = 2 * s;
        const int y = 2 * s + line * 7 * s;
        for (const char *text = lines[line]; *text; text++) {
            const uint8_t *g = xemu_libretro_osd_glyph(*text);
            if (!g) {
                continue;
            }
            for (int row = 0; row < 5; row++) {
                /* each run of set cells in the row as one rectangle */
                for (int col = 0; col < 3;) {
                    if (!(g[row] & (4 >> col))) {
                        col++;
                        continue;
                    }
                    int end = col;
                    while (end < 3 && (g[row] & (4 >> end))) {
                        end++;
                    }
                    const int rx = x + col * s, ry = y + row * s;
                    const int rw = (end - col) * s;
                    if (pass == 0) {
                        rect(ctx, rx - o, ry - o, rw + 2 * o, s + 2 * o, false);
                    } else {
                        rect(ctx, rx, ry, rw, s, true);
                    }
                    col = end;
                }
            }
            x += (*text == '.' ? 2 : 4) * s;
        }
    }
}

#endif
