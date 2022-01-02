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
│        │        │        │        │           │        │            │        │     │   F1   │   F2   │        │        │     │        │        │        │        │    │        │        │   F11  │  EJEC  │
│  M(4)  │  M(3)  │  M(2)  │  M(1)  │           │  M(0)  │            │  ESC   │     │   BD   │   BU   │   F3   │   F4   │     │   F5   │   F6   │   F7   │   F8   │    │   F9   │  F10   │   MC   │  F12   │
│        │        │        │        │           │        │            │        │     │        │        │        │        │     │        │        │        │        │    │        │        │        │        │
└────────┴────────┴────────┴────────┘           └────────┘            └────────┘     └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘    └────────┴────────┴────────┴────────┘

┌────────┬────────┬────────┬────────┐  ┌────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬─────────────────┐
│        │        │        │        │  │        │        │        │  │    ~   │    !   │    @   │    #   │    $   │    %   │    ^   │    &   │   *    │   (    │    )   │   _    │    +   │                 │
│  NUM   │  F24   │    -   │    /   │  │        │        │  CMD+S │  │        │        │        │        │        │        │        │        │        │        │        │        │        │    BACKSPACE    │
│        │        │        │        │  │        │        │        │  │    `   │    1   │    2   │    3   │    4   │    5   │    6   │    7   │   8    │   9    │    0   │   -    │    =   │                 │
├────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┤  ├────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬─────────────┤
│        │        │        │        │  │        │        │        │  │            │        │        │        │        │        │        │        │        │        │        │   {    │    }   │      |      │
│    7   │    8   │    9   │    *   │  │SH+CMD+M│SH+CMD+Z│ CMD+Z  │  │    TAB     │   Q    │    W   │   e    │    R   │   T    │    Y   │   U    │    I   │    O   │    P   │        │        │             │
│        │        │        │        │  │        │        │        │  │            │        │        │        │        │        │        │        │        │        │        │   [    │    ]   │      \      │
├────────┼────────┼────────┼────────┤  └────────┴────────┴────────┘  ├────────────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴──┬─────┴─────────────┤
│        │        │        │        │                                │               │        │        │        │        │        │        │        │        │        │    :   │    "   │                   │
│    4   │    5   │    6   │        │                                │  CAPS LOCK    │    A   │    S   │    D   │    F   │    G   │    H   │    J   │    K   │    L   │        │        │        ENTER      │
│        │        │        │        │                                │               │        │        │        │        │        │        │        │        │        │    ;   │    '   │                   │
├────────┼────────┼────────┼────────┤           ┌────────┐           ├───────────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───────────────────┤
│        │        │        │        │           │        │           │                   │        │        │        │        │        │        │        │    <   │   >    │    ?   │                        │
│    1   │    2   │    3   │        │           │   UP   │           │      SHIFT        │    Z   │    X   │   C    │    V   │    B   │   N    │   M    │        │        │        │        SHIFT           │
│        │        │        │        │           │        │           │                   │        │        │        │        │        │        │        │    ,   │   .    │    /   │                        │
├────────┼────────┼────────┼────────┤  ┌────────┼────────┼────────┐  ├──────────┬────────┴─┬──────┴───┬────┴────────┴────────┴────────┴────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬────────┬────────┤
│        │    0   │        │        │  │        │        │        │  │          │ ALT      │      ⌘  │                                                                 │    ALT │        │        │        │
│    .   │        │        │   WIN  │  │  LEFT  │  DOWN  │  RIGHT │  │   CTRL   │          │ KC_LCMD  │                            space                                │        │   FN   │        │  CTRL  │
│   DEL  │        │        │        │  │        │        │        │  │          │ OPTION   │ COMMAND  │                                                                 │ OPTION │        │COMMAND │        │
└────────┴────────┴────────┴────────┘  └────────┴────────┴────────┘  └──────────┴──────────┴──────────┴─────────────────────────────────────────────────────────────────┴────────┴────────┴────────┴────────┘

*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO,  MO(0),   KC_ESC,  KC_BRMD, KC_BRMU, KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_EJCT,  
        KC_NLCK, KC_NO, KC_PMNS, KC_PSLS,   KC_NO,     KC_NO,    LCMD(KC_S),     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, 
        KC_P7,   KC_P8,   KC_P9,   KC_PAST, LSFT(LCMD(KC_M)),     LSFT(LCMD(KC_Z)),    LCMD(KC_Z),     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, 
        KC_P4,   KC_P5,   KC_P6,   KC_TAB,    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  
        KC_P1,   KC_P2,   KC_P3,   KC_TAB,    KC_UP,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, 
        KC_PDOT, KC_P0,   KC_NO,   KC_LGUI,    KC_LEFT, KC_DOWN, KC_RGHT, KC_LCTL, KC_LOPT, KC_LCMD, KC_SPC,  KC_ROPT, UC_M_MA, KC_RCMD, KC_RCTL      
    ),

};

