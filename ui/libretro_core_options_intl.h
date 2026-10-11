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
#define CATEGORY_VIDEO_LABEL_AR NULL
#define CATEGORY_VIDEO_INFO_0_AR NULL
#define CATEGORY_AUDIO_LABEL_AR NULL
#define CATEGORY_AUDIO_INFO_0_AR NULL
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
#define XEMU_RENDERER_LABEL_AR NULL
#define XEMU_RENDERER_INFO_0_AR NULL
#define OPTION_VAL_VULKAN_AR NULL
#define OPTION_VAL_OPENGL_AR NULL
#define XEMU_ASPECT_RATIO_LABEL_AR NULL
#define XEMU_ASPECT_RATIO_INFO_0_AR NULL
#define OPTION_VAL_AUTO_AR NULL
#define OPTION_VAL_4_3_AR NULL
#define OPTION_VAL_16_9_AR NULL
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
#define XEMU_USE_DSP_LABEL_AR NULL
#define XEMU_USE_DSP_INFO_0_AR NULL
#define XEMU_CACHE_SHADERS_LABEL_AR NULL
#define XEMU_CACHE_SHADERS_INFO_0_AR NULL
#define XEMU_AUDIO_VOLUME_LABEL_AR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_AR NULL
#define OPTION_VAL_100_AR NULL
#define OPTION_VAL_80_AR NULL
#define OPTION_VAL_60_AR NULL
#define OPTION_VAL_40_AR NULL
#define OPTION_VAL_20_AR NULL
#define OPTION_VAL_0_AR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_AR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_AR NULL
#define OPTION_VAL_LINEAR_AR NULL
#define OPTION_VAL_NEAREST_AR NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ar[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_AR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_AR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_AR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_AR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_AR },
            { "nearest", OPTION_VAL_NEAREST_AR },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_AST NULL
#define CATEGORY_VIDEO_INFO_0_AST NULL
#define CATEGORY_AUDIO_LABEL_AST NULL
#define CATEGORY_AUDIO_INFO_0_AST NULL
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
#define XEMU_RENDERER_LABEL_AST NULL
#define XEMU_RENDERER_INFO_0_AST NULL
#define OPTION_VAL_VULKAN_AST NULL
#define OPTION_VAL_OPENGL_AST NULL
#define XEMU_ASPECT_RATIO_LABEL_AST NULL
#define XEMU_ASPECT_RATIO_INFO_0_AST NULL
#define OPTION_VAL_AUTO_AST NULL
#define OPTION_VAL_4_3_AST NULL
#define OPTION_VAL_16_9_AST NULL
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
#define XEMU_USE_DSP_LABEL_AST NULL
#define XEMU_USE_DSP_INFO_0_AST NULL
#define XEMU_CACHE_SHADERS_LABEL_AST NULL
#define XEMU_CACHE_SHADERS_INFO_0_AST NULL
#define XEMU_AUDIO_VOLUME_LABEL_AST NULL
#define XEMU_AUDIO_VOLUME_INFO_0_AST NULL
#define OPTION_VAL_100_AST NULL
#define OPTION_VAL_80_AST NULL
#define OPTION_VAL_60_AST NULL
#define OPTION_VAL_40_AST NULL
#define OPTION_VAL_20_AST NULL
#define OPTION_VAL_0_AST NULL
#define XEMU_DISPLAY_FILTERING_LABEL_AST NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_AST NULL
#define OPTION_VAL_LINEAR_AST NULL
#define OPTION_VAL_NEAREST_AST NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ast[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_AST,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_AST,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_AST,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_AST,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_AST },
            { "nearest", OPTION_VAL_NEAREST_AST },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_BE NULL
#define CATEGORY_VIDEO_INFO_0_BE NULL
#define CATEGORY_AUDIO_LABEL_BE NULL
#define CATEGORY_AUDIO_INFO_0_BE NULL
#define XEMU_MEMORY_LABEL_BE NULL
#define XEMU_MEMORY_INFO_0_BE NULL
#define OPTION_VAL_64_BE NULL
#define OPTION_VAL_128_BE NULL
#define XEMU_NETWORK_BACKEND_LABEL_BE NULL
#define XEMU_NETWORK_BACKEND_INFO_0_BE NULL
#define OPTION_VAL_NAT_BE NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_BE NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_BE NULL
#define XEMU_HARD_FPU_LABEL_BE NULL
#define XEMU_HARD_FPU_INFO_0_BE NULL
#define XEMU_RENDERER_LABEL_BE NULL
#define XEMU_RENDERER_INFO_0_BE NULL
#define OPTION_VAL_VULKAN_BE NULL
#define OPTION_VAL_OPENGL_BE NULL
#define XEMU_ASPECT_RATIO_LABEL_BE NULL
#define XEMU_ASPECT_RATIO_INFO_0_BE NULL
#define OPTION_VAL_AUTO_BE NULL
#define OPTION_VAL_4_3_BE NULL
#define OPTION_VAL_16_9_BE NULL
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
#define OPTION_VAL_COMPOSITE_BE NULL
#define OPTION_VAL_SVIDEO_BE NULL
#define OPTION_VAL_SCART_BE NULL
#define OPTION_VAL_VGA_BE NULL
#define XEMU_USE_DSP_LABEL_BE NULL
#define XEMU_USE_DSP_INFO_0_BE NULL
#define XEMU_CACHE_SHADERS_LABEL_BE NULL
#define XEMU_CACHE_SHADERS_INFO_0_BE NULL
#define XEMU_AUDIO_VOLUME_LABEL_BE NULL
#define XEMU_AUDIO_VOLUME_INFO_0_BE NULL
#define OPTION_VAL_100_BE NULL
#define OPTION_VAL_80_BE NULL
#define OPTION_VAL_60_BE NULL
#define OPTION_VAL_40_BE NULL
#define OPTION_VAL_20_BE NULL
#define OPTION_VAL_0_BE NULL
#define XEMU_DISPLAY_FILTERING_LABEL_BE NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_BE NULL
#define OPTION_VAL_LINEAR_BE NULL
#define OPTION_VAL_NEAREST_BE NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_be[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_BE,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_BE,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_BE,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_BE,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_BE },
            { "nearest", OPTION_VAL_NEAREST_BE },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_be = {
   option_cats_be,
   option_defs_be
};

/* RETRO_LANGUAGE_CA */

#define CATEGORY_SYSTEM_LABEL_CA NULL
#define CATEGORY_SYSTEM_INFO_0_CA NULL
#define CATEGORY_VIDEO_LABEL_CA NULL
#define CATEGORY_VIDEO_INFO_0_CA NULL
#define CATEGORY_AUDIO_LABEL_CA NULL
#define CATEGORY_AUDIO_INFO_0_CA NULL
#define XEMU_MEMORY_LABEL_CA NULL
#define XEMU_MEMORY_INFO_0_CA NULL
#define OPTION_VAL_64_CA NULL
#define OPTION_VAL_128_CA NULL
#define XEMU_NETWORK_BACKEND_LABEL_CA NULL
#define XEMU_NETWORK_BACKEND_INFO_0_CA NULL
#define OPTION_VAL_NAT_CA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CA NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CA NULL
#define XEMU_HARD_FPU_LABEL_CA NULL
#define XEMU_HARD_FPU_INFO_0_CA NULL
#define XEMU_RENDERER_LABEL_CA NULL
#define XEMU_RENDERER_INFO_0_CA NULL
#define OPTION_VAL_VULKAN_CA NULL
#define OPTION_VAL_OPENGL_CA NULL
#define XEMU_ASPECT_RATIO_LABEL_CA NULL
#define XEMU_ASPECT_RATIO_INFO_0_CA NULL
#define OPTION_VAL_AUTO_CA NULL
#define OPTION_VAL_4_3_CA NULL
#define OPTION_VAL_16_9_CA NULL
#define XEMU_SURFACE_SCALE_LABEL_CA NULL
#define XEMU_SURFACE_SCALE_INFO_0_CA NULL
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
#define XEMU_AVPACK_INFO_0_CA NULL
#define OPTION_VAL_HDTV_CA NULL
#define OPTION_VAL_COMPOSITE_CA NULL
#define OPTION_VAL_SVIDEO_CA NULL
#define OPTION_VAL_SCART_CA NULL
#define OPTION_VAL_VGA_CA NULL
#define XEMU_USE_DSP_LABEL_CA NULL
#define XEMU_USE_DSP_INFO_0_CA NULL
#define XEMU_CACHE_SHADERS_LABEL_CA NULL
#define XEMU_CACHE_SHADERS_INFO_0_CA NULL
#define XEMU_AUDIO_VOLUME_LABEL_CA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CA NULL
#define OPTION_VAL_100_CA NULL
#define OPTION_VAL_80_CA NULL
#define OPTION_VAL_60_CA NULL
#define OPTION_VAL_40_CA NULL
#define OPTION_VAL_20_CA NULL
#define OPTION_VAL_0_CA NULL
#define XEMU_DISPLAY_FILTERING_LABEL_CA NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_CA NULL
#define OPTION_VAL_LINEAR_CA NULL
#define OPTION_VAL_NEAREST_CA NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ca[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_CA,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_CA,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_CA,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_CA,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_CA },
            { "nearest", OPTION_VAL_NEAREST_CA },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_CHS NULL
#define CATEGORY_VIDEO_INFO_0_CHS NULL
#define CATEGORY_AUDIO_LABEL_CHS NULL
#define CATEGORY_AUDIO_INFO_0_CHS NULL
#define XEMU_MEMORY_LABEL_CHS NULL
#define XEMU_MEMORY_INFO_0_CHS NULL
#define OPTION_VAL_64_CHS NULL
#define OPTION_VAL_128_CHS NULL
#define XEMU_NETWORK_BACKEND_LABEL_CHS NULL
#define XEMU_NETWORK_BACKEND_INFO_0_CHS NULL
#define OPTION_VAL_NAT_CHS NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_CHS NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_CHS NULL
#define XEMU_HARD_FPU_LABEL_CHS NULL
#define XEMU_HARD_FPU_INFO_0_CHS NULL
#define XEMU_RENDERER_LABEL_CHS NULL
#define XEMU_RENDERER_INFO_0_CHS NULL
#define OPTION_VAL_VULKAN_CHS NULL
#define OPTION_VAL_OPENGL_CHS NULL
#define XEMU_ASPECT_RATIO_LABEL_CHS NULL
#define XEMU_ASPECT_RATIO_INFO_0_CHS NULL
#define OPTION_VAL_AUTO_CHS NULL
#define OPTION_VAL_4_3_CHS NULL
#define OPTION_VAL_16_9_CHS NULL
#define XEMU_SURFACE_SCALE_LABEL_CHS NULL
#define XEMU_SURFACE_SCALE_INFO_0_CHS NULL
#define OPTION_VAL_1_CHS NULL
#define OPTION_VAL_2_CHS NULL
#define OPTION_VAL_3_CHS NULL
#define OPTION_VAL_4_CHS NULL
#define OPTION_VAL_5_CHS NULL
#define OPTION_VAL_6_CHS NULL
#define OPTION_VAL_7_CHS NULL
#define OPTION_VAL_8_CHS NULL
#define OPTION_VAL_9_CHS NULL
#define OPTION_VAL_10_CHS NULL
#define XEMU_AVPACK_LABEL_CHS NULL
#define XEMU_AVPACK_INFO_0_CHS NULL
#define OPTION_VAL_HDTV_CHS NULL
#define OPTION_VAL_COMPOSITE_CHS NULL
#define OPTION_VAL_SVIDEO_CHS NULL
#define OPTION_VAL_SCART_CHS NULL
#define OPTION_VAL_VGA_CHS NULL
#define XEMU_USE_DSP_LABEL_CHS NULL
#define XEMU_USE_DSP_INFO_0_CHS NULL
#define XEMU_CACHE_SHADERS_LABEL_CHS NULL
#define XEMU_CACHE_SHADERS_INFO_0_CHS NULL
#define XEMU_AUDIO_VOLUME_LABEL_CHS NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CHS NULL
#define OPTION_VAL_100_CHS NULL
#define OPTION_VAL_80_CHS NULL
#define OPTION_VAL_60_CHS NULL
#define OPTION_VAL_40_CHS NULL
#define OPTION_VAL_20_CHS NULL
#define OPTION_VAL_0_CHS NULL
#define XEMU_DISPLAY_FILTERING_LABEL_CHS NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_CHS NULL
#define OPTION_VAL_LINEAR_CHS NULL
#define OPTION_VAL_NEAREST_CHS NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_chs[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_CHS,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_CHS,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_CHS,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_CHS,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_CHS },
            { "nearest", OPTION_VAL_NEAREST_CHS },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_CHT NULL
#define CATEGORY_VIDEO_INFO_0_CHT NULL
#define CATEGORY_AUDIO_LABEL_CHT NULL
#define CATEGORY_AUDIO_INFO_0_CHT NULL
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
#define XEMU_RENDERER_LABEL_CHT NULL
#define XEMU_RENDERER_INFO_0_CHT NULL
#define OPTION_VAL_VULKAN_CHT NULL
#define OPTION_VAL_OPENGL_CHT NULL
#define XEMU_ASPECT_RATIO_LABEL_CHT NULL
#define XEMU_ASPECT_RATIO_INFO_0_CHT NULL
#define OPTION_VAL_AUTO_CHT NULL
#define OPTION_VAL_4_3_CHT NULL
#define OPTION_VAL_16_9_CHT NULL
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
#define OPTION_VAL_COMPOSITE_CHT NULL
#define OPTION_VAL_SVIDEO_CHT NULL
#define OPTION_VAL_SCART_CHT NULL
#define OPTION_VAL_VGA_CHT NULL
#define XEMU_USE_DSP_LABEL_CHT NULL
#define XEMU_USE_DSP_INFO_0_CHT NULL
#define XEMU_CACHE_SHADERS_LABEL_CHT NULL
#define XEMU_CACHE_SHADERS_INFO_0_CHT NULL
#define XEMU_AUDIO_VOLUME_LABEL_CHT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CHT NULL
#define OPTION_VAL_100_CHT NULL
#define OPTION_VAL_80_CHT NULL
#define OPTION_VAL_60_CHT NULL
#define OPTION_VAL_40_CHT NULL
#define OPTION_VAL_20_CHT NULL
#define OPTION_VAL_0_CHT NULL
#define XEMU_DISPLAY_FILTERING_LABEL_CHT NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_CHT NULL
#define OPTION_VAL_LINEAR_CHT NULL
#define OPTION_VAL_NEAREST_CHT NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cht[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_CHT,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_CHT,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_CHT,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_CHT,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_CHT },
            { "nearest", OPTION_VAL_NEAREST_CHT },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_AUDIO_LABEL_CS NULL
#define CATEGORY_AUDIO_INFO_0_CS NULL
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
#define XEMU_RENDERER_LABEL_CS NULL
#define XEMU_RENDERER_INFO_0_CS NULL
#define OPTION_VAL_VULKAN_CS NULL
#define OPTION_VAL_OPENGL_CS NULL
#define XEMU_ASPECT_RATIO_LABEL_CS NULL
#define XEMU_ASPECT_RATIO_INFO_0_CS NULL
#define OPTION_VAL_AUTO_CS NULL
#define OPTION_VAL_4_3_CS NULL
#define OPTION_VAL_16_9_CS NULL
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
#define OPTION_VAL_COMPOSITE_CS NULL
#define OPTION_VAL_SVIDEO_CS NULL
#define OPTION_VAL_SCART_CS NULL
#define OPTION_VAL_VGA_CS NULL
#define XEMU_USE_DSP_LABEL_CS NULL
#define XEMU_USE_DSP_INFO_0_CS NULL
#define XEMU_CACHE_SHADERS_LABEL_CS NULL
#define XEMU_CACHE_SHADERS_INFO_0_CS NULL
#define XEMU_AUDIO_VOLUME_LABEL_CS NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CS NULL
#define OPTION_VAL_100_CS NULL
#define OPTION_VAL_80_CS NULL
#define OPTION_VAL_60_CS NULL
#define OPTION_VAL_40_CS NULL
#define OPTION_VAL_20_CS NULL
#define OPTION_VAL_0_CS NULL
#define XEMU_DISPLAY_FILTERING_LABEL_CS NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_CS NULL
#define OPTION_VAL_LINEAR_CS NULL
#define OPTION_VAL_NEAREST_CS NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cs[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_CS,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_CS,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_CS,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_CS,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_CS },
            { "nearest", OPTION_VAL_NEAREST_CS },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_cs = {
   option_cats_cs,
   option_defs_cs
};

/* RETRO_LANGUAGE_DE */

#define CATEGORY_SYSTEM_LABEL_DE NULL
#define CATEGORY_SYSTEM_INFO_0_DE NULL
#define CATEGORY_VIDEO_LABEL_DE NULL
#define CATEGORY_VIDEO_INFO_0_DE NULL
#define CATEGORY_AUDIO_LABEL_DE NULL
#define CATEGORY_AUDIO_INFO_0_DE NULL
#define XEMU_MEMORY_LABEL_DE NULL
#define XEMU_MEMORY_INFO_0_DE NULL
#define OPTION_VAL_64_DE NULL
#define OPTION_VAL_128_DE NULL
#define XEMU_NETWORK_BACKEND_LABEL_DE NULL
#define XEMU_NETWORK_BACKEND_INFO_0_DE NULL
#define OPTION_VAL_NAT_DE NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_DE NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_DE NULL
#define XEMU_HARD_FPU_LABEL_DE NULL
#define XEMU_HARD_FPU_INFO_0_DE NULL
#define XEMU_RENDERER_LABEL_DE NULL
#define XEMU_RENDERER_INFO_0_DE NULL
#define OPTION_VAL_VULKAN_DE NULL
#define OPTION_VAL_OPENGL_DE NULL
#define XEMU_ASPECT_RATIO_LABEL_DE NULL
#define XEMU_ASPECT_RATIO_INFO_0_DE NULL
#define OPTION_VAL_AUTO_DE NULL
#define OPTION_VAL_4_3_DE NULL
#define OPTION_VAL_16_9_DE NULL
#define XEMU_SURFACE_SCALE_LABEL_DE NULL
#define XEMU_SURFACE_SCALE_INFO_0_DE NULL
#define OPTION_VAL_1_DE NULL
#define OPTION_VAL_2_DE NULL
#define OPTION_VAL_3_DE NULL
#define OPTION_VAL_4_DE NULL
#define OPTION_VAL_5_DE NULL
#define OPTION_VAL_6_DE NULL
#define OPTION_VAL_7_DE NULL
#define OPTION_VAL_8_DE NULL
#define OPTION_VAL_9_DE NULL
#define OPTION_VAL_10_DE NULL
#define XEMU_AVPACK_LABEL_DE NULL
#define XEMU_AVPACK_INFO_0_DE NULL
#define OPTION_VAL_HDTV_DE NULL
#define OPTION_VAL_COMPOSITE_DE NULL
#define OPTION_VAL_SVIDEO_DE NULL
#define OPTION_VAL_SCART_DE NULL
#define OPTION_VAL_VGA_DE NULL
#define XEMU_USE_DSP_LABEL_DE NULL
#define XEMU_USE_DSP_INFO_0_DE NULL
#define XEMU_CACHE_SHADERS_LABEL_DE NULL
#define XEMU_CACHE_SHADERS_INFO_0_DE NULL
#define XEMU_AUDIO_VOLUME_LABEL_DE NULL
#define XEMU_AUDIO_VOLUME_INFO_0_DE NULL
#define OPTION_VAL_100_DE NULL
#define OPTION_VAL_80_DE NULL
#define OPTION_VAL_60_DE NULL
#define OPTION_VAL_40_DE NULL
#define OPTION_VAL_20_DE NULL
#define OPTION_VAL_0_DE NULL
#define XEMU_DISPLAY_FILTERING_LABEL_DE NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_DE NULL
#define OPTION_VAL_LINEAR_DE NULL
#define OPTION_VAL_NEAREST_DE NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_de[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_DE,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_DE,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_DE,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_DE,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_DE },
            { "nearest", OPTION_VAL_NEAREST_DE },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_EL NULL
#define CATEGORY_VIDEO_INFO_0_EL NULL
#define CATEGORY_AUDIO_LABEL_EL NULL
#define CATEGORY_AUDIO_INFO_0_EL NULL
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
#define XEMU_RENDERER_LABEL_EL NULL
#define XEMU_RENDERER_INFO_0_EL NULL
#define OPTION_VAL_VULKAN_EL NULL
#define OPTION_VAL_OPENGL_EL NULL
#define XEMU_ASPECT_RATIO_LABEL_EL NULL
#define XEMU_ASPECT_RATIO_INFO_0_EL NULL
#define OPTION_VAL_AUTO_EL NULL
#define OPTION_VAL_4_3_EL NULL
#define OPTION_VAL_16_9_EL NULL
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
#define XEMU_USE_DSP_LABEL_EL NULL
#define XEMU_USE_DSP_INFO_0_EL NULL
#define XEMU_CACHE_SHADERS_LABEL_EL NULL
#define XEMU_CACHE_SHADERS_INFO_0_EL NULL
#define XEMU_AUDIO_VOLUME_LABEL_EL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EL NULL
#define OPTION_VAL_100_EL NULL
#define OPTION_VAL_80_EL NULL
#define OPTION_VAL_60_EL NULL
#define OPTION_VAL_40_EL NULL
#define OPTION_VAL_20_EL NULL
#define OPTION_VAL_0_EL NULL
#define XEMU_DISPLAY_FILTERING_LABEL_EL NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_EL NULL
#define OPTION_VAL_LINEAR_EL NULL
#define OPTION_VAL_NEAREST_EL NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_el[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_EL,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_EL,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_EL,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_EL,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_EL },
            { "nearest", OPTION_VAL_NEAREST_EL },
            { NULL, NULL },
        },
        "linear"
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
#define XEMU_RENDERER_LABEL_EN NULL
#define XEMU_RENDERER_INFO_0_EN NULL
#define OPTION_VAL_VULKAN_EN NULL
#define OPTION_VAL_OPENGL_EN NULL
#define XEMU_ASPECT_RATIO_LABEL_EN NULL
#define XEMU_ASPECT_RATIO_INFO_0_EN NULL
#define OPTION_VAL_AUTO_EN NULL
#define OPTION_VAL_4_3_EN NULL
#define OPTION_VAL_16_9_EN NULL
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
#define XEMU_USE_DSP_LABEL_EN NULL
#define XEMU_USE_DSP_INFO_0_EN NULL
#define XEMU_CACHE_SHADERS_LABEL_EN NULL
#define XEMU_CACHE_SHADERS_INFO_0_EN NULL
#define XEMU_AUDIO_VOLUME_LABEL_EN NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EN NULL
#define OPTION_VAL_100_EN NULL
#define OPTION_VAL_80_EN NULL
#define OPTION_VAL_60_EN NULL
#define OPTION_VAL_40_EN NULL
#define OPTION_VAL_20_EN NULL
#define OPTION_VAL_0_EN NULL
#define XEMU_DISPLAY_FILTERING_LABEL_EN NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_EN NULL
#define OPTION_VAL_LINEAR_EN NULL
#define OPTION_VAL_NEAREST_EN NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_en[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_EN,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_EN,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_EN,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_EN,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_EN },
            { "nearest", OPTION_VAL_NEAREST_EN },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_AUDIO_LABEL_EO NULL
#define CATEGORY_AUDIO_INFO_0_EO NULL
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
#define XEMU_RENDERER_LABEL_EO NULL
#define XEMU_RENDERER_INFO_0_EO NULL
#define OPTION_VAL_VULKAN_EO NULL
#define OPTION_VAL_OPENGL_EO NULL
#define XEMU_ASPECT_RATIO_LABEL_EO NULL
#define XEMU_ASPECT_RATIO_INFO_0_EO NULL
#define OPTION_VAL_AUTO_EO NULL
#define OPTION_VAL_4_3_EO NULL
#define OPTION_VAL_16_9_EO NULL
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
#define OPTION_VAL_COMPOSITE_EO NULL
#define OPTION_VAL_SVIDEO_EO NULL
#define OPTION_VAL_SCART_EO NULL
#define OPTION_VAL_VGA_EO NULL
#define XEMU_USE_DSP_LABEL_EO NULL
#define XEMU_USE_DSP_INFO_0_EO NULL
#define XEMU_CACHE_SHADERS_LABEL_EO NULL
#define XEMU_CACHE_SHADERS_INFO_0_EO NULL
#define XEMU_AUDIO_VOLUME_LABEL_EO NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EO NULL
#define OPTION_VAL_100_EO NULL
#define OPTION_VAL_80_EO NULL
#define OPTION_VAL_60_EO NULL
#define OPTION_VAL_40_EO NULL
#define OPTION_VAL_20_EO NULL
#define OPTION_VAL_0_EO NULL
#define XEMU_DISPLAY_FILTERING_LABEL_EO NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_EO NULL
#define OPTION_VAL_LINEAR_EO NULL
#define OPTION_VAL_NEAREST_EO NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_eo[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_EO,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_EO,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_EO,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_EO,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_EO },
            { "nearest", OPTION_VAL_NEAREST_EO },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_ES NULL
#define CATEGORY_VIDEO_INFO_0_ES NULL
#define CATEGORY_AUDIO_LABEL_ES NULL
#define CATEGORY_AUDIO_INFO_0_ES NULL
#define XEMU_MEMORY_LABEL_ES NULL
#define XEMU_MEMORY_INFO_0_ES NULL
#define OPTION_VAL_64_ES NULL
#define OPTION_VAL_128_ES NULL
#define XEMU_NETWORK_BACKEND_LABEL_ES NULL
#define XEMU_NETWORK_BACKEND_INFO_0_ES NULL
#define OPTION_VAL_NAT_ES NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_ES NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_ES NULL
#define XEMU_HARD_FPU_LABEL_ES NULL
#define XEMU_HARD_FPU_INFO_0_ES NULL
#define XEMU_RENDERER_LABEL_ES NULL
#define XEMU_RENDERER_INFO_0_ES NULL
#define OPTION_VAL_VULKAN_ES NULL
#define OPTION_VAL_OPENGL_ES NULL
#define XEMU_ASPECT_RATIO_LABEL_ES NULL
#define XEMU_ASPECT_RATIO_INFO_0_ES NULL
#define OPTION_VAL_AUTO_ES NULL
#define OPTION_VAL_4_3_ES NULL
#define OPTION_VAL_16_9_ES NULL
#define XEMU_SURFACE_SCALE_LABEL_ES NULL
#define XEMU_SURFACE_SCALE_INFO_0_ES NULL
#define OPTION_VAL_1_ES NULL
#define OPTION_VAL_2_ES NULL
#define OPTION_VAL_3_ES NULL
#define OPTION_VAL_4_ES NULL
#define OPTION_VAL_5_ES NULL
#define OPTION_VAL_6_ES NULL
#define OPTION_VAL_7_ES NULL
#define OPTION_VAL_8_ES NULL
#define OPTION_VAL_9_ES NULL
#define OPTION_VAL_10_ES NULL
#define XEMU_AVPACK_LABEL_ES NULL
#define XEMU_AVPACK_INFO_0_ES NULL
#define OPTION_VAL_HDTV_ES NULL
#define OPTION_VAL_COMPOSITE_ES NULL
#define OPTION_VAL_SVIDEO_ES NULL
#define OPTION_VAL_SCART_ES NULL
#define OPTION_VAL_VGA_ES NULL
#define XEMU_USE_DSP_LABEL_ES NULL
#define XEMU_USE_DSP_INFO_0_ES NULL
#define XEMU_CACHE_SHADERS_LABEL_ES NULL
#define XEMU_CACHE_SHADERS_INFO_0_ES NULL
#define XEMU_AUDIO_VOLUME_LABEL_ES NULL
#define XEMU_AUDIO_VOLUME_INFO_0_ES NULL
#define OPTION_VAL_100_ES NULL
#define OPTION_VAL_80_ES NULL
#define OPTION_VAL_60_ES NULL
#define OPTION_VAL_40_ES NULL
#define OPTION_VAL_20_ES NULL
#define OPTION_VAL_0_ES NULL
#define XEMU_DISPLAY_FILTERING_LABEL_ES NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_ES NULL
#define OPTION_VAL_LINEAR_ES NULL
#define OPTION_VAL_NEAREST_ES NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_es[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_ES,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_ES,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_ES,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_ES,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_ES },
            { "nearest", OPTION_VAL_NEAREST_ES },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_FA NULL
#define CATEGORY_VIDEO_INFO_0_FA NULL
#define CATEGORY_AUDIO_LABEL_FA NULL
#define CATEGORY_AUDIO_INFO_0_FA NULL
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
#define XEMU_RENDERER_LABEL_FA NULL
#define XEMU_RENDERER_INFO_0_FA NULL
#define OPTION_VAL_VULKAN_FA NULL
#define OPTION_VAL_OPENGL_FA NULL
#define XEMU_ASPECT_RATIO_LABEL_FA NULL
#define XEMU_ASPECT_RATIO_INFO_0_FA NULL
#define OPTION_VAL_AUTO_FA NULL
#define OPTION_VAL_4_3_FA NULL
#define OPTION_VAL_16_9_FA NULL
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
#define XEMU_USE_DSP_LABEL_FA NULL
#define XEMU_USE_DSP_INFO_0_FA NULL
#define XEMU_CACHE_SHADERS_LABEL_FA NULL
#define XEMU_CACHE_SHADERS_INFO_0_FA NULL
#define XEMU_AUDIO_VOLUME_LABEL_FA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_FA NULL
#define OPTION_VAL_100_FA NULL
#define OPTION_VAL_80_FA NULL
#define OPTION_VAL_60_FA NULL
#define OPTION_VAL_40_FA NULL
#define OPTION_VAL_20_FA NULL
#define OPTION_VAL_0_FA NULL
#define XEMU_DISPLAY_FILTERING_LABEL_FA NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_FA NULL
#define OPTION_VAL_LINEAR_FA NULL
#define OPTION_VAL_NEAREST_FA NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fa[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_FA,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_FA,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_FA,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_FA,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_FA },
            { "nearest", OPTION_VAL_NEAREST_FA },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_AUDIO_LABEL_FI NULL
#define CATEGORY_AUDIO_INFO_0_FI NULL
#define XEMU_MEMORY_LABEL_FI NULL
#define XEMU_MEMORY_INFO_0_FI NULL
#define OPTION_VAL_64_FI NULL
#define OPTION_VAL_128_FI NULL
#define XEMU_NETWORK_BACKEND_LABEL_FI NULL
#define XEMU_NETWORK_BACKEND_INFO_0_FI NULL
#define OPTION_VAL_NAT_FI NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_FI NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_FI NULL
#define XEMU_HARD_FPU_LABEL_FI NULL
#define XEMU_HARD_FPU_INFO_0_FI NULL
#define XEMU_RENDERER_LABEL_FI NULL
#define XEMU_RENDERER_INFO_0_FI NULL
#define OPTION_VAL_VULKAN_FI NULL
#define OPTION_VAL_OPENGL_FI NULL
#define XEMU_ASPECT_RATIO_LABEL_FI NULL
#define XEMU_ASPECT_RATIO_INFO_0_FI NULL
#define OPTION_VAL_AUTO_FI NULL
#define OPTION_VAL_4_3_FI NULL
#define OPTION_VAL_16_9_FI NULL
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
#define OPTION_VAL_COMPOSITE_FI NULL
#define OPTION_VAL_SVIDEO_FI NULL
#define OPTION_VAL_SCART_FI NULL
#define OPTION_VAL_VGA_FI NULL
#define XEMU_USE_DSP_LABEL_FI NULL
#define XEMU_USE_DSP_INFO_0_FI NULL
#define XEMU_CACHE_SHADERS_LABEL_FI NULL
#define XEMU_CACHE_SHADERS_INFO_0_FI NULL
#define XEMU_AUDIO_VOLUME_LABEL_FI NULL
#define XEMU_AUDIO_VOLUME_INFO_0_FI NULL
#define OPTION_VAL_100_FI NULL
#define OPTION_VAL_80_FI NULL
#define OPTION_VAL_60_FI NULL
#define OPTION_VAL_40_FI NULL
#define OPTION_VAL_20_FI NULL
#define OPTION_VAL_0_FI NULL
#define XEMU_DISPLAY_FILTERING_LABEL_FI NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_FI NULL
#define OPTION_VAL_LINEAR_FI NULL
#define OPTION_VAL_NEAREST_FI NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fi[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_FI,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_FI,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_FI,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_FI,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_FI },
            { "nearest", OPTION_VAL_NEAREST_FI },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_FR NULL
#define CATEGORY_VIDEO_INFO_0_FR NULL
#define CATEGORY_AUDIO_LABEL_FR NULL
#define CATEGORY_AUDIO_INFO_0_FR NULL
#define XEMU_MEMORY_LABEL_FR NULL
#define XEMU_MEMORY_INFO_0_FR NULL
#define OPTION_VAL_64_FR NULL
#define OPTION_VAL_128_FR NULL
#define XEMU_NETWORK_BACKEND_LABEL_FR NULL
#define XEMU_NETWORK_BACKEND_INFO_0_FR NULL
#define OPTION_VAL_NAT_FR NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_FR NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_FR NULL
#define XEMU_HARD_FPU_LABEL_FR NULL
#define XEMU_HARD_FPU_INFO_0_FR NULL
#define XEMU_RENDERER_LABEL_FR NULL
#define XEMU_RENDERER_INFO_0_FR NULL
#define OPTION_VAL_VULKAN_FR NULL
#define OPTION_VAL_OPENGL_FR NULL
#define XEMU_ASPECT_RATIO_LABEL_FR NULL
#define XEMU_ASPECT_RATIO_INFO_0_FR NULL
#define OPTION_VAL_AUTO_FR NULL
#define OPTION_VAL_4_3_FR NULL
#define OPTION_VAL_16_9_FR NULL
#define XEMU_SURFACE_SCALE_LABEL_FR NULL
#define XEMU_SURFACE_SCALE_INFO_0_FR NULL
#define OPTION_VAL_1_FR NULL
#define OPTION_VAL_2_FR NULL
#define OPTION_VAL_3_FR NULL
#define OPTION_VAL_4_FR NULL
#define OPTION_VAL_5_FR NULL
#define OPTION_VAL_6_FR NULL
#define OPTION_VAL_7_FR NULL
#define OPTION_VAL_8_FR NULL
#define OPTION_VAL_9_FR NULL
#define OPTION_VAL_10_FR NULL
#define XEMU_AVPACK_LABEL_FR NULL
#define XEMU_AVPACK_INFO_0_FR NULL
#define OPTION_VAL_HDTV_FR NULL
#define OPTION_VAL_COMPOSITE_FR NULL
#define OPTION_VAL_SVIDEO_FR NULL
#define OPTION_VAL_SCART_FR NULL
#define OPTION_VAL_VGA_FR NULL
#define XEMU_USE_DSP_LABEL_FR NULL
#define XEMU_USE_DSP_INFO_0_FR NULL
#define XEMU_CACHE_SHADERS_LABEL_FR NULL
#define XEMU_CACHE_SHADERS_INFO_0_FR NULL
#define XEMU_AUDIO_VOLUME_LABEL_FR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_FR NULL
#define OPTION_VAL_100_FR NULL
#define OPTION_VAL_80_FR NULL
#define OPTION_VAL_60_FR NULL
#define OPTION_VAL_40_FR NULL
#define OPTION_VAL_20_FR NULL
#define OPTION_VAL_0_FR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_FR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_FR NULL
#define OPTION_VAL_LINEAR_FR NULL
#define OPTION_VAL_NEAREST_FR NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_fr[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_FR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_FR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_FR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_FR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_FR },
            { "nearest", OPTION_VAL_NEAREST_FR },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_fr = {
   option_cats_fr,
   option_defs_fr
};

/* RETRO_LANGUAGE_GA */

#define CATEGORY_SYSTEM_LABEL_GA NULL
#define CATEGORY_SYSTEM_INFO_0_GA NULL
#define CATEGORY_VIDEO_LABEL_GA NULL
#define CATEGORY_VIDEO_INFO_0_GA NULL
#define CATEGORY_AUDIO_LABEL_GA NULL
#define CATEGORY_AUDIO_INFO_0_GA NULL
#define XEMU_MEMORY_LABEL_GA NULL
#define XEMU_MEMORY_INFO_0_GA NULL
#define OPTION_VAL_64_GA NULL
#define OPTION_VAL_128_GA NULL
#define XEMU_NETWORK_BACKEND_LABEL_GA NULL
#define XEMU_NETWORK_BACKEND_INFO_0_GA NULL
#define OPTION_VAL_NAT_GA NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_GA NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_GA NULL
#define XEMU_HARD_FPU_LABEL_GA NULL
#define XEMU_HARD_FPU_INFO_0_GA NULL
#define XEMU_RENDERER_LABEL_GA NULL
#define XEMU_RENDERER_INFO_0_GA NULL
#define OPTION_VAL_VULKAN_GA NULL
#define OPTION_VAL_OPENGL_GA NULL
#define XEMU_ASPECT_RATIO_LABEL_GA NULL
#define XEMU_ASPECT_RATIO_INFO_0_GA NULL
#define OPTION_VAL_AUTO_GA NULL
#define OPTION_VAL_4_3_GA NULL
#define OPTION_VAL_16_9_GA NULL
#define XEMU_SURFACE_SCALE_LABEL_GA NULL
#define XEMU_SURFACE_SCALE_INFO_0_GA NULL
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
#define XEMU_AVPACK_LABEL_GA NULL
#define XEMU_AVPACK_INFO_0_GA NULL
#define OPTION_VAL_HDTV_GA NULL
#define OPTION_VAL_COMPOSITE_GA NULL
#define OPTION_VAL_SVIDEO_GA NULL
#define OPTION_VAL_SCART_GA NULL
#define OPTION_VAL_VGA_GA NULL
#define XEMU_USE_DSP_LABEL_GA NULL
#define XEMU_USE_DSP_INFO_0_GA NULL
#define XEMU_CACHE_SHADERS_LABEL_GA NULL
#define XEMU_CACHE_SHADERS_INFO_0_GA NULL
#define XEMU_AUDIO_VOLUME_LABEL_GA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_GA NULL
#define OPTION_VAL_100_GA NULL
#define OPTION_VAL_80_GA NULL
#define OPTION_VAL_60_GA NULL
#define OPTION_VAL_40_GA NULL
#define OPTION_VAL_20_GA NULL
#define OPTION_VAL_0_GA NULL
#define XEMU_DISPLAY_FILTERING_LABEL_GA NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_GA NULL
#define OPTION_VAL_LINEAR_GA NULL
#define OPTION_VAL_NEAREST_GA NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ga[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_GA,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_GA,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_GA,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_GA,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_GA },
            { "nearest", OPTION_VAL_NEAREST_GA },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_GL NULL
#define CATEGORY_VIDEO_INFO_0_GL NULL
#define CATEGORY_AUDIO_LABEL_GL NULL
#define CATEGORY_AUDIO_INFO_0_GL NULL
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
#define XEMU_RENDERER_LABEL_GL NULL
#define XEMU_RENDERER_INFO_0_GL NULL
#define OPTION_VAL_VULKAN_GL NULL
#define OPTION_VAL_OPENGL_GL NULL
#define XEMU_ASPECT_RATIO_LABEL_GL NULL
#define XEMU_ASPECT_RATIO_INFO_0_GL NULL
#define OPTION_VAL_AUTO_GL NULL
#define OPTION_VAL_4_3_GL NULL
#define OPTION_VAL_16_9_GL NULL
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
#define OPTION_VAL_COMPOSITE_GL NULL
#define OPTION_VAL_SVIDEO_GL NULL
#define OPTION_VAL_SCART_GL NULL
#define OPTION_VAL_VGA_GL NULL
#define XEMU_USE_DSP_LABEL_GL NULL
#define XEMU_USE_DSP_INFO_0_GL NULL
#define XEMU_CACHE_SHADERS_LABEL_GL NULL
#define XEMU_CACHE_SHADERS_INFO_0_GL NULL
#define XEMU_AUDIO_VOLUME_LABEL_GL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_GL NULL
#define OPTION_VAL_100_GL NULL
#define OPTION_VAL_80_GL NULL
#define OPTION_VAL_60_GL NULL
#define OPTION_VAL_40_GL NULL
#define OPTION_VAL_20_GL NULL
#define OPTION_VAL_0_GL NULL
#define XEMU_DISPLAY_FILTERING_LABEL_GL NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_GL NULL
#define OPTION_VAL_LINEAR_GL NULL
#define OPTION_VAL_NEAREST_GL NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_gl[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_GL,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_GL,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_GL,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_GL,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_GL },
            { "nearest", OPTION_VAL_NEAREST_GL },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_HE NULL
#define CATEGORY_VIDEO_INFO_0_HE NULL
#define CATEGORY_AUDIO_LABEL_HE NULL
#define CATEGORY_AUDIO_INFO_0_HE NULL
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
#define XEMU_RENDERER_LABEL_HE NULL
#define XEMU_RENDERER_INFO_0_HE NULL
#define OPTION_VAL_VULKAN_HE NULL
#define OPTION_VAL_OPENGL_HE NULL
#define XEMU_ASPECT_RATIO_LABEL_HE NULL
#define XEMU_ASPECT_RATIO_INFO_0_HE NULL
#define OPTION_VAL_AUTO_HE NULL
#define OPTION_VAL_4_3_HE NULL
#define OPTION_VAL_16_9_HE NULL
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
#define XEMU_USE_DSP_LABEL_HE NULL
#define XEMU_USE_DSP_INFO_0_HE NULL
#define XEMU_CACHE_SHADERS_LABEL_HE NULL
#define XEMU_CACHE_SHADERS_INFO_0_HE NULL
#define XEMU_AUDIO_VOLUME_LABEL_HE NULL
#define XEMU_AUDIO_VOLUME_INFO_0_HE NULL
#define OPTION_VAL_100_HE NULL
#define OPTION_VAL_80_HE NULL
#define OPTION_VAL_60_HE NULL
#define OPTION_VAL_40_HE NULL
#define OPTION_VAL_20_HE NULL
#define OPTION_VAL_0_HE NULL
#define XEMU_DISPLAY_FILTERING_LABEL_HE NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_HE NULL
#define OPTION_VAL_LINEAR_HE NULL
#define OPTION_VAL_NEAREST_HE NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_he[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_HE,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_HE,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_HE,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_HE,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_HE },
            { "nearest", OPTION_VAL_NEAREST_HE },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_he = {
   option_cats_he,
   option_defs_he
};

/* RETRO_LANGUAGE_HU */

#define CATEGORY_SYSTEM_LABEL_HU NULL
#define CATEGORY_SYSTEM_INFO_0_HU NULL
#define CATEGORY_VIDEO_LABEL_HU NULL
#define CATEGORY_VIDEO_INFO_0_HU NULL
#define CATEGORY_AUDIO_LABEL_HU NULL
#define CATEGORY_AUDIO_INFO_0_HU NULL
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
#define XEMU_RENDERER_LABEL_HU NULL
#define XEMU_RENDERER_INFO_0_HU NULL
#define OPTION_VAL_VULKAN_HU NULL
#define OPTION_VAL_OPENGL_HU NULL
#define XEMU_ASPECT_RATIO_LABEL_HU NULL
#define XEMU_ASPECT_RATIO_INFO_0_HU NULL
#define OPTION_VAL_AUTO_HU NULL
#define OPTION_VAL_4_3_HU NULL
#define OPTION_VAL_16_9_HU NULL
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
#define OPTION_VAL_COMPOSITE_HU NULL
#define OPTION_VAL_SVIDEO_HU NULL
#define OPTION_VAL_SCART_HU NULL
#define OPTION_VAL_VGA_HU NULL
#define XEMU_USE_DSP_LABEL_HU NULL
#define XEMU_USE_DSP_INFO_0_HU NULL
#define XEMU_CACHE_SHADERS_LABEL_HU NULL
#define XEMU_CACHE_SHADERS_INFO_0_HU NULL
#define XEMU_AUDIO_VOLUME_LABEL_HU NULL
#define XEMU_AUDIO_VOLUME_INFO_0_HU NULL
#define OPTION_VAL_100_HU NULL
#define OPTION_VAL_80_HU NULL
#define OPTION_VAL_60_HU NULL
#define OPTION_VAL_40_HU NULL
#define OPTION_VAL_20_HU NULL
#define OPTION_VAL_0_HU NULL
#define XEMU_DISPLAY_FILTERING_LABEL_HU NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_HU NULL
#define OPTION_VAL_LINEAR_HU NULL
#define OPTION_VAL_NEAREST_HU NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_hu[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_HU,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_HU,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_HU,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_HU,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_HU },
            { "nearest", OPTION_VAL_NEAREST_HU },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_AUDIO_LABEL_ID NULL
#define CATEGORY_AUDIO_INFO_0_ID NULL
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
#define XEMU_RENDERER_LABEL_ID NULL
#define XEMU_RENDERER_INFO_0_ID NULL
#define OPTION_VAL_VULKAN_ID NULL
#define OPTION_VAL_OPENGL_ID NULL
#define XEMU_ASPECT_RATIO_LABEL_ID NULL
#define XEMU_ASPECT_RATIO_INFO_0_ID NULL
#define OPTION_VAL_AUTO_ID NULL
#define OPTION_VAL_4_3_ID NULL
#define OPTION_VAL_16_9_ID NULL
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
#define XEMU_USE_DSP_LABEL_ID NULL
#define XEMU_USE_DSP_INFO_0_ID NULL
#define XEMU_CACHE_SHADERS_LABEL_ID NULL
#define XEMU_CACHE_SHADERS_INFO_0_ID NULL
#define XEMU_AUDIO_VOLUME_LABEL_ID NULL
#define XEMU_AUDIO_VOLUME_INFO_0_ID NULL
#define OPTION_VAL_100_ID NULL
#define OPTION_VAL_80_ID NULL
#define OPTION_VAL_60_ID NULL
#define OPTION_VAL_40_ID NULL
#define OPTION_VAL_20_ID NULL
#define OPTION_VAL_0_ID NULL
#define XEMU_DISPLAY_FILTERING_LABEL_ID NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_ID NULL
#define OPTION_VAL_LINEAR_ID NULL
#define OPTION_VAL_NEAREST_ID NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_id[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_ID,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_ID,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_ID,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_ID,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_ID },
            { "nearest", OPTION_VAL_NEAREST_ID },
            { NULL, NULL },
        },
        "linear"
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
#define XEMU_RENDERER_LABEL_IT NULL
#define XEMU_RENDERER_INFO_0_IT NULL
#define OPTION_VAL_VULKAN_IT NULL
#define OPTION_VAL_OPENGL_IT NULL
#define XEMU_ASPECT_RATIO_LABEL_IT NULL
#define XEMU_ASPECT_RATIO_INFO_0_IT NULL
#define OPTION_VAL_AUTO_IT NULL
#define OPTION_VAL_4_3_IT NULL
#define OPTION_VAL_16_9_IT NULL
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
#define OPTION_VAL_COMPOSITE_IT NULL
#define OPTION_VAL_SVIDEO_IT NULL
#define OPTION_VAL_SCART_IT NULL
#define OPTION_VAL_VGA_IT NULL
#define XEMU_USE_DSP_LABEL_IT NULL
#define XEMU_USE_DSP_INFO_0_IT NULL
#define XEMU_CACHE_SHADERS_LABEL_IT NULL
#define XEMU_CACHE_SHADERS_INFO_0_IT NULL
#define XEMU_AUDIO_VOLUME_LABEL_IT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_IT NULL
#define OPTION_VAL_100_IT NULL
#define OPTION_VAL_80_IT NULL
#define OPTION_VAL_60_IT NULL
#define OPTION_VAL_40_IT NULL
#define OPTION_VAL_20_IT NULL
#define OPTION_VAL_0_IT NULL
#define XEMU_DISPLAY_FILTERING_LABEL_IT NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_IT NULL
#define OPTION_VAL_LINEAR_IT NULL
#define OPTION_VAL_NEAREST_IT NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_it[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_IT,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_IT,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_IT,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_IT,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_IT },
            { "nearest", OPTION_VAL_NEAREST_IT },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_JA NULL
#define CATEGORY_VIDEO_INFO_0_JA NULL
#define CATEGORY_AUDIO_LABEL_JA NULL
#define CATEGORY_AUDIO_INFO_0_JA NULL
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
#define XEMU_RENDERER_LABEL_JA NULL
#define XEMU_RENDERER_INFO_0_JA NULL
#define OPTION_VAL_VULKAN_JA NULL
#define OPTION_VAL_OPENGL_JA NULL
#define XEMU_ASPECT_RATIO_LABEL_JA NULL
#define XEMU_ASPECT_RATIO_INFO_0_JA NULL
#define OPTION_VAL_AUTO_JA NULL
#define OPTION_VAL_4_3_JA NULL
#define OPTION_VAL_16_9_JA NULL
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
#define OPTION_VAL_COMPOSITE_JA NULL
#define OPTION_VAL_SVIDEO_JA NULL
#define OPTION_VAL_SCART_JA NULL
#define OPTION_VAL_VGA_JA NULL
#define XEMU_USE_DSP_LABEL_JA NULL
#define XEMU_USE_DSP_INFO_0_JA NULL
#define XEMU_CACHE_SHADERS_LABEL_JA NULL
#define XEMU_CACHE_SHADERS_INFO_0_JA NULL
#define XEMU_AUDIO_VOLUME_LABEL_JA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_JA NULL
#define OPTION_VAL_100_JA NULL
#define OPTION_VAL_80_JA NULL
#define OPTION_VAL_60_JA NULL
#define OPTION_VAL_40_JA NULL
#define OPTION_VAL_20_JA NULL
#define OPTION_VAL_0_JA NULL
#define XEMU_DISPLAY_FILTERING_LABEL_JA NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_JA NULL
#define OPTION_VAL_LINEAR_JA NULL
#define OPTION_VAL_NEAREST_JA NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ja[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_JA,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_JA,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_JA,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_JA,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_JA },
            { "nearest", OPTION_VAL_NEAREST_JA },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_KO NULL
#define CATEGORY_VIDEO_INFO_0_KO NULL
#define CATEGORY_AUDIO_LABEL_KO NULL
#define CATEGORY_AUDIO_INFO_0_KO NULL
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
#define XEMU_RENDERER_LABEL_KO NULL
#define XEMU_RENDERER_INFO_0_KO NULL
#define OPTION_VAL_VULKAN_KO NULL
#define OPTION_VAL_OPENGL_KO NULL
#define XEMU_ASPECT_RATIO_LABEL_KO NULL
#define XEMU_ASPECT_RATIO_INFO_0_KO NULL
#define OPTION_VAL_AUTO_KO NULL
#define OPTION_VAL_4_3_KO NULL
#define OPTION_VAL_16_9_KO NULL
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
#define OPTION_VAL_COMPOSITE_KO NULL
#define OPTION_VAL_SVIDEO_KO NULL
#define OPTION_VAL_SCART_KO NULL
#define OPTION_VAL_VGA_KO NULL
#define XEMU_USE_DSP_LABEL_KO NULL
#define XEMU_USE_DSP_INFO_0_KO NULL
#define XEMU_CACHE_SHADERS_LABEL_KO NULL
#define XEMU_CACHE_SHADERS_INFO_0_KO NULL
#define XEMU_AUDIO_VOLUME_LABEL_KO NULL
#define XEMU_AUDIO_VOLUME_INFO_0_KO NULL
#define OPTION_VAL_100_KO NULL
#define OPTION_VAL_80_KO NULL
#define OPTION_VAL_60_KO NULL
#define OPTION_VAL_40_KO NULL
#define OPTION_VAL_20_KO NULL
#define OPTION_VAL_0_KO NULL
#define XEMU_DISPLAY_FILTERING_LABEL_KO NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_KO NULL
#define OPTION_VAL_LINEAR_KO NULL
#define OPTION_VAL_NEAREST_KO NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ko[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_KO,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_KO,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_KO,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_KO,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_KO },
            { "nearest", OPTION_VAL_NEAREST_KO },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_AUDIO_LABEL_NL NULL
#define CATEGORY_AUDIO_INFO_0_NL NULL
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
#define XEMU_RENDERER_LABEL_NL NULL
#define XEMU_RENDERER_INFO_0_NL NULL
#define OPTION_VAL_VULKAN_NL NULL
#define OPTION_VAL_OPENGL_NL NULL
#define XEMU_ASPECT_RATIO_LABEL_NL NULL
#define XEMU_ASPECT_RATIO_INFO_0_NL NULL
#define OPTION_VAL_AUTO_NL NULL
#define OPTION_VAL_4_3_NL NULL
#define OPTION_VAL_16_9_NL NULL
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
#define XEMU_USE_DSP_LABEL_NL NULL
#define XEMU_USE_DSP_INFO_0_NL NULL
#define XEMU_CACHE_SHADERS_LABEL_NL NULL
#define XEMU_CACHE_SHADERS_INFO_0_NL NULL
#define XEMU_AUDIO_VOLUME_LABEL_NL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_NL NULL
#define OPTION_VAL_100_NL NULL
#define OPTION_VAL_80_NL NULL
#define OPTION_VAL_60_NL NULL
#define OPTION_VAL_40_NL NULL
#define OPTION_VAL_20_NL NULL
#define OPTION_VAL_0_NL NULL
#define XEMU_DISPLAY_FILTERING_LABEL_NL NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_NL NULL
#define OPTION_VAL_LINEAR_NL NULL
#define OPTION_VAL_NEAREST_NL NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_nl[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_NL,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_NL,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_NL,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_NL,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_NL },
            { "nearest", OPTION_VAL_NEAREST_NL },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_AUDIO_LABEL_NO NULL
#define CATEGORY_AUDIO_INFO_0_NO NULL
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
#define XEMU_RENDERER_LABEL_NO NULL
#define XEMU_RENDERER_INFO_0_NO NULL
#define OPTION_VAL_VULKAN_NO NULL
#define OPTION_VAL_OPENGL_NO NULL
#define XEMU_ASPECT_RATIO_LABEL_NO NULL
#define XEMU_ASPECT_RATIO_INFO_0_NO NULL
#define OPTION_VAL_AUTO_NO NULL
#define OPTION_VAL_4_3_NO NULL
#define OPTION_VAL_16_9_NO NULL
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
#define XEMU_USE_DSP_LABEL_NO NULL
#define XEMU_USE_DSP_INFO_0_NO NULL
#define XEMU_CACHE_SHADERS_LABEL_NO NULL
#define XEMU_CACHE_SHADERS_INFO_0_NO NULL
#define XEMU_AUDIO_VOLUME_LABEL_NO NULL
#define XEMU_AUDIO_VOLUME_INFO_0_NO NULL
#define OPTION_VAL_100_NO NULL
#define OPTION_VAL_80_NO NULL
#define OPTION_VAL_60_NO NULL
#define OPTION_VAL_40_NO NULL
#define OPTION_VAL_20_NO NULL
#define OPTION_VAL_0_NO NULL
#define XEMU_DISPLAY_FILTERING_LABEL_NO NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_NO NULL
#define OPTION_VAL_LINEAR_NO NULL
#define OPTION_VAL_NEAREST_NO NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_no[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_NO,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_NO,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_NO,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_NO,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_NO },
            { "nearest", OPTION_VAL_NEAREST_NO },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_no = {
   option_cats_no,
   option_defs_no
};

/* RETRO_LANGUAGE_PL */

#define CATEGORY_SYSTEM_LABEL_PL NULL
#define CATEGORY_SYSTEM_INFO_0_PL NULL
#define CATEGORY_VIDEO_LABEL_PL NULL
#define CATEGORY_VIDEO_INFO_0_PL NULL
#define CATEGORY_AUDIO_LABEL_PL NULL
#define CATEGORY_AUDIO_INFO_0_PL NULL
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
#define XEMU_RENDERER_LABEL_PL NULL
#define XEMU_RENDERER_INFO_0_PL NULL
#define OPTION_VAL_VULKAN_PL NULL
#define OPTION_VAL_OPENGL_PL NULL
#define XEMU_ASPECT_RATIO_LABEL_PL NULL
#define XEMU_ASPECT_RATIO_INFO_0_PL NULL
#define OPTION_VAL_AUTO_PL NULL
#define OPTION_VAL_4_3_PL NULL
#define OPTION_VAL_16_9_PL NULL
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
#define OPTION_VAL_COMPOSITE_PL NULL
#define OPTION_VAL_SVIDEO_PL NULL
#define OPTION_VAL_SCART_PL NULL
#define OPTION_VAL_VGA_PL NULL
#define XEMU_USE_DSP_LABEL_PL NULL
#define XEMU_USE_DSP_INFO_0_PL NULL
#define XEMU_CACHE_SHADERS_LABEL_PL NULL
#define XEMU_CACHE_SHADERS_INFO_0_PL NULL
#define XEMU_AUDIO_VOLUME_LABEL_PL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PL NULL
#define OPTION_VAL_100_PL NULL
#define OPTION_VAL_80_PL NULL
#define OPTION_VAL_60_PL NULL
#define OPTION_VAL_40_PL NULL
#define OPTION_VAL_20_PL NULL
#define OPTION_VAL_0_PL NULL
#define XEMU_DISPLAY_FILTERING_LABEL_PL NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_PL NULL
#define OPTION_VAL_LINEAR_PL NULL
#define OPTION_VAL_NEAREST_PL NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pl[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_PL,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_PL,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_PL,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_PL,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_PL },
            { "nearest", OPTION_VAL_NEAREST_PL },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_PT_BR NULL
#define CATEGORY_VIDEO_INFO_0_PT_BR NULL
#define CATEGORY_AUDIO_LABEL_PT_BR NULL
#define CATEGORY_AUDIO_INFO_0_PT_BR NULL
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
#define XEMU_RENDERER_LABEL_PT_BR NULL
#define XEMU_RENDERER_INFO_0_PT_BR NULL
#define OPTION_VAL_VULKAN_PT_BR NULL
#define OPTION_VAL_OPENGL_PT_BR NULL
#define XEMU_ASPECT_RATIO_LABEL_PT_BR NULL
#define XEMU_ASPECT_RATIO_INFO_0_PT_BR NULL
#define OPTION_VAL_AUTO_PT_BR NULL
#define OPTION_VAL_4_3_PT_BR NULL
#define OPTION_VAL_16_9_PT_BR NULL
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
#define OPTION_VAL_COMPOSITE_PT_BR NULL
#define OPTION_VAL_SVIDEO_PT_BR NULL
#define OPTION_VAL_SCART_PT_BR NULL
#define OPTION_VAL_VGA_PT_BR NULL
#define XEMU_USE_DSP_LABEL_PT_BR NULL
#define XEMU_USE_DSP_INFO_0_PT_BR NULL
#define XEMU_CACHE_SHADERS_LABEL_PT_BR NULL
#define XEMU_CACHE_SHADERS_INFO_0_PT_BR NULL
#define XEMU_AUDIO_VOLUME_LABEL_PT_BR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PT_BR NULL
#define OPTION_VAL_100_PT_BR NULL
#define OPTION_VAL_80_PT_BR NULL
#define OPTION_VAL_60_PT_BR NULL
#define OPTION_VAL_40_PT_BR NULL
#define OPTION_VAL_20_PT_BR NULL
#define OPTION_VAL_0_PT_BR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_PT_BR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_PT_BR NULL
#define OPTION_VAL_LINEAR_PT_BR NULL
#define OPTION_VAL_NEAREST_PT_BR NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_br[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_PT_BR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_PT_BR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_PT_BR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_PT_BR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_PT_BR },
            { "nearest", OPTION_VAL_NEAREST_PT_BR },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_PT_PT NULL
#define CATEGORY_VIDEO_INFO_0_PT_PT NULL
#define CATEGORY_AUDIO_LABEL_PT_PT NULL
#define CATEGORY_AUDIO_INFO_0_PT_PT NULL
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
#define XEMU_RENDERER_LABEL_PT_PT NULL
#define XEMU_RENDERER_INFO_0_PT_PT NULL
#define OPTION_VAL_VULKAN_PT_PT NULL
#define OPTION_VAL_OPENGL_PT_PT NULL
#define XEMU_ASPECT_RATIO_LABEL_PT_PT NULL
#define XEMU_ASPECT_RATIO_INFO_0_PT_PT NULL
#define OPTION_VAL_AUTO_PT_PT NULL
#define OPTION_VAL_4_3_PT_PT NULL
#define OPTION_VAL_16_9_PT_PT NULL
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
#define XEMU_USE_DSP_LABEL_PT_PT NULL
#define XEMU_USE_DSP_INFO_0_PT_PT NULL
#define XEMU_CACHE_SHADERS_LABEL_PT_PT NULL
#define XEMU_CACHE_SHADERS_INFO_0_PT_PT NULL
#define XEMU_AUDIO_VOLUME_LABEL_PT_PT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PT_PT NULL
#define OPTION_VAL_100_PT_PT NULL
#define OPTION_VAL_80_PT_PT NULL
#define OPTION_VAL_60_PT_PT NULL
#define OPTION_VAL_40_PT_PT NULL
#define OPTION_VAL_20_PT_PT NULL
#define OPTION_VAL_0_PT_PT NULL
#define XEMU_DISPLAY_FILTERING_LABEL_PT_PT NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_PT_PT NULL
#define OPTION_VAL_LINEAR_PT_PT NULL
#define OPTION_VAL_NEAREST_PT_PT NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_pt_pt[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_PT_PT,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_PT_PT,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_PT_PT,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_PT_PT,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_PT_PT },
            { "nearest", OPTION_VAL_NEAREST_PT_PT },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_RU NULL
#define CATEGORY_VIDEO_INFO_0_RU NULL
#define CATEGORY_AUDIO_LABEL_RU NULL
#define CATEGORY_AUDIO_INFO_0_RU NULL
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
#define XEMU_RENDERER_LABEL_RU NULL
#define XEMU_RENDERER_INFO_0_RU NULL
#define OPTION_VAL_VULKAN_RU NULL
#define OPTION_VAL_OPENGL_RU NULL
#define XEMU_ASPECT_RATIO_LABEL_RU NULL
#define XEMU_ASPECT_RATIO_INFO_0_RU NULL
#define OPTION_VAL_AUTO_RU NULL
#define OPTION_VAL_4_3_RU NULL
#define OPTION_VAL_16_9_RU NULL
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
#define OPTION_VAL_COMPOSITE_RU NULL
#define OPTION_VAL_SVIDEO_RU NULL
#define OPTION_VAL_SCART_RU NULL
#define OPTION_VAL_VGA_RU NULL
#define XEMU_USE_DSP_LABEL_RU NULL
#define XEMU_USE_DSP_INFO_0_RU NULL
#define XEMU_CACHE_SHADERS_LABEL_RU NULL
#define XEMU_CACHE_SHADERS_INFO_0_RU NULL
#define XEMU_AUDIO_VOLUME_LABEL_RU NULL
#define XEMU_AUDIO_VOLUME_INFO_0_RU NULL
#define OPTION_VAL_100_RU NULL
#define OPTION_VAL_80_RU NULL
#define OPTION_VAL_60_RU NULL
#define OPTION_VAL_40_RU NULL
#define OPTION_VAL_20_RU NULL
#define OPTION_VAL_0_RU NULL
#define XEMU_DISPLAY_FILTERING_LABEL_RU NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_RU NULL
#define OPTION_VAL_LINEAR_RU NULL
#define OPTION_VAL_NEAREST_RU NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_ru[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_RU,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_RU,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_RU,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_RU,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_RU },
            { "nearest", OPTION_VAL_NEAREST_RU },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_ru = {
   option_cats_ru,
   option_defs_ru
};

/* RETRO_LANGUAGE_SK */

#define CATEGORY_SYSTEM_LABEL_SK NULL
#define CATEGORY_SYSTEM_INFO_0_SK NULL
#define CATEGORY_VIDEO_LABEL_SK NULL
#define CATEGORY_VIDEO_INFO_0_SK NULL
#define CATEGORY_AUDIO_LABEL_SK NULL
#define CATEGORY_AUDIO_INFO_0_SK NULL
#define XEMU_MEMORY_LABEL_SK NULL
#define XEMU_MEMORY_INFO_0_SK NULL
#define OPTION_VAL_64_SK NULL
#define OPTION_VAL_128_SK NULL
#define XEMU_NETWORK_BACKEND_LABEL_SK NULL
#define XEMU_NETWORK_BACKEND_INFO_0_SK NULL
#define OPTION_VAL_NAT_SK NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_SK NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_SK NULL
#define XEMU_HARD_FPU_LABEL_SK NULL
#define XEMU_HARD_FPU_INFO_0_SK NULL
#define XEMU_RENDERER_LABEL_SK NULL
#define XEMU_RENDERER_INFO_0_SK NULL
#define OPTION_VAL_VULKAN_SK NULL
#define OPTION_VAL_OPENGL_SK NULL
#define XEMU_ASPECT_RATIO_LABEL_SK NULL
#define XEMU_ASPECT_RATIO_INFO_0_SK NULL
#define OPTION_VAL_AUTO_SK NULL
#define OPTION_VAL_4_3_SK NULL
#define OPTION_VAL_16_9_SK NULL
#define XEMU_SURFACE_SCALE_LABEL_SK NULL
#define XEMU_SURFACE_SCALE_INFO_0_SK NULL
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
#define XEMU_AVPACK_LABEL_SK NULL
#define XEMU_AVPACK_INFO_0_SK NULL
#define OPTION_VAL_HDTV_SK NULL
#define OPTION_VAL_COMPOSITE_SK NULL
#define OPTION_VAL_SVIDEO_SK NULL
#define OPTION_VAL_SCART_SK NULL
#define OPTION_VAL_VGA_SK NULL
#define XEMU_USE_DSP_LABEL_SK NULL
#define XEMU_USE_DSP_INFO_0_SK NULL
#define XEMU_CACHE_SHADERS_LABEL_SK NULL
#define XEMU_CACHE_SHADERS_INFO_0_SK NULL
#define XEMU_AUDIO_VOLUME_LABEL_SK NULL
#define XEMU_AUDIO_VOLUME_INFO_0_SK NULL
#define OPTION_VAL_100_SK NULL
#define OPTION_VAL_80_SK NULL
#define OPTION_VAL_60_SK NULL
#define OPTION_VAL_40_SK NULL
#define OPTION_VAL_20_SK NULL
#define OPTION_VAL_0_SK NULL
#define XEMU_DISPLAY_FILTERING_LABEL_SK NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_SK NULL
#define OPTION_VAL_LINEAR_SK NULL
#define OPTION_VAL_NEAREST_SK NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sk[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_SK,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_SK,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_SK,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_SK,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_SK },
            { "nearest", OPTION_VAL_NEAREST_SK },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_sk = {
   option_cats_sk,
   option_defs_sk
};

/* RETRO_LANGUAGE_SV */

#define CATEGORY_SYSTEM_LABEL_SV NULL
#define CATEGORY_SYSTEM_INFO_0_SV NULL
#define CATEGORY_VIDEO_LABEL_SV NULL
#define CATEGORY_VIDEO_INFO_0_SV NULL
#define CATEGORY_AUDIO_LABEL_SV NULL
#define CATEGORY_AUDIO_INFO_0_SV NULL
#define XEMU_MEMORY_LABEL_SV NULL
#define XEMU_MEMORY_INFO_0_SV NULL
#define OPTION_VAL_64_SV NULL
#define OPTION_VAL_128_SV NULL
#define XEMU_NETWORK_BACKEND_LABEL_SV NULL
#define XEMU_NETWORK_BACKEND_INFO_0_SV NULL
#define OPTION_VAL_NAT_SV NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_SV NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_SV NULL
#define XEMU_HARD_FPU_LABEL_SV NULL
#define XEMU_HARD_FPU_INFO_0_SV NULL
#define XEMU_RENDERER_LABEL_SV NULL
#define XEMU_RENDERER_INFO_0_SV NULL
#define OPTION_VAL_VULKAN_SV NULL
#define OPTION_VAL_OPENGL_SV NULL
#define XEMU_ASPECT_RATIO_LABEL_SV NULL
#define XEMU_ASPECT_RATIO_INFO_0_SV NULL
#define OPTION_VAL_AUTO_SV NULL
#define OPTION_VAL_4_3_SV NULL
#define OPTION_VAL_16_9_SV NULL
#define XEMU_SURFACE_SCALE_LABEL_SV NULL
#define XEMU_SURFACE_SCALE_INFO_0_SV NULL
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
#define XEMU_AVPACK_INFO_0_SV NULL
#define OPTION_VAL_HDTV_SV NULL
#define OPTION_VAL_COMPOSITE_SV NULL
#define OPTION_VAL_SVIDEO_SV NULL
#define OPTION_VAL_SCART_SV NULL
#define OPTION_VAL_VGA_SV NULL
#define XEMU_USE_DSP_LABEL_SV NULL
#define XEMU_USE_DSP_INFO_0_SV NULL
#define XEMU_CACHE_SHADERS_LABEL_SV NULL
#define XEMU_CACHE_SHADERS_INFO_0_SV NULL
#define XEMU_AUDIO_VOLUME_LABEL_SV NULL
#define XEMU_AUDIO_VOLUME_INFO_0_SV NULL
#define OPTION_VAL_100_SV NULL
#define OPTION_VAL_80_SV NULL
#define OPTION_VAL_60_SV NULL
#define OPTION_VAL_40_SV NULL
#define OPTION_VAL_20_SV NULL
#define OPTION_VAL_0_SV NULL
#define XEMU_DISPLAY_FILTERING_LABEL_SV NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_SV NULL
#define OPTION_VAL_LINEAR_SV NULL
#define OPTION_VAL_NEAREST_SV NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sv[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_SV,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_SV,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_SV,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_SV,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_SV },
            { "nearest", OPTION_VAL_NEAREST_SV },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_sv = {
   option_cats_sv,
   option_defs_sv
};

/* RETRO_LANGUAGE_TR */

#define CATEGORY_SYSTEM_LABEL_TR NULL
#define CATEGORY_SYSTEM_INFO_0_TR NULL
#define CATEGORY_VIDEO_LABEL_TR NULL
#define CATEGORY_VIDEO_INFO_0_TR NULL
#define CATEGORY_AUDIO_LABEL_TR NULL
#define CATEGORY_AUDIO_INFO_0_TR NULL
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
#define XEMU_RENDERER_LABEL_TR NULL
#define XEMU_RENDERER_INFO_0_TR NULL
#define OPTION_VAL_VULKAN_TR NULL
#define OPTION_VAL_OPENGL_TR NULL
#define XEMU_ASPECT_RATIO_LABEL_TR NULL
#define XEMU_ASPECT_RATIO_INFO_0_TR NULL
#define OPTION_VAL_AUTO_TR NULL
#define OPTION_VAL_4_3_TR NULL
#define OPTION_VAL_16_9_TR NULL
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
#define XEMU_USE_DSP_LABEL_TR NULL
#define XEMU_USE_DSP_INFO_0_TR NULL
#define XEMU_CACHE_SHADERS_LABEL_TR NULL
#define XEMU_CACHE_SHADERS_INFO_0_TR NULL
#define XEMU_AUDIO_VOLUME_LABEL_TR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TR NULL
#define OPTION_VAL_100_TR NULL
#define OPTION_VAL_80_TR NULL
#define OPTION_VAL_60_TR NULL
#define OPTION_VAL_40_TR NULL
#define OPTION_VAL_20_TR NULL
#define OPTION_VAL_0_TR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_TR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_TR NULL
#define OPTION_VAL_LINEAR_TR NULL
#define OPTION_VAL_NEAREST_TR NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_tr[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_TR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_TR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_TR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_TR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_TR },
            { "nearest", OPTION_VAL_NEAREST_TR },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_tr = {
   option_cats_tr,
   option_defs_tr
};

/* RETRO_LANGUAGE_UK */

#define CATEGORY_SYSTEM_LABEL_UK NULL
#define CATEGORY_SYSTEM_INFO_0_UK NULL
#define CATEGORY_VIDEO_LABEL_UK NULL
#define CATEGORY_VIDEO_INFO_0_UK NULL
#define CATEGORY_AUDIO_LABEL_UK NULL
#define CATEGORY_AUDIO_INFO_0_UK NULL
#define XEMU_MEMORY_LABEL_UK NULL
#define XEMU_MEMORY_INFO_0_UK NULL
#define OPTION_VAL_64_UK NULL
#define OPTION_VAL_128_UK NULL
#define XEMU_NETWORK_BACKEND_LABEL_UK NULL
#define XEMU_NETWORK_BACKEND_INFO_0_UK NULL
#define OPTION_VAL_NAT_UK NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_UK NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_UK NULL
#define XEMU_HARD_FPU_LABEL_UK NULL
#define XEMU_HARD_FPU_INFO_0_UK NULL
#define XEMU_RENDERER_LABEL_UK NULL
#define XEMU_RENDERER_INFO_0_UK NULL
#define OPTION_VAL_VULKAN_UK NULL
#define OPTION_VAL_OPENGL_UK NULL
#define XEMU_ASPECT_RATIO_LABEL_UK NULL
#define XEMU_ASPECT_RATIO_INFO_0_UK NULL
#define OPTION_VAL_AUTO_UK NULL
#define OPTION_VAL_4_3_UK NULL
#define OPTION_VAL_16_9_UK NULL
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
#define OPTION_VAL_COMPOSITE_UK NULL
#define OPTION_VAL_SVIDEO_UK NULL
#define OPTION_VAL_SCART_UK NULL
#define OPTION_VAL_VGA_UK NULL
#define XEMU_USE_DSP_LABEL_UK NULL
#define XEMU_USE_DSP_INFO_0_UK NULL
#define XEMU_CACHE_SHADERS_LABEL_UK NULL
#define XEMU_CACHE_SHADERS_INFO_0_UK NULL
#define XEMU_AUDIO_VOLUME_LABEL_UK NULL
#define XEMU_AUDIO_VOLUME_INFO_0_UK NULL
#define OPTION_VAL_100_UK NULL
#define OPTION_VAL_80_UK NULL
#define OPTION_VAL_60_UK NULL
#define OPTION_VAL_40_UK NULL
#define OPTION_VAL_20_UK NULL
#define OPTION_VAL_0_UK NULL
#define XEMU_DISPLAY_FILTERING_LABEL_UK NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_UK NULL
#define OPTION_VAL_LINEAR_UK NULL
#define OPTION_VAL_NEAREST_UK NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_uk[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_UK,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_UK,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_UK,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_UK,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_UK },
            { "nearest", OPTION_VAL_NEAREST_UK },
            { NULL, NULL },
        },
        "linear"
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
#define CATEGORY_VIDEO_LABEL_VAL NULL
#define CATEGORY_VIDEO_INFO_0_VAL NULL
#define CATEGORY_AUDIO_LABEL_VAL NULL
#define CATEGORY_AUDIO_INFO_0_VAL NULL
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
#define XEMU_RENDERER_LABEL_VAL NULL
#define XEMU_RENDERER_INFO_0_VAL NULL
#define OPTION_VAL_VULKAN_VAL NULL
#define OPTION_VAL_OPENGL_VAL NULL
#define XEMU_ASPECT_RATIO_LABEL_VAL NULL
#define XEMU_ASPECT_RATIO_INFO_0_VAL NULL
#define OPTION_VAL_AUTO_VAL NULL
#define OPTION_VAL_4_3_VAL NULL
#define OPTION_VAL_16_9_VAL NULL
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
#define XEMU_USE_DSP_LABEL_VAL NULL
#define XEMU_USE_DSP_INFO_0_VAL NULL
#define XEMU_CACHE_SHADERS_LABEL_VAL NULL
#define XEMU_CACHE_SHADERS_INFO_0_VAL NULL
#define XEMU_AUDIO_VOLUME_LABEL_VAL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_VAL NULL
#define OPTION_VAL_100_VAL NULL
#define OPTION_VAL_80_VAL NULL
#define OPTION_VAL_60_VAL NULL
#define OPTION_VAL_40_VAL NULL
#define OPTION_VAL_20_VAL NULL
#define OPTION_VAL_0_VAL NULL
#define XEMU_DISPLAY_FILTERING_LABEL_VAL NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_VAL NULL
#define OPTION_VAL_LINEAR_VAL NULL
#define OPTION_VAL_NEAREST_VAL NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_val[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_VAL,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_VAL,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_VAL,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_VAL,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_VAL },
            { "nearest", OPTION_VAL_NEAREST_VAL },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_val = {
   option_cats_val,
   option_defs_val
};

/* RETRO_LANGUAGE_VN */

#define CATEGORY_SYSTEM_LABEL_VN NULL
#define CATEGORY_SYSTEM_INFO_0_VN NULL
#define CATEGORY_VIDEO_LABEL_VN NULL
#define CATEGORY_VIDEO_INFO_0_VN NULL
#define CATEGORY_AUDIO_LABEL_VN NULL
#define CATEGORY_AUDIO_INFO_0_VN NULL
#define XEMU_MEMORY_LABEL_VN NULL
#define XEMU_MEMORY_INFO_0_VN NULL
#define OPTION_VAL_64_VN NULL
#define OPTION_VAL_128_VN NULL
#define XEMU_NETWORK_BACKEND_LABEL_VN NULL
#define XEMU_NETWORK_BACKEND_INFO_0_VN NULL
#define OPTION_VAL_NAT_VN NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_VN NULL
#define XEMU_SKIP_BOOT_ANIM_INFO_0_VN NULL
#define XEMU_HARD_FPU_LABEL_VN NULL
#define XEMU_HARD_FPU_INFO_0_VN NULL
#define XEMU_RENDERER_LABEL_VN NULL
#define XEMU_RENDERER_INFO_0_VN NULL
#define OPTION_VAL_VULKAN_VN NULL
#define OPTION_VAL_OPENGL_VN NULL
#define XEMU_ASPECT_RATIO_LABEL_VN NULL
#define XEMU_ASPECT_RATIO_INFO_0_VN NULL
#define OPTION_VAL_AUTO_VN NULL
#define OPTION_VAL_4_3_VN NULL
#define OPTION_VAL_16_9_VN NULL
#define XEMU_SURFACE_SCALE_LABEL_VN NULL
#define XEMU_SURFACE_SCALE_INFO_0_VN NULL
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
#define XEMU_AVPACK_LABEL_VN NULL
#define XEMU_AVPACK_INFO_0_VN NULL
#define OPTION_VAL_HDTV_VN NULL
#define OPTION_VAL_COMPOSITE_VN NULL
#define OPTION_VAL_SVIDEO_VN NULL
#define OPTION_VAL_SCART_VN NULL
#define OPTION_VAL_VGA_VN NULL
#define XEMU_USE_DSP_LABEL_VN NULL
#define XEMU_USE_DSP_INFO_0_VN NULL
#define XEMU_CACHE_SHADERS_LABEL_VN NULL
#define XEMU_CACHE_SHADERS_INFO_0_VN NULL
#define XEMU_AUDIO_VOLUME_LABEL_VN NULL
#define XEMU_AUDIO_VOLUME_INFO_0_VN NULL
#define OPTION_VAL_100_VN NULL
#define OPTION_VAL_80_VN NULL
#define OPTION_VAL_60_VN NULL
#define OPTION_VAL_40_VN NULL
#define OPTION_VAL_20_VN NULL
#define OPTION_VAL_0_VN NULL
#define XEMU_DISPLAY_FILTERING_LABEL_VN NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_VN NULL
#define OPTION_VAL_LINEAR_VN NULL
#define OPTION_VAL_NEAREST_VN NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_vn[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_VN,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_VN,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_VN,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_VN,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_VN },
            { "nearest", OPTION_VAL_NEAREST_VN },
            { NULL, NULL },
        },
        "linear"
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