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

#define CATEGORY_SYSTEM_LABEL_AR "نظام"
#define CATEGORY_SYSTEM_INFO_0_AR NULL
#define CATEGORY_VIDEO_LABEL_AR "الفيديو"
#define CATEGORY_VIDEO_INFO_0_AR NULL
#define CATEGORY_AUDIO_LABEL_AR "الصوت"
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
#define XEMU_ASPECT_RATIO_LABEL_AR "نسبة الجانب"
#define XEMU_ASPECT_RATIO_INFO_0_AR NULL
#define OPTION_VAL_AUTO_AR "تلقائي"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_AR NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_AR NULL
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
#define OPTION_VAL_LINEAR_AR "ثنائي"
#define OPTION_VAL_NEAREST_AR "أقرب جوار"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_AR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_AR,
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

#define CATEGORY_SYSTEM_LABEL_AST "Sistema"
#define CATEGORY_SYSTEM_INFO_0_AST NULL
#define CATEGORY_VIDEO_LABEL_AST "Videu"
#define CATEGORY_VIDEO_INFO_0_AST NULL
#define CATEGORY_AUDIO_LABEL_AST "Audiu"
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
#define XEMU_ASPECT_RATIO_LABEL_AST "Proporción del aspeutu"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_AST NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_AST NULL
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
#define OPTION_VAL_LINEAR_AST "Billinial"
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_AST,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_AST,
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

#define CATEGORY_SYSTEM_LABEL_BE "Сістэма"
#define CATEGORY_SYSTEM_INFO_0_BE NULL
#define CATEGORY_VIDEO_LABEL_BE "Відэа"
#define CATEGORY_VIDEO_INFO_0_BE NULL
#define CATEGORY_AUDIO_LABEL_BE "Аўдыя"
#define CATEGORY_AUDIO_INFO_0_BE NULL
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
#define XEMU_RENDERER_LABEL_BE NULL
#define XEMU_RENDERER_INFO_0_BE NULL
#define OPTION_VAL_VULKAN_BE NULL
#define OPTION_VAL_OPENGL_BE NULL
#define XEMU_ASPECT_RATIO_LABEL_BE "Суадносіны бакоў"
#define XEMU_ASPECT_RATIO_INFO_0_BE NULL
#define OPTION_VAL_AUTO_BE "Аўта"
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
#define OPTION_VAL_COMPOSITE_BE "Кампазітны"
#define OPTION_VAL_SVIDEO_BE NULL
#define OPTION_VAL_SCART_BE NULL
#define OPTION_VAL_VGA_BE NULL
#define XEMU_USE_DSP_LABEL_BE NULL
#define XEMU_USE_DSP_INFO_0_BE NULL
#define XEMU_CACHE_SHADERS_LABEL_BE NULL
#define XEMU_CACHE_SHADERS_INFO_0_BE NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_BE NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_BE NULL
#define XEMU_AUDIO_VOLUME_LABEL_BE NULL
#define XEMU_AUDIO_VOLUME_INFO_0_BE NULL
#define OPTION_VAL_100_BE "100 %"
#define OPTION_VAL_80_BE "80 %"
#define OPTION_VAL_60_BE "60 %"
#define OPTION_VAL_40_BE "40 %"
#define OPTION_VAL_20_BE "20 %"
#define OPTION_VAL_0_BE NULL
#define XEMU_DISPLAY_FILTERING_LABEL_BE NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_BE NULL
#define OPTION_VAL_LINEAR_BE "Білінейны"
#define OPTION_VAL_NEAREST_BE "Метад бліжэйшага суседа"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_BE,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_BE,
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

/* RETRO_LANGUAGE_BG */

#define CATEGORY_SYSTEM_LABEL_BG NULL
#define CATEGORY_SYSTEM_INFO_0_BG NULL
#define CATEGORY_VIDEO_LABEL_BG "Видео"
#define CATEGORY_VIDEO_INFO_0_BG NULL
#define CATEGORY_AUDIO_LABEL_BG "Звук"
#define CATEGORY_AUDIO_INFO_0_BG NULL
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
#define XEMU_RENDERER_LABEL_BG NULL
#define XEMU_RENDERER_INFO_0_BG NULL
#define OPTION_VAL_VULKAN_BG NULL
#define OPTION_VAL_OPENGL_BG NULL
#define XEMU_ASPECT_RATIO_LABEL_BG NULL
#define XEMU_ASPECT_RATIO_INFO_0_BG NULL
#define OPTION_VAL_AUTO_BG NULL
#define OPTION_VAL_4_3_BG NULL
#define OPTION_VAL_16_9_BG NULL
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
#define XEMU_USE_DSP_LABEL_BG NULL
#define XEMU_USE_DSP_INFO_0_BG NULL
#define XEMU_CACHE_SHADERS_LABEL_BG NULL
#define XEMU_CACHE_SHADERS_INFO_0_BG NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_BG NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_BG NULL
#define XEMU_AUDIO_VOLUME_LABEL_BG NULL
#define XEMU_AUDIO_VOLUME_INFO_0_BG NULL
#define OPTION_VAL_100_BG NULL
#define OPTION_VAL_80_BG NULL
#define OPTION_VAL_60_BG NULL
#define OPTION_VAL_40_BG NULL
#define OPTION_VAL_20_BG NULL
#define OPTION_VAL_0_BG NULL
#define XEMU_DISPLAY_FILTERING_LABEL_BG NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_BG NULL
#define OPTION_VAL_LINEAR_BG NULL
#define OPTION_VAL_NEAREST_BG NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_bg[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_BG,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_BG,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_BG,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_BG,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_BG,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_BG,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_BG },
            { "nearest", OPTION_VAL_NEAREST_BG },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_bg = {
   option_cats_bg,
   option_defs_bg
};

/* RETRO_LANGUAGE_CA */

#define CATEGORY_SYSTEM_LABEL_CA "Sistema"
#define CATEGORY_SYSTEM_INFO_0_CA NULL
#define CATEGORY_VIDEO_LABEL_CA "Vídeo"
#define CATEGORY_VIDEO_INFO_0_CA NULL
#define CATEGORY_AUDIO_LABEL_CA "Àudio"
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
#define XEMU_ASPECT_RATIO_LABEL_CA "Relació d'aspecte"
#define XEMU_ASPECT_RATIO_INFO_0_CA NULL
#define OPTION_VAL_AUTO_CA "Automàtic"
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
#define OPTION_VAL_COMPOSITE_CA "Composició"
#define OPTION_VAL_SVIDEO_CA NULL
#define OPTION_VAL_SCART_CA NULL
#define OPTION_VAL_VGA_CA NULL
#define XEMU_USE_DSP_LABEL_CA NULL
#define XEMU_USE_DSP_INFO_0_CA NULL
#define XEMU_CACHE_SHADERS_LABEL_CA NULL
#define XEMU_CACHE_SHADERS_INFO_0_CA NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_CA NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_CA NULL
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
#define OPTION_VAL_LINEAR_CA "Bilineal"
#define OPTION_VAL_NEAREST_CA "Veí més proper"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_CA,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_CA,
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

#define CATEGORY_SYSTEM_LABEL_CHS "系统"
#define CATEGORY_SYSTEM_INFO_0_CHS NULL
#define CATEGORY_VIDEO_LABEL_CHS "视频"
#define CATEGORY_VIDEO_INFO_0_CHS NULL
#define CATEGORY_AUDIO_LABEL_CHS "音频"
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
#define XEMU_ASPECT_RATIO_LABEL_CHS "宽高比"
#define XEMU_ASPECT_RATIO_INFO_0_CHS NULL
#define OPTION_VAL_AUTO_CHS "自动"
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
#define OPTION_VAL_COMPOSITE_CHS "复合"
#define OPTION_VAL_SVIDEO_CHS "S-视频"
#define OPTION_VAL_SCART_CHS NULL
#define OPTION_VAL_VGA_CHS NULL
#define XEMU_USE_DSP_LABEL_CHS NULL
#define XEMU_USE_DSP_INFO_0_CHS NULL
#define XEMU_CACHE_SHADERS_LABEL_CHS NULL
#define XEMU_CACHE_SHADERS_INFO_0_CHS NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_CHS NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_CHS NULL
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
#define OPTION_VAL_LINEAR_CHS "双线性"
#define OPTION_VAL_NEAREST_CHS "最近邻"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_CHS,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_CHS,
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

#define CATEGORY_SYSTEM_LABEL_CHT "系統"
#define CATEGORY_SYSTEM_INFO_0_CHT NULL
#define CATEGORY_VIDEO_LABEL_CHT "顯示"
#define CATEGORY_VIDEO_INFO_0_CHT NULL
#define CATEGORY_AUDIO_LABEL_CHT "音效"
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
#define XEMU_ASPECT_RATIO_LABEL_CHT "寬高比"
#define XEMU_ASPECT_RATIO_INFO_0_CHT NULL
#define OPTION_VAL_AUTO_CHT "自動"
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
#define OPTION_VAL_COMPOSITE_CHT "AV端子 (複合端子)"
#define OPTION_VAL_SVIDEO_CHT "S-端子 (獨立視訊端子)"
#define OPTION_VAL_SCART_CHT NULL
#define OPTION_VAL_VGA_CHT NULL
#define XEMU_USE_DSP_LABEL_CHT NULL
#define XEMU_USE_DSP_INFO_0_CHT NULL
#define XEMU_CACHE_SHADERS_LABEL_CHT NULL
#define XEMU_CACHE_SHADERS_INFO_0_CHT NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_CHT NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_CHT NULL
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
#define OPTION_VAL_LINEAR_CHT "雙線性"
#define OPTION_VAL_NEAREST_CHT "最近鄰法"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_CHT,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_CHT,
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

#define CATEGORY_SYSTEM_LABEL_CS "Systém"
#define CATEGORY_SYSTEM_INFO_0_CS NULL
#define CATEGORY_VIDEO_LABEL_CS NULL
#define CATEGORY_VIDEO_INFO_0_CS NULL
#define CATEGORY_AUDIO_LABEL_CS "Zvuk"
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
#define XEMU_ASPECT_RATIO_LABEL_CS "Poměr stran"
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
#define OPTION_VAL_COMPOSITE_CS "Kompozitní"
#define OPTION_VAL_SVIDEO_CS NULL
#define OPTION_VAL_SCART_CS NULL
#define OPTION_VAL_VGA_CS NULL
#define XEMU_USE_DSP_LABEL_CS NULL
#define XEMU_USE_DSP_INFO_0_CS NULL
#define XEMU_CACHE_SHADERS_LABEL_CS NULL
#define XEMU_CACHE_SHADERS_INFO_0_CS NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_CS NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_CS NULL
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
#define OPTION_VAL_LINEAR_CS "Bilineární"
#define OPTION_VAL_NEAREST_CS "Nejbližší soused"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_CS,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_CS,
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

/* RETRO_LANGUAGE_CY */

#define CATEGORY_SYSTEM_LABEL_CY NULL
#define CATEGORY_SYSTEM_INFO_0_CY NULL
#define CATEGORY_VIDEO_LABEL_CY NULL
#define CATEGORY_VIDEO_INFO_0_CY NULL
#define CATEGORY_AUDIO_LABEL_CY NULL
#define CATEGORY_AUDIO_INFO_0_CY NULL
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
#define XEMU_RENDERER_LABEL_CY NULL
#define XEMU_RENDERER_INFO_0_CY NULL
#define OPTION_VAL_VULKAN_CY NULL
#define OPTION_VAL_OPENGL_CY NULL
#define XEMU_ASPECT_RATIO_LABEL_CY NULL
#define XEMU_ASPECT_RATIO_INFO_0_CY NULL
#define OPTION_VAL_AUTO_CY NULL
#define OPTION_VAL_4_3_CY NULL
#define OPTION_VAL_16_9_CY NULL
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
#define XEMU_USE_DSP_LABEL_CY NULL
#define XEMU_USE_DSP_INFO_0_CY NULL
#define XEMU_CACHE_SHADERS_LABEL_CY NULL
#define XEMU_CACHE_SHADERS_INFO_0_CY NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_CY NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_CY NULL
#define XEMU_AUDIO_VOLUME_LABEL_CY NULL
#define XEMU_AUDIO_VOLUME_INFO_0_CY NULL
#define OPTION_VAL_100_CY NULL
#define OPTION_VAL_80_CY NULL
#define OPTION_VAL_60_CY NULL
#define OPTION_VAL_40_CY NULL
#define OPTION_VAL_20_CY NULL
#define OPTION_VAL_0_CY NULL
#define XEMU_DISPLAY_FILTERING_LABEL_CY NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_CY NULL
#define OPTION_VAL_LINEAR_CY NULL
#define OPTION_VAL_NEAREST_CY NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_cy[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_CY,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_CY,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_CY,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_CY,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_CY,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_CY,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_CY },
            { "nearest", OPTION_VAL_NEAREST_CY },
            { NULL, NULL },
        },
        "linear"
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
#define XEMU_RENDERER_LABEL_DA NULL
#define XEMU_RENDERER_INFO_0_DA NULL
#define OPTION_VAL_VULKAN_DA NULL
#define OPTION_VAL_OPENGL_DA NULL
#define XEMU_ASPECT_RATIO_LABEL_DA NULL
#define XEMU_ASPECT_RATIO_INFO_0_DA NULL
#define OPTION_VAL_AUTO_DA NULL
#define OPTION_VAL_4_3_DA NULL
#define OPTION_VAL_16_9_DA NULL
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
#define XEMU_USE_DSP_LABEL_DA NULL
#define XEMU_USE_DSP_INFO_0_DA NULL
#define XEMU_CACHE_SHADERS_LABEL_DA NULL
#define XEMU_CACHE_SHADERS_INFO_0_DA NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_DA NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_DA NULL
#define XEMU_AUDIO_VOLUME_LABEL_DA NULL
#define XEMU_AUDIO_VOLUME_INFO_0_DA NULL
#define OPTION_VAL_100_DA NULL
#define OPTION_VAL_80_DA NULL
#define OPTION_VAL_60_DA NULL
#define OPTION_VAL_40_DA NULL
#define OPTION_VAL_20_DA NULL
#define OPTION_VAL_0_DA NULL
#define XEMU_DISPLAY_FILTERING_LABEL_DA NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_DA NULL
#define OPTION_VAL_LINEAR_DA NULL
#define OPTION_VAL_NEAREST_DA NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_da[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_DA,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_DA,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_DA,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_DA,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_DA,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_DA,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_DA },
            { "nearest", OPTION_VAL_NEAREST_DA },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_da = {
   option_cats_da,
   option_defs_da
};

/* RETRO_LANGUAGE_DE */

#define CATEGORY_SYSTEM_LABEL_DE NULL
#define CATEGORY_SYSTEM_INFO_0_DE "Systemweite Einstellungen wie BIOS-Pfade, Speicher und Startoptionen konfigurieren."
#define CATEGORY_VIDEO_LABEL_DE NULL
#define CATEGORY_VIDEO_INFO_0_DE "Videorendering-Einstellungen konfigurieren."
#define CATEGORY_AUDIO_LABEL_DE NULL
#define CATEGORY_AUDIO_INFO_0_DE "Audioemulationseinstellungen konfigurieren."
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
#define XEMU_RENDERER_LABEL_DE "Grafik-API (Neustart)"
#define XEMU_RENDERER_INFO_0_DE "Renderer für die Darstellung der emulierten GPU. Vulkan ist die Standardeinstellung; OpenGL dient als Ausweichlösung bei Treibern, mit denen Vulkan Probleme verursacht. Änderung wird nach einem Neustart von RetroArch wirksam. Unter Android wird immer Vulkan verwendet, unter macOS immer OpenGL."
#define OPTION_VAL_VULKAN_DE NULL
#define OPTION_VAL_OPENGL_DE NULL
#define XEMU_ASPECT_RATIO_LABEL_DE "Bildseitenverhältnis"
#define XEMU_ASPECT_RATIO_INFO_0_DE "Seitenverhältnis der Bildanzeige. „Automatisch“ richtet sich nach dem Spiel: 16:9, wenn die Konsole auf Breitbild umschaltet (Breitbild muss in den Videoeinstellungen des Dashboards aktiviert sein), andernfalls 4:3. „16:9“ wählen, wenn ein Spiel im Breitbildformat rendert, aber gestaucht angezeigt wird."
#define OPTION_VAL_AUTO_DE NULL
#define OPTION_VAL_4_3_DE NULL
#define OPTION_VAL_16_9_DE NULL
#define XEMU_SURFACE_SCALE_LABEL_DE "Interne Auflösungsskalierung"
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
#define XEMU_AVPACK_LABEL_DE "AV-Paket"
#define XEMU_AVPACK_INFO_0_DE "AV-Pakettyp auswählen. Beeinflusst die verfügbaren Videomodi."
#define OPTION_VAL_HDTV_DE NULL
#define OPTION_VAL_COMPOSITE_DE NULL
#define OPTION_VAL_SVIDEO_DE NULL
#define OPTION_VAL_SCART_DE NULL
#define OPTION_VAL_VGA_DE NULL
#define XEMU_USE_DSP_LABEL_DE "APU-DSP-Emulation"
#define XEMU_USE_DSP_INFO_0_DE "DSP-Emulation für eine höhere Audiogenauigkeit aktivieren. Kann die Leistung beeinträchtigen."
#define XEMU_CACHE_SHADERS_LABEL_DE "Shadercache"
#define XEMU_CACHE_SHADERS_INFO_0_DE "Kompilierte GPU-Shader auf dem Datenträger zwischenspeichern. Verringert Ruckler bei späteren Starts."
#define XEMU_VK_REDUCED_BUFFERS_LABEL_DE "Reduzierte Vulkan-Puffer (Neustart erforderlich)"
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_DE "Der Vulkan-Renderer reserviert beim Start seine Arbeitspuffer unabhängig davon, was das Spiel benötigt. Bei aktivierter Option wird der Puffer für Inline-Vertexdaten auf ein Zehntel der Größe von xemu begrenzt. Dadurch wird etwa 1,2 GB weniger Videospeicher und ebenso viel weniger Systemspeicher belegt. Bei deaktivierter Option wird auf Grafikkarten mit mindestens 4 GB Videospeicher die volle Puffergröße von xemu reserviert. Diese Einstellung ausprobieren, wenn ein Spiel bei aktivierter Option langsamer läuft."
#define XEMU_AUDIO_VOLUME_LABEL_DE "Maximale Audiolautstärke (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_DE "Lautstärke der Xbox-Audioausgabe unabhängig von der RetroArch-Gesamtlautstärke begrenzen."
#define OPTION_VAL_100_DE "100 %"
#define OPTION_VAL_80_DE "80 %"
#define OPTION_VAL_60_DE "60 %"
#define OPTION_VAL_40_DE "40 %"
#define OPTION_VAL_20_DE "20 %"
#define OPTION_VAL_0_DE "Stummgeschaltet"
#define XEMU_DISPLAY_FILTERING_LABEL_DE "Anzeigefilterung"
#define XEMU_DISPLAY_FILTERING_INFO_0_DE "Texturfiltermodus für die Bildschirmausgabe."
#define OPTION_VAL_LINEAR_DE NULL
#define OPTION_VAL_NEAREST_DE "Nächste-Nachbarn"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_DE,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_DE,
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

#define CATEGORY_SYSTEM_LABEL_EL "Σύστημα"
#define CATEGORY_SYSTEM_INFO_0_EL NULL
#define CATEGORY_VIDEO_LABEL_EL "Βίντεο"
#define CATEGORY_VIDEO_INFO_0_EL NULL
#define CATEGORY_AUDIO_LABEL_EL "Ήχος"
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
#define XEMU_ASPECT_RATIO_LABEL_EL "Αναλογία Οθόνης"
#define XEMU_ASPECT_RATIO_INFO_0_EL NULL
#define OPTION_VAL_AUTO_EL "Αυτόματο"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_EL NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_EL NULL
#define XEMU_AUDIO_VOLUME_LABEL_EL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_EL NULL
#define OPTION_VAL_100_EL NULL
#define OPTION_VAL_80_EL "το 80%"
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_EL,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_EL,
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_EN NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_EN NULL
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
#define OPTION_VAL_NEAREST_EN "Nearest Neighbour"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_EN,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_EN,
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

#define CATEGORY_SYSTEM_LABEL_EO "Sistemo"
#define CATEGORY_SYSTEM_INFO_0_EO NULL
#define CATEGORY_VIDEO_LABEL_EO NULL
#define CATEGORY_VIDEO_INFO_0_EO NULL
#define CATEGORY_AUDIO_LABEL_EO "Sono"
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
#define XEMU_ASPECT_RATIO_LABEL_EO "Bilda proporcio"
#define XEMU_ASPECT_RATIO_INFO_0_EO NULL
#define OPTION_VAL_AUTO_EO "Aŭtomata"
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
#define OPTION_VAL_COMPOSITE_EO "Kunmetita"
#define OPTION_VAL_SVIDEO_EO NULL
#define OPTION_VAL_SCART_EO NULL
#define OPTION_VAL_VGA_EO NULL
#define XEMU_USE_DSP_LABEL_EO NULL
#define XEMU_USE_DSP_INFO_0_EO NULL
#define XEMU_CACHE_SHADERS_LABEL_EO NULL
#define XEMU_CACHE_SHADERS_INFO_0_EO NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_EO NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_EO NULL
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
#define OPTION_VAL_LINEAR_EO "Dulineara"
#define OPTION_VAL_NEAREST_EO "Plej proksima najbaro"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_EO,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_EO,
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

#define CATEGORY_SYSTEM_LABEL_ES "Sistema"
#define CATEGORY_SYSTEM_INFO_0_ES NULL
#define CATEGORY_VIDEO_LABEL_ES "Vídeo"
#define CATEGORY_VIDEO_INFO_0_ES NULL
#define CATEGORY_AUDIO_LABEL_ES NULL
#define CATEGORY_AUDIO_INFO_0_ES NULL
#define XEMU_MEMORY_LABEL_ES "Memoria del sistema (MB)"
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
#define XEMU_ASPECT_RATIO_LABEL_ES "Relación de aspecto"
#define XEMU_ASPECT_RATIO_INFO_0_ES NULL
#define OPTION_VAL_AUTO_ES "Automático"
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
#define OPTION_VAL_COMPOSITE_ES "Vídeo compuesto"
#define OPTION_VAL_SVIDEO_ES NULL
#define OPTION_VAL_SCART_ES "Euroconector"
#define OPTION_VAL_VGA_ES NULL
#define XEMU_USE_DSP_LABEL_ES NULL
#define XEMU_USE_DSP_INFO_0_ES NULL
#define XEMU_CACHE_SHADERS_LABEL_ES NULL
#define XEMU_CACHE_SHADERS_INFO_0_ES NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_ES NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_ES NULL
#define XEMU_AUDIO_VOLUME_LABEL_ES NULL
#define XEMU_AUDIO_VOLUME_INFO_0_ES NULL
#define OPTION_VAL_100_ES "100 %"
#define OPTION_VAL_80_ES "80 %"
#define OPTION_VAL_60_ES "60 %"
#define OPTION_VAL_40_ES "40 %"
#define OPTION_VAL_20_ES "20 %"
#define OPTION_VAL_0_ES NULL
#define XEMU_DISPLAY_FILTERING_LABEL_ES NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_ES NULL
#define OPTION_VAL_LINEAR_ES "Bilineal"
#define OPTION_VAL_NEAREST_ES "Vecino más próximo"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_ES,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_ES,
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

#define CATEGORY_SYSTEM_LABEL_FA "سیستم"
#define CATEGORY_SYSTEM_INFO_0_FA NULL
#define CATEGORY_VIDEO_LABEL_FA "ویدیو"
#define CATEGORY_VIDEO_INFO_0_FA NULL
#define CATEGORY_AUDIO_LABEL_FA "صدا"
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
#define XEMU_ASPECT_RATIO_LABEL_FA "نسبت تصویر"
#define XEMU_ASPECT_RATIO_INFO_0_FA NULL
#define OPTION_VAL_AUTO_FA "خودکار"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_FA NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_FA NULL
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
#define OPTION_VAL_NEAREST_FA "نزدیک‌ترین همسایه"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_FA,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_FA,
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

#define CATEGORY_SYSTEM_LABEL_FI "Järjestelmä"
#define CATEGORY_SYSTEM_INFO_0_FI NULL
#define CATEGORY_VIDEO_LABEL_FI NULL
#define CATEGORY_VIDEO_INFO_0_FI NULL
#define CATEGORY_AUDIO_LABEL_FI "Ääni"
#define CATEGORY_AUDIO_INFO_0_FI NULL
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
#define XEMU_RENDERER_LABEL_FI NULL
#define XEMU_RENDERER_INFO_0_FI NULL
#define OPTION_VAL_VULKAN_FI NULL
#define OPTION_VAL_OPENGL_FI NULL
#define XEMU_ASPECT_RATIO_LABEL_FI "Kuvasuhde"
#define XEMU_ASPECT_RATIO_INFO_0_FI NULL
#define OPTION_VAL_AUTO_FI "Automaattinen"
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
#define OPTION_VAL_COMPOSITE_FI "Komposiitti"
#define OPTION_VAL_SVIDEO_FI NULL
#define OPTION_VAL_SCART_FI NULL
#define OPTION_VAL_VGA_FI NULL
#define XEMU_USE_DSP_LABEL_FI NULL
#define XEMU_USE_DSP_INFO_0_FI NULL
#define XEMU_CACHE_SHADERS_LABEL_FI NULL
#define XEMU_CACHE_SHADERS_INFO_0_FI NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_FI NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_FI NULL
#define XEMU_AUDIO_VOLUME_LABEL_FI NULL
#define XEMU_AUDIO_VOLUME_INFO_0_FI NULL
#define OPTION_VAL_100_FI "100 %"
#define OPTION_VAL_80_FI "80 %"
#define OPTION_VAL_60_FI "60 %"
#define OPTION_VAL_40_FI "40 %"
#define OPTION_VAL_20_FI "20 %"
#define OPTION_VAL_0_FI NULL
#define XEMU_DISPLAY_FILTERING_LABEL_FI NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_FI NULL
#define OPTION_VAL_LINEAR_FI "Bilineaarinen"
#define OPTION_VAL_NEAREST_FI "Lähin naapuri"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_FI,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_FI,
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

#define CATEGORY_SYSTEM_LABEL_FR "Système"
#define CATEGORY_SYSTEM_INFO_0_FR "Configurer les réglages du système tels que les chemins d'accès du BIOS, la mémoire et les options de démarrage."
#define CATEGORY_VIDEO_LABEL_FR "Vidéo"
#define CATEGORY_VIDEO_INFO_0_FR "Configurer les réglages de rendu vidéo."
#define CATEGORY_AUDIO_LABEL_FR "Audio "
#define CATEGORY_AUDIO_INFO_0_FR "Configurer les réglages d'émulation audio."
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
#define XEMU_RENDERER_LABEL_FR "API graphique (redémarrage)"
#define XEMU_RENDERER_INFO_0_FR "Le moteur de rendu utilisé pour afficher le processeur graphique émulé. Vulkan est l'option par défaut ; OpenGL sert d'alternative lorsque Vulkan ne fonctionne pas correctement. La modification prend effet après le redémarrage de RetroArch. Android utilise toujours Vulkan, tandis que macOS utilise toujours OpenGL."
#define OPTION_VAL_VULKAN_FR NULL
#define OPTION_VAL_OPENGL_FR NULL
#define XEMU_ASPECT_RATIO_LABEL_FR "Rapport d'aspect"
#define XEMU_ASPECT_RATIO_INFO_0_FR "Le format d'affichage de l'image. Auto s'adapte au jeu : 16:9 lorsque la console bascule en mode écran large (Écran large doit être activé dans les paramètres vidéo du tableau de bord), et 4:3 dans le cas contraire. Choisissez le format 16:9 pour un jeu conçu pour l'écran large mais qui s'affiche de manière écrasée."
#define OPTION_VAL_AUTO_FR NULL
#define OPTION_VAL_4_3_FR NULL
#define OPTION_VAL_16_9_FR NULL
#define XEMU_SURFACE_SCALE_LABEL_FR "Échelle de résolution interne"
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
#define XEMU_USE_DSP_LABEL_FR "Émulation du DSP de l'APU"
#define XEMU_USE_DSP_INFO_0_FR "Activer l'émulation du DSP pour une meilleure fidélité audio. Cela peut affecter les performances."
#define XEMU_CACHE_SHADERS_LABEL_FR "Cache de shaders"
#define XEMU_CACHE_SHADERS_INFO_0_FR "Mettre en cache sur le disque les shaders de processeur graphique compilés. Réduit les saccades lors des exécutions ultérieures."
#define XEMU_VK_REDUCED_BUFFERS_LABEL_FR "Tampons Vulkan réduits (redémarrage)"
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_FR "Le moteur de rendu Vulkan réserve ses tampons de travail au démarrage, indépendamment des besoins du jeu. Lorsqu'elle est activée, cette option limite la taille du tampon pour les données de sommets (vertex) intégrées à un dixième de la taille utilisée par xemu, ce qui permet d'économiser environ 1,2 Go de mémoire vidéo ainsi qu'une quantité équivalente de mémoire système. Lorsqu'elle est désactivée, la taille totale requise par xemu est réservée sur les cartes graphiques disposant de 4 Go de mémoire ou plus ; essayez de la désactiver si un jeu fonctionne plus lentement avec cette option activée."
#define XEMU_AUDIO_VOLUME_LABEL_FR "Limite de volume audio (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_FR "Limiter le volume de sortie audio de la Xbox indépendamment du volume principal de RetroArch."
#define OPTION_VAL_100_FR "100 %"
#define OPTION_VAL_80_FR "80 %"
#define OPTION_VAL_60_FR "60 %"
#define OPTION_VAL_40_FR "40 %"
#define OPTION_VAL_20_FR "20 %"
#define OPTION_VAL_0_FR "Muet"
#define XEMU_DISPLAY_FILTERING_LABEL_FR "Filtrage d'affichage"
#define XEMU_DISPLAY_FILTERING_INFO_0_FR "Mode de filtrage de texture pour la sortie d'affichage."
#define OPTION_VAL_LINEAR_FR "Bilinéaire"
#define OPTION_VAL_NEAREST_FR "Au plus proche"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_FR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_FR,
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

#define CATEGORY_SYSTEM_LABEL_GA "Córas"
#define CATEGORY_SYSTEM_INFO_0_GA "Cumraigh socruithe ar leibhéal an chórais, amhail conairí BIOS, cuimhne, agus roghanna tosaithe."
#define CATEGORY_VIDEO_LABEL_GA "Físeán"
#define CATEGORY_VIDEO_INFO_0_GA "Cumraigh socruithe rindreála físe."
#define CATEGORY_AUDIO_LABEL_GA "Fuaim"
#define CATEGORY_AUDIO_INFO_0_GA "Cumraigh socruithe na haithrise fuaime."
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
#define XEMU_RENDERER_LABEL_GA "API Grafaice (Atosaigh)"
#define XEMU_RENDERER_INFO_0_GA "An t-inneall rindreála a úsáidtear chun an GPU insamhlaithe a tharraingt. Is é Vulkan an rogha réamhshocraithe; úsáidtear OpenGL mar rogha chúltaca i gcás tiománaithe nach n-oibríonn i gceart le Vulkan. Tiocfaidh an t-athrú i bhfeidhm tar éis RetroArch a atosú. Úsáideann Android Vulkan i gcónaí, agus úsáideann macOS OpenGL i gcónaí."
#define OPTION_VAL_VULKAN_GA NULL
#define OPTION_VAL_OPENGL_GA NULL
#define XEMU_ASPECT_RATIO_LABEL_GA "Cóimheas Gnéithe"
#define XEMU_ASPECT_RATIO_INFO_0_GA "An cruth ina dtaispeántar an íomhá. Leanann an socrú 'Auto' an cluiche: 16:9 nuair a aistrítear an consól go dtí an fhairsingscáileán (ní mór an fhairsingscáileán a bheith curtha ar siúl i socruithe físe an deais), agus 4:3 murach sin. Roghnaigh 16:9 do chluiche a rindreáiltear i bhfairsingscáileán ach a thaispeántar i riocht comhbhrúite."
#define OPTION_VAL_AUTO_GA "Uathoibríoch"
#define OPTION_VAL_4_3_GA NULL
#define OPTION_VAL_16_9_GA NULL
#define XEMU_SURFACE_SCALE_LABEL_GA "Scála Réitigh Inmheánaigh"
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
#define XEMU_AVPACK_LABEL_GA "Pacáiste AV"
#define XEMU_AVPACK_INFO_0_GA "Roghnaigh an cineál pacáiste AV. Bíonn tionchar aige ar na modhanna físe atá ar fáil."
#define OPTION_VAL_HDTV_GA NULL
#define OPTION_VAL_COMPOSITE_GA "Ilchodach"
#define OPTION_VAL_SVIDEO_GA "S-Físeán"
#define OPTION_VAL_SCART_GA NULL
#define OPTION_VAL_VGA_GA NULL
#define XEMU_USE_DSP_LABEL_GA "Aithris APU DSP"
#define XEMU_USE_DSP_INFO_0_GA "Cumasaigh aithris DSP chun cruinneas fuaime a fheabhsú. D’fhéadfadh tionchar a bheith aige ar an bhfeidhmíocht."
#define XEMU_CACHE_SHADERS_LABEL_GA "Taisce Scáthaitheora"
#define XEMU_CACHE_SHADERS_INFO_0_GA "Stóráil scáthóirí GPU tiomsaithe ar an diosca. Laghdaíonn sé seo an mhoill nó an preabadh (stutter) le linn rithanna ina dhiaidh sin."
#define XEMU_VK_REDUCED_BUFFERS_LABEL_GA "Maoláin Vulkan Laghdaithe (Atosaigh)"
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_GA "Cuireann an t-inneall rindreála Vulkan a chuid maolán oibre in áirithe nuair a thosaíonn sé, de réir riachtanais an chluiche. Má bhíonn an ghné seo cumasaithe, coimeádtar an maolán do shonraí ingearán (vertex data) ag an deichiú cuid de mhéid xemu; sábhálann sé sin thart ar 1.2 GB de chuimhne físe agus an méid céanna de chuimhne an chórais. Má bhíonn an ghné díchumasaithe, cuirtear méid iomlán xemu in áirithe ar chártaí grafaicí a bhfuil 4 GB nó níos mó acu; bain triail as sin má ritheann cluiche níos moille agus an ghné seo cumasaithe."
#define XEMU_AUDIO_VOLUME_LABEL_GA "Teorainn Airde Fuaime (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_GA "Cuir teorainn le leibhéal toirte aschuir fuaime an Xbox go neamhspleách ar phríomh-toirt RetroArch."
#define OPTION_VAL_100_GA NULL
#define OPTION_VAL_80_GA NULL
#define OPTION_VAL_60_GA NULL
#define OPTION_VAL_40_GA NULL
#define OPTION_VAL_20_GA NULL
#define OPTION_VAL_0_GA "Balbhaithe"
#define XEMU_DISPLAY_FILTERING_LABEL_GA "Scagadh Taispeána"
#define XEMU_DISPLAY_FILTERING_INFO_0_GA "Modh scagtha uigeachta don aschur taispeána."
#define OPTION_VAL_LINEAR_GA "Délíneach"
#define OPTION_VAL_NEAREST_GA "Comharsa is Gaire"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_GA,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_GA,
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

#define CATEGORY_SYSTEM_LABEL_GL "Sistema"
#define CATEGORY_SYSTEM_INFO_0_GL NULL
#define CATEGORY_VIDEO_LABEL_GL "Vídeo"
#define CATEGORY_VIDEO_INFO_0_GL NULL
#define CATEGORY_AUDIO_LABEL_GL "Son"
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
#define XEMU_ASPECT_RATIO_LABEL_GL "Relación de aspecto"
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
#define OPTION_VAL_COMPOSITE_GL "Composto"
#define OPTION_VAL_SVIDEO_GL NULL
#define OPTION_VAL_SCART_GL NULL
#define OPTION_VAL_VGA_GL NULL
#define XEMU_USE_DSP_LABEL_GL NULL
#define XEMU_USE_DSP_INFO_0_GL NULL
#define XEMU_CACHE_SHADERS_LABEL_GL NULL
#define XEMU_CACHE_SHADERS_INFO_0_GL NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_GL NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_GL NULL
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
#define OPTION_VAL_NEAREST_GL "Veciño máis próximo"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_GL,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_GL,
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
#define CATEGORY_VIDEO_LABEL_HE "וידאו"
#define CATEGORY_VIDEO_INFO_0_HE NULL
#define CATEGORY_AUDIO_LABEL_HE "שמע"
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
#define XEMU_ASPECT_RATIO_LABEL_HE "יחס גובה-רוחב"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_HE NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_HE NULL
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_HE,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_HE,
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

/* RETRO_LANGUAGE_HR */

#define CATEGORY_SYSTEM_LABEL_HR "Sustav"
#define CATEGORY_SYSTEM_INFO_0_HR NULL
#define CATEGORY_VIDEO_LABEL_HR NULL
#define CATEGORY_VIDEO_INFO_0_HR NULL
#define CATEGORY_AUDIO_LABEL_HR "Zvuk"
#define CATEGORY_AUDIO_INFO_0_HR NULL
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
#define XEMU_RENDERER_LABEL_HR NULL
#define XEMU_RENDERER_INFO_0_HR NULL
#define OPTION_VAL_VULKAN_HR NULL
#define OPTION_VAL_OPENGL_HR NULL
#define XEMU_ASPECT_RATIO_LABEL_HR "Omjer slike"
#define XEMU_ASPECT_RATIO_INFO_0_HR NULL
#define OPTION_VAL_AUTO_HR NULL
#define OPTION_VAL_4_3_HR NULL
#define OPTION_VAL_16_9_HR NULL
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
#define XEMU_USE_DSP_LABEL_HR NULL
#define XEMU_USE_DSP_INFO_0_HR NULL
#define XEMU_CACHE_SHADERS_LABEL_HR NULL
#define XEMU_CACHE_SHADERS_INFO_0_HR NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_HR NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_HR NULL
#define XEMU_AUDIO_VOLUME_LABEL_HR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_HR NULL
#define OPTION_VAL_100_HR NULL
#define OPTION_VAL_80_HR NULL
#define OPTION_VAL_60_HR NULL
#define OPTION_VAL_40_HR NULL
#define OPTION_VAL_20_HR NULL
#define OPTION_VAL_0_HR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_HR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_HR NULL
#define OPTION_VAL_LINEAR_HR NULL
#define OPTION_VAL_NEAREST_HR NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_hr[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_HR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_HR,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_HR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_HR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_HR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_HR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_HR },
            { "nearest", OPTION_VAL_NEAREST_HR },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_hr = {
   option_cats_hr,
   option_defs_hr
};

/* RETRO_LANGUAGE_HU */

#define CATEGORY_SYSTEM_LABEL_HU "Rendszer"
#define CATEGORY_SYSTEM_INFO_0_HU NULL
#define CATEGORY_VIDEO_LABEL_HU "Kép"
#define CATEGORY_VIDEO_INFO_0_HU NULL
#define CATEGORY_AUDIO_LABEL_HU "Hang"
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
#define XEMU_ASPECT_RATIO_LABEL_HU "Képarány"
#define XEMU_ASPECT_RATIO_INFO_0_HU NULL
#define OPTION_VAL_AUTO_HU "Automatikus"
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
#define OPTION_VAL_COMPOSITE_HU "Kompozit"
#define OPTION_VAL_SVIDEO_HU NULL
#define OPTION_VAL_SCART_HU NULL
#define OPTION_VAL_VGA_HU NULL
#define XEMU_USE_DSP_LABEL_HU NULL
#define XEMU_USE_DSP_INFO_0_HU NULL
#define XEMU_CACHE_SHADERS_LABEL_HU NULL
#define XEMU_CACHE_SHADERS_INFO_0_HU NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_HU NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_HU NULL
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
#define OPTION_VAL_LINEAR_HU "Bilineáris"
#define OPTION_VAL_NEAREST_HU "Legközelebbi szomszéd"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_HU,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_HU,
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

#define CATEGORY_SYSTEM_LABEL_ID "Sistem"
#define CATEGORY_SYSTEM_INFO_0_ID NULL
#define CATEGORY_VIDEO_LABEL_ID NULL
#define CATEGORY_VIDEO_INFO_0_ID NULL
#define CATEGORY_AUDIO_LABEL_ID "Suara"
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
#define XEMU_ASPECT_RATIO_LABEL_ID "Rasio Aspek"
#define XEMU_ASPECT_RATIO_INFO_0_ID NULL
#define OPTION_VAL_AUTO_ID "Otomatis"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_ID NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_ID NULL
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_ID,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_ID,
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

#define CATEGORY_SYSTEM_LABEL_IT "Sistema"
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
#define XEMU_ASPECT_RATIO_LABEL_IT "Rapporto d'aspetto"
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
#define OPTION_VAL_COMPOSITE_IT "Composito"
#define OPTION_VAL_SVIDEO_IT NULL
#define OPTION_VAL_SCART_IT NULL
#define OPTION_VAL_VGA_IT NULL
#define XEMU_USE_DSP_LABEL_IT NULL
#define XEMU_USE_DSP_INFO_0_IT NULL
#define XEMU_CACHE_SHADERS_LABEL_IT NULL
#define XEMU_CACHE_SHADERS_INFO_0_IT NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_IT NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_IT NULL
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
#define OPTION_VAL_LINEAR_IT "Bilineare"
#define OPTION_VAL_NEAREST_IT "Vicino più prossimo"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_IT,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_IT,
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

#define CATEGORY_SYSTEM_LABEL_JA "システム"
#define CATEGORY_SYSTEM_INFO_0_JA NULL
#define CATEGORY_VIDEO_LABEL_JA "ビデオ"
#define CATEGORY_VIDEO_INFO_0_JA NULL
#define CATEGORY_AUDIO_LABEL_JA "オーディオ"
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
#define XEMU_ASPECT_RATIO_LABEL_JA "アスペクト比"
#define XEMU_ASPECT_RATIO_INFO_0_JA NULL
#define OPTION_VAL_AUTO_JA "自動"
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
#define OPTION_VAL_COMPOSITE_JA "コンポジット"
#define OPTION_VAL_SVIDEO_JA "S端子"
#define OPTION_VAL_SCART_JA NULL
#define OPTION_VAL_VGA_JA NULL
#define XEMU_USE_DSP_LABEL_JA NULL
#define XEMU_USE_DSP_INFO_0_JA NULL
#define XEMU_CACHE_SHADERS_LABEL_JA NULL
#define XEMU_CACHE_SHADERS_INFO_0_JA NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_JA NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_JA NULL
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
#define OPTION_VAL_LINEAR_JA "バイリニア"
#define OPTION_VAL_NEAREST_JA "ニアレストネイバー"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_JA,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_JA,
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

#define CATEGORY_SYSTEM_LABEL_KO "시스템"
#define CATEGORY_SYSTEM_INFO_0_KO NULL
#define CATEGORY_VIDEO_LABEL_KO "비디오"
#define CATEGORY_VIDEO_INFO_0_KO NULL
#define CATEGORY_AUDIO_LABEL_KO "오디오"
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
#define XEMU_ASPECT_RATIO_LABEL_KO "화면비"
#define XEMU_ASPECT_RATIO_INFO_0_KO NULL
#define OPTION_VAL_AUTO_KO "자동"
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
#define OPTION_VAL_COMPOSITE_KO "컴포지트"
#define OPTION_VAL_SVIDEO_KO "S-비디오"
#define OPTION_VAL_SCART_KO NULL
#define OPTION_VAL_VGA_KO NULL
#define XEMU_USE_DSP_LABEL_KO NULL
#define XEMU_USE_DSP_INFO_0_KO NULL
#define XEMU_CACHE_SHADERS_LABEL_KO NULL
#define XEMU_CACHE_SHADERS_INFO_0_KO NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_KO NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_KO NULL
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
#define OPTION_VAL_LINEAR_KO "이중선형보간"
#define OPTION_VAL_NEAREST_KO "최근접 이웃"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_KO,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_KO,
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

#define CATEGORY_SYSTEM_LABEL_NL "Systeem"
#define CATEGORY_SYSTEM_INFO_0_NL NULL
#define CATEGORY_VIDEO_LABEL_NL NULL
#define CATEGORY_VIDEO_INFO_0_NL NULL
#define CATEGORY_AUDIO_LABEL_NL "Geluid"
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
#define XEMU_ASPECT_RATIO_LABEL_NL "Beeldverhouding"
#define XEMU_ASPECT_RATIO_INFO_0_NL NULL
#define OPTION_VAL_AUTO_NL "Automatisch"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_NL NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_NL NULL
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
#define OPTION_VAL_LINEAR_NL "Bilineair"
#define OPTION_VAL_NEAREST_NL "Naaste-buur"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_NL,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_NL,
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
#define CATEGORY_AUDIO_LABEL_NO "Lyd"
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
#define XEMU_ASPECT_RATIO_LABEL_NO "Størrelsesforhold"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_NO NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_NO NULL
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
#define OPTION_VAL_LINEAR_NO "Bilineær"
#define OPTION_VAL_NEAREST_NO "Nærmeste nabo"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_NO,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_NO,
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

/* RETRO_LANGUAGE_OR */

#define CATEGORY_SYSTEM_LABEL_OR NULL
#define CATEGORY_SYSTEM_INFO_0_OR NULL
#define CATEGORY_VIDEO_LABEL_OR "ଵିଡ଼ିଓ"
#define CATEGORY_VIDEO_INFO_0_OR NULL
#define CATEGORY_AUDIO_LABEL_OR "ଅଡ଼ିଓ"
#define CATEGORY_AUDIO_INFO_0_OR NULL
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
#define XEMU_RENDERER_LABEL_OR NULL
#define XEMU_RENDERER_INFO_0_OR NULL
#define OPTION_VAL_VULKAN_OR NULL
#define OPTION_VAL_OPENGL_OR NULL
#define XEMU_ASPECT_RATIO_LABEL_OR NULL
#define XEMU_ASPECT_RATIO_INFO_0_OR NULL
#define OPTION_VAL_AUTO_OR NULL
#define OPTION_VAL_4_3_OR NULL
#define OPTION_VAL_16_9_OR NULL
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
#define XEMU_USE_DSP_LABEL_OR NULL
#define XEMU_USE_DSP_INFO_0_OR NULL
#define XEMU_CACHE_SHADERS_LABEL_OR NULL
#define XEMU_CACHE_SHADERS_INFO_0_OR NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_OR NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_OR NULL
#define XEMU_AUDIO_VOLUME_LABEL_OR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_OR NULL
#define OPTION_VAL_100_OR NULL
#define OPTION_VAL_80_OR NULL
#define OPTION_VAL_60_OR NULL
#define OPTION_VAL_40_OR NULL
#define OPTION_VAL_20_OR NULL
#define OPTION_VAL_0_OR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_OR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_OR NULL
#define OPTION_VAL_LINEAR_OR NULL
#define OPTION_VAL_NEAREST_OR NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_or[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_OR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_OR,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_OR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_OR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_OR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_OR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_OR },
            { "nearest", OPTION_VAL_NEAREST_OR },
            { NULL, NULL },
        },
        "linear"
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
#define XEMU_ASPECT_RATIO_LABEL_PL "Współczynnik proporcji"
#define XEMU_ASPECT_RATIO_INFO_0_PL NULL
#define OPTION_VAL_AUTO_PL "Automatyczny"
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
#define OPTION_VAL_COMPOSITE_PL "Kompozytowy"
#define OPTION_VAL_SVIDEO_PL NULL
#define OPTION_VAL_SCART_PL NULL
#define OPTION_VAL_VGA_PL NULL
#define XEMU_USE_DSP_LABEL_PL NULL
#define XEMU_USE_DSP_INFO_0_PL NULL
#define XEMU_CACHE_SHADERS_LABEL_PL NULL
#define XEMU_CACHE_SHADERS_INFO_0_PL NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_PL NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_PL NULL
#define XEMU_AUDIO_VOLUME_LABEL_PL NULL
#define XEMU_AUDIO_VOLUME_INFO_0_PL NULL
#define OPTION_VAL_100_PL NULL
#define OPTION_VAL_80_PL "80 %"
#define OPTION_VAL_60_PL "60 %"
#define OPTION_VAL_40_PL NULL
#define OPTION_VAL_20_PL NULL
#define OPTION_VAL_0_PL NULL
#define XEMU_DISPLAY_FILTERING_LABEL_PL NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_PL NULL
#define OPTION_VAL_LINEAR_PL "Dwuliniowy"
#define OPTION_VAL_NEAREST_PL "Najbliższy sąsiad"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_PL,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_PL,
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

#define CATEGORY_SYSTEM_LABEL_PT_BR "Sistema"
#define CATEGORY_SYSTEM_INFO_0_PT_BR NULL
#define CATEGORY_VIDEO_LABEL_PT_BR "Vídeo"
#define CATEGORY_VIDEO_INFO_0_PT_BR NULL
#define CATEGORY_AUDIO_LABEL_PT_BR "Áudio"
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
#define XEMU_ASPECT_RATIO_LABEL_PT_BR "Proporção de tela"
#define XEMU_ASPECT_RATIO_INFO_0_PT_BR NULL
#define OPTION_VAL_AUTO_PT_BR "Automático"
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
#define OPTION_VAL_COMPOSITE_PT_BR "Composto"
#define OPTION_VAL_SVIDEO_PT_BR NULL
#define OPTION_VAL_SCART_PT_BR NULL
#define OPTION_VAL_VGA_PT_BR NULL
#define XEMU_USE_DSP_LABEL_PT_BR NULL
#define XEMU_USE_DSP_INFO_0_PT_BR NULL
#define XEMU_CACHE_SHADERS_LABEL_PT_BR NULL
#define XEMU_CACHE_SHADERS_INFO_0_PT_BR NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_PT_BR NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_PT_BR NULL
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_PT_BR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_PT_BR,
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
#define CATEGORY_VIDEO_LABEL_PT_PT "Vídeo"
#define CATEGORY_VIDEO_INFO_0_PT_PT NULL
#define CATEGORY_AUDIO_LABEL_PT_PT "Áudio"
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
#define XEMU_ASPECT_RATIO_LABEL_PT_PT "Proporção do ecrã"
#define XEMU_ASPECT_RATIO_INFO_0_PT_PT NULL
#define OPTION_VAL_AUTO_PT_PT "Automático"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_PT_PT NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_PT_PT NULL
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
#define OPTION_VAL_NEAREST_PT_PT "Vizinho mais próximo"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_PT_PT,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_PT_PT,
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

#define CATEGORY_SYSTEM_LABEL_RU "Система"
#define CATEGORY_SYSTEM_INFO_0_RU NULL
#define CATEGORY_VIDEO_LABEL_RU "Видео"
#define CATEGORY_VIDEO_INFO_0_RU NULL
#define CATEGORY_AUDIO_LABEL_RU "Аудио"
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
#define XEMU_ASPECT_RATIO_LABEL_RU "Соотношение сторон"
#define XEMU_ASPECT_RATIO_INFO_0_RU NULL
#define OPTION_VAL_AUTO_RU "Автоматически"
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
#define OPTION_VAL_COMPOSITE_RU "Композитный"
#define OPTION_VAL_SVIDEO_RU NULL
#define OPTION_VAL_SCART_RU NULL
#define OPTION_VAL_VGA_RU NULL
#define XEMU_USE_DSP_LABEL_RU NULL
#define XEMU_USE_DSP_INFO_0_RU NULL
#define XEMU_CACHE_SHADERS_LABEL_RU NULL
#define XEMU_CACHE_SHADERS_INFO_0_RU NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_RU NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_RU NULL
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
#define OPTION_VAL_LINEAR_RU "Билинейный"
#define OPTION_VAL_NEAREST_RU "Метод ближайшего соседа"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_RU,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_RU,
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

#define CATEGORY_SYSTEM_LABEL_SK "Systém"
#define CATEGORY_SYSTEM_INFO_0_SK "Nastavenia na úrovni systému, ako cesty k BIOSu, pamäť a voľby zavádzania."
#define CATEGORY_VIDEO_LABEL_SK NULL
#define CATEGORY_VIDEO_INFO_0_SK "Nastavenia vykresľovania videa."
#define CATEGORY_AUDIO_LABEL_SK "Zvuk"
#define CATEGORY_AUDIO_INFO_0_SK "Nastavenia emulácie zvuku."
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
#define XEMU_RENDERER_LABEL_SK "Grafické API (reštart)"
#define XEMU_RENDERER_INFO_0_SK "Renderer, ktorým sa kreslí emulované GPU. Vulkan je predvolený; OpenGL je záloha pre ovládače, kde Vulkan nefunguje správne. Prejaví sa po reštarte RetroArchu. Android vždy používa Vulkan, macOS vždy OpenGL."
#define OPTION_VAL_VULKAN_SK NULL
#define OPTION_VAL_OPENGL_SK NULL
#define XEMU_ASPECT_RATIO_LABEL_SK "Pomer strán"
#define XEMU_ASPECT_RATIO_INFO_0_SK "Tvar, v akom sa obraz zobrazuje. Auto sleduje hru: 16:9, keď prepne konzolu na širokouhlý režim (v nastaveniach videa dashboardu musí byť zapnuté Widescreen), inak 4:3. Zvoľte 16:9 pre hru, ktorá kreslí širokouhlo, ale zobrazuje sa stlačená."
#define OPTION_VAL_AUTO_SK NULL
#define OPTION_VAL_4_3_SK NULL
#define OPTION_VAL_16_9_SK NULL
#define XEMU_SURFACE_SCALE_LABEL_SK "Mierka interného rozlíšenia"
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
#define XEMU_AVPACK_LABEL_SK NULL
#define XEMU_AVPACK_INFO_0_SK "Vyberte typ AV Packu. Ovplyvňuje dostupné režimy videa."
#define OPTION_VAL_HDTV_SK NULL
#define OPTION_VAL_COMPOSITE_SK "Kompozit"
#define OPTION_VAL_SVIDEO_SK NULL
#define OPTION_VAL_SCART_SK NULL
#define OPTION_VAL_VGA_SK NULL
#define XEMU_USE_DSP_LABEL_SK "Emulácia DSP v APU"
#define XEMU_USE_DSP_INFO_0_SK "Zapne emuláciu DSP pre presnejší zvuk. Môže ovplyvniť výkon."
#define XEMU_CACHE_SHADERS_LABEL_SK "Vyrovnávacia pamäť shaderov"
#define XEMU_CACHE_SHADERS_INFO_0_SK "Ukladá skompilované shadery GPU na disk. Znižuje trhanie pri ďalších spusteniach."
#define XEMU_VK_REDUCED_BUFFERS_LABEL_SK "Zmenšené zásobníky Vulkanu (reštart)"
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_SK "Renderer Vulkan si pri štarte rezervuje pracovné zásobníky bez ohľadu na to, čo hra potrebuje. Zapnuté drží zásobník pre inline dáta vrcholov na desatine veľkosti, akú má xemu, čo zaberie asi o 1,2 GB menej video pamäte a rovnako menej systémovej pamäte. Vypnuté rezervuje plnú veľkosť xemu na grafických kartách so 4 GB alebo viac; skúste to, ak je hra so zapnutou voľbou pomalšia."
#define XEMU_AUDIO_VOLUME_LABEL_SK "Limit hlasitosti zvuku (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_SK "Obmedzí hlasitosť zvukového výstupu Xboxu nezávisle od hlavnej hlasitosti RetroArchu."
#define OPTION_VAL_100_SK NULL
#define OPTION_VAL_80_SK NULL
#define OPTION_VAL_60_SK NULL
#define OPTION_VAL_40_SK NULL
#define OPTION_VAL_20_SK NULL
#define OPTION_VAL_0_SK "Stlmené"
#define XEMU_DISPLAY_FILTERING_LABEL_SK "Filtrovanie zobrazenia"
#define XEMU_DISPLAY_FILTERING_INFO_0_SK "Režim filtrovania textúr pre výstup zobrazenia."
#define OPTION_VAL_LINEAR_SK "Bilineárna"
#define OPTION_VAL_NEAREST_SK "Najbližší sused"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_SK,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_SK,
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

/* RETRO_LANGUAGE_SR */

#define CATEGORY_SYSTEM_LABEL_SR NULL
#define CATEGORY_SYSTEM_INFO_0_SR NULL
#define CATEGORY_VIDEO_LABEL_SR NULL
#define CATEGORY_VIDEO_INFO_0_SR NULL
#define CATEGORY_AUDIO_LABEL_SR "Zvuk"
#define CATEGORY_AUDIO_INFO_0_SR NULL
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
#define XEMU_RENDERER_LABEL_SR NULL
#define XEMU_RENDERER_INFO_0_SR NULL
#define OPTION_VAL_VULKAN_SR NULL
#define OPTION_VAL_OPENGL_SR NULL
#define XEMU_ASPECT_RATIO_LABEL_SR "Odnos ekrana"
#define XEMU_ASPECT_RATIO_INFO_0_SR NULL
#define OPTION_VAL_AUTO_SR NULL
#define OPTION_VAL_4_3_SR NULL
#define OPTION_VAL_16_9_SR NULL
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
#define XEMU_USE_DSP_LABEL_SR NULL
#define XEMU_USE_DSP_INFO_0_SR NULL
#define XEMU_CACHE_SHADERS_LABEL_SR NULL
#define XEMU_CACHE_SHADERS_INFO_0_SR NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_SR NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_SR NULL
#define XEMU_AUDIO_VOLUME_LABEL_SR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_SR NULL
#define OPTION_VAL_100_SR NULL
#define OPTION_VAL_80_SR NULL
#define OPTION_VAL_60_SR NULL
#define OPTION_VAL_40_SR NULL
#define OPTION_VAL_20_SR NULL
#define OPTION_VAL_0_SR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_SR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_SR NULL
#define OPTION_VAL_LINEAR_SR "Bilinearno"
#define OPTION_VAL_NEAREST_SR "Najbliži sused"

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_sr[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_SR,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_SR,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_SR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_SR,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_SR,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_SR,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_SR },
            { "nearest", OPTION_VAL_NEAREST_SR },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_sr = {
   option_cats_sr,
   option_defs_sr
};

/* RETRO_LANGUAGE_SV */

#define CATEGORY_SYSTEM_LABEL_SV NULL
#define CATEGORY_SYSTEM_INFO_0_SV "Konfigurera systeminställningar som BIOS-sökvägar, minne och startalternativ."
#define CATEGORY_VIDEO_LABEL_SV NULL
#define CATEGORY_VIDEO_INFO_0_SV "Konfigurera inställningar för videorendering."
#define CATEGORY_AUDIO_LABEL_SV "Ljud"
#define CATEGORY_AUDIO_INFO_0_SV "Konfigurera inställningar för ljudemulering."
#define XEMU_MEMORY_LABEL_SV "Systemminne (MB)"
#define XEMU_MEMORY_INFO_0_SV "Mängd system-RAM. 64 MB är standard; 128 MB används av utvecklingskit."
#define OPTION_VAL_64_SV NULL
#define OPTION_VAL_128_SV NULL
#define XEMU_NETWORK_BACKEND_LABEL_SV "Nätverkslösning"
#define XEMU_NETWORK_BACKEND_INFO_0_SV "Aktivera nätverksstöd för Xbox-spel med funktioner för LAN/System Link. NAT-lösningen ger grundläggande anslutning."
#define OPTION_VAL_NAT_SV NULL
#define XEMU_SKIP_BOOT_ANIM_LABEL_SV "Hoppa över startanimering"
#define XEMU_SKIP_BOOT_ANIM_INFO_0_SV "Hoppa över Xbox startanimering."
#define XEMU_HARD_FPU_LABEL_SV "Maskinvaruemulering av FPU"
#define XEMU_HARD_FPU_INFO_0_SV "Använd värddatorns FPU för x87-emulering. Det går snabbare men kan ge mindre avvikelser."
#define XEMU_RENDERER_LABEL_SV "Grafik-API (starta om)"
#define XEMU_RENDERER_INFO_0_SV "Den renderare som används för den emulerade GPU:n. Vulkan är standard; OpenGL används när Vulkan inte fungerar korrekt med grafikdrivrutinen. Ändringen börjar gälla när RetroArch har startats om. Android använder alltid Vulkan och macOS alltid OpenGL."
#define OPTION_VAL_VULKAN_SV NULL
#define OPTION_VAL_OPENGL_SV NULL
#define XEMU_ASPECT_RATIO_LABEL_SV "Bildformat"
#define XEMU_ASPECT_RATIO_INFO_0_SV "Det format bilden visas i. Auto följer spelet: 16:9 när spelet växlar konsolen till bredbildsläge (bredbild måste vara aktiverat i instrumentpanelens videoinställningar), annars 4:3. Välj 16:9 för ett spel som renderas i bredbild men visas ihoptryckt."
#define OPTION_VAL_AUTO_SV NULL
#define OPTION_VAL_4_3_SV NULL
#define OPTION_VAL_16_9_SV NULL
#define XEMU_SURFACE_SCALE_LABEL_SV "Intern upplösningsskala"
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
#define XEMU_AVPACK_LABEL_SV "AV-paket"
#define XEMU_AVPACK_INFO_0_SV "Välj AV-paketets typ. Påverkar tillgängliga videolägen."
#define OPTION_VAL_HDTV_SV NULL
#define OPTION_VAL_COMPOSITE_SV "Komposit"
#define OPTION_VAL_SVIDEO_SV NULL
#define OPTION_VAL_SCART_SV NULL
#define OPTION_VAL_VGA_SV NULL
#define XEMU_USE_DSP_LABEL_SV "Emulering av APU-DSP"
#define XEMU_USE_DSP_INFO_0_SV "Aktivera DSP-emulering för bättre ljudnoggrannhet. Kan påverka prestandan."
#define XEMU_CACHE_SHADERS_LABEL_SV "Shadercache"
#define XEMU_CACHE_SHADERS_INFO_0_SV "Mellanlagra kompilerade GPU-shadrar på disken. Minskar ryckighet vid senare körningar."
#define XEMU_VK_REDUCED_BUFFERS_LABEL_SV "Reducerade Vulkanbuffertar (Omstart)"
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_SV "Vulkanrenderaren reserverar sina arbetsbuffertar när den startar, oavsett vad spelet behöver. När detta är aktiverat hålls bufferten för inbäddade vertexdata på en tiondel av xemus storlek, vilket använder omkring 1,2 GB mindre grafikminne och lika mycket mindre systemminne. När detta är inaktiverat reserveras xemus fulla storlek på grafikkort med 4 GB eller mer. Prova detta om ett spel går långsammare när alternativet är aktiverat."
#define XEMU_AUDIO_VOLUME_LABEL_SV "Ljudvolymgräns (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_SV "Begränsa Xbox ljudutgångsvolym oberoende av RetroArchs huvudvolym."
#define OPTION_VAL_100_SV NULL
#define OPTION_VAL_80_SV NULL
#define OPTION_VAL_60_SV NULL
#define OPTION_VAL_40_SV NULL
#define OPTION_VAL_20_SV NULL
#define OPTION_VAL_0_SV "Avstängd"
#define XEMU_DISPLAY_FILTERING_LABEL_SV "Bildskärmsfiltrering"
#define XEMU_DISPLAY_FILTERING_INFO_0_SV "Läge för texturfiltrering av bildskärmsutdata."
#define OPTION_VAL_LINEAR_SV "Bilinjär"
#define OPTION_VAL_NEAREST_SV "Närmsta granne"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_SV,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_SV,
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

/* RETRO_LANGUAGE_TH */

#define CATEGORY_SYSTEM_LABEL_TH "ระบบ"
#define CATEGORY_SYSTEM_INFO_0_TH NULL
#define CATEGORY_VIDEO_LABEL_TH "วิดีโอ"
#define CATEGORY_VIDEO_INFO_0_TH NULL
#define CATEGORY_AUDIO_LABEL_TH "เสียง"
#define CATEGORY_AUDIO_INFO_0_TH NULL
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
#define XEMU_RENDERER_LABEL_TH NULL
#define XEMU_RENDERER_INFO_0_TH NULL
#define OPTION_VAL_VULKAN_TH NULL
#define OPTION_VAL_OPENGL_TH NULL
#define XEMU_ASPECT_RATIO_LABEL_TH "อัตราส่วนภาพ"
#define XEMU_ASPECT_RATIO_INFO_0_TH NULL
#define OPTION_VAL_AUTO_TH "อัตโนมัติ"
#define OPTION_VAL_4_3_TH NULL
#define OPTION_VAL_16_9_TH NULL
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
#define XEMU_USE_DSP_LABEL_TH NULL
#define XEMU_USE_DSP_INFO_0_TH NULL
#define XEMU_CACHE_SHADERS_LABEL_TH NULL
#define XEMU_CACHE_SHADERS_INFO_0_TH NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_TH NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_TH NULL
#define XEMU_AUDIO_VOLUME_LABEL_TH NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TH NULL
#define OPTION_VAL_100_TH NULL
#define OPTION_VAL_80_TH NULL
#define OPTION_VAL_60_TH NULL
#define OPTION_VAL_40_TH NULL
#define OPTION_VAL_20_TH NULL
#define OPTION_VAL_0_TH NULL
#define XEMU_DISPLAY_FILTERING_LABEL_TH NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_TH NULL
#define OPTION_VAL_LINEAR_TH NULL
#define OPTION_VAL_NEAREST_TH "เนียร์เรสต์ เนเบอร์"

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_th[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_TH,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_TH,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_TH,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_TH,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_TH,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_TH,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_TH },
            { "nearest", OPTION_VAL_NEAREST_TH },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_th = {
   option_cats_th,
   option_defs_th
};

/* RETRO_LANGUAGE_TR */

#define CATEGORY_SYSTEM_LABEL_TR "Sistem"
#define CATEGORY_SYSTEM_INFO_0_TR NULL
#define CATEGORY_VIDEO_LABEL_TR NULL
#define CATEGORY_VIDEO_INFO_0_TR NULL
#define CATEGORY_AUDIO_LABEL_TR "Ses"
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
#define XEMU_ASPECT_RATIO_LABEL_TR "En Boy Oranı"
#define XEMU_ASPECT_RATIO_INFO_0_TR NULL
#define OPTION_VAL_AUTO_TR "Otomatik"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_TR NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_TR NULL
#define XEMU_AUDIO_VOLUME_LABEL_TR NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TR NULL
#define OPTION_VAL_100_TR "%100"
#define OPTION_VAL_80_TR "%80"
#define OPTION_VAL_60_TR "%60"
#define OPTION_VAL_40_TR "%40"
#define OPTION_VAL_20_TR "%20"
#define OPTION_VAL_0_TR NULL
#define XEMU_DISPLAY_FILTERING_LABEL_TR NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_TR NULL
#define OPTION_VAL_LINEAR_TR "İkili Doğrusal"
#define OPTION_VAL_NEAREST_TR "En Yakın İlişki"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_TR,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_TR,
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

/* RETRO_LANGUAGE_TT */

#define CATEGORY_SYSTEM_LABEL_TT NULL
#define CATEGORY_SYSTEM_INFO_0_TT NULL
#define CATEGORY_VIDEO_LABEL_TT "Видео"
#define CATEGORY_VIDEO_INFO_0_TT NULL
#define CATEGORY_AUDIO_LABEL_TT "Аудио"
#define CATEGORY_AUDIO_INFO_0_TT NULL
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
#define XEMU_RENDERER_LABEL_TT NULL
#define XEMU_RENDERER_INFO_0_TT NULL
#define OPTION_VAL_VULKAN_TT NULL
#define OPTION_VAL_OPENGL_TT NULL
#define XEMU_ASPECT_RATIO_LABEL_TT NULL
#define XEMU_ASPECT_RATIO_INFO_0_TT NULL
#define OPTION_VAL_AUTO_TT NULL
#define OPTION_VAL_4_3_TT NULL
#define OPTION_VAL_16_9_TT NULL
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
#define XEMU_USE_DSP_LABEL_TT NULL
#define XEMU_USE_DSP_INFO_0_TT NULL
#define XEMU_CACHE_SHADERS_LABEL_TT NULL
#define XEMU_CACHE_SHADERS_INFO_0_TT NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_TT NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_TT NULL
#define XEMU_AUDIO_VOLUME_LABEL_TT NULL
#define XEMU_AUDIO_VOLUME_INFO_0_TT NULL
#define OPTION_VAL_100_TT NULL
#define OPTION_VAL_80_TT NULL
#define OPTION_VAL_60_TT NULL
#define OPTION_VAL_40_TT NULL
#define OPTION_VAL_20_TT NULL
#define OPTION_VAL_0_TT NULL
#define XEMU_DISPLAY_FILTERING_LABEL_TT NULL
#define XEMU_DISPLAY_FILTERING_INFO_0_TT NULL
#define OPTION_VAL_LINEAR_TT NULL
#define OPTION_VAL_NEAREST_TT NULL

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
    { NULL, NULL, NULL },
};
struct retro_core_option_v2_definition option_defs_tt[] = {
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
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
        "disabled"
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
    {
        "xemu_cache_shaders",
        XEMU_CACHE_SHADERS_LABEL_TT,
        NULL,
        XEMU_CACHE_SHADERS_INFO_0_TT,
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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_TT,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_TT,
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
    {
        "xemu_display_filtering",
        XEMU_DISPLAY_FILTERING_LABEL_TT,
        NULL,
        XEMU_DISPLAY_FILTERING_INFO_0_TT,
        NULL,
        "video",
        {
            { "linear",  OPTION_VAL_LINEAR_TT },
            { "nearest", OPTION_VAL_NEAREST_TT },
            { NULL, NULL },
        },
        "linear"
    },
    { NULL, NULL, NULL, NULL, NULL, NULL, { { NULL, NULL } }, NULL },
};
struct retro_core_options_v2 options_tt = {
   option_cats_tt,
   option_defs_tt
};

/* RETRO_LANGUAGE_UK */

#define CATEGORY_SYSTEM_LABEL_UK "Система"
#define CATEGORY_SYSTEM_INFO_0_UK NULL
#define CATEGORY_VIDEO_LABEL_UK "Відео"
#define CATEGORY_VIDEO_INFO_0_UK NULL
#define CATEGORY_AUDIO_LABEL_UK "Звук"
#define CATEGORY_AUDIO_INFO_0_UK NULL
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
#define XEMU_RENDERER_LABEL_UK NULL
#define XEMU_RENDERER_INFO_0_UK NULL
#define OPTION_VAL_VULKAN_UK NULL
#define OPTION_VAL_OPENGL_UK NULL
#define XEMU_ASPECT_RATIO_LABEL_UK "Співвідношення сторін"
#define XEMU_ASPECT_RATIO_INFO_0_UK NULL
#define OPTION_VAL_AUTO_UK "Автоматично"
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
#define OPTION_VAL_COMPOSITE_UK "Композитний"
#define OPTION_VAL_SVIDEO_UK NULL
#define OPTION_VAL_SCART_UK NULL
#define OPTION_VAL_VGA_UK NULL
#define XEMU_USE_DSP_LABEL_UK NULL
#define XEMU_USE_DSP_INFO_0_UK NULL
#define XEMU_CACHE_SHADERS_LABEL_UK NULL
#define XEMU_CACHE_SHADERS_INFO_0_UK NULL
#define XEMU_VK_REDUCED_BUFFERS_LABEL_UK NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_UK NULL
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
#define OPTION_VAL_LINEAR_UK "Білінійна"
#define OPTION_VAL_NEAREST_UK "Найближчий сусід"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_UK,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_UK,
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

#define CATEGORY_SYSTEM_LABEL_VAL "Sistema"
#define CATEGORY_SYSTEM_INFO_0_VAL NULL
#define CATEGORY_VIDEO_LABEL_VAL "Vídeo"
#define CATEGORY_VIDEO_INFO_0_VAL NULL
#define CATEGORY_AUDIO_LABEL_VAL "Àudio"
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
#define XEMU_ASPECT_RATIO_LABEL_VAL "Relació d'aspecte"
#define XEMU_ASPECT_RATIO_INFO_0_VAL NULL
#define OPTION_VAL_AUTO_VAL "Selecció automàtica"
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
#define XEMU_VK_REDUCED_BUFFERS_LABEL_VAL NULL
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_VAL NULL
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
#define OPTION_VAL_LINEAR_VAL "Bilineal"
#define OPTION_VAL_NEAREST_VAL "Veí més proper"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_VAL,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_VAL,
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

#define CATEGORY_SYSTEM_LABEL_VN "Hệ thống"
#define CATEGORY_SYSTEM_INFO_0_VN "Cấu hình các thiết lập cấp hệ thống như đường dẫn BIOS, bộ nhớ và tùy chọn khởi động."
#define CATEGORY_VIDEO_LABEL_VN NULL
#define CATEGORY_VIDEO_INFO_0_VN "Cấu hình các thiết lập kết xuất hình ảnh."
#define CATEGORY_AUDIO_LABEL_VN "Âm thanh"
#define CATEGORY_AUDIO_INFO_0_VN "Cấu hình các thiết lập mô phỏng âm thanh."
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
#define XEMU_RENDERER_LABEL_VN "Giao diện lập trình đồ họa (cần khởi động lại)"
#define XEMU_RENDERER_INFO_0_VN "Bộ kết xuất được dùng để vẽ hình ảnh từ bộ xử lý đồ họa mô phỏng. Vulkan là lựa chọn mặc định; OpenGL là phương án thay thế cho các trình điều khiển gặp lỗi với Vulkan. Thiết lập có hiệu lực sau khi khởi động lại RetroArch. Trên Android luôn sử dụng Vulkan, trên macOS luôn sử dụng OpenGL."
#define OPTION_VAL_VULKAN_VN NULL
#define OPTION_VAL_OPENGL_VN NULL
#define XEMU_ASPECT_RATIO_LABEL_VN "Tỷ lệ khung hình"
#define XEMU_ASPECT_RATIO_INFO_0_VN "Tỷ lệ khung hình hiển thị của hình ảnh. Tự động sẽ làm theo trò chơi: 16:9 khi trò chơi chuyển máy chơi game sang chế độ màn hình rộng (phải bật Màn hình rộng trong phần cài đặt video của bảng điều khiển), nếu không thì dùng 4:3. Chọn 16:9 nếu trò chơi kết xuất hình ảnh màn hình rộng nhưng hình hiển thị bị ép hẹp."
#define OPTION_VAL_AUTO_VN "Tự động"
#define OPTION_VAL_4_3_VN NULL
#define OPTION_VAL_16_9_VN NULL
#define XEMU_SURFACE_SCALE_LABEL_VN "Tỷ lệ độ phân giải kết xuất nội bộ"
#define XEMU_SURFACE_SCALE_INFO_0_VN "Điều chỉnh độ phân giải kết xuất nội bộ. Giá trị cao hơn cải thiện chất lượng hình ảnh nhưng làm giảm hiệu năng."
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
#define XEMU_AVPACK_LABEL_VN "Bộ kết nối âm thanh và hình ảnh"
#define XEMU_AVPACK_INFO_0_VN "Chọn loại bộ kết nối âm thanh và hình ảnh. Ảnh hưởng đến các chế độ video khả dụng."
#define OPTION_VAL_HDTV_VN NULL
#define OPTION_VAL_COMPOSITE_VN "Kết hợp"
#define OPTION_VAL_SVIDEO_VN NULL
#define OPTION_VAL_SCART_VN NULL
#define OPTION_VAL_VGA_VN NULL
#define XEMU_USE_DSP_LABEL_VN "Mô phỏng bộ xử lý tín hiệu số của APU"
#define XEMU_USE_DSP_INFO_0_VN "Bật mô phỏng bộ xử lý tín hiệu số để tăng độ chính xác của âm thanh. Có thể ảnh hưởng đến hiệu năng."
#define XEMU_CACHE_SHADERS_LABEL_VN "Bộ nhớ đệm bộ đổ bóng"
#define XEMU_CACHE_SHADERS_INFO_0_VN "Lưu bộ đổ bóng đã biên dịch của bộ xử lý đồ họa vào ổ đĩa. Giảm hiện tượng giật hình trong những lần chạy tiếp theo."
#define XEMU_VK_REDUCED_BUFFERS_LABEL_VN "Giảm bộ đệm Vulkan (cần khởi động lại)"
#define XEMU_VK_REDUCED_BUFFERS_INFO_0_VN "Bộ kết xuất hình ảnh Vulkan cấp phát sẵn các bộ đệm xử lý khi khởi động, bất kể trò chơi cần bao nhiêu. Khi bật, bộ đệm chứa dữ liệu đỉnh nội tuyến chỉ còn một phần mười kích thước của xemu, giúp giảm khoảng 1,2 GB bộ nhớ đồ họa và giảm lượng bộ nhớ hệ thống tương ứng. Khi tắt, hệ thống cấp phát bộ đệm theo đầy đủ kích thước của xemu trên các card đồ họa có từ 4 GB bộ nhớ trở lên; hãy thử tắt tùy chọn này nếu trò chơi chạy chậm hơn khi bật."
#define XEMU_AUDIO_VOLUME_LABEL_VN "Giới hạn âm lượng (%)"
#define XEMU_AUDIO_VOLUME_INFO_0_VN "Giới hạn âm lượng đầu ra của Xbox độc lập với âm lượng tổng của RetroArch."
#define OPTION_VAL_100_VN NULL
#define OPTION_VAL_80_VN NULL
#define OPTION_VAL_60_VN NULL
#define OPTION_VAL_40_VN NULL
#define OPTION_VAL_20_VN NULL
#define OPTION_VAL_0_VN "Đã tắt tiếng"
#define XEMU_DISPLAY_FILTERING_LABEL_VN "Bộ lọc hiển thị"
#define XEMU_DISPLAY_FILTERING_INFO_0_VN "Chế độ lọc kết cấu cho hình ảnh đầu ra."
#define OPTION_VAL_LINEAR_VN "Song tuyến tính"
#define OPTION_VAL_NEAREST_VN "Điểm ảnh gần nhất"

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
        "xemu_vk_reduced_buffers",
        XEMU_VK_REDUCED_BUFFERS_LABEL_VN,
        NULL,
        XEMU_VK_REDUCED_BUFFERS_INFO_0_VN,
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