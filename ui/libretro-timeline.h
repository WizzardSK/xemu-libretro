/*
 * Frame timeline (test build, NNshi: OutRun 2 NTSC-J): every retro_run writes
 * one line to <system>/xemu/frametimeline.txt with the guest's display events
 * since the run before, timed from that run's start, for telling a frame
 * finished too late from one finished in time and handed over at the wrong
 * run. Events (xemu_lr_tl):
 *   V  the core raised the vblank (hw/xbox/nv2a/nv2a.c)
 *   A  the guest acknowledged it (hw/xbox/nv2a/pcrtc.c)
 *   S  FLIP_STALL: the game's GPU queue starts to wait for the flip
 *   C  that wait ended, the flip is done (hw/xbox/nv2a/pfifo.c)
 *   F  the flip itself, NV_PGRAPH_INCREMENT (hw/xbox/nv2a/pgraph/pgraph.c)
 *   G  the renderer drew a new guest frame for the display (vk/display.c)
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef UI_LIBRETRO_TIMELINE_H
#define UI_LIBRETRO_TIMELINE_H

void xemu_lr_tl(char kind);

#endif
