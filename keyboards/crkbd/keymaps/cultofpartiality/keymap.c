/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "cultofpartiality.h"

// Some key defines...?
#define U_RDO KC_AGIN
#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

// Keyboard Specific Enums - Layers and Keycodes
// Most of the standard bits are defined in the userspace, so only extras need to be defined here
// Each starts after the *SAFE_RANGE_KB, which is the enum in the userspace, which starts after *SAFE_RANGE
enum layers {
    _MOUSE = LAYERS_SAFE_RANGE_KB,
};


#define LAYOUT_split_3x6_3_wrapper(...)   LAYOUT_split_3x6_3(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY]   = LAYOUT_split_3x6_3(
    /*  -------, -------, -------, -------, -------, -------, -------, /##/ -------, -------, -------, -------, -------, -------, -------, */
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             /**/          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,             /**/          KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, HM_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             /**/          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            SYM_ESC, NUM_SPC, MOU_ENT, /**/ KC_BSPC, NAV_ENT, NAV_DEL
    ),

    [_NAV]    = LAYOUT_split_3x6_3_wrapper(
    /*  -------, -------, -------, -------, -------, -------, -------, /##/ -------, -------, -------, -------, -------, -------, -------,*/
        _______, _______________NAV_LEFT_TOP________________,          /**/          _______________NAV_RIGHT_TOP_______________, _______,
        _______, _______________NAV_LEFT_MID________________,          /**/          _______________NAV_RIGHT_MID_______________, _______,
        _______, _______________NAV_LEFT_BOT________________,          /**/          _______________NAV_RIGHT_BOT_______________, _______,
                                            SYM_ESC, KC_SPC,  KC_ENT,  /**/ U_NA,    U_NA,    U_NA
    ),

    [_SYMB]    = LAYOUT_split_3x6_3_wrapper(
    /*  -------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        _______, _______________SYM_LEFT_TOP________________,         /**/          _______________SYM_RIGHT_TOP_______________, _______,
        _______, _______________SYM_LEFT_MID________________,         /**/          _______________SYM_RIGHT_MID_______________, KC_BSLS,
        _______, _______________SYM_LEFT_BOT________________,         /**/          _______________SYM_RIGHT_BOT_______________, _______,
                                            U_NA,    U_NA,    U_NA,   /**/ KC_BSPC, KC_ENT,  NAV_DEL
    ),

    [_NUMBERS]    = LAYOUT_split_3x6_3_wrapper(
      /*-------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        _______, _______________NUM_LEFT_TOP________________,         /**/          _______________NUM_RIGHT_TOP_______________, _______,
        _______, _______________NUM_LEFT_MID________________,         /**/          _______________NUM_RIGHT_MID_______________, _______,
        _______, _______________NUM_LEFT_BOT________________,         /**/          _______________NUM_RIGHT_BOT_______________, _______,
                                            U_NA,    U_NA,    U_NA,   /**/ KC_BSPC, KC_ENT,  KC_DEL
    ),

    [_FUNC]    = LAYOUT_split_3x6_3(
     /*-------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          /**/          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
        _______, U_NU,    SA_TAB,  U_NU,    A_TAB,   U_NU,           /**/          U_NU,    KC_PWIN, U_NU,    KC_NWIN, KC_F11, _______,
        NM_OFF,  DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, U_NU,           /**/          U_NU,    U_NU,    U_NU,    U_NU,    KC_F12, _______,
                                            U_NA,    U_NA,    U_NA,  /**/ U_NA,    U_NA,    U_NA
    ),

    [_MOUSE]  = LAYOUT_split_3x6_3(
    /*-------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        _______, QK_BOOT, U_NU,     U_NU,   U_NU,    U_NU,          /**/          U_NU,    KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,
        _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, U_NU,          /**/          U_NU,    KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
        _______, U_NU,    KC_ALGR, U_NU,    U_NU,    U_NU,          /**/          U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    _______,
                                            U_NA,    U_NA,  U_NA,   /**/ KC_BTN1, KC_BTN3, KC_BTN2
    ),
};

// //Keyboard specific layer state code. Mostly moved to userspace
// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     return state;
// }

//Keyboard specific process record. Mostly moved to userspace
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

//Combos - Moved to userspace
