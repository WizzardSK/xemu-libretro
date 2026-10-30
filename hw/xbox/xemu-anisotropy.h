/*
 * The libretro core's Anisotropic Filtering option, for both GPUs (hw/xbox/nv2a
 * and hw/xbox/nv2a-stock): the least anisotropy a texture the game filters
 * linearly is sampled with (NNshi, xemu-project/xemu#409). Most Xbox games
 * ask for none.
 */
#ifndef HW_XBOX_XEMU_ANISOTROPY_H
#define HW_XBOX_XEMU_ANISOTROPY_H

#include <stdint.h>

/* 1 for the game's own; set by ui/libretro.c, read as textures are bound */
extern unsigned int xemu_min_anisotropy;

/* The anisotropy for a texture: texfilter is its NV_PGRAPH_TEXFILTER0
 * register, game the anisotropy the game set (its TEXCTL0) */
static inline uint32_t xemu_texture_anisotropy(uint32_t texfilter, uint32_t game)
{
    /* NV_PGRAPH_TEXFILTER0_MIN: the tent (linear) filters, not the box
     * (point) ones, which stay as sharp as the game made them */
    const uint32_t min = (texfilter >> 16) & 0x3f;
    const int linear = min == 2 || min == 4 || min == 6 || min == 7;
    const unsigned int least = *(volatile unsigned int *)&xemu_min_anisotropy;
    return linear && least > game ? least : game;
}

#endif
