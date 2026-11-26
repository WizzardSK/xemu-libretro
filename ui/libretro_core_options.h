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
        "The machine itself: memory, network, boot and language. Taken when the content starts (Trim HDD on Close when it closes)."
    },
    {
        "video",
        "Video",
        "Configure video rendering settings."
    },
    {
        "debug",
        "Debug",
        "The profiler and switches for finding what slows a game down or breaks it: the CPU and GPU fast paths and the renderer's details. Best left as they are otherwise."
    },
    {
        "audio",
        "Audio",
        "Configure audio emulation settings."
    },
    {
        "controls",
        "Controls",
        "Rumble and the sticks' dead zone, per player."
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
        "Amount of the Xbox's system RAM. 64 MB is standard; 128 MB is used by debug kits. A Sega Chihiro always has 128 MB, whatever this says.",
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
    /* NOTE: File path options (bootrom, bios, hdd, eeprom) are not exposed
     * as core options because they require text input which core options
     * don't support (dropdown only). Paths are auto-detected from
     * RetroArch's system directory instead. */
    /* Auto by default rather than the standalone's EEPROM language: games
     * then speak RetroArch's language without a trip to the dashboard
     * (NNshi). */
    {
        "xemu_language",
        "System Language",
        NULL,
        "The language the console's settings give games, in place of the dashboard's setting. Auto is RetroArch's language when the Xbox has it, English otherwise.",
        NULL,
        "system",
        {
            { "auto",       "Auto" },
            { "english",    "English" },
            { "japanese",   "Japanese" },
            { "german",     "German" },
            { "french",     "French" },
            { "spanish",    "Spanish" },
            { "italian",    "Italian" },
            { "korean",     "Korean" },
            { "chinese",    "Chinese" },
            { "portuguese", "Portuguese" },
            { NULL, NULL },
        },
        "auto"
    },
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
        "The display shape the console's video settings report to games, in place of the dashboard's setting. At 16:9, games that support widescreen run in widescreen; at 4:3 they run in 4:3. Set it to the shape of your display. Letterbox is the dashboard's 4:3 with widescreen games letterboxed.",
        NULL,
        "video",
        {
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
        "The shape the picture is shown in. Best kept at Auto, which follows the game: 16:9 when the console is set to widescreen (System Aspect Ratio or the dashboard) and the game renders 16:9, or when a widescreen patch (Widescreen or 16-9 in its name) is on; 4:3 otherwise and on a Chihiro. 16:9 stretches a 4:3 game to widescreen.",
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
    /* Auto by default: standalone has no such option, and the listed games'
     * bars are not part of what they mean to show (NNshi) */
    {
        "xemu_overscan_crop",
        "Crop Vertical Overscan",
        NULL,
        "Some games draw a 448-line picture inside the Xbox's 480 lines, with black bars above and below. Auto crops 16 of every 480 lines at the top and at the bottom of the games on the core's list of such games and stretches the rest to the full height, keeping the aspect ratio.",
        NULL,
        "video",
        {
            { "off",  "Off" },
            { "auto", "Auto" },
            { NULL, NULL },
        },
        "auto"
    },
    {
        "xemu_surface_scale",
        "Internal Resolution Scale (Restart)",
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
    /* Off by default; a test option for now: which sizes help is for the
     * testers to find out (NNshi) */
    {
        "xemu_scale_threshold",
        "Upscaling Threshold",
        NULL,
        "With an Internal Resolution Scale above 1x, render targets whose larger side is at or below this size are drawn at 1x. Small buffers such as bloom, glow or reflection passes then match the original look instead of turning into sharp, blocky artifacts. Vulkan only. Changing it rebuilds the render targets.",
        NULL,
        "video",
        {
            { "0",   "OFF" },
            { "16",  "16" },
            { "32",  "32" },
            { "64",  "64" },
            { "96",  "96" },
            { "128", "128" },
            { "160", "160" },
            { "192", "192" },
            { "256", "256" },
            { "320", "320" },
            { "384", "384" },
            { "448", "448" },
            { "512", "512" },
            { "640", "640" },
            { "720", "720" },
            { NULL, NULL },
        },
        "0"
    },
    /* Auto by default: Nearest Neighbor is a test switch for finding
     * upscaling artifacts (NNshi) */
    {
        "xemu_texture_upscaling",
        "Texture Filtering",
        NULL,
        "How textures are filtered, at any Internal Resolution Scale. \"Auto\" uses the filter the game asks for. \"Nearest Neighbor\" reads every texture without filtering, magnified and minified (mipmaps stay), except the game's own render targets (bloom, blur, the 3D picture): a test switch to tell artifacts caused by bilinear sampling, such as at texture edges, from the rest. Vulkan only.",
        NULL,
        "video",
        {
            { "auto",    "Auto" },
            { "nearest", "Nearest Neighbor" },
            { NULL, NULL },
        },
        "auto"
    },
    /* Off by default: a test switch for upscaling artifacts (NNshi) */
    {
        "xemu_half_pixel_offset",
        "Half-Pixel Offset",
        NULL,
        "With an Internal Resolution Scale above 1x, vertices that lie exactly on a half pixel - where games put screen-aligned quads for UI, post-processing and render-target copies, following Direct3D's half-pixel offset - are moved the way Subpixel Offset Scaling moves the whole picture, so their edges and texture reads line up as at 1x. \"X and Y\": vertices with both coordinates on a half pixel. \"2D Only\": those that are also where the game put them, without a 3D transform (pre-transformed screen-space quads). \"Per Triangle\": a triangle (or line, or quad) whose vertices all have both coordinates on a half pixel is moved as a whole. \"Per Triangle, Quads / Render Targets\": the same, only in draws of a single quad or draws that read an upscaled render target, not in batches of sprites from normal textures (HUDs). \"Native Edges, 2D\" moves nothing: a flat primitive (one depth, UI and 2D) covers exactly the 1x pixels whose centre it contains, as at 1x, while its content is drawn at the internal resolution. \"Per Triangle, Content Kept\": moved as \"Per Triangle\", but its texture, colours and fog stay where they were, so only its edges move. \"Per Axis, Content Kept\": the same, with each axis on its own: a primitive whose corners all have y on a half pixel moves in y, one whose corners all have x there moves in x. \"Per Axis, Flat, Content Kept\": the same for flat primitives only, all corners at one depth (2D, UI, full-screen passes), never 3D. \"Per Axis, Flat, Either Axis\": as \"Per Axis, Flat, Content Kept\", but a flat primitive whose corners all have one axis on a half pixel moves in both axes, as the whole picture would. \"Per Axis, Flat, Either Axis, Unrotated\": the same, but not for a primitive whose texture is mapped rotated (a rotating map). \"Per Axis, Flat, Rects\": as \"Per Axis, Flat, Content Kept\", but only triangles that are halves of axis-aligned rectangles (UI, bars, letterboxes, full-screen passes). \"Per Axis, Flat, Rects, Touched Axis\": the same, and an axis with all corners on a half pixel also moves the other axis when at least one corner is on a half pixel there. \"Per Axis, Flat, Touched Axis, Unrotated\": \"Per Axis, Flat, Content Kept\" with the touched axis, without the rectangle test, and a primitive that reads a texture mapped rotated (a rotating map) is never moved; untextured ones are not checked for rotation. \"Per Axis, Flat, Touched Axis, Unrotated 90\": the same, but a texture turned by a quarter counts as straight. \"..., Whole Pixels Stay\": the same, and the other axis moves only if none of its corners is on a whole pixel. \"..., Thin\": the same, and the other axis moves only for primitives at most 4 pixels across in it (bars, outlines), not for scrolling or growing ones. Other geometry stays where it is. Changing it compiles new shaders.",
        NULL,
        "video",
        {
            { "disabled", "OFF" },
            { "enabled",  "X and Y" },
            { "2d",       "2D Only" },
            { "triangle", "Per Triangle" },
            { "triangle_quads", "Per Triangle, Quads / Render Targets" },
            { "native2d", "Native Edges, 2D" },
            { "triangle_content", "Per Triangle, Content Kept" },
            { "axis_content", "Per Axis, Content Kept" },
            { "axis_flat", "Per Axis, Flat, Content Kept" },
            { "axis_either", "Per Axis, Flat, Either Axis" },
            { "axis_unrot", "Per Axis, Flat, Either Axis, Unrotated" },
            { "axis_rects", "Per Axis, Flat, Rects" },
            { "axis_touched", "Per Axis, Flat, Rects, Touched Axis" },
            { "axis_touched_unrot", "Per Axis, Flat, Touched Axis, Unrotated" },
            { "axis_touched_unrot90", "Per Axis, Flat, Touched Axis, Unrotated 90" },
            { "axis_touched_whole", "Per Axis, Flat, Touched Axis, Unrotated 90, Whole Pixels Stay" },
            { "axis_touched_thin", "Per Axis, Flat, Touched Axis, Unrotated 90, Whole Pixels Stay, Thin" },
            { NULL, NULL },
        },
        "disabled"
    },
    /* Off by default: a test switch for upscaling artifacts (NNshi) */
    {
        "xemu_clamp_textures",
        "Clamp Textures",
        NULL,
        "With an Internal Resolution Scale above 1x, textures drawn one texel per pixel without scaling or rotation - UI, menus, full-screen images - are read from the nearest texel inside the texture, so they look as at 1x: neighbouring images in a texture atlas and the opposite edge of a repeating texture no longer bleed into their borders. \"1:1 + Scaled 2D\" also takes scaled, unrotated draws whose vertices all lie at one depth (UI, text): they are read where the 1x pixel's centre is, so they look as at 1x. \"Low-Res\" leaves out textures with more than 1.5 texels per 1x pixel, such as pictures the game rendered at the upscaled resolution. \"1x Pixel Centres\": every unrotated draw without perspective, 1:1, scaled or shrunk, takes its texture coordinate at the centre of the 1x pixel, so a point-sampled one shows the texel 1x shows (text that sits half a 1x pixel off when upscaled). \"Ties by W\": as \"1x Pixel Centres\", but a 1x centre exactly on a texel edge takes the texel before it only in draws at w 1 and the texel after it otherwise. \"Game's Filter\": as \"1x Pixel Centres\", but a draw at one texel per 1x pixel is read through the game's own filter at the 1x pixel's centre, so a bilinear one blends two texels where 1x does. \"1x Pixel Centres, Game's Filter, Fine\": the same, with the 1x centre taken to 1/512 of a texel instead of 1/64, for draws that map slightly fewer texels than pixels (255 onto 256), whose last rows land just past a texel edge. The game's own render targets (bloom, blur, the 3D picture) are never clamped. Everything else is sampled as the game asks. Changing it compiles new shaders.",
        NULL,
        "video",
        {
            { "disabled", "OFF" },
            { "enabled",  "1:1" },
            { "scaled",   "1:1 + Scaled 2D" },
            { "lowres",   "1:1 + Scaled 2D, Low-Res" },
            { "centres",  "1x Pixel Centres" },
            { "centres_w", "1x Pixel Centres, Ties by W" },
            { "centres_f", "1x Pixel Centres, Game's Filter" },
            { "centres_ff", "1x Pixel Centres, Game's Filter, Fine" },
            { NULL, NULL },
        },
        "disabled"
    },
    /* NNshi, xemu-project/xemu#409: most games filter with no anisotropy */
    {
        "xemu_anisotropic_filtering",
        "Anisotropic Filtering",
        NULL,
        "The least anisotropic filtering the game's smoothly filtered textures get, which keeps textures at a slant sharp. Native leaves the game's own, which for most Xbox games is none.",
        NULL,
        "video",
        {
            { "1",  "Native" },
            { "2",  "2x" },
            { "4",  "4x" },
            { "8",  "8x" },
            { "16", "16x" },
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
    /* On by default: the sound keeps its pace while shaders compile, as
     * standalone's own SDL thread keeps it (NNshi, OutRun 2 from a cold
     * shader cache); fast-forward and slow motion do not change the game's
     * speed in the core either way, and on this thread they leave the sound
     * clean rather than garbled */
    {
        "xemu_audio_thread",
        "Audio Thread (Restart)",
        NULL,
        "Hands the sound to RetroArch's audio thread as the APU mixes it, as standalone plays it, instead of a frame's worth each frame: the sound keeps going while frames stall, as while shaders compile. RetroArch builds from before November 2026 slow their menu down with it when Menu Frame Rate (Frame Throttle) is Display Rate; there, set it to Content Rate.",
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
        "APU DSP Emulation",
        NULL,
        "Emulates the APU's DSP, which plays the games' effects, reverb and much of their music: without it the sound is flat. Takes effect right away.",
        NULL,
        "audio",
        {
            { "disabled", "Disabled" },
            { "enabled",  "Enabled" },
            { NULL, NULL },
        },
        "disabled"
    },
    /* APU DSP Emulation off by default for now, as standalone: with it on,
     * loading a savestate can leave the sound corrupted (NNshi). DSP JIT on,
     * unlike standalone, for when the DSP is turned on. Both switch while a
     * game runs (gp_ep.c follows g_config each frame). HRTF and the voice
     * processor's threads as standalone's (config_spec.yml: audio.hrtf,
     * audio.vp.num_workers) */
    {
        "xemu_dsp_jit",
        "DSP JIT",
        NULL,
        "Runs APU DSP Emulation's programs as compiled code instead of interpreting them: faster, as standalone's DSP JIT. Only does something with APU DSP Emulation on. Takes effect right away.",
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
        "xemu_mspf_overlay",
        "Profiler (F10)",
        NULL,
        "Shows three lines in the top left corner. FPS: the frames per second the game shows, as in standalone xemu's video debug overlay, over its last 60 frames. GPU: the frame rate the game could reach from the time it takes to draw a frame (standalone's MSPF), averaged over its last 60 frames and updated every 20 frames; valid only when the GPU is what limits the game. NV2A IDLE: the share of time since the profiler was turned on that the GPU thread waited for the game to send work; high while the frame rate is below the game's target means the CPU is what limits it. F10 on the keyboard turns the profiler on or off, and each time it comes on NV2A IDLE starts over. With one of the Profiler options below on, turning the profiler off writes a file to system/xemu/<commit> <game>.txt (the same run again overwrites it): the core's version, the game, the settings that matter for speed and the run's average FPS, GPU and NV2A IDLE, then what those options add. With none of them on, there is only the overlay and no file. While on, the core also writes to RetroArch's log every 300 runs how the guest's frames and the frontend's runs lined up. Takes effect right away.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_prof_vcpu",
        "Profiler: vCPU",
        NULL,
        "Windows: with the profiler on, the core samples where the CPU emulation spends its time (this slows it slightly), and when it goes off writes the shares to RetroArch's log and every sample to the profile file. Read when the profiler comes on.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_prof_pfifo",
        "Profiler: PFIFO/PGRAPH",
        NULL,
        "Windows: with the profiler on, the GPU thread (the pushbuffer and the renderer) is sampled beside the CPU emulation, and the profile file gets its section after the CPU's: where it spends its time and what it waits for. Read when the profiler comes on.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_prof_counters",
        "Profiler: Renderer Counters",
        NULL,
        "The profile file ends with the renderer's counters per second over the run: draws, pipeline and shader binds, texture uploads, surface downloads, syncs with the host GPU and why.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_prof_s2t",
        "Profiler: Missed Render Targets",
        NULL,
        "Vulkan: the profile file lists the textures that sit on memory the game renders into but are not taken from that render target (they go through RAM instead, which is slow), each case once with its count and the texture's and the render target's address, format, size and pitch.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_prof_surf",
        "Profiler: Surface Downloads and Uploads",
        NULL,
        "Vulkan: the profile file lists the render targets read back into RAM and written back to the GPU, by the part of the renderer that asked for it, with each render target's address, size and format. Also the render targets evicted, with why and the target that replaced them.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_prof_pacing",
        "Profiler: Frame Pacing",
        NULL,
        "With the profiler on, the core records the time of every frame the game flips and of every frame it hands to RetroArch, with how many new game frames each showed, when its run began and how long it waited for the game and the renderer. The profile file gets the intervals' histograms, the longest ones, and every frame. Read when the profiler comes on.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_cpu_boost",
        "CPU Boost (Restart)",
        NULL,
        "Faster paths for the guest CPU and the audio processor: native SSE and a wider jump cache. Turn it off if a game misbehaves. Taken when the content starts.",
        NULL,
        "debug",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    {
        "xemu_hard_fpu",
        "Hardware FPU Emulation (Restart)",
        NULL,
        "Use host FPU for x87 emulation. Faster but may have minor inaccuracies. Taken when the content starts.",
        NULL,
        "debug",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* Auto by default: All, as standalone, but None on AMD, where they draw
     * garbage (NNshi); fewer for a GPU that crashes on one of them (Akrido) */
    {
        "xemu_vk_fast_paths",
        "Vulkan Fast Paths (Restart)",
        NULL,
        "Currently only confirmed to work on Nvidia graphics cards, broken on AMD. Affects shader compilation speed on Vulkan. \"All\" is the fastest but can crash some games. \"Auto\" is None on AMD graphics cards and All on others.",
        NULL,
        "debug",
        {
            { "auto",     "Auto" },
            { "all",      "All" },
            { "no_gpl",   "No Pipeline Libraries" },
            { "no_dyn",   "No Dynamic States" },
            { "none",     "None" },
            { NULL, NULL },
        },
        "auto"
    },
    /* Own by default: the frontend holds its queue's lock while it presents,
     * and the renderer submits many times a frame */
    {
        "xemu_vk_renderer_queue",
        "Vulkan: Renderer Queue (Restart)",
        NULL,
        "Where the renderer submits its GPU work when the GPU has a second queue in RetroArch's queue family. \"Own\" uses that second queue, so the renderer doesn't wait while RetroArch presents. \"RetroArch's\" shares RetroArch's queue, for tools that capture a frame (RenderDoc) and may not handle two queues. Taken when the content starts.",
        NULL,
        "debug",
        {
            { "own",      "Own" },
            { "frontend", "RetroArch's" },
            { NULL, NULL },
        },
        "own"
    },
    /* Off by default: a diagnostic, it slows rendering a little (NNshi) */
    {
        "xemu_vk_lost_report",
        "Vulkan: Device Lost Report (Restart)",
        NULL,
        "When the GPU is lost (VK_ERROR_DEVICE_LOST), writes system/xemu/xemu_device_lost.txt: the call that failed, the last submits, and the work the GPU was doing when it was lost. The renderer marks every draw, clear, upload, conversion and render pass in GPU memory for it (AMD buffer markers, Nvidia checkpoints), and adds the driver's fault description where it has one. Slows rendering a little. Taken when the content starts.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    /* Off by default: it helps some games and breaks others (NNshi) */
    {
        "xemu_subpixel_offset",
        "Subpixel Offset Scaling",
        NULL,
        "With an Internal Resolution Scale above 1x, moves the picture by a fraction of a pixel so the pixels of the higher resolution line up with the original ones. Fixes ghosting and seams in some games (Jade Empire, Blinx) and breaks others (Splinter Cell). Off is as before.",
        NULL,
        "debug",
        {
            { "off", "OFF" },
            { "on", "ON" },
            { NULL, NULL },
        },
        "off"
    },
    /* Off by default: faster in some games, micro-stutters in others
     * (NNshi) */
    {
        "xemu_tlb_skip_idle",
        "Skip Idle TLB Modes",
        NULL,
        "When the emulator resets the dirty state of guest memory in the CPU's address cache (the TLB), it looks only at the address-translation modes the Xbox actually uses (one or two of 22). Makes some games faster (Crimson Skies, Virtua Cop 3) and makes others micro-stutter (Burnout 3, Ollie King, Otogi, Ninja Gaiden Black, Conker). Takes effect right away.",
        NULL,
        "debug",
        {
            { "disabled", NULL },
            { "enabled",  NULL },
            { NULL, NULL },
        },
        "disabled"
    },
    {
        "xemu_rumble_p1",
        "Rumble (Player 1)",
        NULL,
        "Player 1's pad rumbles, from the Xbox games and from a Chihiro racing game's force feedback. Off, none of either.",
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
        "Rumble (Player 2)",
        NULL,
        "Player 2's pad rumbles, from the Xbox games and from a Chihiro racing game's force feedback. Off, none of either.",
        NULL,
        "controls",
        {
            { "enabled",  "Enabled" },
            { "disabled", "Disabled" },
            { NULL, NULL },
        },
        "enabled"
    },
    /* 0% by default (NNshi); a Chihiro driving game that stops at a drive
     * board error during its test needs it raised (README) */
    {
        "xemu_deadzone_p1",
        "Analog Dead Zone (Player 1)",
        NULL,
        "How far player 1's sticks can be pushed before the game sees it, both sticks, on the Xbox and the Chihiro alike; the rest of the travel is scaled up to full.",
        NULL,
        "controls",
        {
            { "0",  "0%" },
            { "5",  "5%" },
            { "10", "10%" },
            { "15", "15%" },
            { "20", "20%" },
            { "25", "25%" },
            { "30", "30%" },
            { NULL, NULL },
        },
        "0"
    },
    /* 0% by default (NNshi); a Chihiro driving game that stops at a drive
     * board error during its test needs it raised (README) */
    {
        "xemu_deadzone_p2",
        "Analog Dead Zone (Player 2)",
        NULL,
        "How far player 2's sticks can be pushed before the game sees it, both sticks, on the Xbox and the Chihiro alike; the rest of the travel is scaled up to full.",
        NULL,
        "controls",
        {
            { "0",  "0%" },
            { "5",  "5%" },
            { "10", "10%" },
            { "15", "15%" },
            { "20", "20%" },
            { "25", "25%" },
            { "30", "30%" },
            { NULL, NULL },
        },
        "0"
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
    /* 100% is the speed the stick had up and down; across it now moves as
     * fast, where it crossed the whole width in the same time (NNshi) */
    {
        "xemu_chihiro_stick_sensitivity",
        "Stick Aim Sensitivity",
        NULL,
        "How fast the stick moves the aim with Light Gun Aim on Analog Stick, as fast across as up and down; at 100% a full tilt crosses the picture's height in about a second. The mouse aims where it points.",
        NULL,
        "chihiro",
        {
            { "50", "50%" },
            { "60", "60%" },
            { "70", "70%" },
            { "80", "80%" },
            { "90", "90%" },
            { "100", "100%" },
            { "110", "110%" },
            { "120", "120%" },
            { "130", "130%" },
            { "140", "140%" },
            { "150", "150%" },
            { "160", "160%" },
            { "170", "170%" },
            { "180", "180%" },
            { "190", "190%" },
            { "200", "200%" },
            { NULL, NULL },
        },
        "100"
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
    /* Not in standalone, which steers linearly: a stick's short travel
     * makes the racers twitchy (NNshi, as linuxloader-libretro has it);
     * logarithmic by default (NNshi) */
    {
        "xemu_chihiro_steering",
        "Steering Response",
        NULL,
        "How the left stick steers in OutRun 2, OutRun 2 SP, Maximum Tune 1 and 2, Crazy Taxi 3 and Ollie King. Linear: as the stick is pushed. Logarithmic: on a curve with less of the turn around the centre and steeper towards the ends, so a stick steers less twitchily; its shape is set by Steering Effect and Steering Inner Zone. The D-pad is not affected.",
        NULL,
        "chihiro",
        {
            { "linear", "Linear" },
            { "logarithmic", "Logarithmic" },
            { NULL, NULL },
        },
        "logarithmic"
    },
    {
        "xemu_chihiro_steering_effect",
        "Steering Effect",
        NULL,
        "With logarithmic Steering Response: how the rest of the turn rises towards full lock. Cubic is strong, Square weak.",
        NULL,
        "chihiro",
        {
            { "cubic", "Cubic (Strong)" },
            { "square", "Square (Weak)" },
            { NULL, NULL },
        },
        "cubic"
    },
    {
        "xemu_chihiro_steering_inner",
        "Steering Inner Zone",
        NULL,
        "With logarithmic Steering Response: the share of the turn that rises evenly from the centre. Lower is calmer around the centre.",
        NULL,
        "chihiro",
        {
            { "5", "5%" },
            { "10", "10%" },
            { "15", "15%" },
            { "20", "20%" },
            { "25", "25%" },
            { "30", "30%" },
            { "35", "35%" },
            { "40", "40%" },
            { "45", "45%" },
            { "50", "50%" },
            { NULL, NULL },
        },
        "25"
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
