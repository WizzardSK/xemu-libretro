/*
 * Titles that render 16:9 when Widescreen is on in the dashboard's video
 * settings, by the Title ID in their certificate (one per release: the
 * regions have IDs of their own). The games are consolemods.org's list of
 * Xbox games with alternate display modes (16:9 column), their IDs taken
 * from MobCat's Xbox title ID database and the xemu cheat database by name.
 * Sorted, for bsearch.
 */

#ifndef LIBRETRO_WIDESCREEN_TITLES_H
#define LIBRETRO_WIDESCREEN_TITLES_H

#include <stdint.h>

static const uint32_t libretro_widescreen_titles[] = {
    0x41430006, /* Burnout */
    0x41430007, /* Aggressive Inline */
    0x4143000A, /* ATV Quad Power Racing 2 */
    0x4143000B, /* Speed Kings */
    0x41430019, /* Burnout 2: Point of Impact */
    0x4143001D, /* Showdown: Legends of Wrestling */
    0x41560003, /* Street Hoops */
    0x4156000E, /* True Crime: Streets of LA */
    0x41560010, /* Return to Castle Wolfenstein: Tides or War */
    0x41560017, /* Tony Hawk's Pro Skater 4 */
    0x4156001E, /* X-Men Legends */
    0x41560020, /* Doom 3 */
    0x4156002A, /* Call of Duty: Finest Hour */
    0x4156002D, /* Tony Hawk's Underground */
    0x4156003C, /* Tony Hawk's Underground 2 */
    0x41560045, /* True Crime: New York City */
    0x41560047, /* X-Men Legends 2: Rise of Apocalypse */
    0x41560049, /* Tony Hawk's American Wasteland */
    0x4156004B, /* GUN */
    0x4156004E, /* Doom 3: Resurrection of Evil */
    0x41560051, /* Call of Duty 2: Big Red One */
    0x41560055, /* Ty the Tasmanian Tiger 3: Night of the Quinkan */
    0x4156005C, /* Marvel: Ultimate Alliance */
    0x4156005D, /* Call of Duty 3 */
    0x4156005E, /* Tony Hawk's Project 8 */
    0x424D0003, /* Wallace & Gromit in Project Zoo */
    0x4253000A, /* Malice */
    0x4253000B, /* Powerdrome */
    0x42550004, /* Double-S.T.E.A.L. - The Second Clash */
    0x43430002, /* Steel Battalion */
    0x43430009, /* Steel Battalion: Line of Contact */
    0x434D0010, /* Colin McRae Rally 04 */
    0x434D002B, /* Colin McRae Rally 2005 */
    0x43560007, /* Future Tactics: The Uprising */
    0x45410002, /* NASCAR Thunder 2002 */
    0x45410026, /* 007 Nightfire */
    0x45410029, /* Ty the Tasmanian Tiger */
    0x4541002A, /* Freedom Fighters */
    0x4541002C, /* Dead to Rights */
    0x4541002E, /* Freedom Fighters */
    0x45410042, /* 007 Everything or Nothing */
    0x45410043, /* Sims, The: Bustin' Out */
    0x45410045, /* MVP Baseball 2004 */
    0x45410053, /* NASCAR 2005: Chase for the Cup */
    0x45410056, /* MVP Baseball 2005 */
    0x4541005A, /* Need for Speed: Underground 2 */
    0x4541005B, /* Burnout 3: Takedown */
    0x4541005C, /* Catwoman */
    0x45410060, /* The Urbz: Sims In The City */
    0x45410063, /* Ty the Tasmanian Tiger 2: Bush Rescue */
    0x45410066, /* TimeSplitters: Future Perfect */
    0x4541006F, /* Need for Speed: Underground 2 */
    0x45410071, /* Need for Speed: Underground 2 */
    0x45410072, /* FIFA Street */
    0x45410078, /* FIFA 2006 */
    0x4541007A, /* NBA Live 2006 */
    0x45410082, /* SSX on Tour */
    0x45410083, /* Black */
    0x45410085, /* FIFA Street 2 */
    0x4541008D, /* MVP NCAA Baseball 2006 */
    0x45410091, /* Half-Life 2 */
    0x4541009C, /* FIFA World Cup 2006 */
    0x454100A1, /* NBA Live 07 */
    0x454100A6, /* FIFA 2007 */
    0x45410389, /* Batman Begins */
    0x4541038B, /* Sims 2, The */
    0x454C0001, /* Scrapland */
    0x454D0020, /* FlatOut 2 */
    0x45530008, /* Commandos 2 */
    0x45530009, /* Hitman 2: Silent Assassin */
    0x4553000F, /* Legacy of Kain: Defiance */
    0x45530018, /* 25 to Life */
    0x47560003, /* Combat: Task Force 121 */
    0x4756000B, /* World War II Combat: Iwo Jima */
    0x48500001, /* Stolen */
    0x49470007, /* Test Drive */
    0x4947002B, /* Panzer Dragoon Orta */
    0x4947002C, /* Sega GT 2002 */
    0x49470034, /* V-Rally 3 */
    0x49470038, /* Driv3r */
    0x49470039, /* Godzilla: Destroy All Monsters Melee */
    0x4947003B, /* Terminator 3: Rise of the Machines */
    0x49470079, /* Atari Anthology */
    0x4947007B, /* Indigo Prophecy/Fahrenheit */
    0x4947007F, /* Driver: Parallel Lines */
    0x49500006, /* Run Like Hell */
    0x4B4E0003, /* ESPN NFL PrimeTime 2002 */
    0x4B4E0019, /* Dance Dance Revolution Ultramix */
    0x4B4E0020, /* TMNT: Mutant Melee */
    0x4B4E0021, /* Dance Dance Revolution Ultramix 2 */
    0x4B4E0029, /* Dance Dance Revolution Ultramix 3 */
    0x4B4E002F, /* Winning Eleven 9 */
    0x4B4E0030, /* Winning Eleven 9 */
    0x4B4E0034, /* Wallace & Gromit: The Curse of the Were-Rabbit */
    0x4C41000B, /* Star Wars Jedi Knight: Jedi Academy */
    0x4C41000D, /* Armed and Dangerous */
    0x4C410011, /* Star Wars: Battlefront */
    0x4C410013, /* Star Wars: Republic Commando */
    0x4C410015, /* Mercenaries: Playground of Destruction */
    0x4C410019, /* Star Wars: Republic Commando */
    0x4C41001A, /* Star Wars: Battlefront II */
    0x4C41001F, /* Lego Star Wars II: The Original Trilogy */
    0x4D490006, /* Syberia */
    0x4D49000D, /* Sniper Elite */
    0x4D4A0009, /* Advent Rising */
    0x4D500002, /* Shikigami no Shiro */
    0x4D530005, /* Amped: Freestyle Snowboarding */
    0x4D530007, /* Azurik: Rise of Perathia */
    0x4D53000F, /* Rallisport Challenge */
    0x4D53002D, /* Dead or Alive 3 */
    0x4D530035, /* Top Spin */
    0x4D530039, /* Rallisport Challenge 2 */
    0x4D530041, /* Amped 2 */
    0x4D53004B, /* Project Gotham Racing 2 */
    0x4D530053, /* Grabbed by the Ghoulies */
    0x4D530064, /* Halo 2 */
    0x4D53006B, /* MechAssault 2: Lone Wolf */
    0x4D53006E, /* Forza Motorsport */
    0x4D570010, /* NBA Ballers */
    0x4D570018, /* Roadkill */
    0x4D570019, /* Mortal Kombat: Deception */
    0x4D570023, /* Mortal Kombat: Deception */
    0x4D57002C, /* The Suffering: Ties That Bind */
    0x4D570034, /* Mortal Kombat: Armageddon */
    0x4E4D0003, /* Soul Calibur II */
    0x4E4D0005, /* Dead to Rights */
    0x4E4D000B, /* Kill Switch */
    0x4E4D000F, /* I-Ninja */
    0x504C0006, /* Kingdom Under Fire: Heroes */
    0x52410007, /* Rocky */
    0x5343000A, /* Conflict: Vietnam */
    0x5343000C, /* Conflict: Global Terror */
    0x53430010, /* Total Overdose */
    0x534300FA, /* Hitman: Blood Money */
    0x534300FD, /* Tomb Raider: Legend */
    0x53450003, /* Sega GT 2002 */
    0x53450007, /* Panzer Dragoon Orta */
    0x5345000F, /* ToeJam & Earl III: Mission to Earth */
    0x53450013, /* NBA 2K3 */
    0x5345001E, /* NBA 2K3 */
    0x53450021, /* Sega GT Online */
    0x53450022, /* ESPN NFL Football */
    0x53450023, /* ESPN NBA Basketball 2k4 */
    0x5345002C, /* ESPN NFL Football */
    0x53450030, /* ESPN NFL 2K5 */
    0x53450031, /* ESPN NBA 2K5 */
    0x53450036, /* OutRun2 */
    0x53450037, /* Major League Baseball 2K5 */
    0x53450038, /* Super Monkey Ball Deluxe */
    0x53450080, /* ESPN NBA 2K5 */
    0x53450088, /* OutRun 2006: Coast 2 Coast */
    0x53500001, /* Combat Elite: WWII Paratroopers */
    0x53570001, /* Enclave */
    0x54430001, /* Dead or Alive 3 */
    0x54430003, /* Ninja Gaiden */
    0x54430006, /* Dead or Alive Ultimate */
    0x54430007, /* Dead or Alive Xtreme Beach Volleyball */
    0x5443000D, /* Ninja Gaiden Black */
    0x5443000E, /* Tecmo Arcade Classics */
    0x5451000D, /* WWE Raw 2 */
    0x5451000F, /* Alter Echo */
    0x54510018, /* The Punisher */
    0x5451001D, /* Broken Sword: The Sleeping Dragon */
    0x5451001F, /* Scooby-Doo! Night of 100 Frights */
    0x54510021, /* MX Unleashed */
    0x54510023, /* Sphinx and the Cursed Mummy */
    0x54510025, /* Evil Dead: Regeneration */
    0x54510026, /* Destroy All Humans! */
    0x54510027, /* The Spongebob Squarepants Movie */
    0x545100ED, /* MX vs. ATV Unleashed */
    0x54510106, /* Destroy All Humans! 2 */
    0x54510109, /* Disney/Pixar Ratatouille */
    0x54540006, /* State of Emergency */
    0x54540008, /* Midnight Club II */
    0x5454000C, /* Max Payne 2 */
    0x5454000E, /* Grand Theft Auto III */
    0x5454000F, /* Grand Theft Auto: Vice City */
    0x54540012, /* Close Combat: First to Fight */
    0x54540016, /* Virtual Pool */
    0x5454001A, /* Red Dead Revolver */
    0x5454001B, /* Robotech: Invasion */
    0x54540073, /* Grand Theft Auto: Vice City */
    0x54540079, /* Midnight Club 3: DUB Edition */
    0x5454007C, /* Spy Vs. Spy */
    0x5454007F, /* Robotech: Invasion */
    0x54540082, /* Grand Theft Auto: San Andreas */
    0x54540084, /* Spy Vs. Spy */
    0x54540086, /* Grand Theft Auto: San Andreas */
    0x5454008F, /* Sid Meier's Pirates! */
    0x54540090, /* NBA 2K6 */
    0x54540095, /* Grand Theft Auto: San Andreas */
    0x5454009B, /* The Warriors */
    0x545400A1, /* NBA 2K6 */
    0x545400A3, /* Grand Theft Auto: San Andreas */
    0x545400A4, /* Grand Theft Auto: San Andreas */
    0x545400A5, /* Grand Theft Auto: San Andreas */
    0x545400AE, /* NBA 2K7 */
    0x545400B0, /* Family Guy Video Game! */
    0x55530008, /* Far Cry Instincts */
    0x55530012, /* Dragon's Lair 3D: Return to the Lair */
    0x55530014, /* Rocky */
    0x55530036, /* 187 Ride or Die */
    0x5553003B, /* Prince of Persia: Warrior Within */
    0x5553003C, /* Brothers in Arms: Road to Hill 30 */
    0x55530041, /* Tom Clancy's Splinter Cell: Chaos Theory */
    0x5553004B, /* Cold Fear */
    0x55530058, /* Prince of Persia: The Two Thrones */
    0x5553005A, /* Brothers in Arms: Earned in Blood */
    0x5553005B, /* Brothers in Arms: Road to Hill 30 */
    0x5553005E, /* Tom Clancy's Splinter Cell: Double Agent */
    0x56550005, /* Buffy the Vampire Slayer: Chaos Bleeds */
    0x5655000E, /* Enclave */
    0x56550015, /* The Simpsons: Hit and Run */
    0x56550019, /* Men of Valor */
    0x5655001F, /* Crash Nitro Kart */
    0x56550026, /* The Chronicles of Riddick: Escape from Butcher Bay */
    0x56550031, /* Leisure Suit Larry: Magna Cum Laude */
    0x56550034, /* Spyro: A Hero's Tail */
    0x56550036, /* Crash Twinsanity */
    0x56550039, /* The Incredible Hulk: Ultimate Destruction */
    0x5655003F, /* Scarface */
    0x56550040, /* Men of Valor */
    0x56550042, /* 50 Cent: Bulletproof */
    0x5655004B, /* Ice Age 2: The Meltdown */
    0x57520001, /* Justice League Heroes */
    0x584D0002, /* Malice */
};

#endif
