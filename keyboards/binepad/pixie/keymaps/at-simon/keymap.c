// Copyright 2023 Binepad (@binpad)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_user_layers {
    _BASE,
    _BOOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _BASE
     * ,-----------.
     * | MOB | Mut |
     * |-----|-----|
     * | F24 | Ply |
     * `-----------´
     */
    [_BASE] = LAYOUT(
        MO(_BOOT), KC_MUTE,
        KC_F24,    KC_MPLY
    ),

    /* _BOOT
     * ,-----------.
     * | vvv | Bot |
     * |-----|-----|
     * |     |     |
     * `-----------´
     */
    [_BOOT] = LAYOUT(
        _______,   QK_BOOT,
        XXXXXXX,   XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    /*
    * ,-----------. 1: CCW Volume down
    * | (1) | (2) |    CW  Volume up
    * |-----|-----|
    * |     |     | 2: CCW Volume down
    * `-----------´    CW  Volume up
    */
    [_BASE] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },

    /*
    * ,-----------. 1: CCW XXXXXXX
    * | (1) | (2) |    CW  XXXXXXX
    * |-----|-----|
    * |     |     | 2: CCW XXXXXXX
    * `-----------´    CW  XXXXXXX
    */
    [_BOOT] = {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX)
    }
};

#endif
