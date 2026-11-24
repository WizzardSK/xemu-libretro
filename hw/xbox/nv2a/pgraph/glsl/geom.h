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
    /* Half-Pixel Offset: 1 "Per Triangle", the primitive is shifted only
     * when all its vertices are on a half pixel; 2 "Native Edges, 2D", a flat
     * filled primitive is grown by half a native pixel (the pixel shader
     * keeps the fine pixels of native pixels whose centre is inside). Takes the high byte of the old
     * short tri_rot0 (always 0), so the key keeps its size and old seeds
     * read as off. */
    uint8_t half_pixel;
    short tri_rot1;
} GeomState;

typedef struct GenGeomGlslOptions {
    bool vulkan;
    bool locations;
} GenGeomGlslOptions;

void pgraph_glsl_set_geom_state(PGRAPHState *pg, GeomState *geom);
/* Half-Pixel Offset "Per Triangle" (3) and "Per Triangle, Quads / Render
 * Targets" (4): whether this draw may be moved at all */
bool pgraph_glsl_half_pixel_draw(PGRAPHState *pg, int mode);
/* GeomState.half_pixel for the pending draw: in mode 4 it changes from draw
 * to draw without any register changing (shaders.c checks it) */
int pgraph_glsl_geom_half_pixel(PGRAPHState *pg);

bool pgraph_glsl_need_geom(const GeomState *state);

MString *pgraph_glsl_gen_geom(const GeomState *state, GenGeomGlslOptions opts);

#endif
