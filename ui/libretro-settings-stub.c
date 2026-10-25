/*
 * Minimal xemu settings stub for libretro core build.
 * Provides g_config and stub functions without toml++/SDL dependencies.
 *
 * Copyright (c) 2025
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "xemu-config.h"
#include "xemu-settings.h"

struct config g_config;

static char settings_base_path[4096] = "";
static char settings_path[4096] = "";
static char settings_eeprom_path[4096] = "";

void libretro_settings_set_base_path(const char *path)
{
    if (path) {
        snprintf(settings_base_path, sizeof(settings_base_path), "%s", path);
    }
}

void xemu_settings_set_path(const char *path)
{
    if (path) {
        snprintf(settings_path, sizeof(settings_path), "%s", path);
    }
}

const char *xemu_settings_get_base_path(void)
{
    return settings_base_path;
}

const char *xemu_settings_get_path(void)
{
    return settings_path;
}

const char *xemu_settings_get_default_eeprom_path(void)
{
    return settings_eeprom_path;
}

const char *xemu_settings_get_error_message(void)
{
    return NULL;
}

bool xemu_settings_load(void)
{
    /* In libretro mode, config is populated directly from core options */
    return true;
}

void xemu_settings_save(void)
{
    /* No-op in libretro mode */
}

void add_net_nat_forward_ports(int host, int guest, CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL protocol)
{
    (void)host; (void)guest; (void)protocol;
}

void remove_net_nat_forward_ports(unsigned int index)
{
    (void)index;
}

bool xemu_settings_load_gamepad_mapping(const char *guid, GamepadMappings **mapping)
{
    (void)guid; (void)mapping;
    return false;
}

void xemu_settings_reset_controller_mapping(const char *guid)
{
    (void)guid;
}

void xemu_settings_reset_keyboard_mapping(void)
{
}

/* The machine and the image, as the Tovarichtch fork's ui/xemu-settings.cc
 * decides them: an Xbox disc (XISO, or a Redump image's game partition)
 * boots an Xbox, any other image a Chihiro. In the core the image is the
 * loaded content (sys.files.dvd_path). */
bool xemu_media_is_xbox_disc(const char *path)
{
    static const char magic[] = "MICROSOFT*XBOX*MEDIA";
    static const long partitions[] = { 0, 0x18300000 };
    if (!path || !path[0] || g_file_test(path, G_FILE_TEST_IS_DIR)) {
        return false;
    }
    FILE *f = fopen(path, "rb");
    if (!f) {
        return false;
    }
    bool disc = false;
    for (int i = 0; i < 2 && !disc; i++) {
        char buf[sizeof(magic) - 1];
        disc = fseek(f, partitions[i] + 0x10000, SEEK_SET) == 0 &&
               fread(buf, 1, sizeof(buf), f) == sizeof(buf) &&
               memcmp(buf, magic, sizeof(buf)) == 0;
    }
    fclose(f);
    return disc;
}

static int chihiro_mode_asked = -1;
static int chihiro_mode = -1;
static char *chihiro_image;

void xemu_chihiro_mode_ask(bool chihiro)
{
    chihiro_mode_asked = chihiro;
}

/* Decided again for each content: the core stays loaded between contents,
 * and the image a Chihiro booted (its game's region, its shader seeds) is
 * the new content's, not the last one's. Xbox and Chihiro are never mixed:
 * retro_load_game refuses the other machine's content. */
void libretro_chihiro_mode_reset(void)
{
    chihiro_mode_asked = -1;
    chihiro_mode = -1;
    g_free(chihiro_image);
    chihiro_image = NULL;
}

const char *xemu_chihiro_image(void)
{
    if (!chihiro_image) {
        const char *path = g_config.sys.files.dvd_path;
        chihiro_image = g_strdup(path ? path : "");
    }
    return chihiro_image;
}

bool xemu_chihiro_mode(void)
{
    if (chihiro_mode < 0) {
        const char *image = xemu_chihiro_image();
        if (chihiro_mode_asked >= 0) {
            chihiro_mode = chihiro_mode_asked;
        } else if (image && image[0]) {
            chihiro_mode = !xemu_media_is_xbox_disc(image);
        } else {
            chihiro_mode = g_config.sys.default_machine ==
                           CONFIG_SYS_DEFAULT_MACHINE_CHIHIRO;
        }
    }
    return chihiro_mode;
}

/* The fork's easter egg is set in xemu.toml, which the core has none of */
bool xemu_doge_mode(void)
{
    return false;
}

/* Debug mode: XEMU_DEBUG_MODE=1 or 0, else perf.debug_mode */
bool xemu_debug_mode(void)
{
    static int mode = -1;
    if (mode < 0) {
        const char *e = getenv("XEMU_DEBUG_MODE");
        mode = e && e[0] ? e[0] != '0' : g_config.perf.debug_mode;
    }
    return mode;
}
