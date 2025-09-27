/*
Copyright 2020 Guillaume Gérard

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

enum jj50_layers {
  _NUMPAD = LAYERS_SAFE_RANGE_KB,
};

enum jj50_keycodes {
  QWERTY = SAFE_RANGE,
  MODTAP,
  BACKLIT
};

//Layer defines
#define NUMPAD MO(_NUMPAD)
#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* ,-----------------------------------------------------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |  FN  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_QWERTY] = LAYOUT(
  QK_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    /**/ KC_6,    KC_7,   KC_8,     KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    /**/ KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_DEL,
  KC_TAB,  HM_A,    HM_S,    HM_D,   HM_F,    KC_G,    /**/ KC_H,    HM_J,   HM_K,     HM_L,    HM_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    /**/ KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, NUMPAD, KC_SYMB, NUM_SPC, /**/ KC_ENT,  KC_NAV,  KM_CSHT,  KC_RALT, KC_RGUI, KC_RCTL
),
/* Lower
 * ,-----------------------------------------+-----------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   =  |   [  |   ]  |   (  |  F11 | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |Print |   -  |   (  |   )  |   {  |  F12 |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   {  |   }  | Home |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------+-----------------------------------------'
 */
[_SYMB] = LAYOUT_wrapper(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, _______________SYM_LEFT_TOP________________, /**/ _______________SYM_RIGHT_TOP_______________, KC_F12,
    XXXXXXX, _______________SYM_LEFT_MID________________, /**/ _______________SYM_RIGHT_MID_______________, KC_BSLS,
    _______, _______________SYM_LEFT_BOT________________, /**/ _______________SYM_RIGHT_BOT_______________, _______,
    _______, _______, _______, XXXXXXX, _______, KC_SPC,  /**/ _______, _______, _______, _______, _______, _______
),
[_NAV] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    _______, _______________NAV_LEFT_TOP________________, /**/ _______________NAV_RIGHT_TOP_______________, _______,
    _______, _______________NAV_LEFT_MID________________, /**/ _______________NAV_RIGHT_MID_______________, _______,
    _______, _______________NAV_LEFT_BOT________________, /**/ _______________NAV_RIGHT_BOT_______________, _______,
    _______, _______, _______, _______, _______, KC_SPC,       _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
[_NUMBERS] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    _______, _______________NUM_LEFT_TOP________________, /**/ _______________NUM_RIGHT_TOP_______________, _______,
    _______, _______________NUM_LEFT_MID________________, /**/ _______________NUM_RIGHT_MID_______________, _SPARE_,
    _______, _______________NUM_LEFT_BOT________________, /**/ _______________NUM_RIGHT_BOT_______________, _______,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, /**/ KC_ENT,  XXXXXXX, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Debug| Reset|      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|<Desk |      | Desk>|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT(
  QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  _______, _______, _______, _______, _______, _______, _______, KC_PWIN, _______, KC_NWIN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  NM_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, /**/ XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, /**/ _______, KC_0,    KC_0,    KC_DOT,  KC_ENT,  _______
),

};

//Keyboard specific layer state code. Mostly moved to userspace
layer_state_t layer_state_set_keymap(layer_state_t state) {
    return update_tri_layer_state(state, _SYMB, _NAV, _FUNC);
}

//Keyboard specific preocess record. Mostly moved to userspace
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case MODTAP:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MOD);
          }
          return false;
          break;
    }

    return true;
};

//Start with LEDs off
void keyboard_post_init_user(void){
    rgblight_setrgb(0,0,0);
}

//Housekeeping - Called at the end of a cycle. Update LEDs here
void housekeeping_task_user(void){
    if(leader_sequence_active())    rgblight_setrgb(0,255,255);
    else if(IS_NORMAL_MODE_ON())    rgblight_setrgb(255,255,255);
    else if (is_caps_word_on())     rgblight_setrgb(0,0,255);
    else                            rgblight_setrgb(0,0,0);
}

//Combos - Press multiple keys together as a chord to trigger something else
// Moved to userspace
