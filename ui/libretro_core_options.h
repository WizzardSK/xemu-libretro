/*
 * xemu libretro core - Core Options v2
 *
 * The English texts are edited here; the translations in
 * libretro_core_options_intl.h come from Crowdin (intl/).
 *
 * Copyright (c) 2025
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef LIBRETRO_CORE_OPTIONS_H__
#define LIBRETRO_CORE_OPTIONS_H__

#include <stdlib.h>
#include <string.h>

#include "libretro.h"

#ifndef HAVE_NO_LANGEXTRA
#include "libretro_core_options_intl.h"
#endif

/*
 ********************************
 * VERSION: 2.0
 ********************************
 *
 * - 2.0: Add support for core options v2 interface
 * - 1.3: Move translations to libretro_core_options_intl.h
 *        - libretro_core_options_intl.h includes BOM and utf-8
 *          fix for MSVC 2010-2013
 *        - Added HAVE_NO_LANGEXTRA flag to disable translations
 *          on platforms/compilers without BOM support
 * - 1.2: Use core options v1 interface when
 *        RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION is >= 1
 *        (previously required RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION == 1)
 * - 1.1: Support generation of core options v0 retro_core_option_value
 *        arrays containing options with a single value
 * - 1.0: First commit
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
 ********************************
 * Core Option Definitions
 ********************************
*/

/* RETRO_LANGUAGE_ENGLISH */

/* Default language:
 * - All other languages must include the same keys and values
 * - Will be used as a fallback in the event that frontend language
 *   is not available
 * - Will be used as a fallback for any missing entries in
 *   frontend language definition
 * - Translations live in libretro_core_options_intl.h, which is
 *   generated from Crowdin - edit only the English texts here
 */

struct retro_core_option_v2_category option_cats_us[] = {
    {
        "system",
        "System (Restart)",
        "The machine itself: memory, network, boot and CPU. Taken when the content starts (Trim HDD on Close when it closes)."
    },
    {
        "video",
        "Video",
        "Configure video rendering settings."
    },
    {
        "audio",
        "Audio",
        "Configure audio emulation settings."
    },
    {
        "chihiro",
        "Sega Chihiro",
        "The Sega Chihiro arcade games: free play, the gun games' aim and the racing games' force feedback."
    },
    { NULL, NULL, NULL },
};

struct retro_core_option_v2_definition option_defs_us[] = {
    {
        "xemu_memory",
        "System Memory (MB)",
        NULL,
        "Amount of system RAM. 64 MB is standard; 128 MB is used by debug kits.",
        NULL,
        "system",
        {
            { "64",  "64 MB" },
            { "128", "128 MB" },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        "Network Backend",
        NULL,
        "Enable network support for Xbox games with LAN/System Link features. NAT backend provides basic connectivity.",
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      "NAT" },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        "Skip Boot Animation",
        NULL,
        "Skip the Xbox boot animation.",
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_hard_fpu",
        "Hardware FPU Emulation",
        NULL,
        "Use host FPU for x87 emulation. Faster but may have minor inaccuracies.",
        NULL,
        "system",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_cpu_boost",
        "CPU Boost",
        NULL,
        "Faster paths for the guest CPU and the audio processor: native SSE and a wider jump cache. Turn it off if a game misbehaves.",
        NULL,
        "system",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
    {
        "xemu_hdd_trim",
        "Trim HDD on Close",
        NULL,
        "When the game is closed, empties the hard disk's cache partitions X, Y and Z (games format them again when they need them) and rewrites the image without unused space, so the file shrinks. Needs as much free space as the image's data for a moment. Skipped while the image holds a savestate. Done when the game closes, not at its next start.",
        NULL,
        "system",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_renderer",
        "Graphics API (Restart)",
        NULL,
        "The renderer the emulated GPU is drawn with. Vulkan is the default; OpenGL is the fallback for drivers where Vulkan misbehaves. Takes effect after RetroArch is restarted. Android always uses Vulkan, macOS always OpenGL.",
        NULL,
        "video",
        {
            { "vulkan", "Vulkan" },
            { "opengl", "OpenGL" },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        "System Aspect Ratio (Restart)",
        NULL,
        "The display shape the console's video settings report to games, in place of the dashboard's setting. At 16:9, games that support widescreen run in widescreen; at 4:3 they run in 4:3. Set it to the shape of your display. Letterbox is the dashboard's 4:3 with widescreen games letterboxed. Dashboard keeps the dashboard's setting.",
        NULL,
        "video",
        {
            { "dashboard", "Dashboard" },
            { "4:3",       "4:3" },
            { "16:9",      "16:9" },
            { "letterbox", "Letterbox" },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        "Core Aspect Ratio",
        NULL,
        "The shape the picture is shown in. Best kept at Auto, which follows the game: 16:9 when the console is set to widescreen (System Aspect Ratio or the dashboard) and the game renders 16:9, 4:3 otherwise and on a Chihiro. 16:9 stretches a 4:3 game to widescreen.",
        NULL,
        "video",
        {
            { "auto", "Auto" },
            { "4:3",  "4:3" },
            { "16:9", "16:9" },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        "Internal Resolution Scale",
        NULL,
        "Scales the internal rendering resolution. Higher values improve quality but reduce performance.",
        NULL,
        "video",
        {
            { "1", "1x (640x480)" },
            { "2", "2x (1280x960)" },
            { "3", "3x (1920x1440)" },
            { "4", "4x (2560x1920)" },
            { "5", "5x (3200x2400)" },
            { "6", "6x (3840x2880)" },
            { "7", "7x (4480x3360)" },
            { "8", "8x (5120x3840)" },
            { "9", "9x (5760x4320)" },
            { "10", "10x (6400x4800)" },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        "AV Pack (Restart)",
        NULL,
        "Select the AV pack type. Affects available video modes.",
        NULL,
        "video",
        {
            { "hdtv",      "HDTV" },
            { "composite", "Composite" },
            { "svideo",    "S-Video" },
            { "scart",     "SCART" },
            { "vga",       "VGA" },
            { NULL, NULL },
        },
        "hdtv"
    },
    {
        "xemu_use_dsp",
        "APU DSP Emulation",
        NULL,
        "Enable DSP emulation for improved audio accuracy. May impact performance.",
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "disabled"
    },
    /* Defaults as standalone's (config_spec.yml: audio.use_dsp_jit,
     * audio.hrtf, audio.vp.num_workers) */
    {
        "xemu_dsp_jit",
        "DSP JIT",
        NULL,
        "Runs APU DSP Emulation's programs as compiled code instead of interpreting them: faster, as standalone's DSP JIT. Only does something with APU DSP Emulation on.",
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_hrtf",
        "HRTF",
        NULL,
        "Positions the 3D voices of games that use them with head-related transfer functions, as on the console, for headphones and stereo speakers.",
        NULL,
        "audio",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_vp_workers",
        "Voice Processor Threads (Restart)",
        NULL,
        "Threads the audio voice processor mixes the voices on. Auto uses one per CPU core.",
        NULL,
        "audio",
        {
            { "0", "Auto" },
            { "1", NULL },
            { "2", NULL },
            { "4", NULL },
            { "8", NULL },
            { NULL, NULL },
        },
        "0"
    },
    {
        "xemu_smooth_first_play",
        "Smooth First Play (Restart)",
        NULL,
        "Compiles the shaders a game is known to use while it boots, so the first minutes do not stutter while they are compiled. On OpenGL it keeps what it compiles in the shader cache, which is always on.",
        NULL,
        "video",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_audio_volume",
        "Audio Volume Limit (%)",
        NULL,
        "Limit Xbox audio output volume independently from RetroArch master volume.",
        NULL,
        "audio",
        {
            { "100", "100%" },
            { "80",  "80%" },
            { "60",  "60%" },
            { "40",  "40%" },
            { "20",  "20%" },
            { "0",   "Muted" },
            { NULL, NULL },
        },
        "100"
    },
    /* No Pipeline Libraries by default, unlike standalone, which uses all:
     * RalliSport Challenge 2 and Conker crash with them (NNshi), and the
     * dynamic states keep most of the speed; fewer still for a GPU that
     * crashes on one of those (Akrido) */
    {
        "xemu_vk_fast_paths",
        "Vulkan Fast Paths (Restart)",
        NULL,
        "The Vulkan features the renderer's fast paths use: pipeline libraries (pipelines compiled in parts, on a thread) and dynamic states. No Pipeline Libraries by default, as some games crash with them (RalliSport Challenge 2, Conker); All is standalone's.",
        NULL,
        "video",
        {
            { "all",      "All" },
            { "no_gpl",   "No Pipeline Libraries" },
            { "no_dyn",   "No Dynamic States" },
            { "none",     "None" },
            { NULL, NULL },
        },
        "no_gpl"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        "Free Play (Restart)",
        NULL,
        "Starts Sega Chihiro games in free play, without coins. Off, Select inserts a coin.",
        NULL,
        "chihiro",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* Analog Stick by default, unlike standalone, which aims with the mouse:
     * RetroArch is played with pads (NNshi) */
    {
        "xemu_chihiro_gun_aim",
        "Light Gun Aim",
        NULL,
        "What aims in House of the Dead III, Virtua Cop 3 and Ghost Squad. Mouse: the mouse (or RetroArch's light gun) aims, left button fires, right button is the gun's button (pump, change weapon), middle button the pedal or fire rate. Analog Stick: the left stick or D-pad aims, R2 fires, L2 is the gun's button, L the pedal or fire rate, R shoots off the screen.",
        NULL,
        "chihiro",
        {
            { "mouse", "Mouse" },
            { "stick", "Analog Stick" },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        "Crosshair",
        NULL,
        "Draws each player's aim over the picture, player 1 red, player 2 blue.",
        NULL,
        "chihiro",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 100% by default, unlike standalone, where it is off: the Xbox games
     * rumble as they are anyway (NNshi) */
    {
        "xemu_chihiro_ffb",
        "Force Feedback Rumble",
        NULL,
        "Gives a Chihiro racing game's force feedback (OutRun 2, Maximum Tune) as rumble on port 1's pad, at this strength.",
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  "25%" },
            { "50",  "50%" },
            { "75",  "75%" },
            { "100", "100%" },
            { "150", "150%" },
            { "200", "200%" },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};

struct retro_core_options_v2 options_us = {
   option_cats_us,
   option_defs_us
};

/*
 ********************************
 * Language Mapping
 ********************************
*/

#ifndef HAVE_NO_LANGEXTRA
struct retro_core_options_v2 *options_intl[RETRO_LANGUAGE_LAST] = {
   &options_us,       /* RETRO_LANGUAGE_ENGLISH */
   &options_ja,       /* RETRO_LANGUAGE_JAPANESE */
   &options_fr,       /* RETRO_LANGUAGE_FRENCH */
   &options_es,       /* RETRO_LANGUAGE_SPANISH */
   &options_de,       /* RETRO_LANGUAGE_GERMAN */
   &options_it,       /* RETRO_LANGUAGE_ITALIAN */
   &options_nl,       /* RETRO_LANGUAGE_DUTCH */
   &options_pt_br,    /* RETRO_LANGUAGE_PORTUGUESE_BRAZIL */
   &options_pt_pt,    /* RETRO_LANGUAGE_PORTUGUESE_PORTUGAL */
   &options_ru,       /* RETRO_LANGUAGE_RUSSIAN */
   &options_ko,       /* RETRO_LANGUAGE_KOREAN */
   &options_cht,      /* RETRO_LANGUAGE_CHINESE_TRADITIONAL */
   &options_chs,      /* RETRO_LANGUAGE_CHINESE_SIMPLIFIED */
   &options_eo,       /* RETRO_LANGUAGE_ESPERANTO */
   &options_pl,       /* RETRO_LANGUAGE_POLISH */
   &options_vn,       /* RETRO_LANGUAGE_VIETNAMESE */
   &options_ar,       /* RETRO_LANGUAGE_ARABIC */
   &options_el,       /* RETRO_LANGUAGE_GREEK */
   &options_tr,       /* RETRO_LANGUAGE_TURKISH */
   &options_sk,       /* RETRO_LANGUAGE_SLOVAK */
   &options_fa,       /* RETRO_LANGUAGE_PERSIAN */
   &options_he,       /* RETRO_LANGUAGE_HEBREW */
   &options_ast,      /* RETRO_LANGUAGE_ASTURIAN */
   &options_fi,       /* RETRO_LANGUAGE_FINNISH */
   &options_id,       /* RETRO_LANGUAGE_INDONESIAN */
   &options_sv,       /* RETRO_LANGUAGE_SWEDISH */
   &options_uk,       /* RETRO_LANGUAGE_UKRAINIAN */
   &options_cs,       /* RETRO_LANGUAGE_CZECH */
   &options_val,      /* RETRO_LANGUAGE_CATALAN_VALENCIA */
   &options_ca,       /* RETRO_LANGUAGE_CATALAN */
   &options_en,       /* RETRO_LANGUAGE_BRITISH_ENGLISH */
   &options_hu,       /* RETRO_LANGUAGE_HUNGARIAN */
   &options_be,       /* RETRO_LANGUAGE_BELARUSIAN */
   &options_gl,       /* RETRO_LANGUAGE_GALICIAN */
   &options_no,       /* RETRO_LANGUAGE_NORWEGIAN */
   &options_ga,       /* RETRO_LANGUAGE_IRISH */
};
#endif

/*
 ********************************
 * Functions
 ********************************
*/

/* Handles configuration/setting of core options.
 * Should be called as early as possible - ideally inside
 * retro_set_environment(), and no later than retro_load_game()
 * > We place the function body in the header to avoid the
 *   necessity of adding more .c files (i.e. want this to
 *   be as painless as possible for core devs)
 */

static inline void libretro_set_core_options(retro_environment_t environ_cb,
      bool *categories_supported)
{
   unsigned version  = 0;
#ifndef HAVE_NO_LANGEXTRA
   unsigned language = 0;
#endif

   if (!environ_cb || !categories_supported)
      return;

   *categories_supported = false;

   if (!environ_cb(RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION, &version))
      version = 0;

   if (version >= 2)
   {
#ifndef HAVE_NO_LANGEXTRA
      struct retro_core_options_v2_intl core_options_intl;

      core_options_intl.us    = &options_us;
      core_options_intl.local = NULL;

      if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
          (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH))
         core_options_intl.local = options_intl[language];

      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL,
            &core_options_intl);
#else
      *categories_supported = environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2,
            &options_us);
#endif
   }
   else
   {
      size_t i, j;
      size_t option_index              = 0;
      size_t num_options               = 0;
      struct retro_core_option_definition
            *option_v1_defs_us         = NULL;
#ifndef HAVE_NO_LANGEXTRA
      size_t num_options_intl          = 0;
      struct retro_core_option_v2_definition
            *option_defs_intl          = NULL;
      struct retro_core_option_definition
            *option_v1_defs_intl       = NULL;
      struct retro_core_options_intl
            core_options_v1_intl;
#endif
      struct retro_variable *variables = NULL;
      char **values_buf                = NULL;

      /* Determine total number of options */
      while (true)
      {
         if (option_defs_us[num_options].key)
            num_options++;
         else
            break;
      }

      if (version >= 1)
      {
         /* Allocate US array */
         option_v1_defs_us = (struct retro_core_option_definition *)
               calloc(num_options + 1, sizeof(struct retro_core_option_definition));

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            struct retro_core_option_v2_definition *option_def_us = &option_defs_us[i];
            struct retro_core_option_value *option_values         = option_def_us->values;
            struct retro_core_option_definition *option_v1_def_us = &option_v1_defs_us[i];
            struct retro_core_option_value *option_v1_values      = option_v1_def_us->values;

            option_v1_def_us->key           = option_def_us->key;
            option_v1_def_us->desc          = option_def_us->desc;
            option_v1_def_us->info          = option_def_us->info;
            option_v1_def_us->default_value = option_def_us->default_value;

            /* Values must be copied individually... */
            while (option_values->value)
            {
               option_v1_values->value = option_values->value;
               option_v1_values->label = option_values->label;

               option_values++;
               option_v1_values++;
            }
         }

#ifndef HAVE_NO_LANGEXTRA
         if (environ_cb(RETRO_ENVIRONMENT_GET_LANGUAGE, &language) &&
             (language < RETRO_LANGUAGE_LAST) && (language != RETRO_LANGUAGE_ENGLISH) &&
             options_intl[language])
            option_defs_intl = options_intl[language]->definitions;

         if (option_defs_intl)
         {
            /* Determine number of intl options */
            while (true)
            {
               if (option_defs_intl[num_options_intl].key)
                  num_options_intl++;
               else
                  break;
            }

            /* Allocate intl array */
            option_v1_defs_intl = (struct retro_core_option_definition *)
                  calloc(num_options_intl + 1, sizeof(struct retro_core_option_definition));

            /* Copy parameters from option_defs_intl array */
            for (i = 0; i < num_options_intl; i++)
            {
               struct retro_core_option_v2_definition *option_def_intl = &option_defs_intl[i];
               struct retro_core_option_value *option_values           = option_def_intl->values;
               struct retro_core_option_definition *option_v1_def_intl = &option_v1_defs_intl[i];
               struct retro_core_option_value *option_v1_values        = option_v1_def_intl->values;

               option_v1_def_intl->key           = option_def_intl->key;
               option_v1_def_intl->desc          = option_def_intl->desc;
               option_v1_def_intl->info          = option_def_intl->info;
               option_v1_def_intl->default_value = option_def_intl->default_value;

               /* Values must be copied individually... */
               while (option_values->value)
               {
                  option_v1_values->value = option_values->value;
                  option_v1_values->label = option_values->label;

                  option_values++;
                  option_v1_values++;
               }
            }
         }

         core_options_v1_intl.us    = option_v1_defs_us;
         core_options_v1_intl.local = option_v1_defs_intl;

         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS_INTL, &core_options_v1_intl);
#else
         environ_cb(RETRO_ENVIRONMENT_SET_CORE_OPTIONS, option_v1_defs_us);
#endif
      }
      else
      {
         /* Allocate arrays */
         variables  = (struct retro_variable *)calloc(num_options + 1,
               sizeof(struct retro_variable));
         values_buf = (char **)calloc(num_options, sizeof(char *));

         if (!variables || !values_buf)
            goto error;

         /* Copy parameters from option_defs_us array */
         for (i = 0; i < num_options; i++)
         {
            const char *key                        = option_defs_us[i].key;
            const char *desc                       = option_defs_us[i].desc;
            const char *default_value              = option_defs_us[i].default_value;
            struct retro_core_option_value *values = option_defs_us[i].values;
            size_t buf_len                         = 3;
            size_t default_index                   = 0;

            values_buf[i] = NULL;

            if (desc)
            {
               size_t num_values = 0;

               /* Determine number of values */
               while (true)
               {
                  if (values[num_values].value)
                  {
                     /* Check if this is the default value */
                     if (default_value)
                        if (strcmp(values[num_values].value, default_value) == 0)
                           default_index = num_values;

                     buf_len += strlen(values[num_values].value);
                     num_values++;
                  }
                  else
                     break;
               }

               /* Build values string */
               if (num_values > 0)
               {
                  buf_len += num_values - 1;
                  buf_len += strlen(desc);

                  values_buf[i] = (char *)calloc(buf_len, sizeof(char));
                  if (!values_buf[i])
                     goto error;

                  strcpy(values_buf[i], desc);
                  strcat(values_buf[i], "; ");

                  /* Default value goes first */
                  strcat(values_buf[i], values[default_index].value);

                  /* Add remaining values */
                  for (j = 0; j < num_values; j++)
                  {
                     if (j != default_index)
                     {
                        strcat(values_buf[i], "|");
                        strcat(values_buf[i], values[j].value);
                     }
                  }
               }
            }

            variables[option_index].key   = key;
            variables[option_index].value = values_buf[i];
            option_index++;
         }

         /* Set variables */
         environ_cb(RETRO_ENVIRONMENT_SET_VARIABLES, variables);
      }

error:
      /* Clean up */

      if (option_v1_defs_us)
      {
         free(option_v1_defs_us);
         option_v1_defs_us = NULL;
      }

#ifndef HAVE_NO_LANGEXTRA
      if (option_v1_defs_intl)
      {
         free(option_v1_defs_intl);
         option_v1_defs_intl = NULL;
      }
#endif

      if (values_buf)
      {
         for (i = 0; i < num_options; i++)
         {
            if (values_buf[i])
            {
               free(values_buf[i]);
               values_buf[i] = NULL;
            }
         }

         free(values_buf);
         values_buf = NULL;
      }

      if (variables)
      {
         free(variables);
         variables = NULL;
      }
   }
}

#ifdef __cplusplus
}
#endif

#endif
