/*
 * vCPU sampling profiler for the Performance Overlay (ui/libretro-prof.c).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef UI_LIBRETRO_PROF_H
#define UI_LIBRETRO_PROF_H

/* A line for RetroArch's log, printf-style, ending in a newline */
typedef void (*XemuLrProfLog)(const char *fmt, ...);

/* On the vCPU thread, once: the thread the profiler samples */
void xemu_lr_prof_vcpu(void);
/* The overlay came on: start sampling */
void xemu_lr_prof_start(void);
/* The overlay went off (or the game closes): stop, log the shares and
 * write every bucket to <dir>/xemu_profile.txt */
void xemu_lr_prof_stop(XemuLrProfLog log, const char *dir);

#endif
