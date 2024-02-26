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

#include QMK_KEYBOARD_H
#include "customizations.h"

// LAYERS
enum custom_user_layers {
    _B_CALC,
    _B_MEDIA,
    _CONTROL,
    _RESET
};

// Interact with layers
#define MO_CTRL MO(_CONTROL)
#define MO_RST MO(_RESET)

// Define
#define KVM_DELAY 100

// Custom keycodes
enum custom_user_keycodes {
    MED_ON = SAFE_RANGE,
    CALC_ON,
    KVM_UP,
    KVM_DN,
    KVM_SI,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _B_CALC
     * ,-----------------------.
     * | ESC |     | TCT | TMD |
     * `-----------------------´
     * ,-----------------------.
     * | BSP |  /  |  *  |  -  |
     * |-----------------------|
     * |  7  |  8  |  9  |     |
     * |-----------------|  +  |
     * |  4  |  5  |  6  |     |
     * |-----------------------|
     * |  1  |  2  |  3  |     |
     * |-----------------| ENT |
     * |     0     |  .  |     |
     * `-----------------------´
     */
    [_B_CALC] = LAYOUT_numpad_6x4(
        KC_ESC,  XXXXXXX, MO_CTRL, MED_ON,
        KC_BSPC, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
        KC_P0,            KC_PDOT, KC_PENT
    ),

    /* _B_MEDIA
     * ,-----------------------.
     * | NUM | NUM | TCT | MRS |
     * `-----------------------´
     * ,-----------------------.
     * |     | V 0 | V - | V + |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------| F24 |
     * | KSI | K U |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------| Ply |
     * |           |     |     |
     * `-----------------------´
     */
    [_B_MEDIA] = LAYOUT_numpad_6x4(
        CALC_ON, CALC_ON, MO_CTRL, MO_RST,
        XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,
        XXXXXXX, XXXXXXX, XXXXXXX,
        KVM_SI,  KVM_UP,  XXXXXXX, KC_F24,
        KC_SCRL, XXXXXXX, XXXXXXX,
        XXXXXXX,          XXXXXXX, KC_MPLY
    ),

    /* _CONTROL
     * ,-----------------------.
     * |     |     | vvv |     |
     * `-----------------------´
     * ,-----------------------.
     * | N L |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|     |
     * |     |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------| P 1 |
     * |           |     |     |
     * `-----------------------´
     */
    [_CONTROL] = LAYOUT_numpad_6x4(
        XXXXXXX, XXXXXXX, _______, XXXXXXX,
        KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,          XXXXXXX, KC_P1
    ),


    /* _RESET
     * ,-----------------------.
     * |     |     |     | vvv |
     * `-----------------------´
     * ,-----------------------.
     * |     |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|     |
     * |     |     |     |     |
     * |-----------------------|
     * |     |     |     |     |
     * |-----------------|  .  |
     * |   Reset   | EEP |     |
     * `-----------------------´
     */
    [_RESET] = LAYOUT_numpad_6x4(
        XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT,          EE_CLR,  KC_PDOT
    )
};



/* Empty keymap
 * ,-----------------------.
 * |     |     |     |     |
 * `-----------------------´
 * ,-----------------------.
 * |     |     |     |     |
 * |-----------------------|
 * |     |     |     |     |
 * |-----------------|     |
 * |     |     |     |     |
 * |-----------------------|
 * |     |     |     |     |
 * |-----------------|     |
 * |           |     |     |
 * `-----------------------´
 */


// Process custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
    switch (keycode) {
        case MED_ON:
            if (record->event.pressed) {
                layer_on(_B_MEDIA);
                layer_off(_B_CALC);
            }
            return false;
            break;
        case CALC_ON:
            if (record->event.pressed) {
                layer_on(_B_CALC);
                layer_off(_B_MEDIA);
            }
            return false;
            break;
        case KVM_UP:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(KVM_DELAY) SS_TAP(X_SCRL) SS_DELAY(KVM_DELAY) SS_TAP(X_PGUP));
            }
            return false;
            break;
        case KVM_DN:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SCRL) SS_DELAY(KVM_DELAY) SS_TAP(X_SCRL) SS_DELAY(KVM_DELAY) SS_TAP(X_PGDN));
            }
            return false;
            break;
        case KVM_SI:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RALT) SS_DELAY(KVM_DELAY) SS_TAP(X_RALT));
            }
            return false;
            break;
        default:
            break;
    }
    return true;
}