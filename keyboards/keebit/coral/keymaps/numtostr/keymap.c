// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Thumb Keys
#define L_THUMB LT(NavLayer, KC_ENTER)
#define R_THUMB LT(NavLayer, KC_SPACE)

// Rotary
#define L_ROT TD(TD_MNXT_MPREV)
#define R_ROT TD(TD_MPLY_MUTE)

// Custom Keys
#define KK_COPY TD(TD_COPY_CUT)
#define KK_PASTE RCTL(KC_V)
#define KK_MOUSE MO(MouseLayer)
#define BOOTL_1 KC_7
#define BOOTL_2 KC_8
#define BOOTL_3 KC_9
#define EECLR_1 KC_4
#define EECLR_2 KC_5
#define EECLR_3 KC_6

// ###### Tap-Dance ######

enum coral_tapdance {
    TD_MNXT_MPREV,
    TD_MPLY_MUTE,
    TD_COPY_CUT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Media-Next, twice for Media-Previous
    [TD_MNXT_MPREV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
    // Tap once for Play/Pause, twice for Audio Mute
    [TD_MPLY_MUTE] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE),
    // Tap once copy, twice for cut
    [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_X)),
};

// ###### Layers ######

enum coral_keycodes {
    JIGGLE = SAFE_RANGE,
};

enum coral_layers {
    BaseLayer,
    NavLayer,
    MouseLayer,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BaseLayer] = LAYOUT(
        KC_1,    KC_2,  KC_3,    EECLR_1, EECLR_2, EECLR_3,        /**/        BOOTL_1, BOOTL_2, BOOTL_3,  KC_0,    KC_MINUS, KC_EQUAL,
        KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,           /**/        KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,     KC_LBRC,
        KC_GRV,  GUI_A, ALT_S,   SFT_D,   CTL_F,   KC_G,           /**/        KC_H,    CTL_J,   SFT_K,    ALT_L,   GUI_SCLN, KC_QUOTE,
        KC_BSLS, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,           /**/        KC_N,    KC_M,    KC_COMMA, KC_DOT,  KC_SLASH, KC_RBRC,
                        KK_COPY, KC_PSCR, KC_ESC,  L_THUMB, L_ROT, /**/ R_ROT, R_THUMB, KC_BSPC, KC_DEL,   KK_PASTE
    ),
    [NavLayer] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             /**/          KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLU, KC_VOLD,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,            /**/          KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_BRIU, KC_BRID,
        _______, _______, _______, _______, _______, KK_MOUSE,          /**/          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,           /**/          _______, _______, _______, _______,  _______, _______,
                          _______, _______, _______, XXXXXXX,  _______, /**/ _______, XXXXXXX, _______, _______, _______
    ),
    [MouseLayer] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          /**/          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          /**/          _______, KC_BTN1, KC_BTN2, _______, _______, _______,
        _______, _______, _______, _______, _______, XXXXXXX,          /**/          KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
        _______, _______, _______, _______, _______, _______,          /**/          _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, XXXXXXX, _______, /**/ _______, JIGGLE, _______, _______, _______
    ),
};

// ###### Combos ######
const uint16_t PROGMEM capsw_combo[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM bootl_combo[] = {BOOTL_1, BOOTL_2, BOOTL_3, COMBO_END};
const uint16_t PROGMEM eeclr_combo[] = {EECLR_1, EECLR_2, EECLR_3, COMBO_END};

combo_t key_combos[] = {
    COMBO(capsw_combo, QK_CAPS_WORD_TOGGLE),
    COMBO(bootl_combo, QK_BOOTLOADER),
    COMBO(eeclr_combo, QK_CLEAR_EEPROM),
};

// ###### Encoders #######

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BaseLayer] = { ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NavLayer] = { ENCODER_CCW_CW(RGB_MODE_REVERSE, RGB_MODE_FORWARD), ENCODER_CCW_CW(_______, _______) },
    [MouseLayer] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    static deferred_token jiggle_token = INVALID_DEFERRED_TOKEN;
    static report_mouse_t report = {0};
    switch (keycode) {
        case JIGGLE:
            if (record->event.pressed) {
                uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
                    // Deltas to move in a circle of radius 20 pixels over 32 frames.
                    static const int8_t deltas[32] = {
                        0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
                        0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
                    static uint8_t phase = 0;
                    // Get x delta from table and y delta by rotating a quarter cycle.
                    report.x = deltas[phase];
                    report.y = deltas[(phase + 8) & 31];
                    phase = (phase + 1) & 31;
                    host_mouse_send(&report);
                    return 16;  // Call the callback every 16 ms.
                }
                jiggle_token = defer_exec(1, jiggler_callback, NULL);  // Schedule callback.
            }
            return true;
        case KC_ESC:
            if (record->event.pressed && jiggle_token != INVALID_DEFERRED_TOKEN) {
                // If jiggler is currently running, stop when any key is pressed.
                cancel_deferred_exec(jiggle_token);
                jiggle_token = INVALID_DEFERRED_TOKEN;
                report = (report_mouse_t){};  // Clear the mouse.
                host_mouse_send(&report);
            }
            return true;
        default:
            if (jiggle_token != INVALID_DEFERRED_TOKEN) {
                return false; // swallow everything if jiggler is on
            }
            return true; // Process all other keycodes normally
    }
}
