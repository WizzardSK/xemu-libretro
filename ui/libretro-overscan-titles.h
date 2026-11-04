/*
 * Titles that draw a 448-line picture inside the Xbox's 480 lines, with black
 * bars above and below, by the Title ID in their certificate (one per
 * release), their IDs taken from xemu's xdb by name. Crop Vertical Overscan's
 * Auto crops these. The games are the ones testers named (NNshi). Sorted, for
 * bsearch.
 */

#ifndef LIBRETRO_OVERSCAN_TITLES_H
#define LIBRETRO_OVERSCAN_TITLES_H

#include <stdint.h>

static const uint32_t libretro_overscan_titles[] = {
    0x45410049, /* Def Jam: Fight for NY */
    0x4541005B, /* Burnout 3: Takedown */
    0x45410067, /* Def Jam: Fight for NY */
    0x45410076, /* Burnout Revenge */
    0x45410081, /* Burnout Revenge */
    0x49500008, /* Fallout: Brotherhood of Steel */
    0x4950000A, /* Baldur's Gate: Dark Alliance II */
    0x49580001, /* The Bard's Tale */
    0x4B4E0004, /* Silent Hill 2: Restless Dreams */
    0x4B4E001F, /* Silent Hill 4: The Room */
    0x4B540001, /* Silent Hill 2: Saigo no Uta */
    0x5443000A, /* Fatal Frame II: Crimson Butterfly */
    0x54540019, /* Manhunt */
    0x564E0006, /* Baldur's Gate: Dark Alliance */
    0x5655001A, /* Baldur's Gate: Dark Alliance */
};

#endif
