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

#include "qemu/osdep.h"
#include "hw/xbox/nv2a/pgraph/pgraph.h"
#include "geom.h"

/* wide_lines took the padding byte: the shader state size, and with it the
 * seed files and dictionary, must not move. */
QEMU_BUILD_BUG_ON(sizeof(GeomState) != 20);

#ifdef LIBRETRO
/* Half-Pixel Offset (ui/libretro.c) */
extern int xemu_libretro_half_pixel;
#else
static int xemu_libretro_half_pixel;
#endif

/* The vertices the pending draw sends, whichever way it sends them */
static unsigned int draw_vertices(PGRAPHState *pg)
{
    if (pg->draw_arrays_length) {
        unsigned int n = 0;
        for (unsigned int i = 0; i < pg->draw_arrays_length; i++) {
            n += pg->draw_arrays_count[i];
        }
        return n;
    }
    if (pg->inline_elements_length) {
        return pg->inline_elements_length;
    }
    if (pg->inline_buffer_length) {
        return pg->inline_buffer_length;
    }
    if (pg->inline_array_length) {
        unsigned int size = 0;
        for (int i = 0; i < NV2A_VERTEXSHADER_ATTRIBUTES; i++) {
            if (pg->vertex_attributes[i].count) {
                size += pgraph_inline_attr_size(&pg->vertex_attributes[i]);
            }
        }
        return size ? pg->inline_array_length * 4 / size : 0;
    }
    return 0;
}

/* Mode 4 narrows mode 3 to the draws NNshi's captures showed needing it: a
 * single quad (at most 4 vertices: a full-screen pass, DW3's menu strips,
 * JSRF's shadow pass) or a draw reading an upscaled surface (WMMT2's car).
 * A batch of quads from normal textures is a sprite list the game already
 * put on the pixel grid (JSRF's HUD, its spray-can count): moving it moved
 * it away from where it is at 1x. */
bool pgraph_glsl_half_pixel_draw(PGRAPHState *pg, int mode)
{
    if (mode == 3 || (mode >= 6 && mode <= 15)) {
        return true;
    }
    if (mode != 4) {
        return false;
    }
    if (pg->half_pixel_reads_scaled) {
        return true;
    }
    unsigned int n = draw_vertices(pg);
    return n > 0 && n <= 4;
}

int pgraph_glsl_geom_half_pixel(PGRAPHState *pg)
{
    int mode = qatomic_read(&xemu_libretro_half_pixel);
    if (pg->surface_scale_factor <= 1) {
        return 0;
    }
    if (mode == 5) {
        return 2;   /* "Native Edges, 2D", see pgraph_glsl_gen_geom */
    }
    if (mode == 6) {
        return 3;   /* "Per Triangle, Content Kept", see pgraph_glsl_gen_geom */
    }
    if (mode == 7) {
        return 4;   /* "Per Axis, Content Kept", see pgraph_glsl_gen_geom */
    }
    if (mode == 8) {
        return 5;   /* "Per Axis, Flat, Content Kept", see pgraph_glsl_gen_geom */
    }
    if (mode == 9) {
        return 6;   /* "Per Axis, Flat, Either Axis", see pgraph_glsl_gen_geom */
    }
    if (mode == 10) {
        return 7;   /* "Per Axis, Flat, Either Axis, Unrotated", see pgraph_glsl_gen_geom */
    }
    if (mode == 11) {
        return 8;   /* "Per Axis, Flat, Rects", see pgraph_glsl_gen_geom */
    }
    if (mode == 12) {
        return 9;   /* "Per Axis, Flat, Rects, Touched Axis", see pgraph_glsl_gen_geom */
    }
    if (mode == 13) {
        /* "Per Axis, Flat, Touched Axis, Unrotated": 11 when texture 0 is
         * read (the rotation test needs real texture coordinates), 10
         * when not, see pgraph_glsl_gen_geom */
        return pgraph_is_texture_enabled(pg, 0) ? 11 : 10;
    }
    if (mode == 14) {
        /* "Per Axis, Flat, Touched Axis, Unrotated 90": 13 with texture 0,
         * 12 without */
        return pgraph_is_texture_enabled(pg, 0) ? 13 : 12;
    }
    if (mode == 15) {
        /* "Per Axis, Flat, Touched Axis, Unrotated 90, Whole Pixels Stay":
         * 15 with texture 0, 14 without */
        return pgraph_is_texture_enabled(pg, 0) ? 15 : 14;
    }
    return pgraph_glsl_half_pixel_draw(pg, mode) ? 1 : 0;
}

void pgraph_glsl_set_geom_state(PGRAPHState *pg, GeomState *state)
{
    state->primitive_mode = (enum ShaderPrimitiveMode)pg->primitive_mode;

    state->half_pixel = pgraph_glsl_geom_half_pixel(pg);

    state->polygon_front_mode = (enum ShaderPolygonMode)GET_MASK(
        pgraph_reg_r(pg, NV_PGRAPH_SETUPRASTER),
        NV_PGRAPH_SETUPRASTER_FRONTFACEMODE);
    state->polygon_back_mode = (enum ShaderPolygonMode)GET_MASK(
        pgraph_reg_r(pg, NV_PGRAPH_SETUPRASTER),
        NV_PGRAPH_SETUPRASTER_BACKFACEMODE);

    state->smooth_shading = GET_MASK(pgraph_reg_r(pg, NV_PGRAPH_CONTROL_3),
                                     NV_PGRAPH_CONTROL_3_SHADEMODE) ==
                            NV_PGRAPH_CONTROL_3_SHADEMODE_SMOOTH;

    state->first_vertex_is_provoking =
        GET_MASK(pgraph_reg_r(pg, NV_PGRAPH_CONTROL_3),
                 NV_PGRAPH_CONTROL_3_PROVOKING_VERTEX) ==
        NV_PGRAPH_CONTROL_3_PROVOKING_VERTEX_FIRST;

    state->z_perspective = pgraph_reg_r(pg, NV_PGRAPH_CONTROL_0) &
                           NV_PGRAPH_CONTROL_0_Z_PERSPECTIVE_ENABLE;

    if (pg->renderer->ops.get_gpu_properties) {
        GPUProperties *gpu_props = pg->renderer->ops.get_gpu_properties();

        switch (state->primitive_mode) {
        case PRIM_TYPE_TRIANGLES:
            state->tri_rot0 = gpu_props->geom_shader_winding.tri;
            state->tri_rot1 = state->tri_rot0;
            break;
        case PRIM_TYPE_TRIANGLE_STRIP:
            state->tri_rot0 = gpu_props->geom_shader_winding.tri_strip0;
            state->tri_rot1 = gpu_props->geom_shader_winding.tri_strip1;
            break;
        case PRIM_TYPE_TRIANGLE_FAN:
        case PRIM_TYPE_POLYGON:
            state->tri_rot0 = gpu_props->geom_shader_winding.tri_fan;
            state->tri_rot1 = state->tri_rot0;
            break;
        default:
            break;
        }
    }
}

static const char *get_vertex_order(int rot)
{
    if (rot == 0) {
        return "ivec3(0, 1, 2)";
    } else if (rot == 1) {
        return "ivec3(2, 0, 1)";
    } else {
        return "ivec3(1, 2, 0)";
    }
}

/* "Native Edges, 2D": every filled triangle of the body goes through
 * emit_tri instead of three emit_vertex calls */
static char *native_edges_body(const char *body)
{
    MString *out = mstring_new();
    const char *p = body;
    while (*p) {
        char a[16], b[16], c[16], pz[16], pzb[16], pzc[16];
        int n = 0;
        if (sscanf(p, "  emit_vertex(%15[^,], %15[^)]);\n"
                      "  emit_vertex(%15[^,], %15[^)]);\n"
                      "  emit_vertex(%15[^,], %15[^)]);\n"
                      "  EndPrimitive();\n%n",
                   a, pz, b, pzb, c, pzc, &n) == 6 && n > 0 &&
            !strcmp(pz, pzb) && !strcmp(pz, pzc)) {
            mstring_append_fmt(out, "  emit_tri(%s, %s, %s, %s);\n", a, b, c, pz);
            p += n;
            continue;
        }
        const char *nl = strchr(p, '\n');
        size_t len = nl ? (size_t)(nl - p + 1) : strlen(p);
        char line[256];
        snprintf(line, sizeof(line), "%.*s", (int)MIN(len, sizeof(line) - 1), p);
        mstring_append(out, line);
        p += len;
    }
    char *res = g_strdup(mstring_get_str(out));
    mstring_unref(out);
    return res;
}

bool pgraph_glsl_need_geom(const GeomState *state)
{
    /* FIXME: Missing support for 2-sided-poly mode */
    assert(state->polygon_front_mode == state->polygon_back_mode);
    enum ShaderPolygonMode polygon_mode = state->polygon_front_mode;

    switch (state->primitive_mode) {
    case PRIM_TYPE_POINTS:
        return false;
    case PRIM_TYPE_LINES:
    case PRIM_TYPE_LINE_LOOP:
    case PRIM_TYPE_LINE_STRIP:
    case PRIM_TYPE_TRIANGLES:
    case PRIM_TYPE_TRIANGLE_STRIP:
    case PRIM_TYPE_TRIANGLE_FAN:
    case PRIM_TYPE_QUADS:
    case PRIM_TYPE_QUAD_STRIP:
        return true;
    case PRIM_TYPE_POLYGON:
        if (polygon_mode == POLY_MODE_POINT) {
            assert(!"POLY_MODE_POINT not supported");
            return false;
        }
        return true;
    default:
        return false;
    }
}

MString *pgraph_glsl_gen_geom(const GeomState *state, GenGeomGlslOptions opts)
{
    /* FIXME: Missing support for 2-sided-poly mode */
    assert(state->polygon_front_mode == state->polygon_back_mode);
    enum ShaderPolygonMode polygon_mode = state->polygon_front_mode;

    bool need_triz = false;
    bool need_quadz = false;
    bool need_linez = false;
    bool need_wide = false;
    const char *layout_in = NULL;
    const char *layout_out = NULL;
    const char *body = NULL;
    const char *provoking_index = "0";
    int num_in = 0;

    /* TODO: frontface/backface culling for polygon modes POLY_MODE_LINE and
     * POLY_MODE_POINT.
     */
    switch (state->primitive_mode) {
    case PRIM_TYPE_POINTS: return NULL;
    case PRIM_TYPE_LINES:
    case PRIM_TYPE_LINE_LOOP:
    case PRIM_TYPE_LINE_STRIP:
        provoking_index = state->first_vertex_is_provoking ? "0" : "1";
        need_linez = true;
        layout_in = "layout(lines) in;\n";
        num_in = 2;
        if (state->wide_lines) {
            need_wide = true;
            layout_out = "layout(triangle_strip, max_vertices = 4) out;\n";
            body = "  emit_wide_line(0, 1, 0.0);\n";
        } else {
            layout_out = "layout(line_strip, max_vertices = 2) out;\n";
            body = "  emit_line(0, 1, 0.0);\n";
        }
        break;
    case PRIM_TYPE_TRIANGLES:
    case PRIM_TYPE_TRIANGLE_STRIP:
    case PRIM_TYPE_TRIANGLE_FAN:
        if (state->first_vertex_is_provoking) {
            provoking_index = "v[0]";
        } else if (state->primitive_mode == PRIM_TYPE_TRIANGLE_STRIP) {
            provoking_index = "v[2 - (gl_PrimitiveIDIn & 1)]";
        } else if (state->primitive_mode == PRIM_TYPE_TRIANGLE_FAN) {
            provoking_index = "v[1]";
        } else {
            provoking_index = "v[2]";
        }
        need_triz = true;
        layout_in = "layout(triangles) in;\n";
        num_in = 3;
        if (polygon_mode == POLY_MODE_FILL) {
            layout_out = "layout(triangle_strip, max_vertices = 3) out;\n";
            body = "  mat4 pz = calc_triz(v[0], v[1], v[2]);\n"
                   "  emit_vertex(v[0], pz);\n"
                   "  emit_vertex(v[1], pz);\n"
                   "  emit_vertex(v[2], pz);\n"
                   "  EndPrimitive();\n";
        } else if (polygon_mode == POLY_MODE_LINE) {
            need_linez = true;
            layout_out = "layout(line_strip, max_vertices = 6) out;\n";
            body = "  float dz = calc_triz(v[0], v[1], v[2])[3].x;\n"
                   "  emit_line(v[0], v[1], dz);\n"
                   "  emit_line(v[1], v[2], dz);\n"
                   "  emit_line(v[2], v[0], dz);\n";
        } else {
            assert(polygon_mode == POLY_MODE_POINT);
            layout_out = "layout(points, max_vertices = 3) out;\n";
            body = "  mat4 pz = calc_triz(v[0], v[1], v[2]);\n"
                   "  emit_vertex(v[0], mat4(pz[0], pz[0], pz[0], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(v[1], mat4(pz[1], pz[1], pz[1], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(v[2], mat4(pz[2], pz[2], pz[2], pz[3]));\n"
                   "  EndPrimitive();\n";
        }
        break;
    case PRIM_TYPE_QUADS:
        provoking_index = "3";
        need_quadz = true;
        layout_in = "layout(lines_adjacency) in;\n";
        num_in = 4;
        if (polygon_mode == POLY_MODE_FILL) {
            layout_out = "layout(triangle_strip, max_vertices = 6) out;\n";
            body = "  mat4 pz, pz2;\n"
                   "  calc_quadz(0, 1, 2, 3, pz, pz2);\n"
                   "  emit_vertex(1, pz);\n"
                   "  emit_vertex(2, pz);\n"
                   "  emit_vertex(0, pz);\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(2, pz2);\n"
                   "  emit_vertex(3, pz2);\n"
                   "  emit_vertex(0, pz2);\n"
                   "  EndPrimitive();\n";
        } else if (polygon_mode == POLY_MODE_LINE) {
            need_linez = true;
            layout_out = "layout(line_strip, max_vertices = 8) out;\n";
            body = "  mat4 pz, pzs;\n"
                   "  calc_quadz(0, 1, 2, 3, pz, pzs);\n"
                   "  emit_line(0, 1, pz[3].x);\n"
                   "  emit_line(1, 2, pz[3].x);\n"
                   "  emit_line(2, 3, pzs[3].x);\n"
                   "  emit_line(3, 0, pzs[3].x);\n";
        } else {
            assert(polygon_mode == POLY_MODE_POINT);
            layout_out = "layout(points, max_vertices = 4) out;\n";
            body = "  mat4 pz, pz2;\n"
                   "  calc_quadz(0, 1, 2, 3, pz, pz2);\n"
                   "  emit_vertex(0, mat4(pz[0], pz[0], pz[0], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(1, mat4(pz[1], pz[1], pz[1], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(2, mat4(pz[2], pz[2], pz[2], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(3, mat4(pz2[2], pz2[2], pz2[2], pz2[3]));\n"
                   "  EndPrimitive();\n";
        }
        break;
    case PRIM_TYPE_QUAD_STRIP:
        provoking_index = "3";
        need_quadz = true;
        layout_in = "layout(lines_adjacency) in;\n";
        num_in = 4;
        if (polygon_mode == POLY_MODE_FILL) {
            layout_out = "layout(triangle_strip, max_vertices = 6) out;\n";
            body = "  if ((gl_PrimitiveIDIn & 1) != 0) { return; }\n"
                   "  mat4 pz, pz2;\n"
                   "  calc_quadz(2, 0, 1, 3, pz, pz2);\n"
                   "  emit_vertex(0, pz);\n"
                   "  emit_vertex(1, pz);\n"
                   "  emit_vertex(2, pz);\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(2, pz2);\n"
                   "  emit_vertex(1, pz2);\n"
                   "  emit_vertex(3, pz2);\n"
                   "  EndPrimitive();\n";
        } else if (polygon_mode == POLY_MODE_LINE) {
            need_linez = true;
            layout_out = "layout(line_strip, max_vertices = 8) out;\n";
            body = "  if ((gl_PrimitiveIDIn & 1) != 0) { return; }\n"
                   "  mat4 pz, pzs;\n"
                   "  calc_quadz(2, 0, 1, 3, pz, pzs);\n"
                   "  emit_line(0, 1, pz[3].x);\n"
                   "  emit_line(1, 3, pzs[3].x);\n"
                   "  emit_line(3, 2, pzs[3].x);\n"
                   "  emit_line(2, 0, pz[3].x);\n";
        } else {
            assert(polygon_mode == POLY_MODE_POINT);
            layout_out = "layout(points, max_vertices = 4) out;\n";
            body = "  if ((gl_PrimitiveIDIn & 1) != 0) { return; }\n"
                   "  mat4 pz, pz2;\n"
                   "  calc_quadz(2, 0, 1, 3, pz, pz2);\n"
                   "  emit_vertex(0, mat4(pz[1], pz[1], pz[1], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(1, mat4(pz[2], pz[2], pz[2], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(2, mat4(pz[0], pz[0], pz[0], pz[3]));\n"
                   "  EndPrimitive();\n"
                   "  emit_vertex(3, mat4(pz2[2], pz2[2], pz2[2], pz2[3]));\n"
                   "  EndPrimitive();\n";
        }
        break;
    case PRIM_TYPE_POLYGON:
        if (polygon_mode == POLY_MODE_FILL) {
            provoking_index = "v[2]";
            need_triz = true;
            layout_in = "layout(triangles) in;\n";
            num_in = 3;
            layout_out = "layout(triangle_strip, max_vertices = 3) out;\n";
            body = "  mat4 pz = calc_triz(v[0], v[1], v[2]);\n"
                   "  emit_vertex(v[0], pz);\n"
                   "  emit_vertex(v[1], pz);\n"
                   "  emit_vertex(v[2], pz);\n"
                   "  EndPrimitive();\n";
        } else if (polygon_mode == POLY_MODE_LINE) {
            provoking_index = "0";
            need_linez = true;
            /* FIXME: input here is lines and not triangles so we cannot
             * calculate triangle plane slope. Also, the first vertex of the
             * polygon is unavailable so flat shading provoking vertex is
             * wrong.
             */
            layout_in = "layout(lines) in;\n";
            num_in = 2;
            layout_out = "layout(line_strip, max_vertices = 2) out;\n";
            body = "  emit_line(0, 1, 0.0);\n";
        } else {
            assert(!"Invalid polygon mode for PRIM_TYPE_POLYGON");
            return NULL;
        }
        break;

    default:
        assert(!"Invalid primitive mode");
        return NULL;
    }

    /* generate a geometry shader to support deprecated primitive types */
    assert(layout_in);
    assert(layout_out);
    assert(body);
    MString *output =
        mstring_from_fmt("#version %d\n\n"
                         "%s"
                         "%s"
                         "%s"
                         "\n"
                         "#define v_vtxPos %s\n"
                         "\n",
                         opts.vulkan ? 450 : (opts.locations ? 410 : 400),
                         opts.vulkan ? "" :
                             "in gl_PerVertex {\n"
                             "  vec4 gl_Position;\n"
                             "  float gl_PointSize;\n"
                             "} gl_in[];\n"
                             "out gl_PerVertex {\n"
                             "  vec4 gl_Position;\n"
                             "  float gl_PointSize;\n"
                             "};\n\n",
                         layout_in, layout_out,
                         (state->half_pixel == 1 || state->half_pixel >= 3) ?
                             "gsPos" : "v_vtxPos0");
    pgraph_glsl_get_vtx_header(output, opts.vulkan || opts.locations,
                               state->smooth_shading, true, true, true);
    pgraph_glsl_get_vtx_header(output, opts.vulkan || opts.locations,
                               state->smooth_shading, false, false, false);

    /* Half-Pixel Offset "Per Triangle": the vertex shader leaves the
     * positions unshifted and passes the shift in vtxPos1 (xy: clip space per
     * unit of w, zw: native pixels; the geometry shader rewrites vtxPos1
     * anyway). Shifted only when every vertex of the primitive has x and y
     * on n.5: a screen-aligned quad has all its corners there, a moving 3D
     * triangle almost never all three at once (NNshi). */
    /* "Per Triangle, Content Kept" (half_pixel 3) moves the primitive the
     * same way, and gives each moved vertex the texture coordinates, colours
     * and fog the primitive had at its new place: only the edges move, every
     * pixel inside reads what it read unmoved. Moving the content too pulled
     * textured UI half a 1x pixel up and left of where 1x draws it (JSRF's
     * HUD), while an untextured bar has only edges to move (JSRF's
     * letterbox). The values come from the plane through the first three
     * vertices, in screen space, without perspective: exact for a flat 2D
     * primitive (one w), which is what the rule catches; a line has no plane
     * and moves whole. */
    /* "Per Axis, Content Kept" (half_pixel 4): as 3, but each axis on its
     * own - a primitive whose corners all have y on n.5 is moved in y, one
     * whose corners all have x on n.5 in x. Panzer Dragoon Orta's splash
     * has its top and bottom on y n.5 and its sides elsewhere (the panels
     * scroll sideways): "Per Triangle" left it, and above its top edge a
     * strip of what lay under it showed, a white line (NNshi). */
    /* "Per Axis, Flat, Content Kept" (half_pixel 5): as 4, but only for a
     * flat primitive, all three corners at one w (2D, UI, full-screen
     * passes, Orta's splash). A 3D triangle with its corners on one pixel
     * row or column - shadow volumes along a building's straight edge -
     * moved in that axis while its neighbour didn't, and the crack between
     * them showed as lines in JSRF's shadows and flashes in other games
     * (NNshi). */
    /* "Per Axis, Flat, Either Axis" (half_pixel 6): as 5, but a flat
     * primitive with all corners on n.5 in one axis is moved in both. GTA
     * San Andreas' health bar has its x edges on n.5 and its y edges not
     * (bottom at 88.625): 5 moved it in x only, so it sat half a 1x pixel low
     * against 1x, and one red part with all y on n.5 moved up out of the
     * outline (NNshi). With HPO off the whole bar is half a 1x pixel right and
     * down, so the game expects the offset in both axes. */
    /* "Per Axis, Flat, Either Axis, Unrotated" (half_pixel 7): as 6, but
     * not for a triangle whose texture is mapped rotated (u changing along
     * y or v along x). GTA San Andreas' minimap is the map texture rotated
     * onto slivers of a circle; a sliver whose corners happened to have x
     * on n.5 moved half a 1x pixel left while the circle's mask didn't, and
     * the map showed as a line beside the circle. "Per Triangle" left it,
     * as it needs both axes (NNshi). UI, bars and full-screen passes map
     * their textures straight; untextured ones have nothing to rotate. */
    /* "Per Axis, Flat, Rects" (half_pixel 8): as 5, but only for a
     * triangle that is half of an axis-aligned rectangle (two corners
     * share x, two share y). The rotation test of 7 read texture
     * coordinates that untextured draws carry as leftovers, and moved
     * JSRF's letterbox and DW3's dialog boxes off again (NNshi). Bars, UI,
     * letterboxes and full-screen passes are rectangles; the slivers of
     * GTA San Andreas' rotating minimap are not. */
    /* "Per Axis, Flat, Rects, Touched Axis" (half_pixel 9): as 8, and an
     * axis whose corners are all on n.5 also moves the other axis if at
     * least one corner is on n.5 there: GTA San Andreas' health bar (x all
     * n.5, y top 86.5, bottom 88.625). "Either Axis" moved the other axis
     * with no n.5 corner in it at all, and shifted JSRF's grey bar, the
     * Breakdown menu and KOTOR's text (NNshi). */
    /* "Per Axis, Flat, Touched Axis, Unrotated" (half_pixel 10, and 11
     * for a draw that reads texture 0): as 5 with the touched axis of 9,
     * and with 7's rotation test, only for a draw that reads texture 0.
     * GTA San Andreas' minimap is drawn as axis-aligned strips with the
     * map rotated on them, so 8's rectangle test let them through
     * (NNshi); 7's rotation test caught them but also read the leftover
     * texture coordinates of untextured draws (JSRF's letterbox, DW3's
     * dialog boxes). */
    /* "Per Axis, Flat, Touched Axis, Unrotated 90" (half_pixel 12, and 13
     * with texture 0): as 10/11, but a texture turned by a quarter (u along
     * y, v along x) counts as straight: KOTOR's name entry outlines map
     * their corner texture that way and 11 left them unmoved (NNshi); the
     * minimap's map is turned by any angle, u and v both change along x. */
    /* "..., Whole Pixels Stay" (half_pixel 14, and 15 with texture 0): as
     * 12/13, and the touched axis moves only if none of its corners is on a
     * whole pixel. JSRF's grey bar has one x edge on n.5 and the other on a
     * whole pixel; Touched Axis moved it in x and it came out short of 1x
     * (NNshi). GTA San Andreas' health bar has its y edges at 86.5 and
     * 88.625 and still moves. */
    const bool per_axis = state->half_pixel >= 4 && state->half_pixel <= 15;
    const bool per_axis_flat = state->half_pixel >= 5 && state->half_pixel <= 15;
    const bool either_axis = state->half_pixel == 6 || state->half_pixel == 7;
    const bool quarter_ok = state->half_pixel >= 12 && state->half_pixel <= 15;
    const bool unrotated = state->half_pixel == 7 || state->half_pixel == 11 ||
                           state->half_pixel == 13 || state->half_pixel == 15;
    const bool rects = state->half_pixel == 8 || state->half_pixel == 9;
    const bool whole_stay = state->half_pixel == 14 || state->half_pixel == 15;
    const bool touched = state->half_pixel >= 9 && state->half_pixel <= 15;
    const bool hp_keep = (state->half_pixel == 3 || per_axis) && num_in >= 3;
    const char *pos_pre = "gl_in[", *pos_post = "].gl_Position";
    char hp_body[48] = "";
    if (state->half_pixel == 1 || state->half_pixel >= 3) {
        pos_pre = "gsClip[";
        pos_post = "]";
        if (per_axis) {
            /* flat: every corner at the first one's w; either axis: one
             * axis on n.5 moves both; unrotated: dT0/dx has no v and
             * dT0/dy no u (the plane through the three corners) */
            const char *rot_test =
                "  if (any(hit)) {\n"
                "    vec2 e1 = v_vtxPos0[1].xy - v_vtxPos0[0].xy;\n"
                "    vec2 e2 = v_vtxPos0[2].xy - v_vtxPos0[0].xy;\n"
                "    vec2 f1 = v_vtxT0[1].xy - v_vtxT0[0].xy;\n"
                "    vec2 f2 = v_vtxT0[2].xy - v_vtxT0[0].xy;\n"
                "    float det = e1.x * e2.y - e1.y * e2.x;\n"
                "    if (abs(det) > 1e-6) {\n"
                "      vec2 tx = (f1 * e2.y - f2 * e1.y) / det;\n"
                "      vec2 ty = (f2 * e1.x - f1 * e2.x) / det;\n"
                "      float m = 1e-3 * max(abs(tx.x), abs(ty.y));\n"
                "      if (abs(tx.y) > m || abs(ty.x) > m) {\n"
                "        hit = bvec2(false);\n"
                "      }\n"
                "    }\n"
                "  }\n";
            /* the same, but a quarter turn (only u along y, v along x) is
             * straight too */
            const char *rot90_test =
                "  if (any(hit)) {\n"
                "    vec2 e1 = v_vtxPos0[1].xy - v_vtxPos0[0].xy;\n"
                "    vec2 e2 = v_vtxPos0[2].xy - v_vtxPos0[0].xy;\n"
                "    vec2 f1 = v_vtxT0[1].xy - v_vtxT0[0].xy;\n"
                "    vec2 f2 = v_vtxT0[2].xy - v_vtxT0[0].xy;\n"
                "    float det = e1.x * e2.y - e1.y * e2.x;\n"
                "    if (abs(det) > 1e-6) {\n"
                "      vec2 tx = (f1 * e2.y - f2 * e1.y) / det;\n"
                "      vec2 ty = (f2 * e1.x - f1 * e2.x) / det;\n"
                "      float m = 1e-3 * max(max(abs(tx.x), abs(ty.y)),\n"
                "                           max(abs(tx.y), abs(ty.x)));\n"
                "      bool straight = abs(tx.y) <= m && abs(ty.x) <= m;\n"
                "      bool quarter = abs(tx.x) <= m && abs(ty.y) <= m;\n"
                "      if (!straight && !quarter) {\n"
                "        hit = bvec2(false);\n"
                "      }\n"
                "    }\n"
                "  }\n";
            /* touched: the other axis too, with one corner on n.5 there;
             * rects: two corners share x and two share y */
            char touch_test[1024], rect_test[512], whole_test[256];
            snprintf(whole_test, sizeof(whole_test),
                "    for (int i = 0; i < %d; i++) {\n"
                "      touch = bvec2(touch.x && fract(v_vtxPos0[i].x) != 0.0,\n"
                "                    touch.y && fract(v_vtxPos0[i].y) != 0.0);\n"
                "    }\n", num_in);
            snprintf(touch_test, sizeof(touch_test),
                "  {\n"
                "    bvec2 touch = bvec2(false);\n"
                "    for (int i = 0; i < %d; i++) {\n"
                "      touch = bvec2(touch.x || fract(v_vtxPos0[i].x) == 0.5,\n"
                "                    touch.y || fract(v_vtxPos0[i].y) == 0.5);\n"
                "    }\n"
                "%s"
                "    hit = bvec2(hit.x || (hit.y && touch.x),\n"
                "                hit.y || (hit.x && touch.y));\n"
                "  }\n", num_in,
                whole_stay ? whole_test : "");
            snprintf(rect_test, sizeof(rect_test),
                "  if (any(hit)) {\n"
                "    bool sx = false, sy = false;\n"
                "    for (int i = 0; i < %d; i++) {\n"
                "      for (int j = i + 1; j < %d; j++) {\n"
                "        sx = sx || v_vtxPos0[i].x == v_vtxPos0[j].x;\n"
                "        sy = sy || v_vtxPos0[i].y == v_vtxPos0[j].y;\n"
                "      }\n"
                "    }\n"
                "    if (!(sx && sy)) {\n"
                "      hit = bvec2(false);\n"
                "    }\n"
                "  }\n", num_in, num_in);
            char flat_test[2048];
            snprintf(flat_test, sizeof(flat_test),
                     "  for (int i = 1; i < %d; i++) {\n"
                     "    if (v_vtxPos0[i].w != v_vtxPos0[0].w) {\n"
                     "      hit = bvec2(false);\n"
                     "    }\n"
                     "  }\n%s%s%s%s", num_in,
                     unrotated && num_in >= 3 ? (quarter_ok ? rot90_test : rot_test) : "",
                     either_axis ? "  hit = bvec2(any(hit));\n" : "",
                     touched ? touch_test : "",
                     rects && num_in >= 3 ? rect_test : "");
            mstring_append_fmt(output,
                "vec4 gsPos[%d];\n"
                "vec4 gsClip[%d];\n"
                "void hp_init() {\n"
                "  bvec2 hit = bvec2(true);\n"
                "  for (int i = 0; i < %d; i++) {\n"
                "    hit = bvec2(hit.x && fract(v_vtxPos0[i].x) == 0.5,\n"
                "                hit.y && fract(v_vtxPos0[i].y) == 0.5);\n"
                "  }\n"
                "%s"
                "  vec2 hm = vec2(hit);\n"
                "  for (int i = 0; i < %d; i++) {\n"
                "    gsPos[i] = v_vtxPos0[i];\n"
                "    gsClip[i] = gl_in[i].gl_Position;\n"
                "    gsPos[i].xy -= v_vtxPos1[i].zw * hm;\n"
                "    gsClip[i].xy -= v_vtxPos1[i].xy * gsClip[i].w * hm;\n"
                "  }\n"
                "%s"
                "}\n",
                num_in, num_in, num_in,
                per_axis_flat ? flat_test : "",
                num_in,
                hp_keep ? "  hp_keep(hm);\n" : "");
        } else {
            mstring_append_fmt(output,
                "vec4 gsPos[%d];\n"
                "vec4 gsClip[%d];\n"
                "void hp_init() {\n"
                "  bool hit = true;\n"
                "  for (int i = 0; i < %d; i++) {\n"
                "    hit = hit && all(equal(fract(v_vtxPos0[i].xy), vec2(0.5)));\n"
                "  }\n"
                "  for (int i = 0; i < %d; i++) {\n"
                "    gsPos[i] = v_vtxPos0[i];\n"
                "    gsClip[i] = gl_in[i].gl_Position;\n"
                "    if (hit) {\n"
                "      gsPos[i].xy -= v_vtxPos1[i].zw;\n"
                "      gsClip[i].xy -= v_vtxPos1[i].xy * gsClip[i].w;\n"
                "    }\n"
                "  }\n"
                "%s"
                "}\n",
                num_in, num_in, num_in, num_in,
                hp_keep ? "  hp_keep(hit);\n" : "");
        }
        if (hp_keep) {
            /* declared before hp_init, which calls it; flat colours come
             * from one vertex and stay as they are */
            const char *col = state->smooth_shading ? "HP_COLOR" : "HP_FLAT";
            MString *keep = mstring_from_fmt(
                "vec4 gsvtxD0[%d], gsvtxD1[%d], gsvtxB0[%d], gsvtxB1[%d];\n"
                "vec4 gsvtxT0[%d], gsvtxT1[%d], gsvtxT2[%d], gsvtxT3[%d];\n"
                "float gsFog[%d];\n"
                "#define HP_AT(a, i) (a[i] + st.x * (a[1] - a[0]) + st.y * (a[2] - a[0]))\n"
                "#define HP_COLOR(a, i) clamp(HP_AT(a, i), 0.0, 1.0)\n"
                "#define HP_FLAT(a, i) a[i]\n"
                "void hp_keep(%s) {\n"
                "  vec2 st = vec2(0.0);\n"
                "  if (%s) {\n"
                "    vec2 e1 = v_vtxPos0[1].xy - v_vtxPos0[0].xy;\n"
                "    vec2 e2 = v_vtxPos0[2].xy - v_vtxPos0[0].xy;\n"
                "    vec2 m = -v_vtxPos1[0].zw%s;\n"
                "    float det = e1.x * e2.y - e1.y * e2.x;\n"
                "    if (abs(det) > 1e-6) {\n"
                "      st = vec2(m.x * e2.y - m.y * e2.x,\n"
                "                e1.x * m.y - e1.y * m.x) / det;\n"
                "    }\n"
                "  }\n"
                "  for (int i = 0; i < %d; i++) {\n"
                "    gsvtxD0[i] = %s(v_vtxD0, i);\n"
                "    gsvtxD1[i] = %s(v_vtxD1, i);\n"
                "    gsvtxB0[i] = %s(v_vtxB0, i);\n"
                "    gsvtxB1[i] = %s(v_vtxB1, i);\n"
                "    gsvtxT0[i] = HP_AT(v_vtxT0, i);\n"
                "    gsvtxT1[i] = HP_AT(v_vtxT1, i);\n"
                "    gsvtxT2[i] = HP_AT(v_vtxT2, i);\n"
                "    gsvtxT3[i] = HP_AT(v_vtxT3, i);\n"
                "    gsFog[i] = HP_AT(v_vtxFog, i);\n"
                "  }\n"
                "}\n",
                num_in, num_in, num_in, num_in, num_in, num_in, num_in,
                num_in, num_in,
                per_axis ? "vec2 hm" : "bool hit",
                per_axis ? "any(notEqual(hm, vec2(0.0)))" : "hit",
                per_axis ? " * hm" : "",
                num_in, col, col, col, col);
            /* hp_init was just appended: put hp_keep in front of it */
            const char *all = mstring_get_str(output);
            const char *at = strstr(all, "vec4 gsPos[");
            assert(at);
            MString *re = mstring_from_fmt("%.*s%s%s", (int)(at - all), all,
                                           mstring_get_str(keep), at);
            mstring_unref(keep);
            mstring_unref(output);
            output = re;
        }
        snprintf(hp_body, sizeof(hp_body), "  hp_init();\n");
    }

    char vertex_order_buf[80];
    const char *vertex_order_body = "";

    if (need_triz) {
        /* Input triangle absolute vertex order is not guaranteed by OpenGL
         * or Vulkan, only winding order is. Reorder vertices here to first
         * vertex convention which we assumed above when setting
         * provoking_index. This mostly only matters with flat shading, but
         * we reorder always to get consistent results across GPU vendors
         * regarding floating-point rounding when calculating with vtxPos0/1/2.
         */
        mstring_append(output, "ivec3 v;\n");
        if (state->tri_rot0 == state->tri_rot1) {
            snprintf(vertex_order_buf, sizeof(vertex_order_buf), "  v = %s;\n",
                     get_vertex_order(state->tri_rot0));
        } else {
            snprintf(vertex_order_buf, sizeof(vertex_order_buf),
                     "  v = (gl_PrimitiveIDIn & 1) == 0 ? %s : %s;\n",
                     get_vertex_order(state->tri_rot0),
                     get_vertex_order(state->tri_rot1));
        }
        vertex_order_body = vertex_order_buf;
    }

    if (state->smooth_shading) {
        provoking_index = "index";
    }
    const char *hp_attr = hp_keep ? "gs" : "v_";

    mstring_append_fmt(
        output,
        "void emit_vertex(int index, mat4 pz) {\n"
        "  gl_Position = %sindex%s;\n"
        "  gl_PointSize = gl_in[index].gl_PointSize;\n"
        "  vtxD0 = %svtxD0[%s];\n"
        "  vtxD1 = %svtxD1[%s];\n"
        "  vtxB0 = %svtxB0[%s];\n"
        "  vtxB1 = %svtxB1[%s];\n"
        "  vtxFog = %s[index];\n"
        "  vtxT0 = %svtxT0[index];\n"
        "  vtxT1 = %svtxT1[index];\n"
        "  vtxT2 = %svtxT2[index];\n"
        "  vtxT3 = %svtxT3[index];\n"
        "  vtxPos0 = pz[0];\n"
        "  vtxPos1 = pz[1];\n"
        "  vtxPos2 = pz[2];\n"
        "  triMZ = (isnan(pz[3].x) || isinf(pz[3].x)) ? 0.0 : pz[3].x;\n"
        "  EmitVertex();\n"
        "}\n",
        pos_pre, pos_post,
        hp_attr, provoking_index,
        hp_attr, provoking_index,
        hp_attr, provoking_index,
        hp_attr, provoking_index,
        hp_keep ? "gsFog" : "v_vtxFog",
        hp_attr, hp_attr, hp_attr, hp_attr);

    if (need_triz || need_quadz) {
        mstring_append(
            output,
            // Kahan's algorithm for computing a*b - c*d using FMA for higher
            // precision. See e.g.:
            // Muller et al, "Handbook of Floating-Point Arithmetic", 2nd ed.
            // or
            // Claude-Pierre Jeannerod, Nicolas Louvet, and Jean-Michel Muller,
            // Further analysis of Kahan's algorithm for the accurate
            // computation of 2x2 determinants,
            // Mathematics of Computation 82(284), October 2013.
            "float kahan_det(float a, float b, float c, float d) {\n"
            "  precise float cd = c*d;\n"
            "  precise float err = fma(-c, d, cd);\n"
            "  precise float res = fma(a, b, -cd) + err;\n"
            "  return res;\n"
            "}\n");

        if (state->z_perspective) {
            mstring_append(
                output,
                "mat4 calc_triz(int i0, int i1, int i2) {\n"
                "  mat2 m = mat2(v_vtxPos[i1].xy - v_vtxPos[i0].xy,\n"
                "                v_vtxPos[i2].xy - v_vtxPos[i0].xy);\n"
                "  precise vec2 b = vec2(v_vtxPos[i0].w - v_vtxPos[i1].w,\n"
                "                        v_vtxPos[i0].w - v_vtxPos[i2].w);\n"
                "  b /= vec2(v_vtxPos[i1].w, v_vtxPos[i2].w) * v_vtxPos[i0].w;\n"
                // The following computes dzx and dzy same as
                // vec2 dz = b * inverse(m);
                "  float det = kahan_det(m[0].x, m[1].y, m[1].x, m[0].y);\n"
                "  float dzx = kahan_det(b.x, m[1].y, b.y, m[0].y) / det;\n"
                "  float dzy = kahan_det(b.y, m[0].x, b.x, m[1].x) / det;\n"
                "  float dz = max(abs(dzx), abs(dzy));\n"
                "  return mat4(v_vtxPos[i0], v_vtxPos[i1], v_vtxPos[i2], dz, vec3(0.0));\n"
                "}\n");
        } else {
            mstring_append(
                output,
                "mat4 calc_triz(int i0, int i1, int i2) {\n"
                "  mat2 m = mat2(v_vtxPos[i1].xy - v_vtxPos[i0].xy,\n"
                "                v_vtxPos[i2].xy - v_vtxPos[i0].xy);\n"
                "  precise vec2 b = vec2(v_vtxPos[i1].z - v_vtxPos[i0].z,\n"
                "                        v_vtxPos[i2].z - v_vtxPos[i0].z);\n"
                // The following computes dzx and dzy same as
                // vec2 dz = b * inverse(m);
                "  float det = kahan_det(m[0].x, m[1].y, m[1].x, m[0].y);\n"
                "  float dzx = kahan_det(b.x, m[1].y, b.y, m[0].y) / det;\n"
                "  float dzy = kahan_det(b.y, m[0].x, b.x, m[1].x) / det;\n"
                "  float dz = max(abs(dzx), abs(dzy));\n"
                "  return mat4(v_vtxPos[i0], v_vtxPos[i1], v_vtxPos[i2], dz, vec3(0.0));\n"
                "}\n");
        }
    }

    /* "Native Edges, 2D" (half_pixel 2): a flat filled triangle (one z and
     * w at all corners: UI, 2D) is grown by half a native pixel on every
     * side, its outputs extrapolated to the new corners (linear: one w), so
     * that every fine pixel of a native pixel whose centre lies inside is
     * rasterized; the pixel shader discards the others (psh.c). At 1x a
     * pixel is drawn when its centre is inside, so an edge on n.5 covers the
     * whole pixel next to it; drawn at the real edge at Nx it left half a
     * native pixel uncovered (JSRF's letterbox, NNshi). Nothing moves: the
     * texture stays where the geometry puts it. */
    char *native_body = NULL;
    if (state->half_pixel == 2 && strstr(body, "emit_vertex(")) {
        native_body = native_edges_body(body);
        body = native_body;
        /* colours as emit_vertex takes them: interpolated, or the provoking
         * vertex's with flat shading */
        char colours[512];
        if (state->smooth_shading) {
            snprintf(colours, sizeof(colours), "%s",
                "    vtxD0 = l0 * v_vtxD0[i0] + l1 * v_vtxD0[i1] + l2 * v_vtxD0[i2];\n"
                "    vtxD1 = l0 * v_vtxD1[i0] + l1 * v_vtxD1[i1] + l2 * v_vtxD1[i2];\n"
                "    vtxB0 = l0 * v_vtxB0[i0] + l1 * v_vtxB0[i1] + l2 * v_vtxB0[i2];\n"
                "    vtxB1 = l0 * v_vtxB1[i0] + l1 * v_vtxB1[i1] + l2 * v_vtxB1[i2];\n");
        } else {
            snprintf(colours, sizeof(colours),
                     "    vtxD0 = v_vtxD0[%s];\n"
                     "    vtxD1 = v_vtxD1[%s];\n"
                     "    vtxB0 = v_vtxB0[%s];\n"
                     "    vtxB1 = v_vtxB1[%s];\n",
                     provoking_index, provoking_index, provoking_index,
                     provoking_index);
        }
        mstring_append_fmt(
            output,
            "void emit_tri(int i0, int i1, int i2, mat4 pz) {\n"
            "  vec2 P[3] = vec2[3](v_vtxPos[i0].xy, v_vtxPos[i1].xy, v_vtxPos[i2].xy);\n"
            "  bool flat2d = all(equal(v_vtxPos[i0].zw, v_vtxPos[i1].zw)) &&\n"
            "                all(equal(v_vtxPos[i1].zw, v_vtxPos[i2].zw));\n"
            "  float A = (P[1].x - P[0].x) * (P[2].y - P[0].y) -\n"
            "            (P[1].y - P[0].y) * (P[2].x - P[0].x);\n"
            "  if (!flat2d || A == 0.0) {\n"
            "    emit_vertex(i0, pz);\n"
            "    emit_vertex(i1, pz);\n"
            "    emit_vertex(i2, pz);\n"
            "    EndPrimitive();\n"
            "    return;\n"
            "  }\n"
            "  vec2 n[3];\n"
            "  for (int k = 0; k < 3; k++) {\n"
            "    vec2 e = P[(k + 1) %% 3] - P[k];\n"
            "    n[k] = sign(A) * normalize(vec2(e.y, -e.x));\n"
            "  }\n"
            "  int I[3] = int[3](i0, i1, i2);\n"
            "  for (int k = 0; k < 3; k++) {\n"
            "    vec2 a = n[(k + 2) %% 3], b = n[k];\n"
            "    vec2 E = P[k] + 0.5 * (a + b) / max(1.0 + dot(a, b), 0.0625);\n"
            "    float l1 = ((E.x - P[0].x) * (P[2].y - P[0].y) -\n"
            "                (E.y - P[0].y) * (P[2].x - P[0].x)) / A;\n"
            "    float l2 = ((P[1].x - P[0].x) * (E.y - P[0].y) -\n"
            "                (P[1].y - P[0].y) * (E.x - P[0].x)) / A;\n"
            "    float l0 = 1.0 - l1 - l2;\n"
            "    gl_Position = l0 * gl_in[i0].gl_Position + l1 * gl_in[i1].gl_Position +\n"
            "                  l2 * gl_in[i2].gl_Position;\n"
            "    gl_PointSize = gl_in[I[k]].gl_PointSize;\n"
            "%s"
            "    vtxFog = l0 * v_vtxFog[i0] + l1 * v_vtxFog[i1] + l2 * v_vtxFog[i2];\n"
            "    vtxT0 = l0 * v_vtxT0[i0] + l1 * v_vtxT0[i1] + l2 * v_vtxT0[i2];\n"
            "    vtxT1 = l0 * v_vtxT1[i0] + l1 * v_vtxT1[i1] + l2 * v_vtxT1[i2];\n"
            "    vtxT2 = l0 * v_vtxT2[i0] + l1 * v_vtxT2[i1] + l2 * v_vtxT2[i2];\n"
            "    vtxT3 = l0 * v_vtxT3[i0] + l1 * v_vtxT3[i1] + l2 * v_vtxT3[i2];\n"
            "    vtxPos0 = pz[0];\n"
            "    vtxPos1 = pz[1];\n"
            "    vtxPos2 = pz[2];\n"
            "    triMZ = (isnan(pz[3].x) || isinf(pz[3].x)) ? 0.0 : pz[3].x;\n"
            "    EmitVertex();\n"
            "  }\n"
            "  EndPrimitive();\n"
            "}\n",
            colours);
    }

    if (need_linez) {
        mstring_append(
            output,
            // Calculate a third vertex by rotating 90 degrees so that triangle
            // interpolation in fragment shader can be used as is for lines.
            "void emit_line(int i0, int i1, float dz) {\n"
            "  vec2 delta = v_vtxPos[i1].xy - v_vtxPos[i0].xy;\n"
            "  vec2 v2 = vec2(-delta.y, delta.x) + v_vtxPos[i0].xy;\n"
            "  mat4 pz = mat4(v_vtxPos[i0], v_vtxPos[i1], v2, v_vtxPos[i0].zw, dz, vec3(0.0));\n"
            "  emit_vertex(i0, pz);\n"
            "  emit_vertex(i1, pz);\n"
            "  EndPrimitive();\n"
            "}\n");
    }

    if (need_wide) {
        /* A segment as a rectangle of the guest's width: the width is in
         * guest pixels and the surface size in guest pixels too, so the
         * internal scale cancels (1 pixel = 2 / size in clip space). The
         * rectangle is emitted with the winding the culling state keeps,
         * since the hardware never culls a line. */
        mstring_append_fmt(
            output,
            "uniform vec2 gsSurfaceSize;\n"
            "uniform float gsLineWidth;\n"
            "uniform int gsKeepWinding;\n"
            "void emit_wide_vertex(int index, mat4 pz, vec4 pos) {\n"
            "  gl_Position = pos;\n"
            "  gl_PointSize = gl_in[index].gl_PointSize;\n"
            "  vtxD0 = v_vtxD0[%s];\n"
            "  vtxD1 = v_vtxD1[%s];\n"
            "  vtxB0 = v_vtxB0[%s];\n"
            "  vtxB1 = v_vtxB1[%s];\n"
            "  vtxFog = v_vtxFog[index];\n"
            "  vtxT0 = v_vtxT0[index];\n"
            "  vtxT1 = v_vtxT1[index];\n"
            "  vtxT2 = v_vtxT2[index];\n"
            "  vtxT3 = v_vtxT3[index];\n"
            "  vtxPos0 = pz[0];\n"
            "  vtxPos1 = pz[1];\n"
            "  vtxPos2 = pz[2];\n"
            "  triMZ = (isnan(pz[3].x) || isinf(pz[3].x)) ? 0.0 : pz[3].x;\n"
            "  EmitVertex();\n"
            "}\n"
            "void emit_wide_line(int i0, int i1, float dz) {\n"
            "  vec2 delta = v_vtxPos[i1].xy - v_vtxPos[i0].xy;\n"
            "  vec2 v2 = vec2(-delta.y, delta.x) + v_vtxPos[i0].xy;\n"
            "  mat4 pz = mat4(v_vtxPos[i0], v_vtxPos[i1], v2, v_vtxPos[i0].zw, dz, vec3(0.0));\n"
            "  vec4 p0 = %si0%s;\n"
            "  vec4 p1 = %si1%s;\n"
            "  vec2 s0 = p0.xy / p0.w;\n"
            "  vec2 s1 = p1.xy / p1.w;\n"
            "  vec2 d = (s1 - s0) * gsSurfaceSize;\n"
            "  float len = length(d);\n"
            "  vec2 n = (len > 0.0) ? vec2(-d.y, d.x) / len : vec2(0.0, 1.0);\n"
            "  vec2 off = n * gsLineWidth / gsSurfaceSize;\n"
            "  vec2 a = s0 + off;\n"
            "  vec2 b = s0 - off;\n"
            "  vec2 c = s1 + off;\n"
            "  float area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);\n"
            "  if ((gsKeepWinding == 1 && area < 0.0) || (gsKeepWinding == 0 && area > 0.0)) {\n"
            "    off = -off;\n"
            "  }\n"
            "  emit_wide_vertex(i0, pz, vec4((s0 + off) * p0.w, p0.zw));\n"
            "  emit_wide_vertex(i0, pz, vec4((s0 - off) * p0.w, p0.zw));\n"
            "  emit_wide_vertex(i1, pz, vec4((s1 + off) * p1.w, p1.zw));\n"
            "  emit_wide_vertex(i1, pz, vec4((s1 - off) * p1.w, p1.zw));\n"
            "  EndPrimitive();\n"
            "}\n",
            provoking_index, provoking_index, provoking_index, provoking_index,
            pos_pre, pos_post, pos_pre, pos_post);
    }

    if (need_quadz) {
        mstring_append(
            output,
            "void calc_quadz(int i0, int i1, int i2, int i3, out mat4 triz1, out mat4 triz2) {\n"
            "  triz1 = calc_triz(i0, i1, i2);\n"
            "  triz2 = calc_triz(i0, i2, i3);\n"
            "}\n");
    }

    mstring_append_fmt(output,
                       "\n"
                       "void main() {\n"
                       "%s"
                       "%s"
                       "%s"
                       "}\n",
                       hp_body, vertex_order_body, body);
    g_free(native_body);

    return output;
}
