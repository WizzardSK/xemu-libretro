/*
 * xemu network control, for a build without slirp (the Android libretro
 * core): the Xbox's network adapter stays unplugged.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "qemu/osdep.h"
#include "ui/xemu-net.h"

void xemu_net_enable(void)
{
}

void xemu_net_disable(void)
{
}

int xemu_net_is_enabled(void)
{
    return 0;
}
