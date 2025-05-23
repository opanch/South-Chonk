/* Copyright 2022 REPLACE_WITH_YOUR_NAME
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

/*  
┌────────┬────────┬────────┬────────┐           ┌────────┐            ┌────────┐     ┌────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┐    ┌────────┬────────┬────────┬────────┐
│        │        │        │        │           │        │            │        │     │        │        │        │        │     │        │        │        │        │    │        │        │        │        │
│  M(4)  │  M(3)  │  M(2)  │  M(1)  │           │  M(0)  │            │  ESC   │     │   F1   │   F2   │   F3   │   F4   │     │   F5   │   F6   │   F7   │   F8   │    │   F9   │   F10  │   F11  │  F12   │
│        │        │        │        │           │        │            │        │     │        │        │        │        │     │        │        │        │        │    │        │        │        │        │
└────────┴────────┴────────┴────────┘           └────────┘            └────────┘     └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘    └────────┴────────┴────────┴────────┘

┌────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
│        │        │        │  NUM   │  │        │        │        │  │    ~   │    !   │    @   │    #   │    $   │    %   │    ^   │    &   │   *    │   (    │    )   │   _    │    +   │                 │
│   /    │    *   │    -   │  LOCK  │  │ INSERT │  HOME  │  PGUP  │  │        │        │        │        │        │        │        │        │        │        │        │        │        │    BACKSPACE    │
│        │        │        │        │  │        │        │        │  │    `   │    1   │    2   │    3   │    4   │    5   │    6   │    7   │   8    │   9    │    0   │   -    │    =   │                 │
├────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┤  ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
│        │        │        │        │  │        │        │        │  │            │        │        │        │        │        │        │        │        │        │        │   {    │    }   │      |      │
│    +   │    9   │    8   │    7   │  │  DELET │   END  │  PGDN  │  │    TAB     │   Q    │    W   │   e    │    R   │   T    │    Y   │   U    │    I   │    O   │    P   │        │        │             │
│        │        │        │        │  │        │        │        │  │            │        │        │        │        │        │        │        │        │        │        │   [    │    ]   │      \      │
├────────┼────────┼────────┼────────┤  └────────┴────────┴────────┘  ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
│        │        │        │        │                                │               │        │        │        │        │        │        │        │        │        │    :   │    "   │                   │
│    =   │   6    │    5   │    4   │                                │  CAPS LOCK    │    A   │    S   │    D   │    F   │    G   │    H   │    J   │    K   │    L   │        │        │        ENTER      │
│        │        │        │        │                                │               │        │        │        │        │        │        │        │        │        │    ;   │    '   │                   │
├────────┼────────┼────────┼────────┤           ┌────────┐           ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤
│        │        │        │        │           │        │           │                   │        │        │        │        │        │        │        │    <   │   >    │    ?   │                        │
│ SHIFT  │   3    │    2   │    1   │           │   ↑    │           │      SHIFT        │    Z   │    X   │   C    │    V   │    B   │   N    │   M    │        │        │        │        SHIFT           │
│        │        │        │        │           │        │           │                   │        │        │        │        │        │        │        │    ,   │   .    │    /   │                        │
├────────┼────────┼────────┼────────┤  ┌────────┼────────┼────────┐  ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬────────┬────────┤
│        │        │        │        │  │        │        │        │  │          │          │          │                                                                 │        │        │        │        │
│   CTR  │  ALT   │    .   │    0   │  │   ←    │    ↓   │   →    │  │   CTRL   │    WIN   │   ALT    │                            space                                │   ALT  │  WIN   │  MENU  │  CTRL  │
│        │        │   DEL  │        │  │        │        │        │  │          │    OS    │          │                                                                 │        │        │        │        │
└────────┴────────┴────────┴────────┘  └────────┴────────┴────────┘  └──────────┴──────────┴──────────┴─────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┘

*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        M(4),    M(3),    M(2),    M(1),              M(0),            KC_ESC,  KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  
        KC_PSLS, KC_PAST, KC_PMNS, KC_NLCK,  KC_INS, KC_HOME, KC_PGUP, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, 
        KC_PPLS,   KC_P9,   KC_P8,   KC_P7,  KC_DEL, KC_END, KC_PGDN,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
        KC_PEQL,   KC_P6,   KC_P5,   KC_P4,                            KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  
        KC_LSFT,   KC_P3,   KC_P2,   KC_P1,          KC_UP,            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
        KC_RCTL, KC_LALT,   KC_PDOT, KC_P0, KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_RALT, KC_RGUI, KC_MENU, KC_RCTL      
    ),
};

