/*
 * Geforce NV2A PGRAPH GLSL Shader Generator
 *
 * Copyright (c) 2015 espes
 * Copyright (c) 2015 Jannik Vogel
 * Copyright (c) 2020-2025 Matt Borgerson
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

#ifndef HW_XBOX_NV2A_PGRAPH_GLSL_GEOM_H
#define HW_XBOX_NV2A_PGRAPH_GLSL_GEOM_H

#include "common.h"
#include "hw/xbox/nv2a/pgraph/vsh_regs.h"

typedef struct {
    enum ShaderPrimitiveMode primitive_mode;
    enum ShaderPolygonMode polygon_front_mode;
    enum ShaderPolygonMode polygon_back_mode;
    bool smooth_shading;
    bool first_vertex_is_provoking;
    bool z_perspective;
    /* OpenGL only: the host cannot rasterize lines this wide, so the
     * geometry shader draws each segment as a rectangle. Lives in the
     * padding byte: the key keeps its size and every recorded seed. */
    bool wide_lines;
    int8_t tri_rot0;
    /* Half-Pixel Offset for this draw (GEOM_HP_*), 0 off: the HPO options
     * resolved for the draw's texture 0 (its rotation check and, for "Kept
     * When Linear", its filter). Takes the high byte of the old short
     * tri_rot0 (always 0), so the key keeps its size and old seeds read as
     * off. */
    uint8_t half_pixel;
    short tri_rot1;
} GeomState;

/* xemu_libretro_half_pixel: the HPO options as ui/libretro.c packs them,
 * 0 off */
#define HPO_SET_STRATEGY(s) ((s) & 7)   /* HPO_TRIANGLE ... HPO_NATIVE */
#define HPO_SET_FLAT(s)     (((s) >> 3) & 1)
#define HPO_SET_AXIS(s)     (((s) >> 4) & 3) /* 0 both, 1 either, 2 touched */
#define HPO_SET_ROT(s)      (((s) >> 6) & 3) /* 0 off, 1 on, 2 only 90 */
#define HPO_SET_CONTENT(s)  (((s) >> 8) & 3) /* 0 moved, 1 kept, 2 linear */
enum { HPO_TRIANGLE = 1, HPO_AXIS = 2, HPO_VERTEX = 3, HPO_NATIVE = 4 };

/* GeomState.half_pixel: bits 0-1 the strategy that moves corners
 * (HPO_TRIANGLE, HPO_AXIS, HPO_VERTEX), bit 2 flat check, bits 3-4 axis
 * (Per Axis only), bits 5-6 rotation check, bit 7 content kept. Native
 * Edges, which moves nothing, is GEOM_HP_NATIVE alone. */
#define GEOM_HP_STRATEGY(b) ((b) & 3)
#define GEOM_HP_FLAT        0x04
#define GEOM_HP_AXIS(b)     (((b) >> 3) & 3)
#define GEOM_HP_ROT(b)      (((b) >> 5) & 3)
#define GEOM_HP_KEEP        0x80
#define GEOM_HP_NATIVE      0x80

typedef struct GenGeomGlslOptions {
    bool vulkan;
    bool locations;
} GenGeomGlslOptions;

void pgraph_glsl_set_geom_state(PGRAPHState *pg, GeomState *geom);
/* GeomState.half_pixel for the pending draw: it changes with texture 0
 * (rotation check, filter) without the geometry registers changing
 * (shaders.c checks it) */
int pgraph_glsl_geom_half_pixel(PGRAPHState *pg);

bool pgraph_glsl_need_geom(const GeomState *state);

MString *pgraph_glsl_gen_geom(const GeomState *state, GenGeomGlslOptions opts);

#endif
