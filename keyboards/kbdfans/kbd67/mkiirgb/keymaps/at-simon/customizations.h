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

// Custom Colors
#define  RGB_MILKSHAKE_YELLOW 0xFF, 0xDD, 0x0  // 255 221 0
#define  HSV_MILKSHAKE_YELLOW 37, 255, 255     // 37  255 255

#define  RGB_MILKSHAKE_RED 0xFF, 0x45, 0x45    // 255 69  69
#define  HSV_MILKSHAKE_RED 0, 186, 255         // 0   186 255

#define  RGB_MILKSHAKE_GREEN 0x00, 0xFF, 0x1E  // 0   255 30
#define  HSV_MILKSHAKE_GREEN 90, 255, 255      // 90  255  255

#define  RGB_MILKSHAKE_BLUE 0x00, 0xAE, 0xFF   // 0   174 255
#define  HSV_MILKSHAKE_BLUE 141, 255, 255      // 141 255 255

#define  RGB_MILKSHAKE_PURPLE 0x84, 0x00, 0xFF // 132 0   255
#define  HSV_MILKSHAKE_PURPLE 192, 255, 255    // 192 255 255


// RGB LED locations
enum led_location_map {
    LED_ESC, // 0
    LED_1,  // 1
    LED_2,  // 2
    LED_3,  // 3
    LED_4,  // 4
    LED_5,  // 5
    LED_6,  // 6
    LED_7,  // 7
    LED_8,  // 8
    LED_9,  // 9
    LED_0,  // 10
    LED_MINS,   // 11
    LED_EQL,    // 12
    LED_BSPC,   // 13
    LED_DEL,    // 14
    LED_TAB,    // 15
    LED_Q,  // 16
    LED_W,  // 17
    LED_E,  // 18
    LED_R,  // 19
    LED_T,  // 20
    LED_Y,  // 21
    LED_U,  // 22
    LED_I,  // 23
    LED_O,  // 24
    LED_P,  // 25
    LED_LBRC,   // 26  [
    LED_RBRC,   // 27  ]
    LED_BSLS,   // 28  |
    LED_PGUP,   // 29
    LED_CAPS,   // 30
    LED_A,  // 31
    LED_S,  // 32
    LED_D,  // 33
    LED_F,  // 34
    LED_G,  // 35
    LED_H,  // 36
    LED_J,  // 37
    LED_K,  // 38
    LED_L,  // 39
    LED_SCLN, // 40    ;
    LED_QUOT, // 41    "
    LED_ENT, // 42
    LED_PGDN,   // 43
    LED_LSFT,   // 44
    LED_Z,  // 45
    LED_X,  // 46
    LED_C,  // 47
    LED_V,  // 48
    LED_B,  // 49
    LED_N,  // 50
    LED_M,  // 51
    LED_COMM, // 52  ,
    LED_DOT,    // 53  .
    LED_SLSH,   // 54 /
    LED_RSFT,   // 55
    LED_UP, // 56
    LED_END, // 57
    LED_LCTL, // 58
    LED_LWIN, // 59
    LED_LALT, // 60
    LED_SPC, // 61
    LED_FN, // 62
    LED_RCTL, // 63
    LED_LEFT, // 64
    LED_DOWN, // 65
    LED_RIGHT // 66
};

const uint8_t LED_LIST_SETTINGS[] = {
    LED_SLSH, LED_RSFT, LED_UP, LED_END,
    LED_LEFT, LED_DOWN, LED_RIGHT
};

const uint8_t LED_LIST_ARROWS[] = {
    LED_UP,
    LED_LEFT, LED_DOWN, LED_RIGHT
};

const uint8_t LED_LIST_MILKSHAKE_YELLOW[] = {
    LED_BSPC,
    LED_DEL
};

const uint8_t LED_LIST_MILKSHAKE_RED[] = {
    LED_CAPS
};

const uint8_t LED_LIST_MILKSHAKE_GREEN[] = {
    LED_ENT,
    LED_PGDN
};

const uint8_t LED_LIST_MILKSHAKE_BLUE[] = {
    LED_LALT,
    LED_FN
};

const uint8_t LED_LIST_MILKSHAKE_PURPLE[] = {
    LED_LWIN,
    LED_RCTL
};

const uint8_t LED_LIST_NUMPAD[] = {
    LED_7, LED_8, LED_9,
    LED_U, LED_I, LED_O,
    LED_J, LED_K, LED_L,
    LED_M
};

const uint8_t LED_LIST_NUMPAD_EXTRA[] = {
    LED_MINS, LED_EQL, LED_BSPC,
    LED_LBRC, LED_RBRC,
    LED_F, LED_ENT,
    LED_COMM, LED_DOT, LED_SLSH,
    LED_UP, LED_END,
    LED_LEFT, LED_DOWN, LED_RIGHT,
};

const uint8_t LED_LIST_LIGHTNIG_MODE[] = {
    LED_COMM, LED_DOT, LED_SLSH, LED_M,
};

const uint8_t LED_LIST_LOGO_APPLE[] = {
            LED_8,
    LED_U, LED_I, LED_O,
    LED_J, LED_K,
    LED_M, LED_COMM, LED_DOT,
};

const uint8_t LED_LIST_LOGO_WINDOWS_RED[] = {
    LED_4, LED_5, 
    LED_E, LED_R, 
};

const uint8_t LED_LIST_LOGO_WINDOWS_GREEN[] = {
    LED_6, LED_7, 
    LED_T, LED_Y, 
};

const uint8_t LED_LIST_LOGO_WINDOWS_BLUE[] = {
    LED_S, LED_D, 
    LED_Z, LED_X, 
};

const uint8_t LED_LIST_LOGO_WINDOWS_YELLOW[] = {
    LED_F, LED_G, 
    LED_C, LED_V, 
};

#define ARRAYSIZE(arr)  sizeof(arr)/sizeof(arr[0])

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_set_color_all_hsv(uint8_t red, uint8_t green, uint8_t blue);
void rgb_matrix_set_color_hsv(int index, uint8_t red, uint8_t green, uint8_t blue);

void colorize_keycaps(void);
void colorize_settings(void);
void colorize_numpad(void);
void colorize_os_indicators(void);

uint8_t get_lighting_mode(void);
#endif
