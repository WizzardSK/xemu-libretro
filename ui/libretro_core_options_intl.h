#ifndef LIBRETRO_CORE_OPTIONS_INTL_H__
#define LIBRETRO_CORE_OPTIONS_INTL_H__

#if defined(_MSC_VER) && (_MSC_VER >= 1500 && _MSC_VER < 1900)
/* https://support.microsoft.com/en-us/kb/980263 */
#pragma execution_character_set("utf-8")
#pragma warning(disable:4566)
#endif

#include "libretro.h"

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
/* RETRO_LANGUAGE_AR */

#define CATEGORY_SYSTEM_LABEL_AR NULL
#define CATEGORY_SYSTEM_INFO_0_AR NULL
#define CATEGORY_VIDEO_LABEL_AR "الفيديو"
#define CATEGORY_VIDEO_INFO_0_AR NULL
#define CATEGORY_AUDIO_LABEL_AR "الصوت"
#define CATEGORY_AUDIO_INFO_0_AR NULL
#define CATEGORY_CONTROLS_LABEL_AR "التحكم"
#define CATEGORY_CONTROLS_INFO_0_AR NULL
#define CATEGORY_CHIHIRO_LABEL_AR NULL
#define CATEGORY_CHIHIRO_INFO_0_AR NULL
#define XEMU_MEMORY_LABEL_AR NULL
#define XEMU_MEMORY_INFO_0_AR NULL
#define OPTION_VAL_64_AR NULL
#define OPTION_VAL_128_AR NULL
#define XEMU_NETWORK_BACKEND_LABEL_AR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_AR NULL
#define OPTION_VAL_NAT_AR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_AR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_AR NULL
#define XEMU_HARD_FPU_LABEL_AR NULL
#define XEMU_HARD_FPU_INFO_0_AR NULL
#define XEMU_CPU_BOOST_LABEL_AR NULL
#define XEMU_CPU_BOOST_INFO_0_AR NULL
#define XEMU_HDD_TRIM_LABEL_AR NULL
#define XEMU_HDD_TRIM_INFO_0_AR NULL
#define XEMU_RENDERER_LABEL_AR NULL
#define XEMU_RENDERER_INFO_0_AR NULL
#define OPTION_VAL_VULKAN_AR NULL
#define OPTION_VAL_OPENGL_AR NULL
#define XEMU_VIDEO_ASPECT_LABEL_AR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_AR NULL
#define OPTION_VAL_DASHBOARD_AR NULL
#define OPTION_VAL_4_3_AR NULL
#define OPTION_VAL_16_9_AR NULL
#define OPTION_VAL_LETTERBOX_AR NULL
#define XEMU_ASPECT_RATIO_LABEL_AR NULL
#define XEMU_ASPECT_RATIO_INFO_0_AR NULL
#define OPTION_VAL_AUTO_AR "تلقائي"
#define XEMU_SURFACE_SCALE_LABEL_AR NULL
#define XEMU_SURFACE_SCALE_INFO_0_AR NULL
#define OPTION_VAL_1_AR NULL
#define OPTION_VAL_2_AR NULL
#define OPTION_VAL_3_AR NULL
#define OPTION_VAL_4_AR NULL
#define OPTION_VAL_5_AR NULL
#define OPTION_VAL_6_AR NULL
#define OPTION_VAL_7_AR NULL
#define OPTION_VAL_8_AR NULL
#define OPTION_VAL_9_AR NULL
#define OPTION_VAL_10_AR NULL
#define XEMU_AVPACK_LABEL_AR NULL
#define XEMU_AVPACK_INFO_0_AR NULL
#define OPTION_VAL_HDTV_AR NULL
#define OPTION_VAL_COMPOSITE_AR NULL
#define OPTION_VAL_SVIDEO_AR NULL
#define OPTION_VAL_SCART_AR NULL
#define OPTION_VAL_VGA_AR NULL
#define XEMU_AUDIO_THREAD_LABEL_AR NULL
#define XEMU_AUDIO_THREAD_INFO_0_AR NULL
#define XEMU_USE_DSP_LABEL_AR NULL
#define XEMU_USE_DSP_INFO_0_AR NULL
#define XEMU_DSP_JIT_LABEL_AR NULL
#define XEMU_DSP_JIT_INFO_0_AR NULL
#define XEMU_HRTF_LABEL_AR NULL
#define XEMU_HRTF_INFO_0_AR NULL
#define XEMU_VP_WORKERS_LABEL_AR NULL
#define XEMU_VP_WORKERS_INFO_0_AR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_AR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_AR NULL
#define XEMU_AUDIO_VOLUME_LABEL_AR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_AR NULL
#define OPTION_VAL_100_AR NULL
#define OPTION_VAL_80_AR NULL
#define OPTION_VAL_60_AR NULL
#define OPTION_VAL_40_AR NULL
#define OPTION_VAL_20_AR NULL
#define OPTION_VAL_0_AR NULL
#define XEMU_VK_FAST_PATHS_LABEL_AR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_AR NULL
#define OPTION_VAL_ALL_AR "الكل"
#define OPTION_VAL_NO_GPL_AR NULL
#define OPTION_VAL_NO_DYN_AR NULL
#define OPTION_VAL_NONE_AR "لاشيء"
#define XEMU_RUMBLE_P1_LABEL_AR NULL
#define XEMU_RUMBLE_P1_INFO_0_AR NULL
#define XEMU_RUMBLE_P2_LABEL_AR NULL
#define XEMU_RUMBLE_P2_INFO_0_AR NULL
#define XEMU_DEADZONE_P1_LABEL_AR NULL
#define XEMU_DEADZONE_P1_INFO_0_AR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_AR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_AR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_AR NULL
#define OPTION_VAL_15_AR NULL
#define OPTION_VAL_25_AR NULL
#define OPTION_VAL_30_AR NULL
#define XEMU_DEADZONE_P2_LABEL_AR NULL
#define XEMU_DEADZONE_P2_INFO_0_AR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_AR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_AR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_AR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_AR NULL
#define OPTION_VAL_MOUSE_AR NULL
#define OPTION_VAL_STICK_AR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_AR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_AR NULL
#define XEMU_CHIHIRO_FFB_LABEL_AR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_AR NULL
#define OPTION_VAL_50_AR NULL
#define OPTION_VAL_75_AR NULL
#define OPTION_VAL_150_AR NULL
#define OPTION_VAL_200_AR NULL

struct retro_core_option_v2_category option_cats_ar[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_AR,
        CATEGORY_SYSTEM_INFO_0_AR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_AR,
        CATEGORY_VIDEO_INFO_0_AR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_AR,
        CATEGORY_AUDIO_INFO_0_AR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_AR,
        CATEGORY_CONTROLS_INFO_0_AR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_AR,
        CATEGORY_CHIHIRO_INFO_0_AR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ar[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_AR,
        NULL,
        XEMU_MEMORY_INFO_0_AR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_AR },
            { "128", OPTION_VAL_128_AR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_AR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_AR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_AR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_AR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_AR,
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
        XEMU_HARD_FPU_LABEL_AR,
        NULL,
        XEMU_HARD_FPU_INFO_0_AR,
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
        XEMU_CPU_BOOST_LABEL_AR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_AR,
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
        XEMU_HDD_TRIM_LABEL_AR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_AR,
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
        XEMU_RENDERER_LABEL_AR,
        NULL,
        XEMU_RENDERER_INFO_0_AR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_AR },
            { "opengl", OPTION_VAL_OPENGL_AR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_AR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_AR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_AR },
            { "4:3",       OPTION_VAL_4_3_AR },
            { "16:9",      OPTION_VAL_16_9_AR },
            { "letterbox", OPTION_VAL_LETTERBOX_AR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_AR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_AR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_AR },
            { "4:3",  OPTION_VAL_4_3_AR },
            { "16:9", OPTION_VAL_16_9_AR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_AR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_AR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_AR },
            { "2", OPTION_VAL_2_AR },
            { "3", OPTION_VAL_3_AR },
            { "4", OPTION_VAL_4_AR },
            { "5", OPTION_VAL_5_AR },
            { "6", OPTION_VAL_6_AR },
            { "7", OPTION_VAL_7_AR },
            { "8", OPTION_VAL_8_AR },
            { "9", OPTION_VAL_9_AR },
            { "10", OPTION_VAL_10_AR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_AR,
        NULL,
        XEMU_AVPACK_INFO_0_AR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_AR },
            { "composite", OPTION_VAL_COMPOSITE_AR },
            { "svideo",    OPTION_VAL_SVIDEO_AR },
            { "scart",     OPTION_VAL_SCART_AR },
            { "vga",       OPTION_VAL_VGA_AR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_AR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_AR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_AR,
        NULL,
        XEMU_USE_DSP_INFO_0_AR,
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
        XEMU_DSP_JIT_LABEL_AR,
        NULL,
        XEMU_DSP_JIT_INFO_0_AR,
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
        XEMU_HRTF_LABEL_AR,
        NULL,
        XEMU_HRTF_INFO_0_AR,
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
        XEMU_VP_WORKERS_LABEL_AR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_AR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_AR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_AR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_AR,
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
        XEMU_AUDIO_VOLUME_LABEL_AR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_AR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_AR },
            { "80",  OPTION_VAL_80_AR },
            { "60",  OPTION_VAL_60_AR },
            { "40",  OPTION_VAL_40_AR },
            { "20",  OPTION_VAL_20_AR },
            { "0",   OPTION_VAL_0_AR },
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
        XEMU_VK_FAST_PATHS_LABEL_AR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_AR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_AR },
            { "no_gpl",   OPTION_VAL_NO_GPL_AR },
            { "no_dyn",   OPTION_VAL_NO_DYN_AR },
            { "none",     OPTION_VAL_NONE_AR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_AR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_AR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_AR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_AR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_AR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_AR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_AR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_AR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_AR },
            { "15", OPTION_VAL_15_AR },
            { "20", OPTION_VAL_20_AR },
            { "25", OPTION_VAL_25_AR },
            { "30", OPTION_VAL_30_AR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_AR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_AR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_AR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_AR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_AR },
            { "15", OPTION_VAL_15_AR },
            { "20", OPTION_VAL_20_AR },
            { "25", OPTION_VAL_25_AR },
            { "30", OPTION_VAL_30_AR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_AR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_AR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_AR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_AR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_AR },
            { "stick", OPTION_VAL_STICK_AR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_AR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_AR,
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
        XEMU_CHIHIRO_FFB_LABEL_AR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_AR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_AR },
            { "50",  OPTION_VAL_50_AR },
            { "75",  OPTION_VAL_75_AR },
            { "100", OPTION_VAL_100_AR },
            { "150", OPTION_VAL_150_AR },
            { "200", OPTION_VAL_200_AR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ar = {
   option_cats_ar,
   option_defs_ar
};

/* RETRO_LANGUAGE_AST */

#define CATEGORY_SYSTEM_LABEL_AST NULL
#define CATEGORY_SYSTEM_INFO_0_AST NULL
#define CATEGORY_VIDEO_LABEL_AST "Videu"
#define CATEGORY_VIDEO_INFO_0_AST NULL
#define CATEGORY_AUDIO_LABEL_AST "Audiu"
#define CATEGORY_AUDIO_INFO_0_AST NULL
#define CATEGORY_CONTROLS_LABEL_AST NULL
#define CATEGORY_CONTROLS_INFO_0_AST NULL
#define CATEGORY_CHIHIRO_LABEL_AST NULL
#define CATEGORY_CHIHIRO_INFO_0_AST NULL
#define XEMU_MEMORY_LABEL_AST NULL
#define XEMU_MEMORY_INFO_0_AST NULL
#define OPTION_VAL_64_AST NULL
#define OPTION_VAL_128_AST NULL
#define XEMU_NETWORK_BACKEND_LABEL_AST NULL
#define XEMU_NETWORK_BACKEND_INFO_0_AST NULL
#define OPTION_VAL_NAT_AST NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_AST NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_AST NULL
#define XEMU_HARD_FPU_LABEL_AST NULL
#define XEMU_HARD_FPU_INFO_0_AST NULL
#define XEMU_CPU_BOOST_LABEL_AST NULL
#define XEMU_CPU_BOOST_INFO_0_AST NULL
#define XEMU_HDD_TRIM_LABEL_AST NULL
#define XEMU_HDD_TRIM_INFO_0_AST NULL
#define XEMU_RENDERER_LABEL_AST NULL
#define XEMU_RENDERER_INFO_0_AST NULL
#define OPTION_VAL_VULKAN_AST NULL
#define OPTION_VAL_OPENGL_AST NULL
#define XEMU_VIDEO_ASPECT_LABEL_AST NULL
#define XEMU_VIDEO_ASPECT_INFO_0_AST NULL
#define OPTION_VAL_DASHBOARD_AST NULL
#define OPTION_VAL_4_3_AST NULL
#define OPTION_VAL_16_9_AST NULL
#define OPTION_VAL_LETTERBOX_AST NULL
#define XEMU_ASPECT_RATIO_LABEL_AST "Proporción d'aspeutu del nucleu"
#define XEMU_ASPECT_RATIO_INFO_0_AST NULL
#define OPTION_VAL_AUTO_AST NULL
#define XEMU_SURFACE_SCALE_LABEL_AST NULL
#define XEMU_SURFACE_SCALE_INFO_0_AST NULL
#define OPTION_VAL_1_AST NULL
#define OPTION_VAL_2_AST NULL
#define OPTION_VAL_3_AST NULL
#define OPTION_VAL_4_AST NULL
#define OPTION_VAL_5_AST NULL
#define OPTION_VAL_6_AST NULL
#define OPTION_VAL_7_AST NULL
#define OPTION_VAL_8_AST NULL
#define OPTION_VAL_9_AST NULL
#define OPTION_VAL_10_AST NULL
#define XEMU_AVPACK_LABEL_AST NULL
#define XEMU_AVPACK_INFO_0_AST NULL
#define OPTION_VAL_HDTV_AST NULL
#define OPTION_VAL_COMPOSITE_AST NULL
#define OPTION_VAL_SVIDEO_AST NULL
#define OPTION_VAL_SCART_AST NULL
#define OPTION_VAL_VGA_AST NULL
#define XEMU_AUDIO_THREAD_LABEL_AST NULL
#define XEMU_AUDIO_THREAD_INFO_0_AST NULL
#define XEMU_USE_DSP_LABEL_AST NULL
#define XEMU_USE_DSP_INFO_0_AST NULL
#define XEMU_DSP_JIT_LABEL_AST NULL
#define XEMU_DSP_JIT_INFO_0_AST NULL
#define XEMU_HRTF_LABEL_AST NULL
#define XEMU_HRTF_INFO_0_AST NULL
#define XEMU_VP_WORKERS_LABEL_AST NULL
#define XEMU_VP_WORKERS_INFO_0_AST NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_AST NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_AST NULL
#define XEMU_AUDIO_VOLUME_LABEL_AST NULL
#define XEMU_AUDIO_VOLUME_INFO_0_AST NULL
#define OPTION_VAL_100_AST NULL
#define OPTION_VAL_80_AST NULL
#define OPTION_VAL_60_AST NULL
#define OPTION_VAL_40_AST NULL
#define OPTION_VAL_20_AST NULL
#define OPTION_VAL_0_AST NULL
#define XEMU_VK_FAST_PATHS_LABEL_AST NULL
#define XEMU_VK_FAST_PATHS_INFO_0_AST NULL
#define OPTION_VAL_ALL_AST NULL
#define OPTION_VAL_NO_GPL_AST NULL
#define OPTION_VAL_NO_DYN_AST NULL
#define OPTION_VAL_NONE_AST NULL
#define XEMU_RUMBLE_P1_LABEL_AST NULL
#define XEMU_RUMBLE_P1_INFO_0_AST NULL
#define XEMU_RUMBLE_P2_LABEL_AST NULL
#define XEMU_RUMBLE_P2_INFO_0_AST NULL
#define XEMU_DEADZONE_P1_LABEL_AST NULL
#define XEMU_DEADZONE_P1_INFO_0_AST NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_AST NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_AST NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_AST NULL
#define OPTION_VAL_15_AST NULL
#define OPTION_VAL_25_AST NULL
#define OPTION_VAL_30_AST NULL
#define XEMU_DEADZONE_P2_LABEL_AST NULL
#define XEMU_DEADZONE_P2_INFO_0_AST NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_AST NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_AST NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_AST NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_AST NULL
#define OPTION_VAL_MOUSE_AST "Mur"
#define OPTION_VAL_STICK_AST NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_AST NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_AST NULL
#define XEMU_CHIHIRO_FFB_LABEL_AST NULL
#define XEMU_CHIHIRO_FFB_INFO_0_AST NULL
#define OPTION_VAL_50_AST NULL
#define OPTION_VAL_75_AST NULL
#define OPTION_VAL_150_AST NULL
#define OPTION_VAL_200_AST NULL

struct retro_core_option_v2_category option_cats_ast[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_AST,
        CATEGORY_SYSTEM_INFO_0_AST
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_AST,
        CATEGORY_VIDEO_INFO_0_AST
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_AST,
        CATEGORY_AUDIO_INFO_0_AST
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_AST,
        CATEGORY_CONTROLS_INFO_0_AST
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_AST,
        CATEGORY_CHIHIRO_INFO_0_AST
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ast[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_AST,
        NULL,
        XEMU_MEMORY_INFO_0_AST,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_AST },
            { "128", OPTION_VAL_128_AST },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_AST,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_AST,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_AST },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_AST,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_AST,
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
        XEMU_HARD_FPU_LABEL_AST,
        NULL,
        XEMU_HARD_FPU_INFO_0_AST,
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
        XEMU_CPU_BOOST_LABEL_AST,
        NULL,
        XEMU_CPU_BOOST_INFO_0_AST,
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
        XEMU_HDD_TRIM_LABEL_AST,
        NULL,
        XEMU_HDD_TRIM_INFO_0_AST,
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
        XEMU_RENDERER_LABEL_AST,
        NULL,
        XEMU_RENDERER_INFO_0_AST,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_AST },
            { "opengl", OPTION_VAL_OPENGL_AST },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_AST,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_AST,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_AST },
            { "4:3",       OPTION_VAL_4_3_AST },
            { "16:9",      OPTION_VAL_16_9_AST },
            { "letterbox", OPTION_VAL_LETTERBOX_AST },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_AST,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_AST,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_AST },
            { "4:3",  OPTION_VAL_4_3_AST },
            { "16:9", OPTION_VAL_16_9_AST },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_AST,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_AST,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_AST },
            { "2", OPTION_VAL_2_AST },
            { "3", OPTION_VAL_3_AST },
            { "4", OPTION_VAL_4_AST },
            { "5", OPTION_VAL_5_AST },
            { "6", OPTION_VAL_6_AST },
            { "7", OPTION_VAL_7_AST },
            { "8", OPTION_VAL_8_AST },
            { "9", OPTION_VAL_9_AST },
            { "10", OPTION_VAL_10_AST },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_AST,
        NULL,
        XEMU_AVPACK_INFO_0_AST,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_AST },
            { "composite", OPTION_VAL_COMPOSITE_AST },
            { "svideo",    OPTION_VAL_SVIDEO_AST },
            { "scart",     OPTION_VAL_SCART_AST },
            { "vga",       OPTION_VAL_VGA_AST },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_AST,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_AST,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_AST,
        NULL,
        XEMU_USE_DSP_INFO_0_AST,
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
        XEMU_DSP_JIT_LABEL_AST,
        NULL,
        XEMU_DSP_JIT_INFO_0_AST,
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
        XEMU_HRTF_LABEL_AST,
        NULL,
        XEMU_HRTF_INFO_0_AST,
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
        XEMU_VP_WORKERS_LABEL_AST,
        NULL,
        XEMU_VP_WORKERS_INFO_0_AST,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_AST },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_AST,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_AST,
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
        XEMU_AUDIO_VOLUME_LABEL_AST,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_AST,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_AST },
            { "80",  OPTION_VAL_80_AST },
            { "60",  OPTION_VAL_60_AST },
            { "40",  OPTION_VAL_40_AST },
            { "20",  OPTION_VAL_20_AST },
            { "0",   OPTION_VAL_0_AST },
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
        XEMU_VK_FAST_PATHS_LABEL_AST,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_AST,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_AST },
            { "no_gpl",   OPTION_VAL_NO_GPL_AST },
            { "no_dyn",   OPTION_VAL_NO_DYN_AST },
            { "none",     OPTION_VAL_NONE_AST },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_AST,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_AST,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_AST,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_AST,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_AST,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_AST,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_AST },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_AST },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_AST },
            { "15", OPTION_VAL_15_AST },
            { "20", OPTION_VAL_20_AST },
            { "25", OPTION_VAL_25_AST },
            { "30", OPTION_VAL_30_AST },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_AST,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_AST,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_AST },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_AST },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_AST },
            { "15", OPTION_VAL_15_AST },
            { "20", OPTION_VAL_20_AST },
            { "25", OPTION_VAL_25_AST },
            { "30", OPTION_VAL_30_AST },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_AST,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_AST,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_AST,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_AST,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_AST },
            { "stick", OPTION_VAL_STICK_AST },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_AST,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_AST,
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
        XEMU_CHIHIRO_FFB_LABEL_AST,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_AST,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_AST },
            { "50",  OPTION_VAL_50_AST },
            { "75",  OPTION_VAL_75_AST },
            { "100", OPTION_VAL_100_AST },
            { "150", OPTION_VAL_150_AST },
            { "200", OPTION_VAL_200_AST },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ast = {
   option_cats_ast,
   option_defs_ast
};

/* RETRO_LANGUAGE_BE */

#define CATEGORY_SYSTEM_LABEL_BE NULL
#define CATEGORY_SYSTEM_INFO_0_BE NULL
#define CATEGORY_VIDEO_LABEL_BE "Відэа"
#define CATEGORY_VIDEO_INFO_0_BE NULL
#define CATEGORY_AUDIO_LABEL_BE "Аўдыя"
#define CATEGORY_AUDIO_INFO_0_BE NULL
#define CATEGORY_CONTROLS_LABEL_BE "Кіраванне"
#define CATEGORY_CONTROLS_INFO_0_BE NULL
#define CATEGORY_CHIHIRO_LABEL_BE NULL
#define CATEGORY_CHIHIRO_INFO_0_BE NULL
#define XEMU_MEMORY_LABEL_BE NULL
#define XEMU_MEMORY_INFO_0_BE NULL
#define OPTION_VAL_64_BE "64 МБ"
#define OPTION_VAL_128_BE "128 МБ"
#define XEMU_NETWORK_BACKEND_LABEL_BE NULL
#define XEMU_NETWORK_BACKEND_INFO_0_BE NULL
#define OPTION_VAL_NAT_BE NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_BE NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_BE NULL
#define XEMU_HARD_FPU_LABEL_BE NULL
#define XEMU_HARD_FPU_INFO_0_BE NULL
#define XEMU_CPU_BOOST_LABEL_BE NULL
#define XEMU_CPU_BOOST_INFO_0_BE NULL
#define XEMU_HDD_TRIM_LABEL_BE NULL
#define XEMU_HDD_TRIM_INFO_0_BE NULL
#define XEMU_RENDERER_LABEL_BE NULL
#define XEMU_RENDERER_INFO_0_BE NULL
#define OPTION_VAL_VULKAN_BE NULL
#define OPTION_VAL_OPENGL_BE NULL
#define XEMU_VIDEO_ASPECT_LABEL_BE NULL
#define XEMU_VIDEO_ASPECT_INFO_0_BE NULL
#define OPTION_VAL_DASHBOARD_BE NULL
#define OPTION_VAL_4_3_BE NULL
#define OPTION_VAL_16_9_BE NULL
#define OPTION_VAL_LETTERBOX_BE NULL
#define XEMU_ASPECT_RATIO_LABEL_BE "Суадносіны бакоў ядра"
#define XEMU_ASPECT_RATIO_INFO_0_BE NULL
#define OPTION_VAL_AUTO_BE "Аўта"
#define XEMU_SURFACE_SCALE_LABEL_BE NULL
#define XEMU_SURFACE_SCALE_INFO_0_BE NULL
#define OPTION_VAL_1_BE NULL
#define OPTION_VAL_2_BE NULL
#define OPTION_VAL_3_BE NULL
#define OPTION_VAL_4_BE NULL
#define OPTION_VAL_5_BE NULL
#define OPTION_VAL_6_BE NULL
#define OPTION_VAL_7_BE NULL
#define OPTION_VAL_8_BE NULL
#define OPTION_VAL_9_BE NULL
#define OPTION_VAL_10_BE NULL
#define XEMU_AVPACK_LABEL_BE NULL
#define XEMU_AVPACK_INFO_0_BE NULL
#define OPTION_VAL_HDTV_BE NULL
#define OPTION_VAL_COMPOSITE_BE "Кампазітны"
#define OPTION_VAL_SVIDEO_BE NULL
#define OPTION_VAL_SCART_BE NULL
#define OPTION_VAL_VGA_BE NULL
#define XEMU_AUDIO_THREAD_LABEL_BE NULL
#define XEMU_AUDIO_THREAD_INFO_0_BE NULL
#define XEMU_USE_DSP_LABEL_BE NULL
#define XEMU_USE_DSP_INFO_0_BE NULL
#define XEMU_DSP_JIT_LABEL_BE NULL
#define XEMU_DSP_JIT_INFO_0_BE NULL
#define XEMU_HRTF_LABEL_BE NULL
#define XEMU_HRTF_INFO_0_BE NULL
#define XEMU_VP_WORKERS_LABEL_BE NULL
#define XEMU_VP_WORKERS_INFO_0_BE NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_BE NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_BE NULL
#define XEMU_AUDIO_VOLUME_LABEL_BE NULL
#define XEMU_AUDIO_VOLUME_INFO_0_BE NULL
#define OPTION_VAL_100_BE "100 %"
#define OPTION_VAL_80_BE "80 %"
#define OPTION_VAL_60_BE "60 %"
#define OPTION_VAL_40_BE "40 %"
#define OPTION_VAL_20_BE "20 %"
#define OPTION_VAL_0_BE NULL
#define XEMU_VK_FAST_PATHS_LABEL_BE NULL
#define XEMU_VK_FAST_PATHS_INFO_0_BE NULL
#define OPTION_VAL_ALL_BE "Усе"
#define OPTION_VAL_NO_GPL_BE NULL
#define OPTION_VAL_NO_DYN_BE NULL
#define OPTION_VAL_NONE_BE "Няма"
#define XEMU_RUMBLE_P1_LABEL_BE NULL
#define XEMU_RUMBLE_P1_INFO_0_BE NULL
#define XEMU_RUMBLE_P2_LABEL_BE NULL
#define XEMU_RUMBLE_P2_INFO_0_BE NULL
#define XEMU_DEADZONE_P1_LABEL_BE NULL
#define XEMU_DEADZONE_P1_INFO_0_BE NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_BE NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_BE NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_BE NULL
#define OPTION_VAL_15_BE "15 %"
#define OPTION_VAL_25_BE NULL
#define OPTION_VAL_30_BE "30 %"
#define XEMU_DEADZONE_P2_LABEL_BE NULL
#define XEMU_DEADZONE_P2_INFO_0_BE NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_BE NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_BE NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_BE NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_BE NULL
#define OPTION_VAL_MOUSE_BE "Мыш"
#define OPTION_VAL_STICK_BE NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_BE NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_BE NULL
#define XEMU_CHIHIRO_FFB_LABEL_BE NULL
#define XEMU_CHIHIRO_FFB_INFO_0_BE NULL
#define OPTION_VAL_50_BE "50 %"
#define OPTION_VAL_75_BE "75 %"
#define OPTION_VAL_150_BE "150 %"
#define OPTION_VAL_200_BE "200 %"

struct retro_core_option_v2_category option_cats_be[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_BE,
        CATEGORY_SYSTEM_INFO_0_BE
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_BE,
        CATEGORY_VIDEO_INFO_0_BE
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_BE,
        CATEGORY_AUDIO_INFO_0_BE
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_BE,
        CATEGORY_CONTROLS_INFO_0_BE
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_BE,
        CATEGORY_CHIHIRO_INFO_0_BE
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_be[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_BE,
        NULL,
        XEMU_MEMORY_INFO_0_BE,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_BE },
            { "128", OPTION_VAL_128_BE },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_BE,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_BE,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_BE },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_BE,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_BE,
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
        XEMU_HARD_FPU_LABEL_BE,
        NULL,
        XEMU_HARD_FPU_INFO_0_BE,
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
        XEMU_CPU_BOOST_LABEL_BE,
        NULL,
        XEMU_CPU_BOOST_INFO_0_BE,
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
        XEMU_HDD_TRIM_LABEL_BE,
        NULL,
        XEMU_HDD_TRIM_INFO_0_BE,
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
        XEMU_RENDERER_LABEL_BE,
        NULL,
        XEMU_RENDERER_INFO_0_BE,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_BE },
            { "opengl", OPTION_VAL_OPENGL_BE },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_BE,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_BE,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_BE },
            { "4:3",       OPTION_VAL_4_3_BE },
            { "16:9",      OPTION_VAL_16_9_BE },
            { "letterbox", OPTION_VAL_LETTERBOX_BE },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_BE,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_BE,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_BE },
            { "4:3",  OPTION_VAL_4_3_BE },
            { "16:9", OPTION_VAL_16_9_BE },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_BE,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_BE,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_BE },
            { "2", OPTION_VAL_2_BE },
            { "3", OPTION_VAL_3_BE },
            { "4", OPTION_VAL_4_BE },
            { "5", OPTION_VAL_5_BE },
            { "6", OPTION_VAL_6_BE },
            { "7", OPTION_VAL_7_BE },
            { "8", OPTION_VAL_8_BE },
            { "9", OPTION_VAL_9_BE },
            { "10", OPTION_VAL_10_BE },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_BE,
        NULL,
        XEMU_AVPACK_INFO_0_BE,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_BE },
            { "composite", OPTION_VAL_COMPOSITE_BE },
            { "svideo",    OPTION_VAL_SVIDEO_BE },
            { "scart",     OPTION_VAL_SCART_BE },
            { "vga",       OPTION_VAL_VGA_BE },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_BE,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_BE,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_BE,
        NULL,
        XEMU_USE_DSP_INFO_0_BE,
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
        XEMU_DSP_JIT_LABEL_BE,
        NULL,
        XEMU_DSP_JIT_INFO_0_BE,
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
        XEMU_HRTF_LABEL_BE,
        NULL,
        XEMU_HRTF_INFO_0_BE,
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
        XEMU_VP_WORKERS_LABEL_BE,
        NULL,
        XEMU_VP_WORKERS_INFO_0_BE,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_BE },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_BE,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_BE,
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
        XEMU_AUDIO_VOLUME_LABEL_BE,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_BE,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_BE },
            { "80",  OPTION_VAL_80_BE },
            { "60",  OPTION_VAL_60_BE },
            { "40",  OPTION_VAL_40_BE },
            { "20",  OPTION_VAL_20_BE },
            { "0",   OPTION_VAL_0_BE },
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
        XEMU_VK_FAST_PATHS_LABEL_BE,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_BE,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_BE },
            { "no_gpl",   OPTION_VAL_NO_GPL_BE },
            { "no_dyn",   OPTION_VAL_NO_DYN_BE },
            { "none",     OPTION_VAL_NONE_BE },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_BE,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_BE,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_BE,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_BE,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_BE,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_BE,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_BE },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_BE },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_BE },
            { "15", OPTION_VAL_15_BE },
            { "20", OPTION_VAL_20_BE },
            { "25", OPTION_VAL_25_BE },
            { "30", OPTION_VAL_30_BE },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_BE,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_BE,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_BE },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_BE },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_BE },
            { "15", OPTION_VAL_15_BE },
            { "20", OPTION_VAL_20_BE },
            { "25", OPTION_VAL_25_BE },
            { "30", OPTION_VAL_30_BE },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_BE,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_BE,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_BE,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_BE,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_BE },
            { "stick", OPTION_VAL_STICK_BE },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_BE,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_BE,
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
        XEMU_CHIHIRO_FFB_LABEL_BE,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_BE,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_BE },
            { "50",  OPTION_VAL_50_BE },
            { "75",  OPTION_VAL_75_BE },
            { "100", OPTION_VAL_100_BE },
            { "150", OPTION_VAL_150_BE },
            { "200", OPTION_VAL_200_BE },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_be = {
   option_cats_be,
   option_defs_be
};

/* RETRO_LANGUAGE_BG */

#define CATEGORY_SYSTEM_LABEL_BG NULL
#define CATEGORY_SYSTEM_INFO_0_BG NULL
#define CATEGORY_VIDEO_LABEL_BG "Видео"
#define CATEGORY_VIDEO_INFO_0_BG NULL
#define CATEGORY_AUDIO_LABEL_BG "Звук"
#define CATEGORY_AUDIO_INFO_0_BG NULL
#define CATEGORY_CONTROLS_LABEL_BG NULL
#define CATEGORY_CONTROLS_INFO_0_BG NULL
#define CATEGORY_CHIHIRO_LABEL_BG NULL
#define CATEGORY_CHIHIRO_INFO_0_BG NULL
#define XEMU_MEMORY_LABEL_BG NULL
#define XEMU_MEMORY_INFO_0_BG NULL
#define OPTION_VAL_64_BG NULL
#define OPTION_VAL_128_BG NULL
#define XEMU_NETWORK_BACKEND_LABEL_BG NULL
#define XEMU_NETWORK_BACKEND_INFO_0_BG NULL
#define OPTION_VAL_NAT_BG NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_BG NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_BG NULL
#define XEMU_HARD_FPU_LABEL_BG NULL
#define XEMU_HARD_FPU_INFO_0_BG NULL
#define XEMU_CPU_BOOST_LABEL_BG NULL
#define XEMU_CPU_BOOST_INFO_0_BG NULL
#define XEMU_HDD_TRIM_LABEL_BG NULL
#define XEMU_HDD_TRIM_INFO_0_BG NULL
#define XEMU_RENDERER_LABEL_BG NULL
#define XEMU_RENDERER_INFO_0_BG NULL
#define OPTION_VAL_VULKAN_BG NULL
#define OPTION_VAL_OPENGL_BG NULL
#define XEMU_VIDEO_ASPECT_LABEL_BG NULL
#define XEMU_VIDEO_ASPECT_INFO_0_BG NULL
#define OPTION_VAL_DASHBOARD_BG NULL
#define OPTION_VAL_4_3_BG NULL
#define OPTION_VAL_16_9_BG NULL
#define OPTION_VAL_LETTERBOX_BG NULL
#define XEMU_ASPECT_RATIO_LABEL_BG NULL
#define XEMU_ASPECT_RATIO_INFO_0_BG NULL
#define OPTION_VAL_AUTO_BG NULL
#define XEMU_SURFACE_SCALE_LABEL_BG NULL
#define XEMU_SURFACE_SCALE_INFO_0_BG NULL
#define OPTION_VAL_1_BG NULL
#define OPTION_VAL_2_BG NULL
#define OPTION_VAL_3_BG NULL
#define OPTION_VAL_4_BG NULL
#define OPTION_VAL_5_BG NULL
#define OPTION_VAL_6_BG NULL
#define OPTION_VAL_7_BG NULL
#define OPTION_VAL_8_BG NULL
#define OPTION_VAL_9_BG NULL
#define OPTION_VAL_10_BG NULL
#define XEMU_AVPACK_LABEL_BG NULL
#define XEMU_AVPACK_INFO_0_BG NULL
#define OPTION_VAL_HDTV_BG NULL
#define OPTION_VAL_COMPOSITE_BG NULL
#define OPTION_VAL_SVIDEO_BG NULL
#define OPTION_VAL_SCART_BG NULL
#define OPTION_VAL_VGA_BG NULL
#define XEMU_AUDIO_THREAD_LABEL_BG NULL
#define XEMU_AUDIO_THREAD_INFO_0_BG NULL
#define XEMU_USE_DSP_LABEL_BG NULL
#define XEMU_USE_DSP_INFO_0_BG NULL
#define XEMU_DSP_JIT_LABEL_BG NULL
#define XEMU_DSP_JIT_INFO_0_BG NULL
#define XEMU_HRTF_LABEL_BG NULL
#define XEMU_HRTF_INFO_0_BG NULL
#define XEMU_VP_WORKERS_LABEL_BG NULL
#define XEMU_VP_WORKERS_INFO_0_BG NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_BG NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_BG NULL
#define XEMU_AUDIO_VOLUME_LABEL_BG NULL
#define XEMU_AUDIO_VOLUME_INFO_0_BG NULL
#define OPTION_VAL_100_BG NULL
#define OPTION_VAL_80_BG NULL
#define OPTION_VAL_60_BG NULL
#define OPTION_VAL_40_BG NULL
#define OPTION_VAL_20_BG NULL
#define OPTION_VAL_0_BG NULL
#define XEMU_VK_FAST_PATHS_LABEL_BG NULL
#define XEMU_VK_FAST_PATHS_INFO_0_BG NULL
#define OPTION_VAL_ALL_BG NULL
#define OPTION_VAL_NO_GPL_BG NULL
#define OPTION_VAL_NO_DYN_BG NULL
#define OPTION_VAL_NONE_BG NULL
#define XEMU_RUMBLE_P1_LABEL_BG NULL
#define XEMU_RUMBLE_P1_INFO_0_BG NULL
#define XEMU_RUMBLE_P2_LABEL_BG NULL
#define XEMU_RUMBLE_P2_INFO_0_BG NULL
#define XEMU_DEADZONE_P1_LABEL_BG NULL
#define XEMU_DEADZONE_P1_INFO_0_BG NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_BG NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_BG NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_BG NULL
#define OPTION_VAL_15_BG NULL
#define OPTION_VAL_25_BG NULL
#define OPTION_VAL_30_BG NULL
#define XEMU_DEADZONE_P2_LABEL_BG NULL
#define XEMU_DEADZONE_P2_INFO_0_BG NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_BG NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_BG NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_BG NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_BG NULL
#define OPTION_VAL_MOUSE_BG NULL
#define OPTION_VAL_STICK_BG NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_BG NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_BG NULL
#define XEMU_CHIHIRO_FFB_LABEL_BG NULL
#define XEMU_CHIHIRO_FFB_INFO_0_BG NULL
#define OPTION_VAL_50_BG NULL
#define OPTION_VAL_75_BG NULL
#define OPTION_VAL_150_BG NULL
#define OPTION_VAL_200_BG NULL

struct retro_core_option_v2_category option_cats_bg[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_BG,
        CATEGORY_SYSTEM_INFO_0_BG
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_BG,
        CATEGORY_VIDEO_INFO_0_BG
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_BG,
        CATEGORY_AUDIO_INFO_0_BG
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_BG,
        CATEGORY_CONTROLS_INFO_0_BG
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_BG,
        CATEGORY_CHIHIRO_INFO_0_BG
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_bg[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_BG,
        NULL,
        XEMU_MEMORY_INFO_0_BG,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_BG },
            { "128", OPTION_VAL_128_BG },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_BG,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_BG,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_BG },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_BG,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_BG,
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
        XEMU_HARD_FPU_LABEL_BG,
        NULL,
        XEMU_HARD_FPU_INFO_0_BG,
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
        XEMU_CPU_BOOST_LABEL_BG,
        NULL,
        XEMU_CPU_BOOST_INFO_0_BG,
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
        XEMU_HDD_TRIM_LABEL_BG,
        NULL,
        XEMU_HDD_TRIM_INFO_0_BG,
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
        XEMU_RENDERER_LABEL_BG,
        NULL,
        XEMU_RENDERER_INFO_0_BG,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_BG },
            { "opengl", OPTION_VAL_OPENGL_BG },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_BG,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_BG,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_BG },
            { "4:3",       OPTION_VAL_4_3_BG },
            { "16:9",      OPTION_VAL_16_9_BG },
            { "letterbox", OPTION_VAL_LETTERBOX_BG },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_BG,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_BG,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_BG },
            { "4:3",  OPTION_VAL_4_3_BG },
            { "16:9", OPTION_VAL_16_9_BG },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_BG,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_BG,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_BG },
            { "2", OPTION_VAL_2_BG },
            { "3", OPTION_VAL_3_BG },
            { "4", OPTION_VAL_4_BG },
            { "5", OPTION_VAL_5_BG },
            { "6", OPTION_VAL_6_BG },
            { "7", OPTION_VAL_7_BG },
            { "8", OPTION_VAL_8_BG },
            { "9", OPTION_VAL_9_BG },
            { "10", OPTION_VAL_10_BG },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_BG,
        NULL,
        XEMU_AVPACK_INFO_0_BG,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_BG },
            { "composite", OPTION_VAL_COMPOSITE_BG },
            { "svideo",    OPTION_VAL_SVIDEO_BG },
            { "scart",     OPTION_VAL_SCART_BG },
            { "vga",       OPTION_VAL_VGA_BG },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_BG,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_BG,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_BG,
        NULL,
        XEMU_USE_DSP_INFO_0_BG,
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
        XEMU_DSP_JIT_LABEL_BG,
        NULL,
        XEMU_DSP_JIT_INFO_0_BG,
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
        XEMU_HRTF_LABEL_BG,
        NULL,
        XEMU_HRTF_INFO_0_BG,
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
        XEMU_VP_WORKERS_LABEL_BG,
        NULL,
        XEMU_VP_WORKERS_INFO_0_BG,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_BG },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_BG,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_BG,
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
        XEMU_AUDIO_VOLUME_LABEL_BG,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_BG,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_BG },
            { "80",  OPTION_VAL_80_BG },
            { "60",  OPTION_VAL_60_BG },
            { "40",  OPTION_VAL_40_BG },
            { "20",  OPTION_VAL_20_BG },
            { "0",   OPTION_VAL_0_BG },
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
        XEMU_VK_FAST_PATHS_LABEL_BG,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_BG,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_BG },
            { "no_gpl",   OPTION_VAL_NO_GPL_BG },
            { "no_dyn",   OPTION_VAL_NO_DYN_BG },
            { "none",     OPTION_VAL_NONE_BG },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_BG,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_BG,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_BG,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_BG,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_BG,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_BG,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_BG },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_BG },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_BG },
            { "15", OPTION_VAL_15_BG },
            { "20", OPTION_VAL_20_BG },
            { "25", OPTION_VAL_25_BG },
            { "30", OPTION_VAL_30_BG },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_BG,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_BG,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_BG },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_BG },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_BG },
            { "15", OPTION_VAL_15_BG },
            { "20", OPTION_VAL_20_BG },
            { "25", OPTION_VAL_25_BG },
            { "30", OPTION_VAL_30_BG },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_BG,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_BG,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_BG,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_BG,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_BG },
            { "stick", OPTION_VAL_STICK_BG },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_BG,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_BG,
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
        XEMU_CHIHIRO_FFB_LABEL_BG,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_BG,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_BG },
            { "50",  OPTION_VAL_50_BG },
            { "75",  OPTION_VAL_75_BG },
            { "100", OPTION_VAL_100_BG },
            { "150", OPTION_VAL_150_BG },
            { "200", OPTION_VAL_200_BG },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_bg = {
   option_cats_bg,
   option_defs_bg
};

/* RETRO_LANGUAGE_CA */

#define CATEGORY_SYSTEM_LABEL_CA NULL
#define CATEGORY_SYSTEM_INFO_0_CA NULL
#define CATEGORY_VIDEO_LABEL_CA "Vídeo"
#define CATEGORY_VIDEO_INFO_0_CA "Configura el renderitzat de vídeo."
#define CATEGORY_AUDIO_LABEL_CA "Àudio"
#define CATEGORY_AUDIO_INFO_0_CA "Configura l'emulació de vídeo."
#define CATEGORY_CONTROLS_LABEL_CA NULL
#define CATEGORY_CONTROLS_INFO_0_CA NULL
#define CATEGORY_CHIHIRO_LABEL_CA NULL
#define CATEGORY_CHIHIRO_INFO_0_CA NULL
#define XEMU_MEMORY_LABEL_CA "Memòria del sistema (MB)"
#define XEMU_MEMORY_INFO_0_CA "Quantitat de memòria RAM. L'estàndard és 64 MB; es fan servir 128 MB en cas de fer depuració."
#define OPTION_VAL_64_CA NULL
#define OPTION_VAL_128_CA NULL
#define XEMU_NETWORK_BACKEND_LABEL_CA "Backend de xarxa"
#define XEMU_NETWORK_BACKEND_INFO_0_CA "Habilita el suport de xarxa per a jocs d'Xbox amb funcionalitats LAN/System Link. El sistema NAT proporciona connectivitat bàsica."
#define OPTION_VAL_NAT_CA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CA "Omet animació d'inici"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CA "Omet l'animació inicial de Xbox."
#define XEMU_HARD_FPU_LABEL_CA "Emulació del maquinari FPU"
#define XEMU_HARD_FPU_INFO_0_CA "Fes servir l'amfitrió FPU per l'emulació de x87. És més ràpid però pot provocar alguna imprecisió."
#define XEMU_CPU_BOOST_LABEL_CA NULL
#define XEMU_CPU_BOOST_INFO_0_CA NULL
#define XEMU_HDD_TRIM_LABEL_CA NULL
#define XEMU_HDD_TRIM_INFO_0_CA NULL
#define XEMU_RENDERER_LABEL_CA "API de gràfics (Cal reiniciar)"
#define XEMU_RENDERER_INFO_0_CA "El motor de renderització utilitzat per dibuixar la GPU emulada. Vulkan és l'opció predeterminada; OpenGL és l'alternativa per als controladors en què Vulkan no funciona correctament. Els canvis s'apliquen després de reiniciar RetroArch. Android utilitza sempre Vulkan, mentre que macOS utilitza sempre OpenGL."
#define OPTION_VAL_VULKAN_CA NULL
#define OPTION_VAL_OPENGL_CA NULL
#define XEMU_VIDEO_ASPECT_LABEL_CA NULL
#define XEMU_VIDEO_ASPECT_INFO_0_CA NULL
#define OPTION_VAL_DASHBOARD_CA NULL
#define OPTION_VAL_4_3_CA NULL
#define OPTION_VAL_16_9_CA NULL
#define OPTION_VAL_LETTERBOX_CA NULL
#define XEMU_ASPECT_RATIO_LABEL_CA "Relació d'aspecte del nucli"
#define XEMU_ASPECT_RATIO_INFO_0_CA NULL
#define OPTION_VAL_AUTO_CA "Automàtic"
#define XEMU_SURFACE_SCALE_LABEL_CA NULL
#define XEMU_SURFACE_SCALE_INFO_0_CA "Escala la resolució interna de renderització. Valors alts poden millorar la qualitat per reduir el rendiment."
#define OPTION_VAL_1_CA NULL
#define OPTION_VAL_2_CA NULL
#define OPTION_VAL_3_CA NULL
#define OPTION_VAL_4_CA NULL
#define OPTION_VAL_5_CA NULL
#define OPTION_VAL_6_CA NULL
#define OPTION_VAL_7_CA NULL
#define OPTION_VAL_8_CA NULL
#define OPTION_VAL_9_CA NULL
#define OPTION_VAL_10_CA NULL
#define XEMU_AVPACK_LABEL_CA NULL
#define XEMU_AVPACK_INFO_0_CA "Selecciona el tipus de paquet AV. Afecta als modes de vídeo disponibles."
#define OPTION_VAL_HDTV_CA NULL
#define OPTION_VAL_COMPOSITE_CA "Composició"
#define OPTION_VAL_SVIDEO_CA NULL
#define OPTION_VAL_SCART_CA NULL
#define OPTION_VAL_VGA_CA NULL
#define XEMU_AUDIO_THREAD_LABEL_CA "Fil d'àudio (Cal reiniciar)"
#define XEMU_AUDIO_THREAD_INFO_0_CA NULL
#define XEMU_USE_DSP_LABEL_CA "Emulació de APU DSP"
#define XEMU_USE_DSP_INFO_0_CA "Activa l'emulació DSP per millorar la precisió de l'àudio. Pot tenir un impacte en el rendiment."
#define XEMU_DSP_JIT_LABEL_CA NULL
#define XEMU_DSP_JIT_INFO_0_CA NULL
#define XEMU_HRTF_LABEL_CA NULL
#define XEMU_HRTF_INFO_0_CA NULL
#define XEMU_VP_WORKERS_LABEL_CA NULL
#define XEMU_VP_WORKERS_INFO_0_CA NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_CA NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_CA NULL
#define XEMU_AUDIO_VOLUME_LABEL_CA "Llindar del volum d'àudio (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_CA "Limita el volum de la sortida d'àudio de Xbox independentment del volum principal de RetroArch."
#define OPTION_VAL_100_CA NULL
#define OPTION_VAL_80_CA NULL
#define OPTION_VAL_60_CA NULL
#define OPTION_VAL_40_CA NULL
#define OPTION_VAL_20_CA NULL
#define OPTION_VAL_0_CA "Silenciat"
#define XEMU_VK_FAST_PATHS_LABEL_CA NULL
#define XEMU_VK_FAST_PATHS_INFO_0_CA NULL
#define OPTION_VAL_ALL_CA "Tots"
#define OPTION_VAL_NO_GPL_CA NULL
#define OPTION_VAL_NO_DYN_CA NULL
#define OPTION_VAL_NONE_CA "Cap"
#define XEMU_RUMBLE_P1_LABEL_CA NULL
#define XEMU_RUMBLE_P1_INFO_0_CA NULL
#define XEMU_RUMBLE_P2_LABEL_CA NULL
#define XEMU_RUMBLE_P2_INFO_0_CA NULL
#define XEMU_DEADZONE_P1_LABEL_CA NULL
#define XEMU_DEADZONE_P1_INFO_0_CA NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_CA NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_CA NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_CA NULL
#define OPTION_VAL_15_CA NULL
#define OPTION_VAL_25_CA NULL
#define OPTION_VAL_30_CA NULL
#define XEMU_DEADZONE_P2_LABEL_CA NULL
#define XEMU_DEADZONE_P2_INFO_0_CA NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_CA NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_CA NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_CA NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_CA NULL
#define OPTION_VAL_MOUSE_CA "Ratolí"
#define OPTION_VAL_STICK_CA NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_CA NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_CA NULL
#define XEMU_CHIHIRO_FFB_LABEL_CA NULL
#define XEMU_CHIHIRO_FFB_INFO_0_CA NULL
#define OPTION_VAL_50_CA NULL
#define OPTION_VAL_75_CA NULL
#define OPTION_VAL_150_CA NULL
#define OPTION_VAL_200_CA NULL

struct retro_core_option_v2_category option_cats_ca[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_CA,
        CATEGORY_SYSTEM_INFO_0_CA
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_CA,
        CATEGORY_VIDEO_INFO_0_CA
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_CA,
        CATEGORY_AUDIO_INFO_0_CA
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_CA,
        CATEGORY_CONTROLS_INFO_0_CA
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_CA,
        CATEGORY_CHIHIRO_INFO_0_CA
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ca[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_CA,
        NULL,
        XEMU_MEMORY_INFO_0_CA,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_CA },
            { "128", OPTION_VAL_128_CA },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_CA,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_CA,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_CA },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_CA,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_CA,
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
        XEMU_HARD_FPU_LABEL_CA,
        NULL,
        XEMU_HARD_FPU_INFO_0_CA,
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
        XEMU_CPU_BOOST_LABEL_CA,
        NULL,
        XEMU_CPU_BOOST_INFO_0_CA,
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
        XEMU_HDD_TRIM_LABEL_CA,
        NULL,
        XEMU_HDD_TRIM_INFO_0_CA,
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
        XEMU_RENDERER_LABEL_CA,
        NULL,
        XEMU_RENDERER_INFO_0_CA,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_CA },
            { "opengl", OPTION_VAL_OPENGL_CA },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_CA,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_CA,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_CA },
            { "4:3",       OPTION_VAL_4_3_CA },
            { "16:9",      OPTION_VAL_16_9_CA },
            { "letterbox", OPTION_VAL_LETTERBOX_CA },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_CA,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_CA,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_CA },
            { "4:3",  OPTION_VAL_4_3_CA },
            { "16:9", OPTION_VAL_16_9_CA },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_CA,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_CA,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_CA },
            { "2", OPTION_VAL_2_CA },
            { "3", OPTION_VAL_3_CA },
            { "4", OPTION_VAL_4_CA },
            { "5", OPTION_VAL_5_CA },
            { "6", OPTION_VAL_6_CA },
            { "7", OPTION_VAL_7_CA },
            { "8", OPTION_VAL_8_CA },
            { "9", OPTION_VAL_9_CA },
            { "10", OPTION_VAL_10_CA },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_CA,
        NULL,
        XEMU_AVPACK_INFO_0_CA,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_CA },
            { "composite", OPTION_VAL_COMPOSITE_CA },
            { "svideo",    OPTION_VAL_SVIDEO_CA },
            { "scart",     OPTION_VAL_SCART_CA },
            { "vga",       OPTION_VAL_VGA_CA },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_CA,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_CA,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_CA,
        NULL,
        XEMU_USE_DSP_INFO_0_CA,
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
        XEMU_DSP_JIT_LABEL_CA,
        NULL,
        XEMU_DSP_JIT_INFO_0_CA,
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
        XEMU_HRTF_LABEL_CA,
        NULL,
        XEMU_HRTF_INFO_0_CA,
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
        XEMU_VP_WORKERS_LABEL_CA,
        NULL,
        XEMU_VP_WORKERS_INFO_0_CA,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_CA },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_CA,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_CA,
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
        XEMU_AUDIO_VOLUME_LABEL_CA,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_CA,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_CA },
            { "80",  OPTION_VAL_80_CA },
            { "60",  OPTION_VAL_60_CA },
            { "40",  OPTION_VAL_40_CA },
            { "20",  OPTION_VAL_20_CA },
            { "0",   OPTION_VAL_0_CA },
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
        XEMU_VK_FAST_PATHS_LABEL_CA,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_CA,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_CA },
            { "no_gpl",   OPTION_VAL_NO_GPL_CA },
            { "no_dyn",   OPTION_VAL_NO_DYN_CA },
            { "none",     OPTION_VAL_NONE_CA },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_CA,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_CA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_CA,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_CA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_CA,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_CA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CA },
            { "15", OPTION_VAL_15_CA },
            { "20", OPTION_VAL_20_CA },
            { "25", OPTION_VAL_25_CA },
            { "30", OPTION_VAL_30_CA },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_CA,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_CA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CA },
            { "15", OPTION_VAL_15_CA },
            { "20", OPTION_VAL_20_CA },
            { "25", OPTION_VAL_25_CA },
            { "30", OPTION_VAL_30_CA },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_CA,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_CA,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_CA,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_CA,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_CA },
            { "stick", OPTION_VAL_STICK_CA },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_CA,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_CA,
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
        XEMU_CHIHIRO_FFB_LABEL_CA,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_CA,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_CA },
            { "50",  OPTION_VAL_50_CA },
            { "75",  OPTION_VAL_75_CA },
            { "100", OPTION_VAL_100_CA },
            { "150", OPTION_VAL_150_CA },
            { "200", OPTION_VAL_200_CA },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ca = {
   option_cats_ca,
   option_defs_ca
};

/* RETRO_LANGUAGE_CHS */

#define CATEGORY_SYSTEM_LABEL_CHS NULL
#define CATEGORY_SYSTEM_INFO_0_CHS NULL
#define CATEGORY_VIDEO_LABEL_CHS "视频"
#define CATEGORY_VIDEO_INFO_0_CHS "配置视频渲染设置。"
#define CATEGORY_AUDIO_LABEL_CHS "音频"
#define CATEGORY_AUDIO_INFO_0_CHS "配置音频模拟设置。"
#define CATEGORY_CONTROLS_LABEL_CHS "控制"
#define CATEGORY_CONTROLS_INFO_0_CHS NULL
#define CATEGORY_CHIHIRO_LABEL_CHS "世嘉 Chihiro 基板"
#define CATEGORY_CHIHIRO_INFO_0_CHS "世嘉 Chihiro 街机游戏相关设置：包含免费游玩、光枪游戏的瞄准方式以及赛车游戏的力反馈调节。"
#define XEMU_MEMORY_LABEL_CHS "系统内存 (MB)"
#define XEMU_MEMORY_INFO_0_CHS "系统内存容量。64 MB 为标准配置；128 MB 仅用于开发调试机。"
#define OPTION_VAL_64_CHS NULL
#define OPTION_VAL_128_CHS NULL
#define XEMU_NETWORK_BACKEND_LABEL_CHS "网络后端"
#define XEMU_NETWORK_BACKEND_INFO_0_CHS "为支持局域网/系统联机 (System Link) 功能的 Xbox 游戏启用网络支持。NAT 后端提供基础连接能力。"
#define OPTION_VAL_NAT_CHS NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CHS "跳过启动动画"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CHS "跳过 Xbox 开机动画。"
#define XEMU_HARD_FPU_LABEL_CHS "硬件 FPU 模拟"
#define XEMU_HARD_FPU_INFO_0_CHS "使用宿主机的 FPU 来模拟 x87 指令。速度更快，但可能会有轻微的精度偏差。"
#define XEMU_CPU_BOOST_LABEL_CHS NULL
#define XEMU_CPU_BOOST_INFO_0_CHS "为虚拟机 CPU 及音频处理器启用更快的执行路径：包括原生 SSE 指令集和更宽的跳转缓存。若游戏出现运行异常，请将其关闭。"
#define XEMU_HDD_TRIM_LABEL_CHS NULL
#define XEMU_HDD_TRIM_INFO_0_CHS NULL
#define XEMU_RENDERER_LABEL_CHS "图形 API (需重启)"
#define XEMU_RENDERER_INFO_0_CHS "用于绘制模拟 GPU 的渲染器。默认为 Vulkan；当驱动程序无法正常运行 Vulkan 时可回退使用 OpenGL。在重启 RetroArch 后生效。Android 始终使用 Vulkan，macOS 始终使用 OpenGL。"
#define OPTION_VAL_VULKAN_CHS NULL
#define OPTION_VAL_OPENGL_CHS NULL
#define XEMU_VIDEO_ASPECT_LABEL_CHS NULL
#define XEMU_VIDEO_ASPECT_INFO_0_CHS NULL
#define OPTION_VAL_DASHBOARD_CHS NULL
#define OPTION_VAL_4_3_CHS NULL
#define OPTION_VAL_16_9_CHS NULL
#define OPTION_VAL_LETTERBOX_CHS NULL
#define XEMU_ASPECT_RATIO_LABEL_CHS "核心宽高比"
#define XEMU_ASPECT_RATIO_INFO_0_CHS NULL
#define OPTION_VAL_AUTO_CHS "自动"
#define XEMU_SURFACE_SCALE_LABEL_CHS NULL
#define XEMU_SURFACE_SCALE_INFO_0_CHS "缩放内部渲染分辨率。较高的数值可提升画质，但会降低运行性能。"
#define OPTION_VAL_1_CHS NULL
#define OPTION_VAL_2_CHS NULL
#define OPTION_VAL_3_CHS NULL
#define OPTION_VAL_4_CHS "4 x (2560x1920)"
#define OPTION_VAL_5_CHS NULL
#define OPTION_VAL_6_CHS NULL
#define OPTION_VAL_7_CHS "7 x (4480x3360)"
#define OPTION_VAL_8_CHS NULL
#define OPTION_VAL_9_CHS NULL
#define OPTION_VAL_10_CHS NULL
#define XEMU_AVPACK_LABEL_CHS NULL
#define XEMU_AVPACK_INFO_0_CHS "选择影音线缆类型。会影响可用的视频输出模式。"
#define OPTION_VAL_HDTV_CHS "高清电视 (HDTV)"
#define OPTION_VAL_COMPOSITE_CHS "复合"
#define OPTION_VAL_SVIDEO_CHS "S-端子"
#define OPTION_VAL_SCART_CHS NULL
#define OPTION_VAL_VGA_CHS NULL
#define XEMU_AUDIO_THREAD_LABEL_CHS "独立音频线程 (需重启)"
#define XEMU_AUDIO_THREAD_INFO_0_CHS NULL
#define XEMU_USE_DSP_LABEL_CHS "APU DSP 模拟"
#define XEMU_USE_DSP_INFO_0_CHS "启用 DSP 模拟以提高音频精确度。可能会影响运行性能。"
#define XEMU_DSP_JIT_LABEL_CHS NULL
#define XEMU_DSP_JIT_INFO_0_CHS NULL
#define XEMU_HRTF_LABEL_CHS NULL
#define XEMU_HRTF_INFO_0_CHS NULL
#define XEMU_VP_WORKERS_LABEL_CHS NULL
#define XEMU_VP_WORKERS_INFO_0_CHS NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_CHS "平滑首次游玩 (需重启)"
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_CHS NULL
#define XEMU_AUDIO_VOLUME_LABEL_CHS "音频音量限制 (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_CHS "独立于 RetroArch 主音量限制 Xbox 的音频输出音量。"
#define OPTION_VAL_100_CHS NULL
#define OPTION_VAL_80_CHS NULL
#define OPTION_VAL_60_CHS NULL
#define OPTION_VAL_40_CHS NULL
#define OPTION_VAL_20_CHS NULL
#define OPTION_VAL_0_CHS "已静音"
#define XEMU_VK_FAST_PATHS_LABEL_CHS "Vulkan 快速路径 (需重启)"
#define XEMU_VK_FAST_PATHS_INFO_0_CHS NULL
#define OPTION_VAL_ALL_CHS "全部"
#define OPTION_VAL_NO_GPL_CHS "禁用管线库"
#define OPTION_VAL_NO_DYN_CHS "禁用动态状态"
#define OPTION_VAL_NONE_CHS "无"
#define XEMU_RUMBLE_P1_LABEL_CHS NULL
#define XEMU_RUMBLE_P1_INFO_0_CHS NULL
#define XEMU_RUMBLE_P2_LABEL_CHS NULL
#define XEMU_RUMBLE_P2_INFO_0_CHS NULL
#define XEMU_DEADZONE_P1_LABEL_CHS NULL
#define XEMU_DEADZONE_P1_INFO_0_CHS NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_CHS NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_CHS NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_CHS NULL
#define OPTION_VAL_15_CHS NULL
#define OPTION_VAL_25_CHS NULL
#define OPTION_VAL_30_CHS NULL
#define XEMU_DEADZONE_P2_LABEL_CHS NULL
#define XEMU_DEADZONE_P2_INFO_0_CHS NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_CHS "免投币免费玩(需重启)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_CHS "启动世嘉 Chihiro 街机游戏时直接进入免费模式，无需投币。关闭此项时，按下 Select 键即可投币。"
#define XEMU_CHIHIRO_GUN_AIM_LABEL_CHS "光枪瞄准控制"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_CHS "控制《死亡之屋 3》、《VR 战警 3》和《幽灵小队》等游戏的瞄准方式。“鼠标”：使用鼠标（或 RetroArch 的光枪）瞄准，左键射击，右键为枪械功能键（如上膛、换武器），中键为踏板或连发速率；“模拟摇杆”：使用左摇杆或方向键瞄准，R2 开火，L2 为枪械功能键，L 键为踏板或连发速率，R 键向屏幕外射击。"
#define OPTION_VAL_MOUSE_CHS "鼠标"
#define OPTION_VAL_STICK_CHS "模拟摇杆"
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_CHS "游戏准星显示"
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_CHS "在画面上叠加绘制玩家的瞄准准星，1 号玩家显示为红色，2 号玩家显示为蓝色。"
#define XEMU_CHIHIRO_FFB_LABEL_CHS "力反馈震动"
#define XEMU_CHIHIRO_FFB_INFO_0_CHS "将 Chihiro 赛车游戏（如《OutRun 2》、《湾岸午夜最高极速》）的力反馈信号转换为端口 1 手柄的震动效果，强度为此处设定的百分比。"
#define OPTION_VAL_50_CHS NULL
#define OPTION_VAL_75_CHS NULL
#define OPTION_VAL_150_CHS NULL
#define OPTION_VAL_200_CHS NULL

struct retro_core_option_v2_category option_cats_chs[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_CHS,
        CATEGORY_SYSTEM_INFO_0_CHS
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_CHS,
        CATEGORY_VIDEO_INFO_0_CHS
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_CHS,
        CATEGORY_AUDIO_INFO_0_CHS
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_CHS,
        CATEGORY_CONTROLS_INFO_0_CHS
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_CHS,
        CATEGORY_CHIHIRO_INFO_0_CHS
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_chs[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_CHS,
        NULL,
        XEMU_MEMORY_INFO_0_CHS,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_CHS },
            { "128", OPTION_VAL_128_CHS },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_CHS,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_CHS,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_CHS },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_CHS,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_CHS,
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
        XEMU_HARD_FPU_LABEL_CHS,
        NULL,
        XEMU_HARD_FPU_INFO_0_CHS,
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
        XEMU_CPU_BOOST_LABEL_CHS,
        NULL,
        XEMU_CPU_BOOST_INFO_0_CHS,
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
        XEMU_HDD_TRIM_LABEL_CHS,
        NULL,
        XEMU_HDD_TRIM_INFO_0_CHS,
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
        XEMU_RENDERER_LABEL_CHS,
        NULL,
        XEMU_RENDERER_INFO_0_CHS,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_CHS },
            { "opengl", OPTION_VAL_OPENGL_CHS },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_CHS,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_CHS,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_CHS },
            { "4:3",       OPTION_VAL_4_3_CHS },
            { "16:9",      OPTION_VAL_16_9_CHS },
            { "letterbox", OPTION_VAL_LETTERBOX_CHS },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_CHS,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_CHS,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_CHS },
            { "4:3",  OPTION_VAL_4_3_CHS },
            { "16:9", OPTION_VAL_16_9_CHS },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_CHS,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_CHS,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_CHS },
            { "2", OPTION_VAL_2_CHS },
            { "3", OPTION_VAL_3_CHS },
            { "4", OPTION_VAL_4_CHS },
            { "5", OPTION_VAL_5_CHS },
            { "6", OPTION_VAL_6_CHS },
            { "7", OPTION_VAL_7_CHS },
            { "8", OPTION_VAL_8_CHS },
            { "9", OPTION_VAL_9_CHS },
            { "10", OPTION_VAL_10_CHS },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_CHS,
        NULL,
        XEMU_AVPACK_INFO_0_CHS,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_CHS },
            { "composite", OPTION_VAL_COMPOSITE_CHS },
            { "svideo",    OPTION_VAL_SVIDEO_CHS },
            { "scart",     OPTION_VAL_SCART_CHS },
            { "vga",       OPTION_VAL_VGA_CHS },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_CHS,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_CHS,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_CHS,
        NULL,
        XEMU_USE_DSP_INFO_0_CHS,
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
        XEMU_DSP_JIT_LABEL_CHS,
        NULL,
        XEMU_DSP_JIT_INFO_0_CHS,
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
        XEMU_HRTF_LABEL_CHS,
        NULL,
        XEMU_HRTF_INFO_0_CHS,
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
        XEMU_VP_WORKERS_LABEL_CHS,
        NULL,
        XEMU_VP_WORKERS_INFO_0_CHS,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_CHS },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_CHS,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_CHS,
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
        XEMU_AUDIO_VOLUME_LABEL_CHS,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_CHS,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_CHS },
            { "80",  OPTION_VAL_80_CHS },
            { "60",  OPTION_VAL_60_CHS },
            { "40",  OPTION_VAL_40_CHS },
            { "20",  OPTION_VAL_20_CHS },
            { "0",   OPTION_VAL_0_CHS },
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
        XEMU_VK_FAST_PATHS_LABEL_CHS,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_CHS,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_CHS },
            { "no_gpl",   OPTION_VAL_NO_GPL_CHS },
            { "no_dyn",   OPTION_VAL_NO_DYN_CHS },
            { "none",     OPTION_VAL_NONE_CHS },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_CHS,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_CHS,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_CHS,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_CHS,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_CHS,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_CHS,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CHS },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CHS },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CHS },
            { "15", OPTION_VAL_15_CHS },
            { "20", OPTION_VAL_20_CHS },
            { "25", OPTION_VAL_25_CHS },
            { "30", OPTION_VAL_30_CHS },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_CHS,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_CHS,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CHS },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CHS },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CHS },
            { "15", OPTION_VAL_15_CHS },
            { "20", OPTION_VAL_20_CHS },
            { "25", OPTION_VAL_25_CHS },
            { "30", OPTION_VAL_30_CHS },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_CHS,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_CHS,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_CHS,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_CHS,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_CHS },
            { "stick", OPTION_VAL_STICK_CHS },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_CHS,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_CHS,
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
        XEMU_CHIHIRO_FFB_LABEL_CHS,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_CHS,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_CHS },
            { "50",  OPTION_VAL_50_CHS },
            { "75",  OPTION_VAL_75_CHS },
            { "100", OPTION_VAL_100_CHS },
            { "150", OPTION_VAL_150_CHS },
            { "200", OPTION_VAL_200_CHS },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_chs = {
   option_cats_chs,
   option_defs_chs
};

/* RETRO_LANGUAGE_CHT */

#define CATEGORY_SYSTEM_LABEL_CHT NULL
#define CATEGORY_SYSTEM_INFO_0_CHT NULL
#define CATEGORY_VIDEO_LABEL_CHT "顯示"
#define CATEGORY_VIDEO_INFO_0_CHT NULL
#define CATEGORY_AUDIO_LABEL_CHT "音效"
#define CATEGORY_AUDIO_INFO_0_CHT NULL
#define CATEGORY_CONTROLS_LABEL_CHT "控制器 (核心預設)"
#define CATEGORY_CONTROLS_INFO_0_CHT NULL
#define CATEGORY_CHIHIRO_LABEL_CHT NULL
#define CATEGORY_CHIHIRO_INFO_0_CHT NULL
#define XEMU_MEMORY_LABEL_CHT NULL
#define XEMU_MEMORY_INFO_0_CHT NULL
#define OPTION_VAL_64_CHT NULL
#define OPTION_VAL_128_CHT NULL
#define XEMU_NETWORK_BACKEND_LABEL_CHT NULL
#define XEMU_NETWORK_BACKEND_INFO_0_CHT NULL
#define OPTION_VAL_NAT_CHT NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CHT NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CHT NULL
#define XEMU_HARD_FPU_LABEL_CHT NULL
#define XEMU_HARD_FPU_INFO_0_CHT NULL
#define XEMU_CPU_BOOST_LABEL_CHT NULL
#define XEMU_CPU_BOOST_INFO_0_CHT NULL
#define XEMU_HDD_TRIM_LABEL_CHT NULL
#define XEMU_HDD_TRIM_INFO_0_CHT NULL
#define XEMU_RENDERER_LABEL_CHT NULL
#define XEMU_RENDERER_INFO_0_CHT NULL
#define OPTION_VAL_VULKAN_CHT NULL
#define OPTION_VAL_OPENGL_CHT NULL
#define XEMU_VIDEO_ASPECT_LABEL_CHT NULL
#define XEMU_VIDEO_ASPECT_INFO_0_CHT NULL
#define OPTION_VAL_DASHBOARD_CHT NULL
#define OPTION_VAL_4_3_CHT NULL
#define OPTION_VAL_16_9_CHT NULL
#define OPTION_VAL_LETTERBOX_CHT NULL
#define XEMU_ASPECT_RATIO_LABEL_CHT NULL
#define XEMU_ASPECT_RATIO_INFO_0_CHT NULL
#define OPTION_VAL_AUTO_CHT "自動"
#define XEMU_SURFACE_SCALE_LABEL_CHT NULL
#define XEMU_SURFACE_SCALE_INFO_0_CHT NULL
#define OPTION_VAL_1_CHT NULL
#define OPTION_VAL_2_CHT NULL
#define OPTION_VAL_3_CHT NULL
#define OPTION_VAL_4_CHT NULL
#define OPTION_VAL_5_CHT NULL
#define OPTION_VAL_6_CHT NULL
#define OPTION_VAL_7_CHT NULL
#define OPTION_VAL_8_CHT NULL
#define OPTION_VAL_9_CHT NULL
#define OPTION_VAL_10_CHT NULL
#define XEMU_AVPACK_LABEL_CHT NULL
#define XEMU_AVPACK_INFO_0_CHT NULL
#define OPTION_VAL_HDTV_CHT NULL
#define OPTION_VAL_COMPOSITE_CHT "AV端子 (複合端子)"
#define OPTION_VAL_SVIDEO_CHT "S-端子 (獨立視訊端子)"
#define OPTION_VAL_SCART_CHT NULL
#define OPTION_VAL_VGA_CHT NULL
#define XEMU_AUDIO_THREAD_LABEL_CHT NULL
#define XEMU_AUDIO_THREAD_INFO_0_CHT NULL
#define XEMU_USE_DSP_LABEL_CHT NULL
#define XEMU_USE_DSP_INFO_0_CHT NULL
#define XEMU_DSP_JIT_LABEL_CHT NULL
#define XEMU_DSP_JIT_INFO_0_CHT NULL
#define XEMU_HRTF_LABEL_CHT NULL
#define XEMU_HRTF_INFO_0_CHT NULL
#define XEMU_VP_WORKERS_LABEL_CHT NULL
#define XEMU_VP_WORKERS_INFO_0_CHT NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_CHT NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_CHT NULL
#define XEMU_AUDIO_VOLUME_LABEL_CHT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CHT NULL
#define OPTION_VAL_100_CHT NULL
#define OPTION_VAL_80_CHT NULL
#define OPTION_VAL_60_CHT NULL
#define OPTION_VAL_40_CHT NULL
#define OPTION_VAL_20_CHT NULL
#define OPTION_VAL_0_CHT NULL
#define XEMU_VK_FAST_PATHS_LABEL_CHT NULL
#define XEMU_VK_FAST_PATHS_INFO_0_CHT NULL
#define OPTION_VAL_ALL_CHT "全部"
#define OPTION_VAL_NO_GPL_CHT NULL
#define OPTION_VAL_NO_DYN_CHT NULL
#define OPTION_VAL_NONE_CHT "無"
#define XEMU_RUMBLE_P1_LABEL_CHT NULL
#define XEMU_RUMBLE_P1_INFO_0_CHT NULL
#define XEMU_RUMBLE_P2_LABEL_CHT NULL
#define XEMU_RUMBLE_P2_INFO_0_CHT NULL
#define XEMU_DEADZONE_P1_LABEL_CHT NULL
#define XEMU_DEADZONE_P1_INFO_0_CHT NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_CHT NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_CHT NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_CHT NULL
#define OPTION_VAL_15_CHT NULL
#define OPTION_VAL_25_CHT NULL
#define OPTION_VAL_30_CHT NULL
#define XEMU_DEADZONE_P2_LABEL_CHT NULL
#define XEMU_DEADZONE_P2_INFO_0_CHT NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_CHT NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_CHT NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_CHT NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_CHT NULL
#define OPTION_VAL_MOUSE_CHT "滑鼠"
#define OPTION_VAL_STICK_CHT NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_CHT NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_CHT NULL
#define XEMU_CHIHIRO_FFB_LABEL_CHT NULL
#define XEMU_CHIHIRO_FFB_INFO_0_CHT NULL
#define OPTION_VAL_50_CHT NULL
#define OPTION_VAL_75_CHT NULL
#define OPTION_VAL_150_CHT NULL
#define OPTION_VAL_200_CHT NULL

struct retro_core_option_v2_category option_cats_cht[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_CHT,
        CATEGORY_SYSTEM_INFO_0_CHT
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_CHT,
        CATEGORY_VIDEO_INFO_0_CHT
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_CHT,
        CATEGORY_AUDIO_INFO_0_CHT
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_CHT,
        CATEGORY_CONTROLS_INFO_0_CHT
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_CHT,
        CATEGORY_CHIHIRO_INFO_0_CHT
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cht[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_CHT,
        NULL,
        XEMU_MEMORY_INFO_0_CHT,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_CHT },
            { "128", OPTION_VAL_128_CHT },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_CHT,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_CHT,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_CHT },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_CHT,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_CHT,
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
        XEMU_HARD_FPU_LABEL_CHT,
        NULL,
        XEMU_HARD_FPU_INFO_0_CHT,
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
        XEMU_CPU_BOOST_LABEL_CHT,
        NULL,
        XEMU_CPU_BOOST_INFO_0_CHT,
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
        XEMU_HDD_TRIM_LABEL_CHT,
        NULL,
        XEMU_HDD_TRIM_INFO_0_CHT,
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
        XEMU_RENDERER_LABEL_CHT,
        NULL,
        XEMU_RENDERER_INFO_0_CHT,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_CHT },
            { "opengl", OPTION_VAL_OPENGL_CHT },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_CHT,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_CHT,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_CHT },
            { "4:3",       OPTION_VAL_4_3_CHT },
            { "16:9",      OPTION_VAL_16_9_CHT },
            { "letterbox", OPTION_VAL_LETTERBOX_CHT },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_CHT,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_CHT,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_CHT },
            { "4:3",  OPTION_VAL_4_3_CHT },
            { "16:9", OPTION_VAL_16_9_CHT },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_CHT,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_CHT,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_CHT },
            { "2", OPTION_VAL_2_CHT },
            { "3", OPTION_VAL_3_CHT },
            { "4", OPTION_VAL_4_CHT },
            { "5", OPTION_VAL_5_CHT },
            { "6", OPTION_VAL_6_CHT },
            { "7", OPTION_VAL_7_CHT },
            { "8", OPTION_VAL_8_CHT },
            { "9", OPTION_VAL_9_CHT },
            { "10", OPTION_VAL_10_CHT },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_CHT,
        NULL,
        XEMU_AVPACK_INFO_0_CHT,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_CHT },
            { "composite", OPTION_VAL_COMPOSITE_CHT },
            { "svideo",    OPTION_VAL_SVIDEO_CHT },
            { "scart",     OPTION_VAL_SCART_CHT },
            { "vga",       OPTION_VAL_VGA_CHT },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_CHT,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_CHT,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_CHT,
        NULL,
        XEMU_USE_DSP_INFO_0_CHT,
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
        XEMU_DSP_JIT_LABEL_CHT,
        NULL,
        XEMU_DSP_JIT_INFO_0_CHT,
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
        XEMU_HRTF_LABEL_CHT,
        NULL,
        XEMU_HRTF_INFO_0_CHT,
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
        XEMU_VP_WORKERS_LABEL_CHT,
        NULL,
        XEMU_VP_WORKERS_INFO_0_CHT,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_CHT },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_CHT,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_CHT,
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
        XEMU_AUDIO_VOLUME_LABEL_CHT,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_CHT,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_CHT },
            { "80",  OPTION_VAL_80_CHT },
            { "60",  OPTION_VAL_60_CHT },
            { "40",  OPTION_VAL_40_CHT },
            { "20",  OPTION_VAL_20_CHT },
            { "0",   OPTION_VAL_0_CHT },
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
        XEMU_VK_FAST_PATHS_LABEL_CHT,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_CHT,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_CHT },
            { "no_gpl",   OPTION_VAL_NO_GPL_CHT },
            { "no_dyn",   OPTION_VAL_NO_DYN_CHT },
            { "none",     OPTION_VAL_NONE_CHT },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_CHT,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_CHT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_CHT,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_CHT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_CHT,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_CHT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CHT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CHT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CHT },
            { "15", OPTION_VAL_15_CHT },
            { "20", OPTION_VAL_20_CHT },
            { "25", OPTION_VAL_25_CHT },
            { "30", OPTION_VAL_30_CHT },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_CHT,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_CHT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CHT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CHT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CHT },
            { "15", OPTION_VAL_15_CHT },
            { "20", OPTION_VAL_20_CHT },
            { "25", OPTION_VAL_25_CHT },
            { "30", OPTION_VAL_30_CHT },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_CHT,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_CHT,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_CHT,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_CHT,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_CHT },
            { "stick", OPTION_VAL_STICK_CHT },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_CHT,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_CHT,
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
        XEMU_CHIHIRO_FFB_LABEL_CHT,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_CHT,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_CHT },
            { "50",  OPTION_VAL_50_CHT },
            { "75",  OPTION_VAL_75_CHT },
            { "100", OPTION_VAL_100_CHT },
            { "150", OPTION_VAL_150_CHT },
            { "200", OPTION_VAL_200_CHT },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_cht = {
   option_cats_cht,
   option_defs_cht
};

/* RETRO_LANGUAGE_CS */

#define CATEGORY_SYSTEM_LABEL_CS NULL
#define CATEGORY_SYSTEM_INFO_0_CS NULL
#define CATEGORY_VIDEO_LABEL_CS NULL
#define CATEGORY_VIDEO_INFO_0_CS NULL
#define CATEGORY_AUDIO_LABEL_CS "Zvuk"
#define CATEGORY_AUDIO_INFO_0_CS NULL
#define CATEGORY_CONTROLS_LABEL_CS "Her. ovladače"
#define CATEGORY_CONTROLS_INFO_0_CS NULL
#define CATEGORY_CHIHIRO_LABEL_CS NULL
#define CATEGORY_CHIHIRO_INFO_0_CS NULL
#define XEMU_MEMORY_LABEL_CS NULL
#define XEMU_MEMORY_INFO_0_CS NULL
#define OPTION_VAL_64_CS NULL
#define OPTION_VAL_128_CS NULL
#define XEMU_NETWORK_BACKEND_LABEL_CS NULL
#define XEMU_NETWORK_BACKEND_INFO_0_CS NULL
#define OPTION_VAL_NAT_CS NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CS NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CS NULL
#define XEMU_HARD_FPU_LABEL_CS NULL
#define XEMU_HARD_FPU_INFO_0_CS NULL
#define XEMU_CPU_BOOST_LABEL_CS NULL
#define XEMU_CPU_BOOST_INFO_0_CS NULL
#define XEMU_HDD_TRIM_LABEL_CS NULL
#define XEMU_HDD_TRIM_INFO_0_CS NULL
#define XEMU_RENDERER_LABEL_CS NULL
#define XEMU_RENDERER_INFO_0_CS NULL
#define OPTION_VAL_VULKAN_CS NULL
#define OPTION_VAL_OPENGL_CS NULL
#define XEMU_VIDEO_ASPECT_LABEL_CS NULL
#define XEMU_VIDEO_ASPECT_INFO_0_CS NULL
#define OPTION_VAL_DASHBOARD_CS NULL
#define OPTION_VAL_4_3_CS NULL
#define OPTION_VAL_16_9_CS NULL
#define OPTION_VAL_LETTERBOX_CS NULL
#define XEMU_ASPECT_RATIO_LABEL_CS "Poměr Stran Jádra"
#define XEMU_ASPECT_RATIO_INFO_0_CS NULL
#define OPTION_VAL_AUTO_CS NULL
#define XEMU_SURFACE_SCALE_LABEL_CS NULL
#define XEMU_SURFACE_SCALE_INFO_0_CS NULL
#define OPTION_VAL_1_CS NULL
#define OPTION_VAL_2_CS NULL
#define OPTION_VAL_3_CS NULL
#define OPTION_VAL_4_CS NULL
#define OPTION_VAL_5_CS NULL
#define OPTION_VAL_6_CS NULL
#define OPTION_VAL_7_CS NULL
#define OPTION_VAL_8_CS NULL
#define OPTION_VAL_9_CS NULL
#define OPTION_VAL_10_CS NULL
#define XEMU_AVPACK_LABEL_CS NULL
#define XEMU_AVPACK_INFO_0_CS NULL
#define OPTION_VAL_HDTV_CS NULL
#define OPTION_VAL_COMPOSITE_CS "Kompozitní"
#define OPTION_VAL_SVIDEO_CS NULL
#define OPTION_VAL_SCART_CS NULL
#define OPTION_VAL_VGA_CS NULL
#define XEMU_AUDIO_THREAD_LABEL_CS NULL
#define XEMU_AUDIO_THREAD_INFO_0_CS NULL
#define XEMU_USE_DSP_LABEL_CS NULL
#define XEMU_USE_DSP_INFO_0_CS NULL
#define XEMU_DSP_JIT_LABEL_CS NULL
#define XEMU_DSP_JIT_INFO_0_CS NULL
#define XEMU_HRTF_LABEL_CS NULL
#define XEMU_HRTF_INFO_0_CS NULL
#define XEMU_VP_WORKERS_LABEL_CS NULL
#define XEMU_VP_WORKERS_INFO_0_CS NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_CS NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_CS NULL
#define XEMU_AUDIO_VOLUME_LABEL_CS NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CS NULL
#define OPTION_VAL_100_CS NULL
#define OPTION_VAL_80_CS NULL
#define OPTION_VAL_60_CS NULL
#define OPTION_VAL_40_CS NULL
#define OPTION_VAL_20_CS NULL
#define OPTION_VAL_0_CS NULL
#define XEMU_VK_FAST_PATHS_LABEL_CS NULL
#define XEMU_VK_FAST_PATHS_INFO_0_CS NULL
#define OPTION_VAL_ALL_CS "Vše"
#define OPTION_VAL_NO_GPL_CS NULL
#define OPTION_VAL_NO_DYN_CS NULL
#define OPTION_VAL_NONE_CS "Žádné"
#define XEMU_RUMBLE_P1_LABEL_CS NULL
#define XEMU_RUMBLE_P1_INFO_0_CS NULL
#define XEMU_RUMBLE_P2_LABEL_CS NULL
#define XEMU_RUMBLE_P2_INFO_0_CS NULL
#define XEMU_DEADZONE_P1_LABEL_CS NULL
#define XEMU_DEADZONE_P1_INFO_0_CS NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_CS NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_CS NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_CS NULL
#define OPTION_VAL_15_CS NULL
#define OPTION_VAL_25_CS NULL
#define OPTION_VAL_30_CS NULL
#define XEMU_DEADZONE_P2_LABEL_CS NULL
#define XEMU_DEADZONE_P2_INFO_0_CS NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_CS NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_CS NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_CS NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_CS NULL
#define OPTION_VAL_MOUSE_CS "Myš"
#define OPTION_VAL_STICK_CS NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_CS NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_CS NULL
#define XEMU_CHIHIRO_FFB_LABEL_CS NULL
#define XEMU_CHIHIRO_FFB_INFO_0_CS NULL
#define OPTION_VAL_50_CS NULL
#define OPTION_VAL_75_CS NULL
#define OPTION_VAL_150_CS NULL
#define OPTION_VAL_200_CS NULL

struct retro_core_option_v2_category option_cats_cs[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_CS,
        CATEGORY_SYSTEM_INFO_0_CS
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_CS,
        CATEGORY_VIDEO_INFO_0_CS
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_CS,
        CATEGORY_AUDIO_INFO_0_CS
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_CS,
        CATEGORY_CONTROLS_INFO_0_CS
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_CS,
        CATEGORY_CHIHIRO_INFO_0_CS
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cs[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_CS,
        NULL,
        XEMU_MEMORY_INFO_0_CS,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_CS },
            { "128", OPTION_VAL_128_CS },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_CS,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_CS,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_CS },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_CS,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_CS,
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
        XEMU_HARD_FPU_LABEL_CS,
        NULL,
        XEMU_HARD_FPU_INFO_0_CS,
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
        XEMU_CPU_BOOST_LABEL_CS,
        NULL,
        XEMU_CPU_BOOST_INFO_0_CS,
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
        XEMU_HDD_TRIM_LABEL_CS,
        NULL,
        XEMU_HDD_TRIM_INFO_0_CS,
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
        XEMU_RENDERER_LABEL_CS,
        NULL,
        XEMU_RENDERER_INFO_0_CS,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_CS },
            { "opengl", OPTION_VAL_OPENGL_CS },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_CS,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_CS,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_CS },
            { "4:3",       OPTION_VAL_4_3_CS },
            { "16:9",      OPTION_VAL_16_9_CS },
            { "letterbox", OPTION_VAL_LETTERBOX_CS },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_CS,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_CS,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_CS },
            { "4:3",  OPTION_VAL_4_3_CS },
            { "16:9", OPTION_VAL_16_9_CS },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_CS,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_CS,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_CS },
            { "2", OPTION_VAL_2_CS },
            { "3", OPTION_VAL_3_CS },
            { "4", OPTION_VAL_4_CS },
            { "5", OPTION_VAL_5_CS },
            { "6", OPTION_VAL_6_CS },
            { "7", OPTION_VAL_7_CS },
            { "8", OPTION_VAL_8_CS },
            { "9", OPTION_VAL_9_CS },
            { "10", OPTION_VAL_10_CS },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_CS,
        NULL,
        XEMU_AVPACK_INFO_0_CS,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_CS },
            { "composite", OPTION_VAL_COMPOSITE_CS },
            { "svideo",    OPTION_VAL_SVIDEO_CS },
            { "scart",     OPTION_VAL_SCART_CS },
            { "vga",       OPTION_VAL_VGA_CS },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_CS,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_CS,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_CS,
        NULL,
        XEMU_USE_DSP_INFO_0_CS,
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
        XEMU_DSP_JIT_LABEL_CS,
        NULL,
        XEMU_DSP_JIT_INFO_0_CS,
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
        XEMU_HRTF_LABEL_CS,
        NULL,
        XEMU_HRTF_INFO_0_CS,
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
        XEMU_VP_WORKERS_LABEL_CS,
        NULL,
        XEMU_VP_WORKERS_INFO_0_CS,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_CS },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_CS,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_CS,
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
        XEMU_AUDIO_VOLUME_LABEL_CS,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_CS,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_CS },
            { "80",  OPTION_VAL_80_CS },
            { "60",  OPTION_VAL_60_CS },
            { "40",  OPTION_VAL_40_CS },
            { "20",  OPTION_VAL_20_CS },
            { "0",   OPTION_VAL_0_CS },
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
        XEMU_VK_FAST_PATHS_LABEL_CS,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_CS,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_CS },
            { "no_gpl",   OPTION_VAL_NO_GPL_CS },
            { "no_dyn",   OPTION_VAL_NO_DYN_CS },
            { "none",     OPTION_VAL_NONE_CS },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_CS,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_CS,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_CS,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_CS,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_CS,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_CS,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CS },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CS },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CS },
            { "15", OPTION_VAL_15_CS },
            { "20", OPTION_VAL_20_CS },
            { "25", OPTION_VAL_25_CS },
            { "30", OPTION_VAL_30_CS },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_CS,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_CS,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CS },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CS },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CS },
            { "15", OPTION_VAL_15_CS },
            { "20", OPTION_VAL_20_CS },
            { "25", OPTION_VAL_25_CS },
            { "30", OPTION_VAL_30_CS },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_CS,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_CS,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_CS,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_CS,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_CS },
            { "stick", OPTION_VAL_STICK_CS },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_CS,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_CS,
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
        XEMU_CHIHIRO_FFB_LABEL_CS,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_CS,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_CS },
            { "50",  OPTION_VAL_50_CS },
            { "75",  OPTION_VAL_75_CS },
            { "100", OPTION_VAL_100_CS },
            { "150", OPTION_VAL_150_CS },
            { "200", OPTION_VAL_200_CS },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_cs = {
   option_cats_cs,
   option_defs_cs
};

/* RETRO_LANGUAGE_CY */

#define CATEGORY_SYSTEM_LABEL_CY NULL
#define CATEGORY_SYSTEM_INFO_0_CY NULL
#define CATEGORY_VIDEO_LABEL_CY NULL
#define CATEGORY_VIDEO_INFO_0_CY NULL
#define CATEGORY_AUDIO_LABEL_CY NULL
#define CATEGORY_AUDIO_INFO_0_CY NULL
#define CATEGORY_CONTROLS_LABEL_CY NULL
#define CATEGORY_CONTROLS_INFO_0_CY NULL
#define CATEGORY_CHIHIRO_LABEL_CY NULL
#define CATEGORY_CHIHIRO_INFO_0_CY NULL
#define XEMU_MEMORY_LABEL_CY NULL
#define XEMU_MEMORY_INFO_0_CY NULL
#define OPTION_VAL_64_CY NULL
#define OPTION_VAL_128_CY NULL
#define XEMU_NETWORK_BACKEND_LABEL_CY NULL
#define XEMU_NETWORK_BACKEND_INFO_0_CY NULL
#define OPTION_VAL_NAT_CY NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CY NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CY NULL
#define XEMU_HARD_FPU_LABEL_CY NULL
#define XEMU_HARD_FPU_INFO_0_CY NULL
#define XEMU_CPU_BOOST_LABEL_CY NULL
#define XEMU_CPU_BOOST_INFO_0_CY NULL
#define XEMU_HDD_TRIM_LABEL_CY NULL
#define XEMU_HDD_TRIM_INFO_0_CY NULL
#define XEMU_RENDERER_LABEL_CY NULL
#define XEMU_RENDERER_INFO_0_CY NULL
#define OPTION_VAL_VULKAN_CY NULL
#define OPTION_VAL_OPENGL_CY NULL
#define XEMU_VIDEO_ASPECT_LABEL_CY NULL
#define XEMU_VIDEO_ASPECT_INFO_0_CY NULL
#define OPTION_VAL_DASHBOARD_CY NULL
#define OPTION_VAL_4_3_CY NULL
#define OPTION_VAL_16_9_CY NULL
#define OPTION_VAL_LETTERBOX_CY NULL
#define XEMU_ASPECT_RATIO_LABEL_CY NULL
#define XEMU_ASPECT_RATIO_INFO_0_CY NULL
#define OPTION_VAL_AUTO_CY NULL
#define XEMU_SURFACE_SCALE_LABEL_CY NULL
#define XEMU_SURFACE_SCALE_INFO_0_CY NULL
#define OPTION_VAL_1_CY NULL
#define OPTION_VAL_2_CY NULL
#define OPTION_VAL_3_CY NULL
#define OPTION_VAL_4_CY NULL
#define OPTION_VAL_5_CY NULL
#define OPTION_VAL_6_CY NULL
#define OPTION_VAL_7_CY NULL
#define OPTION_VAL_8_CY NULL
#define OPTION_VAL_9_CY NULL
#define OPTION_VAL_10_CY NULL
#define XEMU_AVPACK_LABEL_CY NULL
#define XEMU_AVPACK_INFO_0_CY NULL
#define OPTION_VAL_HDTV_CY NULL
#define OPTION_VAL_COMPOSITE_CY NULL
#define OPTION_VAL_SVIDEO_CY NULL
#define OPTION_VAL_SCART_CY NULL
#define OPTION_VAL_VGA_CY NULL
#define XEMU_AUDIO_THREAD_LABEL_CY NULL
#define XEMU_AUDIO_THREAD_INFO_0_CY NULL
#define XEMU_USE_DSP_LABEL_CY NULL
#define XEMU_USE_DSP_INFO_0_CY NULL
#define XEMU_DSP_JIT_LABEL_CY NULL
#define XEMU_DSP_JIT_INFO_0_CY NULL
#define XEMU_HRTF_LABEL_CY NULL
#define XEMU_HRTF_INFO_0_CY NULL
#define XEMU_VP_WORKERS_LABEL_CY NULL
#define XEMU_VP_WORKERS_INFO_0_CY NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_CY NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_CY NULL
#define XEMU_AUDIO_VOLUME_LABEL_CY NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CY NULL
#define OPTION_VAL_100_CY NULL
#define OPTION_VAL_80_CY NULL
#define OPTION_VAL_60_CY NULL
#define OPTION_VAL_40_CY NULL
#define OPTION_VAL_20_CY NULL
#define OPTION_VAL_0_CY NULL
#define XEMU_VK_FAST_PATHS_LABEL_CY NULL
#define XEMU_VK_FAST_PATHS_INFO_0_CY NULL
#define OPTION_VAL_ALL_CY "Popeth"
#define OPTION_VAL_NO_GPL_CY NULL
#define OPTION_VAL_NO_DYN_CY NULL
#define OPTION_VAL_NONE_CY "Dim"
#define XEMU_RUMBLE_P1_LABEL_CY NULL
#define XEMU_RUMBLE_P1_INFO_0_CY NULL
#define XEMU_RUMBLE_P2_LABEL_CY NULL
#define XEMU_RUMBLE_P2_INFO_0_CY NULL
#define XEMU_DEADZONE_P1_LABEL_CY NULL
#define XEMU_DEADZONE_P1_INFO_0_CY NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_CY NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_CY NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_CY NULL
#define OPTION_VAL_15_CY NULL
#define OPTION_VAL_25_CY NULL
#define OPTION_VAL_30_CY NULL
#define XEMU_DEADZONE_P2_LABEL_CY NULL
#define XEMU_DEADZONE_P2_INFO_0_CY NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_CY NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_CY NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_CY NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_CY NULL
#define OPTION_VAL_MOUSE_CY NULL
#define OPTION_VAL_STICK_CY NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_CY NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_CY NULL
#define XEMU_CHIHIRO_FFB_LABEL_CY NULL
#define XEMU_CHIHIRO_FFB_INFO_0_CY NULL
#define OPTION_VAL_50_CY NULL
#define OPTION_VAL_75_CY NULL
#define OPTION_VAL_150_CY NULL
#define OPTION_VAL_200_CY NULL

struct retro_core_option_v2_category option_cats_cy[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_CY,
        CATEGORY_SYSTEM_INFO_0_CY
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_CY,
        CATEGORY_VIDEO_INFO_0_CY
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_CY,
        CATEGORY_AUDIO_INFO_0_CY
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_CY,
        CATEGORY_CONTROLS_INFO_0_CY
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_CY,
        CATEGORY_CHIHIRO_INFO_0_CY
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cy[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_CY,
        NULL,
        XEMU_MEMORY_INFO_0_CY,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_CY },
            { "128", OPTION_VAL_128_CY },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_CY,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_CY,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_CY },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_CY,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_CY,
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
        XEMU_HARD_FPU_LABEL_CY,
        NULL,
        XEMU_HARD_FPU_INFO_0_CY,
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
        XEMU_CPU_BOOST_LABEL_CY,
        NULL,
        XEMU_CPU_BOOST_INFO_0_CY,
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
        XEMU_HDD_TRIM_LABEL_CY,
        NULL,
        XEMU_HDD_TRIM_INFO_0_CY,
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
        XEMU_RENDERER_LABEL_CY,
        NULL,
        XEMU_RENDERER_INFO_0_CY,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_CY },
            { "opengl", OPTION_VAL_OPENGL_CY },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_CY,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_CY,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_CY },
            { "4:3",       OPTION_VAL_4_3_CY },
            { "16:9",      OPTION_VAL_16_9_CY },
            { "letterbox", OPTION_VAL_LETTERBOX_CY },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_CY,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_CY,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_CY },
            { "4:3",  OPTION_VAL_4_3_CY },
            { "16:9", OPTION_VAL_16_9_CY },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_CY,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_CY,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_CY },
            { "2", OPTION_VAL_2_CY },
            { "3", OPTION_VAL_3_CY },
            { "4", OPTION_VAL_4_CY },
            { "5", OPTION_VAL_5_CY },
            { "6", OPTION_VAL_6_CY },
            { "7", OPTION_VAL_7_CY },
            { "8", OPTION_VAL_8_CY },
            { "9", OPTION_VAL_9_CY },
            { "10", OPTION_VAL_10_CY },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_CY,
        NULL,
        XEMU_AVPACK_INFO_0_CY,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_CY },
            { "composite", OPTION_VAL_COMPOSITE_CY },
            { "svideo",    OPTION_VAL_SVIDEO_CY },
            { "scart",     OPTION_VAL_SCART_CY },
            { "vga",       OPTION_VAL_VGA_CY },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_CY,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_CY,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_CY,
        NULL,
        XEMU_USE_DSP_INFO_0_CY,
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
        XEMU_DSP_JIT_LABEL_CY,
        NULL,
        XEMU_DSP_JIT_INFO_0_CY,
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
        XEMU_HRTF_LABEL_CY,
        NULL,
        XEMU_HRTF_INFO_0_CY,
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
        XEMU_VP_WORKERS_LABEL_CY,
        NULL,
        XEMU_VP_WORKERS_INFO_0_CY,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_CY },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_CY,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_CY,
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
        XEMU_AUDIO_VOLUME_LABEL_CY,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_CY,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_CY },
            { "80",  OPTION_VAL_80_CY },
            { "60",  OPTION_VAL_60_CY },
            { "40",  OPTION_VAL_40_CY },
            { "20",  OPTION_VAL_20_CY },
            { "0",   OPTION_VAL_0_CY },
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
        XEMU_VK_FAST_PATHS_LABEL_CY,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_CY,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_CY },
            { "no_gpl",   OPTION_VAL_NO_GPL_CY },
            { "no_dyn",   OPTION_VAL_NO_DYN_CY },
            { "none",     OPTION_VAL_NONE_CY },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_CY,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_CY,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_CY,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_CY,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_CY,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_CY,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CY },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CY },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CY },
            { "15", OPTION_VAL_15_CY },
            { "20", OPTION_VAL_20_CY },
            { "25", OPTION_VAL_25_CY },
            { "30", OPTION_VAL_30_CY },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_CY,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_CY,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_CY },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_CY },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_CY },
            { "15", OPTION_VAL_15_CY },
            { "20", OPTION_VAL_20_CY },
            { "25", OPTION_VAL_25_CY },
            { "30", OPTION_VAL_30_CY },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_CY,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_CY,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_CY,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_CY,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_CY },
            { "stick", OPTION_VAL_STICK_CY },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_CY,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_CY,
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
        XEMU_CHIHIRO_FFB_LABEL_CY,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_CY,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_CY },
            { "50",  OPTION_VAL_50_CY },
            { "75",  OPTION_VAL_75_CY },
            { "100", OPTION_VAL_100_CY },
            { "150", OPTION_VAL_150_CY },
            { "200", OPTION_VAL_200_CY },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_cy = {
   option_cats_cy,
   option_defs_cy
};

/* RETRO_LANGUAGE_DA */

#define CATEGORY_SYSTEM_LABEL_DA NULL
#define CATEGORY_SYSTEM_INFO_0_DA NULL
#define CATEGORY_VIDEO_LABEL_DA NULL
#define CATEGORY_VIDEO_INFO_0_DA NULL
#define CATEGORY_AUDIO_LABEL_DA "Lyd"
#define CATEGORY_AUDIO_INFO_0_DA NULL
#define CATEGORY_CONTROLS_LABEL_DA NULL
#define CATEGORY_CONTROLS_INFO_0_DA NULL
#define CATEGORY_CHIHIRO_LABEL_DA NULL
#define CATEGORY_CHIHIRO_INFO_0_DA NULL
#define XEMU_MEMORY_LABEL_DA NULL
#define XEMU_MEMORY_INFO_0_DA NULL
#define OPTION_VAL_64_DA NULL
#define OPTION_VAL_128_DA NULL
#define XEMU_NETWORK_BACKEND_LABEL_DA NULL
#define XEMU_NETWORK_BACKEND_INFO_0_DA NULL
#define OPTION_VAL_NAT_DA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_DA NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_DA NULL
#define XEMU_HARD_FPU_LABEL_DA NULL
#define XEMU_HARD_FPU_INFO_0_DA NULL
#define XEMU_CPU_BOOST_LABEL_DA NULL
#define XEMU_CPU_BOOST_INFO_0_DA NULL
#define XEMU_HDD_TRIM_LABEL_DA NULL
#define XEMU_HDD_TRIM_INFO_0_DA NULL
#define XEMU_RENDERER_LABEL_DA NULL
#define XEMU_RENDERER_INFO_0_DA NULL
#define OPTION_VAL_VULKAN_DA NULL
#define OPTION_VAL_OPENGL_DA NULL
#define XEMU_VIDEO_ASPECT_LABEL_DA NULL
#define XEMU_VIDEO_ASPECT_INFO_0_DA NULL
#define OPTION_VAL_DASHBOARD_DA NULL
#define OPTION_VAL_4_3_DA NULL
#define OPTION_VAL_16_9_DA NULL
#define OPTION_VAL_LETTERBOX_DA NULL
#define XEMU_ASPECT_RATIO_LABEL_DA NULL
#define XEMU_ASPECT_RATIO_INFO_0_DA NULL
#define OPTION_VAL_AUTO_DA NULL
#define XEMU_SURFACE_SCALE_LABEL_DA NULL
#define XEMU_SURFACE_SCALE_INFO_0_DA NULL
#define OPTION_VAL_1_DA NULL
#define OPTION_VAL_2_DA NULL
#define OPTION_VAL_3_DA NULL
#define OPTION_VAL_4_DA NULL
#define OPTION_VAL_5_DA NULL
#define OPTION_VAL_6_DA NULL
#define OPTION_VAL_7_DA NULL
#define OPTION_VAL_8_DA NULL
#define OPTION_VAL_9_DA NULL
#define OPTION_VAL_10_DA NULL
#define XEMU_AVPACK_LABEL_DA NULL
#define XEMU_AVPACK_INFO_0_DA NULL
#define OPTION_VAL_HDTV_DA NULL
#define OPTION_VAL_COMPOSITE_DA NULL
#define OPTION_VAL_SVIDEO_DA NULL
#define OPTION_VAL_SCART_DA NULL
#define OPTION_VAL_VGA_DA NULL
#define XEMU_AUDIO_THREAD_LABEL_DA NULL
#define XEMU_AUDIO_THREAD_INFO_0_DA NULL
#define XEMU_USE_DSP_LABEL_DA NULL
#define XEMU_USE_DSP_INFO_0_DA NULL
#define XEMU_DSP_JIT_LABEL_DA NULL
#define XEMU_DSP_JIT_INFO_0_DA NULL
#define XEMU_HRTF_LABEL_DA NULL
#define XEMU_HRTF_INFO_0_DA NULL
#define XEMU_VP_WORKERS_LABEL_DA NULL
#define XEMU_VP_WORKERS_INFO_0_DA NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_DA NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_DA NULL
#define XEMU_AUDIO_VOLUME_LABEL_DA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_DA NULL
#define OPTION_VAL_100_DA NULL
#define OPTION_VAL_80_DA NULL
#define OPTION_VAL_60_DA NULL
#define OPTION_VAL_40_DA NULL
#define OPTION_VAL_20_DA NULL
#define OPTION_VAL_0_DA NULL
#define XEMU_VK_FAST_PATHS_LABEL_DA NULL
#define XEMU_VK_FAST_PATHS_INFO_0_DA NULL
#define OPTION_VAL_ALL_DA NULL
#define OPTION_VAL_NO_GPL_DA NULL
#define OPTION_VAL_NO_DYN_DA NULL
#define OPTION_VAL_NONE_DA NULL
#define XEMU_RUMBLE_P1_LABEL_DA NULL
#define XEMU_RUMBLE_P1_INFO_0_DA NULL
#define XEMU_RUMBLE_P2_LABEL_DA NULL
#define XEMU_RUMBLE_P2_INFO_0_DA NULL
#define XEMU_DEADZONE_P1_LABEL_DA NULL
#define XEMU_DEADZONE_P1_INFO_0_DA NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_DA NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_DA NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_DA NULL
#define OPTION_VAL_15_DA NULL
#define OPTION_VAL_25_DA NULL
#define OPTION_VAL_30_DA NULL
#define XEMU_DEADZONE_P2_LABEL_DA NULL
#define XEMU_DEADZONE_P2_INFO_0_DA NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_DA NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_DA NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_DA NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_DA NULL
#define OPTION_VAL_MOUSE_DA NULL
#define OPTION_VAL_STICK_DA NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_DA NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_DA NULL
#define XEMU_CHIHIRO_FFB_LABEL_DA NULL
#define XEMU_CHIHIRO_FFB_INFO_0_DA NULL
#define OPTION_VAL_50_DA NULL
#define OPTION_VAL_75_DA NULL
#define OPTION_VAL_150_DA NULL
#define OPTION_VAL_200_DA NULL

struct retro_core_option_v2_category option_cats_da[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_DA,
        CATEGORY_SYSTEM_INFO_0_DA
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_DA,
        CATEGORY_VIDEO_INFO_0_DA
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_DA,
        CATEGORY_AUDIO_INFO_0_DA
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_DA,
        CATEGORY_CONTROLS_INFO_0_DA
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_DA,
        CATEGORY_CHIHIRO_INFO_0_DA
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_da[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_DA,
        NULL,
        XEMU_MEMORY_INFO_0_DA,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_DA },
            { "128", OPTION_VAL_128_DA },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_DA,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_DA,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_DA },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_DA,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_DA,
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
        XEMU_HARD_FPU_LABEL_DA,
        NULL,
        XEMU_HARD_FPU_INFO_0_DA,
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
        XEMU_CPU_BOOST_LABEL_DA,
        NULL,
        XEMU_CPU_BOOST_INFO_0_DA,
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
        XEMU_HDD_TRIM_LABEL_DA,
        NULL,
        XEMU_HDD_TRIM_INFO_0_DA,
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
        XEMU_RENDERER_LABEL_DA,
        NULL,
        XEMU_RENDERER_INFO_0_DA,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_DA },
            { "opengl", OPTION_VAL_OPENGL_DA },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_DA,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_DA,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_DA },
            { "4:3",       OPTION_VAL_4_3_DA },
            { "16:9",      OPTION_VAL_16_9_DA },
            { "letterbox", OPTION_VAL_LETTERBOX_DA },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_DA,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_DA,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_DA },
            { "4:3",  OPTION_VAL_4_3_DA },
            { "16:9", OPTION_VAL_16_9_DA },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_DA,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_DA,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_DA },
            { "2", OPTION_VAL_2_DA },
            { "3", OPTION_VAL_3_DA },
            { "4", OPTION_VAL_4_DA },
            { "5", OPTION_VAL_5_DA },
            { "6", OPTION_VAL_6_DA },
            { "7", OPTION_VAL_7_DA },
            { "8", OPTION_VAL_8_DA },
            { "9", OPTION_VAL_9_DA },
            { "10", OPTION_VAL_10_DA },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_DA,
        NULL,
        XEMU_AVPACK_INFO_0_DA,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_DA },
            { "composite", OPTION_VAL_COMPOSITE_DA },
            { "svideo",    OPTION_VAL_SVIDEO_DA },
            { "scart",     OPTION_VAL_SCART_DA },
            { "vga",       OPTION_VAL_VGA_DA },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_DA,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_DA,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_DA,
        NULL,
        XEMU_USE_DSP_INFO_0_DA,
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
        XEMU_DSP_JIT_LABEL_DA,
        NULL,
        XEMU_DSP_JIT_INFO_0_DA,
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
        XEMU_HRTF_LABEL_DA,
        NULL,
        XEMU_HRTF_INFO_0_DA,
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
        XEMU_VP_WORKERS_LABEL_DA,
        NULL,
        XEMU_VP_WORKERS_INFO_0_DA,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_DA },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_DA,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_DA,
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
        XEMU_AUDIO_VOLUME_LABEL_DA,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_DA,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_DA },
            { "80",  OPTION_VAL_80_DA },
            { "60",  OPTION_VAL_60_DA },
            { "40",  OPTION_VAL_40_DA },
            { "20",  OPTION_VAL_20_DA },
            { "0",   OPTION_VAL_0_DA },
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
        XEMU_VK_FAST_PATHS_LABEL_DA,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_DA,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_DA },
            { "no_gpl",   OPTION_VAL_NO_GPL_DA },
            { "no_dyn",   OPTION_VAL_NO_DYN_DA },
            { "none",     OPTION_VAL_NONE_DA },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_DA,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_DA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_DA,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_DA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_DA,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_DA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_DA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_DA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_DA },
            { "15", OPTION_VAL_15_DA },
            { "20", OPTION_VAL_20_DA },
            { "25", OPTION_VAL_25_DA },
            { "30", OPTION_VAL_30_DA },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_DA,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_DA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_DA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_DA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_DA },
            { "15", OPTION_VAL_15_DA },
            { "20", OPTION_VAL_20_DA },
            { "25", OPTION_VAL_25_DA },
            { "30", OPTION_VAL_30_DA },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_DA,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_DA,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_DA,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_DA,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_DA },
            { "stick", OPTION_VAL_STICK_DA },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_DA,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_DA,
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
        XEMU_CHIHIRO_FFB_LABEL_DA,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_DA,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_DA },
            { "50",  OPTION_VAL_50_DA },
            { "75",  OPTION_VAL_75_DA },
            { "100", OPTION_VAL_100_DA },
            { "150", OPTION_VAL_150_DA },
            { "200", OPTION_VAL_200_DA },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_da = {
   option_cats_da,
   option_defs_da
};

/* RETRO_LANGUAGE_DE */

#define CATEGORY_SYSTEM_LABEL_DE NULL
#define CATEGORY_SYSTEM_INFO_0_DE NULL
#define CATEGORY_VIDEO_LABEL_DE NULL
#define CATEGORY_VIDEO_INFO_0_DE "Videorendering-Einstellungen konfigurieren."
#define CATEGORY_AUDIO_LABEL_DE NULL
#define CATEGORY_AUDIO_INFO_0_DE "Audioemulationseinstellungen konfigurieren."
#define CATEGORY_CONTROLS_LABEL_DE "Steuerung"
#define CATEGORY_CONTROLS_INFO_0_DE NULL
#define CATEGORY_CHIHIRO_LABEL_DE NULL
#define CATEGORY_CHIHIRO_INFO_0_DE NULL
#define XEMU_MEMORY_LABEL_DE "Systemspeicher (MB)"
#define XEMU_MEMORY_INFO_0_DE "Größe des Systemspeichers. 64 MB ist der Standardwert; Debug-Kits verwenden 128 MB."
#define OPTION_VAL_64_DE NULL
#define OPTION_VAL_128_DE NULL
#define XEMU_NETWORK_BACKEND_LABEL_DE "Netzwerk-Backend"
#define XEMU_NETWORK_BACKEND_INFO_0_DE "Netzwerkunterstützung für Xbox-Spiele mit LAN-/System-Link-Funktionen aktivieren. Das NAT-Backend stellt grundlegende Konnektivität bereit."
#define OPTION_VAL_NAT_DE NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_DE "Startanimation überspringen"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_DE "Die Xbox-Startanimation überspringen."
#define XEMU_HARD_FPU_LABEL_DE "Hardware-FPU-Emulation"
#define XEMU_HARD_FPU_INFO_0_DE "Für die x87-Emulation die Host-FPU verwenden. Schneller, aber möglicherweise mit geringfügigen Ungenauigkeiten."
#define XEMU_CPU_BOOST_LABEL_DE NULL
#define XEMU_CPU_BOOST_INFO_0_DE NULL
#define XEMU_HDD_TRIM_LABEL_DE NULL
#define XEMU_HDD_TRIM_INFO_0_DE NULL
#define XEMU_RENDERER_LABEL_DE "Grafik-API (Neustart)"
#define XEMU_RENDERER_INFO_0_DE "Renderer für die Darstellung der emulierten GPU. Vulkan ist die Standardeinstellung; OpenGL dient als Ausweichlösung bei Treibern, mit denen Vulkan Probleme verursacht. Änderung wird nach einem Neustart von RetroArch wirksam. Unter Android wird immer Vulkan verwendet, unter macOS immer OpenGL."
#define OPTION_VAL_VULKAN_DE NULL
#define OPTION_VAL_OPENGL_DE NULL
#define XEMU_VIDEO_ASPECT_LABEL_DE NULL
#define XEMU_VIDEO_ASPECT_INFO_0_DE NULL
#define OPTION_VAL_DASHBOARD_DE NULL
#define OPTION_VAL_4_3_DE NULL
#define OPTION_VAL_16_9_DE NULL
#define OPTION_VAL_LETTERBOX_DE NULL
#define XEMU_ASPECT_RATIO_LABEL_DE "Core-Seitenverhältnis"
#define XEMU_ASPECT_RATIO_INFO_0_DE NULL
#define OPTION_VAL_AUTO_DE NULL
#define XEMU_SURFACE_SCALE_LABEL_DE NULL
#define XEMU_SURFACE_SCALE_INFO_0_DE "Skaliert die interne Renderauflösung. Höhere Werte verbessern die Bildqualität, verringern aber die Leistung."
#define OPTION_VAL_1_DE "1× (640 × 480)"
#define OPTION_VAL_2_DE "2× (1280 × 960)"
#define OPTION_VAL_3_DE "3× (1920 × 1440)"
#define OPTION_VAL_4_DE "4× (2560 × 1920)"
#define OPTION_VAL_5_DE "5× (3200 × 2400)"
#define OPTION_VAL_6_DE "6× (3840 × 2880)"
#define OPTION_VAL_7_DE "7× (4480 × 3360)"
#define OPTION_VAL_8_DE "8× (5120 × 3840)"
#define OPTION_VAL_9_DE "9× (5760 × 4320)"
#define OPTION_VAL_10_DE "10× (6400 × 4800)"
#define XEMU_AVPACK_LABEL_DE NULL
#define XEMU_AVPACK_INFO_0_DE "AV-Pakettyp auswählen. Beeinflusst die verfügbaren Videomodi."
#define OPTION_VAL_HDTV_DE NULL
#define OPTION_VAL_COMPOSITE_DE NULL
#define OPTION_VAL_SVIDEO_DE NULL
#define OPTION_VAL_SCART_DE NULL
#define OPTION_VAL_VGA_DE NULL
#define XEMU_AUDIO_THREAD_LABEL_DE "Audiothread (Neustart)"
#define XEMU_AUDIO_THREAD_INFO_0_DE NULL
#define XEMU_USE_DSP_LABEL_DE "APU-DSP-Emulation"
#define XEMU_USE_DSP_INFO_0_DE "DSP-Emulation für eine höhere Audiogenauigkeit aktivieren. Kann die Leistung beeinträchtigen."
#define XEMU_DSP_JIT_LABEL_DE NULL
#define XEMU_DSP_JIT_INFO_0_DE NULL
#define XEMU_HRTF_LABEL_DE NULL
#define XEMU_HRTF_INFO_0_DE NULL
#define XEMU_VP_WORKERS_LABEL_DE NULL
#define XEMU_VP_WORKERS_INFO_0_DE NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_DE NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_DE NULL
#define XEMU_AUDIO_VOLUME_LABEL_DE "Maximale Audiolautstärke (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_DE "Lautstärke der Xbox-Audioausgabe unabhängig von der RetroArch-Gesamtlautstärke begrenzen."
#define OPTION_VAL_100_DE "100 %"
#define OPTION_VAL_80_DE "80 %"
#define OPTION_VAL_60_DE "60 %"
#define OPTION_VAL_40_DE "40 %"
#define OPTION_VAL_20_DE "20 %"
#define OPTION_VAL_0_DE "Stummgeschaltet"
#define XEMU_VK_FAST_PATHS_LABEL_DE "Vulkan-Schnellpfade (Neustart)"
#define XEMU_VK_FAST_PATHS_INFO_0_DE NULL
#define OPTION_VAL_ALL_DE "Alle"
#define OPTION_VAL_NO_GPL_DE "Keine Pipelinebibliotheken"
#define OPTION_VAL_NO_DYN_DE "Keine dynamischen Zustände"
#define OPTION_VAL_NONE_DE "Nein"
#define XEMU_RUMBLE_P1_LABEL_DE NULL
#define XEMU_RUMBLE_P1_INFO_0_DE NULL
#define XEMU_RUMBLE_P2_LABEL_DE NULL
#define XEMU_RUMBLE_P2_INFO_0_DE NULL
#define XEMU_DEADZONE_P1_LABEL_DE NULL
#define XEMU_DEADZONE_P1_INFO_0_DE NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_DE "0 %"
#define OPTION_VAL_5_XEMU_DEADZONE_P1_DE "5 %"
#define OPTION_VAL_10_XEMU_DEADZONE_P1_DE "10 %"
#define OPTION_VAL_15_DE "15 %"
#define OPTION_VAL_25_DE "25 %"
#define OPTION_VAL_30_DE "30 %"
#define XEMU_DEADZONE_P2_LABEL_DE NULL
#define XEMU_DEADZONE_P2_INFO_0_DE NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_DE "Freispiel (Neustart)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_DE "Startet Sega-Chihiro-Spiele im Freispielmodus, ohne Münzeinwurf. Bei „Aus“ wird mit „Auswählen“ eine Münze eingeworfen."
#define XEMU_CHIHIRO_GUN_AIM_LABEL_DE "Lightgun-Zielpunkt"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_DE NULL
#define OPTION_VAL_MOUSE_DE "Maus"
#define OPTION_VAL_STICK_DE NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_DE NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_DE NULL
#define XEMU_CHIHIRO_FFB_LABEL_DE NULL
#define XEMU_CHIHIRO_FFB_INFO_0_DE NULL
#define OPTION_VAL_50_DE "50 %"
#define OPTION_VAL_75_DE "75 %"
#define OPTION_VAL_150_DE "150 %"
#define OPTION_VAL_200_DE "200 %"

struct retro_core_option_v2_category option_cats_de[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_DE,
        CATEGORY_SYSTEM_INFO_0_DE
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_DE,
        CATEGORY_VIDEO_INFO_0_DE
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_DE,
        CATEGORY_AUDIO_INFO_0_DE
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_DE,
        CATEGORY_CONTROLS_INFO_0_DE
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_DE,
        CATEGORY_CHIHIRO_INFO_0_DE
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_de[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_DE,
        NULL,
        XEMU_MEMORY_INFO_0_DE,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_DE },
            { "128", OPTION_VAL_128_DE },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_DE,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_DE,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_DE },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_DE,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_DE,
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
        XEMU_HARD_FPU_LABEL_DE,
        NULL,
        XEMU_HARD_FPU_INFO_0_DE,
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
        XEMU_CPU_BOOST_LABEL_DE,
        NULL,
        XEMU_CPU_BOOST_INFO_0_DE,
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
        XEMU_HDD_TRIM_LABEL_DE,
        NULL,
        XEMU_HDD_TRIM_INFO_0_DE,
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
        XEMU_RENDERER_LABEL_DE,
        NULL,
        XEMU_RENDERER_INFO_0_DE,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_DE },
            { "opengl", OPTION_VAL_OPENGL_DE },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_DE,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_DE,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_DE },
            { "4:3",       OPTION_VAL_4_3_DE },
            { "16:9",      OPTION_VAL_16_9_DE },
            { "letterbox", OPTION_VAL_LETTERBOX_DE },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_DE,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_DE,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_DE },
            { "4:3",  OPTION_VAL_4_3_DE },
            { "16:9", OPTION_VAL_16_9_DE },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_DE,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_DE,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_DE },
            { "2", OPTION_VAL_2_DE },
            { "3", OPTION_VAL_3_DE },
            { "4", OPTION_VAL_4_DE },
            { "5", OPTION_VAL_5_DE },
            { "6", OPTION_VAL_6_DE },
            { "7", OPTION_VAL_7_DE },
            { "8", OPTION_VAL_8_DE },
            { "9", OPTION_VAL_9_DE },
            { "10", OPTION_VAL_10_DE },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_DE,
        NULL,
        XEMU_AVPACK_INFO_0_DE,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_DE },
            { "composite", OPTION_VAL_COMPOSITE_DE },
            { "svideo",    OPTION_VAL_SVIDEO_DE },
            { "scart",     OPTION_VAL_SCART_DE },
            { "vga",       OPTION_VAL_VGA_DE },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_DE,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_DE,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_DE,
        NULL,
        XEMU_USE_DSP_INFO_0_DE,
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
        XEMU_DSP_JIT_LABEL_DE,
        NULL,
        XEMU_DSP_JIT_INFO_0_DE,
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
        XEMU_HRTF_LABEL_DE,
        NULL,
        XEMU_HRTF_INFO_0_DE,
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
        XEMU_VP_WORKERS_LABEL_DE,
        NULL,
        XEMU_VP_WORKERS_INFO_0_DE,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_DE },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_DE,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_DE,
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
        XEMU_AUDIO_VOLUME_LABEL_DE,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_DE,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_DE },
            { "80",  OPTION_VAL_80_DE },
            { "60",  OPTION_VAL_60_DE },
            { "40",  OPTION_VAL_40_DE },
            { "20",  OPTION_VAL_20_DE },
            { "0",   OPTION_VAL_0_DE },
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
        XEMU_VK_FAST_PATHS_LABEL_DE,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_DE,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_DE },
            { "no_gpl",   OPTION_VAL_NO_GPL_DE },
            { "no_dyn",   OPTION_VAL_NO_DYN_DE },
            { "none",     OPTION_VAL_NONE_DE },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_DE,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_DE,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_DE,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_DE,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_DE,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_DE,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_DE },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_DE },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_DE },
            { "15", OPTION_VAL_15_DE },
            { "20", OPTION_VAL_20_DE },
            { "25", OPTION_VAL_25_DE },
            { "30", OPTION_VAL_30_DE },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_DE,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_DE,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_DE },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_DE },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_DE },
            { "15", OPTION_VAL_15_DE },
            { "20", OPTION_VAL_20_DE },
            { "25", OPTION_VAL_25_DE },
            { "30", OPTION_VAL_30_DE },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_DE,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_DE,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_DE,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_DE,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_DE },
            { "stick", OPTION_VAL_STICK_DE },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_DE,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_DE,
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
        XEMU_CHIHIRO_FFB_LABEL_DE,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_DE,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_DE },
            { "50",  OPTION_VAL_50_DE },
            { "75",  OPTION_VAL_75_DE },
            { "100", OPTION_VAL_100_DE },
            { "150", OPTION_VAL_150_DE },
            { "200", OPTION_VAL_200_DE },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_de = {
   option_cats_de,
   option_defs_de
};

/* RETRO_LANGUAGE_EL */

#define CATEGORY_SYSTEM_LABEL_EL NULL
#define CATEGORY_SYSTEM_INFO_0_EL NULL
#define CATEGORY_VIDEO_LABEL_EL "Βίντεο"
#define CATEGORY_VIDEO_INFO_0_EL NULL
#define CATEGORY_AUDIO_LABEL_EL "Ήχος"
#define CATEGORY_AUDIO_INFO_0_EL NULL
#define CATEGORY_CONTROLS_LABEL_EL "Χειρισμοί"
#define CATEGORY_CONTROLS_INFO_0_EL NULL
#define CATEGORY_CHIHIRO_LABEL_EL NULL
#define CATEGORY_CHIHIRO_INFO_0_EL NULL
#define XEMU_MEMORY_LABEL_EL NULL
#define XEMU_MEMORY_INFO_0_EL NULL
#define OPTION_VAL_64_EL NULL
#define OPTION_VAL_128_EL NULL
#define XEMU_NETWORK_BACKEND_LABEL_EL NULL
#define XEMU_NETWORK_BACKEND_INFO_0_EL NULL
#define OPTION_VAL_NAT_EL NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_EL NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_EL NULL
#define XEMU_HARD_FPU_LABEL_EL NULL
#define XEMU_HARD_FPU_INFO_0_EL NULL
#define XEMU_CPU_BOOST_LABEL_EL NULL
#define XEMU_CPU_BOOST_INFO_0_EL NULL
#define XEMU_HDD_TRIM_LABEL_EL NULL
#define XEMU_HDD_TRIM_INFO_0_EL NULL
#define XEMU_RENDERER_LABEL_EL NULL
#define XEMU_RENDERER_INFO_0_EL NULL
#define OPTION_VAL_VULKAN_EL NULL
#define OPTION_VAL_OPENGL_EL NULL
#define XEMU_VIDEO_ASPECT_LABEL_EL NULL
#define XEMU_VIDEO_ASPECT_INFO_0_EL NULL
#define OPTION_VAL_DASHBOARD_EL NULL
#define OPTION_VAL_4_3_EL NULL
#define OPTION_VAL_16_9_EL NULL
#define OPTION_VAL_LETTERBOX_EL NULL
#define XEMU_ASPECT_RATIO_LABEL_EL NULL
#define XEMU_ASPECT_RATIO_INFO_0_EL NULL
#define OPTION_VAL_AUTO_EL "Αυτόματο"
#define XEMU_SURFACE_SCALE_LABEL_EL NULL
#define XEMU_SURFACE_SCALE_INFO_0_EL NULL
#define OPTION_VAL_1_EL NULL
#define OPTION_VAL_2_EL NULL
#define OPTION_VAL_3_EL NULL
#define OPTION_VAL_4_EL NULL
#define OPTION_VAL_5_EL NULL
#define OPTION_VAL_6_EL NULL
#define OPTION_VAL_7_EL NULL
#define OPTION_VAL_8_EL NULL
#define OPTION_VAL_9_EL NULL
#define OPTION_VAL_10_EL NULL
#define XEMU_AVPACK_LABEL_EL NULL
#define XEMU_AVPACK_INFO_0_EL NULL
#define OPTION_VAL_HDTV_EL NULL
#define OPTION_VAL_COMPOSITE_EL NULL
#define OPTION_VAL_SVIDEO_EL NULL
#define OPTION_VAL_SCART_EL NULL
#define OPTION_VAL_VGA_EL NULL
#define XEMU_AUDIO_THREAD_LABEL_EL NULL
#define XEMU_AUDIO_THREAD_INFO_0_EL NULL
#define XEMU_USE_DSP_LABEL_EL NULL
#define XEMU_USE_DSP_INFO_0_EL NULL
#define XEMU_DSP_JIT_LABEL_EL NULL
#define XEMU_DSP_JIT_INFO_0_EL NULL
#define XEMU_HRTF_LABEL_EL NULL
#define XEMU_HRTF_INFO_0_EL NULL
#define XEMU_VP_WORKERS_LABEL_EL NULL
#define XEMU_VP_WORKERS_INFO_0_EL NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_EL NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_EL NULL
#define XEMU_AUDIO_VOLUME_LABEL_EL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EL NULL
#define OPTION_VAL_100_EL NULL
#define OPTION_VAL_80_EL "το 80%"
#define OPTION_VAL_60_EL NULL
#define OPTION_VAL_40_EL NULL
#define OPTION_VAL_20_EL NULL
#define OPTION_VAL_0_EL NULL
#define XEMU_VK_FAST_PATHS_LABEL_EL NULL
#define XEMU_VK_FAST_PATHS_INFO_0_EL NULL
#define OPTION_VAL_ALL_EL "Όλα"
#define OPTION_VAL_NO_GPL_EL NULL
#define OPTION_VAL_NO_DYN_EL NULL
#define OPTION_VAL_NONE_EL "Κανείς"
#define XEMU_RUMBLE_P1_LABEL_EL NULL
#define XEMU_RUMBLE_P1_INFO_0_EL NULL
#define XEMU_RUMBLE_P2_LABEL_EL NULL
#define XEMU_RUMBLE_P2_INFO_0_EL NULL
#define XEMU_DEADZONE_P1_LABEL_EL NULL
#define XEMU_DEADZONE_P1_INFO_0_EL NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_EL NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_EL NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_EL NULL
#define OPTION_VAL_15_EL NULL
#define OPTION_VAL_25_EL NULL
#define OPTION_VAL_30_EL NULL
#define XEMU_DEADZONE_P2_LABEL_EL NULL
#define XEMU_DEADZONE_P2_INFO_0_EL NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_EL NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_EL NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_EL NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_EL NULL
#define OPTION_VAL_MOUSE_EL NULL
#define OPTION_VAL_STICK_EL NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_EL NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_EL NULL
#define XEMU_CHIHIRO_FFB_LABEL_EL NULL
#define XEMU_CHIHIRO_FFB_INFO_0_EL NULL
#define OPTION_VAL_50_EL NULL
#define OPTION_VAL_75_EL NULL
#define OPTION_VAL_150_EL NULL
#define OPTION_VAL_200_EL NULL

struct retro_core_option_v2_category option_cats_el[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_EL,
        CATEGORY_SYSTEM_INFO_0_EL
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_EL,
        CATEGORY_VIDEO_INFO_0_EL
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_EL,
        CATEGORY_AUDIO_INFO_0_EL
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_EL,
        CATEGORY_CONTROLS_INFO_0_EL
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_EL,
        CATEGORY_CHIHIRO_INFO_0_EL
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_el[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_EL,
        NULL,
        XEMU_MEMORY_INFO_0_EL,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_EL },
            { "128", OPTION_VAL_128_EL },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_EL,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_EL,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_EL },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_EL,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_EL,
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
        XEMU_HARD_FPU_LABEL_EL,
        NULL,
        XEMU_HARD_FPU_INFO_0_EL,
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
        XEMU_CPU_BOOST_LABEL_EL,
        NULL,
        XEMU_CPU_BOOST_INFO_0_EL,
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
        XEMU_HDD_TRIM_LABEL_EL,
        NULL,
        XEMU_HDD_TRIM_INFO_0_EL,
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
        XEMU_RENDERER_LABEL_EL,
        NULL,
        XEMU_RENDERER_INFO_0_EL,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_EL },
            { "opengl", OPTION_VAL_OPENGL_EL },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_EL,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_EL,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_EL },
            { "4:3",       OPTION_VAL_4_3_EL },
            { "16:9",      OPTION_VAL_16_9_EL },
            { "letterbox", OPTION_VAL_LETTERBOX_EL },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_EL,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_EL,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_EL },
            { "4:3",  OPTION_VAL_4_3_EL },
            { "16:9", OPTION_VAL_16_9_EL },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_EL,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_EL,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_EL },
            { "2", OPTION_VAL_2_EL },
            { "3", OPTION_VAL_3_EL },
            { "4", OPTION_VAL_4_EL },
            { "5", OPTION_VAL_5_EL },
            { "6", OPTION_VAL_6_EL },
            { "7", OPTION_VAL_7_EL },
            { "8", OPTION_VAL_8_EL },
            { "9", OPTION_VAL_9_EL },
            { "10", OPTION_VAL_10_EL },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_EL,
        NULL,
        XEMU_AVPACK_INFO_0_EL,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_EL },
            { "composite", OPTION_VAL_COMPOSITE_EL },
            { "svideo",    OPTION_VAL_SVIDEO_EL },
            { "scart",     OPTION_VAL_SCART_EL },
            { "vga",       OPTION_VAL_VGA_EL },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_EL,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_EL,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_EL,
        NULL,
        XEMU_USE_DSP_INFO_0_EL,
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
        XEMU_DSP_JIT_LABEL_EL,
        NULL,
        XEMU_DSP_JIT_INFO_0_EL,
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
        XEMU_HRTF_LABEL_EL,
        NULL,
        XEMU_HRTF_INFO_0_EL,
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
        XEMU_VP_WORKERS_LABEL_EL,
        NULL,
        XEMU_VP_WORKERS_INFO_0_EL,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_EL },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_EL,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_EL,
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
        XEMU_AUDIO_VOLUME_LABEL_EL,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_EL,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_EL },
            { "80",  OPTION_VAL_80_EL },
            { "60",  OPTION_VAL_60_EL },
            { "40",  OPTION_VAL_40_EL },
            { "20",  OPTION_VAL_20_EL },
            { "0",   OPTION_VAL_0_EL },
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
        XEMU_VK_FAST_PATHS_LABEL_EL,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_EL,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_EL },
            { "no_gpl",   OPTION_VAL_NO_GPL_EL },
            { "no_dyn",   OPTION_VAL_NO_DYN_EL },
            { "none",     OPTION_VAL_NONE_EL },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_EL,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_EL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_EL,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_EL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_EL,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_EL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_EL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_EL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_EL },
            { "15", OPTION_VAL_15_EL },
            { "20", OPTION_VAL_20_EL },
            { "25", OPTION_VAL_25_EL },
            { "30", OPTION_VAL_30_EL },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_EL,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_EL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_EL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_EL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_EL },
            { "15", OPTION_VAL_15_EL },
            { "20", OPTION_VAL_20_EL },
            { "25", OPTION_VAL_25_EL },
            { "30", OPTION_VAL_30_EL },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_EL,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_EL,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_EL,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_EL,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_EL },
            { "stick", OPTION_VAL_STICK_EL },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_EL,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_EL,
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
        XEMU_CHIHIRO_FFB_LABEL_EL,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_EL,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_EL },
            { "50",  OPTION_VAL_50_EL },
            { "75",  OPTION_VAL_75_EL },
            { "100", OPTION_VAL_100_EL },
            { "150", OPTION_VAL_150_EL },
            { "200", OPTION_VAL_200_EL },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_el = {
   option_cats_el,
   option_defs_el
};

/* RETRO_LANGUAGE_EN */

#define CATEGORY_SYSTEM_LABEL_EN NULL
#define CATEGORY_SYSTEM_INFO_0_EN NULL
#define CATEGORY_VIDEO_LABEL_EN NULL
#define CATEGORY_VIDEO_INFO_0_EN NULL
#define CATEGORY_AUDIO_LABEL_EN NULL
#define CATEGORY_AUDIO_INFO_0_EN NULL
#define CATEGORY_CONTROLS_LABEL_EN NULL
#define CATEGORY_CONTROLS_INFO_0_EN NULL
#define CATEGORY_CHIHIRO_LABEL_EN NULL
#define CATEGORY_CHIHIRO_INFO_0_EN NULL
#define XEMU_MEMORY_LABEL_EN NULL
#define XEMU_MEMORY_INFO_0_EN NULL
#define OPTION_VAL_64_EN NULL
#define OPTION_VAL_128_EN NULL
#define XEMU_NETWORK_BACKEND_LABEL_EN NULL
#define XEMU_NETWORK_BACKEND_INFO_0_EN NULL
#define OPTION_VAL_NAT_EN NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_EN NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_EN NULL
#define XEMU_HARD_FPU_LABEL_EN NULL
#define XEMU_HARD_FPU_INFO_0_EN NULL
#define XEMU_CPU_BOOST_LABEL_EN NULL
#define XEMU_CPU_BOOST_INFO_0_EN NULL
#define XEMU_HDD_TRIM_LABEL_EN NULL
#define XEMU_HDD_TRIM_INFO_0_EN NULL
#define XEMU_RENDERER_LABEL_EN NULL
#define XEMU_RENDERER_INFO_0_EN NULL
#define OPTION_VAL_VULKAN_EN NULL
#define OPTION_VAL_OPENGL_EN NULL
#define XEMU_VIDEO_ASPECT_LABEL_EN NULL
#define XEMU_VIDEO_ASPECT_INFO_0_EN NULL
#define OPTION_VAL_DASHBOARD_EN NULL
#define OPTION_VAL_4_3_EN NULL
#define OPTION_VAL_16_9_EN NULL
#define OPTION_VAL_LETTERBOX_EN NULL
#define XEMU_ASPECT_RATIO_LABEL_EN NULL
#define XEMU_ASPECT_RATIO_INFO_0_EN NULL
#define OPTION_VAL_AUTO_EN NULL
#define XEMU_SURFACE_SCALE_LABEL_EN NULL
#define XEMU_SURFACE_SCALE_INFO_0_EN NULL
#define OPTION_VAL_1_EN NULL
#define OPTION_VAL_2_EN NULL
#define OPTION_VAL_3_EN NULL
#define OPTION_VAL_4_EN NULL
#define OPTION_VAL_5_EN NULL
#define OPTION_VAL_6_EN NULL
#define OPTION_VAL_7_EN NULL
#define OPTION_VAL_8_EN NULL
#define OPTION_VAL_9_EN NULL
#define OPTION_VAL_10_EN NULL
#define XEMU_AVPACK_LABEL_EN NULL
#define XEMU_AVPACK_INFO_0_EN NULL
#define OPTION_VAL_HDTV_EN NULL
#define OPTION_VAL_COMPOSITE_EN NULL
#define OPTION_VAL_SVIDEO_EN NULL
#define OPTION_VAL_SCART_EN NULL
#define OPTION_VAL_VGA_EN NULL
#define XEMU_AUDIO_THREAD_LABEL_EN NULL
#define XEMU_AUDIO_THREAD_INFO_0_EN NULL
#define XEMU_USE_DSP_LABEL_EN NULL
#define XEMU_USE_DSP_INFO_0_EN NULL
#define XEMU_DSP_JIT_LABEL_EN NULL
#define XEMU_DSP_JIT_INFO_0_EN NULL
#define XEMU_HRTF_LABEL_EN NULL
#define XEMU_HRTF_INFO_0_EN NULL
#define XEMU_VP_WORKERS_LABEL_EN NULL
#define XEMU_VP_WORKERS_INFO_0_EN NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_EN NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_EN NULL
#define XEMU_AUDIO_VOLUME_LABEL_EN NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EN NULL
#define OPTION_VAL_100_EN NULL
#define OPTION_VAL_80_EN NULL
#define OPTION_VAL_60_EN NULL
#define OPTION_VAL_40_EN NULL
#define OPTION_VAL_20_EN NULL
#define OPTION_VAL_0_EN NULL
#define XEMU_VK_FAST_PATHS_LABEL_EN NULL
#define XEMU_VK_FAST_PATHS_INFO_0_EN NULL
#define OPTION_VAL_ALL_EN NULL
#define OPTION_VAL_NO_GPL_EN NULL
#define OPTION_VAL_NO_DYN_EN NULL
#define OPTION_VAL_NONE_EN NULL
#define XEMU_RUMBLE_P1_LABEL_EN NULL
#define XEMU_RUMBLE_P1_INFO_0_EN NULL
#define XEMU_RUMBLE_P2_LABEL_EN NULL
#define XEMU_RUMBLE_P2_INFO_0_EN NULL
#define XEMU_DEADZONE_P1_LABEL_EN NULL
#define XEMU_DEADZONE_P1_INFO_0_EN NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_EN NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_EN NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_EN NULL
#define OPTION_VAL_15_EN NULL
#define OPTION_VAL_25_EN NULL
#define OPTION_VAL_30_EN NULL
#define XEMU_DEADZONE_P2_LABEL_EN NULL
#define XEMU_DEADZONE_P2_INFO_0_EN NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_EN NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_EN NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_EN NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_EN NULL
#define OPTION_VAL_MOUSE_EN NULL
#define OPTION_VAL_STICK_EN NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_EN NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_EN NULL
#define XEMU_CHIHIRO_FFB_LABEL_EN NULL
#define XEMU_CHIHIRO_FFB_INFO_0_EN NULL
#define OPTION_VAL_50_EN NULL
#define OPTION_VAL_75_EN NULL
#define OPTION_VAL_150_EN NULL
#define OPTION_VAL_200_EN NULL

struct retro_core_option_v2_category option_cats_en[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_EN,
        CATEGORY_SYSTEM_INFO_0_EN
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_EN,
        CATEGORY_VIDEO_INFO_0_EN
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_EN,
        CATEGORY_AUDIO_INFO_0_EN
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_EN,
        CATEGORY_CONTROLS_INFO_0_EN
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_EN,
        CATEGORY_CHIHIRO_INFO_0_EN
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_en[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_EN,
        NULL,
        XEMU_MEMORY_INFO_0_EN,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_EN },
            { "128", OPTION_VAL_128_EN },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_EN,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_EN,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_EN },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_EN,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_EN,
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
        XEMU_HARD_FPU_LABEL_EN,
        NULL,
        XEMU_HARD_FPU_INFO_0_EN,
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
        XEMU_CPU_BOOST_LABEL_EN,
        NULL,
        XEMU_CPU_BOOST_INFO_0_EN,
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
        XEMU_HDD_TRIM_LABEL_EN,
        NULL,
        XEMU_HDD_TRIM_INFO_0_EN,
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
        XEMU_RENDERER_LABEL_EN,
        NULL,
        XEMU_RENDERER_INFO_0_EN,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_EN },
            { "opengl", OPTION_VAL_OPENGL_EN },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_EN,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_EN,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_EN },
            { "4:3",       OPTION_VAL_4_3_EN },
            { "16:9",      OPTION_VAL_16_9_EN },
            { "letterbox", OPTION_VAL_LETTERBOX_EN },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_EN,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_EN,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_EN },
            { "4:3",  OPTION_VAL_4_3_EN },
            { "16:9", OPTION_VAL_16_9_EN },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_EN,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_EN,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_EN },
            { "2", OPTION_VAL_2_EN },
            { "3", OPTION_VAL_3_EN },
            { "4", OPTION_VAL_4_EN },
            { "5", OPTION_VAL_5_EN },
            { "6", OPTION_VAL_6_EN },
            { "7", OPTION_VAL_7_EN },
            { "8", OPTION_VAL_8_EN },
            { "9", OPTION_VAL_9_EN },
            { "10", OPTION_VAL_10_EN },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_EN,
        NULL,
        XEMU_AVPACK_INFO_0_EN,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_EN },
            { "composite", OPTION_VAL_COMPOSITE_EN },
            { "svideo",    OPTION_VAL_SVIDEO_EN },
            { "scart",     OPTION_VAL_SCART_EN },
            { "vga",       OPTION_VAL_VGA_EN },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_EN,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_EN,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_EN,
        NULL,
        XEMU_USE_DSP_INFO_0_EN,
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
        XEMU_DSP_JIT_LABEL_EN,
        NULL,
        XEMU_DSP_JIT_INFO_0_EN,
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
        XEMU_HRTF_LABEL_EN,
        NULL,
        XEMU_HRTF_INFO_0_EN,
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
        XEMU_VP_WORKERS_LABEL_EN,
        NULL,
        XEMU_VP_WORKERS_INFO_0_EN,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_EN },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_EN,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_EN,
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
        XEMU_AUDIO_VOLUME_LABEL_EN,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_EN,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_EN },
            { "80",  OPTION_VAL_80_EN },
            { "60",  OPTION_VAL_60_EN },
            { "40",  OPTION_VAL_40_EN },
            { "20",  OPTION_VAL_20_EN },
            { "0",   OPTION_VAL_0_EN },
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
        XEMU_VK_FAST_PATHS_LABEL_EN,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_EN,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_EN },
            { "no_gpl",   OPTION_VAL_NO_GPL_EN },
            { "no_dyn",   OPTION_VAL_NO_DYN_EN },
            { "none",     OPTION_VAL_NONE_EN },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_EN,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_EN,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_EN,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_EN,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_EN,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_EN,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_EN },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_EN },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_EN },
            { "15", OPTION_VAL_15_EN },
            { "20", OPTION_VAL_20_EN },
            { "25", OPTION_VAL_25_EN },
            { "30", OPTION_VAL_30_EN },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_EN,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_EN,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_EN },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_EN },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_EN },
            { "15", OPTION_VAL_15_EN },
            { "20", OPTION_VAL_20_EN },
            { "25", OPTION_VAL_25_EN },
            { "30", OPTION_VAL_30_EN },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_EN,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_EN,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_EN,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_EN,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_EN },
            { "stick", OPTION_VAL_STICK_EN },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_EN,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_EN,
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
        XEMU_CHIHIRO_FFB_LABEL_EN,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_EN,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_EN },
            { "50",  OPTION_VAL_50_EN },
            { "75",  OPTION_VAL_75_EN },
            { "100", OPTION_VAL_100_EN },
            { "150", OPTION_VAL_150_EN },
            { "200", OPTION_VAL_200_EN },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_en = {
   option_cats_en,
   option_defs_en
};

/* RETRO_LANGUAGE_EO */

#define CATEGORY_SYSTEM_LABEL_EO NULL
#define CATEGORY_SYSTEM_INFO_0_EO NULL
#define CATEGORY_VIDEO_LABEL_EO NULL
#define CATEGORY_VIDEO_INFO_0_EO NULL
#define CATEGORY_AUDIO_LABEL_EO "Sono"
#define CATEGORY_AUDIO_INFO_0_EO NULL
#define CATEGORY_CONTROLS_LABEL_EO "Regiloj"
#define CATEGORY_CONTROLS_INFO_0_EO NULL
#define CATEGORY_CHIHIRO_LABEL_EO NULL
#define CATEGORY_CHIHIRO_INFO_0_EO NULL
#define XEMU_MEMORY_LABEL_EO NULL
#define XEMU_MEMORY_INFO_0_EO NULL
#define OPTION_VAL_64_EO NULL
#define OPTION_VAL_128_EO NULL
#define XEMU_NETWORK_BACKEND_LABEL_EO NULL
#define XEMU_NETWORK_BACKEND_INFO_0_EO NULL
#define OPTION_VAL_NAT_EO NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_EO NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_EO NULL
#define XEMU_HARD_FPU_LABEL_EO NULL
#define XEMU_HARD_FPU_INFO_0_EO NULL
#define XEMU_CPU_BOOST_LABEL_EO NULL
#define XEMU_CPU_BOOST_INFO_0_EO NULL
#define XEMU_HDD_TRIM_LABEL_EO NULL
#define XEMU_HDD_TRIM_INFO_0_EO NULL
#define XEMU_RENDERER_LABEL_EO NULL
#define XEMU_RENDERER_INFO_0_EO NULL
#define OPTION_VAL_VULKAN_EO NULL
#define OPTION_VAL_OPENGL_EO NULL
#define XEMU_VIDEO_ASPECT_LABEL_EO NULL
#define XEMU_VIDEO_ASPECT_INFO_0_EO NULL
#define OPTION_VAL_DASHBOARD_EO NULL
#define OPTION_VAL_4_3_EO NULL
#define OPTION_VAL_16_9_EO NULL
#define OPTION_VAL_LETTERBOX_EO NULL
#define XEMU_ASPECT_RATIO_LABEL_EO "Kerna bilda proporcio"
#define XEMU_ASPECT_RATIO_INFO_0_EO NULL
#define OPTION_VAL_AUTO_EO "Aŭtomata"
#define XEMU_SURFACE_SCALE_LABEL_EO NULL
#define XEMU_SURFACE_SCALE_INFO_0_EO NULL
#define OPTION_VAL_1_EO NULL
#define OPTION_VAL_2_EO NULL
#define OPTION_VAL_3_EO NULL
#define OPTION_VAL_4_EO NULL
#define OPTION_VAL_5_EO NULL
#define OPTION_VAL_6_EO NULL
#define OPTION_VAL_7_EO NULL
#define OPTION_VAL_8_EO NULL
#define OPTION_VAL_9_EO NULL
#define OPTION_VAL_10_EO NULL
#define XEMU_AVPACK_LABEL_EO NULL
#define XEMU_AVPACK_INFO_0_EO NULL
#define OPTION_VAL_HDTV_EO NULL
#define OPTION_VAL_COMPOSITE_EO "Kunmetita"
#define OPTION_VAL_SVIDEO_EO NULL
#define OPTION_VAL_SCART_EO NULL
#define OPTION_VAL_VGA_EO NULL
#define XEMU_AUDIO_THREAD_LABEL_EO NULL
#define XEMU_AUDIO_THREAD_INFO_0_EO NULL
#define XEMU_USE_DSP_LABEL_EO NULL
#define XEMU_USE_DSP_INFO_0_EO NULL
#define XEMU_DSP_JIT_LABEL_EO NULL
#define XEMU_DSP_JIT_INFO_0_EO NULL
#define XEMU_HRTF_LABEL_EO NULL
#define XEMU_HRTF_INFO_0_EO NULL
#define XEMU_VP_WORKERS_LABEL_EO NULL
#define XEMU_VP_WORKERS_INFO_0_EO NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_EO NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_EO NULL
#define XEMU_AUDIO_VOLUME_LABEL_EO NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EO NULL
#define OPTION_VAL_100_EO NULL
#define OPTION_VAL_80_EO NULL
#define OPTION_VAL_60_EO NULL
#define OPTION_VAL_40_EO NULL
#define OPTION_VAL_20_EO NULL
#define OPTION_VAL_0_EO NULL
#define XEMU_VK_FAST_PATHS_LABEL_EO NULL
#define XEMU_VK_FAST_PATHS_INFO_0_EO NULL
#define OPTION_VAL_ALL_EO "Ĉiuj"
#define OPTION_VAL_NO_GPL_EO NULL
#define OPTION_VAL_NO_DYN_EO NULL
#define OPTION_VAL_NONE_EO "Neniom"
#define XEMU_RUMBLE_P1_LABEL_EO NULL
#define XEMU_RUMBLE_P1_INFO_0_EO NULL
#define XEMU_RUMBLE_P2_LABEL_EO NULL
#define XEMU_RUMBLE_P2_INFO_0_EO NULL
#define XEMU_DEADZONE_P1_LABEL_EO NULL
#define XEMU_DEADZONE_P1_INFO_0_EO NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_EO NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_EO NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_EO NULL
#define OPTION_VAL_15_EO NULL
#define OPTION_VAL_25_EO NULL
#define OPTION_VAL_30_EO NULL
#define XEMU_DEADZONE_P2_LABEL_EO NULL
#define XEMU_DEADZONE_P2_INFO_0_EO NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_EO NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_EO NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_EO NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_EO NULL
#define OPTION_VAL_MOUSE_EO "Muso"
#define OPTION_VAL_STICK_EO NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_EO NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_EO NULL
#define XEMU_CHIHIRO_FFB_LABEL_EO NULL
#define XEMU_CHIHIRO_FFB_INFO_0_EO NULL
#define OPTION_VAL_50_EO NULL
#define OPTION_VAL_75_EO NULL
#define OPTION_VAL_150_EO NULL
#define OPTION_VAL_200_EO NULL

struct retro_core_option_v2_category option_cats_eo[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_EO,
        CATEGORY_SYSTEM_INFO_0_EO
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_EO,
        CATEGORY_VIDEO_INFO_0_EO
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_EO,
        CATEGORY_AUDIO_INFO_0_EO
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_EO,
        CATEGORY_CONTROLS_INFO_0_EO
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_EO,
        CATEGORY_CHIHIRO_INFO_0_EO
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_eo[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_EO,
        NULL,
        XEMU_MEMORY_INFO_0_EO,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_EO },
            { "128", OPTION_VAL_128_EO },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_EO,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_EO,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_EO },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_EO,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_EO,
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
        XEMU_HARD_FPU_LABEL_EO,
        NULL,
        XEMU_HARD_FPU_INFO_0_EO,
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
        XEMU_CPU_BOOST_LABEL_EO,
        NULL,
        XEMU_CPU_BOOST_INFO_0_EO,
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
        XEMU_HDD_TRIM_LABEL_EO,
        NULL,
        XEMU_HDD_TRIM_INFO_0_EO,
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
        XEMU_RENDERER_LABEL_EO,
        NULL,
        XEMU_RENDERER_INFO_0_EO,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_EO },
            { "opengl", OPTION_VAL_OPENGL_EO },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_EO,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_EO,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_EO },
            { "4:3",       OPTION_VAL_4_3_EO },
            { "16:9",      OPTION_VAL_16_9_EO },
            { "letterbox", OPTION_VAL_LETTERBOX_EO },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_EO,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_EO,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_EO },
            { "4:3",  OPTION_VAL_4_3_EO },
            { "16:9", OPTION_VAL_16_9_EO },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_EO,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_EO,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_EO },
            { "2", OPTION_VAL_2_EO },
            { "3", OPTION_VAL_3_EO },
            { "4", OPTION_VAL_4_EO },
            { "5", OPTION_VAL_5_EO },
            { "6", OPTION_VAL_6_EO },
            { "7", OPTION_VAL_7_EO },
            { "8", OPTION_VAL_8_EO },
            { "9", OPTION_VAL_9_EO },
            { "10", OPTION_VAL_10_EO },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_EO,
        NULL,
        XEMU_AVPACK_INFO_0_EO,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_EO },
            { "composite", OPTION_VAL_COMPOSITE_EO },
            { "svideo",    OPTION_VAL_SVIDEO_EO },
            { "scart",     OPTION_VAL_SCART_EO },
            { "vga",       OPTION_VAL_VGA_EO },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_EO,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_EO,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_EO,
        NULL,
        XEMU_USE_DSP_INFO_0_EO,
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
        XEMU_DSP_JIT_LABEL_EO,
        NULL,
        XEMU_DSP_JIT_INFO_0_EO,
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
        XEMU_HRTF_LABEL_EO,
        NULL,
        XEMU_HRTF_INFO_0_EO,
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
        XEMU_VP_WORKERS_LABEL_EO,
        NULL,
        XEMU_VP_WORKERS_INFO_0_EO,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_EO },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_EO,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_EO,
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
        XEMU_AUDIO_VOLUME_LABEL_EO,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_EO,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_EO },
            { "80",  OPTION_VAL_80_EO },
            { "60",  OPTION_VAL_60_EO },
            { "40",  OPTION_VAL_40_EO },
            { "20",  OPTION_VAL_20_EO },
            { "0",   OPTION_VAL_0_EO },
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
        XEMU_VK_FAST_PATHS_LABEL_EO,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_EO,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_EO },
            { "no_gpl",   OPTION_VAL_NO_GPL_EO },
            { "no_dyn",   OPTION_VAL_NO_DYN_EO },
            { "none",     OPTION_VAL_NONE_EO },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_EO,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_EO,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_EO,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_EO,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_EO,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_EO,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_EO },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_EO },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_EO },
            { "15", OPTION_VAL_15_EO },
            { "20", OPTION_VAL_20_EO },
            { "25", OPTION_VAL_25_EO },
            { "30", OPTION_VAL_30_EO },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_EO,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_EO,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_EO },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_EO },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_EO },
            { "15", OPTION_VAL_15_EO },
            { "20", OPTION_VAL_20_EO },
            { "25", OPTION_VAL_25_EO },
            { "30", OPTION_VAL_30_EO },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_EO,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_EO,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_EO,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_EO,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_EO },
            { "stick", OPTION_VAL_STICK_EO },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_EO,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_EO,
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
        XEMU_CHIHIRO_FFB_LABEL_EO,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_EO,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_EO },
            { "50",  OPTION_VAL_50_EO },
            { "75",  OPTION_VAL_75_EO },
            { "100", OPTION_VAL_100_EO },
            { "150", OPTION_VAL_150_EO },
            { "200", OPTION_VAL_200_EO },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_eo = {
   option_cats_eo,
   option_defs_eo
};

/* RETRO_LANGUAGE_ES */

#define CATEGORY_SYSTEM_LABEL_ES NULL
#define CATEGORY_SYSTEM_INFO_0_ES NULL
#define CATEGORY_VIDEO_LABEL_ES "Vídeo"
#define CATEGORY_VIDEO_INFO_0_ES "Configura el renderizado de vídeo."
#define CATEGORY_AUDIO_LABEL_ES NULL
#define CATEGORY_AUDIO_INFO_0_ES "Configura la emulación de audio."
#define CATEGORY_CONTROLS_LABEL_ES "Controles"
#define CATEGORY_CONTROLS_INFO_0_ES NULL
#define CATEGORY_CHIHIRO_LABEL_ES NULL
#define CATEGORY_CHIHIRO_INFO_0_ES "Los juegos arcade de Sega Chihiro: el juego libre, el apuntado de los juegos de lightgun y el force feedback para los juegos de conducción."
#define XEMU_MEMORY_LABEL_ES "Memoria del sistema (MB)"
#define XEMU_MEMORY_INFO_0_ES "La cantidad de memoria RAM que tendrá el sistema. 64 MB es el valor estándar, 128 MB es para kits de depuración."
#define OPTION_VAL_64_ES NULL
#define OPTION_VAL_128_ES NULL
#define XEMU_NETWORK_BACKEND_LABEL_ES "Back-end de red"
#define XEMU_NETWORK_BACKEND_INFO_0_ES "Activa el soporte de red para aquellos juegos de Xbox compatibles con red local e interconexión. El back-end NAT ofrece una conectividad básica."
#define OPTION_VAL_NAT_ES NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_ES "Omitir animación de arranque"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_ES "Omite la animación de arranque de Xbox."
#define XEMU_HARD_FPU_LABEL_ES "Emulación de FPU de hardware"
#define XEMU_HARD_FPU_INFO_0_ES "Utiliza la FPU del host para emular el código x87. Es más rápido, pero tendrá pequeñas pérdidas de precisión."
#define XEMU_CPU_BOOST_LABEL_ES NULL
#define XEMU_CPU_BOOST_INFO_0_ES "Rutas más rápidas para la CPU invitada y para el procesador de audio: SSE nativo y una mayor caché de saltos. Desactiva esta opción si un juego empieza a dar problemas."
#define XEMU_HDD_TRIM_LABEL_ES NULL
#define XEMU_HDD_TRIM_INFO_0_ES NULL
#define XEMU_RENDERER_LABEL_ES "API de gráficos (es necesario reiniciar)"
#define XEMU_RENDERER_INFO_0_ES "El renderizador con el que se dibujará la GPU emulada. Vulkan es el predeterminado, OpenGL es el de respaldo para aquellos controladores en los que Vulkan dé problemas. Es necesario reiniciar RetroArch. Android utilizará siempre Vulkan y macOS utilizará OpenGL."
#define OPTION_VAL_VULKAN_ES NULL
#define OPTION_VAL_OPENGL_ES NULL
#define XEMU_VIDEO_ASPECT_LABEL_ES NULL
#define XEMU_VIDEO_ASPECT_INFO_0_ES NULL
#define OPTION_VAL_DASHBOARD_ES NULL
#define OPTION_VAL_4_3_ES NULL
#define OPTION_VAL_16_9_ES NULL
#define OPTION_VAL_LETTERBOX_ES NULL
#define XEMU_ASPECT_RATIO_LABEL_ES "Relación de aspecto del núcleo"
#define XEMU_ASPECT_RATIO_INFO_0_ES NULL
#define OPTION_VAL_AUTO_ES "Automática"
#define XEMU_SURFACE_SCALE_LABEL_ES NULL
#define XEMU_SURFACE_SCALE_INFO_0_ES "Escala la resolución interna de renderizado. Un valor más alto mejorará la calidad, pero reducirá el rendimiento."
#define OPTION_VAL_1_ES "× 1 (640 × 480)"
#define OPTION_VAL_2_ES "× 2 (1280 × 960)"
#define OPTION_VAL_3_ES "× 3 (1920 × 1440)"
#define OPTION_VAL_4_ES "× 4 (2560 × 1920)"
#define OPTION_VAL_5_ES "× 5 (3200 × 2400)"
#define OPTION_VAL_6_ES "× 6 (3840 × 2880)"
#define OPTION_VAL_7_ES "× 7 (4480 × 3360)"
#define OPTION_VAL_8_ES "× 8 (5120 × 3840)"
#define OPTION_VAL_9_ES "× 9 (5760 × 4320)"
#define OPTION_VAL_10_ES "× 10 (6400 × 4800)"
#define XEMU_AVPACK_LABEL_ES NULL
#define XEMU_AVPACK_INFO_0_ES "Selecciona el tipo de cable AV. Afectará a los modos de vídeo disponibles."
#define OPTION_VAL_HDTV_ES NULL
#define OPTION_VAL_COMPOSITE_ES "Vídeo compuesto"
#define OPTION_VAL_SVIDEO_ES NULL
#define OPTION_VAL_SCART_ES NULL
#define OPTION_VAL_VGA_ES NULL
#define XEMU_AUDIO_THREAD_LABEL_ES "Hilo para audio (es necesario reiniciar)"
#define XEMU_AUDIO_THREAD_INFO_0_ES NULL
#define XEMU_USE_DSP_LABEL_ES "Emulación del DSP de la APU"
#define XEMU_USE_DSP_INFO_0_ES "Activa la emulación del DSP para mejorar la fidelidad del audio. Podría afectar al rendimiento."
#define XEMU_DSP_JIT_LABEL_ES NULL
#define XEMU_DSP_JIT_INFO_0_ES NULL
#define XEMU_HRTF_LABEL_ES NULL
#define XEMU_HRTF_INFO_0_ES NULL
#define XEMU_VP_WORKERS_LABEL_ES NULL
#define XEMU_VP_WORKERS_INFO_0_ES NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_ES "Primera ejecución fluida (es necesario reiniciar)"
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_ES NULL
#define XEMU_AUDIO_VOLUME_LABEL_ES "Límite de volumen de audio (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_ES "Limita el volumen de la salida de audio de Xbox de forma independiente al volumen maestro de RetroArch."
#define OPTION_VAL_100_ES "100 %"
#define OPTION_VAL_80_ES "80 %"
#define OPTION_VAL_60_ES "60 %"
#define OPTION_VAL_40_ES "40 %"
#define OPTION_VAL_20_ES "20 %"
#define OPTION_VAL_0_ES "Silenciado"
#define XEMU_VK_FAST_PATHS_LABEL_ES "Rutas rápidas de Vulkan (es necesario reiniciar)"
#define XEMU_VK_FAST_PATHS_INFO_0_ES NULL
#define OPTION_VAL_ALL_ES "Todos"
#define OPTION_VAL_NO_GPL_ES "Sin bibliotecas de canalización"
#define OPTION_VAL_NO_DYN_ES "Sin estados dinámicos"
#define OPTION_VAL_NONE_ES "No compartir"
#define XEMU_RUMBLE_P1_LABEL_ES NULL
#define XEMU_RUMBLE_P1_INFO_0_ES NULL
#define XEMU_RUMBLE_P2_LABEL_ES NULL
#define XEMU_RUMBLE_P2_INFO_0_ES NULL
#define XEMU_DEADZONE_P1_LABEL_ES NULL
#define XEMU_DEADZONE_P1_INFO_0_ES NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_ES "0 %"
#define OPTION_VAL_5_XEMU_DEADZONE_P1_ES "5 %"
#define OPTION_VAL_10_XEMU_DEADZONE_P1_ES "10 %"
#define OPTION_VAL_15_ES "15 %"
#define OPTION_VAL_25_ES "25 %"
#define OPTION_VAL_30_ES "30 %"
#define XEMU_DEADZONE_P2_LABEL_ES NULL
#define XEMU_DEADZONE_P2_INFO_0_ES NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_ES "Juego libre (es necesario reiniciar)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_ES "Arranca los juegos de Sega Chihiro en modo de juego libre, sin necesitar introducir monedas. Desactiva esta opción y pulsa el botón SELECT para introducir una moneda."
#define XEMU_CHIHIRO_GUN_AIM_LABEL_ES "Método de apuntado de lightguns"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_ES "Indica qué es lo que apunta a la pantalla en House of the Dead III, Virtua Cop 3 y Ghost Squad. Ratón: apunta con el ratón (o la lightgun de RetroArch), dispara con el botón izquierdo, el botón derecho es el botón del arma (para empujar la corredera del arma o cambiar de arma), el botón central es el pedal o el selector de disparo. Stick analógico: apunta con el stick izquierdo o con la cruceta, dispara con R2, L2 es el botón del arma, L el pedal o el selector de disparo, y con R dispararás fuera de la pantalla."
#define OPTION_VAL_MOUSE_ES "Ratón"
#define OPTION_VAL_STICK_ES "Stick analógico"
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_ES "Punto de mira"
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_ES "Dibuja la posición de la lightgun de cada jugador en pantalla: el punto de mira del jugador 1 es rojo y el del jugador 2 es azul."
#define XEMU_CHIHIRO_FFB_LABEL_ES "Vibración con force feedback"
#define XEMU_CHIHIRO_FFB_INFO_0_ES "Transmite la señal de force feedback de los juegos de carreras (OutRun 2, Maximum Tune) de Chihiro a la vibración del mando del puerto 1 con la fuerza indicada."
#define OPTION_VAL_50_ES "50 %"
#define OPTION_VAL_75_ES "75 %"
#define OPTION_VAL_150_ES "150 %"
#define OPTION_VAL_200_ES "200 %"

struct retro_core_option_v2_category option_cats_es[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_ES,
        CATEGORY_SYSTEM_INFO_0_ES
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_ES,
        CATEGORY_VIDEO_INFO_0_ES
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_ES,
        CATEGORY_AUDIO_INFO_0_ES
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_ES,
        CATEGORY_CONTROLS_INFO_0_ES
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_ES,
        CATEGORY_CHIHIRO_INFO_0_ES
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_es[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_ES,
        NULL,
        XEMU_MEMORY_INFO_0_ES,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_ES },
            { "128", OPTION_VAL_128_ES },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_ES,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_ES,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_ES },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_ES,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_ES,
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
        XEMU_HARD_FPU_LABEL_ES,
        NULL,
        XEMU_HARD_FPU_INFO_0_ES,
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
        XEMU_CPU_BOOST_LABEL_ES,
        NULL,
        XEMU_CPU_BOOST_INFO_0_ES,
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
        XEMU_HDD_TRIM_LABEL_ES,
        NULL,
        XEMU_HDD_TRIM_INFO_0_ES,
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
        XEMU_RENDERER_LABEL_ES,
        NULL,
        XEMU_RENDERER_INFO_0_ES,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_ES },
            { "opengl", OPTION_VAL_OPENGL_ES },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_ES,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_ES,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_ES },
            { "4:3",       OPTION_VAL_4_3_ES },
            { "16:9",      OPTION_VAL_16_9_ES },
            { "letterbox", OPTION_VAL_LETTERBOX_ES },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_ES,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_ES,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_ES },
            { "4:3",  OPTION_VAL_4_3_ES },
            { "16:9", OPTION_VAL_16_9_ES },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_ES,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_ES,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_ES },
            { "2", OPTION_VAL_2_ES },
            { "3", OPTION_VAL_3_ES },
            { "4", OPTION_VAL_4_ES },
            { "5", OPTION_VAL_5_ES },
            { "6", OPTION_VAL_6_ES },
            { "7", OPTION_VAL_7_ES },
            { "8", OPTION_VAL_8_ES },
            { "9", OPTION_VAL_9_ES },
            { "10", OPTION_VAL_10_ES },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_ES,
        NULL,
        XEMU_AVPACK_INFO_0_ES,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_ES },
            { "composite", OPTION_VAL_COMPOSITE_ES },
            { "svideo",    OPTION_VAL_SVIDEO_ES },
            { "scart",     OPTION_VAL_SCART_ES },
            { "vga",       OPTION_VAL_VGA_ES },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_ES,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_ES,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_ES,
        NULL,
        XEMU_USE_DSP_INFO_0_ES,
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
        XEMU_DSP_JIT_LABEL_ES,
        NULL,
        XEMU_DSP_JIT_INFO_0_ES,
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
        XEMU_HRTF_LABEL_ES,
        NULL,
        XEMU_HRTF_INFO_0_ES,
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
        XEMU_VP_WORKERS_LABEL_ES,
        NULL,
        XEMU_VP_WORKERS_INFO_0_ES,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_ES },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_ES,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_ES,
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
        XEMU_AUDIO_VOLUME_LABEL_ES,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_ES,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_ES },
            { "80",  OPTION_VAL_80_ES },
            { "60",  OPTION_VAL_60_ES },
            { "40",  OPTION_VAL_40_ES },
            { "20",  OPTION_VAL_20_ES },
            { "0",   OPTION_VAL_0_ES },
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
        XEMU_VK_FAST_PATHS_LABEL_ES,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_ES,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_ES },
            { "no_gpl",   OPTION_VAL_NO_GPL_ES },
            { "no_dyn",   OPTION_VAL_NO_DYN_ES },
            { "none",     OPTION_VAL_NONE_ES },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_ES,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_ES,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_ES,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_ES,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_ES,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_ES,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_ES },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_ES },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_ES },
            { "15", OPTION_VAL_15_ES },
            { "20", OPTION_VAL_20_ES },
            { "25", OPTION_VAL_25_ES },
            { "30", OPTION_VAL_30_ES },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_ES,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_ES,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_ES },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_ES },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_ES },
            { "15", OPTION_VAL_15_ES },
            { "20", OPTION_VAL_20_ES },
            { "25", OPTION_VAL_25_ES },
            { "30", OPTION_VAL_30_ES },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_ES,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_ES,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_ES,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_ES,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_ES },
            { "stick", OPTION_VAL_STICK_ES },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_ES,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_ES,
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
        XEMU_CHIHIRO_FFB_LABEL_ES,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_ES,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_ES },
            { "50",  OPTION_VAL_50_ES },
            { "75",  OPTION_VAL_75_ES },
            { "100", OPTION_VAL_100_ES },
            { "150", OPTION_VAL_150_ES },
            { "200", OPTION_VAL_200_ES },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_es = {
   option_cats_es,
   option_defs_es
};

/* RETRO_LANGUAGE_FA */

#define CATEGORY_SYSTEM_LABEL_FA NULL
#define CATEGORY_SYSTEM_INFO_0_FA NULL
#define CATEGORY_VIDEO_LABEL_FA "ویدیو"
#define CATEGORY_VIDEO_INFO_0_FA NULL
#define CATEGORY_AUDIO_LABEL_FA "صدا"
#define CATEGORY_AUDIO_INFO_0_FA NULL
#define CATEGORY_CONTROLS_LABEL_FA "کنترل‌ها"
#define CATEGORY_CONTROLS_INFO_0_FA NULL
#define CATEGORY_CHIHIRO_LABEL_FA NULL
#define CATEGORY_CHIHIRO_INFO_0_FA NULL
#define XEMU_MEMORY_LABEL_FA NULL
#define XEMU_MEMORY_INFO_0_FA NULL
#define OPTION_VAL_64_FA NULL
#define OPTION_VAL_128_FA NULL
#define XEMU_NETWORK_BACKEND_LABEL_FA NULL
#define XEMU_NETWORK_BACKEND_INFO_0_FA NULL
#define OPTION_VAL_NAT_FA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_FA NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_FA NULL
#define XEMU_HARD_FPU_LABEL_FA NULL
#define XEMU_HARD_FPU_INFO_0_FA NULL
#define XEMU_CPU_BOOST_LABEL_FA NULL
#define XEMU_CPU_BOOST_INFO_0_FA NULL
#define XEMU_HDD_TRIM_LABEL_FA NULL
#define XEMU_HDD_TRIM_INFO_0_FA NULL
#define XEMU_RENDERER_LABEL_FA NULL
#define XEMU_RENDERER_INFO_0_FA NULL
#define OPTION_VAL_VULKAN_FA NULL
#define OPTION_VAL_OPENGL_FA NULL
#define XEMU_VIDEO_ASPECT_LABEL_FA NULL
#define XEMU_VIDEO_ASPECT_INFO_0_FA NULL
#define OPTION_VAL_DASHBOARD_FA NULL
#define OPTION_VAL_4_3_FA NULL
#define OPTION_VAL_16_9_FA NULL
#define OPTION_VAL_LETTERBOX_FA NULL
#define XEMU_ASPECT_RATIO_LABEL_FA NULL
#define XEMU_ASPECT_RATIO_INFO_0_FA NULL
#define OPTION_VAL_AUTO_FA "خودکار"
#define XEMU_SURFACE_SCALE_LABEL_FA NULL
#define XEMU_SURFACE_SCALE_INFO_0_FA NULL
#define OPTION_VAL_1_FA NULL
#define OPTION_VAL_2_FA NULL
#define OPTION_VAL_3_FA NULL
#define OPTION_VAL_4_FA NULL
#define OPTION_VAL_5_FA NULL
#define OPTION_VAL_6_FA NULL
#define OPTION_VAL_7_FA NULL
#define OPTION_VAL_8_FA NULL
#define OPTION_VAL_9_FA NULL
#define OPTION_VAL_10_FA NULL
#define XEMU_AVPACK_LABEL_FA NULL
#define XEMU_AVPACK_INFO_0_FA NULL
#define OPTION_VAL_HDTV_FA NULL
#define OPTION_VAL_COMPOSITE_FA NULL
#define OPTION_VAL_SVIDEO_FA NULL
#define OPTION_VAL_SCART_FA NULL
#define OPTION_VAL_VGA_FA NULL
#define XEMU_AUDIO_THREAD_LABEL_FA NULL
#define XEMU_AUDIO_THREAD_INFO_0_FA NULL
#define XEMU_USE_DSP_LABEL_FA NULL
#define XEMU_USE_DSP_INFO_0_FA NULL
#define XEMU_DSP_JIT_LABEL_FA NULL
#define XEMU_DSP_JIT_INFO_0_FA NULL
#define XEMU_HRTF_LABEL_FA NULL
#define XEMU_HRTF_INFO_0_FA NULL
#define XEMU_VP_WORKERS_LABEL_FA NULL
#define XEMU_VP_WORKERS_INFO_0_FA NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_FA NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_FA NULL
#define XEMU_AUDIO_VOLUME_LABEL_FA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_FA NULL
#define OPTION_VAL_100_FA NULL
#define OPTION_VAL_80_FA NULL
#define OPTION_VAL_60_FA NULL
#define OPTION_VAL_40_FA NULL
#define OPTION_VAL_20_FA NULL
#define OPTION_VAL_0_FA NULL
#define XEMU_VK_FAST_PATHS_LABEL_FA NULL
#define XEMU_VK_FAST_PATHS_INFO_0_FA NULL
#define OPTION_VAL_ALL_FA NULL
#define OPTION_VAL_NO_GPL_FA NULL
#define OPTION_VAL_NO_DYN_FA NULL
#define OPTION_VAL_NONE_FA "هیچکدام"
#define XEMU_RUMBLE_P1_LABEL_FA NULL
#define XEMU_RUMBLE_P1_INFO_0_FA NULL
#define XEMU_RUMBLE_P2_LABEL_FA NULL
#define XEMU_RUMBLE_P2_INFO_0_FA NULL
#define XEMU_DEADZONE_P1_LABEL_FA NULL
#define XEMU_DEADZONE_P1_INFO_0_FA NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_FA NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_FA NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_FA NULL
#define OPTION_VAL_15_FA NULL
#define OPTION_VAL_25_FA NULL
#define OPTION_VAL_30_FA NULL
#define XEMU_DEADZONE_P2_LABEL_FA NULL
#define XEMU_DEADZONE_P2_INFO_0_FA NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_FA NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_FA NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_FA NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_FA NULL
#define OPTION_VAL_MOUSE_FA NULL
#define OPTION_VAL_STICK_FA NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_FA NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_FA NULL
#define XEMU_CHIHIRO_FFB_LABEL_FA NULL
#define XEMU_CHIHIRO_FFB_INFO_0_FA NULL
#define OPTION_VAL_50_FA NULL
#define OPTION_VAL_75_FA NULL
#define OPTION_VAL_150_FA NULL
#define OPTION_VAL_200_FA NULL

struct retro_core_option_v2_category option_cats_fa[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_FA,
        CATEGORY_SYSTEM_INFO_0_FA
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_FA,
        CATEGORY_VIDEO_INFO_0_FA
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_FA,
        CATEGORY_AUDIO_INFO_0_FA
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_FA,
        CATEGORY_CONTROLS_INFO_0_FA
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_FA,
        CATEGORY_CHIHIRO_INFO_0_FA
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fa[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_FA,
        NULL,
        XEMU_MEMORY_INFO_0_FA,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_FA },
            { "128", OPTION_VAL_128_FA },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_FA,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_FA,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_FA },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_FA,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_FA,
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
        XEMU_HARD_FPU_LABEL_FA,
        NULL,
        XEMU_HARD_FPU_INFO_0_FA,
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
        XEMU_CPU_BOOST_LABEL_FA,
        NULL,
        XEMU_CPU_BOOST_INFO_0_FA,
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
        XEMU_HDD_TRIM_LABEL_FA,
        NULL,
        XEMU_HDD_TRIM_INFO_0_FA,
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
        XEMU_RENDERER_LABEL_FA,
        NULL,
        XEMU_RENDERER_INFO_0_FA,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_FA },
            { "opengl", OPTION_VAL_OPENGL_FA },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_FA,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_FA,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_FA },
            { "4:3",       OPTION_VAL_4_3_FA },
            { "16:9",      OPTION_VAL_16_9_FA },
            { "letterbox", OPTION_VAL_LETTERBOX_FA },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_FA,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_FA,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_FA },
            { "4:3",  OPTION_VAL_4_3_FA },
            { "16:9", OPTION_VAL_16_9_FA },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_FA,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_FA,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_FA },
            { "2", OPTION_VAL_2_FA },
            { "3", OPTION_VAL_3_FA },
            { "4", OPTION_VAL_4_FA },
            { "5", OPTION_VAL_5_FA },
            { "6", OPTION_VAL_6_FA },
            { "7", OPTION_VAL_7_FA },
            { "8", OPTION_VAL_8_FA },
            { "9", OPTION_VAL_9_FA },
            { "10", OPTION_VAL_10_FA },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_FA,
        NULL,
        XEMU_AVPACK_INFO_0_FA,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_FA },
            { "composite", OPTION_VAL_COMPOSITE_FA },
            { "svideo",    OPTION_VAL_SVIDEO_FA },
            { "scart",     OPTION_VAL_SCART_FA },
            { "vga",       OPTION_VAL_VGA_FA },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_FA,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_FA,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_FA,
        NULL,
        XEMU_USE_DSP_INFO_0_FA,
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
        XEMU_DSP_JIT_LABEL_FA,
        NULL,
        XEMU_DSP_JIT_INFO_0_FA,
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
        XEMU_HRTF_LABEL_FA,
        NULL,
        XEMU_HRTF_INFO_0_FA,
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
        XEMU_VP_WORKERS_LABEL_FA,
        NULL,
        XEMU_VP_WORKERS_INFO_0_FA,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_FA },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_FA,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_FA,
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
        XEMU_AUDIO_VOLUME_LABEL_FA,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_FA,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_FA },
            { "80",  OPTION_VAL_80_FA },
            { "60",  OPTION_VAL_60_FA },
            { "40",  OPTION_VAL_40_FA },
            { "20",  OPTION_VAL_20_FA },
            { "0",   OPTION_VAL_0_FA },
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
        XEMU_VK_FAST_PATHS_LABEL_FA,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_FA,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_FA },
            { "no_gpl",   OPTION_VAL_NO_GPL_FA },
            { "no_dyn",   OPTION_VAL_NO_DYN_FA },
            { "none",     OPTION_VAL_NONE_FA },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_FA,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_FA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_FA,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_FA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_FA,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_FA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_FA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_FA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_FA },
            { "15", OPTION_VAL_15_FA },
            { "20", OPTION_VAL_20_FA },
            { "25", OPTION_VAL_25_FA },
            { "30", OPTION_VAL_30_FA },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_FA,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_FA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_FA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_FA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_FA },
            { "15", OPTION_VAL_15_FA },
            { "20", OPTION_VAL_20_FA },
            { "25", OPTION_VAL_25_FA },
            { "30", OPTION_VAL_30_FA },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_FA,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_FA,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_FA,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_FA,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_FA },
            { "stick", OPTION_VAL_STICK_FA },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_FA,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_FA,
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
        XEMU_CHIHIRO_FFB_LABEL_FA,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_FA,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_FA },
            { "50",  OPTION_VAL_50_FA },
            { "75",  OPTION_VAL_75_FA },
            { "100", OPTION_VAL_100_FA },
            { "150", OPTION_VAL_150_FA },
            { "200", OPTION_VAL_200_FA },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_fa = {
   option_cats_fa,
   option_defs_fa
};

/* RETRO_LANGUAGE_FI */

#define CATEGORY_SYSTEM_LABEL_FI NULL
#define CATEGORY_SYSTEM_INFO_0_FI NULL
#define CATEGORY_VIDEO_LABEL_FI NULL
#define CATEGORY_VIDEO_INFO_0_FI NULL
#define CATEGORY_AUDIO_LABEL_FI "Ääni"
#define CATEGORY_AUDIO_INFO_0_FI NULL
#define CATEGORY_CONTROLS_LABEL_FI "Ohjaus"
#define CATEGORY_CONTROLS_INFO_0_FI NULL
#define CATEGORY_CHIHIRO_LABEL_FI NULL
#define CATEGORY_CHIHIRO_INFO_0_FI NULL
#define XEMU_MEMORY_LABEL_FI NULL
#define XEMU_MEMORY_INFO_0_FI NULL
#define OPTION_VAL_64_FI "64 Mt"
#define OPTION_VAL_128_FI "128 Mt"
#define XEMU_NETWORK_BACKEND_LABEL_FI NULL
#define XEMU_NETWORK_BACKEND_INFO_0_FI NULL
#define OPTION_VAL_NAT_FI NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_FI NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_FI NULL
#define XEMU_HARD_FPU_LABEL_FI NULL
#define XEMU_HARD_FPU_INFO_0_FI NULL
#define XEMU_CPU_BOOST_LABEL_FI NULL
#define XEMU_CPU_BOOST_INFO_0_FI NULL
#define XEMU_HDD_TRIM_LABEL_FI NULL
#define XEMU_HDD_TRIM_INFO_0_FI NULL
#define XEMU_RENDERER_LABEL_FI NULL
#define XEMU_RENDERER_INFO_0_FI NULL
#define OPTION_VAL_VULKAN_FI NULL
#define OPTION_VAL_OPENGL_FI NULL
#define XEMU_VIDEO_ASPECT_LABEL_FI NULL
#define XEMU_VIDEO_ASPECT_INFO_0_FI NULL
#define OPTION_VAL_DASHBOARD_FI NULL
#define OPTION_VAL_4_3_FI NULL
#define OPTION_VAL_16_9_FI NULL
#define OPTION_VAL_LETTERBOX_FI NULL
#define XEMU_ASPECT_RATIO_LABEL_FI "Ytimen kuvasuhde"
#define XEMU_ASPECT_RATIO_INFO_0_FI NULL
#define OPTION_VAL_AUTO_FI "Automaattinen"
#define XEMU_SURFACE_SCALE_LABEL_FI NULL
#define XEMU_SURFACE_SCALE_INFO_0_FI NULL
#define OPTION_VAL_1_FI NULL
#define OPTION_VAL_2_FI NULL
#define OPTION_VAL_3_FI NULL
#define OPTION_VAL_4_FI NULL
#define OPTION_VAL_5_FI NULL
#define OPTION_VAL_6_FI NULL
#define OPTION_VAL_7_FI NULL
#define OPTION_VAL_8_FI NULL
#define OPTION_VAL_9_FI NULL
#define OPTION_VAL_10_FI NULL
#define XEMU_AVPACK_LABEL_FI NULL
#define XEMU_AVPACK_INFO_0_FI NULL
#define OPTION_VAL_HDTV_FI NULL
#define OPTION_VAL_COMPOSITE_FI "Komposiitti"
#define OPTION_VAL_SVIDEO_FI NULL
#define OPTION_VAL_SCART_FI NULL
#define OPTION_VAL_VGA_FI NULL
#define XEMU_AUDIO_THREAD_LABEL_FI NULL
#define XEMU_AUDIO_THREAD_INFO_0_FI NULL
#define XEMU_USE_DSP_LABEL_FI NULL
#define XEMU_USE_DSP_INFO_0_FI NULL
#define XEMU_DSP_JIT_LABEL_FI NULL
#define XEMU_DSP_JIT_INFO_0_FI NULL
#define XEMU_HRTF_LABEL_FI NULL
#define XEMU_HRTF_INFO_0_FI NULL
#define XEMU_VP_WORKERS_LABEL_FI NULL
#define XEMU_VP_WORKERS_INFO_0_FI NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_FI NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_FI NULL
#define XEMU_AUDIO_VOLUME_LABEL_FI NULL
#define XEMU_AUDIO_VOLUME_INFO_0_FI NULL
#define OPTION_VAL_100_FI "100 %"
#define OPTION_VAL_80_FI "80 %"
#define OPTION_VAL_60_FI "60 %"
#define OPTION_VAL_40_FI "40 %"
#define OPTION_VAL_20_FI "20 %"
#define OPTION_VAL_0_FI NULL
#define XEMU_VK_FAST_PATHS_LABEL_FI NULL
#define XEMU_VK_FAST_PATHS_INFO_0_FI NULL
#define OPTION_VAL_ALL_FI "Kaikki"
#define OPTION_VAL_NO_GPL_FI NULL
#define OPTION_VAL_NO_DYN_FI NULL
#define OPTION_VAL_NONE_FI "Ei mitään"
#define XEMU_RUMBLE_P1_LABEL_FI NULL
#define XEMU_RUMBLE_P1_INFO_0_FI NULL
#define XEMU_RUMBLE_P2_LABEL_FI NULL
#define XEMU_RUMBLE_P2_INFO_0_FI NULL
#define XEMU_DEADZONE_P1_LABEL_FI NULL
#define XEMU_DEADZONE_P1_INFO_0_FI NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_FI NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_FI NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_FI NULL
#define OPTION_VAL_15_FI "15 %"
#define OPTION_VAL_25_FI NULL
#define OPTION_VAL_30_FI "30 %"
#define XEMU_DEADZONE_P2_LABEL_FI NULL
#define XEMU_DEADZONE_P2_INFO_0_FI NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_FI NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_FI NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_FI NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_FI NULL
#define OPTION_VAL_MOUSE_FI "Hiiri"
#define OPTION_VAL_STICK_FI NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_FI NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_FI NULL
#define XEMU_CHIHIRO_FFB_LABEL_FI NULL
#define XEMU_CHIHIRO_FFB_INFO_0_FI NULL
#define OPTION_VAL_50_FI "50 %"
#define OPTION_VAL_75_FI "75 %"
#define OPTION_VAL_150_FI "150 %"
#define OPTION_VAL_200_FI "200 %"

struct retro_core_option_v2_category option_cats_fi[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_FI,
        CATEGORY_SYSTEM_INFO_0_FI
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_FI,
        CATEGORY_VIDEO_INFO_0_FI
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_FI,
        CATEGORY_AUDIO_INFO_0_FI
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_FI,
        CATEGORY_CONTROLS_INFO_0_FI
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_FI,
        CATEGORY_CHIHIRO_INFO_0_FI
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fi[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_FI,
        NULL,
        XEMU_MEMORY_INFO_0_FI,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_FI },
            { "128", OPTION_VAL_128_FI },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_FI,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_FI,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_FI },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_FI,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_FI,
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
        XEMU_HARD_FPU_LABEL_FI,
        NULL,
        XEMU_HARD_FPU_INFO_0_FI,
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
        XEMU_CPU_BOOST_LABEL_FI,
        NULL,
        XEMU_CPU_BOOST_INFO_0_FI,
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
        XEMU_HDD_TRIM_LABEL_FI,
        NULL,
        XEMU_HDD_TRIM_INFO_0_FI,
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
        XEMU_RENDERER_LABEL_FI,
        NULL,
        XEMU_RENDERER_INFO_0_FI,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_FI },
            { "opengl", OPTION_VAL_OPENGL_FI },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_FI,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_FI,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_FI },
            { "4:3",       OPTION_VAL_4_3_FI },
            { "16:9",      OPTION_VAL_16_9_FI },
            { "letterbox", OPTION_VAL_LETTERBOX_FI },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_FI,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_FI,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_FI },
            { "4:3",  OPTION_VAL_4_3_FI },
            { "16:9", OPTION_VAL_16_9_FI },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_FI,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_FI,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_FI },
            { "2", OPTION_VAL_2_FI },
            { "3", OPTION_VAL_3_FI },
            { "4", OPTION_VAL_4_FI },
            { "5", OPTION_VAL_5_FI },
            { "6", OPTION_VAL_6_FI },
            { "7", OPTION_VAL_7_FI },
            { "8", OPTION_VAL_8_FI },
            { "9", OPTION_VAL_9_FI },
            { "10", OPTION_VAL_10_FI },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_FI,
        NULL,
        XEMU_AVPACK_INFO_0_FI,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_FI },
            { "composite", OPTION_VAL_COMPOSITE_FI },
            { "svideo",    OPTION_VAL_SVIDEO_FI },
            { "scart",     OPTION_VAL_SCART_FI },
            { "vga",       OPTION_VAL_VGA_FI },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_FI,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_FI,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_FI,
        NULL,
        XEMU_USE_DSP_INFO_0_FI,
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
        XEMU_DSP_JIT_LABEL_FI,
        NULL,
        XEMU_DSP_JIT_INFO_0_FI,
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
        XEMU_HRTF_LABEL_FI,
        NULL,
        XEMU_HRTF_INFO_0_FI,
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
        XEMU_VP_WORKERS_LABEL_FI,
        NULL,
        XEMU_VP_WORKERS_INFO_0_FI,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_FI },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_FI,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_FI,
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
        XEMU_AUDIO_VOLUME_LABEL_FI,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_FI,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_FI },
            { "80",  OPTION_VAL_80_FI },
            { "60",  OPTION_VAL_60_FI },
            { "40",  OPTION_VAL_40_FI },
            { "20",  OPTION_VAL_20_FI },
            { "0",   OPTION_VAL_0_FI },
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
        XEMU_VK_FAST_PATHS_LABEL_FI,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_FI,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_FI },
            { "no_gpl",   OPTION_VAL_NO_GPL_FI },
            { "no_dyn",   OPTION_VAL_NO_DYN_FI },
            { "none",     OPTION_VAL_NONE_FI },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_FI,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_FI,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_FI,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_FI,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_FI,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_FI,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_FI },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_FI },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_FI },
            { "15", OPTION_VAL_15_FI },
            { "20", OPTION_VAL_20_FI },
            { "25", OPTION_VAL_25_FI },
            { "30", OPTION_VAL_30_FI },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_FI,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_FI,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_FI },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_FI },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_FI },
            { "15", OPTION_VAL_15_FI },
            { "20", OPTION_VAL_20_FI },
            { "25", OPTION_VAL_25_FI },
            { "30", OPTION_VAL_30_FI },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_FI,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_FI,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_FI,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_FI,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_FI },
            { "stick", OPTION_VAL_STICK_FI },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_FI,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_FI,
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
        XEMU_CHIHIRO_FFB_LABEL_FI,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_FI,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_FI },
            { "50",  OPTION_VAL_50_FI },
            { "75",  OPTION_VAL_75_FI },
            { "100", OPTION_VAL_100_FI },
            { "150", OPTION_VAL_150_FI },
            { "200", OPTION_VAL_200_FI },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_fi = {
   option_cats_fi,
   option_defs_fi
};

/* RETRO_LANGUAGE_FR */

#define CATEGORY_SYSTEM_LABEL_FR NULL
#define CATEGORY_SYSTEM_INFO_0_FR NULL
#define CATEGORY_VIDEO_LABEL_FR "Vidéo"
#define CATEGORY_VIDEO_INFO_0_FR "Configurer les réglages de rendu vidéo."
#define CATEGORY_AUDIO_LABEL_FR "Audio "
#define CATEGORY_AUDIO_INFO_0_FR "Configurer les réglages d'émulation audio."
#define CATEGORY_CONTROLS_LABEL_FR "Touches"
#define CATEGORY_CONTROLS_INFO_0_FR NULL
#define CATEGORY_CHIHIRO_LABEL_FR NULL
#define CATEGORY_CHIHIRO_INFO_0_FR NULL
#define XEMU_MEMORY_LABEL_FR "Mémoire système (Mo)"
#define XEMU_MEMORY_INFO_0_FR "Quantité de RAM du système. 64 Mo est la norme ; 128 Mo sont utilisés par les kits de débogage."
#define OPTION_VAL_64_FR "64 Mo"
#define OPTION_VAL_128_FR "128 Mo"
#define XEMU_NETWORK_BACKEND_LABEL_FR "Backend réseau"
#define XEMU_NETWORK_BACKEND_INFO_0_FR "Activer la prise en charge réseau pour les jeux Xbox dotés de fonctionnalités LAN/System Link. Le backend NAT assure une connectivité de base."
#define OPTION_VAL_NAT_FR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_FR "Passer l'animation de démarrage"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_FR "Passer l'animation de démarrage de la Xbox."
#define XEMU_HARD_FPU_LABEL_FR "Émulation matérielle de FPU"
#define XEMU_HARD_FPU_INFO_0_FR "Utiliser la FPU de l'hôte pour l'émulation x87. Plus rapide, mais peut entraîner de légères imprécisions."
#define XEMU_CPU_BOOST_LABEL_FR NULL
#define XEMU_CPU_BOOST_INFO_0_FR NULL
#define XEMU_HDD_TRIM_LABEL_FR NULL
#define XEMU_HDD_TRIM_INFO_0_FR NULL
#define XEMU_RENDERER_LABEL_FR "API graphique (redémarrage)"
#define XEMU_RENDERER_INFO_0_FR "Le moteur de rendu utilisé pour afficher le processeur graphique émulé. Vulkan est l'option par défaut ; OpenGL sert d'alternative lorsque Vulkan ne fonctionne pas correctement. La modification prend effet après le redémarrage de RetroArch. Android utilise toujours Vulkan, tandis que macOS utilise toujours OpenGL."
#define OPTION_VAL_VULKAN_FR NULL
#define OPTION_VAL_OPENGL_FR NULL
#define XEMU_VIDEO_ASPECT_LABEL_FR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_FR NULL
#define OPTION_VAL_DASHBOARD_FR NULL
#define OPTION_VAL_4_3_FR NULL
#define OPTION_VAL_16_9_FR NULL
#define OPTION_VAL_LETTERBOX_FR NULL
#define XEMU_ASPECT_RATIO_LABEL_FR "Rapport d'aspect du cœur"
#define XEMU_ASPECT_RATIO_INFO_0_FR NULL
#define OPTION_VAL_AUTO_FR NULL
#define XEMU_SURFACE_SCALE_LABEL_FR NULL
#define XEMU_SURFACE_SCALE_INFO_0_FR "Ajuste l'échelle de la résolution de rendu interne. Des valeurs plus élevées améliorent la qualité mais réduisent les performances."
#define OPTION_VAL_1_FR "x1 (640 x 480)"
#define OPTION_VAL_2_FR "x2 (1280 x 960)"
#define OPTION_VAL_3_FR "x3 (1920 x 1440)"
#define OPTION_VAL_4_FR "x4 (2560 x 1920)"
#define OPTION_VAL_5_FR "x5 (3200 x 2400)"
#define OPTION_VAL_6_FR "x6 (3840 x 2880)"
#define OPTION_VAL_7_FR "x7 (4480 x 3360)"
#define OPTION_VAL_8_FR "x8 (5120 x 3840)"
#define OPTION_VAL_9_FR "x9 (5760 x 4320)"
#define OPTION_VAL_10_FR "x10 (6400 x 4800)"
#define XEMU_AVPACK_LABEL_FR NULL
#define XEMU_AVPACK_INFO_0_FR "Sélectionner le type de pack AV. Cela influe sur les modes vidéo disponibles."
#define OPTION_VAL_HDTV_FR "TVHD"
#define OPTION_VAL_COMPOSITE_FR NULL
#define OPTION_VAL_SVIDEO_FR NULL
#define OPTION_VAL_SCART_FR "Péritel (SCART)"
#define OPTION_VAL_VGA_FR NULL
#define XEMU_AUDIO_THREAD_LABEL_FR NULL
#define XEMU_AUDIO_THREAD_INFO_0_FR NULL
#define XEMU_USE_DSP_LABEL_FR "Émulation du DSP de l'APU"
#define XEMU_USE_DSP_INFO_0_FR "Activer l'émulation du DSP pour une meilleure fidélité audio. Cela peut affecter les performances."
#define XEMU_DSP_JIT_LABEL_FR NULL
#define XEMU_DSP_JIT_INFO_0_FR NULL
#define XEMU_HRTF_LABEL_FR NULL
#define XEMU_HRTF_INFO_0_FR NULL
#define XEMU_VP_WORKERS_LABEL_FR NULL
#define XEMU_VP_WORKERS_INFO_0_FR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_FR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_FR NULL
#define XEMU_AUDIO_VOLUME_LABEL_FR "Limite de volume audio (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_FR "Limiter le volume de sortie audio de la Xbox indépendamment du volume principal de RetroArch."
#define OPTION_VAL_100_FR "100 %"
#define OPTION_VAL_80_FR "80 %"
#define OPTION_VAL_60_FR "60 %"
#define OPTION_VAL_40_FR "40 %"
#define OPTION_VAL_20_FR "20 %"
#define OPTION_VAL_0_FR "Muet"
#define XEMU_VK_FAST_PATHS_LABEL_FR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_FR NULL
#define OPTION_VAL_ALL_FR "Tous"
#define OPTION_VAL_NO_GPL_FR NULL
#define OPTION_VAL_NO_DYN_FR NULL
#define OPTION_VAL_NONE_FR "Ne pas partager"
#define XEMU_RUMBLE_P1_LABEL_FR NULL
#define XEMU_RUMBLE_P1_INFO_0_FR NULL
#define XEMU_RUMBLE_P2_LABEL_FR NULL
#define XEMU_RUMBLE_P2_INFO_0_FR NULL
#define XEMU_DEADZONE_P1_LABEL_FR NULL
#define XEMU_DEADZONE_P1_INFO_0_FR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_FR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_FR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_FR NULL
#define OPTION_VAL_15_FR "15 %"
#define OPTION_VAL_25_FR NULL
#define OPTION_VAL_30_FR "30 %"
#define XEMU_DEADZONE_P2_LABEL_FR NULL
#define XEMU_DEADZONE_P2_INFO_0_FR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_FR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_FR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_FR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_FR NULL
#define OPTION_VAL_MOUSE_FR "Souris"
#define OPTION_VAL_STICK_FR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_FR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_FR NULL
#define XEMU_CHIHIRO_FFB_LABEL_FR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_FR NULL
#define OPTION_VAL_50_FR "50 %"
#define OPTION_VAL_75_FR "75 %"
#define OPTION_VAL_150_FR "150 %"
#define OPTION_VAL_200_FR "200 %"

struct retro_core_option_v2_category option_cats_fr[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_FR,
        CATEGORY_SYSTEM_INFO_0_FR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_FR,
        CATEGORY_VIDEO_INFO_0_FR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_FR,
        CATEGORY_AUDIO_INFO_0_FR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_FR,
        CATEGORY_CONTROLS_INFO_0_FR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_FR,
        CATEGORY_CHIHIRO_INFO_0_FR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fr[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_FR,
        NULL,
        XEMU_MEMORY_INFO_0_FR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_FR },
            { "128", OPTION_VAL_128_FR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_FR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_FR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_FR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_FR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_FR,
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
        XEMU_HARD_FPU_LABEL_FR,
        NULL,
        XEMU_HARD_FPU_INFO_0_FR,
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
        XEMU_CPU_BOOST_LABEL_FR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_FR,
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
        XEMU_HDD_TRIM_LABEL_FR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_FR,
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
        XEMU_RENDERER_LABEL_FR,
        NULL,
        XEMU_RENDERER_INFO_0_FR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_FR },
            { "opengl", OPTION_VAL_OPENGL_FR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_FR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_FR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_FR },
            { "4:3",       OPTION_VAL_4_3_FR },
            { "16:9",      OPTION_VAL_16_9_FR },
            { "letterbox", OPTION_VAL_LETTERBOX_FR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_FR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_FR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_FR },
            { "4:3",  OPTION_VAL_4_3_FR },
            { "16:9", OPTION_VAL_16_9_FR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_FR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_FR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_FR },
            { "2", OPTION_VAL_2_FR },
            { "3", OPTION_VAL_3_FR },
            { "4", OPTION_VAL_4_FR },
            { "5", OPTION_VAL_5_FR },
            { "6", OPTION_VAL_6_FR },
            { "7", OPTION_VAL_7_FR },
            { "8", OPTION_VAL_8_FR },
            { "9", OPTION_VAL_9_FR },
            { "10", OPTION_VAL_10_FR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_FR,
        NULL,
        XEMU_AVPACK_INFO_0_FR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_FR },
            { "composite", OPTION_VAL_COMPOSITE_FR },
            { "svideo",    OPTION_VAL_SVIDEO_FR },
            { "scart",     OPTION_VAL_SCART_FR },
            { "vga",       OPTION_VAL_VGA_FR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_FR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_FR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_FR,
        NULL,
        XEMU_USE_DSP_INFO_0_FR,
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
        XEMU_DSP_JIT_LABEL_FR,
        NULL,
        XEMU_DSP_JIT_INFO_0_FR,
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
        XEMU_HRTF_LABEL_FR,
        NULL,
        XEMU_HRTF_INFO_0_FR,
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
        XEMU_VP_WORKERS_LABEL_FR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_FR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_FR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_FR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_FR,
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
        XEMU_AUDIO_VOLUME_LABEL_FR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_FR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_FR },
            { "80",  OPTION_VAL_80_FR },
            { "60",  OPTION_VAL_60_FR },
            { "40",  OPTION_VAL_40_FR },
            { "20",  OPTION_VAL_20_FR },
            { "0",   OPTION_VAL_0_FR },
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
        XEMU_VK_FAST_PATHS_LABEL_FR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_FR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_FR },
            { "no_gpl",   OPTION_VAL_NO_GPL_FR },
            { "no_dyn",   OPTION_VAL_NO_DYN_FR },
            { "none",     OPTION_VAL_NONE_FR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_FR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_FR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_FR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_FR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_FR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_FR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_FR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_FR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_FR },
            { "15", OPTION_VAL_15_FR },
            { "20", OPTION_VAL_20_FR },
            { "25", OPTION_VAL_25_FR },
            { "30", OPTION_VAL_30_FR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_FR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_FR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_FR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_FR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_FR },
            { "15", OPTION_VAL_15_FR },
            { "20", OPTION_VAL_20_FR },
            { "25", OPTION_VAL_25_FR },
            { "30", OPTION_VAL_30_FR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_FR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_FR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_FR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_FR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_FR },
            { "stick", OPTION_VAL_STICK_FR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_FR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_FR,
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
        XEMU_CHIHIRO_FFB_LABEL_FR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_FR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_FR },
            { "50",  OPTION_VAL_50_FR },
            { "75",  OPTION_VAL_75_FR },
            { "100", OPTION_VAL_100_FR },
            { "150", OPTION_VAL_150_FR },
            { "200", OPTION_VAL_200_FR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_fr = {
   option_cats_fr,
   option_defs_fr
};

/* RETRO_LANGUAGE_GA */

#define CATEGORY_SYSTEM_LABEL_GA "Córas (Atosaigh)"
#define CATEGORY_SYSTEM_INFO_0_GA "An meaisín féin: cuimhne, líonra, tosú agus LAP. Gabhtar é seo nuair a thosaíonn an t-ábhar (baintear úsáid as 'Trim HDD on Close' nuair a dhúntar é)."
#define CATEGORY_VIDEO_LABEL_GA "Físeán"
#define CATEGORY_VIDEO_INFO_0_GA "Cumraigh socruithe rindreála físe."
#define CATEGORY_AUDIO_LABEL_GA "Fuaim"
#define CATEGORY_AUDIO_INFO_0_GA "Cumraigh socruithe na haithrise fuaime."
#define CATEGORY_CONTROLS_LABEL_GA "Rialuithe"
#define CATEGORY_CONTROLS_INFO_0_GA "Creathadh agus crios marbh na luamhán, in aghaidh an imreora."
#define CATEGORY_CHIHIRO_LABEL_GA NULL
#define CATEGORY_CHIHIRO_INFO_0_GA "Cluichí áircéid Sega Chihiro: súgradh saor in aisce, díriú i gcluichí gunna, agus aiseolas fórsa i gcluichí rásaíochta."
#define XEMU_MEMORY_LABEL_GA "Cuimhne an Chórais (MB)"
#define XEMU_MEMORY_INFO_0_GA "Méid an RAM córais. Is é 64 MB an caighdeán; úsáideann feisteas dífhabhtaithe 128 MB."
#define OPTION_VAL_64_GA NULL
#define OPTION_VAL_128_GA NULL
#define XEMU_NETWORK_BACKEND_LABEL_GA "Cúlchóras Líonra"
#define XEMU_NETWORK_BACKEND_INFO_0_GA "Cumasaigh tacaíocht líonra do chluichí Xbox a bhfuil gnéithe LAN/System Link acu. Soláthraíonn an cúlchóras NAT nascacht bhunúsach."
#define OPTION_VAL_NAT_GA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_GA "Scipeáil an Beochan Tosaithe"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_GA "Scipeáil an beochan tosaithe Xbox."
#define XEMU_HARD_FPU_LABEL_GA "Aithris FPU trí Chrua-earraí"
#define XEMU_HARD_FPU_INFO_0_GA "Bain úsáid as FPU an óstaigh le haghaidh aithrise x87. Bíonn sé níos tapúla, ach d’fhéadfadh mion-mhíchruinneas a bheith i gceist."
#define XEMU_CPU_BOOST_LABEL_GA "Treisiú LAP"
#define XEMU_CPU_BOOST_INFO_0_GA "Bealaí níos tapúla don LAP aíonna agus don phróiseálaí fuaime: SSE dúchasach agus taisce léimneach níos leithne. Múch é má bhíonn fadhbanna le cluiche."
#define XEMU_HDD_TRIM_LABEL_GA "Trim an HDD agus é á dhúnadh"
#define XEMU_HDD_TRIM_INFO_0_GA "Nuair a dhúntar an cluiche, glantar na deighiltí taisce X, Y agus Z ar an diosca crua (déanfaidh na cluichí iad a fhormáidiú arís nuair a bheidh siad ag teastáil uathu) agus athscríobhtar an íomhá gan an spás neamhúsáidte, rud a fhágann go laghdaítear méid an chomhaid. Teastaíonn méid spáis shaor atá comhionann le sonraí na híomhá, ar feadh tamaill. Ní dhéantar an próiseas seo má tá 'stát sábháilte' ag an íomhá. Déantar é seo nuair a dhúntar an cluiche, ní nuair a thosaítear arís é."
#define XEMU_RENDERER_LABEL_GA "API Grafaice (Atosaigh)"
#define XEMU_RENDERER_INFO_0_GA "An t-inneall rindreála a úsáidtear chun an GPU insamhlaithe a tharraingt. Is é Vulkan an rogha réamhshocraithe; úsáidtear OpenGL mar rogha chúltaca i gcás tiománaithe nach n-oibríonn i gceart le Vulkan. Tiocfaidh an t-athrú i bhfeidhm tar éis RetroArch a atosú. Úsáideann Android Vulkan i gcónaí, agus úsáideann macOS OpenGL i gcónaí."
#define OPTION_VAL_VULKAN_GA NULL
#define OPTION_VAL_OPENGL_GA NULL
#define XEMU_VIDEO_ASPECT_LABEL_GA "Cóimheas Gné an Chórais (Atosaigh)"
#define XEMU_VIDEO_ASPECT_INFO_0_GA "Socraíonn sé seo an fhormáid taispeána a thuairiscíonn an consól do chluichí, in áit an tsocraithe atá ag an deais. Má roghnaítear 16:9, rithfidh cluichí a thacaíonn le scáileán leathan i bhformáid scáileáin leathain; má roghnaítear 4:3, rithfidh siad i bhformáid 4:3. Roghnaigh an socrú a fhreagraíonn do chruth do scáileáin. Úsáideann an rogha 'Letterbox' formáid 4:3 na deais, ach taispeántar cluichí scáileáin leathain le barraí dubha ag an mbarr agus ag an mbun. Coinníonn an rogha 'Dashboard' an socrú atá ag an deais féin."
#define OPTION_VAL_DASHBOARD_GA "Painéal Rialúcháin"
#define OPTION_VAL_4_3_GA NULL
#define OPTION_VAL_16_9_GA NULL
#define OPTION_VAL_LETTERBOX_GA "Bosca litreacha"
#define XEMU_ASPECT_RATIO_LABEL_GA "Cóimheas Gné Croí"
#define XEMU_ASPECT_RATIO_INFO_0_GA "An cruth ina dtaispeántar an pictiúr. Is fearr é a fhágáil ar 'Auto', a leanann an cluiche: 16:9 nuair a bhíonn an consól socraithe ar scáileán leathan (Cóimheas Gné an Chórais nó an deais) agus an cluiche á rindreáil i 16:9; 4:3 ar shlí eile, nó ar chóras Chihiro. Síneann an suíomh 16:9 cluiche 4:3 amach chun an scáileán leathan a líonadh."
#define OPTION_VAL_AUTO_GA "Uathoibríoch"
#define XEMU_SURFACE_SCALE_LABEL_GA "Scála Réitigh Inmheánaigh (Atosaigh)"
#define XEMU_SURFACE_SCALE_INFO_0_GA "Déanann sé scálú ar an réiteach inmheánach rindreála. Feabhsaíonn luachanna níos airde an caighdeán ach laghdaíonn siad an fheidhmíocht."
#define OPTION_VAL_1_GA NULL
#define OPTION_VAL_2_GA NULL
#define OPTION_VAL_3_GA NULL
#define OPTION_VAL_4_GA NULL
#define OPTION_VAL_5_GA NULL
#define OPTION_VAL_6_GA NULL
#define OPTION_VAL_7_GA NULL
#define OPTION_VAL_8_GA NULL
#define OPTION_VAL_9_GA NULL
#define OPTION_VAL_10_GA NULL
#define XEMU_AVPACK_LABEL_GA "Pacáiste AV (Atosaigh)"
#define XEMU_AVPACK_INFO_0_GA "Roghnaigh an cineál pacáiste AV. Bíonn tionchar aige ar na modhanna físe atá ar fáil."
#define OPTION_VAL_HDTV_GA NULL
#define OPTION_VAL_COMPOSITE_GA "Ilchodach"
#define OPTION_VAL_SVIDEO_GA "S-Físeán"
#define OPTION_VAL_SCART_GA NULL
#define OPTION_VAL_VGA_GA NULL
#define XEMU_AUDIO_THREAD_LABEL_GA "Snáithe Fuaime (Atosaigh)"
#define XEMU_AUDIO_THREAD_INFO_0_GA "Tugann sé an fhuaim do shnáithe fuaime RetroArch agus an APU á mheascadh, agus é á sheinm go neamhspleách, seachas fráma amháin a bheith in aghaidh gach fráma: leanann an fhuaim ar aghaidh agus na frámaí ag stopadh, amhail is dá mba rud é go mbíonn scáthaitheoirí ag tiomsú."
#define XEMU_USE_DSP_LABEL_GA "Aithris APU DSP"
#define XEMU_USE_DSP_INFO_0_GA "Cumasaigh aithris DSP chun cruinneas fuaime a fheabhsú. D’fhéadfadh tionchar a bheith aige ar an bhfeidhmíocht."
#define XEMU_DSP_JIT_LABEL_GA NULL
#define XEMU_DSP_JIT_INFO_0_GA "Ritheann sé cláir Aithriseoireachta DSP an APU mar chód tiomsaithe in áit iad a léirmhíniú: tá sé níos tapúla, cosúil le JIT DSP i bhfeidhmchlár neamhspleách. Ní dhéanann sé aon rud mura bhfuil Aithriseoireacht DSP an APU casta air."
#define XEMU_HRTF_LABEL_GA NULL
#define XEMU_HRTF_INFO_0_GA "Cuireann sé guthanna 3D i gcluichí a bhaineann úsáid astu ina n-ionad cuí, ag baint úsáide as feidhmeanna aistrithe a bhaineann leis an gceann — díreach mar a dhéantar ar an gconsól — le haghaidh cluasán agus callairí steirió."
#define XEMU_VP_WORKERS_LABEL_GA "Snáitheanna Próiseálaí Gutha (Atosaigh)"
#define XEMU_VP_WORKERS_INFO_0_GA "Snáitheanna a mheascann an próiseálaí gutha fuaime na guthanna orthu. Úsáideann an socrú uathoibríoch ceann amháin in aghaidh an chroíleacáin LAP."
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_GA "An Chéad Seinm Réidh (Atosaigh)"
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_GA "Tiomponn sé na *shaders* a úsáideann cluiche le linn an phróisis tosaithe, ionas nach mbeidh aon bhac ná preabadh sna chéad nóiméid agus iad á dtiomsú. Ar OpenGL coinníonn sé a bhfuil á thiomsú aige sa taisce scáthaithe, atá ar siúl i gcónaí."
#define XEMU_AUDIO_VOLUME_LABEL_GA "Teorainn Airde Fuaime (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_GA "Cuir teorainn le leibhéal toirte aschuir fuaime an Xbox go neamhspleách ar phríomh-toirt RetroArch."
#define OPTION_VAL_100_GA NULL
#define OPTION_VAL_80_GA NULL
#define OPTION_VAL_60_GA NULL
#define OPTION_VAL_40_GA NULL
#define OPTION_VAL_20_GA NULL
#define OPTION_VAL_0_GA "Balbhaithe"
#define XEMU_VK_FAST_PATHS_LABEL_GA "Conairí Tapa Vulkan (Atosaigh)"
#define XEMU_VK_FAST_PATHS_INFO_0_GA "Bíonn tionchar aige ar luas tiomsaithe scáthaithe ar Vulkan. Is é \"All\" an rogha is tapúla, ach d'fhéadfadh sé a chur faoi deara go dteipfeadh ar chluichí áirithe."
#define OPTION_VAL_ALL_GA "Gach"
#define OPTION_VAL_NO_GPL_GA "Gan Leabharlanna Píblíne"
#define OPTION_VAL_NO_DYN_GA "Gan Stáit Dhinimiciúla"
#define OPTION_VAL_NONE_GA "Dada"
#define XEMU_RUMBLE_P1_LABEL_GA "Rumble (Imreoir 1)"
#define XEMU_RUMBLE_P1_INFO_0_GA "Crithfidh rialtán Imreoir 1 — de bharr cluichí Xbox agus aiseolas fórsa ó chluiche rásaíochta Chihiro. Má bhíonn sé múchta, ní bheidh ceachtar acu i gceist."
#define XEMU_RUMBLE_P2_LABEL_GA "Creathadh (Imreoir 2)"
#define XEMU_RUMBLE_P2_INFO_0_GA "Tá ceap Imreoir 2 ag torann, ó na cluichí Xbox agus ó aiseolas fórsa i gcluiche rásaíochta Chihiro. Mura bhfuil sé ar siúl, ní bhíonn ceachtar acu i gceist."
#define XEMU_DEADZONE_P1_LABEL_GA "Crios Marbh Analógach (Imreoir 1)"
#define XEMU_DEADZONE_P1_INFO_0_GA "Cé chomh fada is féidir bataí imreora 1 a bhrú sula bhfeiceann an cluiche é, an dá bhata, ar an Xbox agus an Chihiro araon; déantar an chuid eile den ghluaiseacht a scálú suas go dtí an t-uasmhéid."
#define OPTION_VAL_0_XEMU_DEADZONE_P1_GA NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_GA NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_GA NULL
#define OPTION_VAL_15_GA NULL
#define OPTION_VAL_25_GA NULL
#define OPTION_VAL_30_GA NULL
#define XEMU_DEADZONE_P2_LABEL_GA "Crios Marbh Analógach (Imreoir 2)"
#define XEMU_DEADZONE_P2_INFO_0_GA "Cé chomh fada is féidir bataí imreoir 2 a bhrú sula bhfeiceann an cluiche é, an dá bhata, ar an Xbox agus an Chihiro araon; déantar an chuid eile den ghluaiseacht a scálú suas go dtí an t-uasmhéid."
#define XEMU_CHIHIRO_FREEPLAY_LABEL_GA "Imirt Shaor (Atosaigh)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_GA "Cuireann sé tús le cluichí Sega Chihiro i mód súgartha saor in aisce, gan boinn. Nuair atá sé múchta, cuireann an cnaipe 'Select' bonn isteach."
#define XEMU_CHIHIRO_GUN_AIM_LABEL_GA "Díriú le Gunna Solais"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_GA "Cad iad na haidhmeanna atá i House of the Dead III, Virtua Cop 3 agus Ghost Squad? Luch: déantar díriú leis an luch (nó le gunna solais *RetroArch*); scaoileann an cnaipe clé, feidhmíonn an cnaipe deas mar chnaipe an ghunna (chun an gunna a luchtú nó airm a athrú), agus rialaíonn an cnaipe lár an peadal nó an ráta scaoilte. Bata Analógach: déantar díriú leis an mbata clé nó leis an eochaircheap treo D-pad; scaoileann *R2*, feidhmíonn *L2* mar chnaipe an ghunna, rialaíonn *L* an peadal nó an ráta scaoilte, agus scaoileann *R* lasmuigh den scáileán."
#define OPTION_VAL_MOUSE_GA "Luch"
#define OPTION_VAL_STICK_GA "Maide Analógach"
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_GA "Croisghléas"
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_GA "Tarraingíonn sé sprioc gach imreora thar an bpictiúr; dearg d'Imreoir 1, gorm d'Imreoir 2."
#define XEMU_CHIHIRO_FFB_LABEL_GA "Creathadh le haiseolas fórsa"
#define XEMU_CHIHIRO_FFB_INFO_0_GA "Cuireann sé aiseolas fórsa ó chluiche rásaíochta Chihiro (OutRun 2, Maximum Tune) ar fáil mar chreathadh ar an rialtóir i bport 1, ag an déine seo."
#define OPTION_VAL_50_GA NULL
#define OPTION_VAL_75_GA NULL
#define OPTION_VAL_150_GA NULL
#define OPTION_VAL_200_GA NULL

struct retro_core_option_v2_category option_cats_ga[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_GA,
        CATEGORY_SYSTEM_INFO_0_GA
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_GA,
        CATEGORY_VIDEO_INFO_0_GA
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_GA,
        CATEGORY_AUDIO_INFO_0_GA
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_GA,
        CATEGORY_CONTROLS_INFO_0_GA
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_GA,
        CATEGORY_CHIHIRO_INFO_0_GA
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ga[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_GA,
        NULL,
        XEMU_MEMORY_INFO_0_GA,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_GA },
            { "128", OPTION_VAL_128_GA },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_GA,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_GA,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_GA },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_GA,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_GA,
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
        XEMU_HARD_FPU_LABEL_GA,
        NULL,
        XEMU_HARD_FPU_INFO_0_GA,
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
        XEMU_CPU_BOOST_LABEL_GA,
        NULL,
        XEMU_CPU_BOOST_INFO_0_GA,
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
        XEMU_HDD_TRIM_LABEL_GA,
        NULL,
        XEMU_HDD_TRIM_INFO_0_GA,
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
        XEMU_RENDERER_LABEL_GA,
        NULL,
        XEMU_RENDERER_INFO_0_GA,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_GA },
            { "opengl", OPTION_VAL_OPENGL_GA },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_GA,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_GA,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_GA },
            { "4:3",       OPTION_VAL_4_3_GA },
            { "16:9",      OPTION_VAL_16_9_GA },
            { "letterbox", OPTION_VAL_LETTERBOX_GA },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_GA,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_GA,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_GA },
            { "4:3",  OPTION_VAL_4_3_GA },
            { "16:9", OPTION_VAL_16_9_GA },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_GA,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_GA,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_GA },
            { "2", OPTION_VAL_2_GA },
            { "3", OPTION_VAL_3_GA },
            { "4", OPTION_VAL_4_GA },
            { "5", OPTION_VAL_5_GA },
            { "6", OPTION_VAL_6_GA },
            { "7", OPTION_VAL_7_GA },
            { "8", OPTION_VAL_8_GA },
            { "9", OPTION_VAL_9_GA },
            { "10", OPTION_VAL_10_GA },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_GA,
        NULL,
        XEMU_AVPACK_INFO_0_GA,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_GA },
            { "composite", OPTION_VAL_COMPOSITE_GA },
            { "svideo",    OPTION_VAL_SVIDEO_GA },
            { "scart",     OPTION_VAL_SCART_GA },
            { "vga",       OPTION_VAL_VGA_GA },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_GA,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_GA,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_GA,
        NULL,
        XEMU_USE_DSP_INFO_0_GA,
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
        XEMU_DSP_JIT_LABEL_GA,
        NULL,
        XEMU_DSP_JIT_INFO_0_GA,
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
        XEMU_HRTF_LABEL_GA,
        NULL,
        XEMU_HRTF_INFO_0_GA,
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
        XEMU_VP_WORKERS_LABEL_GA,
        NULL,
        XEMU_VP_WORKERS_INFO_0_GA,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_GA },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_GA,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_GA,
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
        XEMU_AUDIO_VOLUME_LABEL_GA,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_GA,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_GA },
            { "80",  OPTION_VAL_80_GA },
            { "60",  OPTION_VAL_60_GA },
            { "40",  OPTION_VAL_40_GA },
            { "20",  OPTION_VAL_20_GA },
            { "0",   OPTION_VAL_0_GA },
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
        XEMU_VK_FAST_PATHS_LABEL_GA,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_GA,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_GA },
            { "no_gpl",   OPTION_VAL_NO_GPL_GA },
            { "no_dyn",   OPTION_VAL_NO_DYN_GA },
            { "none",     OPTION_VAL_NONE_GA },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_GA,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_GA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_GA,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_GA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_GA,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_GA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_GA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_GA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_GA },
            { "15", OPTION_VAL_15_GA },
            { "20", OPTION_VAL_20_GA },
            { "25", OPTION_VAL_25_GA },
            { "30", OPTION_VAL_30_GA },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_GA,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_GA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_GA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_GA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_GA },
            { "15", OPTION_VAL_15_GA },
            { "20", OPTION_VAL_20_GA },
            { "25", OPTION_VAL_25_GA },
            { "30", OPTION_VAL_30_GA },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_GA,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_GA,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_GA,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_GA,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_GA },
            { "stick", OPTION_VAL_STICK_GA },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_GA,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_GA,
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
        XEMU_CHIHIRO_FFB_LABEL_GA,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_GA,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_GA },
            { "50",  OPTION_VAL_50_GA },
            { "75",  OPTION_VAL_75_GA },
            { "100", OPTION_VAL_100_GA },
            { "150", OPTION_VAL_150_GA },
            { "200", OPTION_VAL_200_GA },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ga = {
   option_cats_ga,
   option_defs_ga
};

/* RETRO_LANGUAGE_GL */

#define CATEGORY_SYSTEM_LABEL_GL NULL
#define CATEGORY_SYSTEM_INFO_0_GL NULL
#define CATEGORY_VIDEO_LABEL_GL "Vídeo"
#define CATEGORY_VIDEO_INFO_0_GL NULL
#define CATEGORY_AUDIO_LABEL_GL "Son"
#define CATEGORY_AUDIO_INFO_0_GL NULL
#define CATEGORY_CONTROLS_LABEL_GL "Controis"
#define CATEGORY_CONTROLS_INFO_0_GL NULL
#define CATEGORY_CHIHIRO_LABEL_GL NULL
#define CATEGORY_CHIHIRO_INFO_0_GL NULL
#define XEMU_MEMORY_LABEL_GL NULL
#define XEMU_MEMORY_INFO_0_GL NULL
#define OPTION_VAL_64_GL NULL
#define OPTION_VAL_128_GL NULL
#define XEMU_NETWORK_BACKEND_LABEL_GL NULL
#define XEMU_NETWORK_BACKEND_INFO_0_GL NULL
#define OPTION_VAL_NAT_GL NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_GL NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_GL NULL
#define XEMU_HARD_FPU_LABEL_GL NULL
#define XEMU_HARD_FPU_INFO_0_GL NULL
#define XEMU_CPU_BOOST_LABEL_GL NULL
#define XEMU_CPU_BOOST_INFO_0_GL NULL
#define XEMU_HDD_TRIM_LABEL_GL NULL
#define XEMU_HDD_TRIM_INFO_0_GL NULL
#define XEMU_RENDERER_LABEL_GL NULL
#define XEMU_RENDERER_INFO_0_GL NULL
#define OPTION_VAL_VULKAN_GL NULL
#define OPTION_VAL_OPENGL_GL NULL
#define XEMU_VIDEO_ASPECT_LABEL_GL NULL
#define XEMU_VIDEO_ASPECT_INFO_0_GL NULL
#define OPTION_VAL_DASHBOARD_GL NULL
#define OPTION_VAL_4_3_GL NULL
#define OPTION_VAL_16_9_GL NULL
#define OPTION_VAL_LETTERBOX_GL NULL
#define XEMU_ASPECT_RATIO_LABEL_GL "Relación de aspecto do núcleo"
#define XEMU_ASPECT_RATIO_INFO_0_GL NULL
#define OPTION_VAL_AUTO_GL NULL
#define XEMU_SURFACE_SCALE_LABEL_GL NULL
#define XEMU_SURFACE_SCALE_INFO_0_GL NULL
#define OPTION_VAL_1_GL NULL
#define OPTION_VAL_2_GL NULL
#define OPTION_VAL_3_GL NULL
#define OPTION_VAL_4_GL NULL
#define OPTION_VAL_5_GL NULL
#define OPTION_VAL_6_GL NULL
#define OPTION_VAL_7_GL NULL
#define OPTION_VAL_8_GL NULL
#define OPTION_VAL_9_GL NULL
#define OPTION_VAL_10_GL NULL
#define XEMU_AVPACK_LABEL_GL NULL
#define XEMU_AVPACK_INFO_0_GL NULL
#define OPTION_VAL_HDTV_GL NULL
#define OPTION_VAL_COMPOSITE_GL "Composto"
#define OPTION_VAL_SVIDEO_GL NULL
#define OPTION_VAL_SCART_GL NULL
#define OPTION_VAL_VGA_GL NULL
#define XEMU_AUDIO_THREAD_LABEL_GL NULL
#define XEMU_AUDIO_THREAD_INFO_0_GL NULL
#define XEMU_USE_DSP_LABEL_GL NULL
#define XEMU_USE_DSP_INFO_0_GL NULL
#define XEMU_DSP_JIT_LABEL_GL NULL
#define XEMU_DSP_JIT_INFO_0_GL NULL
#define XEMU_HRTF_LABEL_GL NULL
#define XEMU_HRTF_INFO_0_GL NULL
#define XEMU_VP_WORKERS_LABEL_GL NULL
#define XEMU_VP_WORKERS_INFO_0_GL NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_GL NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_GL NULL
#define XEMU_AUDIO_VOLUME_LABEL_GL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_GL NULL
#define OPTION_VAL_100_GL NULL
#define OPTION_VAL_80_GL NULL
#define OPTION_VAL_60_GL NULL
#define OPTION_VAL_40_GL NULL
#define OPTION_VAL_20_GL NULL
#define OPTION_VAL_0_GL NULL
#define XEMU_VK_FAST_PATHS_LABEL_GL NULL
#define XEMU_VK_FAST_PATHS_INFO_0_GL NULL
#define OPTION_VAL_ALL_GL "Todo"
#define OPTION_VAL_NO_GPL_GL NULL
#define OPTION_VAL_NO_DYN_GL NULL
#define OPTION_VAL_NONE_GL "Ningún"
#define XEMU_RUMBLE_P1_LABEL_GL NULL
#define XEMU_RUMBLE_P1_INFO_0_GL NULL
#define XEMU_RUMBLE_P2_LABEL_GL NULL
#define XEMU_RUMBLE_P2_INFO_0_GL NULL
#define XEMU_DEADZONE_P1_LABEL_GL NULL
#define XEMU_DEADZONE_P1_INFO_0_GL NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_GL NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_GL NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_GL NULL
#define OPTION_VAL_15_GL NULL
#define OPTION_VAL_25_GL NULL
#define OPTION_VAL_30_GL NULL
#define XEMU_DEADZONE_P2_LABEL_GL NULL
#define XEMU_DEADZONE_P2_INFO_0_GL NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_GL NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_GL NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_GL NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_GL NULL
#define OPTION_VAL_MOUSE_GL "Rato"
#define OPTION_VAL_STICK_GL NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_GL NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_GL NULL
#define XEMU_CHIHIRO_FFB_LABEL_GL NULL
#define XEMU_CHIHIRO_FFB_INFO_0_GL NULL
#define OPTION_VAL_50_GL NULL
#define OPTION_VAL_75_GL NULL
#define OPTION_VAL_150_GL NULL
#define OPTION_VAL_200_GL NULL

struct retro_core_option_v2_category option_cats_gl[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_GL,
        CATEGORY_SYSTEM_INFO_0_GL
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_GL,
        CATEGORY_VIDEO_INFO_0_GL
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_GL,
        CATEGORY_AUDIO_INFO_0_GL
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_GL,
        CATEGORY_CONTROLS_INFO_0_GL
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_GL,
        CATEGORY_CHIHIRO_INFO_0_GL
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_gl[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_GL,
        NULL,
        XEMU_MEMORY_INFO_0_GL,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_GL },
            { "128", OPTION_VAL_128_GL },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_GL,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_GL,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_GL },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_GL,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_GL,
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
        XEMU_HARD_FPU_LABEL_GL,
        NULL,
        XEMU_HARD_FPU_INFO_0_GL,
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
        XEMU_CPU_BOOST_LABEL_GL,
        NULL,
        XEMU_CPU_BOOST_INFO_0_GL,
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
        XEMU_HDD_TRIM_LABEL_GL,
        NULL,
        XEMU_HDD_TRIM_INFO_0_GL,
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
        XEMU_RENDERER_LABEL_GL,
        NULL,
        XEMU_RENDERER_INFO_0_GL,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_GL },
            { "opengl", OPTION_VAL_OPENGL_GL },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_GL,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_GL,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_GL },
            { "4:3",       OPTION_VAL_4_3_GL },
            { "16:9",      OPTION_VAL_16_9_GL },
            { "letterbox", OPTION_VAL_LETTERBOX_GL },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_GL,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_GL,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_GL },
            { "4:3",  OPTION_VAL_4_3_GL },
            { "16:9", OPTION_VAL_16_9_GL },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_GL,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_GL,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_GL },
            { "2", OPTION_VAL_2_GL },
            { "3", OPTION_VAL_3_GL },
            { "4", OPTION_VAL_4_GL },
            { "5", OPTION_VAL_5_GL },
            { "6", OPTION_VAL_6_GL },
            { "7", OPTION_VAL_7_GL },
            { "8", OPTION_VAL_8_GL },
            { "9", OPTION_VAL_9_GL },
            { "10", OPTION_VAL_10_GL },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_GL,
        NULL,
        XEMU_AVPACK_INFO_0_GL,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_GL },
            { "composite", OPTION_VAL_COMPOSITE_GL },
            { "svideo",    OPTION_VAL_SVIDEO_GL },
            { "scart",     OPTION_VAL_SCART_GL },
            { "vga",       OPTION_VAL_VGA_GL },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_GL,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_GL,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_GL,
        NULL,
        XEMU_USE_DSP_INFO_0_GL,
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
        XEMU_DSP_JIT_LABEL_GL,
        NULL,
        XEMU_DSP_JIT_INFO_0_GL,
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
        XEMU_HRTF_LABEL_GL,
        NULL,
        XEMU_HRTF_INFO_0_GL,
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
        XEMU_VP_WORKERS_LABEL_GL,
        NULL,
        XEMU_VP_WORKERS_INFO_0_GL,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_GL },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_GL,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_GL,
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
        XEMU_AUDIO_VOLUME_LABEL_GL,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_GL,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_GL },
            { "80",  OPTION_VAL_80_GL },
            { "60",  OPTION_VAL_60_GL },
            { "40",  OPTION_VAL_40_GL },
            { "20",  OPTION_VAL_20_GL },
            { "0",   OPTION_VAL_0_GL },
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
        XEMU_VK_FAST_PATHS_LABEL_GL,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_GL,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_GL },
            { "no_gpl",   OPTION_VAL_NO_GPL_GL },
            { "no_dyn",   OPTION_VAL_NO_DYN_GL },
            { "none",     OPTION_VAL_NONE_GL },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_GL,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_GL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_GL,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_GL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_GL,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_GL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_GL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_GL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_GL },
            { "15", OPTION_VAL_15_GL },
            { "20", OPTION_VAL_20_GL },
            { "25", OPTION_VAL_25_GL },
            { "30", OPTION_VAL_30_GL },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_GL,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_GL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_GL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_GL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_GL },
            { "15", OPTION_VAL_15_GL },
            { "20", OPTION_VAL_20_GL },
            { "25", OPTION_VAL_25_GL },
            { "30", OPTION_VAL_30_GL },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_GL,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_GL,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_GL,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_GL,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_GL },
            { "stick", OPTION_VAL_STICK_GL },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_GL,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_GL,
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
        XEMU_CHIHIRO_FFB_LABEL_GL,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_GL,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_GL },
            { "50",  OPTION_VAL_50_GL },
            { "75",  OPTION_VAL_75_GL },
            { "100", OPTION_VAL_100_GL },
            { "150", OPTION_VAL_150_GL },
            { "200", OPTION_VAL_200_GL },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_gl = {
   option_cats_gl,
   option_defs_gl
};

/* RETRO_LANGUAGE_HE */

#define CATEGORY_SYSTEM_LABEL_HE NULL
#define CATEGORY_SYSTEM_INFO_0_HE NULL
#define CATEGORY_VIDEO_LABEL_HE "וידאו"
#define CATEGORY_VIDEO_INFO_0_HE NULL
#define CATEGORY_AUDIO_LABEL_HE "שמע"
#define CATEGORY_AUDIO_INFO_0_HE NULL
#define CATEGORY_CONTROLS_LABEL_HE NULL
#define CATEGORY_CONTROLS_INFO_0_HE NULL
#define CATEGORY_CHIHIRO_LABEL_HE NULL
#define CATEGORY_CHIHIRO_INFO_0_HE NULL
#define XEMU_MEMORY_LABEL_HE NULL
#define XEMU_MEMORY_INFO_0_HE NULL
#define OPTION_VAL_64_HE NULL
#define OPTION_VAL_128_HE NULL
#define XEMU_NETWORK_BACKEND_LABEL_HE NULL
#define XEMU_NETWORK_BACKEND_INFO_0_HE NULL
#define OPTION_VAL_NAT_HE NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_HE NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_HE NULL
#define XEMU_HARD_FPU_LABEL_HE NULL
#define XEMU_HARD_FPU_INFO_0_HE NULL
#define XEMU_CPU_BOOST_LABEL_HE NULL
#define XEMU_CPU_BOOST_INFO_0_HE NULL
#define XEMU_HDD_TRIM_LABEL_HE NULL
#define XEMU_HDD_TRIM_INFO_0_HE NULL
#define XEMU_RENDERER_LABEL_HE NULL
#define XEMU_RENDERER_INFO_0_HE NULL
#define OPTION_VAL_VULKAN_HE NULL
#define OPTION_VAL_OPENGL_HE NULL
#define XEMU_VIDEO_ASPECT_LABEL_HE NULL
#define XEMU_VIDEO_ASPECT_INFO_0_HE NULL
#define OPTION_VAL_DASHBOARD_HE NULL
#define OPTION_VAL_4_3_HE NULL
#define OPTION_VAL_16_9_HE NULL
#define OPTION_VAL_LETTERBOX_HE NULL
#define XEMU_ASPECT_RATIO_LABEL_HE NULL
#define XEMU_ASPECT_RATIO_INFO_0_HE NULL
#define OPTION_VAL_AUTO_HE NULL
#define XEMU_SURFACE_SCALE_LABEL_HE NULL
#define XEMU_SURFACE_SCALE_INFO_0_HE NULL
#define OPTION_VAL_1_HE NULL
#define OPTION_VAL_2_HE NULL
#define OPTION_VAL_3_HE NULL
#define OPTION_VAL_4_HE NULL
#define OPTION_VAL_5_HE NULL
#define OPTION_VAL_6_HE NULL
#define OPTION_VAL_7_HE NULL
#define OPTION_VAL_8_HE NULL
#define OPTION_VAL_9_HE NULL
#define OPTION_VAL_10_HE NULL
#define XEMU_AVPACK_LABEL_HE NULL
#define XEMU_AVPACK_INFO_0_HE NULL
#define OPTION_VAL_HDTV_HE NULL
#define OPTION_VAL_COMPOSITE_HE NULL
#define OPTION_VAL_SVIDEO_HE NULL
#define OPTION_VAL_SCART_HE NULL
#define OPTION_VAL_VGA_HE NULL
#define XEMU_AUDIO_THREAD_LABEL_HE NULL
#define XEMU_AUDIO_THREAD_INFO_0_HE NULL
#define XEMU_USE_DSP_LABEL_HE NULL
#define XEMU_USE_DSP_INFO_0_HE NULL
#define XEMU_DSP_JIT_LABEL_HE NULL
#define XEMU_DSP_JIT_INFO_0_HE NULL
#define XEMU_HRTF_LABEL_HE NULL
#define XEMU_HRTF_INFO_0_HE NULL
#define XEMU_VP_WORKERS_LABEL_HE NULL
#define XEMU_VP_WORKERS_INFO_0_HE NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_HE NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_HE NULL
#define XEMU_AUDIO_VOLUME_LABEL_HE NULL
#define XEMU_AUDIO_VOLUME_INFO_0_HE NULL
#define OPTION_VAL_100_HE NULL
#define OPTION_VAL_80_HE NULL
#define OPTION_VAL_60_HE NULL
#define OPTION_VAL_40_HE NULL
#define OPTION_VAL_20_HE NULL
#define OPTION_VAL_0_HE NULL
#define XEMU_VK_FAST_PATHS_LABEL_HE NULL
#define XEMU_VK_FAST_PATHS_INFO_0_HE NULL
#define OPTION_VAL_ALL_HE NULL
#define OPTION_VAL_NO_GPL_HE NULL
#define OPTION_VAL_NO_DYN_HE NULL
#define OPTION_VAL_NONE_HE NULL
#define XEMU_RUMBLE_P1_LABEL_HE NULL
#define XEMU_RUMBLE_P1_INFO_0_HE NULL
#define XEMU_RUMBLE_P2_LABEL_HE NULL
#define XEMU_RUMBLE_P2_INFO_0_HE NULL
#define XEMU_DEADZONE_P1_LABEL_HE NULL
#define XEMU_DEADZONE_P1_INFO_0_HE NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_HE NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_HE NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_HE NULL
#define OPTION_VAL_15_HE NULL
#define OPTION_VAL_25_HE NULL
#define OPTION_VAL_30_HE NULL
#define XEMU_DEADZONE_P2_LABEL_HE NULL
#define XEMU_DEADZONE_P2_INFO_0_HE NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_HE NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_HE NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_HE NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_HE NULL
#define OPTION_VAL_MOUSE_HE NULL
#define OPTION_VAL_STICK_HE NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_HE NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_HE NULL
#define XEMU_CHIHIRO_FFB_LABEL_HE NULL
#define XEMU_CHIHIRO_FFB_INFO_0_HE NULL
#define OPTION_VAL_50_HE NULL
#define OPTION_VAL_75_HE NULL
#define OPTION_VAL_150_HE NULL
#define OPTION_VAL_200_HE NULL

struct retro_core_option_v2_category option_cats_he[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_HE,
        CATEGORY_SYSTEM_INFO_0_HE
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_HE,
        CATEGORY_VIDEO_INFO_0_HE
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_HE,
        CATEGORY_AUDIO_INFO_0_HE
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_HE,
        CATEGORY_CONTROLS_INFO_0_HE
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_HE,
        CATEGORY_CHIHIRO_INFO_0_HE
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_he[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_HE,
        NULL,
        XEMU_MEMORY_INFO_0_HE,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_HE },
            { "128", OPTION_VAL_128_HE },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_HE,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_HE,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_HE },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_HE,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_HE,
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
        XEMU_HARD_FPU_LABEL_HE,
        NULL,
        XEMU_HARD_FPU_INFO_0_HE,
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
        XEMU_CPU_BOOST_LABEL_HE,
        NULL,
        XEMU_CPU_BOOST_INFO_0_HE,
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
        XEMU_HDD_TRIM_LABEL_HE,
        NULL,
        XEMU_HDD_TRIM_INFO_0_HE,
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
        XEMU_RENDERER_LABEL_HE,
        NULL,
        XEMU_RENDERER_INFO_0_HE,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_HE },
            { "opengl", OPTION_VAL_OPENGL_HE },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_HE,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_HE,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_HE },
            { "4:3",       OPTION_VAL_4_3_HE },
            { "16:9",      OPTION_VAL_16_9_HE },
            { "letterbox", OPTION_VAL_LETTERBOX_HE },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_HE,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_HE,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_HE },
            { "4:3",  OPTION_VAL_4_3_HE },
            { "16:9", OPTION_VAL_16_9_HE },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_HE,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_HE,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_HE },
            { "2", OPTION_VAL_2_HE },
            { "3", OPTION_VAL_3_HE },
            { "4", OPTION_VAL_4_HE },
            { "5", OPTION_VAL_5_HE },
            { "6", OPTION_VAL_6_HE },
            { "7", OPTION_VAL_7_HE },
            { "8", OPTION_VAL_8_HE },
            { "9", OPTION_VAL_9_HE },
            { "10", OPTION_VAL_10_HE },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_HE,
        NULL,
        XEMU_AVPACK_INFO_0_HE,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_HE },
            { "composite", OPTION_VAL_COMPOSITE_HE },
            { "svideo",    OPTION_VAL_SVIDEO_HE },
            { "scart",     OPTION_VAL_SCART_HE },
            { "vga",       OPTION_VAL_VGA_HE },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_HE,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_HE,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_HE,
        NULL,
        XEMU_USE_DSP_INFO_0_HE,
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
        XEMU_DSP_JIT_LABEL_HE,
        NULL,
        XEMU_DSP_JIT_INFO_0_HE,
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
        XEMU_HRTF_LABEL_HE,
        NULL,
        XEMU_HRTF_INFO_0_HE,
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
        XEMU_VP_WORKERS_LABEL_HE,
        NULL,
        XEMU_VP_WORKERS_INFO_0_HE,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_HE },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_HE,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_HE,
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
        XEMU_AUDIO_VOLUME_LABEL_HE,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_HE,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_HE },
            { "80",  OPTION_VAL_80_HE },
            { "60",  OPTION_VAL_60_HE },
            { "40",  OPTION_VAL_40_HE },
            { "20",  OPTION_VAL_20_HE },
            { "0",   OPTION_VAL_0_HE },
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
        XEMU_VK_FAST_PATHS_LABEL_HE,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_HE,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_HE },
            { "no_gpl",   OPTION_VAL_NO_GPL_HE },
            { "no_dyn",   OPTION_VAL_NO_DYN_HE },
            { "none",     OPTION_VAL_NONE_HE },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_HE,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_HE,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_HE,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_HE,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_HE,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_HE,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_HE },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_HE },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_HE },
            { "15", OPTION_VAL_15_HE },
            { "20", OPTION_VAL_20_HE },
            { "25", OPTION_VAL_25_HE },
            { "30", OPTION_VAL_30_HE },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_HE,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_HE,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_HE },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_HE },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_HE },
            { "15", OPTION_VAL_15_HE },
            { "20", OPTION_VAL_20_HE },
            { "25", OPTION_VAL_25_HE },
            { "30", OPTION_VAL_30_HE },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_HE,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_HE,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_HE,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_HE,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_HE },
            { "stick", OPTION_VAL_STICK_HE },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_HE,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_HE,
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
        XEMU_CHIHIRO_FFB_LABEL_HE,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_HE,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_HE },
            { "50",  OPTION_VAL_50_HE },
            { "75",  OPTION_VAL_75_HE },
            { "100", OPTION_VAL_100_HE },
            { "150", OPTION_VAL_150_HE },
            { "200", OPTION_VAL_200_HE },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_he = {
   option_cats_he,
   option_defs_he
};

/* RETRO_LANGUAGE_HR */

#define CATEGORY_SYSTEM_LABEL_HR NULL
#define CATEGORY_SYSTEM_INFO_0_HR NULL
#define CATEGORY_VIDEO_LABEL_HR NULL
#define CATEGORY_VIDEO_INFO_0_HR NULL
#define CATEGORY_AUDIO_LABEL_HR "Zvuk"
#define CATEGORY_AUDIO_INFO_0_HR NULL
#define CATEGORY_CONTROLS_LABEL_HR NULL
#define CATEGORY_CONTROLS_INFO_0_HR NULL
#define CATEGORY_CHIHIRO_LABEL_HR NULL
#define CATEGORY_CHIHIRO_INFO_0_HR NULL
#define XEMU_MEMORY_LABEL_HR NULL
#define XEMU_MEMORY_INFO_0_HR NULL
#define OPTION_VAL_64_HR NULL
#define OPTION_VAL_128_HR NULL
#define XEMU_NETWORK_BACKEND_LABEL_HR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_HR NULL
#define OPTION_VAL_NAT_HR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_HR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_HR NULL
#define XEMU_HARD_FPU_LABEL_HR NULL
#define XEMU_HARD_FPU_INFO_0_HR NULL
#define XEMU_CPU_BOOST_LABEL_HR NULL
#define XEMU_CPU_BOOST_INFO_0_HR NULL
#define XEMU_HDD_TRIM_LABEL_HR NULL
#define XEMU_HDD_TRIM_INFO_0_HR NULL
#define XEMU_RENDERER_LABEL_HR NULL
#define XEMU_RENDERER_INFO_0_HR NULL
#define OPTION_VAL_VULKAN_HR NULL
#define OPTION_VAL_OPENGL_HR NULL
#define XEMU_VIDEO_ASPECT_LABEL_HR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_HR NULL
#define OPTION_VAL_DASHBOARD_HR NULL
#define OPTION_VAL_4_3_HR NULL
#define OPTION_VAL_16_9_HR NULL
#define OPTION_VAL_LETTERBOX_HR NULL
#define XEMU_ASPECT_RATIO_LABEL_HR NULL
#define XEMU_ASPECT_RATIO_INFO_0_HR NULL
#define OPTION_VAL_AUTO_HR NULL
#define XEMU_SURFACE_SCALE_LABEL_HR NULL
#define XEMU_SURFACE_SCALE_INFO_0_HR NULL
#define OPTION_VAL_1_HR NULL
#define OPTION_VAL_2_HR NULL
#define OPTION_VAL_3_HR NULL
#define OPTION_VAL_4_HR NULL
#define OPTION_VAL_5_HR NULL
#define OPTION_VAL_6_HR NULL
#define OPTION_VAL_7_HR NULL
#define OPTION_VAL_8_HR NULL
#define OPTION_VAL_9_HR NULL
#define OPTION_VAL_10_HR NULL
#define XEMU_AVPACK_LABEL_HR NULL
#define XEMU_AVPACK_INFO_0_HR NULL
#define OPTION_VAL_HDTV_HR NULL
#define OPTION_VAL_COMPOSITE_HR "Kompozitni"
#define OPTION_VAL_SVIDEO_HR NULL
#define OPTION_VAL_SCART_HR NULL
#define OPTION_VAL_VGA_HR NULL
#define XEMU_AUDIO_THREAD_LABEL_HR NULL
#define XEMU_AUDIO_THREAD_INFO_0_HR NULL
#define XEMU_USE_DSP_LABEL_HR NULL
#define XEMU_USE_DSP_INFO_0_HR NULL
#define XEMU_DSP_JIT_LABEL_HR NULL
#define XEMU_DSP_JIT_INFO_0_HR NULL
#define XEMU_HRTF_LABEL_HR NULL
#define XEMU_HRTF_INFO_0_HR NULL
#define XEMU_VP_WORKERS_LABEL_HR NULL
#define XEMU_VP_WORKERS_INFO_0_HR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_HR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_HR NULL
#define XEMU_AUDIO_VOLUME_LABEL_HR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_HR NULL
#define OPTION_VAL_100_HR NULL
#define OPTION_VAL_80_HR NULL
#define OPTION_VAL_60_HR NULL
#define OPTION_VAL_40_HR NULL
#define OPTION_VAL_20_HR NULL
#define OPTION_VAL_0_HR NULL
#define XEMU_VK_FAST_PATHS_LABEL_HR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_HR NULL
#define OPTION_VAL_ALL_HR NULL
#define OPTION_VAL_NO_GPL_HR NULL
#define OPTION_VAL_NO_DYN_HR NULL
#define OPTION_VAL_NONE_HR "Ništa"
#define XEMU_RUMBLE_P1_LABEL_HR NULL
#define XEMU_RUMBLE_P1_INFO_0_HR NULL
#define XEMU_RUMBLE_P2_LABEL_HR NULL
#define XEMU_RUMBLE_P2_INFO_0_HR NULL
#define XEMU_DEADZONE_P1_LABEL_HR NULL
#define XEMU_DEADZONE_P1_INFO_0_HR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_HR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_HR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_HR NULL
#define OPTION_VAL_15_HR NULL
#define OPTION_VAL_25_HR NULL
#define OPTION_VAL_30_HR NULL
#define XEMU_DEADZONE_P2_LABEL_HR NULL
#define XEMU_DEADZONE_P2_INFO_0_HR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_HR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_HR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_HR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_HR NULL
#define OPTION_VAL_MOUSE_HR "Miš"
#define OPTION_VAL_STICK_HR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_HR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_HR NULL
#define XEMU_CHIHIRO_FFB_LABEL_HR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_HR NULL
#define OPTION_VAL_50_HR NULL
#define OPTION_VAL_75_HR NULL
#define OPTION_VAL_150_HR NULL
#define OPTION_VAL_200_HR NULL

struct retro_core_option_v2_category option_cats_hr[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_HR,
        CATEGORY_SYSTEM_INFO_0_HR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_HR,
        CATEGORY_VIDEO_INFO_0_HR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_HR,
        CATEGORY_AUDIO_INFO_0_HR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_HR,
        CATEGORY_CONTROLS_INFO_0_HR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_HR,
        CATEGORY_CHIHIRO_INFO_0_HR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_hr[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_HR,
        NULL,
        XEMU_MEMORY_INFO_0_HR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_HR },
            { "128", OPTION_VAL_128_HR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_HR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_HR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_HR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_HR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_HR,
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
        XEMU_HARD_FPU_LABEL_HR,
        NULL,
        XEMU_HARD_FPU_INFO_0_HR,
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
        XEMU_CPU_BOOST_LABEL_HR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_HR,
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
        XEMU_HDD_TRIM_LABEL_HR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_HR,
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
        XEMU_RENDERER_LABEL_HR,
        NULL,
        XEMU_RENDERER_INFO_0_HR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_HR },
            { "opengl", OPTION_VAL_OPENGL_HR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_HR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_HR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_HR },
            { "4:3",       OPTION_VAL_4_3_HR },
            { "16:9",      OPTION_VAL_16_9_HR },
            { "letterbox", OPTION_VAL_LETTERBOX_HR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_HR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_HR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_HR },
            { "4:3",  OPTION_VAL_4_3_HR },
            { "16:9", OPTION_VAL_16_9_HR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_HR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_HR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_HR },
            { "2", OPTION_VAL_2_HR },
            { "3", OPTION_VAL_3_HR },
            { "4", OPTION_VAL_4_HR },
            { "5", OPTION_VAL_5_HR },
            { "6", OPTION_VAL_6_HR },
            { "7", OPTION_VAL_7_HR },
            { "8", OPTION_VAL_8_HR },
            { "9", OPTION_VAL_9_HR },
            { "10", OPTION_VAL_10_HR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_HR,
        NULL,
        XEMU_AVPACK_INFO_0_HR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_HR },
            { "composite", OPTION_VAL_COMPOSITE_HR },
            { "svideo",    OPTION_VAL_SVIDEO_HR },
            { "scart",     OPTION_VAL_SCART_HR },
            { "vga",       OPTION_VAL_VGA_HR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_HR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_HR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_HR,
        NULL,
        XEMU_USE_DSP_INFO_0_HR,
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
        XEMU_DSP_JIT_LABEL_HR,
        NULL,
        XEMU_DSP_JIT_INFO_0_HR,
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
        XEMU_HRTF_LABEL_HR,
        NULL,
        XEMU_HRTF_INFO_0_HR,
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
        XEMU_VP_WORKERS_LABEL_HR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_HR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_HR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_HR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_HR,
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
        XEMU_AUDIO_VOLUME_LABEL_HR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_HR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_HR },
            { "80",  OPTION_VAL_80_HR },
            { "60",  OPTION_VAL_60_HR },
            { "40",  OPTION_VAL_40_HR },
            { "20",  OPTION_VAL_20_HR },
            { "0",   OPTION_VAL_0_HR },
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
        XEMU_VK_FAST_PATHS_LABEL_HR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_HR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_HR },
            { "no_gpl",   OPTION_VAL_NO_GPL_HR },
            { "no_dyn",   OPTION_VAL_NO_DYN_HR },
            { "none",     OPTION_VAL_NONE_HR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_HR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_HR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_HR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_HR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_HR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_HR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_HR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_HR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_HR },
            { "15", OPTION_VAL_15_HR },
            { "20", OPTION_VAL_20_HR },
            { "25", OPTION_VAL_25_HR },
            { "30", OPTION_VAL_30_HR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_HR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_HR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_HR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_HR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_HR },
            { "15", OPTION_VAL_15_HR },
            { "20", OPTION_VAL_20_HR },
            { "25", OPTION_VAL_25_HR },
            { "30", OPTION_VAL_30_HR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_HR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_HR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_HR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_HR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_HR },
            { "stick", OPTION_VAL_STICK_HR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_HR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_HR,
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
        XEMU_CHIHIRO_FFB_LABEL_HR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_HR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_HR },
            { "50",  OPTION_VAL_50_HR },
            { "75",  OPTION_VAL_75_HR },
            { "100", OPTION_VAL_100_HR },
            { "150", OPTION_VAL_150_HR },
            { "200", OPTION_VAL_200_HR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_hr = {
   option_cats_hr,
   option_defs_hr
};

/* RETRO_LANGUAGE_HU */

#define CATEGORY_SYSTEM_LABEL_HU NULL
#define CATEGORY_SYSTEM_INFO_0_HU NULL
#define CATEGORY_VIDEO_LABEL_HU "Kép"
#define CATEGORY_VIDEO_INFO_0_HU NULL
#define CATEGORY_AUDIO_LABEL_HU "Hang"
#define CATEGORY_AUDIO_INFO_0_HU NULL
#define CATEGORY_CONTROLS_LABEL_HU "Irányítás"
#define CATEGORY_CONTROLS_INFO_0_HU NULL
#define CATEGORY_CHIHIRO_LABEL_HU NULL
#define CATEGORY_CHIHIRO_INFO_0_HU NULL
#define XEMU_MEMORY_LABEL_HU NULL
#define XEMU_MEMORY_INFO_0_HU NULL
#define OPTION_VAL_64_HU NULL
#define OPTION_VAL_128_HU NULL
#define XEMU_NETWORK_BACKEND_LABEL_HU NULL
#define XEMU_NETWORK_BACKEND_INFO_0_HU NULL
#define OPTION_VAL_NAT_HU NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_HU NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_HU NULL
#define XEMU_HARD_FPU_LABEL_HU NULL
#define XEMU_HARD_FPU_INFO_0_HU NULL
#define XEMU_CPU_BOOST_LABEL_HU NULL
#define XEMU_CPU_BOOST_INFO_0_HU NULL
#define XEMU_HDD_TRIM_LABEL_HU NULL
#define XEMU_HDD_TRIM_INFO_0_HU NULL
#define XEMU_RENDERER_LABEL_HU NULL
#define XEMU_RENDERER_INFO_0_HU NULL
#define OPTION_VAL_VULKAN_HU NULL
#define OPTION_VAL_OPENGL_HU NULL
#define XEMU_VIDEO_ASPECT_LABEL_HU NULL
#define XEMU_VIDEO_ASPECT_INFO_0_HU NULL
#define OPTION_VAL_DASHBOARD_HU NULL
#define OPTION_VAL_4_3_HU NULL
#define OPTION_VAL_16_9_HU NULL
#define OPTION_VAL_LETTERBOX_HU NULL
#define XEMU_ASPECT_RATIO_LABEL_HU "A mag képaránya"
#define XEMU_ASPECT_RATIO_INFO_0_HU NULL
#define OPTION_VAL_AUTO_HU "Automatikus"
#define XEMU_SURFACE_SCALE_LABEL_HU NULL
#define XEMU_SURFACE_SCALE_INFO_0_HU NULL
#define OPTION_VAL_1_HU NULL
#define OPTION_VAL_2_HU NULL
#define OPTION_VAL_3_HU NULL
#define OPTION_VAL_4_HU NULL
#define OPTION_VAL_5_HU NULL
#define OPTION_VAL_6_HU NULL
#define OPTION_VAL_7_HU NULL
#define OPTION_VAL_8_HU NULL
#define OPTION_VAL_9_HU NULL
#define OPTION_VAL_10_HU NULL
#define XEMU_AVPACK_LABEL_HU NULL
#define XEMU_AVPACK_INFO_0_HU NULL
#define OPTION_VAL_HDTV_HU NULL
#define OPTION_VAL_COMPOSITE_HU "Kompozit"
#define OPTION_VAL_SVIDEO_HU NULL
#define OPTION_VAL_SCART_HU NULL
#define OPTION_VAL_VGA_HU NULL
#define XEMU_AUDIO_THREAD_LABEL_HU NULL
#define XEMU_AUDIO_THREAD_INFO_0_HU NULL
#define XEMU_USE_DSP_LABEL_HU NULL
#define XEMU_USE_DSP_INFO_0_HU NULL
#define XEMU_DSP_JIT_LABEL_HU NULL
#define XEMU_DSP_JIT_INFO_0_HU NULL
#define XEMU_HRTF_LABEL_HU NULL
#define XEMU_HRTF_INFO_0_HU NULL
#define XEMU_VP_WORKERS_LABEL_HU NULL
#define XEMU_VP_WORKERS_INFO_0_HU NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_HU NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_HU NULL
#define XEMU_AUDIO_VOLUME_LABEL_HU NULL
#define XEMU_AUDIO_VOLUME_INFO_0_HU NULL
#define OPTION_VAL_100_HU NULL
#define OPTION_VAL_80_HU NULL
#define OPTION_VAL_60_HU NULL
#define OPTION_VAL_40_HU NULL
#define OPTION_VAL_20_HU NULL
#define OPTION_VAL_0_HU NULL
#define XEMU_VK_FAST_PATHS_LABEL_HU NULL
#define XEMU_VK_FAST_PATHS_INFO_0_HU NULL
#define OPTION_VAL_ALL_HU "Összes"
#define OPTION_VAL_NO_GPL_HU NULL
#define OPTION_VAL_NO_DYN_HU NULL
#define OPTION_VAL_NONE_HU "Nincs"
#define XEMU_RUMBLE_P1_LABEL_HU NULL
#define XEMU_RUMBLE_P1_INFO_0_HU NULL
#define XEMU_RUMBLE_P2_LABEL_HU NULL
#define XEMU_RUMBLE_P2_INFO_0_HU NULL
#define XEMU_DEADZONE_P1_LABEL_HU NULL
#define XEMU_DEADZONE_P1_INFO_0_HU NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_HU NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_HU NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_HU NULL
#define OPTION_VAL_15_HU NULL
#define OPTION_VAL_25_HU NULL
#define OPTION_VAL_30_HU NULL
#define XEMU_DEADZONE_P2_LABEL_HU NULL
#define XEMU_DEADZONE_P2_INFO_0_HU NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_HU NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_HU NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_HU NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_HU NULL
#define OPTION_VAL_MOUSE_HU "Egér"
#define OPTION_VAL_STICK_HU NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_HU NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_HU NULL
#define XEMU_CHIHIRO_FFB_LABEL_HU NULL
#define XEMU_CHIHIRO_FFB_INFO_0_HU NULL
#define OPTION_VAL_50_HU NULL
#define OPTION_VAL_75_HU NULL
#define OPTION_VAL_150_HU NULL
#define OPTION_VAL_200_HU NULL

struct retro_core_option_v2_category option_cats_hu[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_HU,
        CATEGORY_SYSTEM_INFO_0_HU
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_HU,
        CATEGORY_VIDEO_INFO_0_HU
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_HU,
        CATEGORY_AUDIO_INFO_0_HU
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_HU,
        CATEGORY_CONTROLS_INFO_0_HU
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_HU,
        CATEGORY_CHIHIRO_INFO_0_HU
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_hu[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_HU,
        NULL,
        XEMU_MEMORY_INFO_0_HU,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_HU },
            { "128", OPTION_VAL_128_HU },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_HU,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_HU,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_HU },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_HU,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_HU,
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
        XEMU_HARD_FPU_LABEL_HU,
        NULL,
        XEMU_HARD_FPU_INFO_0_HU,
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
        XEMU_CPU_BOOST_LABEL_HU,
        NULL,
        XEMU_CPU_BOOST_INFO_0_HU,
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
        XEMU_HDD_TRIM_LABEL_HU,
        NULL,
        XEMU_HDD_TRIM_INFO_0_HU,
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
        XEMU_RENDERER_LABEL_HU,
        NULL,
        XEMU_RENDERER_INFO_0_HU,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_HU },
            { "opengl", OPTION_VAL_OPENGL_HU },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_HU,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_HU,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_HU },
            { "4:3",       OPTION_VAL_4_3_HU },
            { "16:9",      OPTION_VAL_16_9_HU },
            { "letterbox", OPTION_VAL_LETTERBOX_HU },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_HU,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_HU,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_HU },
            { "4:3",  OPTION_VAL_4_3_HU },
            { "16:9", OPTION_VAL_16_9_HU },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_HU,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_HU,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_HU },
            { "2", OPTION_VAL_2_HU },
            { "3", OPTION_VAL_3_HU },
            { "4", OPTION_VAL_4_HU },
            { "5", OPTION_VAL_5_HU },
            { "6", OPTION_VAL_6_HU },
            { "7", OPTION_VAL_7_HU },
            { "8", OPTION_VAL_8_HU },
            { "9", OPTION_VAL_9_HU },
            { "10", OPTION_VAL_10_HU },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_HU,
        NULL,
        XEMU_AVPACK_INFO_0_HU,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_HU },
            { "composite", OPTION_VAL_COMPOSITE_HU },
            { "svideo",    OPTION_VAL_SVIDEO_HU },
            { "scart",     OPTION_VAL_SCART_HU },
            { "vga",       OPTION_VAL_VGA_HU },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_HU,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_HU,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_HU,
        NULL,
        XEMU_USE_DSP_INFO_0_HU,
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
        XEMU_DSP_JIT_LABEL_HU,
        NULL,
        XEMU_DSP_JIT_INFO_0_HU,
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
        XEMU_HRTF_LABEL_HU,
        NULL,
        XEMU_HRTF_INFO_0_HU,
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
        XEMU_VP_WORKERS_LABEL_HU,
        NULL,
        XEMU_VP_WORKERS_INFO_0_HU,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_HU },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_HU,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_HU,
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
        XEMU_AUDIO_VOLUME_LABEL_HU,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_HU,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_HU },
            { "80",  OPTION_VAL_80_HU },
            { "60",  OPTION_VAL_60_HU },
            { "40",  OPTION_VAL_40_HU },
            { "20",  OPTION_VAL_20_HU },
            { "0",   OPTION_VAL_0_HU },
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
        XEMU_VK_FAST_PATHS_LABEL_HU,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_HU,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_HU },
            { "no_gpl",   OPTION_VAL_NO_GPL_HU },
            { "no_dyn",   OPTION_VAL_NO_DYN_HU },
            { "none",     OPTION_VAL_NONE_HU },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_HU,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_HU,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_HU,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_HU,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_HU,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_HU,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_HU },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_HU },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_HU },
            { "15", OPTION_VAL_15_HU },
            { "20", OPTION_VAL_20_HU },
            { "25", OPTION_VAL_25_HU },
            { "30", OPTION_VAL_30_HU },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_HU,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_HU,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_HU },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_HU },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_HU },
            { "15", OPTION_VAL_15_HU },
            { "20", OPTION_VAL_20_HU },
            { "25", OPTION_VAL_25_HU },
            { "30", OPTION_VAL_30_HU },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_HU,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_HU,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_HU,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_HU,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_HU },
            { "stick", OPTION_VAL_STICK_HU },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_HU,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_HU,
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
        XEMU_CHIHIRO_FFB_LABEL_HU,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_HU,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_HU },
            { "50",  OPTION_VAL_50_HU },
            { "75",  OPTION_VAL_75_HU },
            { "100", OPTION_VAL_100_HU },
            { "150", OPTION_VAL_150_HU },
            { "200", OPTION_VAL_200_HU },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_hu = {
   option_cats_hu,
   option_defs_hu
};

/* RETRO_LANGUAGE_ID */

#define CATEGORY_SYSTEM_LABEL_ID NULL
#define CATEGORY_SYSTEM_INFO_0_ID NULL
#define CATEGORY_VIDEO_LABEL_ID NULL
#define CATEGORY_VIDEO_INFO_0_ID NULL
#define CATEGORY_AUDIO_LABEL_ID "Suara"
#define CATEGORY_AUDIO_INFO_0_ID NULL
#define CATEGORY_CONTROLS_LABEL_ID "Tombol Kendali"
#define CATEGORY_CONTROLS_INFO_0_ID NULL
#define CATEGORY_CHIHIRO_LABEL_ID NULL
#define CATEGORY_CHIHIRO_INFO_0_ID NULL
#define XEMU_MEMORY_LABEL_ID NULL
#define XEMU_MEMORY_INFO_0_ID NULL
#define OPTION_VAL_64_ID NULL
#define OPTION_VAL_128_ID NULL
#define XEMU_NETWORK_BACKEND_LABEL_ID NULL
#define XEMU_NETWORK_BACKEND_INFO_0_ID NULL
#define OPTION_VAL_NAT_ID NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_ID NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_ID NULL
#define XEMU_HARD_FPU_LABEL_ID NULL
#define XEMU_HARD_FPU_INFO_0_ID NULL
#define XEMU_CPU_BOOST_LABEL_ID NULL
#define XEMU_CPU_BOOST_INFO_0_ID NULL
#define XEMU_HDD_TRIM_LABEL_ID NULL
#define XEMU_HDD_TRIM_INFO_0_ID NULL
#define XEMU_RENDERER_LABEL_ID NULL
#define XEMU_RENDERER_INFO_0_ID NULL
#define OPTION_VAL_VULKAN_ID NULL
#define OPTION_VAL_OPENGL_ID NULL
#define XEMU_VIDEO_ASPECT_LABEL_ID NULL
#define XEMU_VIDEO_ASPECT_INFO_0_ID NULL
#define OPTION_VAL_DASHBOARD_ID NULL
#define OPTION_VAL_4_3_ID NULL
#define OPTION_VAL_16_9_ID NULL
#define OPTION_VAL_LETTERBOX_ID NULL
#define XEMU_ASPECT_RATIO_LABEL_ID NULL
#define XEMU_ASPECT_RATIO_INFO_0_ID NULL
#define OPTION_VAL_AUTO_ID "Otomatis"
#define XEMU_SURFACE_SCALE_LABEL_ID NULL
#define XEMU_SURFACE_SCALE_INFO_0_ID NULL
#define OPTION_VAL_1_ID NULL
#define OPTION_VAL_2_ID NULL
#define OPTION_VAL_3_ID NULL
#define OPTION_VAL_4_ID NULL
#define OPTION_VAL_5_ID NULL
#define OPTION_VAL_6_ID NULL
#define OPTION_VAL_7_ID NULL
#define OPTION_VAL_8_ID NULL
#define OPTION_VAL_9_ID NULL
#define OPTION_VAL_10_ID NULL
#define XEMU_AVPACK_LABEL_ID NULL
#define XEMU_AVPACK_INFO_0_ID NULL
#define OPTION_VAL_HDTV_ID NULL
#define OPTION_VAL_COMPOSITE_ID NULL
#define OPTION_VAL_SVIDEO_ID NULL
#define OPTION_VAL_SCART_ID NULL
#define OPTION_VAL_VGA_ID NULL
#define XEMU_AUDIO_THREAD_LABEL_ID NULL
#define XEMU_AUDIO_THREAD_INFO_0_ID NULL
#define XEMU_USE_DSP_LABEL_ID NULL
#define XEMU_USE_DSP_INFO_0_ID NULL
#define XEMU_DSP_JIT_LABEL_ID NULL
#define XEMU_DSP_JIT_INFO_0_ID NULL
#define XEMU_HRTF_LABEL_ID NULL
#define XEMU_HRTF_INFO_0_ID NULL
#define XEMU_VP_WORKERS_LABEL_ID NULL
#define XEMU_VP_WORKERS_INFO_0_ID NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_ID NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_ID NULL
#define XEMU_AUDIO_VOLUME_LABEL_ID NULL
#define XEMU_AUDIO_VOLUME_INFO_0_ID NULL
#define OPTION_VAL_100_ID NULL
#define OPTION_VAL_80_ID NULL
#define OPTION_VAL_60_ID NULL
#define OPTION_VAL_40_ID NULL
#define OPTION_VAL_20_ID NULL
#define OPTION_VAL_0_ID NULL
#define XEMU_VK_FAST_PATHS_LABEL_ID NULL
#define XEMU_VK_FAST_PATHS_INFO_0_ID NULL
#define OPTION_VAL_ALL_ID NULL
#define OPTION_VAL_NO_GPL_ID NULL
#define OPTION_VAL_NO_DYN_ID NULL
#define OPTION_VAL_NONE_ID "Tak ada"
#define XEMU_RUMBLE_P1_LABEL_ID NULL
#define XEMU_RUMBLE_P1_INFO_0_ID NULL
#define XEMU_RUMBLE_P2_LABEL_ID NULL
#define XEMU_RUMBLE_P2_INFO_0_ID NULL
#define XEMU_DEADZONE_P1_LABEL_ID NULL
#define XEMU_DEADZONE_P1_INFO_0_ID NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_ID NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_ID NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_ID NULL
#define OPTION_VAL_15_ID NULL
#define OPTION_VAL_25_ID NULL
#define OPTION_VAL_30_ID NULL
#define XEMU_DEADZONE_P2_LABEL_ID NULL
#define XEMU_DEADZONE_P2_INFO_0_ID NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_ID NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_ID NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_ID NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_ID NULL
#define OPTION_VAL_MOUSE_ID NULL
#define OPTION_VAL_STICK_ID NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_ID NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_ID NULL
#define XEMU_CHIHIRO_FFB_LABEL_ID NULL
#define XEMU_CHIHIRO_FFB_INFO_0_ID NULL
#define OPTION_VAL_50_ID NULL
#define OPTION_VAL_75_ID NULL
#define OPTION_VAL_150_ID NULL
#define OPTION_VAL_200_ID NULL

struct retro_core_option_v2_category option_cats_id[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_ID,
        CATEGORY_SYSTEM_INFO_0_ID
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_ID,
        CATEGORY_VIDEO_INFO_0_ID
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_ID,
        CATEGORY_AUDIO_INFO_0_ID
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_ID,
        CATEGORY_CONTROLS_INFO_0_ID
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_ID,
        CATEGORY_CHIHIRO_INFO_0_ID
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_id[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_ID,
        NULL,
        XEMU_MEMORY_INFO_0_ID,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_ID },
            { "128", OPTION_VAL_128_ID },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_ID,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_ID,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_ID },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_ID,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_ID,
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
        XEMU_HARD_FPU_LABEL_ID,
        NULL,
        XEMU_HARD_FPU_INFO_0_ID,
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
        XEMU_CPU_BOOST_LABEL_ID,
        NULL,
        XEMU_CPU_BOOST_INFO_0_ID,
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
        XEMU_HDD_TRIM_LABEL_ID,
        NULL,
        XEMU_HDD_TRIM_INFO_0_ID,
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
        XEMU_RENDERER_LABEL_ID,
        NULL,
        XEMU_RENDERER_INFO_0_ID,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_ID },
            { "opengl", OPTION_VAL_OPENGL_ID },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_ID,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_ID,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_ID },
            { "4:3",       OPTION_VAL_4_3_ID },
            { "16:9",      OPTION_VAL_16_9_ID },
            { "letterbox", OPTION_VAL_LETTERBOX_ID },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_ID,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_ID,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_ID },
            { "4:3",  OPTION_VAL_4_3_ID },
            { "16:9", OPTION_VAL_16_9_ID },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_ID,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_ID,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_ID },
            { "2", OPTION_VAL_2_ID },
            { "3", OPTION_VAL_3_ID },
            { "4", OPTION_VAL_4_ID },
            { "5", OPTION_VAL_5_ID },
            { "6", OPTION_VAL_6_ID },
            { "7", OPTION_VAL_7_ID },
            { "8", OPTION_VAL_8_ID },
            { "9", OPTION_VAL_9_ID },
            { "10", OPTION_VAL_10_ID },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_ID,
        NULL,
        XEMU_AVPACK_INFO_0_ID,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_ID },
            { "composite", OPTION_VAL_COMPOSITE_ID },
            { "svideo",    OPTION_VAL_SVIDEO_ID },
            { "scart",     OPTION_VAL_SCART_ID },
            { "vga",       OPTION_VAL_VGA_ID },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_ID,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_ID,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_ID,
        NULL,
        XEMU_USE_DSP_INFO_0_ID,
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
        XEMU_DSP_JIT_LABEL_ID,
        NULL,
        XEMU_DSP_JIT_INFO_0_ID,
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
        XEMU_HRTF_LABEL_ID,
        NULL,
        XEMU_HRTF_INFO_0_ID,
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
        XEMU_VP_WORKERS_LABEL_ID,
        NULL,
        XEMU_VP_WORKERS_INFO_0_ID,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_ID },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_ID,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_ID,
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
        XEMU_AUDIO_VOLUME_LABEL_ID,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_ID,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_ID },
            { "80",  OPTION_VAL_80_ID },
            { "60",  OPTION_VAL_60_ID },
            { "40",  OPTION_VAL_40_ID },
            { "20",  OPTION_VAL_20_ID },
            { "0",   OPTION_VAL_0_ID },
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
        XEMU_VK_FAST_PATHS_LABEL_ID,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_ID,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_ID },
            { "no_gpl",   OPTION_VAL_NO_GPL_ID },
            { "no_dyn",   OPTION_VAL_NO_DYN_ID },
            { "none",     OPTION_VAL_NONE_ID },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_ID,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_ID,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_ID,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_ID,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_ID,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_ID,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_ID },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_ID },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_ID },
            { "15", OPTION_VAL_15_ID },
            { "20", OPTION_VAL_20_ID },
            { "25", OPTION_VAL_25_ID },
            { "30", OPTION_VAL_30_ID },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_ID,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_ID,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_ID },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_ID },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_ID },
            { "15", OPTION_VAL_15_ID },
            { "20", OPTION_VAL_20_ID },
            { "25", OPTION_VAL_25_ID },
            { "30", OPTION_VAL_30_ID },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_ID,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_ID,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_ID,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_ID,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_ID },
            { "stick", OPTION_VAL_STICK_ID },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_ID,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_ID,
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
        XEMU_CHIHIRO_FFB_LABEL_ID,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_ID,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_ID },
            { "50",  OPTION_VAL_50_ID },
            { "75",  OPTION_VAL_75_ID },
            { "100", OPTION_VAL_100_ID },
            { "150", OPTION_VAL_150_ID },
            { "200", OPTION_VAL_200_ID },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_id = {
   option_cats_id,
   option_defs_id
};

/* RETRO_LANGUAGE_IT */

#define CATEGORY_SYSTEM_LABEL_IT NULL
#define CATEGORY_SYSTEM_INFO_0_IT NULL
#define CATEGORY_VIDEO_LABEL_IT NULL
#define CATEGORY_VIDEO_INFO_0_IT NULL
#define CATEGORY_AUDIO_LABEL_IT NULL
#define CATEGORY_AUDIO_INFO_0_IT NULL
#define CATEGORY_CONTROLS_LABEL_IT "Controlli"
#define CATEGORY_CONTROLS_INFO_0_IT NULL
#define CATEGORY_CHIHIRO_LABEL_IT NULL
#define CATEGORY_CHIHIRO_INFO_0_IT NULL
#define XEMU_MEMORY_LABEL_IT NULL
#define XEMU_MEMORY_INFO_0_IT NULL
#define OPTION_VAL_64_IT NULL
#define OPTION_VAL_128_IT NULL
#define XEMU_NETWORK_BACKEND_LABEL_IT NULL
#define XEMU_NETWORK_BACKEND_INFO_0_IT NULL
#define OPTION_VAL_NAT_IT NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_IT NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_IT NULL
#define XEMU_HARD_FPU_LABEL_IT NULL
#define XEMU_HARD_FPU_INFO_0_IT NULL
#define XEMU_CPU_BOOST_LABEL_IT NULL
#define XEMU_CPU_BOOST_INFO_0_IT NULL
#define XEMU_HDD_TRIM_LABEL_IT NULL
#define XEMU_HDD_TRIM_INFO_0_IT NULL
#define XEMU_RENDERER_LABEL_IT NULL
#define XEMU_RENDERER_INFO_0_IT NULL
#define OPTION_VAL_VULKAN_IT NULL
#define OPTION_VAL_OPENGL_IT NULL
#define XEMU_VIDEO_ASPECT_LABEL_IT NULL
#define XEMU_VIDEO_ASPECT_INFO_0_IT NULL
#define OPTION_VAL_DASHBOARD_IT NULL
#define OPTION_VAL_4_3_IT NULL
#define OPTION_VAL_16_9_IT NULL
#define OPTION_VAL_LETTERBOX_IT NULL
#define XEMU_ASPECT_RATIO_LABEL_IT "Rapporto d'aspetto Core"
#define XEMU_ASPECT_RATIO_INFO_0_IT NULL
#define OPTION_VAL_AUTO_IT NULL
#define XEMU_SURFACE_SCALE_LABEL_IT NULL
#define XEMU_SURFACE_SCALE_INFO_0_IT NULL
#define OPTION_VAL_1_IT NULL
#define OPTION_VAL_2_IT NULL
#define OPTION_VAL_3_IT NULL
#define OPTION_VAL_4_IT NULL
#define OPTION_VAL_5_IT NULL
#define OPTION_VAL_6_IT NULL
#define OPTION_VAL_7_IT NULL
#define OPTION_VAL_8_IT NULL
#define OPTION_VAL_9_IT NULL
#define OPTION_VAL_10_IT NULL
#define XEMU_AVPACK_LABEL_IT NULL
#define XEMU_AVPACK_INFO_0_IT NULL
#define OPTION_VAL_HDTV_IT NULL
#define OPTION_VAL_COMPOSITE_IT "Composito"
#define OPTION_VAL_SVIDEO_IT NULL
#define OPTION_VAL_SCART_IT NULL
#define OPTION_VAL_VGA_IT NULL
#define XEMU_AUDIO_THREAD_LABEL_IT NULL
#define XEMU_AUDIO_THREAD_INFO_0_IT NULL
#define XEMU_USE_DSP_LABEL_IT NULL
#define XEMU_USE_DSP_INFO_0_IT NULL
#define XEMU_DSP_JIT_LABEL_IT NULL
#define XEMU_DSP_JIT_INFO_0_IT NULL
#define XEMU_HRTF_LABEL_IT NULL
#define XEMU_HRTF_INFO_0_IT NULL
#define XEMU_VP_WORKERS_LABEL_IT NULL
#define XEMU_VP_WORKERS_INFO_0_IT NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_IT NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_IT NULL
#define XEMU_AUDIO_VOLUME_LABEL_IT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_IT NULL
#define OPTION_VAL_100_IT NULL
#define OPTION_VAL_80_IT NULL
#define OPTION_VAL_60_IT NULL
#define OPTION_VAL_40_IT NULL
#define OPTION_VAL_20_IT NULL
#define OPTION_VAL_0_IT NULL
#define XEMU_VK_FAST_PATHS_LABEL_IT NULL
#define XEMU_VK_FAST_PATHS_INFO_0_IT NULL
#define OPTION_VAL_ALL_IT "Tutti"
#define OPTION_VAL_NO_GPL_IT NULL
#define OPTION_VAL_NO_DYN_IT NULL
#define OPTION_VAL_NONE_IT "Nessuno"
#define XEMU_RUMBLE_P1_LABEL_IT NULL
#define XEMU_RUMBLE_P1_INFO_0_IT NULL
#define XEMU_RUMBLE_P2_LABEL_IT NULL
#define XEMU_RUMBLE_P2_INFO_0_IT NULL
#define XEMU_DEADZONE_P1_LABEL_IT NULL
#define XEMU_DEADZONE_P1_INFO_0_IT NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_IT NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_IT NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_IT NULL
#define OPTION_VAL_15_IT NULL
#define OPTION_VAL_25_IT NULL
#define OPTION_VAL_30_IT NULL
#define XEMU_DEADZONE_P2_LABEL_IT NULL
#define XEMU_DEADZONE_P2_INFO_0_IT NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_IT NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_IT NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_IT NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_IT NULL
#define OPTION_VAL_MOUSE_IT NULL
#define OPTION_VAL_STICK_IT NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_IT NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_IT NULL
#define XEMU_CHIHIRO_FFB_LABEL_IT NULL
#define XEMU_CHIHIRO_FFB_INFO_0_IT NULL
#define OPTION_VAL_50_IT NULL
#define OPTION_VAL_75_IT NULL
#define OPTION_VAL_150_IT NULL
#define OPTION_VAL_200_IT NULL

struct retro_core_option_v2_category option_cats_it[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_IT,
        CATEGORY_SYSTEM_INFO_0_IT
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_IT,
        CATEGORY_VIDEO_INFO_0_IT
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_IT,
        CATEGORY_AUDIO_INFO_0_IT
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_IT,
        CATEGORY_CONTROLS_INFO_0_IT
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_IT,
        CATEGORY_CHIHIRO_INFO_0_IT
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_it[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_IT,
        NULL,
        XEMU_MEMORY_INFO_0_IT,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_IT },
            { "128", OPTION_VAL_128_IT },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_IT,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_IT,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_IT },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_IT,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_IT,
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
        XEMU_HARD_FPU_LABEL_IT,
        NULL,
        XEMU_HARD_FPU_INFO_0_IT,
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
        XEMU_CPU_BOOST_LABEL_IT,
        NULL,
        XEMU_CPU_BOOST_INFO_0_IT,
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
        XEMU_HDD_TRIM_LABEL_IT,
        NULL,
        XEMU_HDD_TRIM_INFO_0_IT,
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
        XEMU_RENDERER_LABEL_IT,
        NULL,
        XEMU_RENDERER_INFO_0_IT,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_IT },
            { "opengl", OPTION_VAL_OPENGL_IT },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_IT,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_IT,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_IT },
            { "4:3",       OPTION_VAL_4_3_IT },
            { "16:9",      OPTION_VAL_16_9_IT },
            { "letterbox", OPTION_VAL_LETTERBOX_IT },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_IT,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_IT,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_IT },
            { "4:3",  OPTION_VAL_4_3_IT },
            { "16:9", OPTION_VAL_16_9_IT },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_IT,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_IT,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_IT },
            { "2", OPTION_VAL_2_IT },
            { "3", OPTION_VAL_3_IT },
            { "4", OPTION_VAL_4_IT },
            { "5", OPTION_VAL_5_IT },
            { "6", OPTION_VAL_6_IT },
            { "7", OPTION_VAL_7_IT },
            { "8", OPTION_VAL_8_IT },
            { "9", OPTION_VAL_9_IT },
            { "10", OPTION_VAL_10_IT },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_IT,
        NULL,
        XEMU_AVPACK_INFO_0_IT,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_IT },
            { "composite", OPTION_VAL_COMPOSITE_IT },
            { "svideo",    OPTION_VAL_SVIDEO_IT },
            { "scart",     OPTION_VAL_SCART_IT },
            { "vga",       OPTION_VAL_VGA_IT },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_IT,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_IT,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_IT,
        NULL,
        XEMU_USE_DSP_INFO_0_IT,
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
        XEMU_DSP_JIT_LABEL_IT,
        NULL,
        XEMU_DSP_JIT_INFO_0_IT,
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
        XEMU_HRTF_LABEL_IT,
        NULL,
        XEMU_HRTF_INFO_0_IT,
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
        XEMU_VP_WORKERS_LABEL_IT,
        NULL,
        XEMU_VP_WORKERS_INFO_0_IT,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_IT },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_IT,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_IT,
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
        XEMU_AUDIO_VOLUME_LABEL_IT,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_IT,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_IT },
            { "80",  OPTION_VAL_80_IT },
            { "60",  OPTION_VAL_60_IT },
            { "40",  OPTION_VAL_40_IT },
            { "20",  OPTION_VAL_20_IT },
            { "0",   OPTION_VAL_0_IT },
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
        XEMU_VK_FAST_PATHS_LABEL_IT,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_IT,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_IT },
            { "no_gpl",   OPTION_VAL_NO_GPL_IT },
            { "no_dyn",   OPTION_VAL_NO_DYN_IT },
            { "none",     OPTION_VAL_NONE_IT },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_IT,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_IT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_IT,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_IT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_IT,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_IT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_IT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_IT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_IT },
            { "15", OPTION_VAL_15_IT },
            { "20", OPTION_VAL_20_IT },
            { "25", OPTION_VAL_25_IT },
            { "30", OPTION_VAL_30_IT },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_IT,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_IT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_IT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_IT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_IT },
            { "15", OPTION_VAL_15_IT },
            { "20", OPTION_VAL_20_IT },
            { "25", OPTION_VAL_25_IT },
            { "30", OPTION_VAL_30_IT },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_IT,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_IT,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_IT,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_IT,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_IT },
            { "stick", OPTION_VAL_STICK_IT },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_IT,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_IT,
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
        XEMU_CHIHIRO_FFB_LABEL_IT,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_IT,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_IT },
            { "50",  OPTION_VAL_50_IT },
            { "75",  OPTION_VAL_75_IT },
            { "100", OPTION_VAL_100_IT },
            { "150", OPTION_VAL_150_IT },
            { "200", OPTION_VAL_200_IT },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_it = {
   option_cats_it,
   option_defs_it
};

/* RETRO_LANGUAGE_JA */

#define CATEGORY_SYSTEM_LABEL_JA NULL
#define CATEGORY_SYSTEM_INFO_0_JA NULL
#define CATEGORY_VIDEO_LABEL_JA "ビデオ"
#define CATEGORY_VIDEO_INFO_0_JA NULL
#define CATEGORY_AUDIO_LABEL_JA "オーディオ"
#define CATEGORY_AUDIO_INFO_0_JA NULL
#define CATEGORY_CONTROLS_LABEL_JA "コントロール"
#define CATEGORY_CONTROLS_INFO_0_JA NULL
#define CATEGORY_CHIHIRO_LABEL_JA NULL
#define CATEGORY_CHIHIRO_INFO_0_JA NULL
#define XEMU_MEMORY_LABEL_JA NULL
#define XEMU_MEMORY_INFO_0_JA NULL
#define OPTION_VAL_64_JA NULL
#define OPTION_VAL_128_JA NULL
#define XEMU_NETWORK_BACKEND_LABEL_JA NULL
#define XEMU_NETWORK_BACKEND_INFO_0_JA NULL
#define OPTION_VAL_NAT_JA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_JA NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_JA NULL
#define XEMU_HARD_FPU_LABEL_JA NULL
#define XEMU_HARD_FPU_INFO_0_JA NULL
#define XEMU_CPU_BOOST_LABEL_JA NULL
#define XEMU_CPU_BOOST_INFO_0_JA NULL
#define XEMU_HDD_TRIM_LABEL_JA NULL
#define XEMU_HDD_TRIM_INFO_0_JA NULL
#define XEMU_RENDERER_LABEL_JA NULL
#define XEMU_RENDERER_INFO_0_JA NULL
#define OPTION_VAL_VULKAN_JA NULL
#define OPTION_VAL_OPENGL_JA NULL
#define XEMU_VIDEO_ASPECT_LABEL_JA NULL
#define XEMU_VIDEO_ASPECT_INFO_0_JA NULL
#define OPTION_VAL_DASHBOARD_JA NULL
#define OPTION_VAL_4_3_JA NULL
#define OPTION_VAL_16_9_JA NULL
#define OPTION_VAL_LETTERBOX_JA NULL
#define XEMU_ASPECT_RATIO_LABEL_JA "コアアスペクト比"
#define XEMU_ASPECT_RATIO_INFO_0_JA NULL
#define OPTION_VAL_AUTO_JA "自動"
#define XEMU_SURFACE_SCALE_LABEL_JA NULL
#define XEMU_SURFACE_SCALE_INFO_0_JA NULL
#define OPTION_VAL_1_JA NULL
#define OPTION_VAL_2_JA NULL
#define OPTION_VAL_3_JA NULL
#define OPTION_VAL_4_JA NULL
#define OPTION_VAL_5_JA NULL
#define OPTION_VAL_6_JA NULL
#define OPTION_VAL_7_JA NULL
#define OPTION_VAL_8_JA NULL
#define OPTION_VAL_9_JA NULL
#define OPTION_VAL_10_JA NULL
#define XEMU_AVPACK_LABEL_JA NULL
#define XEMU_AVPACK_INFO_0_JA NULL
#define OPTION_VAL_HDTV_JA NULL
#define OPTION_VAL_COMPOSITE_JA "コンポジット"
#define OPTION_VAL_SVIDEO_JA "S端子"
#define OPTION_VAL_SCART_JA NULL
#define OPTION_VAL_VGA_JA NULL
#define XEMU_AUDIO_THREAD_LABEL_JA NULL
#define XEMU_AUDIO_THREAD_INFO_0_JA NULL
#define XEMU_USE_DSP_LABEL_JA NULL
#define XEMU_USE_DSP_INFO_0_JA NULL
#define XEMU_DSP_JIT_LABEL_JA NULL
#define XEMU_DSP_JIT_INFO_0_JA NULL
#define XEMU_HRTF_LABEL_JA NULL
#define XEMU_HRTF_INFO_0_JA NULL
#define XEMU_VP_WORKERS_LABEL_JA NULL
#define XEMU_VP_WORKERS_INFO_0_JA NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_JA NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_JA NULL
#define XEMU_AUDIO_VOLUME_LABEL_JA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_JA NULL
#define OPTION_VAL_100_JA NULL
#define OPTION_VAL_80_JA NULL
#define OPTION_VAL_60_JA NULL
#define OPTION_VAL_40_JA NULL
#define OPTION_VAL_20_JA NULL
#define OPTION_VAL_0_JA NULL
#define XEMU_VK_FAST_PATHS_LABEL_JA NULL
#define XEMU_VK_FAST_PATHS_INFO_0_JA NULL
#define OPTION_VAL_ALL_JA "すべて"
#define OPTION_VAL_NO_GPL_JA NULL
#define OPTION_VAL_NO_DYN_JA NULL
#define OPTION_VAL_NONE_JA "なし"
#define XEMU_RUMBLE_P1_LABEL_JA NULL
#define XEMU_RUMBLE_P1_INFO_0_JA NULL
#define XEMU_RUMBLE_P2_LABEL_JA NULL
#define XEMU_RUMBLE_P2_INFO_0_JA NULL
#define XEMU_DEADZONE_P1_LABEL_JA NULL
#define XEMU_DEADZONE_P1_INFO_0_JA NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_JA NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_JA NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_JA NULL
#define OPTION_VAL_15_JA NULL
#define OPTION_VAL_25_JA NULL
#define OPTION_VAL_30_JA NULL
#define XEMU_DEADZONE_P2_LABEL_JA NULL
#define XEMU_DEADZONE_P2_INFO_0_JA NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_JA NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_JA NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_JA NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_JA NULL
#define OPTION_VAL_MOUSE_JA "マウス"
#define OPTION_VAL_STICK_JA NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_JA NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_JA NULL
#define XEMU_CHIHIRO_FFB_LABEL_JA NULL
#define XEMU_CHIHIRO_FFB_INFO_0_JA NULL
#define OPTION_VAL_50_JA NULL
#define OPTION_VAL_75_JA NULL
#define OPTION_VAL_150_JA NULL
#define OPTION_VAL_200_JA NULL

struct retro_core_option_v2_category option_cats_ja[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_JA,
        CATEGORY_SYSTEM_INFO_0_JA
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_JA,
        CATEGORY_VIDEO_INFO_0_JA
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_JA,
        CATEGORY_AUDIO_INFO_0_JA
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_JA,
        CATEGORY_CONTROLS_INFO_0_JA
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_JA,
        CATEGORY_CHIHIRO_INFO_0_JA
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ja[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_JA,
        NULL,
        XEMU_MEMORY_INFO_0_JA,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_JA },
            { "128", OPTION_VAL_128_JA },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_JA,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_JA,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_JA },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_JA,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_JA,
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
        XEMU_HARD_FPU_LABEL_JA,
        NULL,
        XEMU_HARD_FPU_INFO_0_JA,
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
        XEMU_CPU_BOOST_LABEL_JA,
        NULL,
        XEMU_CPU_BOOST_INFO_0_JA,
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
        XEMU_HDD_TRIM_LABEL_JA,
        NULL,
        XEMU_HDD_TRIM_INFO_0_JA,
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
        XEMU_RENDERER_LABEL_JA,
        NULL,
        XEMU_RENDERER_INFO_0_JA,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_JA },
            { "opengl", OPTION_VAL_OPENGL_JA },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_JA,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_JA,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_JA },
            { "4:3",       OPTION_VAL_4_3_JA },
            { "16:9",      OPTION_VAL_16_9_JA },
            { "letterbox", OPTION_VAL_LETTERBOX_JA },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_JA,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_JA,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_JA },
            { "4:3",  OPTION_VAL_4_3_JA },
            { "16:9", OPTION_VAL_16_9_JA },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_JA,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_JA,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_JA },
            { "2", OPTION_VAL_2_JA },
            { "3", OPTION_VAL_3_JA },
            { "4", OPTION_VAL_4_JA },
            { "5", OPTION_VAL_5_JA },
            { "6", OPTION_VAL_6_JA },
            { "7", OPTION_VAL_7_JA },
            { "8", OPTION_VAL_8_JA },
            { "9", OPTION_VAL_9_JA },
            { "10", OPTION_VAL_10_JA },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_JA,
        NULL,
        XEMU_AVPACK_INFO_0_JA,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_JA },
            { "composite", OPTION_VAL_COMPOSITE_JA },
            { "svideo",    OPTION_VAL_SVIDEO_JA },
            { "scart",     OPTION_VAL_SCART_JA },
            { "vga",       OPTION_VAL_VGA_JA },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_JA,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_JA,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_JA,
        NULL,
        XEMU_USE_DSP_INFO_0_JA,
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
        XEMU_DSP_JIT_LABEL_JA,
        NULL,
        XEMU_DSP_JIT_INFO_0_JA,
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
        XEMU_HRTF_LABEL_JA,
        NULL,
        XEMU_HRTF_INFO_0_JA,
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
        XEMU_VP_WORKERS_LABEL_JA,
        NULL,
        XEMU_VP_WORKERS_INFO_0_JA,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_JA },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_JA,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_JA,
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
        XEMU_AUDIO_VOLUME_LABEL_JA,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_JA,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_JA },
            { "80",  OPTION_VAL_80_JA },
            { "60",  OPTION_VAL_60_JA },
            { "40",  OPTION_VAL_40_JA },
            { "20",  OPTION_VAL_20_JA },
            { "0",   OPTION_VAL_0_JA },
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
        XEMU_VK_FAST_PATHS_LABEL_JA,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_JA,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_JA },
            { "no_gpl",   OPTION_VAL_NO_GPL_JA },
            { "no_dyn",   OPTION_VAL_NO_DYN_JA },
            { "none",     OPTION_VAL_NONE_JA },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_JA,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_JA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_JA,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_JA,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_JA,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_JA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_JA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_JA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_JA },
            { "15", OPTION_VAL_15_JA },
            { "20", OPTION_VAL_20_JA },
            { "25", OPTION_VAL_25_JA },
            { "30", OPTION_VAL_30_JA },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_JA,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_JA,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_JA },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_JA },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_JA },
            { "15", OPTION_VAL_15_JA },
            { "20", OPTION_VAL_20_JA },
            { "25", OPTION_VAL_25_JA },
            { "30", OPTION_VAL_30_JA },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_JA,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_JA,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_JA,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_JA,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_JA },
            { "stick", OPTION_VAL_STICK_JA },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_JA,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_JA,
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
        XEMU_CHIHIRO_FFB_LABEL_JA,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_JA,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_JA },
            { "50",  OPTION_VAL_50_JA },
            { "75",  OPTION_VAL_75_JA },
            { "100", OPTION_VAL_100_JA },
            { "150", OPTION_VAL_150_JA },
            { "200", OPTION_VAL_200_JA },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ja = {
   option_cats_ja,
   option_defs_ja
};

/* RETRO_LANGUAGE_KO */

#define CATEGORY_SYSTEM_LABEL_KO NULL
#define CATEGORY_SYSTEM_INFO_0_KO NULL
#define CATEGORY_VIDEO_LABEL_KO "비디오"
#define CATEGORY_VIDEO_INFO_0_KO NULL
#define CATEGORY_AUDIO_LABEL_KO "오디오"
#define CATEGORY_AUDIO_INFO_0_KO NULL
#define CATEGORY_CONTROLS_LABEL_KO "컨트롤"
#define CATEGORY_CONTROLS_INFO_0_KO NULL
#define CATEGORY_CHIHIRO_LABEL_KO NULL
#define CATEGORY_CHIHIRO_INFO_0_KO NULL
#define XEMU_MEMORY_LABEL_KO NULL
#define XEMU_MEMORY_INFO_0_KO NULL
#define OPTION_VAL_64_KO NULL
#define OPTION_VAL_128_KO NULL
#define XEMU_NETWORK_BACKEND_LABEL_KO NULL
#define XEMU_NETWORK_BACKEND_INFO_0_KO NULL
#define OPTION_VAL_NAT_KO NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_KO NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_KO NULL
#define XEMU_HARD_FPU_LABEL_KO NULL
#define XEMU_HARD_FPU_INFO_0_KO NULL
#define XEMU_CPU_BOOST_LABEL_KO NULL
#define XEMU_CPU_BOOST_INFO_0_KO NULL
#define XEMU_HDD_TRIM_LABEL_KO NULL
#define XEMU_HDD_TRIM_INFO_0_KO NULL
#define XEMU_RENDERER_LABEL_KO NULL
#define XEMU_RENDERER_INFO_0_KO NULL
#define OPTION_VAL_VULKAN_KO NULL
#define OPTION_VAL_OPENGL_KO NULL
#define XEMU_VIDEO_ASPECT_LABEL_KO NULL
#define XEMU_VIDEO_ASPECT_INFO_0_KO NULL
#define OPTION_VAL_DASHBOARD_KO NULL
#define OPTION_VAL_4_3_KO NULL
#define OPTION_VAL_16_9_KO NULL
#define OPTION_VAL_LETTERBOX_KO NULL
#define XEMU_ASPECT_RATIO_LABEL_KO "코어 화면비"
#define XEMU_ASPECT_RATIO_INFO_0_KO NULL
#define OPTION_VAL_AUTO_KO "자동"
#define XEMU_SURFACE_SCALE_LABEL_KO NULL
#define XEMU_SURFACE_SCALE_INFO_0_KO NULL
#define OPTION_VAL_1_KO NULL
#define OPTION_VAL_2_KO NULL
#define OPTION_VAL_3_KO NULL
#define OPTION_VAL_4_KO NULL
#define OPTION_VAL_5_KO NULL
#define OPTION_VAL_6_KO NULL
#define OPTION_VAL_7_KO NULL
#define OPTION_VAL_8_KO NULL
#define OPTION_VAL_9_KO NULL
#define OPTION_VAL_10_KO NULL
#define XEMU_AVPACK_LABEL_KO NULL
#define XEMU_AVPACK_INFO_0_KO NULL
#define OPTION_VAL_HDTV_KO NULL
#define OPTION_VAL_COMPOSITE_KO "컴포지트"
#define OPTION_VAL_SVIDEO_KO "S-비디오"
#define OPTION_VAL_SCART_KO NULL
#define OPTION_VAL_VGA_KO NULL
#define XEMU_AUDIO_THREAD_LABEL_KO NULL
#define XEMU_AUDIO_THREAD_INFO_0_KO NULL
#define XEMU_USE_DSP_LABEL_KO NULL
#define XEMU_USE_DSP_INFO_0_KO NULL
#define XEMU_DSP_JIT_LABEL_KO NULL
#define XEMU_DSP_JIT_INFO_0_KO NULL
#define XEMU_HRTF_LABEL_KO NULL
#define XEMU_HRTF_INFO_0_KO NULL
#define XEMU_VP_WORKERS_LABEL_KO NULL
#define XEMU_VP_WORKERS_INFO_0_KO NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_KO NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_KO NULL
#define XEMU_AUDIO_VOLUME_LABEL_KO NULL
#define XEMU_AUDIO_VOLUME_INFO_0_KO NULL
#define OPTION_VAL_100_KO NULL
#define OPTION_VAL_80_KO NULL
#define OPTION_VAL_60_KO NULL
#define OPTION_VAL_40_KO NULL
#define OPTION_VAL_20_KO NULL
#define OPTION_VAL_0_KO NULL
#define XEMU_VK_FAST_PATHS_LABEL_KO NULL
#define XEMU_VK_FAST_PATHS_INFO_0_KO NULL
#define OPTION_VAL_ALL_KO "전체"
#define OPTION_VAL_NO_GPL_KO NULL
#define OPTION_VAL_NO_DYN_KO NULL
#define OPTION_VAL_NONE_KO "없음"
#define XEMU_RUMBLE_P1_LABEL_KO NULL
#define XEMU_RUMBLE_P1_INFO_0_KO NULL
#define XEMU_RUMBLE_P2_LABEL_KO NULL
#define XEMU_RUMBLE_P2_INFO_0_KO NULL
#define XEMU_DEADZONE_P1_LABEL_KO NULL
#define XEMU_DEADZONE_P1_INFO_0_KO NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_KO NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_KO NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_KO NULL
#define OPTION_VAL_15_KO NULL
#define OPTION_VAL_25_KO NULL
#define OPTION_VAL_30_KO NULL
#define XEMU_DEADZONE_P2_LABEL_KO NULL
#define XEMU_DEADZONE_P2_INFO_0_KO NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_KO NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_KO NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_KO NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_KO NULL
#define OPTION_VAL_MOUSE_KO "마우스"
#define OPTION_VAL_STICK_KO NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_KO NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_KO NULL
#define XEMU_CHIHIRO_FFB_LABEL_KO NULL
#define XEMU_CHIHIRO_FFB_INFO_0_KO NULL
#define OPTION_VAL_50_KO NULL
#define OPTION_VAL_75_KO NULL
#define OPTION_VAL_150_KO NULL
#define OPTION_VAL_200_KO NULL

struct retro_core_option_v2_category option_cats_ko[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_KO,
        CATEGORY_SYSTEM_INFO_0_KO
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_KO,
        CATEGORY_VIDEO_INFO_0_KO
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_KO,
        CATEGORY_AUDIO_INFO_0_KO
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_KO,
        CATEGORY_CONTROLS_INFO_0_KO
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_KO,
        CATEGORY_CHIHIRO_INFO_0_KO
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ko[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_KO,
        NULL,
        XEMU_MEMORY_INFO_0_KO,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_KO },
            { "128", OPTION_VAL_128_KO },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_KO,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_KO,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_KO },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_KO,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_KO,
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
        XEMU_HARD_FPU_LABEL_KO,
        NULL,
        XEMU_HARD_FPU_INFO_0_KO,
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
        XEMU_CPU_BOOST_LABEL_KO,
        NULL,
        XEMU_CPU_BOOST_INFO_0_KO,
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
        XEMU_HDD_TRIM_LABEL_KO,
        NULL,
        XEMU_HDD_TRIM_INFO_0_KO,
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
        XEMU_RENDERER_LABEL_KO,
        NULL,
        XEMU_RENDERER_INFO_0_KO,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_KO },
            { "opengl", OPTION_VAL_OPENGL_KO },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_KO,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_KO,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_KO },
            { "4:3",       OPTION_VAL_4_3_KO },
            { "16:9",      OPTION_VAL_16_9_KO },
            { "letterbox", OPTION_VAL_LETTERBOX_KO },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_KO,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_KO,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_KO },
            { "4:3",  OPTION_VAL_4_3_KO },
            { "16:9", OPTION_VAL_16_9_KO },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_KO,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_KO,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_KO },
            { "2", OPTION_VAL_2_KO },
            { "3", OPTION_VAL_3_KO },
            { "4", OPTION_VAL_4_KO },
            { "5", OPTION_VAL_5_KO },
            { "6", OPTION_VAL_6_KO },
            { "7", OPTION_VAL_7_KO },
            { "8", OPTION_VAL_8_KO },
            { "9", OPTION_VAL_9_KO },
            { "10", OPTION_VAL_10_KO },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_KO,
        NULL,
        XEMU_AVPACK_INFO_0_KO,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_KO },
            { "composite", OPTION_VAL_COMPOSITE_KO },
            { "svideo",    OPTION_VAL_SVIDEO_KO },
            { "scart",     OPTION_VAL_SCART_KO },
            { "vga",       OPTION_VAL_VGA_KO },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_KO,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_KO,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_KO,
        NULL,
        XEMU_USE_DSP_INFO_0_KO,
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
        XEMU_DSP_JIT_LABEL_KO,
        NULL,
        XEMU_DSP_JIT_INFO_0_KO,
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
        XEMU_HRTF_LABEL_KO,
        NULL,
        XEMU_HRTF_INFO_0_KO,
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
        XEMU_VP_WORKERS_LABEL_KO,
        NULL,
        XEMU_VP_WORKERS_INFO_0_KO,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_KO },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_KO,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_KO,
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
        XEMU_AUDIO_VOLUME_LABEL_KO,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_KO,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_KO },
            { "80",  OPTION_VAL_80_KO },
            { "60",  OPTION_VAL_60_KO },
            { "40",  OPTION_VAL_40_KO },
            { "20",  OPTION_VAL_20_KO },
            { "0",   OPTION_VAL_0_KO },
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
        XEMU_VK_FAST_PATHS_LABEL_KO,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_KO,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_KO },
            { "no_gpl",   OPTION_VAL_NO_GPL_KO },
            { "no_dyn",   OPTION_VAL_NO_DYN_KO },
            { "none",     OPTION_VAL_NONE_KO },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_KO,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_KO,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_KO,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_KO,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_KO,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_KO,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_KO },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_KO },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_KO },
            { "15", OPTION_VAL_15_KO },
            { "20", OPTION_VAL_20_KO },
            { "25", OPTION_VAL_25_KO },
            { "30", OPTION_VAL_30_KO },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_KO,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_KO,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_KO },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_KO },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_KO },
            { "15", OPTION_VAL_15_KO },
            { "20", OPTION_VAL_20_KO },
            { "25", OPTION_VAL_25_KO },
            { "30", OPTION_VAL_30_KO },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_KO,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_KO,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_KO,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_KO,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_KO },
            { "stick", OPTION_VAL_STICK_KO },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_KO,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_KO,
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
        XEMU_CHIHIRO_FFB_LABEL_KO,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_KO,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_KO },
            { "50",  OPTION_VAL_50_KO },
            { "75",  OPTION_VAL_75_KO },
            { "100", OPTION_VAL_100_KO },
            { "150", OPTION_VAL_150_KO },
            { "200", OPTION_VAL_200_KO },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ko = {
   option_cats_ko,
   option_defs_ko
};

/* RETRO_LANGUAGE_NL */

#define CATEGORY_SYSTEM_LABEL_NL NULL
#define CATEGORY_SYSTEM_INFO_0_NL NULL
#define CATEGORY_VIDEO_LABEL_NL NULL
#define CATEGORY_VIDEO_INFO_0_NL NULL
#define CATEGORY_AUDIO_LABEL_NL "Geluid"
#define CATEGORY_AUDIO_INFO_0_NL NULL
#define CATEGORY_CONTROLS_LABEL_NL "Besturingselementen"
#define CATEGORY_CONTROLS_INFO_0_NL NULL
#define CATEGORY_CHIHIRO_LABEL_NL NULL
#define CATEGORY_CHIHIRO_INFO_0_NL NULL
#define XEMU_MEMORY_LABEL_NL NULL
#define XEMU_MEMORY_INFO_0_NL NULL
#define OPTION_VAL_64_NL NULL
#define OPTION_VAL_128_NL NULL
#define XEMU_NETWORK_BACKEND_LABEL_NL NULL
#define XEMU_NETWORK_BACKEND_INFO_0_NL NULL
#define OPTION_VAL_NAT_NL NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_NL NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_NL NULL
#define XEMU_HARD_FPU_LABEL_NL NULL
#define XEMU_HARD_FPU_INFO_0_NL NULL
#define XEMU_CPU_BOOST_LABEL_NL NULL
#define XEMU_CPU_BOOST_INFO_0_NL NULL
#define XEMU_HDD_TRIM_LABEL_NL NULL
#define XEMU_HDD_TRIM_INFO_0_NL NULL
#define XEMU_RENDERER_LABEL_NL NULL
#define XEMU_RENDERER_INFO_0_NL NULL
#define OPTION_VAL_VULKAN_NL NULL
#define OPTION_VAL_OPENGL_NL NULL
#define XEMU_VIDEO_ASPECT_LABEL_NL NULL
#define XEMU_VIDEO_ASPECT_INFO_0_NL NULL
#define OPTION_VAL_DASHBOARD_NL NULL
#define OPTION_VAL_4_3_NL NULL
#define OPTION_VAL_16_9_NL NULL
#define OPTION_VAL_LETTERBOX_NL NULL
#define XEMU_ASPECT_RATIO_LABEL_NL NULL
#define XEMU_ASPECT_RATIO_INFO_0_NL NULL
#define OPTION_VAL_AUTO_NL "Automatisch"
#define XEMU_SURFACE_SCALE_LABEL_NL NULL
#define XEMU_SURFACE_SCALE_INFO_0_NL NULL
#define OPTION_VAL_1_NL NULL
#define OPTION_VAL_2_NL NULL
#define OPTION_VAL_3_NL NULL
#define OPTION_VAL_4_NL NULL
#define OPTION_VAL_5_NL NULL
#define OPTION_VAL_6_NL NULL
#define OPTION_VAL_7_NL NULL
#define OPTION_VAL_8_NL NULL
#define OPTION_VAL_9_NL NULL
#define OPTION_VAL_10_NL NULL
#define XEMU_AVPACK_LABEL_NL NULL
#define XEMU_AVPACK_INFO_0_NL NULL
#define OPTION_VAL_HDTV_NL NULL
#define OPTION_VAL_COMPOSITE_NL NULL
#define OPTION_VAL_SVIDEO_NL NULL
#define OPTION_VAL_SCART_NL NULL
#define OPTION_VAL_VGA_NL NULL
#define XEMU_AUDIO_THREAD_LABEL_NL NULL
#define XEMU_AUDIO_THREAD_INFO_0_NL NULL
#define XEMU_USE_DSP_LABEL_NL NULL
#define XEMU_USE_DSP_INFO_0_NL NULL
#define XEMU_DSP_JIT_LABEL_NL NULL
#define XEMU_DSP_JIT_INFO_0_NL NULL
#define XEMU_HRTF_LABEL_NL NULL
#define XEMU_HRTF_INFO_0_NL NULL
#define XEMU_VP_WORKERS_LABEL_NL NULL
#define XEMU_VP_WORKERS_INFO_0_NL NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_NL NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_NL NULL
#define XEMU_AUDIO_VOLUME_LABEL_NL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_NL NULL
#define OPTION_VAL_100_NL NULL
#define OPTION_VAL_80_NL NULL
#define OPTION_VAL_60_NL NULL
#define OPTION_VAL_40_NL NULL
#define OPTION_VAL_20_NL NULL
#define OPTION_VAL_0_NL NULL
#define XEMU_VK_FAST_PATHS_LABEL_NL NULL
#define XEMU_VK_FAST_PATHS_INFO_0_NL NULL
#define OPTION_VAL_ALL_NL "Alle"
#define OPTION_VAL_NO_GPL_NL NULL
#define OPTION_VAL_NO_DYN_NL NULL
#define OPTION_VAL_NONE_NL "Geen"
#define XEMU_RUMBLE_P1_LABEL_NL NULL
#define XEMU_RUMBLE_P1_INFO_0_NL NULL
#define XEMU_RUMBLE_P2_LABEL_NL NULL
#define XEMU_RUMBLE_P2_INFO_0_NL NULL
#define XEMU_DEADZONE_P1_LABEL_NL NULL
#define XEMU_DEADZONE_P1_INFO_0_NL NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_NL NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_NL NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_NL NULL
#define OPTION_VAL_15_NL NULL
#define OPTION_VAL_25_NL NULL
#define OPTION_VAL_30_NL NULL
#define XEMU_DEADZONE_P2_LABEL_NL NULL
#define XEMU_DEADZONE_P2_INFO_0_NL NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_NL NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_NL NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_NL NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_NL NULL
#define OPTION_VAL_MOUSE_NL NULL
#define OPTION_VAL_STICK_NL NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_NL NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_NL NULL
#define XEMU_CHIHIRO_FFB_LABEL_NL NULL
#define XEMU_CHIHIRO_FFB_INFO_0_NL NULL
#define OPTION_VAL_50_NL NULL
#define OPTION_VAL_75_NL NULL
#define OPTION_VAL_150_NL NULL
#define OPTION_VAL_200_NL NULL

struct retro_core_option_v2_category option_cats_nl[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_NL,
        CATEGORY_SYSTEM_INFO_0_NL
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_NL,
        CATEGORY_VIDEO_INFO_0_NL
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_NL,
        CATEGORY_AUDIO_INFO_0_NL
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_NL,
        CATEGORY_CONTROLS_INFO_0_NL
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_NL,
        CATEGORY_CHIHIRO_INFO_0_NL
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_nl[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_NL,
        NULL,
        XEMU_MEMORY_INFO_0_NL,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_NL },
            { "128", OPTION_VAL_128_NL },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_NL,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_NL,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_NL },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_NL,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_NL,
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
        XEMU_HARD_FPU_LABEL_NL,
        NULL,
        XEMU_HARD_FPU_INFO_0_NL,
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
        XEMU_CPU_BOOST_LABEL_NL,
        NULL,
        XEMU_CPU_BOOST_INFO_0_NL,
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
        XEMU_HDD_TRIM_LABEL_NL,
        NULL,
        XEMU_HDD_TRIM_INFO_0_NL,
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
        XEMU_RENDERER_LABEL_NL,
        NULL,
        XEMU_RENDERER_INFO_0_NL,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_NL },
            { "opengl", OPTION_VAL_OPENGL_NL },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_NL,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_NL,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_NL },
            { "4:3",       OPTION_VAL_4_3_NL },
            { "16:9",      OPTION_VAL_16_9_NL },
            { "letterbox", OPTION_VAL_LETTERBOX_NL },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_NL,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_NL,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_NL },
            { "4:3",  OPTION_VAL_4_3_NL },
            { "16:9", OPTION_VAL_16_9_NL },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_NL,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_NL,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_NL },
            { "2", OPTION_VAL_2_NL },
            { "3", OPTION_VAL_3_NL },
            { "4", OPTION_VAL_4_NL },
            { "5", OPTION_VAL_5_NL },
            { "6", OPTION_VAL_6_NL },
            { "7", OPTION_VAL_7_NL },
            { "8", OPTION_VAL_8_NL },
            { "9", OPTION_VAL_9_NL },
            { "10", OPTION_VAL_10_NL },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_NL,
        NULL,
        XEMU_AVPACK_INFO_0_NL,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_NL },
            { "composite", OPTION_VAL_COMPOSITE_NL },
            { "svideo",    OPTION_VAL_SVIDEO_NL },
            { "scart",     OPTION_VAL_SCART_NL },
            { "vga",       OPTION_VAL_VGA_NL },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_NL,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_NL,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_NL,
        NULL,
        XEMU_USE_DSP_INFO_0_NL,
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
        XEMU_DSP_JIT_LABEL_NL,
        NULL,
        XEMU_DSP_JIT_INFO_0_NL,
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
        XEMU_HRTF_LABEL_NL,
        NULL,
        XEMU_HRTF_INFO_0_NL,
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
        XEMU_VP_WORKERS_LABEL_NL,
        NULL,
        XEMU_VP_WORKERS_INFO_0_NL,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_NL },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_NL,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_NL,
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
        XEMU_AUDIO_VOLUME_LABEL_NL,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_NL,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_NL },
            { "80",  OPTION_VAL_80_NL },
            { "60",  OPTION_VAL_60_NL },
            { "40",  OPTION_VAL_40_NL },
            { "20",  OPTION_VAL_20_NL },
            { "0",   OPTION_VAL_0_NL },
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
        XEMU_VK_FAST_PATHS_LABEL_NL,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_NL,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_NL },
            { "no_gpl",   OPTION_VAL_NO_GPL_NL },
            { "no_dyn",   OPTION_VAL_NO_DYN_NL },
            { "none",     OPTION_VAL_NONE_NL },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_NL,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_NL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_NL,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_NL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_NL,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_NL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_NL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_NL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_NL },
            { "15", OPTION_VAL_15_NL },
            { "20", OPTION_VAL_20_NL },
            { "25", OPTION_VAL_25_NL },
            { "30", OPTION_VAL_30_NL },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_NL,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_NL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_NL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_NL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_NL },
            { "15", OPTION_VAL_15_NL },
            { "20", OPTION_VAL_20_NL },
            { "25", OPTION_VAL_25_NL },
            { "30", OPTION_VAL_30_NL },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_NL,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_NL,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_NL,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_NL,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_NL },
            { "stick", OPTION_VAL_STICK_NL },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_NL,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_NL,
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
        XEMU_CHIHIRO_FFB_LABEL_NL,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_NL,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_NL },
            { "50",  OPTION_VAL_50_NL },
            { "75",  OPTION_VAL_75_NL },
            { "100", OPTION_VAL_100_NL },
            { "150", OPTION_VAL_150_NL },
            { "200", OPTION_VAL_200_NL },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_nl = {
   option_cats_nl,
   option_defs_nl
};

/* RETRO_LANGUAGE_NO */

#define CATEGORY_SYSTEM_LABEL_NO NULL
#define CATEGORY_SYSTEM_INFO_0_NO NULL
#define CATEGORY_VIDEO_LABEL_NO NULL
#define CATEGORY_VIDEO_INFO_0_NO NULL
#define CATEGORY_AUDIO_LABEL_NO "Lyd"
#define CATEGORY_AUDIO_INFO_0_NO NULL
#define CATEGORY_CONTROLS_LABEL_NO NULL
#define CATEGORY_CONTROLS_INFO_0_NO NULL
#define CATEGORY_CHIHIRO_LABEL_NO NULL
#define CATEGORY_CHIHIRO_INFO_0_NO NULL
#define XEMU_MEMORY_LABEL_NO NULL
#define XEMU_MEMORY_INFO_0_NO NULL
#define OPTION_VAL_64_NO NULL
#define OPTION_VAL_128_NO NULL
#define XEMU_NETWORK_BACKEND_LABEL_NO NULL
#define XEMU_NETWORK_BACKEND_INFO_0_NO NULL
#define OPTION_VAL_NAT_NO NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_NO NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_NO NULL
#define XEMU_HARD_FPU_LABEL_NO NULL
#define XEMU_HARD_FPU_INFO_0_NO NULL
#define XEMU_CPU_BOOST_LABEL_NO NULL
#define XEMU_CPU_BOOST_INFO_0_NO NULL
#define XEMU_HDD_TRIM_LABEL_NO NULL
#define XEMU_HDD_TRIM_INFO_0_NO NULL
#define XEMU_RENDERER_LABEL_NO NULL
#define XEMU_RENDERER_INFO_0_NO NULL
#define OPTION_VAL_VULKAN_NO NULL
#define OPTION_VAL_OPENGL_NO NULL
#define XEMU_VIDEO_ASPECT_LABEL_NO NULL
#define XEMU_VIDEO_ASPECT_INFO_0_NO NULL
#define OPTION_VAL_DASHBOARD_NO NULL
#define OPTION_VAL_4_3_NO NULL
#define OPTION_VAL_16_9_NO NULL
#define OPTION_VAL_LETTERBOX_NO NULL
#define XEMU_ASPECT_RATIO_LABEL_NO NULL
#define XEMU_ASPECT_RATIO_INFO_0_NO NULL
#define OPTION_VAL_AUTO_NO NULL
#define XEMU_SURFACE_SCALE_LABEL_NO NULL
#define XEMU_SURFACE_SCALE_INFO_0_NO NULL
#define OPTION_VAL_1_NO NULL
#define OPTION_VAL_2_NO NULL
#define OPTION_VAL_3_NO NULL
#define OPTION_VAL_4_NO NULL
#define OPTION_VAL_5_NO NULL
#define OPTION_VAL_6_NO NULL
#define OPTION_VAL_7_NO NULL
#define OPTION_VAL_8_NO NULL
#define OPTION_VAL_9_NO NULL
#define OPTION_VAL_10_NO NULL
#define XEMU_AVPACK_LABEL_NO NULL
#define XEMU_AVPACK_INFO_0_NO NULL
#define OPTION_VAL_HDTV_NO NULL
#define OPTION_VAL_COMPOSITE_NO NULL
#define OPTION_VAL_SVIDEO_NO NULL
#define OPTION_VAL_SCART_NO NULL
#define OPTION_VAL_VGA_NO NULL
#define XEMU_AUDIO_THREAD_LABEL_NO NULL
#define XEMU_AUDIO_THREAD_INFO_0_NO NULL
#define XEMU_USE_DSP_LABEL_NO NULL
#define XEMU_USE_DSP_INFO_0_NO NULL
#define XEMU_DSP_JIT_LABEL_NO NULL
#define XEMU_DSP_JIT_INFO_0_NO NULL
#define XEMU_HRTF_LABEL_NO NULL
#define XEMU_HRTF_INFO_0_NO NULL
#define XEMU_VP_WORKERS_LABEL_NO NULL
#define XEMU_VP_WORKERS_INFO_0_NO NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_NO NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_NO NULL
#define XEMU_AUDIO_VOLUME_LABEL_NO NULL
#define XEMU_AUDIO_VOLUME_INFO_0_NO NULL
#define OPTION_VAL_100_NO NULL
#define OPTION_VAL_80_NO NULL
#define OPTION_VAL_60_NO NULL
#define OPTION_VAL_40_NO NULL
#define OPTION_VAL_20_NO NULL
#define OPTION_VAL_0_NO NULL
#define XEMU_VK_FAST_PATHS_LABEL_NO NULL
#define XEMU_VK_FAST_PATHS_INFO_0_NO NULL
#define OPTION_VAL_ALL_NO "Alle"
#define OPTION_VAL_NO_GPL_NO NULL
#define OPTION_VAL_NO_DYN_NO NULL
#define OPTION_VAL_NONE_NO "Ingen"
#define XEMU_RUMBLE_P1_LABEL_NO NULL
#define XEMU_RUMBLE_P1_INFO_0_NO NULL
#define XEMU_RUMBLE_P2_LABEL_NO NULL
#define XEMU_RUMBLE_P2_INFO_0_NO NULL
#define XEMU_DEADZONE_P1_LABEL_NO NULL
#define XEMU_DEADZONE_P1_INFO_0_NO NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_NO NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_NO NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_NO NULL
#define OPTION_VAL_15_NO NULL
#define OPTION_VAL_25_NO NULL
#define OPTION_VAL_30_NO NULL
#define XEMU_DEADZONE_P2_LABEL_NO NULL
#define XEMU_DEADZONE_P2_INFO_0_NO NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_NO NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_NO NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_NO NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_NO NULL
#define OPTION_VAL_MOUSE_NO NULL
#define OPTION_VAL_STICK_NO NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_NO NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_NO NULL
#define XEMU_CHIHIRO_FFB_LABEL_NO NULL
#define XEMU_CHIHIRO_FFB_INFO_0_NO NULL
#define OPTION_VAL_50_NO NULL
#define OPTION_VAL_75_NO NULL
#define OPTION_VAL_150_NO NULL
#define OPTION_VAL_200_NO NULL

struct retro_core_option_v2_category option_cats_no[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_NO,
        CATEGORY_SYSTEM_INFO_0_NO
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_NO,
        CATEGORY_VIDEO_INFO_0_NO
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_NO,
        CATEGORY_AUDIO_INFO_0_NO
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_NO,
        CATEGORY_CONTROLS_INFO_0_NO
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_NO,
        CATEGORY_CHIHIRO_INFO_0_NO
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_no[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_NO,
        NULL,
        XEMU_MEMORY_INFO_0_NO,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_NO },
            { "128", OPTION_VAL_128_NO },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_NO,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_NO,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_NO },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_NO,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_NO,
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
        XEMU_HARD_FPU_LABEL_NO,
        NULL,
        XEMU_HARD_FPU_INFO_0_NO,
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
        XEMU_CPU_BOOST_LABEL_NO,
        NULL,
        XEMU_CPU_BOOST_INFO_0_NO,
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
        XEMU_HDD_TRIM_LABEL_NO,
        NULL,
        XEMU_HDD_TRIM_INFO_0_NO,
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
        XEMU_RENDERER_LABEL_NO,
        NULL,
        XEMU_RENDERER_INFO_0_NO,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_NO },
            { "opengl", OPTION_VAL_OPENGL_NO },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_NO,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_NO,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_NO },
            { "4:3",       OPTION_VAL_4_3_NO },
            { "16:9",      OPTION_VAL_16_9_NO },
            { "letterbox", OPTION_VAL_LETTERBOX_NO },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_NO,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_NO,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_NO },
            { "4:3",  OPTION_VAL_4_3_NO },
            { "16:9", OPTION_VAL_16_9_NO },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_NO,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_NO,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_NO },
            { "2", OPTION_VAL_2_NO },
            { "3", OPTION_VAL_3_NO },
            { "4", OPTION_VAL_4_NO },
            { "5", OPTION_VAL_5_NO },
            { "6", OPTION_VAL_6_NO },
            { "7", OPTION_VAL_7_NO },
            { "8", OPTION_VAL_8_NO },
            { "9", OPTION_VAL_9_NO },
            { "10", OPTION_VAL_10_NO },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_NO,
        NULL,
        XEMU_AVPACK_INFO_0_NO,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_NO },
            { "composite", OPTION_VAL_COMPOSITE_NO },
            { "svideo",    OPTION_VAL_SVIDEO_NO },
            { "scart",     OPTION_VAL_SCART_NO },
            { "vga",       OPTION_VAL_VGA_NO },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_NO,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_NO,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_NO,
        NULL,
        XEMU_USE_DSP_INFO_0_NO,
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
        XEMU_DSP_JIT_LABEL_NO,
        NULL,
        XEMU_DSP_JIT_INFO_0_NO,
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
        XEMU_HRTF_LABEL_NO,
        NULL,
        XEMU_HRTF_INFO_0_NO,
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
        XEMU_VP_WORKERS_LABEL_NO,
        NULL,
        XEMU_VP_WORKERS_INFO_0_NO,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_NO },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_NO,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_NO,
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
        XEMU_AUDIO_VOLUME_LABEL_NO,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_NO,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_NO },
            { "80",  OPTION_VAL_80_NO },
            { "60",  OPTION_VAL_60_NO },
            { "40",  OPTION_VAL_40_NO },
            { "20",  OPTION_VAL_20_NO },
            { "0",   OPTION_VAL_0_NO },
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
        XEMU_VK_FAST_PATHS_LABEL_NO,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_NO,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_NO },
            { "no_gpl",   OPTION_VAL_NO_GPL_NO },
            { "no_dyn",   OPTION_VAL_NO_DYN_NO },
            { "none",     OPTION_VAL_NONE_NO },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_NO,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_NO,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_NO,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_NO,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_NO,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_NO,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_NO },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_NO },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_NO },
            { "15", OPTION_VAL_15_NO },
            { "20", OPTION_VAL_20_NO },
            { "25", OPTION_VAL_25_NO },
            { "30", OPTION_VAL_30_NO },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_NO,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_NO,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_NO },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_NO },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_NO },
            { "15", OPTION_VAL_15_NO },
            { "20", OPTION_VAL_20_NO },
            { "25", OPTION_VAL_25_NO },
            { "30", OPTION_VAL_30_NO },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_NO,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_NO,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_NO,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_NO,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_NO },
            { "stick", OPTION_VAL_STICK_NO },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_NO,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_NO,
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
        XEMU_CHIHIRO_FFB_LABEL_NO,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_NO,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_NO },
            { "50",  OPTION_VAL_50_NO },
            { "75",  OPTION_VAL_75_NO },
            { "100", OPTION_VAL_100_NO },
            { "150", OPTION_VAL_150_NO },
            { "200", OPTION_VAL_200_NO },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_no = {
   option_cats_no,
   option_defs_no
};

/* RETRO_LANGUAGE_OR */

#define CATEGORY_SYSTEM_LABEL_OR NULL
#define CATEGORY_SYSTEM_INFO_0_OR NULL
#define CATEGORY_VIDEO_LABEL_OR "ଵିଡ଼ିଓ"
#define CATEGORY_VIDEO_INFO_0_OR NULL
#define CATEGORY_AUDIO_LABEL_OR "ଅଡ଼ିଓ"
#define CATEGORY_AUDIO_INFO_0_OR NULL
#define CATEGORY_CONTROLS_LABEL_OR NULL
#define CATEGORY_CONTROLS_INFO_0_OR NULL
#define CATEGORY_CHIHIRO_LABEL_OR NULL
#define CATEGORY_CHIHIRO_INFO_0_OR NULL
#define XEMU_MEMORY_LABEL_OR NULL
#define XEMU_MEMORY_INFO_0_OR NULL
#define OPTION_VAL_64_OR NULL
#define OPTION_VAL_128_OR NULL
#define XEMU_NETWORK_BACKEND_LABEL_OR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_OR NULL
#define OPTION_VAL_NAT_OR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_OR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_OR NULL
#define XEMU_HARD_FPU_LABEL_OR NULL
#define XEMU_HARD_FPU_INFO_0_OR NULL
#define XEMU_CPU_BOOST_LABEL_OR NULL
#define XEMU_CPU_BOOST_INFO_0_OR NULL
#define XEMU_HDD_TRIM_LABEL_OR NULL
#define XEMU_HDD_TRIM_INFO_0_OR NULL
#define XEMU_RENDERER_LABEL_OR NULL
#define XEMU_RENDERER_INFO_0_OR NULL
#define OPTION_VAL_VULKAN_OR NULL
#define OPTION_VAL_OPENGL_OR NULL
#define XEMU_VIDEO_ASPECT_LABEL_OR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_OR NULL
#define OPTION_VAL_DASHBOARD_OR NULL
#define OPTION_VAL_4_3_OR NULL
#define OPTION_VAL_16_9_OR NULL
#define OPTION_VAL_LETTERBOX_OR NULL
#define XEMU_ASPECT_RATIO_LABEL_OR NULL
#define XEMU_ASPECT_RATIO_INFO_0_OR NULL
#define OPTION_VAL_AUTO_OR NULL
#define XEMU_SURFACE_SCALE_LABEL_OR NULL
#define XEMU_SURFACE_SCALE_INFO_0_OR NULL
#define OPTION_VAL_1_OR NULL
#define OPTION_VAL_2_OR NULL
#define OPTION_VAL_3_OR NULL
#define OPTION_VAL_4_OR NULL
#define OPTION_VAL_5_OR NULL
#define OPTION_VAL_6_OR NULL
#define OPTION_VAL_7_OR NULL
#define OPTION_VAL_8_OR NULL
#define OPTION_VAL_9_OR NULL
#define OPTION_VAL_10_OR NULL
#define XEMU_AVPACK_LABEL_OR NULL
#define XEMU_AVPACK_INFO_0_OR NULL
#define OPTION_VAL_HDTV_OR NULL
#define OPTION_VAL_COMPOSITE_OR NULL
#define OPTION_VAL_SVIDEO_OR NULL
#define OPTION_VAL_SCART_OR NULL
#define OPTION_VAL_VGA_OR NULL
#define XEMU_AUDIO_THREAD_LABEL_OR NULL
#define XEMU_AUDIO_THREAD_INFO_0_OR NULL
#define XEMU_USE_DSP_LABEL_OR NULL
#define XEMU_USE_DSP_INFO_0_OR NULL
#define XEMU_DSP_JIT_LABEL_OR NULL
#define XEMU_DSP_JIT_INFO_0_OR NULL
#define XEMU_HRTF_LABEL_OR NULL
#define XEMU_HRTF_INFO_0_OR NULL
#define XEMU_VP_WORKERS_LABEL_OR NULL
#define XEMU_VP_WORKERS_INFO_0_OR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_OR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_OR NULL
#define XEMU_AUDIO_VOLUME_LABEL_OR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_OR NULL
#define OPTION_VAL_100_OR NULL
#define OPTION_VAL_80_OR NULL
#define OPTION_VAL_60_OR NULL
#define OPTION_VAL_40_OR NULL
#define OPTION_VAL_20_OR NULL
#define OPTION_VAL_0_OR NULL
#define XEMU_VK_FAST_PATHS_LABEL_OR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_OR NULL
#define OPTION_VAL_ALL_OR NULL
#define OPTION_VAL_NO_GPL_OR NULL
#define OPTION_VAL_NO_DYN_OR NULL
#define OPTION_VAL_NONE_OR NULL
#define XEMU_RUMBLE_P1_LABEL_OR NULL
#define XEMU_RUMBLE_P1_INFO_0_OR NULL
#define XEMU_RUMBLE_P2_LABEL_OR NULL
#define XEMU_RUMBLE_P2_INFO_0_OR NULL
#define XEMU_DEADZONE_P1_LABEL_OR NULL
#define XEMU_DEADZONE_P1_INFO_0_OR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_OR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_OR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_OR NULL
#define OPTION_VAL_15_OR NULL
#define OPTION_VAL_25_OR NULL
#define OPTION_VAL_30_OR NULL
#define XEMU_DEADZONE_P2_LABEL_OR NULL
#define XEMU_DEADZONE_P2_INFO_0_OR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_OR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_OR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_OR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_OR NULL
#define OPTION_VAL_MOUSE_OR NULL
#define OPTION_VAL_STICK_OR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_OR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_OR NULL
#define XEMU_CHIHIRO_FFB_LABEL_OR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_OR NULL
#define OPTION_VAL_50_OR NULL
#define OPTION_VAL_75_OR NULL
#define OPTION_VAL_150_OR NULL
#define OPTION_VAL_200_OR NULL

struct retro_core_option_v2_category option_cats_or[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_OR,
        CATEGORY_SYSTEM_INFO_0_OR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_OR,
        CATEGORY_VIDEO_INFO_0_OR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_OR,
        CATEGORY_AUDIO_INFO_0_OR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_OR,
        CATEGORY_CONTROLS_INFO_0_OR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_OR,
        CATEGORY_CHIHIRO_INFO_0_OR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_or[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_OR,
        NULL,
        XEMU_MEMORY_INFO_0_OR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_OR },
            { "128", OPTION_VAL_128_OR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_OR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_OR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_OR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_OR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_OR,
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
        XEMU_HARD_FPU_LABEL_OR,
        NULL,
        XEMU_HARD_FPU_INFO_0_OR,
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
        XEMU_CPU_BOOST_LABEL_OR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_OR,
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
        XEMU_HDD_TRIM_LABEL_OR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_OR,
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
        XEMU_RENDERER_LABEL_OR,
        NULL,
        XEMU_RENDERER_INFO_0_OR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_OR },
            { "opengl", OPTION_VAL_OPENGL_OR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_OR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_OR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_OR },
            { "4:3",       OPTION_VAL_4_3_OR },
            { "16:9",      OPTION_VAL_16_9_OR },
            { "letterbox", OPTION_VAL_LETTERBOX_OR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_OR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_OR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_OR },
            { "4:3",  OPTION_VAL_4_3_OR },
            { "16:9", OPTION_VAL_16_9_OR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_OR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_OR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_OR },
            { "2", OPTION_VAL_2_OR },
            { "3", OPTION_VAL_3_OR },
            { "4", OPTION_VAL_4_OR },
            { "5", OPTION_VAL_5_OR },
            { "6", OPTION_VAL_6_OR },
            { "7", OPTION_VAL_7_OR },
            { "8", OPTION_VAL_8_OR },
            { "9", OPTION_VAL_9_OR },
            { "10", OPTION_VAL_10_OR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_OR,
        NULL,
        XEMU_AVPACK_INFO_0_OR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_OR },
            { "composite", OPTION_VAL_COMPOSITE_OR },
            { "svideo",    OPTION_VAL_SVIDEO_OR },
            { "scart",     OPTION_VAL_SCART_OR },
            { "vga",       OPTION_VAL_VGA_OR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_OR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_OR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_OR,
        NULL,
        XEMU_USE_DSP_INFO_0_OR,
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
        XEMU_DSP_JIT_LABEL_OR,
        NULL,
        XEMU_DSP_JIT_INFO_0_OR,
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
        XEMU_HRTF_LABEL_OR,
        NULL,
        XEMU_HRTF_INFO_0_OR,
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
        XEMU_VP_WORKERS_LABEL_OR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_OR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_OR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_OR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_OR,
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
        XEMU_AUDIO_VOLUME_LABEL_OR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_OR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_OR },
            { "80",  OPTION_VAL_80_OR },
            { "60",  OPTION_VAL_60_OR },
            { "40",  OPTION_VAL_40_OR },
            { "20",  OPTION_VAL_20_OR },
            { "0",   OPTION_VAL_0_OR },
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
        XEMU_VK_FAST_PATHS_LABEL_OR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_OR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_OR },
            { "no_gpl",   OPTION_VAL_NO_GPL_OR },
            { "no_dyn",   OPTION_VAL_NO_DYN_OR },
            { "none",     OPTION_VAL_NONE_OR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_OR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_OR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_OR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_OR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_OR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_OR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_OR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_OR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_OR },
            { "15", OPTION_VAL_15_OR },
            { "20", OPTION_VAL_20_OR },
            { "25", OPTION_VAL_25_OR },
            { "30", OPTION_VAL_30_OR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_OR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_OR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_OR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_OR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_OR },
            { "15", OPTION_VAL_15_OR },
            { "20", OPTION_VAL_20_OR },
            { "25", OPTION_VAL_25_OR },
            { "30", OPTION_VAL_30_OR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_OR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_OR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_OR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_OR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_OR },
            { "stick", OPTION_VAL_STICK_OR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_OR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_OR,
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
        XEMU_CHIHIRO_FFB_LABEL_OR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_OR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_OR },
            { "50",  OPTION_VAL_50_OR },
            { "75",  OPTION_VAL_75_OR },
            { "100", OPTION_VAL_100_OR },
            { "150", OPTION_VAL_150_OR },
            { "200", OPTION_VAL_200_OR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_or = {
   option_cats_or,
   option_defs_or
};

/* RETRO_LANGUAGE_PL */

#define CATEGORY_SYSTEM_LABEL_PL NULL
#define CATEGORY_SYSTEM_INFO_0_PL NULL
#define CATEGORY_VIDEO_LABEL_PL "Wideo"
#define CATEGORY_VIDEO_INFO_0_PL NULL
#define CATEGORY_AUDIO_LABEL_PL "Dźwięk"
#define CATEGORY_AUDIO_INFO_0_PL NULL
#define CATEGORY_CONTROLS_LABEL_PL "Elementy sterujące"
#define CATEGORY_CONTROLS_INFO_0_PL NULL
#define CATEGORY_CHIHIRO_LABEL_PL NULL
#define CATEGORY_CHIHIRO_INFO_0_PL NULL
#define XEMU_MEMORY_LABEL_PL NULL
#define XEMU_MEMORY_INFO_0_PL NULL
#define OPTION_VAL_64_PL NULL
#define OPTION_VAL_128_PL NULL
#define XEMU_NETWORK_BACKEND_LABEL_PL NULL
#define XEMU_NETWORK_BACKEND_INFO_0_PL NULL
#define OPTION_VAL_NAT_PL NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_PL NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_PL NULL
#define XEMU_HARD_FPU_LABEL_PL NULL
#define XEMU_HARD_FPU_INFO_0_PL NULL
#define XEMU_CPU_BOOST_LABEL_PL NULL
#define XEMU_CPU_BOOST_INFO_0_PL NULL
#define XEMU_HDD_TRIM_LABEL_PL NULL
#define XEMU_HDD_TRIM_INFO_0_PL NULL
#define XEMU_RENDERER_LABEL_PL NULL
#define XEMU_RENDERER_INFO_0_PL NULL
#define OPTION_VAL_VULKAN_PL NULL
#define OPTION_VAL_OPENGL_PL NULL
#define XEMU_VIDEO_ASPECT_LABEL_PL NULL
#define XEMU_VIDEO_ASPECT_INFO_0_PL NULL
#define OPTION_VAL_DASHBOARD_PL NULL
#define OPTION_VAL_4_3_PL NULL
#define OPTION_VAL_16_9_PL NULL
#define OPTION_VAL_LETTERBOX_PL NULL
#define XEMU_ASPECT_RATIO_LABEL_PL "Proporcje rdzenia"
#define XEMU_ASPECT_RATIO_INFO_0_PL NULL
#define OPTION_VAL_AUTO_PL "Automatyczny"
#define XEMU_SURFACE_SCALE_LABEL_PL NULL
#define XEMU_SURFACE_SCALE_INFO_0_PL NULL
#define OPTION_VAL_1_PL NULL
#define OPTION_VAL_2_PL NULL
#define OPTION_VAL_3_PL NULL
#define OPTION_VAL_4_PL NULL
#define OPTION_VAL_5_PL NULL
#define OPTION_VAL_6_PL NULL
#define OPTION_VAL_7_PL NULL
#define OPTION_VAL_8_PL NULL
#define OPTION_VAL_9_PL NULL
#define OPTION_VAL_10_PL NULL
#define XEMU_AVPACK_LABEL_PL NULL
#define XEMU_AVPACK_INFO_0_PL NULL
#define OPTION_VAL_HDTV_PL NULL
#define OPTION_VAL_COMPOSITE_PL "Kompozytowy"
#define OPTION_VAL_SVIDEO_PL NULL
#define OPTION_VAL_SCART_PL NULL
#define OPTION_VAL_VGA_PL NULL
#define XEMU_AUDIO_THREAD_LABEL_PL NULL
#define XEMU_AUDIO_THREAD_INFO_0_PL NULL
#define XEMU_USE_DSP_LABEL_PL NULL
#define XEMU_USE_DSP_INFO_0_PL NULL
#define XEMU_DSP_JIT_LABEL_PL NULL
#define XEMU_DSP_JIT_INFO_0_PL NULL
#define XEMU_HRTF_LABEL_PL NULL
#define XEMU_HRTF_INFO_0_PL NULL
#define XEMU_VP_WORKERS_LABEL_PL NULL
#define XEMU_VP_WORKERS_INFO_0_PL NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_PL NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_PL NULL
#define XEMU_AUDIO_VOLUME_LABEL_PL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PL NULL
#define OPTION_VAL_100_PL NULL
#define OPTION_VAL_80_PL "80 %"
#define OPTION_VAL_60_PL "60 %"
#define OPTION_VAL_40_PL NULL
#define OPTION_VAL_20_PL NULL
#define OPTION_VAL_0_PL NULL
#define XEMU_VK_FAST_PATHS_LABEL_PL NULL
#define XEMU_VK_FAST_PATHS_INFO_0_PL NULL
#define OPTION_VAL_ALL_PL "Wszystkie"
#define OPTION_VAL_NO_GPL_PL NULL
#define OPTION_VAL_NO_DYN_PL NULL
#define OPTION_VAL_NONE_PL "Brak"
#define XEMU_RUMBLE_P1_LABEL_PL NULL
#define XEMU_RUMBLE_P1_INFO_0_PL NULL
#define XEMU_RUMBLE_P2_LABEL_PL NULL
#define XEMU_RUMBLE_P2_INFO_0_PL NULL
#define XEMU_DEADZONE_P1_LABEL_PL NULL
#define XEMU_DEADZONE_P1_INFO_0_PL NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_PL NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_PL NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_PL NULL
#define OPTION_VAL_15_PL NULL
#define OPTION_VAL_25_PL NULL
#define OPTION_VAL_30_PL "30 %"
#define XEMU_DEADZONE_P2_LABEL_PL NULL
#define XEMU_DEADZONE_P2_INFO_0_PL NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_PL NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_PL NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_PL NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_PL NULL
#define OPTION_VAL_MOUSE_PL "Mysz"
#define OPTION_VAL_STICK_PL NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_PL NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_PL NULL
#define XEMU_CHIHIRO_FFB_LABEL_PL NULL
#define XEMU_CHIHIRO_FFB_INFO_0_PL NULL
#define OPTION_VAL_50_PL "50 %"
#define OPTION_VAL_75_PL NULL
#define OPTION_VAL_150_PL NULL
#define OPTION_VAL_200_PL NULL

struct retro_core_option_v2_category option_cats_pl[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_PL,
        CATEGORY_SYSTEM_INFO_0_PL
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_PL,
        CATEGORY_VIDEO_INFO_0_PL
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_PL,
        CATEGORY_AUDIO_INFO_0_PL
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_PL,
        CATEGORY_CONTROLS_INFO_0_PL
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_PL,
        CATEGORY_CHIHIRO_INFO_0_PL
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pl[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_PL,
        NULL,
        XEMU_MEMORY_INFO_0_PL,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_PL },
            { "128", OPTION_VAL_128_PL },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_PL,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_PL,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_PL },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_PL,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_PL,
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
        XEMU_HARD_FPU_LABEL_PL,
        NULL,
        XEMU_HARD_FPU_INFO_0_PL,
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
        XEMU_CPU_BOOST_LABEL_PL,
        NULL,
        XEMU_CPU_BOOST_INFO_0_PL,
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
        XEMU_HDD_TRIM_LABEL_PL,
        NULL,
        XEMU_HDD_TRIM_INFO_0_PL,
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
        XEMU_RENDERER_LABEL_PL,
        NULL,
        XEMU_RENDERER_INFO_0_PL,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_PL },
            { "opengl", OPTION_VAL_OPENGL_PL },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_PL,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_PL,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_PL },
            { "4:3",       OPTION_VAL_4_3_PL },
            { "16:9",      OPTION_VAL_16_9_PL },
            { "letterbox", OPTION_VAL_LETTERBOX_PL },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_PL,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_PL,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_PL },
            { "4:3",  OPTION_VAL_4_3_PL },
            { "16:9", OPTION_VAL_16_9_PL },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_PL,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_PL,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_PL },
            { "2", OPTION_VAL_2_PL },
            { "3", OPTION_VAL_3_PL },
            { "4", OPTION_VAL_4_PL },
            { "5", OPTION_VAL_5_PL },
            { "6", OPTION_VAL_6_PL },
            { "7", OPTION_VAL_7_PL },
            { "8", OPTION_VAL_8_PL },
            { "9", OPTION_VAL_9_PL },
            { "10", OPTION_VAL_10_PL },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_PL,
        NULL,
        XEMU_AVPACK_INFO_0_PL,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_PL },
            { "composite", OPTION_VAL_COMPOSITE_PL },
            { "svideo",    OPTION_VAL_SVIDEO_PL },
            { "scart",     OPTION_VAL_SCART_PL },
            { "vga",       OPTION_VAL_VGA_PL },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_PL,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_PL,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_PL,
        NULL,
        XEMU_USE_DSP_INFO_0_PL,
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
        XEMU_DSP_JIT_LABEL_PL,
        NULL,
        XEMU_DSP_JIT_INFO_0_PL,
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
        XEMU_HRTF_LABEL_PL,
        NULL,
        XEMU_HRTF_INFO_0_PL,
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
        XEMU_VP_WORKERS_LABEL_PL,
        NULL,
        XEMU_VP_WORKERS_INFO_0_PL,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_PL },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_PL,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_PL,
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
        XEMU_AUDIO_VOLUME_LABEL_PL,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_PL,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_PL },
            { "80",  OPTION_VAL_80_PL },
            { "60",  OPTION_VAL_60_PL },
            { "40",  OPTION_VAL_40_PL },
            { "20",  OPTION_VAL_20_PL },
            { "0",   OPTION_VAL_0_PL },
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
        XEMU_VK_FAST_PATHS_LABEL_PL,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_PL,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_PL },
            { "no_gpl",   OPTION_VAL_NO_GPL_PL },
            { "no_dyn",   OPTION_VAL_NO_DYN_PL },
            { "none",     OPTION_VAL_NONE_PL },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_PL,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_PL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_PL,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_PL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_PL,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_PL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_PL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_PL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_PL },
            { "15", OPTION_VAL_15_PL },
            { "20", OPTION_VAL_20_PL },
            { "25", OPTION_VAL_25_PL },
            { "30", OPTION_VAL_30_PL },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_PL,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_PL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_PL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_PL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_PL },
            { "15", OPTION_VAL_15_PL },
            { "20", OPTION_VAL_20_PL },
            { "25", OPTION_VAL_25_PL },
            { "30", OPTION_VAL_30_PL },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_PL,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_PL,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_PL,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_PL,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_PL },
            { "stick", OPTION_VAL_STICK_PL },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_PL,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_PL,
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
        XEMU_CHIHIRO_FFB_LABEL_PL,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_PL,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_PL },
            { "50",  OPTION_VAL_50_PL },
            { "75",  OPTION_VAL_75_PL },
            { "100", OPTION_VAL_100_PL },
            { "150", OPTION_VAL_150_PL },
            { "200", OPTION_VAL_200_PL },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_pl = {
   option_cats_pl,
   option_defs_pl
};

/* RETRO_LANGUAGE_PT_BR */

#define CATEGORY_SYSTEM_LABEL_PT_BR NULL
#define CATEGORY_SYSTEM_INFO_0_PT_BR NULL
#define CATEGORY_VIDEO_LABEL_PT_BR "Vídeo"
#define CATEGORY_VIDEO_INFO_0_PT_BR NULL
#define CATEGORY_AUDIO_LABEL_PT_BR "Áudio"
#define CATEGORY_AUDIO_INFO_0_PT_BR NULL
#define CATEGORY_CONTROLS_LABEL_PT_BR "Controles"
#define CATEGORY_CONTROLS_INFO_0_PT_BR NULL
#define CATEGORY_CHIHIRO_LABEL_PT_BR NULL
#define CATEGORY_CHIHIRO_INFO_0_PT_BR NULL
#define XEMU_MEMORY_LABEL_PT_BR NULL
#define XEMU_MEMORY_INFO_0_PT_BR NULL
#define OPTION_VAL_64_PT_BR NULL
#define OPTION_VAL_128_PT_BR NULL
#define XEMU_NETWORK_BACKEND_LABEL_PT_BR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_PT_BR NULL
#define OPTION_VAL_NAT_PT_BR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_PT_BR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_PT_BR NULL
#define XEMU_HARD_FPU_LABEL_PT_BR NULL
#define XEMU_HARD_FPU_INFO_0_PT_BR NULL
#define XEMU_CPU_BOOST_LABEL_PT_BR NULL
#define XEMU_CPU_BOOST_INFO_0_PT_BR NULL
#define XEMU_HDD_TRIM_LABEL_PT_BR NULL
#define XEMU_HDD_TRIM_INFO_0_PT_BR NULL
#define XEMU_RENDERER_LABEL_PT_BR NULL
#define XEMU_RENDERER_INFO_0_PT_BR NULL
#define OPTION_VAL_VULKAN_PT_BR NULL
#define OPTION_VAL_OPENGL_PT_BR NULL
#define XEMU_VIDEO_ASPECT_LABEL_PT_BR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_PT_BR NULL
#define OPTION_VAL_DASHBOARD_PT_BR NULL
#define OPTION_VAL_4_3_PT_BR NULL
#define OPTION_VAL_16_9_PT_BR NULL
#define OPTION_VAL_LETTERBOX_PT_BR NULL
#define XEMU_ASPECT_RATIO_LABEL_PT_BR "Proporção de tela do núcleo"
#define XEMU_ASPECT_RATIO_INFO_0_PT_BR NULL
#define OPTION_VAL_AUTO_PT_BR "Automático"
#define XEMU_SURFACE_SCALE_LABEL_PT_BR NULL
#define XEMU_SURFACE_SCALE_INFO_0_PT_BR NULL
#define OPTION_VAL_1_PT_BR NULL
#define OPTION_VAL_2_PT_BR NULL
#define OPTION_VAL_3_PT_BR NULL
#define OPTION_VAL_4_PT_BR NULL
#define OPTION_VAL_5_PT_BR NULL
#define OPTION_VAL_6_PT_BR NULL
#define OPTION_VAL_7_PT_BR NULL
#define OPTION_VAL_8_PT_BR NULL
#define OPTION_VAL_9_PT_BR NULL
#define OPTION_VAL_10_PT_BR NULL
#define XEMU_AVPACK_LABEL_PT_BR NULL
#define XEMU_AVPACK_INFO_0_PT_BR NULL
#define OPTION_VAL_HDTV_PT_BR NULL
#define OPTION_VAL_COMPOSITE_PT_BR "Composto"
#define OPTION_VAL_SVIDEO_PT_BR NULL
#define OPTION_VAL_SCART_PT_BR NULL
#define OPTION_VAL_VGA_PT_BR NULL
#define XEMU_AUDIO_THREAD_LABEL_PT_BR NULL
#define XEMU_AUDIO_THREAD_INFO_0_PT_BR NULL
#define XEMU_USE_DSP_LABEL_PT_BR NULL
#define XEMU_USE_DSP_INFO_0_PT_BR NULL
#define XEMU_DSP_JIT_LABEL_PT_BR NULL
#define XEMU_DSP_JIT_INFO_0_PT_BR NULL
#define XEMU_HRTF_LABEL_PT_BR NULL
#define XEMU_HRTF_INFO_0_PT_BR NULL
#define XEMU_VP_WORKERS_LABEL_PT_BR NULL
#define XEMU_VP_WORKERS_INFO_0_PT_BR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_PT_BR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_PT_BR NULL
#define XEMU_AUDIO_VOLUME_LABEL_PT_BR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PT_BR NULL
#define OPTION_VAL_100_PT_BR NULL
#define OPTION_VAL_80_PT_BR NULL
#define OPTION_VAL_60_PT_BR NULL
#define OPTION_VAL_40_PT_BR NULL
#define OPTION_VAL_20_PT_BR NULL
#define OPTION_VAL_0_PT_BR NULL
#define XEMU_VK_FAST_PATHS_LABEL_PT_BR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_PT_BR NULL
#define OPTION_VAL_ALL_PT_BR "Todas"
#define OPTION_VAL_NO_GPL_PT_BR NULL
#define OPTION_VAL_NO_DYN_PT_BR NULL
#define OPTION_VAL_NONE_PT_BR "Nenhum"
#define XEMU_RUMBLE_P1_LABEL_PT_BR NULL
#define XEMU_RUMBLE_P1_INFO_0_PT_BR NULL
#define XEMU_RUMBLE_P2_LABEL_PT_BR NULL
#define XEMU_RUMBLE_P2_INFO_0_PT_BR NULL
#define XEMU_DEADZONE_P1_LABEL_PT_BR NULL
#define XEMU_DEADZONE_P1_INFO_0_PT_BR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_PT_BR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_PT_BR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_PT_BR NULL
#define OPTION_VAL_15_PT_BR NULL
#define OPTION_VAL_25_PT_BR NULL
#define OPTION_VAL_30_PT_BR NULL
#define XEMU_DEADZONE_P2_LABEL_PT_BR NULL
#define XEMU_DEADZONE_P2_INFO_0_PT_BR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_PT_BR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_PT_BR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_PT_BR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_PT_BR NULL
#define OPTION_VAL_MOUSE_PT_BR NULL
#define OPTION_VAL_STICK_PT_BR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_PT_BR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_PT_BR NULL
#define XEMU_CHIHIRO_FFB_LABEL_PT_BR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_PT_BR NULL
#define OPTION_VAL_50_PT_BR NULL
#define OPTION_VAL_75_PT_BR NULL
#define OPTION_VAL_150_PT_BR NULL
#define OPTION_VAL_200_PT_BR NULL

struct retro_core_option_v2_category option_cats_pt_br[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_PT_BR,
        CATEGORY_SYSTEM_INFO_0_PT_BR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_PT_BR,
        CATEGORY_VIDEO_INFO_0_PT_BR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_PT_BR,
        CATEGORY_AUDIO_INFO_0_PT_BR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_PT_BR,
        CATEGORY_CONTROLS_INFO_0_PT_BR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_PT_BR,
        CATEGORY_CHIHIRO_INFO_0_PT_BR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_br[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_PT_BR,
        NULL,
        XEMU_MEMORY_INFO_0_PT_BR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_PT_BR },
            { "128", OPTION_VAL_128_PT_BR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_PT_BR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_PT_BR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_PT_BR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_PT_BR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_PT_BR,
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
        XEMU_HARD_FPU_LABEL_PT_BR,
        NULL,
        XEMU_HARD_FPU_INFO_0_PT_BR,
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
        XEMU_CPU_BOOST_LABEL_PT_BR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_PT_BR,
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
        XEMU_HDD_TRIM_LABEL_PT_BR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_PT_BR,
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
        XEMU_RENDERER_LABEL_PT_BR,
        NULL,
        XEMU_RENDERER_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_PT_BR },
            { "opengl", OPTION_VAL_OPENGL_PT_BR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_PT_BR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_PT_BR },
            { "4:3",       OPTION_VAL_4_3_PT_BR },
            { "16:9",      OPTION_VAL_16_9_PT_BR },
            { "letterbox", OPTION_VAL_LETTERBOX_PT_BR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_PT_BR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_PT_BR },
            { "4:3",  OPTION_VAL_4_3_PT_BR },
            { "16:9", OPTION_VAL_16_9_PT_BR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_PT_BR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_PT_BR },
            { "2", OPTION_VAL_2_PT_BR },
            { "3", OPTION_VAL_3_PT_BR },
            { "4", OPTION_VAL_4_PT_BR },
            { "5", OPTION_VAL_5_PT_BR },
            { "6", OPTION_VAL_6_PT_BR },
            { "7", OPTION_VAL_7_PT_BR },
            { "8", OPTION_VAL_8_PT_BR },
            { "9", OPTION_VAL_9_PT_BR },
            { "10", OPTION_VAL_10_PT_BR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_PT_BR,
        NULL,
        XEMU_AVPACK_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_PT_BR },
            { "composite", OPTION_VAL_COMPOSITE_PT_BR },
            { "svideo",    OPTION_VAL_SVIDEO_PT_BR },
            { "scart",     OPTION_VAL_SCART_PT_BR },
            { "vga",       OPTION_VAL_VGA_PT_BR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_PT_BR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_PT_BR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_PT_BR,
        NULL,
        XEMU_USE_DSP_INFO_0_PT_BR,
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
        XEMU_DSP_JIT_LABEL_PT_BR,
        NULL,
        XEMU_DSP_JIT_INFO_0_PT_BR,
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
        XEMU_HRTF_LABEL_PT_BR,
        NULL,
        XEMU_HRTF_INFO_0_PT_BR,
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
        XEMU_VP_WORKERS_LABEL_PT_BR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_PT_BR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_PT_BR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_PT_BR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_PT_BR,
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
        XEMU_AUDIO_VOLUME_LABEL_PT_BR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_PT_BR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_PT_BR },
            { "80",  OPTION_VAL_80_PT_BR },
            { "60",  OPTION_VAL_60_PT_BR },
            { "40",  OPTION_VAL_40_PT_BR },
            { "20",  OPTION_VAL_20_PT_BR },
            { "0",   OPTION_VAL_0_PT_BR },
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
        XEMU_VK_FAST_PATHS_LABEL_PT_BR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_PT_BR },
            { "no_gpl",   OPTION_VAL_NO_GPL_PT_BR },
            { "no_dyn",   OPTION_VAL_NO_DYN_PT_BR },
            { "none",     OPTION_VAL_NONE_PT_BR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_PT_BR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_PT_BR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_PT_BR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_PT_BR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_PT_BR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_PT_BR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_PT_BR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_PT_BR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_PT_BR },
            { "15", OPTION_VAL_15_PT_BR },
            { "20", OPTION_VAL_20_PT_BR },
            { "25", OPTION_VAL_25_PT_BR },
            { "30", OPTION_VAL_30_PT_BR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_PT_BR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_PT_BR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_PT_BR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_PT_BR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_PT_BR },
            { "15", OPTION_VAL_15_PT_BR },
            { "20", OPTION_VAL_20_PT_BR },
            { "25", OPTION_VAL_25_PT_BR },
            { "30", OPTION_VAL_30_PT_BR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_PT_BR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_PT_BR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_PT_BR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_PT_BR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_PT_BR },
            { "stick", OPTION_VAL_STICK_PT_BR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_PT_BR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_PT_BR,
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
        XEMU_CHIHIRO_FFB_LABEL_PT_BR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_PT_BR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_PT_BR },
            { "50",  OPTION_VAL_50_PT_BR },
            { "75",  OPTION_VAL_75_PT_BR },
            { "100", OPTION_VAL_100_PT_BR },
            { "150", OPTION_VAL_150_PT_BR },
            { "200", OPTION_VAL_200_PT_BR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_pt_br = {
   option_cats_pt_br,
   option_defs_pt_br
};

/* RETRO_LANGUAGE_PT_PT */

#define CATEGORY_SYSTEM_LABEL_PT_PT NULL
#define CATEGORY_SYSTEM_INFO_0_PT_PT NULL
#define CATEGORY_VIDEO_LABEL_PT_PT "Vídeo"
#define CATEGORY_VIDEO_INFO_0_PT_PT NULL
#define CATEGORY_AUDIO_LABEL_PT_PT "Áudio"
#define CATEGORY_AUDIO_INFO_0_PT_PT NULL
#define CATEGORY_CONTROLS_LABEL_PT_PT "Mapeamento de teclas"
#define CATEGORY_CONTROLS_INFO_0_PT_PT NULL
#define CATEGORY_CHIHIRO_LABEL_PT_PT NULL
#define CATEGORY_CHIHIRO_INFO_0_PT_PT NULL
#define XEMU_MEMORY_LABEL_PT_PT NULL
#define XEMU_MEMORY_INFO_0_PT_PT NULL
#define OPTION_VAL_64_PT_PT NULL
#define OPTION_VAL_128_PT_PT NULL
#define XEMU_NETWORK_BACKEND_LABEL_PT_PT NULL
#define XEMU_NETWORK_BACKEND_INFO_0_PT_PT NULL
#define OPTION_VAL_NAT_PT_PT NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_PT_PT NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_PT_PT NULL
#define XEMU_HARD_FPU_LABEL_PT_PT NULL
#define XEMU_HARD_FPU_INFO_0_PT_PT NULL
#define XEMU_CPU_BOOST_LABEL_PT_PT NULL
#define XEMU_CPU_BOOST_INFO_0_PT_PT NULL
#define XEMU_HDD_TRIM_LABEL_PT_PT NULL
#define XEMU_HDD_TRIM_INFO_0_PT_PT NULL
#define XEMU_RENDERER_LABEL_PT_PT NULL
#define XEMU_RENDERER_INFO_0_PT_PT NULL
#define OPTION_VAL_VULKAN_PT_PT NULL
#define OPTION_VAL_OPENGL_PT_PT NULL
#define XEMU_VIDEO_ASPECT_LABEL_PT_PT NULL
#define XEMU_VIDEO_ASPECT_INFO_0_PT_PT NULL
#define OPTION_VAL_DASHBOARD_PT_PT NULL
#define OPTION_VAL_4_3_PT_PT NULL
#define OPTION_VAL_16_9_PT_PT NULL
#define OPTION_VAL_LETTERBOX_PT_PT NULL
#define XEMU_ASPECT_RATIO_LABEL_PT_PT NULL
#define XEMU_ASPECT_RATIO_INFO_0_PT_PT NULL
#define OPTION_VAL_AUTO_PT_PT "Automático"
#define XEMU_SURFACE_SCALE_LABEL_PT_PT NULL
#define XEMU_SURFACE_SCALE_INFO_0_PT_PT NULL
#define OPTION_VAL_1_PT_PT NULL
#define OPTION_VAL_2_PT_PT NULL
#define OPTION_VAL_3_PT_PT NULL
#define OPTION_VAL_4_PT_PT NULL
#define OPTION_VAL_5_PT_PT NULL
#define OPTION_VAL_6_PT_PT NULL
#define OPTION_VAL_7_PT_PT NULL
#define OPTION_VAL_8_PT_PT NULL
#define OPTION_VAL_9_PT_PT NULL
#define OPTION_VAL_10_PT_PT NULL
#define XEMU_AVPACK_LABEL_PT_PT NULL
#define XEMU_AVPACK_INFO_0_PT_PT NULL
#define OPTION_VAL_HDTV_PT_PT NULL
#define OPTION_VAL_COMPOSITE_PT_PT NULL
#define OPTION_VAL_SVIDEO_PT_PT NULL
#define OPTION_VAL_SCART_PT_PT NULL
#define OPTION_VAL_VGA_PT_PT NULL
#define XEMU_AUDIO_THREAD_LABEL_PT_PT NULL
#define XEMU_AUDIO_THREAD_INFO_0_PT_PT NULL
#define XEMU_USE_DSP_LABEL_PT_PT NULL
#define XEMU_USE_DSP_INFO_0_PT_PT NULL
#define XEMU_DSP_JIT_LABEL_PT_PT NULL
#define XEMU_DSP_JIT_INFO_0_PT_PT NULL
#define XEMU_HRTF_LABEL_PT_PT NULL
#define XEMU_HRTF_INFO_0_PT_PT NULL
#define XEMU_VP_WORKERS_LABEL_PT_PT NULL
#define XEMU_VP_WORKERS_INFO_0_PT_PT NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_PT_PT NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_PT_PT NULL
#define XEMU_AUDIO_VOLUME_LABEL_PT_PT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PT_PT NULL
#define OPTION_VAL_100_PT_PT NULL
#define OPTION_VAL_80_PT_PT NULL
#define OPTION_VAL_60_PT_PT NULL
#define OPTION_VAL_40_PT_PT NULL
#define OPTION_VAL_20_PT_PT NULL
#define OPTION_VAL_0_PT_PT NULL
#define XEMU_VK_FAST_PATHS_LABEL_PT_PT NULL
#define XEMU_VK_FAST_PATHS_INFO_0_PT_PT NULL
#define OPTION_VAL_ALL_PT_PT NULL
#define OPTION_VAL_NO_GPL_PT_PT NULL
#define OPTION_VAL_NO_DYN_PT_PT NULL
#define OPTION_VAL_NONE_PT_PT "Não partilhar"
#define XEMU_RUMBLE_P1_LABEL_PT_PT NULL
#define XEMU_RUMBLE_P1_INFO_0_PT_PT NULL
#define XEMU_RUMBLE_P2_LABEL_PT_PT NULL
#define XEMU_RUMBLE_P2_INFO_0_PT_PT NULL
#define XEMU_DEADZONE_P1_LABEL_PT_PT NULL
#define XEMU_DEADZONE_P1_INFO_0_PT_PT NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_PT_PT NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_PT_PT NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_PT_PT NULL
#define OPTION_VAL_15_PT_PT NULL
#define OPTION_VAL_25_PT_PT NULL
#define OPTION_VAL_30_PT_PT NULL
#define XEMU_DEADZONE_P2_LABEL_PT_PT NULL
#define XEMU_DEADZONE_P2_INFO_0_PT_PT NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_PT_PT NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_PT_PT NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_PT_PT NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_PT_PT NULL
#define OPTION_VAL_MOUSE_PT_PT NULL
#define OPTION_VAL_STICK_PT_PT NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_PT_PT NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_PT_PT NULL
#define XEMU_CHIHIRO_FFB_LABEL_PT_PT NULL
#define XEMU_CHIHIRO_FFB_INFO_0_PT_PT NULL
#define OPTION_VAL_50_PT_PT NULL
#define OPTION_VAL_75_PT_PT NULL
#define OPTION_VAL_150_PT_PT NULL
#define OPTION_VAL_200_PT_PT NULL

struct retro_core_option_v2_category option_cats_pt_pt[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_PT_PT,
        CATEGORY_SYSTEM_INFO_0_PT_PT
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_PT_PT,
        CATEGORY_VIDEO_INFO_0_PT_PT
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_PT_PT,
        CATEGORY_AUDIO_INFO_0_PT_PT
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_PT_PT,
        CATEGORY_CONTROLS_INFO_0_PT_PT
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_PT_PT,
        CATEGORY_CHIHIRO_INFO_0_PT_PT
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_pt[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_PT_PT,
        NULL,
        XEMU_MEMORY_INFO_0_PT_PT,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_PT_PT },
            { "128", OPTION_VAL_128_PT_PT },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_PT_PT,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_PT_PT,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_PT_PT },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_PT_PT,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_PT_PT,
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
        XEMU_HARD_FPU_LABEL_PT_PT,
        NULL,
        XEMU_HARD_FPU_INFO_0_PT_PT,
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
        XEMU_CPU_BOOST_LABEL_PT_PT,
        NULL,
        XEMU_CPU_BOOST_INFO_0_PT_PT,
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
        XEMU_HDD_TRIM_LABEL_PT_PT,
        NULL,
        XEMU_HDD_TRIM_INFO_0_PT_PT,
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
        XEMU_RENDERER_LABEL_PT_PT,
        NULL,
        XEMU_RENDERER_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_PT_PT },
            { "opengl", OPTION_VAL_OPENGL_PT_PT },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_PT_PT,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_PT_PT },
            { "4:3",       OPTION_VAL_4_3_PT_PT },
            { "16:9",      OPTION_VAL_16_9_PT_PT },
            { "letterbox", OPTION_VAL_LETTERBOX_PT_PT },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_PT_PT,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_PT_PT },
            { "4:3",  OPTION_VAL_4_3_PT_PT },
            { "16:9", OPTION_VAL_16_9_PT_PT },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_PT_PT,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_PT_PT },
            { "2", OPTION_VAL_2_PT_PT },
            { "3", OPTION_VAL_3_PT_PT },
            { "4", OPTION_VAL_4_PT_PT },
            { "5", OPTION_VAL_5_PT_PT },
            { "6", OPTION_VAL_6_PT_PT },
            { "7", OPTION_VAL_7_PT_PT },
            { "8", OPTION_VAL_8_PT_PT },
            { "9", OPTION_VAL_9_PT_PT },
            { "10", OPTION_VAL_10_PT_PT },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_PT_PT,
        NULL,
        XEMU_AVPACK_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_PT_PT },
            { "composite", OPTION_VAL_COMPOSITE_PT_PT },
            { "svideo",    OPTION_VAL_SVIDEO_PT_PT },
            { "scart",     OPTION_VAL_SCART_PT_PT },
            { "vga",       OPTION_VAL_VGA_PT_PT },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_PT_PT,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_PT_PT,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_PT_PT,
        NULL,
        XEMU_USE_DSP_INFO_0_PT_PT,
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
        XEMU_DSP_JIT_LABEL_PT_PT,
        NULL,
        XEMU_DSP_JIT_INFO_0_PT_PT,
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
        XEMU_HRTF_LABEL_PT_PT,
        NULL,
        XEMU_HRTF_INFO_0_PT_PT,
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
        XEMU_VP_WORKERS_LABEL_PT_PT,
        NULL,
        XEMU_VP_WORKERS_INFO_0_PT_PT,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_PT_PT },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_PT_PT,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_PT_PT,
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
        XEMU_AUDIO_VOLUME_LABEL_PT_PT,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_PT_PT,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_PT_PT },
            { "80",  OPTION_VAL_80_PT_PT },
            { "60",  OPTION_VAL_60_PT_PT },
            { "40",  OPTION_VAL_40_PT_PT },
            { "20",  OPTION_VAL_20_PT_PT },
            { "0",   OPTION_VAL_0_PT_PT },
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
        XEMU_VK_FAST_PATHS_LABEL_PT_PT,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_PT_PT },
            { "no_gpl",   OPTION_VAL_NO_GPL_PT_PT },
            { "no_dyn",   OPTION_VAL_NO_DYN_PT_PT },
            { "none",     OPTION_VAL_NONE_PT_PT },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_PT_PT,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_PT_PT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_PT_PT,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_PT_PT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_PT_PT,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_PT_PT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_PT_PT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_PT_PT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_PT_PT },
            { "15", OPTION_VAL_15_PT_PT },
            { "20", OPTION_VAL_20_PT_PT },
            { "25", OPTION_VAL_25_PT_PT },
            { "30", OPTION_VAL_30_PT_PT },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_PT_PT,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_PT_PT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_PT_PT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_PT_PT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_PT_PT },
            { "15", OPTION_VAL_15_PT_PT },
            { "20", OPTION_VAL_20_PT_PT },
            { "25", OPTION_VAL_25_PT_PT },
            { "30", OPTION_VAL_30_PT_PT },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_PT_PT,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_PT_PT,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_PT_PT,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_PT_PT,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_PT_PT },
            { "stick", OPTION_VAL_STICK_PT_PT },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_PT_PT,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_PT_PT,
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
        XEMU_CHIHIRO_FFB_LABEL_PT_PT,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_PT_PT,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_PT_PT },
            { "50",  OPTION_VAL_50_PT_PT },
            { "75",  OPTION_VAL_75_PT_PT },
            { "100", OPTION_VAL_100_PT_PT },
            { "150", OPTION_VAL_150_PT_PT },
            { "200", OPTION_VAL_200_PT_PT },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_pt_pt = {
   option_cats_pt_pt,
   option_defs_pt_pt
};

/* RETRO_LANGUAGE_RU */

#define CATEGORY_SYSTEM_LABEL_RU NULL
#define CATEGORY_SYSTEM_INFO_0_RU NULL
#define CATEGORY_VIDEO_LABEL_RU "Видео"
#define CATEGORY_VIDEO_INFO_0_RU NULL
#define CATEGORY_AUDIO_LABEL_RU "Аудио"
#define CATEGORY_AUDIO_INFO_0_RU NULL
#define CATEGORY_CONTROLS_LABEL_RU "Управление"
#define CATEGORY_CONTROLS_INFO_0_RU NULL
#define CATEGORY_CHIHIRO_LABEL_RU NULL
#define CATEGORY_CHIHIRO_INFO_0_RU NULL
#define XEMU_MEMORY_LABEL_RU NULL
#define XEMU_MEMORY_INFO_0_RU NULL
#define OPTION_VAL_64_RU NULL
#define OPTION_VAL_128_RU NULL
#define XEMU_NETWORK_BACKEND_LABEL_RU NULL
#define XEMU_NETWORK_BACKEND_INFO_0_RU NULL
#define OPTION_VAL_NAT_RU NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_RU NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_RU NULL
#define XEMU_HARD_FPU_LABEL_RU NULL
#define XEMU_HARD_FPU_INFO_0_RU NULL
#define XEMU_CPU_BOOST_LABEL_RU NULL
#define XEMU_CPU_BOOST_INFO_0_RU NULL
#define XEMU_HDD_TRIM_LABEL_RU NULL
#define XEMU_HDD_TRIM_INFO_0_RU NULL
#define XEMU_RENDERER_LABEL_RU NULL
#define XEMU_RENDERER_INFO_0_RU NULL
#define OPTION_VAL_VULKAN_RU NULL
#define OPTION_VAL_OPENGL_RU NULL
#define XEMU_VIDEO_ASPECT_LABEL_RU NULL
#define XEMU_VIDEO_ASPECT_INFO_0_RU NULL
#define OPTION_VAL_DASHBOARD_RU NULL
#define OPTION_VAL_4_3_RU NULL
#define OPTION_VAL_16_9_RU NULL
#define OPTION_VAL_LETTERBOX_RU NULL
#define XEMU_ASPECT_RATIO_LABEL_RU "Соотношение сторон ядра"
#define XEMU_ASPECT_RATIO_INFO_0_RU NULL
#define OPTION_VAL_AUTO_RU "Автоматически"
#define XEMU_SURFACE_SCALE_LABEL_RU NULL
#define XEMU_SURFACE_SCALE_INFO_0_RU NULL
#define OPTION_VAL_1_RU NULL
#define OPTION_VAL_2_RU NULL
#define OPTION_VAL_3_RU NULL
#define OPTION_VAL_4_RU NULL
#define OPTION_VAL_5_RU NULL
#define OPTION_VAL_6_RU NULL
#define OPTION_VAL_7_RU NULL
#define OPTION_VAL_8_RU NULL
#define OPTION_VAL_9_RU NULL
#define OPTION_VAL_10_RU NULL
#define XEMU_AVPACK_LABEL_RU NULL
#define XEMU_AVPACK_INFO_0_RU NULL
#define OPTION_VAL_HDTV_RU NULL
#define OPTION_VAL_COMPOSITE_RU "Композитный"
#define OPTION_VAL_SVIDEO_RU NULL
#define OPTION_VAL_SCART_RU NULL
#define OPTION_VAL_VGA_RU NULL
#define XEMU_AUDIO_THREAD_LABEL_RU NULL
#define XEMU_AUDIO_THREAD_INFO_0_RU NULL
#define XEMU_USE_DSP_LABEL_RU NULL
#define XEMU_USE_DSP_INFO_0_RU NULL
#define XEMU_DSP_JIT_LABEL_RU NULL
#define XEMU_DSP_JIT_INFO_0_RU NULL
#define XEMU_HRTF_LABEL_RU NULL
#define XEMU_HRTF_INFO_0_RU NULL
#define XEMU_VP_WORKERS_LABEL_RU NULL
#define XEMU_VP_WORKERS_INFO_0_RU NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_RU NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_RU NULL
#define XEMU_AUDIO_VOLUME_LABEL_RU NULL
#define XEMU_AUDIO_VOLUME_INFO_0_RU NULL
#define OPTION_VAL_100_RU NULL
#define OPTION_VAL_80_RU NULL
#define OPTION_VAL_60_RU NULL
#define OPTION_VAL_40_RU NULL
#define OPTION_VAL_20_RU NULL
#define OPTION_VAL_0_RU NULL
#define XEMU_VK_FAST_PATHS_LABEL_RU NULL
#define XEMU_VK_FAST_PATHS_INFO_0_RU NULL
#define OPTION_VAL_ALL_RU "Все"
#define OPTION_VAL_NO_GPL_RU NULL
#define OPTION_VAL_NO_DYN_RU NULL
#define OPTION_VAL_NONE_RU "Нет"
#define XEMU_RUMBLE_P1_LABEL_RU NULL
#define XEMU_RUMBLE_P1_INFO_0_RU NULL
#define XEMU_RUMBLE_P2_LABEL_RU NULL
#define XEMU_RUMBLE_P2_INFO_0_RU NULL
#define XEMU_DEADZONE_P1_LABEL_RU NULL
#define XEMU_DEADZONE_P1_INFO_0_RU NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_RU NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_RU NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_RU NULL
#define OPTION_VAL_15_RU NULL
#define OPTION_VAL_25_RU NULL
#define OPTION_VAL_30_RU NULL
#define XEMU_DEADZONE_P2_LABEL_RU NULL
#define XEMU_DEADZONE_P2_INFO_0_RU NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_RU NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_RU NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_RU NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_RU NULL
#define OPTION_VAL_MOUSE_RU "Мышь"
#define OPTION_VAL_STICK_RU NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_RU NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_RU NULL
#define XEMU_CHIHIRO_FFB_LABEL_RU NULL
#define XEMU_CHIHIRO_FFB_INFO_0_RU NULL
#define OPTION_VAL_50_RU NULL
#define OPTION_VAL_75_RU NULL
#define OPTION_VAL_150_RU NULL
#define OPTION_VAL_200_RU NULL

struct retro_core_option_v2_category option_cats_ru[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_RU,
        CATEGORY_SYSTEM_INFO_0_RU
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_RU,
        CATEGORY_VIDEO_INFO_0_RU
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_RU,
        CATEGORY_AUDIO_INFO_0_RU
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_RU,
        CATEGORY_CONTROLS_INFO_0_RU
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_RU,
        CATEGORY_CHIHIRO_INFO_0_RU
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ru[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_RU,
        NULL,
        XEMU_MEMORY_INFO_0_RU,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_RU },
            { "128", OPTION_VAL_128_RU },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_RU,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_RU,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_RU },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_RU,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_RU,
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
        XEMU_HARD_FPU_LABEL_RU,
        NULL,
        XEMU_HARD_FPU_INFO_0_RU,
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
        XEMU_CPU_BOOST_LABEL_RU,
        NULL,
        XEMU_CPU_BOOST_INFO_0_RU,
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
        XEMU_HDD_TRIM_LABEL_RU,
        NULL,
        XEMU_HDD_TRIM_INFO_0_RU,
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
        XEMU_RENDERER_LABEL_RU,
        NULL,
        XEMU_RENDERER_INFO_0_RU,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_RU },
            { "opengl", OPTION_VAL_OPENGL_RU },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_RU,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_RU,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_RU },
            { "4:3",       OPTION_VAL_4_3_RU },
            { "16:9",      OPTION_VAL_16_9_RU },
            { "letterbox", OPTION_VAL_LETTERBOX_RU },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_RU,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_RU,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_RU },
            { "4:3",  OPTION_VAL_4_3_RU },
            { "16:9", OPTION_VAL_16_9_RU },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_RU,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_RU,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_RU },
            { "2", OPTION_VAL_2_RU },
            { "3", OPTION_VAL_3_RU },
            { "4", OPTION_VAL_4_RU },
            { "5", OPTION_VAL_5_RU },
            { "6", OPTION_VAL_6_RU },
            { "7", OPTION_VAL_7_RU },
            { "8", OPTION_VAL_8_RU },
            { "9", OPTION_VAL_9_RU },
            { "10", OPTION_VAL_10_RU },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_RU,
        NULL,
        XEMU_AVPACK_INFO_0_RU,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_RU },
            { "composite", OPTION_VAL_COMPOSITE_RU },
            { "svideo",    OPTION_VAL_SVIDEO_RU },
            { "scart",     OPTION_VAL_SCART_RU },
            { "vga",       OPTION_VAL_VGA_RU },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_RU,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_RU,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_RU,
        NULL,
        XEMU_USE_DSP_INFO_0_RU,
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
        XEMU_DSP_JIT_LABEL_RU,
        NULL,
        XEMU_DSP_JIT_INFO_0_RU,
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
        XEMU_HRTF_LABEL_RU,
        NULL,
        XEMU_HRTF_INFO_0_RU,
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
        XEMU_VP_WORKERS_LABEL_RU,
        NULL,
        XEMU_VP_WORKERS_INFO_0_RU,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_RU },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_RU,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_RU,
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
        XEMU_AUDIO_VOLUME_LABEL_RU,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_RU,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_RU },
            { "80",  OPTION_VAL_80_RU },
            { "60",  OPTION_VAL_60_RU },
            { "40",  OPTION_VAL_40_RU },
            { "20",  OPTION_VAL_20_RU },
            { "0",   OPTION_VAL_0_RU },
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
        XEMU_VK_FAST_PATHS_LABEL_RU,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_RU,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_RU },
            { "no_gpl",   OPTION_VAL_NO_GPL_RU },
            { "no_dyn",   OPTION_VAL_NO_DYN_RU },
            { "none",     OPTION_VAL_NONE_RU },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_RU,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_RU,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_RU,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_RU,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_RU,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_RU,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_RU },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_RU },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_RU },
            { "15", OPTION_VAL_15_RU },
            { "20", OPTION_VAL_20_RU },
            { "25", OPTION_VAL_25_RU },
            { "30", OPTION_VAL_30_RU },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_RU,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_RU,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_RU },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_RU },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_RU },
            { "15", OPTION_VAL_15_RU },
            { "20", OPTION_VAL_20_RU },
            { "25", OPTION_VAL_25_RU },
            { "30", OPTION_VAL_30_RU },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_RU,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_RU,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_RU,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_RU,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_RU },
            { "stick", OPTION_VAL_STICK_RU },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_RU,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_RU,
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
        XEMU_CHIHIRO_FFB_LABEL_RU,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_RU,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_RU },
            { "50",  OPTION_VAL_50_RU },
            { "75",  OPTION_VAL_75_RU },
            { "100", OPTION_VAL_100_RU },
            { "150", OPTION_VAL_150_RU },
            { "200", OPTION_VAL_200_RU },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ru = {
   option_cats_ru,
   option_defs_ru
};

/* RETRO_LANGUAGE_SK */

#define CATEGORY_SYSTEM_LABEL_SK "Systém (reštart)"
#define CATEGORY_SYSTEM_INFO_0_SK "Samotný stroj: pamäť, sieť, štart a procesor. Berie sa pri spustení obsahu (Orezať HDD pri zatvorení pri jeho zatvorení)."
#define CATEGORY_VIDEO_LABEL_SK NULL
#define CATEGORY_VIDEO_INFO_0_SK "Nastavenia vykresľovania videa."
#define CATEGORY_AUDIO_LABEL_SK "Zvuk"
#define CATEGORY_AUDIO_INFO_0_SK "Nastavenia emulácie zvuku."
#define CATEGORY_CONTROLS_LABEL_SK "Ovládanie"
#define CATEGORY_CONTROLS_INFO_0_SK "Vibrácie a mŕtva zóna páčok, pre každého hráča."
#define CATEGORY_CHIHIRO_LABEL_SK NULL
#define CATEGORY_CHIHIRO_INFO_0_SK "Arkádové hry Sega Chihiro: hra zadarmo, mierenie v strieľačkách a spätná väzba v pretekárskych hrách."
#define XEMU_MEMORY_LABEL_SK "Systémová pamäť (MB)"
#define XEMU_MEMORY_INFO_0_SK "Veľkosť systémovej RAM. 64 MB je štandard; 128 MB používajú vývojárske súpravy."
#define OPTION_VAL_64_SK NULL
#define OPTION_VAL_128_SK NULL
#define XEMU_NETWORK_BACKEND_LABEL_SK "Sieťový backend"
#define XEMU_NETWORK_BACKEND_INFO_0_SK "Zapne podporu siete pre hry Xbox s funkciami LAN/System Link. Backend NAT poskytuje základnú konektivitu."
#define OPTION_VAL_NAT_SK NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_SK "Preskočiť úvodnú animáciu"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_SK "Preskočí úvodnú animáciu Xboxu."
#define XEMU_HARD_FPU_LABEL_SK "Hardvérová emulácia FPU"
#define XEMU_HARD_FPU_INFO_0_SK "Použije FPU hostiteľa na emuláciu x87. Rýchlejšie, ale môže mať drobné nepresnosti."
#define XEMU_CPU_BOOST_LABEL_SK "Zrýchlenie CPU"
#define XEMU_CPU_BOOST_INFO_0_SK "Rýchlejšie cesty pre emulovaný procesor a zvukový procesor: natívne SSE a väčšia vyrovnávacia pamäť skokov. Vypnite, ak sa hra správa nesprávne."
#define XEMU_HDD_TRIM_LABEL_SK "Orezať HDD pri zatvorení"
#define XEMU_HDD_TRIM_INFO_0_SK "Po zatvorení hry vyprázdni vyrovnávacie oddiely X, Y a Z pevného disku (hry ich pri potrebe znova naformátujú) a prepíše obraz bez nevyužitého miesta, takže súbor sa zmenší. Na chvíľu potrebuje toľko voľného miesta, koľko dát obraz obsahuje. Preskočí sa, kým obraz obsahuje savestate. Robí sa pri zatvorení hry, nie pri jej ďalšom spustení."
#define XEMU_RENDERER_LABEL_SK "Grafické API (reštart)"
#define XEMU_RENDERER_INFO_0_SK "Renderer, ktorým sa kreslí emulované GPU. Vulkan je predvolený; OpenGL je záloha pre ovládače, kde Vulkan nefunguje správne. Prejaví sa po reštarte RetroArchu. Android vždy používa Vulkan, macOS vždy OpenGL."
#define OPTION_VAL_VULKAN_SK NULL
#define OPTION_VAL_OPENGL_SK NULL
#define XEMU_VIDEO_ASPECT_LABEL_SK "Systémový pomer strán (reštart)"
#define XEMU_VIDEO_ASPECT_INFO_0_SK "Tvar obrazovky, ktorý video nastavenia konzoly hlásia hrám, namiesto nastavenia v dashboarde. Pri 16:9 bežia hry podporujúce široký obraz v širokom obraze, pri 4:3 v 4:3. Nastavte podľa tvaru vášho displeja. Letterbox je 4:3 z dashboardu s hrami v širokom obraze s čiernymi pruhmi. Dashboard ponechá nastavenie dashboardu."
#define OPTION_VAL_DASHBOARD_SK NULL
#define OPTION_VAL_4_3_SK NULL
#define OPTION_VAL_16_9_SK NULL
#define OPTION_VAL_LETTERBOX_SK NULL
#define XEMU_ASPECT_RATIO_LABEL_SK "Pomer strán jadra"
#define XEMU_ASPECT_RATIO_INFO_0_SK "Tvar, v ktorom sa obraz zobrazuje. Najlepšie je nechať Auto, ktoré sa riadi hrou: 16:9, keď je konzola nastavená na široký obraz (Systémový pomer strán alebo dashboard) a hra vykresľuje 16:9, inak 4:3, a na Chihiro tiež 4:3. 16:9 roztiahne hru v 4:3 na široký obraz."
#define OPTION_VAL_AUTO_SK NULL
#define XEMU_SURFACE_SCALE_LABEL_SK "Mierka interného rozlíšenia (reštart)"
#define XEMU_SURFACE_SCALE_INFO_0_SK "Škáluje interné rozlíšenie vykresľovania. Vyššie hodnoty zlepšujú kvalitu, ale znižujú výkon."
#define OPTION_VAL_1_SK NULL
#define OPTION_VAL_2_SK NULL
#define OPTION_VAL_3_SK NULL
#define OPTION_VAL_4_SK NULL
#define OPTION_VAL_5_SK NULL
#define OPTION_VAL_6_SK NULL
#define OPTION_VAL_7_SK NULL
#define OPTION_VAL_8_SK NULL
#define OPTION_VAL_9_SK NULL
#define OPTION_VAL_10_SK NULL
#define XEMU_AVPACK_LABEL_SK "AV kábel (reštart)"
#define XEMU_AVPACK_INFO_0_SK "Vyberte typ AV Packu. Ovplyvňuje dostupné režimy videa."
#define OPTION_VAL_HDTV_SK NULL
#define OPTION_VAL_COMPOSITE_SK "Kompozit"
#define OPTION_VAL_SVIDEO_SK NULL
#define OPTION_VAL_SCART_SK NULL
#define OPTION_VAL_VGA_SK NULL
#define XEMU_AUDIO_THREAD_LABEL_SK "Zvukové vlákno (reštart)"
#define XEMU_AUDIO_THREAD_INFO_0_SK "Odovzdáva zvuk zvukovému vláknu RetroArchu tak, ako ho APU mixuje, ako ho prehráva samostatné xemu, namiesto dávky jednej snímky za snímku: zvuk pokračuje, aj keď sa snímky zastavia, napríklad pri kompilácii shaderov."
#define XEMU_USE_DSP_LABEL_SK "Emulácia DSP v APU"
#define XEMU_USE_DSP_INFO_0_SK "Zapne emuláciu DSP pre presnejší zvuk. Môže ovplyvniť výkon."
#define XEMU_DSP_JIT_LABEL_SK NULL
#define XEMU_DSP_JIT_INFO_0_SK "Spúšťa programy Emulácie DSP v APU ako skompilovaný kód namiesto ich interpretovania: rýchlejšie, ako DSP JIT samostatného xemu. Prejaví sa iba so zapnutou Emuláciou DSP v APU."
#define XEMU_HRTF_LABEL_SK NULL
#define XEMU_HRTF_INFO_0_SK "Umiestňuje 3D hlasy hier, ktoré ich používajú, pomocou funkcií prenosu vzhľadom na hlavu, ako na konzole, pre slúchadlá a stereo reproduktory."
#define XEMU_VP_WORKERS_LABEL_SK "Vlákna hlasového procesora (reštart)"
#define XEMU_VP_WORKERS_INFO_0_SK "Vlákna, na ktorých zvukový hlasový procesor mixuje hlasy. Auto použije jedno na každé jadro procesora."
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_SK "Plynulé prvé hranie (reštart)"
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_SK "Počas štartu hry skompiluje shadery, o ktorých je známe, že ich hra používa, aby sa prvé minúty nesekali pri ich kompilácii. Na OpenGL uchová to, čo skompiluje, vo vyrovnávacej pamäti shaderov, ktorá je vždy zapnutá."
#define XEMU_AUDIO_VOLUME_LABEL_SK "Limit hlasitosti zvuku (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_SK "Obmedzí hlasitosť zvukového výstupu Xboxu nezávisle od hlavnej hlasitosti RetroArchu."
#define OPTION_VAL_100_SK NULL
#define OPTION_VAL_80_SK NULL
#define OPTION_VAL_60_SK NULL
#define OPTION_VAL_40_SK NULL
#define OPTION_VAL_20_SK NULL
#define OPTION_VAL_0_SK "Stlmené"
#define XEMU_VK_FAST_PATHS_LABEL_SK "Rýchle cesty Vulkanu (reštart)"
#define XEMU_VK_FAST_PATHS_INFO_0_SK "Ovplyvňuje rýchlosť kompilácie shaderov na Vulkane. „Všetko“ je najrýchlejšie, ale niektoré hry môže zhodiť."
#define OPTION_VAL_ALL_SK "Všetko"
#define OPTION_VAL_NO_GPL_SK "Bez knižníc pipeline"
#define OPTION_VAL_NO_DYN_SK "Bez dynamických stavov"
#define OPTION_VAL_NONE_SK "Žiadne"
#define XEMU_RUMBLE_P1_LABEL_SK "Vibrácie (hráč 1)"
#define XEMU_RUMBLE_P1_INFO_0_SK "Gamepad hráča 1 vibruje z hier pre Xbox aj zo spätnej väzby pretekárskych hier Chihiro. Vypnuté: ani jedno."
#define XEMU_RUMBLE_P2_LABEL_SK "Vibrácie (hráč 2)"
#define XEMU_RUMBLE_P2_INFO_0_SK "Gamepad hráča 2 vibruje z hier pre Xbox aj zo spätnej väzby pretekárskych hier Chihiro. Vypnuté: ani jedno."
#define XEMU_DEADZONE_P1_LABEL_SK "Mŕtva zóna analógu (hráč 1)"
#define XEMU_DEADZONE_P1_INFO_0_SK "Ako ďaleko sa dajú páčky hráča 1 vychýliť, kým to hra zaregistruje, obe páčky, na Xboxe aj na Chihiro; zvyšok pohybu sa roztiahne na celý rozsah."
#define OPTION_VAL_0_XEMU_DEADZONE_P1_SK NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_SK NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_SK NULL
#define OPTION_VAL_15_SK NULL
#define OPTION_VAL_25_SK NULL
#define OPTION_VAL_30_SK NULL
#define XEMU_DEADZONE_P2_LABEL_SK "Mŕtva zóna analógu (hráč 2)"
#define XEMU_DEADZONE_P2_INFO_0_SK "Ako ďaleko sa dajú páčky hráča 2 vychýliť, kým to hra zaregistruje, obe páčky, na Xboxe aj na Chihiro; zvyšok pohybu sa roztiahne na celý rozsah."
#define XEMU_CHIHIRO_FREEPLAY_LABEL_SK "Hra zadarmo (reštart)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_SK "Spustí hry Sega Chihiro v režime hry zadarmo, bez mincí. Vypnuté: Select vhodí mincu."
#define XEMU_CHIHIRO_GUN_AIM_LABEL_SK "Mierenie svetelnej pištole"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_SK "Čím sa mieri v House of the Dead III, Virtua Cop 3 a Ghost Squad. Myš: mieri myš (alebo svetelná pištoľ RetroArchu), ľavé tlačidlo strieľa, pravé je tlačidlo pištole (prebitie, zmena zbrane), stredné pedál alebo rýchlosť streľby. Analógová páčka: mieri ľavá páčka alebo D-pad, R2 strieľa, L2 je tlačidlo pištole, L pedál alebo rýchlosť streľby, R strieľa mimo obrazovky."
#define OPTION_VAL_MOUSE_SK "Myš"
#define OPTION_VAL_STICK_SK "Analógová páčka"
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_SK "Zameriavač"
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_SK "Vykreslí mierenie každého hráča cez obraz, hráč 1 červený, hráč 2 modrý."
#define XEMU_CHIHIRO_FFB_LABEL_SK "Spätná väzba ako vibrácie"
#define XEMU_CHIHIRO_FFB_INFO_0_SK "Spätnú väzbu pretekárskych hier Chihiro (OutRun 2, Maximum Tune) dáva ako vibrácie na gamepad portu 1, s touto silou."
#define OPTION_VAL_50_SK NULL
#define OPTION_VAL_75_SK NULL
#define OPTION_VAL_150_SK NULL
#define OPTION_VAL_200_SK NULL

struct retro_core_option_v2_category option_cats_sk[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_SK,
        CATEGORY_SYSTEM_INFO_0_SK
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_SK,
        CATEGORY_VIDEO_INFO_0_SK
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_SK,
        CATEGORY_AUDIO_INFO_0_SK
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_SK,
        CATEGORY_CONTROLS_INFO_0_SK
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_SK,
        CATEGORY_CHIHIRO_INFO_0_SK
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sk[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_SK,
        NULL,
        XEMU_MEMORY_INFO_0_SK,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_SK },
            { "128", OPTION_VAL_128_SK },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_SK,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_SK,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_SK },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_SK,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_SK,
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
        XEMU_HARD_FPU_LABEL_SK,
        NULL,
        XEMU_HARD_FPU_INFO_0_SK,
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
        XEMU_CPU_BOOST_LABEL_SK,
        NULL,
        XEMU_CPU_BOOST_INFO_0_SK,
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
        XEMU_HDD_TRIM_LABEL_SK,
        NULL,
        XEMU_HDD_TRIM_INFO_0_SK,
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
        XEMU_RENDERER_LABEL_SK,
        NULL,
        XEMU_RENDERER_INFO_0_SK,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_SK },
            { "opengl", OPTION_VAL_OPENGL_SK },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_SK,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_SK,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_SK },
            { "4:3",       OPTION_VAL_4_3_SK },
            { "16:9",      OPTION_VAL_16_9_SK },
            { "letterbox", OPTION_VAL_LETTERBOX_SK },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_SK,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_SK,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_SK },
            { "4:3",  OPTION_VAL_4_3_SK },
            { "16:9", OPTION_VAL_16_9_SK },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_SK,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_SK,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_SK },
            { "2", OPTION_VAL_2_SK },
            { "3", OPTION_VAL_3_SK },
            { "4", OPTION_VAL_4_SK },
            { "5", OPTION_VAL_5_SK },
            { "6", OPTION_VAL_6_SK },
            { "7", OPTION_VAL_7_SK },
            { "8", OPTION_VAL_8_SK },
            { "9", OPTION_VAL_9_SK },
            { "10", OPTION_VAL_10_SK },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_SK,
        NULL,
        XEMU_AVPACK_INFO_0_SK,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_SK },
            { "composite", OPTION_VAL_COMPOSITE_SK },
            { "svideo",    OPTION_VAL_SVIDEO_SK },
            { "scart",     OPTION_VAL_SCART_SK },
            { "vga",       OPTION_VAL_VGA_SK },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_SK,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_SK,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_SK,
        NULL,
        XEMU_USE_DSP_INFO_0_SK,
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
        XEMU_DSP_JIT_LABEL_SK,
        NULL,
        XEMU_DSP_JIT_INFO_0_SK,
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
        XEMU_HRTF_LABEL_SK,
        NULL,
        XEMU_HRTF_INFO_0_SK,
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
        XEMU_VP_WORKERS_LABEL_SK,
        NULL,
        XEMU_VP_WORKERS_INFO_0_SK,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_SK },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_SK,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_SK,
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
        XEMU_AUDIO_VOLUME_LABEL_SK,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_SK,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_SK },
            { "80",  OPTION_VAL_80_SK },
            { "60",  OPTION_VAL_60_SK },
            { "40",  OPTION_VAL_40_SK },
            { "20",  OPTION_VAL_20_SK },
            { "0",   OPTION_VAL_0_SK },
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
        XEMU_VK_FAST_PATHS_LABEL_SK,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_SK,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_SK },
            { "no_gpl",   OPTION_VAL_NO_GPL_SK },
            { "no_dyn",   OPTION_VAL_NO_DYN_SK },
            { "none",     OPTION_VAL_NONE_SK },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_SK,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_SK,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_SK,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_SK,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_SK,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_SK,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_SK },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_SK },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_SK },
            { "15", OPTION_VAL_15_SK },
            { "20", OPTION_VAL_20_SK },
            { "25", OPTION_VAL_25_SK },
            { "30", OPTION_VAL_30_SK },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_SK,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_SK,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_SK },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_SK },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_SK },
            { "15", OPTION_VAL_15_SK },
            { "20", OPTION_VAL_20_SK },
            { "25", OPTION_VAL_25_SK },
            { "30", OPTION_VAL_30_SK },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_SK,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_SK,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_SK,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_SK,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_SK },
            { "stick", OPTION_VAL_STICK_SK },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_SK,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_SK,
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
        XEMU_CHIHIRO_FFB_LABEL_SK,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_SK,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_SK },
            { "50",  OPTION_VAL_50_SK },
            { "75",  OPTION_VAL_75_SK },
            { "100", OPTION_VAL_100_SK },
            { "150", OPTION_VAL_150_SK },
            { "200", OPTION_VAL_200_SK },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_sk = {
   option_cats_sk,
   option_defs_sk
};

/* RETRO_LANGUAGE_SR */

#define CATEGORY_SYSTEM_LABEL_SR NULL
#define CATEGORY_SYSTEM_INFO_0_SR NULL
#define CATEGORY_VIDEO_LABEL_SR NULL
#define CATEGORY_VIDEO_INFO_0_SR NULL
#define CATEGORY_AUDIO_LABEL_SR "Zvuk"
#define CATEGORY_AUDIO_INFO_0_SR NULL
#define CATEGORY_CONTROLS_LABEL_SR NULL
#define CATEGORY_CONTROLS_INFO_0_SR NULL
#define CATEGORY_CHIHIRO_LABEL_SR NULL
#define CATEGORY_CHIHIRO_INFO_0_SR NULL
#define XEMU_MEMORY_LABEL_SR NULL
#define XEMU_MEMORY_INFO_0_SR NULL
#define OPTION_VAL_64_SR NULL
#define OPTION_VAL_128_SR NULL
#define XEMU_NETWORK_BACKEND_LABEL_SR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_SR NULL
#define OPTION_VAL_NAT_SR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_SR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_SR NULL
#define XEMU_HARD_FPU_LABEL_SR NULL
#define XEMU_HARD_FPU_INFO_0_SR NULL
#define XEMU_CPU_BOOST_LABEL_SR NULL
#define XEMU_CPU_BOOST_INFO_0_SR NULL
#define XEMU_HDD_TRIM_LABEL_SR NULL
#define XEMU_HDD_TRIM_INFO_0_SR NULL
#define XEMU_RENDERER_LABEL_SR NULL
#define XEMU_RENDERER_INFO_0_SR NULL
#define OPTION_VAL_VULKAN_SR NULL
#define OPTION_VAL_OPENGL_SR NULL
#define XEMU_VIDEO_ASPECT_LABEL_SR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_SR NULL
#define OPTION_VAL_DASHBOARD_SR NULL
#define OPTION_VAL_4_3_SR NULL
#define OPTION_VAL_16_9_SR NULL
#define OPTION_VAL_LETTERBOX_SR NULL
#define XEMU_ASPECT_RATIO_LABEL_SR NULL
#define XEMU_ASPECT_RATIO_INFO_0_SR NULL
#define OPTION_VAL_AUTO_SR NULL
#define XEMU_SURFACE_SCALE_LABEL_SR NULL
#define XEMU_SURFACE_SCALE_INFO_0_SR NULL
#define OPTION_VAL_1_SR NULL
#define OPTION_VAL_2_SR NULL
#define OPTION_VAL_3_SR NULL
#define OPTION_VAL_4_SR NULL
#define OPTION_VAL_5_SR NULL
#define OPTION_VAL_6_SR NULL
#define OPTION_VAL_7_SR NULL
#define OPTION_VAL_8_SR NULL
#define OPTION_VAL_9_SR NULL
#define OPTION_VAL_10_SR NULL
#define XEMU_AVPACK_LABEL_SR NULL
#define XEMU_AVPACK_INFO_0_SR NULL
#define OPTION_VAL_HDTV_SR NULL
#define OPTION_VAL_COMPOSITE_SR NULL
#define OPTION_VAL_SVIDEO_SR NULL
#define OPTION_VAL_SCART_SR NULL
#define OPTION_VAL_VGA_SR NULL
#define XEMU_AUDIO_THREAD_LABEL_SR NULL
#define XEMU_AUDIO_THREAD_INFO_0_SR NULL
#define XEMU_USE_DSP_LABEL_SR NULL
#define XEMU_USE_DSP_INFO_0_SR NULL
#define XEMU_DSP_JIT_LABEL_SR NULL
#define XEMU_DSP_JIT_INFO_0_SR NULL
#define XEMU_HRTF_LABEL_SR NULL
#define XEMU_HRTF_INFO_0_SR NULL
#define XEMU_VP_WORKERS_LABEL_SR NULL
#define XEMU_VP_WORKERS_INFO_0_SR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_SR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_SR NULL
#define XEMU_AUDIO_VOLUME_LABEL_SR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_SR NULL
#define OPTION_VAL_100_SR NULL
#define OPTION_VAL_80_SR NULL
#define OPTION_VAL_60_SR NULL
#define OPTION_VAL_40_SR NULL
#define OPTION_VAL_20_SR NULL
#define OPTION_VAL_0_SR NULL
#define XEMU_VK_FAST_PATHS_LABEL_SR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_SR NULL
#define OPTION_VAL_ALL_SR NULL
#define OPTION_VAL_NO_GPL_SR NULL
#define OPTION_VAL_NO_DYN_SR NULL
#define OPTION_VAL_NONE_SR NULL
#define XEMU_RUMBLE_P1_LABEL_SR NULL
#define XEMU_RUMBLE_P1_INFO_0_SR NULL
#define XEMU_RUMBLE_P2_LABEL_SR NULL
#define XEMU_RUMBLE_P2_INFO_0_SR NULL
#define XEMU_DEADZONE_P1_LABEL_SR NULL
#define XEMU_DEADZONE_P1_INFO_0_SR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_SR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_SR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_SR NULL
#define OPTION_VAL_15_SR NULL
#define OPTION_VAL_25_SR NULL
#define OPTION_VAL_30_SR NULL
#define XEMU_DEADZONE_P2_LABEL_SR NULL
#define XEMU_DEADZONE_P2_INFO_0_SR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_SR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_SR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_SR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_SR NULL
#define OPTION_VAL_MOUSE_SR NULL
#define OPTION_VAL_STICK_SR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_SR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_SR NULL
#define XEMU_CHIHIRO_FFB_LABEL_SR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_SR NULL
#define OPTION_VAL_50_SR NULL
#define OPTION_VAL_75_SR NULL
#define OPTION_VAL_150_SR NULL
#define OPTION_VAL_200_SR NULL

struct retro_core_option_v2_category option_cats_sr[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_SR,
        CATEGORY_SYSTEM_INFO_0_SR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_SR,
        CATEGORY_VIDEO_INFO_0_SR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_SR,
        CATEGORY_AUDIO_INFO_0_SR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_SR,
        CATEGORY_CONTROLS_INFO_0_SR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_SR,
        CATEGORY_CHIHIRO_INFO_0_SR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sr[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_SR,
        NULL,
        XEMU_MEMORY_INFO_0_SR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_SR },
            { "128", OPTION_VAL_128_SR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_SR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_SR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_SR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_SR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_SR,
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
        XEMU_HARD_FPU_LABEL_SR,
        NULL,
        XEMU_HARD_FPU_INFO_0_SR,
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
        XEMU_CPU_BOOST_LABEL_SR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_SR,
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
        XEMU_HDD_TRIM_LABEL_SR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_SR,
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
        XEMU_RENDERER_LABEL_SR,
        NULL,
        XEMU_RENDERER_INFO_0_SR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_SR },
            { "opengl", OPTION_VAL_OPENGL_SR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_SR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_SR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_SR },
            { "4:3",       OPTION_VAL_4_3_SR },
            { "16:9",      OPTION_VAL_16_9_SR },
            { "letterbox", OPTION_VAL_LETTERBOX_SR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_SR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_SR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_SR },
            { "4:3",  OPTION_VAL_4_3_SR },
            { "16:9", OPTION_VAL_16_9_SR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_SR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_SR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_SR },
            { "2", OPTION_VAL_2_SR },
            { "3", OPTION_VAL_3_SR },
            { "4", OPTION_VAL_4_SR },
            { "5", OPTION_VAL_5_SR },
            { "6", OPTION_VAL_6_SR },
            { "7", OPTION_VAL_7_SR },
            { "8", OPTION_VAL_8_SR },
            { "9", OPTION_VAL_9_SR },
            { "10", OPTION_VAL_10_SR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_SR,
        NULL,
        XEMU_AVPACK_INFO_0_SR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_SR },
            { "composite", OPTION_VAL_COMPOSITE_SR },
            { "svideo",    OPTION_VAL_SVIDEO_SR },
            { "scart",     OPTION_VAL_SCART_SR },
            { "vga",       OPTION_VAL_VGA_SR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_SR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_SR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_SR,
        NULL,
        XEMU_USE_DSP_INFO_0_SR,
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
        XEMU_DSP_JIT_LABEL_SR,
        NULL,
        XEMU_DSP_JIT_INFO_0_SR,
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
        XEMU_HRTF_LABEL_SR,
        NULL,
        XEMU_HRTF_INFO_0_SR,
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
        XEMU_VP_WORKERS_LABEL_SR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_SR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_SR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_SR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_SR,
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
        XEMU_AUDIO_VOLUME_LABEL_SR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_SR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_SR },
            { "80",  OPTION_VAL_80_SR },
            { "60",  OPTION_VAL_60_SR },
            { "40",  OPTION_VAL_40_SR },
            { "20",  OPTION_VAL_20_SR },
            { "0",   OPTION_VAL_0_SR },
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
        XEMU_VK_FAST_PATHS_LABEL_SR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_SR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_SR },
            { "no_gpl",   OPTION_VAL_NO_GPL_SR },
            { "no_dyn",   OPTION_VAL_NO_DYN_SR },
            { "none",     OPTION_VAL_NONE_SR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_SR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_SR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_SR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_SR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_SR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_SR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_SR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_SR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_SR },
            { "15", OPTION_VAL_15_SR },
            { "20", OPTION_VAL_20_SR },
            { "25", OPTION_VAL_25_SR },
            { "30", OPTION_VAL_30_SR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_SR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_SR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_SR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_SR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_SR },
            { "15", OPTION_VAL_15_SR },
            { "20", OPTION_VAL_20_SR },
            { "25", OPTION_VAL_25_SR },
            { "30", OPTION_VAL_30_SR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_SR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_SR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_SR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_SR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_SR },
            { "stick", OPTION_VAL_STICK_SR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_SR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_SR,
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
        XEMU_CHIHIRO_FFB_LABEL_SR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_SR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_SR },
            { "50",  OPTION_VAL_50_SR },
            { "75",  OPTION_VAL_75_SR },
            { "100", OPTION_VAL_100_SR },
            { "150", OPTION_VAL_150_SR },
            { "200", OPTION_VAL_200_SR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_sr = {
   option_cats_sr,
   option_defs_sr
};

/* RETRO_LANGUAGE_SV */

#define CATEGORY_SYSTEM_LABEL_SV NULL
#define CATEGORY_SYSTEM_INFO_0_SV NULL
#define CATEGORY_VIDEO_LABEL_SV NULL
#define CATEGORY_VIDEO_INFO_0_SV "Konfigurera inställningar för videorendering."
#define CATEGORY_AUDIO_LABEL_SV "Ljud"
#define CATEGORY_AUDIO_INFO_0_SV "Konfigurera inställningar för ljudemulering."
#define CATEGORY_CONTROLS_LABEL_SV "Spelkontroller"
#define CATEGORY_CONTROLS_INFO_0_SV NULL
#define CATEGORY_CHIHIRO_LABEL_SV NULL
#define CATEGORY_CHIHIRO_INFO_0_SV "Sega Chihiro-arkadspel: gratisspel, sikte i skjutspel och kraftåterkoppling i racingspel."
#define XEMU_MEMORY_LABEL_SV "Systemminne (MB)"
#define XEMU_MEMORY_INFO_0_SV "Mängd system-RAM. 64 MB är standard; 128 MB används av utvecklingskit."
#define OPTION_VAL_64_SV NULL
#define OPTION_VAL_128_SV NULL
#define XEMU_NETWORK_BACKEND_LABEL_SV "Nätverksbakände"
#define XEMU_NETWORK_BACKEND_INFO_0_SV "Aktivera nätverksstöd för Xbox-spel med LAN- och System Link-funktioner. NAT-bakänden ger grundläggande anslutning."
#define OPTION_VAL_NAT_SV NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_SV "Hoppa över startanimering"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_SV "Hoppa över Xbox-startanimeringen."
#define XEMU_HARD_FPU_LABEL_SV "Maskinvaruemulering av FPU"
#define XEMU_HARD_FPU_INFO_0_SV "Använd värdsystemets FPU för x87-emulering. Det går snabbare men kan ge mindre avvikelser."
#define XEMU_CPU_BOOST_LABEL_SV NULL
#define XEMU_CPU_BOOST_INFO_0_SV "Snabbare kodvägar för gästprocessorn och ljudprocessorn: inbyggd SSE och en större hoppcache. Stäng av om ett spel inte fungerar som det ska."
#define XEMU_HDD_TRIM_LABEL_SV NULL
#define XEMU_HDD_TRIM_INFO_0_SV NULL
#define XEMU_RENDERER_LABEL_SV "Grafik-API (omstart)"
#define XEMU_RENDERER_INFO_0_SV "Den renderare som används för den emulerade GPU:n. Vulkan är standard; OpenGL används när Vulkan inte fungerar korrekt med grafikdrivrutinen. Ändringen börjar gälla när RetroArch har startats om. Android använder alltid Vulkan och macOS alltid OpenGL."
#define OPTION_VAL_VULKAN_SV NULL
#define OPTION_VAL_OPENGL_SV NULL
#define XEMU_VIDEO_ASPECT_LABEL_SV NULL
#define XEMU_VIDEO_ASPECT_INFO_0_SV NULL
#define OPTION_VAL_DASHBOARD_SV NULL
#define OPTION_VAL_4_3_SV NULL
#define OPTION_VAL_16_9_SV NULL
#define OPTION_VAL_LETTERBOX_SV NULL
#define XEMU_ASPECT_RATIO_LABEL_SV "Kärnspecifikt bildformat"
#define XEMU_ASPECT_RATIO_INFO_0_SV NULL
#define OPTION_VAL_AUTO_SV "Automatiskt"
#define XEMU_SURFACE_SCALE_LABEL_SV NULL
#define XEMU_SURFACE_SCALE_INFO_0_SV "Skalar den interna renderingsupplösningen. Högre värden förbättrar kvaliteten men minskar prestandan."
#define OPTION_VAL_1_SV NULL
#define OPTION_VAL_2_SV NULL
#define OPTION_VAL_3_SV NULL
#define OPTION_VAL_4_SV NULL
#define OPTION_VAL_5_SV NULL
#define OPTION_VAL_6_SV NULL
#define OPTION_VAL_7_SV NULL
#define OPTION_VAL_8_SV NULL
#define OPTION_VAL_9_SV NULL
#define OPTION_VAL_10_SV NULL
#define XEMU_AVPACK_LABEL_SV NULL
#define XEMU_AVPACK_INFO_0_SV "Välj AV-paketets typ. Påverkar tillgängliga videolägen."
#define OPTION_VAL_HDTV_SV NULL
#define OPTION_VAL_COMPOSITE_SV "Komposit"
#define OPTION_VAL_SVIDEO_SV NULL
#define OPTION_VAL_SCART_SV NULL
#define OPTION_VAL_VGA_SV NULL
#define XEMU_AUDIO_THREAD_LABEL_SV "Ljudtråd (starta om)"
#define XEMU_AUDIO_THREAD_INFO_0_SV NULL
#define XEMU_USE_DSP_LABEL_SV "Emulering av APU-DSP"
#define XEMU_USE_DSP_INFO_0_SV "Aktivera DSP-emulering för bättre ljudnoggrannhet. Kan påverka prestandan."
#define XEMU_DSP_JIT_LABEL_SV NULL
#define XEMU_DSP_JIT_INFO_0_SV NULL
#define XEMU_HRTF_LABEL_SV NULL
#define XEMU_HRTF_INFO_0_SV NULL
#define XEMU_VP_WORKERS_LABEL_SV NULL
#define XEMU_VP_WORKERS_INFO_0_SV NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_SV "Jämn första spelstart (omstart)"
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_SV NULL
#define XEMU_AUDIO_VOLUME_LABEL_SV "Ljudvolymgräns (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_SV "Begränsa Xbox-ljudutgångens volym oberoende av RetroArchs huvudvolym."
#define OPTION_VAL_100_SV NULL
#define OPTION_VAL_80_SV NULL
#define OPTION_VAL_60_SV NULL
#define OPTION_VAL_40_SV NULL
#define OPTION_VAL_20_SV NULL
#define OPTION_VAL_0_SV "Avstängd"
#define XEMU_VK_FAST_PATHS_LABEL_SV "Snabba Vulkan-kodvägar (omstart)"
#define XEMU_VK_FAST_PATHS_INFO_0_SV NULL
#define OPTION_VAL_ALL_SV "Alla"
#define OPTION_VAL_NO_GPL_SV "Inga pipelinebibliotek"
#define OPTION_VAL_NO_DYN_SV "Inga dynamiska tillstånd"
#define OPTION_VAL_NONE_SV "Ingen"
#define XEMU_RUMBLE_P1_LABEL_SV NULL
#define XEMU_RUMBLE_P1_INFO_0_SV NULL
#define XEMU_RUMBLE_P2_LABEL_SV NULL
#define XEMU_RUMBLE_P2_INFO_0_SV NULL
#define XEMU_DEADZONE_P1_LABEL_SV NULL
#define XEMU_DEADZONE_P1_INFO_0_SV NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_SV "0 %"
#define OPTION_VAL_5_XEMU_DEADZONE_P1_SV "5 %"
#define OPTION_VAL_10_XEMU_DEADZONE_P1_SV "10 %"
#define OPTION_VAL_15_SV NULL
#define OPTION_VAL_25_SV "25 %"
#define OPTION_VAL_30_SV NULL
#define XEMU_DEADZONE_P2_LABEL_SV NULL
#define XEMU_DEADZONE_P2_INFO_0_SV NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_SV "Gratisspel (omstart)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_SV "Startar Sega Chihiro-spel utan mynt. När alternativet är avstängt lägger Select in ett mynt."
#define XEMU_CHIHIRO_GUN_AIM_LABEL_SV "Sikta med ljuspistol"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_SV "Välj hur du siktar i House of the Dead III, Virtua Cop 3 och Ghost Squad. Mus: sikta med musen (eller RetroArchs ljuspistol), skjut med vänster knapp, använd vapnets knapp med höger knapp (pumpa eller byt vapen) och använd pedalen eller eldhastigheten med mittenknappen. Analog spak: sikta med vänster spak eller styrkorset, skjut med R2, använd vapnets knapp med L2 och pedalen eller eldhastigheten med L. R skjuter utanför skärmen."
#define OPTION_VAL_MOUSE_SV "Mus"
#define OPTION_VAL_STICK_SV "Analog spak"
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_SV "Sikte"
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_SV "Visar spelarnas sikten över bilden: spelare 1 i rött och spelare 2 i blått."
#define XEMU_CHIHIRO_FFB_LABEL_SV "Vibration från kraftåterkoppling"
#define XEMU_CHIHIRO_FFB_INFO_0_SV "Återger kraftåterkoppling från ett Chihiro-racingspel (OutRun 2, Maximum Tune) som vibration med denna styrka på handkontrollen i port 1."
#define OPTION_VAL_50_SV NULL
#define OPTION_VAL_75_SV NULL
#define OPTION_VAL_150_SV NULL
#define OPTION_VAL_200_SV NULL

struct retro_core_option_v2_category option_cats_sv[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_SV,
        CATEGORY_SYSTEM_INFO_0_SV
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_SV,
        CATEGORY_VIDEO_INFO_0_SV
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_SV,
        CATEGORY_AUDIO_INFO_0_SV
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_SV,
        CATEGORY_CONTROLS_INFO_0_SV
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_SV,
        CATEGORY_CHIHIRO_INFO_0_SV
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sv[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_SV,
        NULL,
        XEMU_MEMORY_INFO_0_SV,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_SV },
            { "128", OPTION_VAL_128_SV },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_SV,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_SV,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_SV },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_SV,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_SV,
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
        XEMU_HARD_FPU_LABEL_SV,
        NULL,
        XEMU_HARD_FPU_INFO_0_SV,
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
        XEMU_CPU_BOOST_LABEL_SV,
        NULL,
        XEMU_CPU_BOOST_INFO_0_SV,
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
        XEMU_HDD_TRIM_LABEL_SV,
        NULL,
        XEMU_HDD_TRIM_INFO_0_SV,
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
        XEMU_RENDERER_LABEL_SV,
        NULL,
        XEMU_RENDERER_INFO_0_SV,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_SV },
            { "opengl", OPTION_VAL_OPENGL_SV },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_SV,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_SV,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_SV },
            { "4:3",       OPTION_VAL_4_3_SV },
            { "16:9",      OPTION_VAL_16_9_SV },
            { "letterbox", OPTION_VAL_LETTERBOX_SV },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_SV,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_SV,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_SV },
            { "4:3",  OPTION_VAL_4_3_SV },
            { "16:9", OPTION_VAL_16_9_SV },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_SV,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_SV,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_SV },
            { "2", OPTION_VAL_2_SV },
            { "3", OPTION_VAL_3_SV },
            { "4", OPTION_VAL_4_SV },
            { "5", OPTION_VAL_5_SV },
            { "6", OPTION_VAL_6_SV },
            { "7", OPTION_VAL_7_SV },
            { "8", OPTION_VAL_8_SV },
            { "9", OPTION_VAL_9_SV },
            { "10", OPTION_VAL_10_SV },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_SV,
        NULL,
        XEMU_AVPACK_INFO_0_SV,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_SV },
            { "composite", OPTION_VAL_COMPOSITE_SV },
            { "svideo",    OPTION_VAL_SVIDEO_SV },
            { "scart",     OPTION_VAL_SCART_SV },
            { "vga",       OPTION_VAL_VGA_SV },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_SV,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_SV,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_SV,
        NULL,
        XEMU_USE_DSP_INFO_0_SV,
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
        XEMU_DSP_JIT_LABEL_SV,
        NULL,
        XEMU_DSP_JIT_INFO_0_SV,
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
        XEMU_HRTF_LABEL_SV,
        NULL,
        XEMU_HRTF_INFO_0_SV,
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
        XEMU_VP_WORKERS_LABEL_SV,
        NULL,
        XEMU_VP_WORKERS_INFO_0_SV,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_SV },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_SV,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_SV,
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
        XEMU_AUDIO_VOLUME_LABEL_SV,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_SV,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_SV },
            { "80",  OPTION_VAL_80_SV },
            { "60",  OPTION_VAL_60_SV },
            { "40",  OPTION_VAL_40_SV },
            { "20",  OPTION_VAL_20_SV },
            { "0",   OPTION_VAL_0_SV },
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
        XEMU_VK_FAST_PATHS_LABEL_SV,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_SV,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_SV },
            { "no_gpl",   OPTION_VAL_NO_GPL_SV },
            { "no_dyn",   OPTION_VAL_NO_DYN_SV },
            { "none",     OPTION_VAL_NONE_SV },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_SV,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_SV,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_SV,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_SV,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_SV,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_SV,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_SV },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_SV },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_SV },
            { "15", OPTION_VAL_15_SV },
            { "20", OPTION_VAL_20_SV },
            { "25", OPTION_VAL_25_SV },
            { "30", OPTION_VAL_30_SV },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_SV,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_SV,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_SV },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_SV },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_SV },
            { "15", OPTION_VAL_15_SV },
            { "20", OPTION_VAL_20_SV },
            { "25", OPTION_VAL_25_SV },
            { "30", OPTION_VAL_30_SV },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_SV,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_SV,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_SV,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_SV,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_SV },
            { "stick", OPTION_VAL_STICK_SV },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_SV,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_SV,
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
        XEMU_CHIHIRO_FFB_LABEL_SV,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_SV,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_SV },
            { "50",  OPTION_VAL_50_SV },
            { "75",  OPTION_VAL_75_SV },
            { "100", OPTION_VAL_100_SV },
            { "150", OPTION_VAL_150_SV },
            { "200", OPTION_VAL_200_SV },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_sv = {
   option_cats_sv,
   option_defs_sv
};

/* RETRO_LANGUAGE_TH */

#define CATEGORY_SYSTEM_LABEL_TH NULL
#define CATEGORY_SYSTEM_INFO_0_TH NULL
#define CATEGORY_VIDEO_LABEL_TH "วิดีโอ"
#define CATEGORY_VIDEO_INFO_0_TH NULL
#define CATEGORY_AUDIO_LABEL_TH "เสียง"
#define CATEGORY_AUDIO_INFO_0_TH NULL
#define CATEGORY_CONTROLS_LABEL_TH "การควบคุม"
#define CATEGORY_CONTROLS_INFO_0_TH NULL
#define CATEGORY_CHIHIRO_LABEL_TH NULL
#define CATEGORY_CHIHIRO_INFO_0_TH NULL
#define XEMU_MEMORY_LABEL_TH NULL
#define XEMU_MEMORY_INFO_0_TH NULL
#define OPTION_VAL_64_TH NULL
#define OPTION_VAL_128_TH NULL
#define XEMU_NETWORK_BACKEND_LABEL_TH NULL
#define XEMU_NETWORK_BACKEND_INFO_0_TH NULL
#define OPTION_VAL_NAT_TH NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_TH NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_TH NULL
#define XEMU_HARD_FPU_LABEL_TH NULL
#define XEMU_HARD_FPU_INFO_0_TH NULL
#define XEMU_CPU_BOOST_LABEL_TH NULL
#define XEMU_CPU_BOOST_INFO_0_TH NULL
#define XEMU_HDD_TRIM_LABEL_TH NULL
#define XEMU_HDD_TRIM_INFO_0_TH NULL
#define XEMU_RENDERER_LABEL_TH NULL
#define XEMU_RENDERER_INFO_0_TH NULL
#define OPTION_VAL_VULKAN_TH NULL
#define OPTION_VAL_OPENGL_TH NULL
#define XEMU_VIDEO_ASPECT_LABEL_TH NULL
#define XEMU_VIDEO_ASPECT_INFO_0_TH NULL
#define OPTION_VAL_DASHBOARD_TH NULL
#define OPTION_VAL_4_3_TH NULL
#define OPTION_VAL_16_9_TH NULL
#define OPTION_VAL_LETTERBOX_TH NULL
#define XEMU_ASPECT_RATIO_LABEL_TH "อัตราส่วนภาพของคอร์"
#define XEMU_ASPECT_RATIO_INFO_0_TH NULL
#define OPTION_VAL_AUTO_TH "อัตโนมัติ"
#define XEMU_SURFACE_SCALE_LABEL_TH NULL
#define XEMU_SURFACE_SCALE_INFO_0_TH NULL
#define OPTION_VAL_1_TH NULL
#define OPTION_VAL_2_TH NULL
#define OPTION_VAL_3_TH NULL
#define OPTION_VAL_4_TH NULL
#define OPTION_VAL_5_TH NULL
#define OPTION_VAL_6_TH NULL
#define OPTION_VAL_7_TH NULL
#define OPTION_VAL_8_TH NULL
#define OPTION_VAL_9_TH NULL
#define OPTION_VAL_10_TH NULL
#define XEMU_AVPACK_LABEL_TH NULL
#define XEMU_AVPACK_INFO_0_TH NULL
#define OPTION_VAL_HDTV_TH NULL
#define OPTION_VAL_COMPOSITE_TH NULL
#define OPTION_VAL_SVIDEO_TH NULL
#define OPTION_VAL_SCART_TH NULL
#define OPTION_VAL_VGA_TH NULL
#define XEMU_AUDIO_THREAD_LABEL_TH NULL
#define XEMU_AUDIO_THREAD_INFO_0_TH NULL
#define XEMU_USE_DSP_LABEL_TH NULL
#define XEMU_USE_DSP_INFO_0_TH NULL
#define XEMU_DSP_JIT_LABEL_TH NULL
#define XEMU_DSP_JIT_INFO_0_TH NULL
#define XEMU_HRTF_LABEL_TH NULL
#define XEMU_HRTF_INFO_0_TH NULL
#define XEMU_VP_WORKERS_LABEL_TH NULL
#define XEMU_VP_WORKERS_INFO_0_TH NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_TH NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_TH NULL
#define XEMU_AUDIO_VOLUME_LABEL_TH NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TH NULL
#define OPTION_VAL_100_TH NULL
#define OPTION_VAL_80_TH NULL
#define OPTION_VAL_60_TH NULL
#define OPTION_VAL_40_TH NULL
#define OPTION_VAL_20_TH NULL
#define OPTION_VAL_0_TH NULL
#define XEMU_VK_FAST_PATHS_LABEL_TH NULL
#define XEMU_VK_FAST_PATHS_INFO_0_TH NULL
#define OPTION_VAL_ALL_TH "ทั้งหมด"
#define OPTION_VAL_NO_GPL_TH NULL
#define OPTION_VAL_NO_DYN_TH NULL
#define OPTION_VAL_NONE_TH "ไม่แชร์อินพุต"
#define XEMU_RUMBLE_P1_LABEL_TH NULL
#define XEMU_RUMBLE_P1_INFO_0_TH NULL
#define XEMU_RUMBLE_P2_LABEL_TH NULL
#define XEMU_RUMBLE_P2_INFO_0_TH NULL
#define XEMU_DEADZONE_P1_LABEL_TH NULL
#define XEMU_DEADZONE_P1_INFO_0_TH NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_TH NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_TH NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_TH NULL
#define OPTION_VAL_15_TH NULL
#define OPTION_VAL_25_TH NULL
#define OPTION_VAL_30_TH NULL
#define XEMU_DEADZONE_P2_LABEL_TH NULL
#define XEMU_DEADZONE_P2_INFO_0_TH NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_TH NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_TH NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_TH NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_TH NULL
#define OPTION_VAL_MOUSE_TH "เมาส์"
#define OPTION_VAL_STICK_TH NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_TH NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_TH NULL
#define XEMU_CHIHIRO_FFB_LABEL_TH NULL
#define XEMU_CHIHIRO_FFB_INFO_0_TH NULL
#define OPTION_VAL_50_TH NULL
#define OPTION_VAL_75_TH NULL
#define OPTION_VAL_150_TH NULL
#define OPTION_VAL_200_TH NULL

struct retro_core_option_v2_category option_cats_th[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_TH,
        CATEGORY_SYSTEM_INFO_0_TH
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_TH,
        CATEGORY_VIDEO_INFO_0_TH
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_TH,
        CATEGORY_AUDIO_INFO_0_TH
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_TH,
        CATEGORY_CONTROLS_INFO_0_TH
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_TH,
        CATEGORY_CHIHIRO_INFO_0_TH
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_th[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_TH,
        NULL,
        XEMU_MEMORY_INFO_0_TH,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_TH },
            { "128", OPTION_VAL_128_TH },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_TH,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_TH,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_TH },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_TH,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_TH,
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
        XEMU_HARD_FPU_LABEL_TH,
        NULL,
        XEMU_HARD_FPU_INFO_0_TH,
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
        XEMU_CPU_BOOST_LABEL_TH,
        NULL,
        XEMU_CPU_BOOST_INFO_0_TH,
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
        XEMU_HDD_TRIM_LABEL_TH,
        NULL,
        XEMU_HDD_TRIM_INFO_0_TH,
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
        XEMU_RENDERER_LABEL_TH,
        NULL,
        XEMU_RENDERER_INFO_0_TH,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_TH },
            { "opengl", OPTION_VAL_OPENGL_TH },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_TH,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_TH,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_TH },
            { "4:3",       OPTION_VAL_4_3_TH },
            { "16:9",      OPTION_VAL_16_9_TH },
            { "letterbox", OPTION_VAL_LETTERBOX_TH },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_TH,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_TH,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_TH },
            { "4:3",  OPTION_VAL_4_3_TH },
            { "16:9", OPTION_VAL_16_9_TH },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_TH,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_TH,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_TH },
            { "2", OPTION_VAL_2_TH },
            { "3", OPTION_VAL_3_TH },
            { "4", OPTION_VAL_4_TH },
            { "5", OPTION_VAL_5_TH },
            { "6", OPTION_VAL_6_TH },
            { "7", OPTION_VAL_7_TH },
            { "8", OPTION_VAL_8_TH },
            { "9", OPTION_VAL_9_TH },
            { "10", OPTION_VAL_10_TH },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_TH,
        NULL,
        XEMU_AVPACK_INFO_0_TH,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_TH },
            { "composite", OPTION_VAL_COMPOSITE_TH },
            { "svideo",    OPTION_VAL_SVIDEO_TH },
            { "scart",     OPTION_VAL_SCART_TH },
            { "vga",       OPTION_VAL_VGA_TH },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_TH,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_TH,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_TH,
        NULL,
        XEMU_USE_DSP_INFO_0_TH,
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
        XEMU_DSP_JIT_LABEL_TH,
        NULL,
        XEMU_DSP_JIT_INFO_0_TH,
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
        XEMU_HRTF_LABEL_TH,
        NULL,
        XEMU_HRTF_INFO_0_TH,
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
        XEMU_VP_WORKERS_LABEL_TH,
        NULL,
        XEMU_VP_WORKERS_INFO_0_TH,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_TH },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_TH,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_TH,
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
        XEMU_AUDIO_VOLUME_LABEL_TH,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_TH,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_TH },
            { "80",  OPTION_VAL_80_TH },
            { "60",  OPTION_VAL_60_TH },
            { "40",  OPTION_VAL_40_TH },
            { "20",  OPTION_VAL_20_TH },
            { "0",   OPTION_VAL_0_TH },
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
        XEMU_VK_FAST_PATHS_LABEL_TH,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_TH,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_TH },
            { "no_gpl",   OPTION_VAL_NO_GPL_TH },
            { "no_dyn",   OPTION_VAL_NO_DYN_TH },
            { "none",     OPTION_VAL_NONE_TH },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_TH,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_TH,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_TH,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_TH,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_TH,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_TH,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_TH },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_TH },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_TH },
            { "15", OPTION_VAL_15_TH },
            { "20", OPTION_VAL_20_TH },
            { "25", OPTION_VAL_25_TH },
            { "30", OPTION_VAL_30_TH },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_TH,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_TH,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_TH },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_TH },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_TH },
            { "15", OPTION_VAL_15_TH },
            { "20", OPTION_VAL_20_TH },
            { "25", OPTION_VAL_25_TH },
            { "30", OPTION_VAL_30_TH },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_TH,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_TH,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_TH,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_TH,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_TH },
            { "stick", OPTION_VAL_STICK_TH },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_TH,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_TH,
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
        XEMU_CHIHIRO_FFB_LABEL_TH,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_TH,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_TH },
            { "50",  OPTION_VAL_50_TH },
            { "75",  OPTION_VAL_75_TH },
            { "100", OPTION_VAL_100_TH },
            { "150", OPTION_VAL_150_TH },
            { "200", OPTION_VAL_200_TH },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_th = {
   option_cats_th,
   option_defs_th
};

/* RETRO_LANGUAGE_TR */

#define CATEGORY_SYSTEM_LABEL_TR NULL
#define CATEGORY_SYSTEM_INFO_0_TR NULL
#define CATEGORY_VIDEO_LABEL_TR NULL
#define CATEGORY_VIDEO_INFO_0_TR NULL
#define CATEGORY_AUDIO_LABEL_TR "Ses"
#define CATEGORY_AUDIO_INFO_0_TR NULL
#define CATEGORY_CONTROLS_LABEL_TR "Kontrolcüler"
#define CATEGORY_CONTROLS_INFO_0_TR NULL
#define CATEGORY_CHIHIRO_LABEL_TR NULL
#define CATEGORY_CHIHIRO_INFO_0_TR NULL
#define XEMU_MEMORY_LABEL_TR NULL
#define XEMU_MEMORY_INFO_0_TR NULL
#define OPTION_VAL_64_TR NULL
#define OPTION_VAL_128_TR NULL
#define XEMU_NETWORK_BACKEND_LABEL_TR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_TR NULL
#define OPTION_VAL_NAT_TR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_TR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_TR NULL
#define XEMU_HARD_FPU_LABEL_TR NULL
#define XEMU_HARD_FPU_INFO_0_TR NULL
#define XEMU_CPU_BOOST_LABEL_TR NULL
#define XEMU_CPU_BOOST_INFO_0_TR NULL
#define XEMU_HDD_TRIM_LABEL_TR NULL
#define XEMU_HDD_TRIM_INFO_0_TR NULL
#define XEMU_RENDERER_LABEL_TR NULL
#define XEMU_RENDERER_INFO_0_TR NULL
#define OPTION_VAL_VULKAN_TR NULL
#define OPTION_VAL_OPENGL_TR NULL
#define XEMU_VIDEO_ASPECT_LABEL_TR NULL
#define XEMU_VIDEO_ASPECT_INFO_0_TR NULL
#define OPTION_VAL_DASHBOARD_TR NULL
#define OPTION_VAL_4_3_TR NULL
#define OPTION_VAL_16_9_TR NULL
#define OPTION_VAL_LETTERBOX_TR NULL
#define XEMU_ASPECT_RATIO_LABEL_TR "Çekirdek En Boy Oranı"
#define XEMU_ASPECT_RATIO_INFO_0_TR NULL
#define OPTION_VAL_AUTO_TR "Otomatik"
#define XEMU_SURFACE_SCALE_LABEL_TR NULL
#define XEMU_SURFACE_SCALE_INFO_0_TR NULL
#define OPTION_VAL_1_TR NULL
#define OPTION_VAL_2_TR NULL
#define OPTION_VAL_3_TR NULL
#define OPTION_VAL_4_TR NULL
#define OPTION_VAL_5_TR NULL
#define OPTION_VAL_6_TR NULL
#define OPTION_VAL_7_TR NULL
#define OPTION_VAL_8_TR NULL
#define OPTION_VAL_9_TR NULL
#define OPTION_VAL_10_TR NULL
#define XEMU_AVPACK_LABEL_TR NULL
#define XEMU_AVPACK_INFO_0_TR NULL
#define OPTION_VAL_HDTV_TR NULL
#define OPTION_VAL_COMPOSITE_TR NULL
#define OPTION_VAL_SVIDEO_TR NULL
#define OPTION_VAL_SCART_TR NULL
#define OPTION_VAL_VGA_TR NULL
#define XEMU_AUDIO_THREAD_LABEL_TR NULL
#define XEMU_AUDIO_THREAD_INFO_0_TR NULL
#define XEMU_USE_DSP_LABEL_TR NULL
#define XEMU_USE_DSP_INFO_0_TR NULL
#define XEMU_DSP_JIT_LABEL_TR NULL
#define XEMU_DSP_JIT_INFO_0_TR NULL
#define XEMU_HRTF_LABEL_TR NULL
#define XEMU_HRTF_INFO_0_TR NULL
#define XEMU_VP_WORKERS_LABEL_TR NULL
#define XEMU_VP_WORKERS_INFO_0_TR NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_TR NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_TR NULL
#define XEMU_AUDIO_VOLUME_LABEL_TR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TR NULL
#define OPTION_VAL_100_TR "%100"
#define OPTION_VAL_80_TR "%80"
#define OPTION_VAL_60_TR "%60"
#define OPTION_VAL_40_TR "%40"
#define OPTION_VAL_20_TR "%20"
#define OPTION_VAL_0_TR NULL
#define XEMU_VK_FAST_PATHS_LABEL_TR NULL
#define XEMU_VK_FAST_PATHS_INFO_0_TR NULL
#define OPTION_VAL_ALL_TR "Tümü"
#define OPTION_VAL_NO_GPL_TR NULL
#define OPTION_VAL_NO_DYN_TR NULL
#define OPTION_VAL_NONE_TR "Yok"
#define XEMU_RUMBLE_P1_LABEL_TR NULL
#define XEMU_RUMBLE_P1_INFO_0_TR NULL
#define XEMU_RUMBLE_P2_LABEL_TR NULL
#define XEMU_RUMBLE_P2_INFO_0_TR NULL
#define XEMU_DEADZONE_P1_LABEL_TR NULL
#define XEMU_DEADZONE_P1_INFO_0_TR NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_TR NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_TR NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_TR NULL
#define OPTION_VAL_15_TR "%15"
#define OPTION_VAL_25_TR NULL
#define OPTION_VAL_30_TR "%30"
#define XEMU_DEADZONE_P2_LABEL_TR NULL
#define XEMU_DEADZONE_P2_INFO_0_TR NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_TR NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_TR NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_TR NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_TR NULL
#define OPTION_VAL_MOUSE_TR "Fare"
#define OPTION_VAL_STICK_TR NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_TR NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_TR NULL
#define XEMU_CHIHIRO_FFB_LABEL_TR NULL
#define XEMU_CHIHIRO_FFB_INFO_0_TR NULL
#define OPTION_VAL_50_TR "%50"
#define OPTION_VAL_75_TR "%75"
#define OPTION_VAL_150_TR "%150"
#define OPTION_VAL_200_TR "%200"

struct retro_core_option_v2_category option_cats_tr[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_TR,
        CATEGORY_SYSTEM_INFO_0_TR
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_TR,
        CATEGORY_VIDEO_INFO_0_TR
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_TR,
        CATEGORY_AUDIO_INFO_0_TR
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_TR,
        CATEGORY_CONTROLS_INFO_0_TR
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_TR,
        CATEGORY_CHIHIRO_INFO_0_TR
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_tr[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_TR,
        NULL,
        XEMU_MEMORY_INFO_0_TR,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_TR },
            { "128", OPTION_VAL_128_TR },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_TR,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_TR,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_TR },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_TR,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_TR,
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
        XEMU_HARD_FPU_LABEL_TR,
        NULL,
        XEMU_HARD_FPU_INFO_0_TR,
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
        XEMU_CPU_BOOST_LABEL_TR,
        NULL,
        XEMU_CPU_BOOST_INFO_0_TR,
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
        XEMU_HDD_TRIM_LABEL_TR,
        NULL,
        XEMU_HDD_TRIM_INFO_0_TR,
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
        XEMU_RENDERER_LABEL_TR,
        NULL,
        XEMU_RENDERER_INFO_0_TR,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_TR },
            { "opengl", OPTION_VAL_OPENGL_TR },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_TR,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_TR,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_TR },
            { "4:3",       OPTION_VAL_4_3_TR },
            { "16:9",      OPTION_VAL_16_9_TR },
            { "letterbox", OPTION_VAL_LETTERBOX_TR },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_TR,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_TR,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_TR },
            { "4:3",  OPTION_VAL_4_3_TR },
            { "16:9", OPTION_VAL_16_9_TR },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_TR,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_TR,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_TR },
            { "2", OPTION_VAL_2_TR },
            { "3", OPTION_VAL_3_TR },
            { "4", OPTION_VAL_4_TR },
            { "5", OPTION_VAL_5_TR },
            { "6", OPTION_VAL_6_TR },
            { "7", OPTION_VAL_7_TR },
            { "8", OPTION_VAL_8_TR },
            { "9", OPTION_VAL_9_TR },
            { "10", OPTION_VAL_10_TR },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_TR,
        NULL,
        XEMU_AVPACK_INFO_0_TR,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_TR },
            { "composite", OPTION_VAL_COMPOSITE_TR },
            { "svideo",    OPTION_VAL_SVIDEO_TR },
            { "scart",     OPTION_VAL_SCART_TR },
            { "vga",       OPTION_VAL_VGA_TR },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_TR,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_TR,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_TR,
        NULL,
        XEMU_USE_DSP_INFO_0_TR,
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
        XEMU_DSP_JIT_LABEL_TR,
        NULL,
        XEMU_DSP_JIT_INFO_0_TR,
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
        XEMU_HRTF_LABEL_TR,
        NULL,
        XEMU_HRTF_INFO_0_TR,
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
        XEMU_VP_WORKERS_LABEL_TR,
        NULL,
        XEMU_VP_WORKERS_INFO_0_TR,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_TR },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_TR,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_TR,
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
        XEMU_AUDIO_VOLUME_LABEL_TR,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_TR,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_TR },
            { "80",  OPTION_VAL_80_TR },
            { "60",  OPTION_VAL_60_TR },
            { "40",  OPTION_VAL_40_TR },
            { "20",  OPTION_VAL_20_TR },
            { "0",   OPTION_VAL_0_TR },
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
        XEMU_VK_FAST_PATHS_LABEL_TR,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_TR,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_TR },
            { "no_gpl",   OPTION_VAL_NO_GPL_TR },
            { "no_dyn",   OPTION_VAL_NO_DYN_TR },
            { "none",     OPTION_VAL_NONE_TR },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_TR,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_TR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_TR,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_TR,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_TR,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_TR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_TR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_TR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_TR },
            { "15", OPTION_VAL_15_TR },
            { "20", OPTION_VAL_20_TR },
            { "25", OPTION_VAL_25_TR },
            { "30", OPTION_VAL_30_TR },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_TR,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_TR,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_TR },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_TR },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_TR },
            { "15", OPTION_VAL_15_TR },
            { "20", OPTION_VAL_20_TR },
            { "25", OPTION_VAL_25_TR },
            { "30", OPTION_VAL_30_TR },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_TR,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_TR,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_TR,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_TR,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_TR },
            { "stick", OPTION_VAL_STICK_TR },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_TR,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_TR,
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
        XEMU_CHIHIRO_FFB_LABEL_TR,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_TR,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_TR },
            { "50",  OPTION_VAL_50_TR },
            { "75",  OPTION_VAL_75_TR },
            { "100", OPTION_VAL_100_TR },
            { "150", OPTION_VAL_150_TR },
            { "200", OPTION_VAL_200_TR },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_tr = {
   option_cats_tr,
   option_defs_tr
};

/* RETRO_LANGUAGE_TT */

#define CATEGORY_SYSTEM_LABEL_TT NULL
#define CATEGORY_SYSTEM_INFO_0_TT NULL
#define CATEGORY_VIDEO_LABEL_TT "Видео"
#define CATEGORY_VIDEO_INFO_0_TT NULL
#define CATEGORY_AUDIO_LABEL_TT "Аудио"
#define CATEGORY_AUDIO_INFO_0_TT NULL
#define CATEGORY_CONTROLS_LABEL_TT NULL
#define CATEGORY_CONTROLS_INFO_0_TT NULL
#define CATEGORY_CHIHIRO_LABEL_TT NULL
#define CATEGORY_CHIHIRO_INFO_0_TT NULL
#define XEMU_MEMORY_LABEL_TT NULL
#define XEMU_MEMORY_INFO_0_TT NULL
#define OPTION_VAL_64_TT NULL
#define OPTION_VAL_128_TT NULL
#define XEMU_NETWORK_BACKEND_LABEL_TT NULL
#define XEMU_NETWORK_BACKEND_INFO_0_TT NULL
#define OPTION_VAL_NAT_TT NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_TT NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_TT NULL
#define XEMU_HARD_FPU_LABEL_TT NULL
#define XEMU_HARD_FPU_INFO_0_TT NULL
#define XEMU_CPU_BOOST_LABEL_TT NULL
#define XEMU_CPU_BOOST_INFO_0_TT NULL
#define XEMU_HDD_TRIM_LABEL_TT NULL
#define XEMU_HDD_TRIM_INFO_0_TT NULL
#define XEMU_RENDERER_LABEL_TT NULL
#define XEMU_RENDERER_INFO_0_TT NULL
#define OPTION_VAL_VULKAN_TT NULL
#define OPTION_VAL_OPENGL_TT NULL
#define XEMU_VIDEO_ASPECT_LABEL_TT NULL
#define XEMU_VIDEO_ASPECT_INFO_0_TT NULL
#define OPTION_VAL_DASHBOARD_TT NULL
#define OPTION_VAL_4_3_TT NULL
#define OPTION_VAL_16_9_TT NULL
#define OPTION_VAL_LETTERBOX_TT NULL
#define XEMU_ASPECT_RATIO_LABEL_TT NULL
#define XEMU_ASPECT_RATIO_INFO_0_TT NULL
#define OPTION_VAL_AUTO_TT NULL
#define XEMU_SURFACE_SCALE_LABEL_TT NULL
#define XEMU_SURFACE_SCALE_INFO_0_TT NULL
#define OPTION_VAL_1_TT NULL
#define OPTION_VAL_2_TT NULL
#define OPTION_VAL_3_TT NULL
#define OPTION_VAL_4_TT NULL
#define OPTION_VAL_5_TT NULL
#define OPTION_VAL_6_TT NULL
#define OPTION_VAL_7_TT NULL
#define OPTION_VAL_8_TT NULL
#define OPTION_VAL_9_TT NULL
#define OPTION_VAL_10_TT NULL
#define XEMU_AVPACK_LABEL_TT NULL
#define XEMU_AVPACK_INFO_0_TT NULL
#define OPTION_VAL_HDTV_TT NULL
#define OPTION_VAL_COMPOSITE_TT NULL
#define OPTION_VAL_SVIDEO_TT NULL
#define OPTION_VAL_SCART_TT NULL
#define OPTION_VAL_VGA_TT NULL
#define XEMU_AUDIO_THREAD_LABEL_TT NULL
#define XEMU_AUDIO_THREAD_INFO_0_TT NULL
#define XEMU_USE_DSP_LABEL_TT NULL
#define XEMU_USE_DSP_INFO_0_TT NULL
#define XEMU_DSP_JIT_LABEL_TT NULL
#define XEMU_DSP_JIT_INFO_0_TT NULL
#define XEMU_HRTF_LABEL_TT NULL
#define XEMU_HRTF_INFO_0_TT NULL
#define XEMU_VP_WORKERS_LABEL_TT NULL
#define XEMU_VP_WORKERS_INFO_0_TT NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_TT NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_TT NULL
#define XEMU_AUDIO_VOLUME_LABEL_TT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TT NULL
#define OPTION_VAL_100_TT NULL
#define OPTION_VAL_80_TT NULL
#define OPTION_VAL_60_TT NULL
#define OPTION_VAL_40_TT NULL
#define OPTION_VAL_20_TT NULL
#define OPTION_VAL_0_TT NULL
#define XEMU_VK_FAST_PATHS_LABEL_TT NULL
#define XEMU_VK_FAST_PATHS_INFO_0_TT NULL
#define OPTION_VAL_ALL_TT "Барлык"
#define OPTION_VAL_NO_GPL_TT NULL
#define OPTION_VAL_NO_DYN_TT NULL
#define OPTION_VAL_NONE_TT NULL
#define XEMU_RUMBLE_P1_LABEL_TT NULL
#define XEMU_RUMBLE_P1_INFO_0_TT NULL
#define XEMU_RUMBLE_P2_LABEL_TT NULL
#define XEMU_RUMBLE_P2_INFO_0_TT NULL
#define XEMU_DEADZONE_P1_LABEL_TT NULL
#define XEMU_DEADZONE_P1_INFO_0_TT NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_TT NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_TT NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_TT NULL
#define OPTION_VAL_15_TT NULL
#define OPTION_VAL_25_TT NULL
#define OPTION_VAL_30_TT NULL
#define XEMU_DEADZONE_P2_LABEL_TT NULL
#define XEMU_DEADZONE_P2_INFO_0_TT NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_TT NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_TT NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_TT NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_TT NULL
#define OPTION_VAL_MOUSE_TT NULL
#define OPTION_VAL_STICK_TT NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_TT NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_TT NULL
#define XEMU_CHIHIRO_FFB_LABEL_TT NULL
#define XEMU_CHIHIRO_FFB_INFO_0_TT NULL
#define OPTION_VAL_50_TT NULL
#define OPTION_VAL_75_TT NULL
#define OPTION_VAL_150_TT NULL
#define OPTION_VAL_200_TT NULL

struct retro_core_option_v2_category option_cats_tt[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_TT,
        CATEGORY_SYSTEM_INFO_0_TT
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_TT,
        CATEGORY_VIDEO_INFO_0_TT
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_TT,
        CATEGORY_AUDIO_INFO_0_TT
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_TT,
        CATEGORY_CONTROLS_INFO_0_TT
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_TT,
        CATEGORY_CHIHIRO_INFO_0_TT
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_tt[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_TT,
        NULL,
        XEMU_MEMORY_INFO_0_TT,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_TT },
            { "128", OPTION_VAL_128_TT },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_TT,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_TT,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_TT },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_TT,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_TT,
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
        XEMU_HARD_FPU_LABEL_TT,
        NULL,
        XEMU_HARD_FPU_INFO_0_TT,
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
        XEMU_CPU_BOOST_LABEL_TT,
        NULL,
        XEMU_CPU_BOOST_INFO_0_TT,
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
        XEMU_HDD_TRIM_LABEL_TT,
        NULL,
        XEMU_HDD_TRIM_INFO_0_TT,
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
        XEMU_RENDERER_LABEL_TT,
        NULL,
        XEMU_RENDERER_INFO_0_TT,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_TT },
            { "opengl", OPTION_VAL_OPENGL_TT },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_TT,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_TT,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_TT },
            { "4:3",       OPTION_VAL_4_3_TT },
            { "16:9",      OPTION_VAL_16_9_TT },
            { "letterbox", OPTION_VAL_LETTERBOX_TT },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_TT,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_TT,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_TT },
            { "4:3",  OPTION_VAL_4_3_TT },
            { "16:9", OPTION_VAL_16_9_TT },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_TT,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_TT,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_TT },
            { "2", OPTION_VAL_2_TT },
            { "3", OPTION_VAL_3_TT },
            { "4", OPTION_VAL_4_TT },
            { "5", OPTION_VAL_5_TT },
            { "6", OPTION_VAL_6_TT },
            { "7", OPTION_VAL_7_TT },
            { "8", OPTION_VAL_8_TT },
            { "9", OPTION_VAL_9_TT },
            { "10", OPTION_VAL_10_TT },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_TT,
        NULL,
        XEMU_AVPACK_INFO_0_TT,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_TT },
            { "composite", OPTION_VAL_COMPOSITE_TT },
            { "svideo",    OPTION_VAL_SVIDEO_TT },
            { "scart",     OPTION_VAL_SCART_TT },
            { "vga",       OPTION_VAL_VGA_TT },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_TT,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_TT,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_TT,
        NULL,
        XEMU_USE_DSP_INFO_0_TT,
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
        XEMU_DSP_JIT_LABEL_TT,
        NULL,
        XEMU_DSP_JIT_INFO_0_TT,
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
        XEMU_HRTF_LABEL_TT,
        NULL,
        XEMU_HRTF_INFO_0_TT,
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
        XEMU_VP_WORKERS_LABEL_TT,
        NULL,
        XEMU_VP_WORKERS_INFO_0_TT,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_TT },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_TT,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_TT,
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
        XEMU_AUDIO_VOLUME_LABEL_TT,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_TT,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_TT },
            { "80",  OPTION_VAL_80_TT },
            { "60",  OPTION_VAL_60_TT },
            { "40",  OPTION_VAL_40_TT },
            { "20",  OPTION_VAL_20_TT },
            { "0",   OPTION_VAL_0_TT },
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
        XEMU_VK_FAST_PATHS_LABEL_TT,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_TT,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_TT },
            { "no_gpl",   OPTION_VAL_NO_GPL_TT },
            { "no_dyn",   OPTION_VAL_NO_DYN_TT },
            { "none",     OPTION_VAL_NONE_TT },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_TT,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_TT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_TT,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_TT,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_TT,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_TT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_TT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_TT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_TT },
            { "15", OPTION_VAL_15_TT },
            { "20", OPTION_VAL_20_TT },
            { "25", OPTION_VAL_25_TT },
            { "30", OPTION_VAL_30_TT },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_TT,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_TT,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_TT },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_TT },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_TT },
            { "15", OPTION_VAL_15_TT },
            { "20", OPTION_VAL_20_TT },
            { "25", OPTION_VAL_25_TT },
            { "30", OPTION_VAL_30_TT },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_TT,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_TT,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_TT,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_TT,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_TT },
            { "stick", OPTION_VAL_STICK_TT },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_TT,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_TT,
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
        XEMU_CHIHIRO_FFB_LABEL_TT,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_TT,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_TT },
            { "50",  OPTION_VAL_50_TT },
            { "75",  OPTION_VAL_75_TT },
            { "100", OPTION_VAL_100_TT },
            { "150", OPTION_VAL_150_TT },
            { "200", OPTION_VAL_200_TT },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_tt = {
   option_cats_tt,
   option_defs_tt
};

/* RETRO_LANGUAGE_UK */

#define CATEGORY_SYSTEM_LABEL_UK NULL
#define CATEGORY_SYSTEM_INFO_0_UK NULL
#define CATEGORY_VIDEO_LABEL_UK "Відео"
#define CATEGORY_VIDEO_INFO_0_UK NULL
#define CATEGORY_AUDIO_LABEL_UK "Звук"
#define CATEGORY_AUDIO_INFO_0_UK NULL
#define CATEGORY_CONTROLS_LABEL_UK "Управління"
#define CATEGORY_CONTROLS_INFO_0_UK NULL
#define CATEGORY_CHIHIRO_LABEL_UK NULL
#define CATEGORY_CHIHIRO_INFO_0_UK NULL
#define XEMU_MEMORY_LABEL_UK NULL
#define XEMU_MEMORY_INFO_0_UK NULL
#define OPTION_VAL_64_UK "64 МБ"
#define OPTION_VAL_128_UK "128 МБ"
#define XEMU_NETWORK_BACKEND_LABEL_UK NULL
#define XEMU_NETWORK_BACKEND_INFO_0_UK NULL
#define OPTION_VAL_NAT_UK NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_UK NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_UK NULL
#define XEMU_HARD_FPU_LABEL_UK NULL
#define XEMU_HARD_FPU_INFO_0_UK NULL
#define XEMU_CPU_BOOST_LABEL_UK NULL
#define XEMU_CPU_BOOST_INFO_0_UK NULL
#define XEMU_HDD_TRIM_LABEL_UK NULL
#define XEMU_HDD_TRIM_INFO_0_UK NULL
#define XEMU_RENDERER_LABEL_UK NULL
#define XEMU_RENDERER_INFO_0_UK NULL
#define OPTION_VAL_VULKAN_UK NULL
#define OPTION_VAL_OPENGL_UK NULL
#define XEMU_VIDEO_ASPECT_LABEL_UK NULL
#define XEMU_VIDEO_ASPECT_INFO_0_UK NULL
#define OPTION_VAL_DASHBOARD_UK NULL
#define OPTION_VAL_4_3_UK NULL
#define OPTION_VAL_16_9_UK NULL
#define OPTION_VAL_LETTERBOX_UK NULL
#define XEMU_ASPECT_RATIO_LABEL_UK "Співвідношення сторін ядра"
#define XEMU_ASPECT_RATIO_INFO_0_UK NULL
#define OPTION_VAL_AUTO_UK "Автоматично"
#define XEMU_SURFACE_SCALE_LABEL_UK NULL
#define XEMU_SURFACE_SCALE_INFO_0_UK NULL
#define OPTION_VAL_1_UK NULL
#define OPTION_VAL_2_UK NULL
#define OPTION_VAL_3_UK NULL
#define OPTION_VAL_4_UK NULL
#define OPTION_VAL_5_UK NULL
#define OPTION_VAL_6_UK NULL
#define OPTION_VAL_7_UK NULL
#define OPTION_VAL_8_UK NULL
#define OPTION_VAL_9_UK NULL
#define OPTION_VAL_10_UK NULL
#define XEMU_AVPACK_LABEL_UK NULL
#define XEMU_AVPACK_INFO_0_UK NULL
#define OPTION_VAL_HDTV_UK NULL
#define OPTION_VAL_COMPOSITE_UK "Композитний"
#define OPTION_VAL_SVIDEO_UK NULL
#define OPTION_VAL_SCART_UK NULL
#define OPTION_VAL_VGA_UK NULL
#define XEMU_AUDIO_THREAD_LABEL_UK NULL
#define XEMU_AUDIO_THREAD_INFO_0_UK NULL
#define XEMU_USE_DSP_LABEL_UK NULL
#define XEMU_USE_DSP_INFO_0_UK NULL
#define XEMU_DSP_JIT_LABEL_UK NULL
#define XEMU_DSP_JIT_INFO_0_UK NULL
#define XEMU_HRTF_LABEL_UK NULL
#define XEMU_HRTF_INFO_0_UK NULL
#define XEMU_VP_WORKERS_LABEL_UK NULL
#define XEMU_VP_WORKERS_INFO_0_UK NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_UK NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_UK NULL
#define XEMU_AUDIO_VOLUME_LABEL_UK NULL
#define XEMU_AUDIO_VOLUME_INFO_0_UK NULL
#define OPTION_VAL_100_UK NULL
#define OPTION_VAL_80_UK NULL
#define OPTION_VAL_60_UK NULL
#define OPTION_VAL_40_UK NULL
#define OPTION_VAL_20_UK NULL
#define OPTION_VAL_0_UK NULL
#define XEMU_VK_FAST_PATHS_LABEL_UK NULL
#define XEMU_VK_FAST_PATHS_INFO_0_UK NULL
#define OPTION_VAL_ALL_UK "Усі"
#define OPTION_VAL_NO_GPL_UK NULL
#define OPTION_VAL_NO_DYN_UK NULL
#define OPTION_VAL_NONE_UK "Немає"
#define XEMU_RUMBLE_P1_LABEL_UK NULL
#define XEMU_RUMBLE_P1_INFO_0_UK NULL
#define XEMU_RUMBLE_P2_LABEL_UK NULL
#define XEMU_RUMBLE_P2_INFO_0_UK NULL
#define XEMU_DEADZONE_P1_LABEL_UK NULL
#define XEMU_DEADZONE_P1_INFO_0_UK NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_UK NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_UK NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_UK NULL
#define OPTION_VAL_15_UK NULL
#define OPTION_VAL_25_UK NULL
#define OPTION_VAL_30_UK NULL
#define XEMU_DEADZONE_P2_LABEL_UK NULL
#define XEMU_DEADZONE_P2_INFO_0_UK NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_UK NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_UK NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_UK NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_UK NULL
#define OPTION_VAL_MOUSE_UK "Миша"
#define OPTION_VAL_STICK_UK NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_UK NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_UK NULL
#define XEMU_CHIHIRO_FFB_LABEL_UK NULL
#define XEMU_CHIHIRO_FFB_INFO_0_UK NULL
#define OPTION_VAL_50_UK NULL
#define OPTION_VAL_75_UK NULL
#define OPTION_VAL_150_UK NULL
#define OPTION_VAL_200_UK NULL

struct retro_core_option_v2_category option_cats_uk[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_UK,
        CATEGORY_SYSTEM_INFO_0_UK
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_UK,
        CATEGORY_VIDEO_INFO_0_UK
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_UK,
        CATEGORY_AUDIO_INFO_0_UK
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_UK,
        CATEGORY_CONTROLS_INFO_0_UK
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_UK,
        CATEGORY_CHIHIRO_INFO_0_UK
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_uk[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_UK,
        NULL,
        XEMU_MEMORY_INFO_0_UK,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_UK },
            { "128", OPTION_VAL_128_UK },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_UK,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_UK,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_UK },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_UK,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_UK,
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
        XEMU_HARD_FPU_LABEL_UK,
        NULL,
        XEMU_HARD_FPU_INFO_0_UK,
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
        XEMU_CPU_BOOST_LABEL_UK,
        NULL,
        XEMU_CPU_BOOST_INFO_0_UK,
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
        XEMU_HDD_TRIM_LABEL_UK,
        NULL,
        XEMU_HDD_TRIM_INFO_0_UK,
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
        XEMU_RENDERER_LABEL_UK,
        NULL,
        XEMU_RENDERER_INFO_0_UK,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_UK },
            { "opengl", OPTION_VAL_OPENGL_UK },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_UK,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_UK,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_UK },
            { "4:3",       OPTION_VAL_4_3_UK },
            { "16:9",      OPTION_VAL_16_9_UK },
            { "letterbox", OPTION_VAL_LETTERBOX_UK },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_UK,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_UK,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_UK },
            { "4:3",  OPTION_VAL_4_3_UK },
            { "16:9", OPTION_VAL_16_9_UK },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_UK,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_UK,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_UK },
            { "2", OPTION_VAL_2_UK },
            { "3", OPTION_VAL_3_UK },
            { "4", OPTION_VAL_4_UK },
            { "5", OPTION_VAL_5_UK },
            { "6", OPTION_VAL_6_UK },
            { "7", OPTION_VAL_7_UK },
            { "8", OPTION_VAL_8_UK },
            { "9", OPTION_VAL_9_UK },
            { "10", OPTION_VAL_10_UK },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_UK,
        NULL,
        XEMU_AVPACK_INFO_0_UK,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_UK },
            { "composite", OPTION_VAL_COMPOSITE_UK },
            { "svideo",    OPTION_VAL_SVIDEO_UK },
            { "scart",     OPTION_VAL_SCART_UK },
            { "vga",       OPTION_VAL_VGA_UK },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_UK,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_UK,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_UK,
        NULL,
        XEMU_USE_DSP_INFO_0_UK,
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
        XEMU_DSP_JIT_LABEL_UK,
        NULL,
        XEMU_DSP_JIT_INFO_0_UK,
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
        XEMU_HRTF_LABEL_UK,
        NULL,
        XEMU_HRTF_INFO_0_UK,
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
        XEMU_VP_WORKERS_LABEL_UK,
        NULL,
        XEMU_VP_WORKERS_INFO_0_UK,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_UK },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_UK,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_UK,
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
        XEMU_AUDIO_VOLUME_LABEL_UK,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_UK,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_UK },
            { "80",  OPTION_VAL_80_UK },
            { "60",  OPTION_VAL_60_UK },
            { "40",  OPTION_VAL_40_UK },
            { "20",  OPTION_VAL_20_UK },
            { "0",   OPTION_VAL_0_UK },
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
        XEMU_VK_FAST_PATHS_LABEL_UK,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_UK,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_UK },
            { "no_gpl",   OPTION_VAL_NO_GPL_UK },
            { "no_dyn",   OPTION_VAL_NO_DYN_UK },
            { "none",     OPTION_VAL_NONE_UK },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_UK,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_UK,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_UK,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_UK,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_UK,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_UK,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_UK },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_UK },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_UK },
            { "15", OPTION_VAL_15_UK },
            { "20", OPTION_VAL_20_UK },
            { "25", OPTION_VAL_25_UK },
            { "30", OPTION_VAL_30_UK },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_UK,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_UK,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_UK },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_UK },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_UK },
            { "15", OPTION_VAL_15_UK },
            { "20", OPTION_VAL_20_UK },
            { "25", OPTION_VAL_25_UK },
            { "30", OPTION_VAL_30_UK },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_UK,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_UK,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_UK,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_UK,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_UK },
            { "stick", OPTION_VAL_STICK_UK },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_UK,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_UK,
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
        XEMU_CHIHIRO_FFB_LABEL_UK,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_UK,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_UK },
            { "50",  OPTION_VAL_50_UK },
            { "75",  OPTION_VAL_75_UK },
            { "100", OPTION_VAL_100_UK },
            { "150", OPTION_VAL_150_UK },
            { "200", OPTION_VAL_200_UK },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_uk = {
   option_cats_uk,
   option_defs_uk
};

/* RETRO_LANGUAGE_VAL */

#define CATEGORY_SYSTEM_LABEL_VAL NULL
#define CATEGORY_SYSTEM_INFO_0_VAL NULL
#define CATEGORY_VIDEO_LABEL_VAL "Vídeo"
#define CATEGORY_VIDEO_INFO_0_VAL NULL
#define CATEGORY_AUDIO_LABEL_VAL "Àudio"
#define CATEGORY_AUDIO_INFO_0_VAL NULL
#define CATEGORY_CONTROLS_LABEL_VAL NULL
#define CATEGORY_CONTROLS_INFO_0_VAL NULL
#define CATEGORY_CHIHIRO_LABEL_VAL NULL
#define CATEGORY_CHIHIRO_INFO_0_VAL NULL
#define XEMU_MEMORY_LABEL_VAL NULL
#define XEMU_MEMORY_INFO_0_VAL NULL
#define OPTION_VAL_64_VAL NULL
#define OPTION_VAL_128_VAL NULL
#define XEMU_NETWORK_BACKEND_LABEL_VAL NULL
#define XEMU_NETWORK_BACKEND_INFO_0_VAL NULL
#define OPTION_VAL_NAT_VAL NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_VAL NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_VAL NULL
#define XEMU_HARD_FPU_LABEL_VAL NULL
#define XEMU_HARD_FPU_INFO_0_VAL NULL
#define XEMU_CPU_BOOST_LABEL_VAL NULL
#define XEMU_CPU_BOOST_INFO_0_VAL NULL
#define XEMU_HDD_TRIM_LABEL_VAL NULL
#define XEMU_HDD_TRIM_INFO_0_VAL NULL
#define XEMU_RENDERER_LABEL_VAL NULL
#define XEMU_RENDERER_INFO_0_VAL NULL
#define OPTION_VAL_VULKAN_VAL NULL
#define OPTION_VAL_OPENGL_VAL NULL
#define XEMU_VIDEO_ASPECT_LABEL_VAL NULL
#define XEMU_VIDEO_ASPECT_INFO_0_VAL NULL
#define OPTION_VAL_DASHBOARD_VAL NULL
#define OPTION_VAL_4_3_VAL NULL
#define OPTION_VAL_16_9_VAL NULL
#define OPTION_VAL_LETTERBOX_VAL NULL
#define XEMU_ASPECT_RATIO_LABEL_VAL NULL
#define XEMU_ASPECT_RATIO_INFO_0_VAL NULL
#define OPTION_VAL_AUTO_VAL "Selecció automàtica"
#define XEMU_SURFACE_SCALE_LABEL_VAL NULL
#define XEMU_SURFACE_SCALE_INFO_0_VAL NULL
#define OPTION_VAL_1_VAL NULL
#define OPTION_VAL_2_VAL NULL
#define OPTION_VAL_3_VAL NULL
#define OPTION_VAL_4_VAL NULL
#define OPTION_VAL_5_VAL NULL
#define OPTION_VAL_6_VAL NULL
#define OPTION_VAL_7_VAL NULL
#define OPTION_VAL_8_VAL NULL
#define OPTION_VAL_9_VAL NULL
#define OPTION_VAL_10_VAL NULL
#define XEMU_AVPACK_LABEL_VAL NULL
#define XEMU_AVPACK_INFO_0_VAL NULL
#define OPTION_VAL_HDTV_VAL NULL
#define OPTION_VAL_COMPOSITE_VAL NULL
#define OPTION_VAL_SVIDEO_VAL NULL
#define OPTION_VAL_SCART_VAL NULL
#define OPTION_VAL_VGA_VAL NULL
#define XEMU_AUDIO_THREAD_LABEL_VAL NULL
#define XEMU_AUDIO_THREAD_INFO_0_VAL NULL
#define XEMU_USE_DSP_LABEL_VAL NULL
#define XEMU_USE_DSP_INFO_0_VAL NULL
#define XEMU_DSP_JIT_LABEL_VAL NULL
#define XEMU_DSP_JIT_INFO_0_VAL NULL
#define XEMU_HRTF_LABEL_VAL NULL
#define XEMU_HRTF_INFO_0_VAL NULL
#define XEMU_VP_WORKERS_LABEL_VAL NULL
#define XEMU_VP_WORKERS_INFO_0_VAL NULL
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_VAL NULL
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_VAL NULL
#define XEMU_AUDIO_VOLUME_LABEL_VAL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_VAL NULL
#define OPTION_VAL_100_VAL NULL
#define OPTION_VAL_80_VAL NULL
#define OPTION_VAL_60_VAL NULL
#define OPTION_VAL_40_VAL NULL
#define OPTION_VAL_20_VAL NULL
#define OPTION_VAL_0_VAL NULL
#define XEMU_VK_FAST_PATHS_LABEL_VAL NULL
#define XEMU_VK_FAST_PATHS_INFO_0_VAL NULL
#define OPTION_VAL_ALL_VAL NULL
#define OPTION_VAL_NO_GPL_VAL NULL
#define OPTION_VAL_NO_DYN_VAL NULL
#define OPTION_VAL_NONE_VAL "Cap"
#define XEMU_RUMBLE_P1_LABEL_VAL NULL
#define XEMU_RUMBLE_P1_INFO_0_VAL NULL
#define XEMU_RUMBLE_P2_LABEL_VAL NULL
#define XEMU_RUMBLE_P2_INFO_0_VAL NULL
#define XEMU_DEADZONE_P1_LABEL_VAL NULL
#define XEMU_DEADZONE_P1_INFO_0_VAL NULL
#define OPTION_VAL_0_XEMU_DEADZONE_P1_VAL NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_VAL NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_VAL NULL
#define OPTION_VAL_15_VAL NULL
#define OPTION_VAL_25_VAL NULL
#define OPTION_VAL_30_VAL NULL
#define XEMU_DEADZONE_P2_LABEL_VAL NULL
#define XEMU_DEADZONE_P2_INFO_0_VAL NULL
#define XEMU_CHIHIRO_FREEPLAY_LABEL_VAL NULL
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_VAL NULL
#define XEMU_CHIHIRO_GUN_AIM_LABEL_VAL NULL
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_VAL NULL
#define OPTION_VAL_MOUSE_VAL NULL
#define OPTION_VAL_STICK_VAL NULL
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_VAL NULL
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_VAL NULL
#define XEMU_CHIHIRO_FFB_LABEL_VAL NULL
#define XEMU_CHIHIRO_FFB_INFO_0_VAL NULL
#define OPTION_VAL_50_VAL NULL
#define OPTION_VAL_75_VAL NULL
#define OPTION_VAL_150_VAL NULL
#define OPTION_VAL_200_VAL NULL

struct retro_core_option_v2_category option_cats_val[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_VAL,
        CATEGORY_SYSTEM_INFO_0_VAL
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_VAL,
        CATEGORY_VIDEO_INFO_0_VAL
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_VAL,
        CATEGORY_AUDIO_INFO_0_VAL
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_VAL,
        CATEGORY_CONTROLS_INFO_0_VAL
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_VAL,
        CATEGORY_CHIHIRO_INFO_0_VAL
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_val[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_VAL,
        NULL,
        XEMU_MEMORY_INFO_0_VAL,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_VAL },
            { "128", OPTION_VAL_128_VAL },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_VAL,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_VAL,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_VAL },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_VAL,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_VAL,
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
        XEMU_HARD_FPU_LABEL_VAL,
        NULL,
        XEMU_HARD_FPU_INFO_0_VAL,
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
        XEMU_CPU_BOOST_LABEL_VAL,
        NULL,
        XEMU_CPU_BOOST_INFO_0_VAL,
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
        XEMU_HDD_TRIM_LABEL_VAL,
        NULL,
        XEMU_HDD_TRIM_INFO_0_VAL,
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
        XEMU_RENDERER_LABEL_VAL,
        NULL,
        XEMU_RENDERER_INFO_0_VAL,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_VAL },
            { "opengl", OPTION_VAL_OPENGL_VAL },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_VAL,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_VAL,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_VAL },
            { "4:3",       OPTION_VAL_4_3_VAL },
            { "16:9",      OPTION_VAL_16_9_VAL },
            { "letterbox", OPTION_VAL_LETTERBOX_VAL },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_VAL,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_VAL,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_VAL },
            { "4:3",  OPTION_VAL_4_3_VAL },
            { "16:9", OPTION_VAL_16_9_VAL },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_VAL,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_VAL,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_VAL },
            { "2", OPTION_VAL_2_VAL },
            { "3", OPTION_VAL_3_VAL },
            { "4", OPTION_VAL_4_VAL },
            { "5", OPTION_VAL_5_VAL },
            { "6", OPTION_VAL_6_VAL },
            { "7", OPTION_VAL_7_VAL },
            { "8", OPTION_VAL_8_VAL },
            { "9", OPTION_VAL_9_VAL },
            { "10", OPTION_VAL_10_VAL },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_VAL,
        NULL,
        XEMU_AVPACK_INFO_0_VAL,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_VAL },
            { "composite", OPTION_VAL_COMPOSITE_VAL },
            { "svideo",    OPTION_VAL_SVIDEO_VAL },
            { "scart",     OPTION_VAL_SCART_VAL },
            { "vga",       OPTION_VAL_VGA_VAL },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_VAL,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_VAL,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_VAL,
        NULL,
        XEMU_USE_DSP_INFO_0_VAL,
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
        XEMU_DSP_JIT_LABEL_VAL,
        NULL,
        XEMU_DSP_JIT_INFO_0_VAL,
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
        XEMU_HRTF_LABEL_VAL,
        NULL,
        XEMU_HRTF_INFO_0_VAL,
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
        XEMU_VP_WORKERS_LABEL_VAL,
        NULL,
        XEMU_VP_WORKERS_INFO_0_VAL,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_VAL },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_VAL,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_VAL,
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
        XEMU_AUDIO_VOLUME_LABEL_VAL,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_VAL,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_VAL },
            { "80",  OPTION_VAL_80_VAL },
            { "60",  OPTION_VAL_60_VAL },
            { "40",  OPTION_VAL_40_VAL },
            { "20",  OPTION_VAL_20_VAL },
            { "0",   OPTION_VAL_0_VAL },
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
        XEMU_VK_FAST_PATHS_LABEL_VAL,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_VAL,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_VAL },
            { "no_gpl",   OPTION_VAL_NO_GPL_VAL },
            { "no_dyn",   OPTION_VAL_NO_DYN_VAL },
            { "none",     OPTION_VAL_NONE_VAL },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_VAL,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_VAL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_VAL,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_VAL,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_VAL,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_VAL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_VAL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_VAL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_VAL },
            { "15", OPTION_VAL_15_VAL },
            { "20", OPTION_VAL_20_VAL },
            { "25", OPTION_VAL_25_VAL },
            { "30", OPTION_VAL_30_VAL },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_VAL,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_VAL,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_VAL },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_VAL },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_VAL },
            { "15", OPTION_VAL_15_VAL },
            { "20", OPTION_VAL_20_VAL },
            { "25", OPTION_VAL_25_VAL },
            { "30", OPTION_VAL_30_VAL },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_VAL,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_VAL,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_VAL,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_VAL,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_VAL },
            { "stick", OPTION_VAL_STICK_VAL },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_VAL,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_VAL,
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
        XEMU_CHIHIRO_FFB_LABEL_VAL,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_VAL,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_VAL },
            { "50",  OPTION_VAL_50_VAL },
            { "75",  OPTION_VAL_75_VAL },
            { "100", OPTION_VAL_100_VAL },
            { "150", OPTION_VAL_150_VAL },
            { "200", OPTION_VAL_200_VAL },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_val = {
   option_cats_val,
   option_defs_val
};

/* RETRO_LANGUAGE_VN */

#define CATEGORY_SYSTEM_LABEL_VN "Hệ thống (khởi động lại)"
#define CATEGORY_SYSTEM_INFO_0_VN "Bản thân máy chơi game: bộ nhớ, mạng, quá trình khởi động và bộ xử lý. Các thiết lập này được áp dụng khi nội dung bắt đầu chạy (dọn ổ cứng khi đóng sẽ được thực hiện lúc nội dung đóng)."
#define CATEGORY_VIDEO_LABEL_VN NULL
#define CATEGORY_VIDEO_INFO_0_VN "Cấu hình các thiết lập Dựng hình hình ảnh."
#define CATEGORY_AUDIO_LABEL_VN "Âm thanh"
#define CATEGORY_AUDIO_INFO_0_VN "Cấu hình các thiết lập mô phỏng âm thanh."
#define CATEGORY_CONTROLS_LABEL_VN "Điều khiển"
#define CATEGORY_CONTROLS_INFO_0_VN "Độ rung và vùng chết của cần analog, áp dụng riêng cho từng người chơi."
#define CATEGORY_CHIHIRO_LABEL_VN NULL
#define CATEGORY_CHIHIRO_INFO_0_VN "Các trò chơi thùng máy Sega Chihiro: chơi miễn phí, ngắm bắn trong các trò chơi bắn súng và phản hồi lực trong các trò chơi đua xe."
#define XEMU_MEMORY_LABEL_VN "Bộ nhớ hệ thống (MB)"
#define XEMU_MEMORY_INFO_0_VN "Dung lượng bộ nhớ RAM của hệ thống. 64 MB là tiêu chuẩn; 128 MB được sử dụng trên các bộ máy dành cho gỡ lỗi."
#define OPTION_VAL_64_VN NULL
#define OPTION_VAL_128_VN NULL
#define XEMU_NETWORK_BACKEND_LABEL_VN "Nền tảng mạng"
#define XEMU_NETWORK_BACKEND_INFO_0_VN "Bật hỗ trợ mạng cho các trò chơi Xbox có tính năng mạng nội bộ hoặc liên kết hệ thống. Nền tảng NAT cung cấp khả năng kết nối cơ bản."
#define OPTION_VAL_NAT_VN NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_VN "Bỏ qua hoạt ảnh khởi động"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_VN "Bỏ qua hoạt ảnh khởi động của Xbox."
#define XEMU_HARD_FPU_LABEL_VN "Mô phỏng bộ xử lý dấu phẩy động bằng phần cứng"
#define XEMU_HARD_FPU_INFO_0_VN "Sử dụng bộ xử lý dấu phẩy động của máy chủ để mô phỏng x87. Tốc độ nhanh hơn nhưng có thể có một số sai lệch nhỏ."
#define XEMU_CPU_BOOST_LABEL_VN "Tăng tốc bộ xử lý"
#define XEMU_CPU_BOOST_INFO_0_VN "Các phương thức xử lý nhanh hơn cho bộ xử lý của máy được mô phỏng và bộ xử lý âm thanh: sử dụng trực tiếp tập lệnh SSE và bộ nhớ đệm lệnh nhảy lớn hơn. Tắt nếu trò chơi hoạt động bất thường."
#define XEMU_HDD_TRIM_LABEL_VN "Dọn ổ cứng khi đóng"
#define XEMU_HDD_TRIM_INFO_0_VN "Khi trò chơi đóng, xóa các phân vùng bộ nhớ đệm X, Y và Z trên ổ cứng (trò chơi sẽ định dạng lại chúng khi cần) và ghi lại ảnh ổ đĩa để loại bỏ phần dung lượng không sử dụng, giúp giảm kích thước tệp. Tạm thời cần dung lượng trống tương đương với lượng dữ liệu trong ảnh ổ đĩa. Không thực hiện nếu ảnh ổ đĩa đang chứa trạng thái lưu. Thao tác được thực hiện khi trò chơi đóng, không phải khi khởi chạy lần tiếp theo."
#define XEMU_RENDERER_LABEL_VN "Giao diện lập trình đồ họa (cần khởi động lại)"
#define XEMU_RENDERER_INFO_0_VN "Bộ Dựng hình được dùng để vẽ hình ảnh từ bộ xử lý đồ họa mô phỏng. Vulkan là lựa chọn mặc định; OpenGL là phương án thay thế cho các trình điều khiển gặp lỗi với Vulkan. Thiết lập có hiệu lực sau khi khởi động lại RetroArch. Trên Android luôn sử dụng Vulkan, trên macOS luôn sử dụng OpenGL."
#define OPTION_VAL_VULKAN_VN NULL
#define OPTION_VAL_OPENGL_VN NULL
#define XEMU_VIDEO_ASPECT_LABEL_VN "Tỷ lệ khung hình của hệ máy (cần khởi động lại)"
#define XEMU_VIDEO_ASPECT_INFO_0_VN "Tỷ lệ khung hình mà cài đặt video của máy chơi game cung cấp cho trò chơi, thay cho cài đặt của bảng điều khiển chính. Ở tỷ lệ 16:9, các trò chơi hỗ trợ màn hình rộng sẽ chạy ở chế độ màn hình rộng; ở tỷ lệ 4:3, chúng sẽ chạy ở tỷ lệ 4:3. Hãy đặt theo tỷ lệ màn hình của bạn. Chế độ viền đen giữ tỷ lệ 4:3 của bảng điều khiển chính và thêm viền đen cho các trò chơi màn hình rộng. Bảng điều khiển chính giữ nguyên cài đặt của bảng điều khiển chính."
#define OPTION_VAL_DASHBOARD_VN "Bảng điều khiển chính"
#define OPTION_VAL_4_3_VN NULL
#define OPTION_VAL_16_9_VN NULL
#define OPTION_VAL_LETTERBOX_VN "Viền đen"
#define XEMU_ASPECT_RATIO_LABEL_VN "Tỷ lệ khung hình của trình giả lập"
#define XEMU_ASPECT_RATIO_INFO_0_VN "Tỷ lệ khung hình khi hình ảnh được hiển thị. Tốt nhất nên để ở chế độ Tự động, chế độ này sẽ làm theo trò chơi: 16:9 khi máy chơi game được đặt ở chế độ màn hình rộng (Tỷ lệ khung hình của hệ máy hoặc bảng điều khiển chính) và trò chơi xuất hình ảnh ở tỷ lệ 16:9; nếu không thì là 4:3, đồng thời luôn là 4:3 trên Chihiro. Tỷ lệ 16:9 kéo giãn trò chơi 4:3 thành màn hình rộng."
#define OPTION_VAL_AUTO_VN "Tự động"
#define XEMU_SURFACE_SCALE_LABEL_VN "Tỷ lệ độ phân giải nội bộ (cần khởi động lại)"
#define XEMU_SURFACE_SCALE_INFO_0_VN "Điều chỉnh độ phân giải Dựng hình nội bộ. Giá trị cao hơn cải thiện chất lượng hình ảnh nhưng làm giảm hiệu năng."
#define OPTION_VAL_1_VN NULL
#define OPTION_VAL_2_VN NULL
#define OPTION_VAL_3_VN NULL
#define OPTION_VAL_4_VN NULL
#define OPTION_VAL_5_VN NULL
#define OPTION_VAL_6_VN NULL
#define OPTION_VAL_7_VN NULL
#define OPTION_VAL_8_VN NULL
#define OPTION_VAL_9_VN NULL
#define OPTION_VAL_10_VN NULL
#define XEMU_AVPACK_LABEL_VN "Bộ kết nối âm thanh hình ảnh (khởi động lại)"
#define XEMU_AVPACK_INFO_0_VN "Chọn loại bộ kết nối âm thanh và hình ảnh. Ảnh hưởng đến các chế độ video khả dụng."
#define OPTION_VAL_HDTV_VN NULL
#define OPTION_VAL_COMPOSITE_VN "Kết hợp"
#define OPTION_VAL_SVIDEO_VN NULL
#define OPTION_VAL_SCART_VN NULL
#define OPTION_VAL_VGA_VN NULL
#define XEMU_AUDIO_THREAD_LABEL_VN "Luồng âm thanh (Cần khởi động lại)"
#define XEMU_AUDIO_THREAD_INFO_0_VN "Chuyển âm thanh sang luồng âm thanh của RetroArch ngay khi bộ xử lý âm thanh của máy chơi game trộn xong, giống như khi chạy độc lập, thay vì gửi lượng âm thanh tương ứng với một khung hình ở mỗi khung hình: âm thanh vẫn tiếp tục phát khi khung hình bị khựng, chẳng hạn như lúc biên dịch bộ đổ bóng."
#define XEMU_USE_DSP_LABEL_VN "Mô phỏng bộ xử lý tín hiệu số của APU"
#define XEMU_USE_DSP_INFO_0_VN "Bật mô phỏng bộ xử lý tín hiệu số để tăng độ chính xác của âm thanh. Có thể ảnh hưởng đến hiệu năng."
#define XEMU_DSP_JIT_LABEL_VN "Biên dịch tức thời bộ xử lý tín hiệu số"
#define XEMU_DSP_JIT_INFO_0_VN "Chạy các chương trình của bộ xử lý tín hiệu số trong mô phỏng bộ xử lý âm thanh dưới dạng mã đã biên dịch thay vì thông dịch, giúp tăng tốc, tương tự chức năng biên dịch tức thời bộ xử lý tín hiệu số của bản độc lập. Chỉ có tác dụng khi bật mô phỏng bộ xử lý âm thanh."
#define XEMU_HRTF_LABEL_VN "Mô phỏng âm thanh theo đặc tính truyền âm của đầu người"
#define XEMU_HRTF_INFO_0_VN "Định vị âm thanh ba chiều của trò chơi có hỗ trợ bằng cách sử dụng hàm truyền đạt liên quan đến đầu người, giống như trên máy chơi game gốc, dành cho tai nghe và loa âm thanh nổi."
#define XEMU_VP_WORKERS_LABEL_VN "Số luồng xử lý giọng nói (khởi động lại)"
#define XEMU_VP_WORKERS_INFO_0_VN "Số luồng dùng để xử lý và phối trộn các âm thanh giọng nói. Tự động sử dụng một luồng cho mỗi lõi bộ xử lý."
#define XEMU_SMOOTH_FIRST_PLAY_LABEL_VN "Làm mượt lần chơi đầu tiên (cần khởi động lại)"
#define XEMU_SMOOTH_FIRST_PLAY_INFO_0_VN "Biên dịch các bộ đổ bóng mà trò chơi dự kiến sử dụng ngay trong quá trình khởi động, giúp tránh hiện tượng giật khựng trong những phút đầu khi chúng được biên dịch. Với OpenGL, các bộ đổ bóng đã biên dịch được lưu trong bộ nhớ đệm bộ đổ bóng, tính năng này luôn được bật."
#define XEMU_AUDIO_VOLUME_LABEL_VN "Giới hạn âm lượng (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_VN "Giới hạn âm lượng đầu ra của Xbox độc lập với âm lượng tổng của RetroArch."
#define OPTION_VAL_100_VN NULL
#define OPTION_VAL_80_VN NULL
#define OPTION_VAL_60_VN NULL
#define OPTION_VAL_40_VN NULL
#define OPTION_VAL_20_VN NULL
#define OPTION_VAL_0_VN "Đã tắt tiếng"
#define XEMU_VK_FAST_PATHS_LABEL_VN "Các phương thức tăng tốc Vulkan (cần khởi động lại)"
#define XEMU_VK_FAST_PATHS_INFO_0_VN "Ảnh hưởng đến tốc độ biên dịch bộ đổ bóng trên Vulkan. \"Tất cả\" là lựa chọn nhanh nhất nhưng có thể khiến một số trò chơi bị lỗi."
#define OPTION_VAL_ALL_VN "Tất cả"
#define OPTION_VAL_NO_GPL_VN "Không dùng thư viện quy trình xử lý"
#define OPTION_VAL_NO_DYN_VN "Không dùng trạng thái động"
#define OPTION_VAL_NONE_VN "Không"
#define XEMU_RUMBLE_P1_LABEL_VN "Độ rung (người chơi 1)"
#define XEMU_RUMBLE_P1_INFO_0_VN "Tay cầm của người chơi 1 rung theo phản hồi từ các trò chơi Xbox và phản hồi lực trong một trò đua xe Chihiro. Tắt để vô hiệu hóa cả hai loại rung."
#define XEMU_RUMBLE_P2_LABEL_VN "Độ rung (người chơi 2)"
#define XEMU_RUMBLE_P2_INFO_0_VN "Tay cầm của người chơi 2 rung theo phản hồi từ các trò chơi Xbox và phản hồi lực trong một trò đua xe Chihiro. Tắt để vô hiệu hóa cả hai loại rung."
#define XEMU_DEADZONE_P1_LABEL_VN "Vùng chết cần analog (người chơi 1)"
#define XEMU_DEADZONE_P1_INFO_0_VN "Khoảng di chuyển mà các cần analog của người chơi 1 có thể dịch chuyển trước khi trò chơi nhận được tín hiệu, áp dụng cho cả hai cần trên Xbox và Chihiro; phần hành trình còn lại được tăng tỷ lệ để đạt mức tối đa."
#define OPTION_VAL_0_XEMU_DEADZONE_P1_VN NULL
#define OPTION_VAL_5_XEMU_DEADZONE_P1_VN NULL
#define OPTION_VAL_10_XEMU_DEADZONE_P1_VN NULL
#define OPTION_VAL_15_VN NULL
#define OPTION_VAL_25_VN NULL
#define OPTION_VAL_30_VN NULL
#define XEMU_DEADZONE_P2_LABEL_VN "Vùng chết cần analog (người chơi 2)"
#define XEMU_DEADZONE_P2_INFO_0_VN "Khoảng di chuyển mà các cần analog của người chơi 2 có thể dịch chuyển trước khi trò chơi nhận được tín hiệu, áp dụng cho cả hai cần trên Xbox và Chihiro; phần hành trình còn lại được tăng tỷ lệ để đạt mức tối đa."
#define XEMU_CHIHIRO_FREEPLAY_LABEL_VN "Chơi miễn phí (cần khởi động lại)"
#define XEMU_CHIHIRO_FREEPLAY_INFO_0_VN "Khởi chạy các trò chơi Sega Chihiro ở chế độ chơi miễn phí, không cần xu. Khi tắt, nhấn nút Chọn để bỏ xu vào máy."
#define XEMU_CHIHIRO_GUN_AIM_LABEL_VN "Ngắm bắn bằng súng quang"
#define XEMU_CHIHIRO_GUN_AIM_INFO_0_VN "Cách ngắm bắn trong House of the Dead III, Virtua Cop 3 và Ghost Squad. Chuột: dùng chuột (hoặc súng quang của RetroArch) để ngắm, nút trái để bắn, nút phải để dùng nút chức năng của súng (bơm đạn, đổi vũ khí), nút giữa để đạp bàn đạp hoặc điều chỉnh tốc độ bắn. Cần analog: dùng cần trái hoặc bàn phím điều hướng để ngắm, R2 để bắn, L2 để dùng nút chức năng của súng, L để đạp bàn đạp hoặc điều chỉnh tốc độ bắn, R để bắn ra ngoài màn hình."
#define OPTION_VAL_MOUSE_VN "Chuột"
#define OPTION_VAL_STICK_VN "Cần analog"
#define XEMU_CHIHIRO_CROSSHAIR_LABEL_VN "Tâm ngắm"
#define XEMU_CHIHIRO_CROSSHAIR_INFO_0_VN "Hiển thị tâm ngắm của từng người chơi trên hình ảnh, người chơi 1 màu đỏ, người chơi 2 màu xanh dương."
#define XEMU_CHIHIRO_FFB_LABEL_VN "Rung phản hồi lực"
#define XEMU_CHIHIRO_FFB_INFO_0_VN "Truyền phản hồi lực của các trò chơi đua xe Chihiro (OutRun 2, Maximum Tune) thành rung trên tay cầm ở cổng 1, với cường độ này."
#define OPTION_VAL_50_VN NULL
#define OPTION_VAL_75_VN NULL
#define OPTION_VAL_150_VN NULL
#define OPTION_VAL_200_VN NULL

struct retro_core_option_v2_category option_cats_vn[] = {
    {
        "system",
        CATEGORY_SYSTEM_LABEL_VN,
        CATEGORY_SYSTEM_INFO_0_VN
    },
    {
        "video",
        CATEGORY_VIDEO_LABEL_VN,
        CATEGORY_VIDEO_INFO_0_VN
    },
    {
        "audio",
        CATEGORY_AUDIO_LABEL_VN,
        CATEGORY_AUDIO_INFO_0_VN
    },
    {
        "controls",
        CATEGORY_CONTROLS_LABEL_VN,
        CATEGORY_CONTROLS_INFO_0_VN
    },
    {
        "chihiro",
        CATEGORY_CHIHIRO_LABEL_VN,
        CATEGORY_CHIHIRO_INFO_0_VN
    },
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_vn[] = {
    {
        "xemu_memory",
        XEMU_MEMORY_LABEL_VN,
        NULL,
        XEMU_MEMORY_INFO_0_VN,
        NULL,
        "system",
        {
            { "64",  OPTION_VAL_64_VN },
            { "128", OPTION_VAL_128_VN },
            { NULL, NULL },
        },
        "64"
    },
    {
        "xemu_network_backend",
        XEMU_NETWORK_BACKEND_LABEL_VN,
        NULL,
        XEMU_NETWORK_BACKEND_INFO_0_VN,
        NULL,
        "system",
        {
            { "disabled", "Disabled" },
            { "nat",      OPTION_VAL_NAT_VN },
            { NULL, NULL },
        },
        "disabled"
    },
    /* On by default, unlike standalone: it breaks nothing, and the animation
     * only holds up the game (NNshi) */
    {
        "xemu_skip_boot_anim",
        XEMU_SKIP_BOOT_ANIM_LABEL_VN,
        NULL,
        XEMU_SKIP_BOOT_ANIM_INFO_0_VN,
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
        XEMU_HARD_FPU_LABEL_VN,
        NULL,
        XEMU_HARD_FPU_INFO_0_VN,
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
        XEMU_CPU_BOOST_LABEL_VN,
        NULL,
        XEMU_CPU_BOOST_INFO_0_VN,
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
        XEMU_HDD_TRIM_LABEL_VN,
        NULL,
        XEMU_HDD_TRIM_INFO_0_VN,
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
        XEMU_RENDERER_LABEL_VN,
        NULL,
        XEMU_RENDERER_INFO_0_VN,
        NULL,
        "video",
        {
            { "vulkan", OPTION_VAL_VULKAN_VN },
            { "opengl", OPTION_VAL_OPENGL_VN },
            { NULL, NULL },
        },
        "vulkan"
    },
    /* 16:9 by default, unlike standalone's dashboard setting: the core is for
     * computers, whose displays are 16:9 nearly always, and no one should
     * have to go to the dashboard first (NNshi) */
    {
        "xemu_video_aspect",
        XEMU_VIDEO_ASPECT_LABEL_VN,
        NULL,
        XEMU_VIDEO_ASPECT_INFO_0_VN,
        NULL,
        "video",
        {
            { "dashboard", OPTION_VAL_DASHBOARD_VN },
            { "4:3",       OPTION_VAL_4_3_VN },
            { "16:9",      OPTION_VAL_16_9_VN },
            { "letterbox", OPTION_VAL_LETTERBOX_VN },
            { NULL, NULL },
        },
        "16:9"
    },
    {
        "xemu_aspect_ratio",
        XEMU_ASPECT_RATIO_LABEL_VN,
        NULL,
        XEMU_ASPECT_RATIO_INFO_0_VN,
        NULL,
        "video",
        {
            { "auto", OPTION_VAL_AUTO_VN },
            { "4:3",  OPTION_VAL_4_3_VN },
            { "16:9", OPTION_VAL_16_9_VN },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        XEMU_SURFACE_SCALE_LABEL_VN,
        NULL,
        XEMU_SURFACE_SCALE_INFO_0_VN,
        NULL,
        "video",
        {
            { "1", OPTION_VAL_1_VN },
            { "2", OPTION_VAL_2_VN },
            { "3", OPTION_VAL_3_VN },
            { "4", OPTION_VAL_4_VN },
            { "5", OPTION_VAL_5_VN },
            { "6", OPTION_VAL_6_VN },
            { "7", OPTION_VAL_7_VN },
            { "8", OPTION_VAL_8_VN },
            { "9", OPTION_VAL_9_VN },
            { "10", OPTION_VAL_10_VN },
            { NULL, NULL },
        },
        "1"
    },
    {
        "xemu_avpack",
        XEMU_AVPACK_LABEL_VN,
        NULL,
        XEMU_AVPACK_INFO_0_VN,
        NULL,
        "video",
        {
            { "hdtv",      OPTION_VAL_HDTV_VN },
            { "composite", OPTION_VAL_COMPOSITE_VN },
            { "svideo",    OPTION_VAL_SVIDEO_VN },
            { "scart",     OPTION_VAL_SCART_VN },
            { "vga",       OPTION_VAL_VGA_VN },
            { NULL, NULL },
        },
        "hdtv"
    },
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        XEMU_AUDIO_THREAD_LABEL_VN,
        NULL,
        XEMU_AUDIO_THREAD_INFO_0_VN,
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_use_dsp",
        XEMU_USE_DSP_LABEL_VN,
        NULL,
        XEMU_USE_DSP_INFO_0_VN,
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
        XEMU_DSP_JIT_LABEL_VN,
        NULL,
        XEMU_DSP_JIT_INFO_0_VN,
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
        XEMU_HRTF_LABEL_VN,
        NULL,
        XEMU_HRTF_INFO_0_VN,
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
        XEMU_VP_WORKERS_LABEL_VN,
        NULL,
        XEMU_VP_WORKERS_INFO_0_VN,
        NULL,
        "audio",
        {
            { "0", OPTION_VAL_AUTO_VN },
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
        XEMU_SMOOTH_FIRST_PLAY_LABEL_VN,
        NULL,
        XEMU_SMOOTH_FIRST_PLAY_INFO_0_VN,
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
        XEMU_AUDIO_VOLUME_LABEL_VN,
        NULL,
        XEMU_AUDIO_VOLUME_INFO_0_VN,
        NULL,
        "audio",
        {
            { "100", OPTION_VAL_100_VN },
            { "80",  OPTION_VAL_80_VN },
            { "60",  OPTION_VAL_60_VN },
            { "40",  OPTION_VAL_40_VN },
            { "20",  OPTION_VAL_20_VN },
            { "0",   OPTION_VAL_0_VN },
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
        XEMU_VK_FAST_PATHS_LABEL_VN,
        NULL,
        XEMU_VK_FAST_PATHS_INFO_0_VN,
        NULL,
        "video",
        {
            { "all",      OPTION_VAL_ALL_VN },
            { "no_gpl",   OPTION_VAL_NO_GPL_VN },
            { "no_dyn",   OPTION_VAL_NO_DYN_VN },
            { "none",     OPTION_VAL_NONE_VN },
            { NULL, NULL },
        },
        "no_gpl"
    },
    {
        "xemu_rumble_p1",
        XEMU_RUMBLE_P1_LABEL_VN,
        NULL,
        XEMU_RUMBLE_P1_INFO_0_VN,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_rumble_p2",
        XEMU_RUMBLE_P2_LABEL_VN,
        NULL,
        XEMU_RUMBLE_P2_INFO_0_VN,
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p1",
        XEMU_DEADZONE_P1_LABEL_VN,
        NULL,
        XEMU_DEADZONE_P1_INFO_0_VN,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_VN },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_VN },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_VN },
            { "15", OPTION_VAL_15_VN },
            { "20", OPTION_VAL_20_VN },
            { "25", OPTION_VAL_25_VN },
            { "30", OPTION_VAL_30_VN },
            { NULL, NULL },
        },
        "10"
    },
    /* 10% by default: a stick at rest is rarely at 0, and OutRun 2 stops
     * at a drive board error when the wheel is not centred during its test
     * (NNshi) */
    {
        "xemu_deadzone_p2",
        XEMU_DEADZONE_P2_LABEL_VN,
        NULL,
        XEMU_DEADZONE_P2_INFO_0_VN,
        NULL,
        "controls",
        {
            { "0",  OPTION_VAL_0_XEMU_DEADZONE_P1_VN },
            { "5",  OPTION_VAL_5_XEMU_DEADZONE_P1_VN },
            { "10", OPTION_VAL_10_XEMU_DEADZONE_P1_VN },
            { "15", OPTION_VAL_15_VN },
            { "20", OPTION_VAL_20_VN },
            { "25", OPTION_VAL_25_VN },
            { "30", OPTION_VAL_30_VN },
            { NULL, NULL },
        },
        "10"
    },
    /* The Chihiro's options last: their category goes last (RetroArch lists
     * the categories in the order their first options come) */
    /* On by default, unlike standalone: a cabinet at home has no coins to
     * put in, and NNshi asked for it to start that way (Select still
     * inserts a coin when it is off) */
    {
        "xemu_chihiro_freeplay",
        XEMU_CHIHIRO_FREEPLAY_LABEL_VN,
        NULL,
        XEMU_CHIHIRO_FREEPLAY_INFO_0_VN,
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
        XEMU_CHIHIRO_GUN_AIM_LABEL_VN,
        NULL,
        XEMU_CHIHIRO_GUN_AIM_INFO_0_VN,
        NULL,
        "chihiro",
        {
            { "mouse", OPTION_VAL_MOUSE_VN },
            { "stick", OPTION_VAL_STICK_VN },
            { NULL, NULL },
        },
        "stick"
    },
    /* On by default: standalone shows the mouse cursor the light gun aims
     * with; a real light gun has no use for it */
    {
        "xemu_chihiro_crosshair",
        XEMU_CHIHIRO_CROSSHAIR_LABEL_VN,
        NULL,
        XEMU_CHIHIRO_CROSSHAIR_INFO_0_VN,
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
        XEMU_CHIHIRO_FFB_LABEL_VN,
        NULL,
        XEMU_CHIHIRO_FFB_INFO_0_VN,
        NULL,
        "chihiro",
        {
            { "disabled", "Disabled" },
            { "25",  OPTION_VAL_25_VN },
            { "50",  OPTION_VAL_50_VN },
            { "75",  OPTION_VAL_75_VN },
            { "100", OPTION_VAL_100_VN },
            { "150", OPTION_VAL_150_VN },
            { "200", OPTION_VAL_200_VN },
            { NULL, NULL },
        },
        "100"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_vn = {
   option_cats_vn,
   option_defs_vn
};


#ifdef __cplusplus
}
#endif

#endif