/*
 * The Chihiro gun games' crosshairs, drawn over the picture handed to the
 * frontend: libretro-chihiro.c sets them each run from the aim, the Vulkan
 * renderer's frame copy (hw/xbox/nv2a/pgraph/vk/display.c) and the OpenGL
 * blit (ui/libretro.c) draw them. A position is 0..1 across the picture,
 * left to right and top to bottom.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef UI_LIBRETRO_CROSSHAIR_H
#define UI_LIBRETRO_CROSSHAIR_H

typedef struct XemuLibretroCrosshair {
    bool shown;
    float x, y;
} XemuLibretroCrosshair;

extern XemuLibretroCrosshair xemu_libretro_crosshairs[2];

#endif
