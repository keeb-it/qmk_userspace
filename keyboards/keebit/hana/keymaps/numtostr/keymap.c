// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define BOOTL_1 KC_A
#define BOOTL_2 KC_B

// Rotary
#define L_ROT KC_MNXT
#define R_ROT KC_MPLY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
      //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   L_ROT,      R_ROT,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
      //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,    MO(2), KC_RALT, _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {  ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif

const uint16_t PROGMEM bootl_combo[] = {BOOTL_1, BOOTL_2, COMBO_END};

combo_t key_combos[] = {
    COMBO(bootl_combo, QK_BOOTLOADER),
};


#ifdef OLED_ENABLE
#include "luna.c"
#endif

