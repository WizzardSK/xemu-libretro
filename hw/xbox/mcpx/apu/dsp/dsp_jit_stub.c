/*
 * The DSP without its JIT: on Android there is no build of the dsp56300
 * library the JIT runs on, so the C interpreter stands in for it.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include "qemu/osdep.h"
#include "dsp_internal.h"

const DSPOps jit_dsp_ops;

void dsp_jit_init(DSPState *dsp)
{
    dsp_c_init(dsp);
}
