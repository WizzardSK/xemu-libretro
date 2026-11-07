/*
 * Internal Framerate (NNshi): the guest's frame rate from its render time
 * (the MSPF of standalone xemu's video debug overlay), drawn in the top left
 * corner of the picture handed to the frontend. hw/xbox/nv2a/pgraph/profile.c
 * hands each frame's render time to xemu_libretro_osd_frame, ui/libretro.c
 * keeps the rate, and the Vulkan frame copy (hw/xbox/nv2a/pgraph/vk/display.c)
 * and the OpenGL blit (ui/libretro.c) draw it with xemu_libretro_osd_draw.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef UI_LIBRETRO_OSD_H
#define UI_LIBRETRO_OSD_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* The rate shown, in hundredths of a frame per second: the average render
 * time of the last 60 guest frames, taken every 20 frames; 0 (nothing shown)
 * when the option is off. Written by the nv2a thread, read where the frame is
 * handed over. */
extern unsigned int xemu_libretro_osd_fps100;

/* One guest frame's render time, in microseconds: from the flip of the frame
 * before to this frame's FLIP_STALL, where it starts to wait for the vblank */
void xemu_libretro_osd_frame(int64_t render_us);

/* One rectangle of the text, in pixels from the picture's top left corner:
 * white, or black for the outline */
typedef void (*XemuLibretroOsdRect)(void *ctx, int x, int y, int w, int h,
                                    bool white);

/* Digits and the point, 3x5 cells, a row's bits from the left */
static inline const uint8_t *xemu_libretro_osd_glyph(char c)
{
    static const uint8_t digits[10][5] = {
        { 7, 5, 5, 5, 7 }, { 2, 6, 2, 2, 7 }, { 7, 1, 7, 4, 7 },
        { 7, 1, 7, 1, 7 }, { 5, 5, 7, 1, 1 }, { 7, 4, 7, 1, 7 },
        { 7, 4, 7, 5, 7 }, { 7, 1, 1, 1, 1 }, { 7, 5, 7, 5, 7 },
        { 7, 5, 7, 1, 7 },
    };
    static const uint8_t point[5] = { 0, 0, 0, 0, 4 };
    if (c >= '0' && c <= '9') {
        return digits[c - '0'];
    }
    return c == '.' ? point : NULL;
}

/* The text's rectangles for one pass: 0 is the black outline, 1 the white
 * cells over it (the caller orders the second after the first). A cell is a
 * 160th of the picture's height, 2 to 12 pixels; the largest rectangle is a
 * row of three cells with its outline, 44x20 pixels. */
static inline void xemu_libretro_osd_draw(int height, int pass,
                                          XemuLibretroOsdRect rect, void *ctx)
{
    const unsigned int fps100 =
        __atomic_load_n(&xemu_libretro_osd_fps100, __ATOMIC_RELAXED);
    if (!fps100) {
        return;
    }
    char buf[16];
    snprintf(buf, sizeof(buf), "%u.%02u", fps100 / 100, fps100 % 100);
    const char *text = buf;
    int s = height / 160;
    s = s < 2 ? 2 : (s > 12 ? 12 : s);
    const int o = s / 3 > 0 ? s / 3 : 1;
    int x = 2 * s;
    const int y = 2 * s;
    for (; *text; text++) {
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

#endif
