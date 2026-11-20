/*
 * Geforce NV2A PGRAPH lazy surface writebacks, shared by the renderers
 *
 * Copyright (c) 2026 Réda Chérif-Touil
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

#include "hw/xbox/nv2a/nv2a_int.h"
#include "writeback.h"

static bool wb_range_overlaps(const PGRAPHWritebackRange *r, hwaddr addr,
                              size_t size)
{
    return r->size && !(addr >= r->addr + r->size || r->addr >= addr + size);
}

/* Whether a range is live, for an eviction about to write it back: each
 * live range it overlaps counts one more eager writeback, and one that went
 * PGRAPH_WB_LIVE_EVICTIONS of them without a reader proving it live again
 * is forgotten. That is safe: a forgotten range's evictions are owed to
 * their first reader, which writes them back then and learns it again. */
static bool G_GNUC_UNUSED writeback_range_is_live(PGRAPHState *pg, hwaddr addr, size_t size)
{
    PGRAPHWritebackState *wb = &pg->writeback;
    bool live = false;
    for (unsigned int i = 0; i < PGRAPH_WB_LIVE_RANGES; i++) {
        if (wb_range_overlaps(&wb->live[i], addr, size)) {
            live = true;
            if (++wb->live_evictions[i] >= PGRAPH_WB_LIVE_EVICTIONS) {
                wb->live[i].size = 0;
                wb->live_evictions[i] = 0;
            }
        }
    }
    return live;
}

bool pgraph_writeback_dead(NV2AState *d, hwaddr addr, size_t size,
                           unsigned int cpu_reads)
{
    if (cpu_reads != 0) {
        return false;
    }
    /* No list of ranges a reader once proved live (eager writebacks for
     * them): every eviction is owed to its first reader, which writes it
     * back then. Conker kept a depth buffer evicted 90 times a second in
     * that list, written back and uploaded again each time. */
    hwaddr scan = d->pcrtc.start;
    if (scan >= addr && scan < addr + size) {
        return false; /* the displayed framebuffer -- must be preserved */
    }
    return true;
}

void pgraph_writeback_learn_live(PGRAPHState *pg, hwaddr addr, size_t size)
{
    PGRAPHWritebackState *wb = &pg->writeback;

    for (unsigned int i = 0; i < PGRAPH_WB_LIVE_RANGES; i++) {
        if (wb->live[i].size && wb->live[i].addr == addr &&
            wb->live[i].size == size) {
            wb->live_evictions[i] = 0; /* proven live again */
            return; /* already known */
        }
    }
    unsigned int i = wb->live_w % PGRAPH_WB_LIVE_RANGES;
    wb->live[i] = (PGRAPHWritebackRange){ .addr = addr, .size = size };
    wb->live_evictions[i] = 0;
    wb->live_w++;
}

void pgraph_writeback_record_discard(PGRAPHState *pg, hwaddr addr,
                                     size_t size)
{
    PGRAPHWritebackState *wb = &pg->writeback;

    wb->discarded[wb->discarded_w % PGRAPH_WB_DISCARD_SPANS] =
        (PGRAPHWritebackRange){ .addr = addr, .size = size };
    wb->discarded_w++;
}

bool pgraph_writeback_discarded(PGRAPHState *pg, hwaddr addr, size_t size)
{
    for (unsigned int i = 0; i < PGRAPH_WB_DISCARD_SPANS; i++) {
        const PGRAPHWritebackRange *s = &pg->writeback.discarded[i];
        if (s->size && addr >= s->addr && addr + size <= s->addr + s->size) {
            return true;
        }
    }
    return false;
}

void pgraph_writeback_clear_discard(PGRAPHState *pg, hwaddr addr,
                                    size_t size)
{
    for (unsigned int i = 0; i < PGRAPH_WB_DISCARD_SPANS; i++) {
        if (wb_range_overlaps(&pg->writeback.discarded[i], addr, size)) {
            pg->writeback.discarded[i].size = 0;
        }
    }
}

void pgraph_writeback_reset(PGRAPHState *pg)
{
    memset(&pg->writeback, 0, sizeof(pg->writeback));
}
