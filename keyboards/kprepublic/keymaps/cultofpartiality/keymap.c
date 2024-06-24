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
[_SYMB] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  XXXXXXX, SYM_L4T, SYM_L3T, SYM_L2T, SYM_L1T, SYM_L0T, /**/ SYM_R0T, SYM_R1T, SYM_R2T, SYM_R3T, SYM_R4T, KC_F12,
  XXXXXXX, SYM_L4M, SYM_L3M, SYM_L2M, SYM_L1M, SYM_L0M, /**/ SYM_R0M, SYM_R1M, SYM_R2M, SYM_R3M, SYM_R4M, KC_BSLS,
  _______, SYM_L4B, SYM_L3B, SYM_L2B, SYM_L1B, SYM_L0B, /**/ SYM_R0B, SYM_R1B, SYM_R2B, SYM_R3B, SYM_R4B, _______,
  _______, _______, _______, XXXXXXX, _______, KC_SPC, /**/ _______, _______, _______, _______, _______, _______
),
/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   _  |   0  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Up|PrvWrd|  Up  |NxtWrd|      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Dw| Left | Down |Right |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |      | Home |      | End  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------|-----------------------------------------'
 */
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,      KC_6,    KC_7,    KC_8,    KC_UNDS, KC_0,    KC_BSPC,
  _______, NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T, /**/ NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, KC_DEL,
  _______, NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M, /**/ NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, KC_BSLS,
  _______, NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B, /**/ NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______,
  _______, _______, _______, _______, _______, KC_SPC,       _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_NUMBERS] = LAYOUT(
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______,
  _______, NUM_L4T, NUM_L3T, NUM_L2T, NUM_L1T, NUM_L0T, /**/ NUM_R0T, NUM_R1T, NUM_R2T, NUM_R3T, NUM_R4T, _______,
  _______, NUM_L4M, NUM_L3M, NUM_L2M, NUM_L1M, NUM_L0M, /**/ NUM_R0M, NUM_R1M, NUM_R2M, NUM_R3M, NUM_R4M, _SPARE_,
  _______, NUM_L4B, NUM_L3B, NUM_L2B, NUM_L1B, NUM_L0B, /**/ NUM_R0B, NUM_R1B, NUM_R2B, NUM_R3B, NUM_R4B, _______,
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
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,
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
//Indicate state of Caps Word
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_setrgb(0,0,255);
    } else {
        rgblight_setrgb(0,0,0);
    }
}

//Combos - Press multiple keys together as a chord to trigger something else
//
// Currently defined:
//  - Caps Word:     Homerow Shifts = Trigger Caps Word
//                   Both Normal Shifts = Trigger Caps Word
//  - Planck Delete: P + Backspace = Delete
//  - Leader Key:    S + D? Not sure on this combo

const uint16_t PROGMEM combo_homerowShiftsCapsWord[] = {HM_F, HM_J, COMBO_END};
const uint16_t PROGMEM combo_bothShiftsCapsWord[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM combo_leaderKey1[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_leaderKey2[] = {HM_S, HM_D, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(combo_homerowShiftsCapsWord),
    COMBO_ACTION(combo_bothShiftsCapsWord),
    COMBO(combo_leaderKey1,QK_LEAD),
    COMBO(combo_leaderKey2,QK_LEAD),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
    case 1:
      if (pressed) {
        caps_word_on();
      }
      break;
  }
}
