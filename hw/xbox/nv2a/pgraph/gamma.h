/*
 * The DAC's lookup table (NV_USER_DAC_PALETTE), applied to the picture as the
 * DAC does: a gamma ramp per channel after scanout and the video overlay.
 * After parallel-xbox a0ee82d8.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef HW_XBOX_NV2A_PGRAPH_GAMMA_H
#define HW_XBOX_NV2A_PGRAPH_GAMMA_H

#include <stdbool.h>
#include <stdint.h>

typedef struct PGRAPHGamma {
    /* One word per DAC input: red | green << 8 | blue << 16; on the GPU 64
     * uvec4s */
    uint32_t ramp[256];
    /* Not the identity, which leaves the picture as it is */
    bool enabled;
} PGRAPHGamma;

/* The ramp from the guest's palette (256 RGB triplets). The CPU thread may
 * be writing it meanwhile; a ramp caught half written is shown for a frame
 * and replaced by the next one. */
static inline void pgraph_gamma_read(PGRAPHGamma *g, const uint8_t *palette)
{
    g->enabled = false;
    for (unsigned i = 0; i < 256; i++) {
        const uint8_t *p = &palette[i * 3];
        g->ramp[i] = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                     ((uint32_t)p[2] << 16);
        g->enabled |= g->ramp[i] != (i | (i << 8) | (i << 16));
    }
}

/* Applied after scanout decoding and the video overlay; alpha untouched.
 * Needs uvec4 gamma_lut[64] declared before it. */
#define PGRAPH_GAMMA_GLSL \
    "vec3 apply_gamma(vec3 color) {\n" \
    "    uvec3 i = uvec3(clamp(color, 0.0, 1.0) * 255.0 + 0.5);\n" \
    "    uint r = gamma_lut[i.r >> 2u][i.r & 3u];\n" \
    "    uint g = gamma_lut[i.g >> 2u][i.g & 3u];\n" \
    "    uint b = gamma_lut[i.b >> 2u][i.b & 3u];\n" \
    "    return vec3(float(r & 255u), float((g >> 8u) & 255u),\n" \
    "                float((b >> 16u) & 255u)) / 255.0;\n" \
    "}\n"

#endif
