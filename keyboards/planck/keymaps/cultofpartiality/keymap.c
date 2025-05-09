/* Copyright 2015-2021 Jack Humbert
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
#include "cultofpartiality.h"


#ifndef ZOMBIE_PLANCK
    #include "testing.c"
    #include "muse.h"
#endif

//Layer key defines
#define NUMPAD MO(_NUMPAD)

// Keyboard Specific Enums - Layers and Keycodes
// Most of the standard bits are defined in the userspace, so only extras need to be defined here
// Each starts after the *SAFE_RANGE_KB, which is the enum in the userspace, which starts after *SAFE_RANGE
enum planck_layers {
  _NUMPAD = LAYERS_SAFE_RANGE_KB,
  _MOUSE
};
enum planck_keycodes {
  QWERTY = SAFE_RANGE_KB,
  BACKLIT,
};

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_planck_grid_wrapper(...)   LAYOUT_planck_grid(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty and homerow qwerty
    * ,-----------------------------------------------------------------------------------.
    * | `ESC |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | GUI  | Alt  |Numpad|Lower |Space |Enter |Raise |CtlShf| Alt  | GUI  | Ctrl |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_grid(
        QK_GESC, KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    /**/ KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HM_A,    HM_S,    HM_D,   HM_F,    KC_G,    /**/ KC_H,    HM_J,   HM_K,    HM_L,    HM_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    /**/ KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT, NUMPAD, KC_SYMB, NUM_SPC, /**/ NAV_ENT, KC_NAV, KM_CSHT, KC_RALT, KC_RGUI, KC_RCTL
    ),

    /* Lower - Symbols
    *      Standardised easy-access keys from userspace to keep all boards in sync
    * ,-----------------------------------------------------------------------------------.
    * |______|  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |______|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |______|  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |______|  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |______|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |______|______|______|______| LAYER|______|______|______|______|______|______|______|
    * `-----------------------------------------------------------------------------------'
    */
    [_SYMB] = LAYOUT_planck_grid_wrapper(
        _______, _______________SYM_LEFT_TOP________________, /**/ _______________SYM_RIGHT_TOP_______________, _______,
        _______, _______________SYM_LEFT_MID________________, /**/ _______________SYM_RIGHT_MID_______________, KC_BSLS,
        _______, _______________SYM_LEFT_BOT________________, /**/ _______________SYM_RIGHT_BOT_______________, _______,
        _______, _______, _______, XXXXXXX, _______, KC_SPC,  /**/ _______, _______, _______, _______, _______, _______
    ),

    /* Raise - Navigation
    *      Standardised easy-access keys from userspace to keep all boards in sync
    * ,-----------------------------------------------------------------------------------.
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      | LAYER|      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NAV] = LAYOUT_planck_grid_wrapper(
        _______, _______________NAV_LEFT_TOP________________, /**/ _______________NAV_RIGHT_TOP_______________, _______,
        _______, _______________NAV_LEFT_MID________________, /**/ _______________NAV_RIGHT_MID_______________, _______,
        _______, _______________NAV_LEFT_BOT________________, /**/ _______________NAV_RIGHT_BOT_______________, _______,
        _______, _______, _______, XXXXXXX, _______, KC_SPC,  /**/ _______, _______, _______, _______, _______, _______
    ),

    /* Test additional layer on the right thumb enter key
    * ,-----------------------------------------------------------------------------------.
    * |______|   !  |   @  |   #  |   $  |   %  |  ^   |   &  |   *  |   (  |   )  |______|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |______|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |______|      |      |      |      |      |      |      |      |______|______|______|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |______|______|______|______|      |      | LAYER|      |______|______|______|______|
    * `-----------------------------------------------------------------------------------'
    */

    [_NUMBERS] = LAYOUT_planck_grid(
        _______, NUM_L4T, NUM_L3T, NUM_L2T, NUM_L1T, NUM_L0T, /**/ NUM_R0T, NUM_R1T, NUM_R2T, NUM_R3T, NUM_R4T, _______,
        _______, NUM_L4M, NUM_L3M, NUM_L2M, NUM_L1M, NUM_L0M, /**/ NUM_R0M, NUM_R1M, NUM_R2M, NUM_R3M, NUM_R4M, _SPARE_,
        _______, NUM_L4B, NUM_L3B, NUM_L2B, NUM_L1B, NUM_L0B, /**/ NUM_R0B, NUM_R1B, NUM_R2B, NUM_R3B, NUM_R4B, _______,
        _______, _______, _______, XXXXXXX, XXXXXXX, _______, /**/ KC_ENT,  XXXXXXX, _______, _______, _______, _______
    ),

    /* Function (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * |Reset |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |PrvWin|      |NxtWin|      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FUNC] = LAYOUT_planck_grid(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, /**/ _______, KC_PWIN, _______, KC_NWIN, _______, KC_F12,
        _______, _______, _______, DM_REC1, DM_REC2, _______, /**/ _______, _______, _______, _______, _______, _______,
        NM_OFF,  _______, _______, XXXXXXX, _______, _______, /**/ _______, _______, _______, _______, _______, _______
    ),

    /* Num Pad Layer
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUMPAD] = LAYOUT_planck_grid(
        XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_7, KC_8, KC_9,   XXXXXXX, KC_BSPC,
        XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, /**/ XXXXXXX, KC_4, KC_5, KC_6,   XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_1, KC_2, KC_3,   KC_ENT,  XXXXXXX,
        _______, _______, _______, _______, XXXXXXX, _______, /**/ _______, KC_0, KC_0, KC_DOT, KC_ENT,  _______
    )
};

// //Keyboard specific layer state code. Mostly moved to userspace
// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     return state;
// }

// //Keyboard specific process record. Mostly moved to userspace
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

// Combos - Moved to userspace

//Leader Keys - Mostly in userspace but can define keyboard specific actions here
// void leader_start_keymap(void) { }
// void leader_end_keymap(void) { }

// Start with LEDs off
void keyboard_post_init_user(void){
#ifndef ZOMBIE_PLANCK
    rgblight_setrgb(0,0,0);
#endif
}

// Housekeeping - Called at the end of a cycle. Update LEDs here
//  LED stuff is only for non-zombies
void housekeeping_task_user(void){
#ifndef ZOMBIE_PLANCK
    if(leader_sequence_active())    rgblight_setrgb(0,255,255);
    else if(IS_NORMAL_MODE_ON())    rgblight_setrgb(255,255,255);
    else if(is_caps_word_on())      rgblight_setrgb(0,0,255);
    else                            rgblight_setrgb(0,0,0);
#endif
}
