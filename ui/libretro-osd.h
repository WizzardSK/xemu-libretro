/*
 * Performance Overlay (NNshi): the game's frames per second (FPS) and the
 * rate its render time allows (GPU; the MSPF of standalone xemu's video
 * debug overlay), drawn in the top left
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

/* Standalone xemu's FPS (its video debug view): the game's flips per
 * second, in hundredths, over its last 60 flips (nv2a_profile_increment),
 * so 59.94 reads as such; the first line */
extern unsigned int xemu_libretro_osd_guest_fps100;

/* NV2A idle, in hundredths of a percent: the share of the time since the
 * overlay was turned on that the PFIFO thread waited for the guest to push
 * work (not for a flip's vblank or for reports); the third line */
extern unsigned int xemu_libretro_osd_idle100;

/* One guest frame's render time, in microseconds: from the flip of the frame
 * before to this frame's FLIP_STALL, where it starts to wait for the vblank */
void xemu_libretro_osd_frame(int64_t render_us);

/* One rectangle of the text, in pixels from the picture's top left corner:
 * white, or black for the outline */
typedef void (*XemuLibretroOsdRect)(void *ctx, int x, int y, int w, int h,
                                    bool white);

/* Digits, the point, the colon, the percent sign and the labels' letters
 * (A, D, E, F, G, I, L, N, P, S, U, V), 3x5 cells, a row's bits from the
 * left */
static inline const uint8_t *xemu_libretro_osd_glyph(char c)
{
    static const uint8_t colon[5] = { 0, 2, 0, 2, 0 };
    static const uint8_t letter_f[5] = { 7, 4, 6, 4, 4 };
    static const uint8_t letter_g[5] = { 7, 4, 5, 5, 7 };
    static const uint8_t letter_p[5] = { 7, 5, 7, 4, 4 };
    static const uint8_t letter_s[5] = { 7, 4, 7, 1, 7 };
    static const uint8_t letter_u[5] = { 5, 5, 5, 5, 7 };
    static const uint8_t letter_a[5] = { 7, 5, 7, 5, 5 };
    static const uint8_t letter_d[5] = { 6, 5, 5, 5, 6 };
    static const uint8_t letter_e[5] = { 7, 4, 6, 4, 7 };
    static const uint8_t letter_i[5] = { 7, 2, 2, 2, 7 };
    static const uint8_t letter_l[5] = { 4, 4, 4, 4, 7 };
    static const uint8_t letter_n[5] = { 5, 7, 7, 5, 5 };
    static const uint8_t letter_v[5] = { 5, 5, 5, 5, 2 };
    static const uint8_t percent[5] = { 5, 1, 2, 4, 5 };
    switch (c) {
    case ':': return colon;
    case '%': return percent;
    case 'A': return letter_a;
    case 'D': return letter_d;
    case 'E': return letter_e;
    case 'I': return letter_i;
    case 'L': return letter_l;
    case 'N': return letter_n;
    case 'V': return letter_v;
    case 'F': return letter_f;
    case 'G': return letter_g;
    case 'P': return letter_p;
    case 'S': return letter_s;
    case 'U': return letter_u;
    }
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
 * 200th of the picture's height, 2 to 10 pixels; the largest rectangle is a
 * row of three cells with its outline, 36x16 pixels. Three lines: FPS, the
 * game's flips per second, GPU, the rate from the render time, and NV2A
 * IDLE, the share of time the GPU thread waited for work. */
static inline void xemu_libretro_osd_draw(int height, int pass,
                                          XemuLibretroOsdRect rect, void *ctx)
{
    const unsigned int fps100 =
        __atomic_load_n(&xemu_libretro_osd_fps100, __ATOMIC_RELAXED);
    if (!fps100) {
        return;
    }
    const unsigned int guest100 =
        __atomic_load_n(&xemu_libretro_osd_guest_fps100, __ATOMIC_RELAXED);
    const unsigned int idle100 =
        __atomic_load_n(&xemu_libretro_osd_idle100, __ATOMIC_RELAXED);
    char buf[3][24];
    /* FPS: the game's flips per second (standalone xemu's FPS); GPU: the
     * rate its render time allows (standalone's MSPF) */
    snprintf(buf[0], sizeof(buf[0]), "FPS: %u.%02u", guest100 / 100,
             guest100 % 100);
    snprintf(buf[1], sizeof(buf[1]), "GPU: %u.%02u", fps100 / 100,
             fps100 % 100);
    snprintf(buf[2], sizeof(buf[2]), "NV2A IDLE: %u.%u%%", idle100 / 100,
             idle100 % 100 / 10);
    int s = height / 200;
    s = s < 2 ? 2 : (s > 10 ? 10 : s);
    const int o = s / 3 > 0 ? s / 3 : 1;
    for (int line = 0; line < 3; line++) {
    const char *text = buf[line];
    int x = 2 * s;
    const int y = 2 * s + line * 7 * s;
    for (; *text; text++) {
        const uint8_t *g = xemu_libretro_osd_glyph(*text);
        if (!g) {
            x += 2 * s; /* a space */
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
        x += (*text == '.' || *text == ':' ? 2 : 4) * s;
    }
    }
}

#endif
