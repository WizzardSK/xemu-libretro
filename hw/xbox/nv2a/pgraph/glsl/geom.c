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

/* GeomState.half_pixel for the pending draw: on only above 1x, where the
 * half-pixel offset a game applies no longer lands on a pixel edge */
int pgraph_glsl_geom_half_pixel(PGRAPHState *pg)
{
    return qatomic_read(&xemu_libretro_half_pixel) &&
           pg->surface_scale_factor > 1;
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
                         state->half_pixel ?
                             "gsPos" : "v_vtxPos0");
    pgraph_glsl_get_vtx_header(output, opts.vulkan || opts.locations,
                               state->smooth_shading, true, true, true);
    pgraph_glsl_get_vtx_header(output, opts.vulkan || opts.locations,
                               state->smooth_shading, false, false, false);

    /* Half-Pixel Offset: above 1x, a corner coordinate on a half pixel is
     * one the game moved by Direct3D's half-pixel offset (screen-aligned
     * quads: UI, post-process passes, render-target copies). At 1x an edge
     * on n.5 covers the pixel beside it up to the pixel line; drawn at Nx it
     * covers half a native pixel less. The vertex shader leaves the
     * positions as they are and passes the shift in vtxPos1 (xy: clip space
     * per unit of w, zw: native pixels; the geometry shader rewrites vtxPos1
     * anyway), and hp_init() moves here
     * - each corner coordinate on n.5 on its own, so a bar with one edge on
     *   n.5 gets the 1x coverage there and keeps the other edge (JSRF's grey
     *   bar, GTA San Andreas' health bar, the letterboxes of MM3 and DW3);
     *   corners shared by neighbours move alike, so no seams open (Panzer
     *   Dragoon Orta's clouds),
     * - only in a primitive with every corner at the first one's w (flat:
     *   2D, UI, full-screen passes): 3D shadow volumes along a straight
     *   edge moved while their neighbours didn't, and the cracks showed in
     *   JSRF's shadows.
     * The content stays: a moved corner takes the texture coordinates,
     * colours and fog the primitive had at its new place, from the plane
     * through the first three corners in screen space (exact for a flat
     * primitive), so only the edges move. A line has no plane and moves
     * whole; points are moved by the vertex shader (vsh.c).
     * Tried on the texture-upscale branch and dropped (NNshi's tests):
     * moving a triangle or an axis only when all its corners are on n.5, a
     * check for rotated texture mapping, moving the content with the
     * corners, and growing flat primitives to the 1x coverage instead. */
    const bool hp_keep = state->half_pixel && num_in >= 3;
    const char *pos_pre = "gl_in[", *pos_post = "].gl_Position";
    char hp_body[48] = "";
    if (state->half_pixel) {
        pos_pre = "gsClip[";
        pos_post = "]";
        /* hit: the primitive may move (it is flat); each corner then moves
         * in the axes it has on n.5 (gsHm) */
        mstring_append_fmt(output,
            "vec2 gsHm[%d];\n"
            "vec4 gsPos[%d];\n"
            "vec4 gsClip[%d];\n"
            "void hp_init() {\n"
            "  bvec2 hit = bvec2(true);\n"
            "  for (int i = 1; i < %d; i++) {\n"
            "    if (v_vtxPos0[i].w != v_vtxPos0[0].w) {\n"
            "      hit = bvec2(false);\n"
            "    }\n"
            "  }\n"
            "  for (int i = 0; i < %d; i++) {\n"
            "    gsHm[i] = vec2(hit) * vec2(equal(fract(v_vtxPos0[i].xy), vec2(0.5)));\n"
            "    gsPos[i] = v_vtxPos0[i];\n"
            "    gsClip[i] = gl_in[i].gl_Position;\n"
            "    gsPos[i].xy -= v_vtxPos1[i].zw * gsHm[i];\n"
            "    gsClip[i].xy -= v_vtxPos1[i].xy * gsClip[i].w * gsHm[i];\n"
            "  }\n"
            "%s"
            "}\n",
            num_in, num_in, num_in, num_in, num_in,
            hp_keep ? "  hp_keep();\n" : "");
        if (hp_keep) {
            /* declared before hp_init, which calls it; st: where the moved
             * corner lies in the plane's coordinates (e1, e2), the outputs
             * taken there. Flat colours come from one vertex and stay. */
            const char *col = state->smooth_shading ? "HP_COLOR" : "HP_FLAT";
            MString *keep = mstring_from_fmt(
                "vec4 gsvtxD0[%d], gsvtxD1[%d], gsvtxB0[%d], gsvtxB1[%d];\n"
                "vec4 gsvtxT0[%d], gsvtxT1[%d], gsvtxT2[%d], gsvtxT3[%d];\n"
                "float gsFog[%d];\n"
                "#define HP_AT(a, i) (a[i] + st.x * (a[1] - a[0]) + st.y * (a[2] - a[0]))\n"
                "#define HP_COLOR(a, i) clamp(HP_AT(a, i), 0.0, 1.0)\n"
                "#define HP_FLAT(a, i) a[i]\n"
                "void hp_keep() {\n"
                "  vec2 e1 = v_vtxPos0[1].xy - v_vtxPos0[0].xy;\n"
                "  vec2 e2 = v_vtxPos0[2].xy - v_vtxPos0[0].xy;\n"
                "  float det = e1.x * e2.y - e1.y * e2.x;\n"
                "  for (int i = 0; i < %d; i++) {\n"
                "    vec2 st = vec2(0.0);\n"
                "    vec2 m = -v_vtxPos1[i].zw * gsHm[i];\n"
                "    if (any(notEqual(m, vec2(0.0))) && abs(det) > 1e-6) {\n"
                "      st = vec2(m.x * e2.y - m.y * e2.x,\n"
                "                e1.x * m.y - e1.y * m.x) / det;\n"
                "    }\n"
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
                num_in, num_in, num_in, col, col, col, col);
            /* hp_init was just appended: put hp_keep in front of it, after
             * gsHm, which it reads */
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

    return output;
}
