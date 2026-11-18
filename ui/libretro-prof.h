/*
 * vCPU and GPU-thread sampling profiler of Profiler (F10) (ui/libretro-prof.c).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef UI_LIBRETRO_PROF_H
#define UI_LIBRETRO_PROF_H

/* A line for RetroArch's log, printf-style, ending in a newline */
typedef void (*XemuLrProfLog)(const char *fmt, ...);

/* On the vCPU thread, once: the thread the profiler samples */
void xemu_lr_prof_vcpu(void);
/* On the GPU thread (nv2a.pfifo), once: sampled beside the vCPU */
void xemu_lr_prof_pfifo(void);
/* The profiler came on: start sampling */
void xemu_lr_prof_start(void);
/* The profiler went off (or the game closes): stop, log the shares and
 * write every bucket to the file at path (overwritten), after header, the
 * run's description; path NULL writes no file */
void xemu_lr_prof_stop(XemuLrProfLog log, const char *path,
                       const char *header);

#endif
