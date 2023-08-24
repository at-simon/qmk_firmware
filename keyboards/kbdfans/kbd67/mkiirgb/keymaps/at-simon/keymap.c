/* Copyright 2022 at-simon
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
// Useful stuff at: /users/drashna/callbacks.md

#include QMK_KEYBOARD_H
#include "customizations.h"
#include "sendstring_us_international.h"

// Custom Keycodes
enum custom_user_keycodes {
    RGB_M_0 = SAFE_RANGE,
    RGB_M_1,
    RGB_M_2,
    BRGHT_I,
    BRGHT_D,
    SPEED_I,
    SPEED_D,
    RAINBOW,
    A_GREET,
    A_MAIL,
    K_GREET,
    K_MAIL
};

// LAYERS
enum custom_user_layers {
    _BASE,
    _SETTINGS,
    _NUMPAD,
    _RESET,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base layer
     * ,--------------------------------------------------------------------------------------------------.
     * | Ec~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | PgUp |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgDn |
     * |-------------------------------------------------------------------------------------------+------|
     * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * | LCtrl | LGUI | LAlt |               Space                 | RAlt | MO 1 |   | Left  | Dwn | Rght |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_BASE] = LAYOUT_65_ansi_blocker(
        QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLASH,KC_PGUP,
        XXXXXXX,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT,  MO(1),              KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),


    /* Settings layer
     * ,--------------------------------------------------------------------------------------------------.
     * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |     Del     | PScr |
     * |-------------------------------------------------------------------------------------------+------|
     * |        |     |     |     |     |     |     |     |     | TO3 |     | TO2 |     |          | Ins  |
     * |-------------------------------------------------------------------------------------------+------|
     * | Caps     |     | A_M | K_M |     |     |     |     | S - | S + | Br- | Br+ |              | Play |
     * |-------------------------------------------------------------------------------------------+------|
     * |     VV     |     |     |     | A_G | K_G |     | RBW | RM0 | RM1 | RM2 |     VV     | V + | Mute |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * |   VV  |  VV  |  VV  |                                     |  VV  |  VV  |   | Prev  | V - | Next |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_SETTINGS] = LAYOUT_65_ansi_blocker(
        KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_PSCR,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TO(3),    XXXXXXX,  TO(2),    XXXXXXX,  XXXXXXX,  KC_INS,
        KC_CAPS,  XXXXXXX,  A_MAIL,   K_MAIL,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  SPEED_D,  SPEED_I,  BRGHT_D,  BRGHT_I,            XXXXXXX,  KC_MPLY,
        _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  A_GREET,  K_GREET,  XXXXXXX,  RAINBOW,  RGB_M_0,  RGB_M_1,  RGB_M_2,  _______,            KC_VOLU,  KC_MUTE,
        _______,  _______,  _______,                                XXXXXXX,                      _______,  _______,            KC_MPRV,  KC_VOLD,  KC_MNXT
    ),
  
  
    /* Numpad layer
     * ,--------------------------------------------------------------------------------------------------.
     * | TO0 |     |     |     |     |     |     |  7  |  8  |  9  |     |  -  |  +  |  Backspace  | Home |
     * |-------------------------------------------------------------------------------------------+------|
     * | Tab    |     |     |     |     |     |     |  4  |  5  |  6  |     |  *  |  /  |          |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |     |     |     | NmL |     |     |  1  |  2  |  3  |     |     |    Enter     |      |
     * |-------------------------------------------------------------------------------------------+------|
     * | Shift      |     |  X  |  C  |  V  |     |     |  0  |  ,  |  .  |  /  |            | Up  | End  |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * | LCtrl |      | LAlt |                                     |      |      |   | Left  | Dwn | Rght |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_NUMPAD] = LAYOUT_65_ansi_blocker(
        TO(0),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P7,    KC_P8,    KC_P9,    XXXXXXX,  KC_PMNS,  KC_PPLS,  KC_BSPC,  KC_HOME,
        KC_TAB,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_P4,    KC_P5,    KC_P6,    XXXXXXX,  KC_PAST,  KC_PSLS,  XXXXXXX,  KC_PGUP,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM,   XXXXXXX,  XXXXXXX,  KC_P1,    KC_P2,    KC_P3,    XXXXXXX,  XXXXXXX,            KC_ENT,   KC_PGDN,
        KC_LSFT,  XXXXXXX,  KC_X,     KC_C,     KC_V,     XXXXXXX,  XXXXXXX,  KC_P0,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
        KC_LCTL,  XXXXXXX,  KC_LALT,                                XXXXXXX,                      XXXXXXX,  XXXXXXX,            KC_LEFT,  KC_DOWN,  KC_RIGHT
    ),


    /* Reset and EEPROM clear layer
     * ,--------------------------------------------------------------------------------------------------.
     * | TO0 |     |     |     |     |     |     |     |     |     |     |     |     |             |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |          |     |     |     |     |     |     | RST | EEP |     |     |     |              |      |
     * |-------------------------------------------------------------------------------------------+------|
     * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
     * |-------------------------------------------------------------------------┬---┬-------------+------|
     * |       |      |      |                                     |      |      |   |       |     |      |
     * `-------------------------------------------------------------------------´   `--------------------´
     */
    [_RESET] = LAYOUT_65_ansi_blocker(
        TO(0),    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,  EE_CLR,   XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                      XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
};

/* Empty keymap
 * ,--------------------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |             |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |          |     |     |     |     |     |     |     |     |     |     |     |              |      |
 * |-------------------------------------------------------------------------------------------+------|
 * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
 * |-------------------------------------------------------------------------┬---┬-------------+------|
 * |       |      |      |                                     |      |      |   |       |     |      |
 * `-------------------------------------------------------------------------´   `--------------------´
 */


// ----------------------------- Lighting stuff ----------------------------.
// #ifdef ENABLE_MILKSHAKE  
uint8_t lighting_mode = 3; // default: Rainbow
uint8_t hsv_val = 170;

void keyboard_post_init_user(void) {
    rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP); // default for rainbow
    // rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR); // default for milkshake
    // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
}

uint8_t get_lighting_mode(void) {
    return lighting_mode;
}


void rgb_matrix_set_color_hsv(int index, uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {hue, sat, hsv_val};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_driver.set_color(index, rgb.r, rgb.g, rgb.b);
}

void rgb_matrix_set_color_all_hsv(uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {hue, sat, hsv_val};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_driver.set_color_all(rgb.r, rgb.g, rgb.b);
}


// -------------------------------- Milkshake --------------------------------.
void colorize_keycaps(void) {
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_YELLOW); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_YELLOW[i], HSV_MILKSHAKE_YELLOW);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_RED); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_RED[i], HSV_MILKSHAKE_RED);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_GREEN); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_GREEN[i], HSV_MILKSHAKE_GREEN);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_BLUE); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_BLUE[i], HSV_MILKSHAKE_BLUE);
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_MILKSHAKE_PURPLE); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_MILKSHAKE_PURPLE[i], HSV_MILKSHAKE_PURPLE);
    }
}

void colorize_settings(void) {
    rgb_matrix_set_color_hsv(LED_LBRC, HSV_MILKSHAKE_PURPLE);
    
    rgb_matrix_set_color_hsv(LED_QUOT, HSV_MILKSHAKE_GREEN);
    rgb_matrix_set_color_hsv(LED_SCLN, HSV_MILKSHAKE_RED);

    rgb_matrix_set_color_hsv(LED_L, HSV_MILKSHAKE_GREEN);
    rgb_matrix_set_color_hsv(LED_K, HSV_MILKSHAKE_RED);

    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_LIGHTNIG_MODE); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_LIGHTNIG_MODE[i], HSV_MILKSHAKE_YELLOW);
    }
    rgb_matrix_set_color_hsv(LED_LIST_LIGHTNIG_MODE[get_lighting_mode()], HSV_MILKSHAKE_RED);
}

void colorize_numpad(void) {
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_NUMPAD); i++) {
        if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
            rgb_matrix_set_color_hsv(LED_LIST_NUMPAD[i], HSV_MILKSHAKE_BLUE);
        } else {
            rgb_matrix_set_color_hsv(LED_LIST_NUMPAD[i], HSV_MILKSHAKE_RED);
        }
    }
    for (uint8_t i=0; i<ARRAYSIZE(LED_LIST_NUMPAD_EXTRA); i++) {
        rgb_matrix_set_color_hsv(LED_LIST_NUMPAD_EXTRA[i], HSV_MILKSHAKE_PURPLE);
    }
    rgb_matrix_set_color_hsv(LED_ESC, HSV_MILKSHAKE_RED);
}
// ----------------------------------------------------------------------------

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state)){ 
    case _BASE:
        switch(get_lighting_mode()) {
        case 0:
            rgb_matrix_set_color_all_hsv(HSV_WHITE);
            colorize_keycaps();
            break;
        case 1:
            rgb_matrix_set_color_all(HSV_OFF);
            colorize_keycaps();
            break;
        case 2:
            rgb_matrix_set_color_all(HSV_OFF);
            break;
        default:
            break;
        }
        break;
    case _SETTINGS: 
        switch(get_lighting_mode()) {
        case 0:
            rgb_matrix_set_color_all_hsv(HSV_WHITE);
            colorize_keycaps();
            colorize_settings();
            break;
        case 1:
            rgb_matrix_set_color_all(HSV_OFF);
            colorize_keycaps();
            colorize_settings();
            break;
        case 2:
            rgb_matrix_set_color_all(HSV_OFF);
            break;
        default:
            break;
        }
        break;
    case _NUMPAD:
        switch(get_lighting_mode()) {
        case 0:
            rgb_matrix_set_color_all_hsv(HSV_WHITE);
            colorize_keycaps();
            colorize_numpad();
            break;
        case 1:
            rgb_matrix_set_color_all(HSV_OFF);
            colorize_keycaps();
            colorize_numpad();
            break;
        case 2:
            rgb_matrix_set_color_all(HSV_OFF);
            break;
        default:
            break;
        }
        break;
    case _RESET:
        // Special lighting for reset layer
        rgb_matrix_set_color_all(HSV_OFF);
        rgb_matrix_set_color_hsv(LED_ESC, HSV_MILKSHAKE_RED);
        rgb_matrix_set_color_hsv(LED_J, HSV_MILKSHAKE_RED);
        rgb_matrix_set_color_hsv(LED_K, HSV_MILKSHAKE_RED);
        break;
    default:
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
    switch (keycode) {
        case RGB_M_0:
            if (record->event.pressed) {
                lighting_mode = 0;
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
            break;
        case RGB_M_1:
            if (record->event.pressed) {
                lighting_mode = 1;
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
            break;
        case RGB_M_2:
            if (record->event.pressed) {
                lighting_mode = 2;
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            }
            return false;
            break;
        case BRGHT_I:
            if (record->event.pressed) {
                hsv_val = (hsv_val >= 238) ? 255 : hsv_val + 17;
            }
            return false;
            break;
        case BRGHT_D:
            if (record->event.pressed) {
                hsv_val = (hsv_val <= 34) ? 17 : hsv_val - 17;
            }
            return false;
            break;
        case RAINBOW:
            if (record->event.pressed) {
                lighting_mode = 3;
                rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
            }
            return false;
            break;
        case SPEED_I:
            if (record->event.pressed) {
                rgb_matrix_increase_speed_noeeprom();
            }
            return false;
            break;
        case SPEED_D:
            if (record->event.pressed) {
                rgb_matrix_decrease_speed_noeeprom();
            }
            return false;
            break;
        case A_GREET:
            if (record->event.pressed) {
                SEND_STRING("Viele Gr" SS_RALT("y") SS_RALT("s") "e\nSimon");
            }
            return false;
            break;
        case A_MAIL:
            if (record->event.pressed) {
                send_string("MAIL"); // TODO insert Mail here
            }
            return false;
            break;
        case K_GREET:
            if (record->event.pressed) {
                SEND_STRING("Mit freundlichen Gr" SS_RALT("y") SS_RALT("s") "en\nSimon"); // TODO
            }
            return false;
            break;
        case K_MAIL:
            if (record->event.pressed) {
                send_string("MAIL"); // TODO insert Mail here
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}
// #endif
// ---------------------------------------------------------------------------´
