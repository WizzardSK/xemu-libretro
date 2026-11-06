/*
 * Titles that draw a 448-line picture inside the Xbox's 480 lines, with black
 * bars above and below, by the Title ID in their certificate (one per
 * release), their IDs taken from xemu's xdb by name. Crop Vertical Overscan's
 * Auto crops these. The games are the ones testers found to have them (NNshi). Sorted, for
 * bsearch.
 */

#ifndef LIBRETRO_OVERSCAN_TITLES_H
#define LIBRETRO_OVERSCAN_TITLES_H

#include <stdint.h>

static const uint32_t libretro_overscan_titles[] = {
    0x4541005B, /* Burnout 3: Takedown */
    0x45410076, /* Burnout Revenge */
    0x45410081, /* Burnout Revenge */
    0x49500008, /* Fallout: Brotherhood of Steel */
    0x4950000A, /* Baldur's Gate: Dark Alliance II */
    0x49580001, /* The Bard's Tale */
    0x4B4F0003, /* Dynasty Warriors 3 */
    0x4B4F0004, /* Dynasty Warriors 4 */
    0x4B4F0007, /* Dynasty Warriors 5 */
    0x4E4D0009, /* Breakdown */
    0x53500001, /* Combat Elite: WWII Paratroopers */
    0x564E0006, /* Baldur's Gate: Dark Alliance */
    0x5655001A, /* Baldur's Gate: Dark Alliance */
};

#endif
