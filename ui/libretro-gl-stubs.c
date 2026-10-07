/*
 * The OpenGL side of the libretro core, for a build with no GL renderer
 * (Android, where the core draws with Vulkan only): ui/libretro.c still
 * names these, and they are never reached there.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "qemu/osdep.h"
typedef struct GloContext GloContext;

GloContext *glo_context_create(void)
{
    return NULL;
}

void glo_set_current(GloContext *context)
{
    (void)context;
}

void libretro_gl_prepare(void)
{
}

void libretro_gl_wake_pfifo(void)
{
}

void libretro_gl_set_standalone_mode(void)
{
}

void libretro_gl_init_wait_event(void)
{
}
