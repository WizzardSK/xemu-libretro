/*
 * Chihiro cabinet controls from RetroArch's pads and light guns.
 *
 * The standalone reads the cabinet's inputs from the keyboard, mouse and
 * joysticks through its SDL UI (ui/xemu-input.c, not part of the core). Here
 * each retro_run reads ports 1 and 2 and sets the JVS I/O board's switches
 * and analog channels the same way, per game profile. What has to happen
 * with the big lock held (a coin, a card pushed in) is queued here and done
 * on the emulation thread, when the game next talks to the JVS board.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "qemu/osdep.h"
#include "qemu/atomic.h"
#include <math.h>

#include "hw/xbox/chihiro/chihiro-jvs.h"
#include "hw/xbox/chihiro/chihiro.h"
#include "hw/xbox/chihiro/chihiro-driveboard-v257.h"
#include "hw/xbox/chihiro/chihiro-driveboard-sega838.h"
#include "hw/xbox/chihiro/chihiro-cabinet.h"
#include "hw/xbox/chihiro/chihiro-cardreader-hw210.h"
#include "xemu-settings.h"
#include "libretro.h"
#include "libretro-crosshair.h"

extern retro_input_state_t input_state_cb;

void libretro_chihiro_update_input(void);
void libretro_chihiro_apply_pending(void);

/* Queued for the emulation thread: coins per player, Card In presses
 * (bit 0/1: HW210 slot of player 1/2, bit 2: the CRP-1231 reader) */
static int pending_coins[2];
static int pending_cards;

static bool pad(unsigned port, unsigned id)
{
    return input_state_cb(port, RETRO_DEVICE_JOYPAD, 0, id) != 0;
}

/* One axis of a stick, through its player's Analog Dead Zone
 * (libretro-stubs.c) */
static int16_t stick(unsigned port, unsigned index, unsigned id)
{
    extern void libretro_input_stick(unsigned port, unsigned index, int16_t *x, int16_t *y);
    int16_t x, y;
    libretro_input_stick(port, index, &x, &y);
    return id == RETRO_DEVICE_ID_ANALOG_X ? x : y;
}

/* A trigger's travel, 0..1; a pad without analog triggers gives all or none */
static float trigger(unsigned port, unsigned id)
{
    int16_t v = input_state_cb(port, RETRO_DEVICE_ANALOG,
                               RETRO_DEVICE_INDEX_ANALOG_BUTTON, id);
    if (v <= 0) {
        return pad(port, id) ? 1.0f : 0.0f;
    }
    return v / 32767.0f;
}

/* Sega Chihiro > Light Gun Aim: the left stick (or D-pad) aims in place of
 * the mouse or RetroArch's light gun, the mouse being the only way in
 * standalone (NNshi); and Sega Chihiro > Crosshair (ui/libretro.c sets
 * them) */
bool libretro_chihiro_aim_stick = true;
/* Chihiro > Stick Aim Sensitivity, and the picture's height over its width
 * (libretro.c, update_aspect), so the stick moves as fast across as up and
 * down (NNshi) */
float libretro_chihiro_aim_speed = 1.0f;
float libretro_chihiro_aim_across = 0.75f;
bool libretro_chihiro_crosshair = true;

XemuLibretroCrosshair xemu_libretro_crosshairs[2];

/* The light gun, unless the stick aims: then RetroArch's light gun, which
 * follows the mouse, must not move the aim or press anything */
static bool gun(unsigned port, unsigned id)
{
    return !libretro_chihiro_aim_stick &&
           input_state_cb(port, RETRO_DEVICE_LIGHTGUN, 0, id) != 0;
}

/* A mouse button, where the mouse aims (standalone's bindings: left the
 * trigger, right the gun's button; NNshi: middle the pedal) */
static bool mouse(unsigned port, unsigned id)
{
    return !libretro_chihiro_aim_stick &&
           input_state_cb(port, RETRO_DEVICE_MOUSE, 0, id) != 0;
}

static bool pressed(bool now, bool *before)
{
    bool edge = now && !*before;
    *before = now;
    return edge;
}

/* As standalone: a digital input ramps to full lock instead of jumping */
static uint16_t axis_smooth(uint16_t pos, bool neg, bool posv)
{
    uint16_t target = 0x8000;
    if (neg && !posv) target = 0x0000;
    else if (posv && !neg) target = 0xFFFF;
    int delta = (int)target - (int)pos;
    int step = 0x1000;
    if (delta > step) return pos + step;
    if (delta < -step) return pos - step;
    return target;
}

/* A left-stick axis, or the D-pad ramping, as a JVS channel */
static uint16_t steering(unsigned port, uint16_t *ramp, bool invert)
{
    int16_t x = stick(port, RETRO_DEVICE_INDEX_ANALOG_LEFT,
                      RETRO_DEVICE_ID_ANALOG_X);
    bool l = pad(port, RETRO_DEVICE_ID_JOYPAD_LEFT);
    bool r = pad(port, RETRO_DEVICE_ID_JOYPAD_RIGHT);

    if (invert) {
        bool t = l;
        l = r;
        r = t;
        x = x == INT16_MIN ? INT16_MAX : -x;
    }
    if (l || r) {
        *ramp = axis_smooth(*ramp, l, r);
        return *ramp;
    }
    *ramp = 0x8000;
    return (uint16_t)(0x8000 + x);
}

/* A gun player's aim into its analog pair (P1: 0/1, P2: 2/3). Off the
 * picture, or with Reload held, the SCREEN switch is up: how the games see
 * a reload. */
/* The stick's aim, 0..1 across the picture, kept from run to run */
static float stick_aim_pos[2][2] = { { 0.5f, 0.5f }, { 0.5f, 0.5f } };
/* Whether port 2's player has aimed or fired yet: until then its crosshair
 * stays hidden, so one player does not see a second one standing still */
static bool aim_used[2];

/* The left stick moves the aim, past a small dead zone, as fast as it is
 * pushed - squared, for fine aim near the centre - up and down the picture
 * in about a second at full tilt times Stick Aim Sensitivity, and across as
 * fast, less of its width (NNshi); the D-pad at half that speed */
static bool stick_aim(unsigned port)
{
    static const unsigned dpad[2][2] = {
        { RETRO_DEVICE_ID_JOYPAD_LEFT, RETRO_DEVICE_ID_JOYPAD_RIGHT },
        { RETRO_DEVICE_ID_JOYPAD_UP, RETRO_DEVICE_ID_JOYPAD_DOWN },
    };
    bool moved = false;

    for (int axis = 0; axis < 2; axis++) {
        float v = stick(port, RETRO_DEVICE_INDEX_ANALOG_LEFT,
                        axis ? RETRO_DEVICE_ID_ANALOG_Y : RETRO_DEVICE_ID_ANALOG_X) /
                  32767.0f;
        float a = fabsf(v);
        float step = 0.0f;
        if (a > 0.15f) {
            a = (a - 0.15f) / 0.85f;
            step = copysignf(a * a, v);
        } else if (pad(port, dpad[axis][0])) {
            step = -0.5f;
        } else if (pad(port, dpad[axis][1])) {
            step = 0.5f;
        }
        if (step != 0.0f) {
            float *p = &stick_aim_pos[port][axis];
            const float scale = libretro_chihiro_aim_speed *
                                (axis ? 1.0f : libretro_chihiro_aim_across);
            *p = MIN(MAX(*p + step * scale / 60.0f, 0.0f), 1.0f);
            moved = true;
        }
    }
    return moved;
}

static uint8_t gun_aim(ChihiroJVSState *jvs, unsigned port)
{
    /* off the screen: a light gun pointed away, its reload button, or with
     * the stick R (the games' optional manual reload) */
    bool off = gun(port, RETRO_DEVICE_ID_LIGHTGUN_IS_OFFSCREEN) ||
               gun(port, RETRO_DEVICE_ID_LIGHTGUN_RELOAD) ||
               (libretro_chihiro_aim_stick && pad(port, RETRO_DEVICE_ID_JOYPAD_R));
    float x, y;

    if (libretro_chihiro_aim_stick) {
        aim_used[port] |= stick_aim(port);
        x = stick_aim_pos[port][0];
        y = stick_aim_pos[port][1];
    } else {
        int16_t gx = input_state_cb(port, RETRO_DEVICE_LIGHTGUN, 0,
                                    RETRO_DEVICE_ID_LIGHTGUN_SCREEN_X);
        int16_t gy = input_state_cb(port, RETRO_DEVICE_LIGHTGUN, 0,
                                    RETRO_DEVICE_ID_LIGHTGUN_SCREEN_Y);
        x = (gx + 0x8000) / 65536.0f;
        y = (gy + 0x8000) / 65536.0f;
        /* RetroArch gives every port the one mouse's place: port 2 aims
         * only where it is somewhere else, else its crosshair covers port
         * 1's (NNshi saw only blue) */
        if (port == 0) {
            aim_used[0] = true;
        } else if (x != xemu_libretro_crosshairs[0].x ||
                   y != xemu_libretro_crosshairs[0].y) {
            aim_used[port] = true;
        }
    }
    aim_used[port] |= port == 0 || (libretro_chihiro_aim_stick && off);

    XemuLibretroCrosshair *c = &xemu_libretro_crosshairs[port];
    c->x = x;
    c->y = y;
    c->shown = !off && aim_used[port] && libretro_chihiro_crosshair;

    if (off) {
        jvs->analog[port * 2] = 0;
        jvs->analog[port * 2 + 1] = 0;
        return 0x01;
    }
    jvs->analog[port * 2] = (uint16_t)MIN(x * 65536.0f, 65535.0f);
    jvs->analog[port * 2 + 1] = (uint16_t)MIN(y * 65536.0f, 65535.0f);
    return 0;
}

/* Trigger, body button and the game's extra switch of one gun player, as
 * standalone binds them: the trigger, the gun's button (House of the Dead
 * III's pump reload, Virtua Cop 3's change weapon, Ghost Squad's action),
 * and Virtua Cop 3's pedal or Ghost Squad's fire rate. With the mouse the
 * left, right and middle buttons; with the stick R2, L2 and L. */
static void gun_player(ChihiroJVSState *jvs, unsigned port, int profile,
                       uint8_t *sw0, uint8_t *sw1)
{
    const bool stick = libretro_chihiro_aim_stick;
    *sw0 |= gun_aim(jvs, port);
    if (gun(port, RETRO_DEVICE_ID_LIGHTGUN_TRIGGER) ||
        mouse(port, RETRO_DEVICE_ID_MOUSE_LEFT) ||
        (stick && pad(port, RETRO_DEVICE_ID_JOYPAD_R2))) {
        *sw0 |= 0x02;
        aim_used[port] |= stick;
    }
    if (gun(port, RETRO_DEVICE_ID_LIGHTGUN_AUX_A) ||
        mouse(port, RETRO_DEVICE_ID_MOUSE_RIGHT) ||
        (stick && pad(port, RETRO_DEVICE_ID_JOYPAD_L2)))
        *sw1 |= 0x80;
    if (profile != CONFIG_CHIHIRO_JVS_PROFILE_HOTD3 &&
        (gun(port, RETRO_DEVICE_ID_LIGHTGUN_AUX_B) ||
         mouse(port, RETRO_DEVICE_ID_MOUSE_MIDDLE) ||
         (stick && pad(port, RETRO_DEVICE_ID_JOYPAD_L))))
        *sw1 |= 0x40;
}

/* Gundam's sticks: up, down, left, right, trigger, button */
static uint8_t gundam_stick(unsigned port, unsigned index, unsigned trig,
                            unsigned button, bool dpad)
{
    int16_t x = stick(port, index, RETRO_DEVICE_ID_ANALOG_X);
    int16_t y = stick(port, index, RETRO_DEVICE_ID_ANALOG_Y);
    uint8_t sw = 0;

    if (y < -0x4000 || (dpad && pad(port, RETRO_DEVICE_ID_JOYPAD_UP)))
        sw |= 0x20;
    if (y > 0x4000 || (dpad && pad(port, RETRO_DEVICE_ID_JOYPAD_DOWN)))
        sw |= 0x10;
    if (x < -0x4000 || (dpad && pad(port, RETRO_DEVICE_ID_JOYPAD_LEFT)))
        sw |= 0x08;
    if (x > 0x4000 || (dpad && pad(port, RETRO_DEVICE_ID_JOYPAD_RIGHT)))
        sw |= 0x04;
    if (pad(port, trig))
        sw |= 0x02;
    if (pad(port, button))
        sw |= 0x01;
    return sw;
}

/* Maximum Tune's H shifter, moved a gear at a time by R and L; the gate
 * positions are standalone's (wmmt_lever) */
static uint8_t wmmt_lever(void)
{
    static const uint8_t gate[7] = { 0x00, 0xA0, 0x60, 0x80, 0x40, 0x90, 0x50 };
    static int gear;
    static bool up_before, down_before;

    if (pressed(pad(0, RETRO_DEVICE_ID_JOYPAD_R), &up_before) && gear < 6)
        gear++;
    if (pressed(pad(0, RETRO_DEVICE_ID_JOYPAD_L), &down_before) && gear > 0)
        gear--;
    return gate[gear];
}

/* The drive board's force feedback as rumble on port 1, the pad that
 * steers, as standalone gives it to a gamepad (chihiro_ffb_update in
 * ui/xemu-input.c): the Sega board's events and vibration (OutRun 2), the
 * V257's push (Maximum Tune). A pad has nothing for the spring and the
 * damping. Off unless Sega Chihiro > Force Feedback Rumble is on (NNshi). */
static void ffb_rumble(void)
{
    extern void libretro_input_set_rumble(unsigned port, uint16_t strong, uint16_t weak);
    int str = g_config.chihiro.settings.ffb_strength;
    uint32_t raw = 0;

    if (!chihiro_driveboard_global) {
        return;
    }
    if (g_config.chihiro.settings.force_feedback && str > 0) {
        if (chihiro_v257_global &&
            chihiro_cabinet_drive_board() == CHIHIRO_DRIVE_V257) {
            int target, spring, damping, torque;
            v257_drive(chihiro_v257_global, &target, &spring, &damping, &torque);
            raw = (uint32_t)abs(torque) * 0xFFFF / 0x7F * (uint32_t)str / 100;
        } else {
            /* the Sega board plays its packages on as this is called, once
             * per frame as in standalone */
            DriveBoardFFB ffb;
            driveboard_get_ffb(chihiro_driveboard_global, &ffb);
            raw = (uint32_t)driveboard_get_rumble(chihiro_driveboard_global) *
                  (uint32_t)str / 100;
        }
    }
    uint16_t r = raw > 0xFFFF ? 0xFFFF : (uint16_t)raw;
    libretro_input_set_rumble(0, r, r);
}

/* RetroArch's controls list for the Chihiro game that runs: each button by
 * what it does in that game's cabinet, as libretro_chihiro_update_input()
 * below binds it, in place of the Xbox pad's names (NNshi). Names only:
 * nothing is bound differently, and RetroArch's remapping rebinds them. Sent
 * again when the game or Light Gun Aim changes. */
#define CHIHIRO_DESC_MAX 64
static struct retro_input_descriptor chihiro_descs[CHIHIRO_DESC_MAX];
static unsigned chihiro_desc_count;

static void chihiro_desc(unsigned port, unsigned device, unsigned index,
                         unsigned id, const char *name)
{
    if (chihiro_desc_count < CHIHIRO_DESC_MAX - 1) {
        chihiro_descs[chihiro_desc_count++] =
            (struct retro_input_descriptor){ port, device, index, id, name };
    }
}

static void chihiro_joy(unsigned port, unsigned id, const char *name)
{
    chihiro_desc(port, RETRO_DEVICE_JOYPAD, 0, id, name);
}

static void chihiro_axis(unsigned port, unsigned index, unsigned id,
                         const char *name)
{
    chihiro_desc(port, RETRO_DEVICE_ANALOG, index, id, name);
}

static void chihiro_publish_descriptors(int profile)
{
    extern void libretro_set_input_descriptors(const struct retro_input_descriptor *desc);
    static int last_profile = -2;
    static bool last_stick;
    const bool stick = libretro_chihiro_aim_stick;

    if (profile == last_profile && stick == last_stick) {
        return;
    }
    last_profile = profile;
    last_stick = stick;
    chihiro_desc_count = 0;

    switch (profile) {
    case CONFIG_CHIHIRO_JVS_PROFILE_HOTD3:
    case CONFIG_CHIHIRO_JVS_PROFILE_VC3:
    case CONFIG_CHIHIRO_JVS_PROFILE_GS:
        for (unsigned p = 0; p < 2; p++) {
            if (stick) {
                chihiro_axis(p, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_X, "Aim Left/Right");
                chihiro_axis(p, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_Y, "Aim Up/Down");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_UP, "Aim Up");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_DOWN, "Aim Down");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_LEFT, "Aim Left");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_RIGHT, "Aim Right");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_R2, "Trigger");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_R, "Reload");
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_L2,
                            profile == CONFIG_CHIHIRO_JVS_PROFILE_HOTD3 ? "Pump Reload" :
                            profile == CONFIG_CHIHIRO_JVS_PROFILE_VC3 ? "Change Weapon" : "Action");
                if (profile == CONFIG_CHIHIRO_JVS_PROFILE_VC3) {
                    chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_L, "Pedal");
                } else if (profile == CONFIG_CHIHIRO_JVS_PROFILE_GS) {
                    chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_L, "Fire Rate");
                }
            }
            if (profile == CONFIG_CHIHIRO_JVS_PROFILE_GS) {
                chihiro_joy(p, RETRO_DEVICE_ID_JOYPAD_X, "Insert Card");
            }
        }
        break;
    case CONFIG_CHIHIRO_JVS_PROFILE_CTX:
    case CONFIG_CHIHIRO_JVS_PROFILE_OR2:
    case CONFIG_CHIHIRO_JVS_PROFILE_WMMT2:
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_X, "Steering");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_LEFT, "Steer Left");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_RIGHT, "Steer Right");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R2, "Gas");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L2, "Brake");
        if (profile == CONFIG_CHIHIRO_JVS_PROFILE_CTX) {
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R, "Drive");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L, "Reverse");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_B, "Jump");
        } else if (profile == CONFIG_CHIHIRO_JVS_PROFILE_WMMT2) {
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R, "Shift Up");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L, "Shift Down");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_Y, "View Change");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_A, "Intrude Change");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_X, "Insert Card");
        } else {
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_Y, "View Change");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R, "Gear Up");
            chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L, "Gear Down");
        }
        break;
    case CONFIG_CHIHIRO_JVS_PROFILE_OK:
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_X, "Board Left/Right");
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_Y, "Board Front/Rear");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_LEFT, "Board Left");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_RIGHT, "Board Right");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_UP, "Board Front");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_DOWN, "Board Rear");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L, "Left Grab");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R, "Right Grab");
        break;
    case CONFIG_CHIHIRO_JVS_PROFILE_GUNDAM:
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_X, "Left Stick Left/Right");
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_LEFT, RETRO_DEVICE_ID_ANALOG_Y, "Left Stick Up/Down");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_UP, "Left Stick Up");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_DOWN, "Left Stick Down");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_LEFT, "Left Stick Left");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_RIGHT, "Left Stick Right");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L2, "Left Trigger");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L, "Left Button");
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_RIGHT, RETRO_DEVICE_ID_ANALOG_X, "Right Stick Left/Right");
        chihiro_axis(0, RETRO_DEVICE_INDEX_ANALOG_RIGHT, RETRO_DEVICE_ID_ANALOG_Y, "Right Stick Up/Down");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R2, "Right Trigger");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R, "Right Button");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_B, "Pedal");
        chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_X, "Insert Card");
        break;
    default:
        break;
    }
    chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_START, "Start");
    chihiro_joy(1, RETRO_DEVICE_ID_JOYPAD_START, "Start");
    chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_SELECT, "Coin");
    chihiro_joy(1, RETRO_DEVICE_ID_JOYPAD_SELECT, "Coin");
    chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_L3, "Service");
    chihiro_joy(0, RETRO_DEVICE_ID_JOYPAD_R3, "Test");
    chihiro_descs[chihiro_desc_count] = (struct retro_input_descriptor){ 0 };
    libretro_set_input_descriptors(chihiro_descs);
}

void libretro_chihiro_update_input(void)
{
    ChihiroJVSState *jvs = chihiro_jvs_global;
    uint8_t sw0 = 0, sw1 = 0, p2sw0 = 0, p2sw1 = 0;

    /* shown again by the gun games' aim, below */
    xemu_libretro_crosshairs[0].shown = false;
    xemu_libretro_crosshairs[1].shown = false;
    static uint16_t steer_ramp = 0x8000;
    static bool card_before[2], coin_before[2];
    int cards = 0;

    if (!jvs || !input_state_cb) {
        return;
    }

    int profile = chihiro_detected_game_profile();
    if (profile < 0) {
        profile = g_config.chihiro.jvs.profile;
    }
    chihiro_publish_descriptors(profile);
    bool card_in[2] = {
        pressed(pad(0, RETRO_DEVICE_ID_JOYPAD_X), &card_before[0]),
        pressed(pad(1, RETRO_DEVICE_ID_JOYPAD_X), &card_before[1]),
    };

    switch (profile) {
    case CONFIG_CHIHIRO_JVS_PROFILE_HOTD3:
    case CONFIG_CHIHIRO_JVS_PROFILE_VC3:
    case CONFIG_CHIHIRO_JVS_PROFILE_GS:
        gun_player(jvs, 0, profile, &sw0, &sw1);
        gun_player(jvs, 1, profile, &p2sw0, &p2sw1);
        if (profile == CONFIG_CHIHIRO_JVS_PROFILE_GS) {
            for (int p = 0; p < 2; p++) {
                if (card_in[p])
                    cards |= 1 << p;
            }
            if (chihiro_hw210_enabled && chihiro_card_reader_present(0))
                sw1 |= 0x20;
            if (chihiro_hw210_enabled && chihiro_card_reader_present(1))
                p2sw1 |= 0x20;
        }
        break;
    case CONFIG_CHIHIRO_JVS_PROFILE_CTX:
    case CONFIG_CHIHIRO_JVS_PROFILE_OR2:
    case CONFIG_CHIHIRO_JVS_PROFILE_WMMT2: {
        uint16_t steer = steering(0, &steer_ramp, false);

        jvs->analog[0] = steer;
        if (chihiro_v257_global)
            v257_set_wheel(chihiro_v257_global, steer >> 6);
        jvs->analog[1] =
            (uint16_t)(trigger(0, RETRO_DEVICE_ID_JOYPAD_R2) * 65535.0f);
        jvs->analog[2] =
            (uint16_t)(trigger(0, RETRO_DEVICE_ID_JOYPAD_L2) * 65535.0f);

        if (profile == CONFIG_CHIHIRO_JVS_PROFILE_CTX) {
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_R))
                sw0 |= 0x20; /* drive */
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_L))
                sw0 |= 0x10; /* reverse */
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_B))
                sw0 |= 0x02; /* jump */
        } else if (profile == CONFIG_CHIHIRO_JVS_PROFILE_WMMT2) {
            sw1 |= wmmt_lever();
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_Y))
                sw1 |= 0x02; /* view change */
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_A))
                sw1 |= 0x01; /* intrude change */
            if (card_in[0])
                cards |= 4;
        } else {
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_Y))
                sw0 |= 0x10; /* view change */
            /* OutRun 2's shifter is wired to player 2's up and down */
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_R))
                p2sw0 |= 0x20;
            if (pad(0, RETRO_DEVICE_ID_JOYPAD_L))
                p2sw0 |= 0x10;
        }
        break;
    }
    case CONFIG_CHIHIRO_JVS_PROFILE_OK: {
        /* The board reads left above centre and right below it */
        jvs->analog[1] = steering(0, &steer_ramp, true);
        if (pad(0, RETRO_DEVICE_ID_JOYPAD_UP) ||
            stick(0, RETRO_DEVICE_INDEX_ANALOG_LEFT,
                  RETRO_DEVICE_ID_ANALOG_Y) < -0x4000)
            sw0 |= 0x20; /* board front */
        if (pad(0, RETRO_DEVICE_ID_JOYPAD_DOWN) ||
            stick(0, RETRO_DEVICE_INDEX_ANALOG_LEFT,
                  RETRO_DEVICE_ID_ANALOG_Y) > 0x4000)
            sw0 |= 0x10; /* board rear */
        if (pad(0, RETRO_DEVICE_ID_JOYPAD_L))
            sw0 |= 0x02; /* left grab */
        if (pad(0, RETRO_DEVICE_ID_JOYPAD_R))
            sw0 |= 0x01; /* right grab */
        break;
    }
    case CONFIG_CHIHIRO_JVS_PROFILE_GUNDAM:
        sw0 |= gundam_stick(0, RETRO_DEVICE_INDEX_ANALOG_LEFT,
                            RETRO_DEVICE_ID_JOYPAD_L2,
                            RETRO_DEVICE_ID_JOYPAD_L, true);
        p2sw0 |= gundam_stick(0, RETRO_DEVICE_INDEX_ANALOG_RIGHT,
                              RETRO_DEVICE_ID_JOYPAD_R2,
                              RETRO_DEVICE_ID_JOYPAD_R, false);
        jvs->analog[1] = pad(0, RETRO_DEVICE_ID_JOYPAD_B) ? 0xFFFF : 0;
        if (card_in[0])
            cards |= 1;
        if (chihiro_hw210_enabled && chihiro_card_reader_present(0))
            sw1 |= 0x80;
        break;
    }

    if (pad(0, RETRO_DEVICE_ID_JOYPAD_START))
        sw0 |= 0x80;
    if (pad(0, RETRO_DEVICE_ID_JOYPAD_L3))
        sw0 |= 0x40; /* service */
    if (pad(1, RETRO_DEVICE_ID_JOYPAD_START))
        p2sw0 |= 0x80;

    jvs->player_switches[0][0] = sw0;
    jvs->player_switches[0][1] = sw1;
    jvs->player_switches[1][0] = p2sw0;
    jvs->player_switches[1][1] = p2sw1;
    jvs->system_switches = pad(0, RETRO_DEVICE_ID_JOYPAD_R3) ? 0x80 : 0x00;

    for (int p = 0; p < 2; p++) {
        if (pressed(pad(p, RETRO_DEVICE_ID_JOYPAD_SELECT), &coin_before[p]))
            qatomic_inc(&pending_coins[p]);
    }
    if (cards) {
        qatomic_or(&pending_cards, cards);
    }
    ffb_rumble();
}

/* On the emulation thread, with the big lock held */
void libretro_chihiro_apply_pending(void)
{
    ChihiroJVSState *jvs = chihiro_jvs_global;

    if (!jvs) {
        return;
    }
    chihiro_card_ui_sync();
    for (int p = 0; p < 2; p++) {
        jvs->coin_count[p] += qatomic_xchg(&pending_coins[p], 0);
    }
    int cards = qatomic_xchg(&pending_cards, 0);
    if (cards & 1)
        chihiro_hw210_card_key(0);
    if (cards & 2)
        chihiro_hw210_card_key(1);
    if (cards & 4)
        chihiro_crp1231_card_key();
}
