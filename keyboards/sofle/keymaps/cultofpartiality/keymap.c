#include QMK_KEYBOARD_H
#include "cultofpartiality.h"

// Keyboard Specific Enums - Layers and Keycodes
// Most of the standard bits are defined in the userspace, so only extras need to be defined here
// Each starts after the *SAFE_RANGE_KB, which is the enum in the userspace, which starts after *SAFE_RANGE
// ***Moved to defines for oled stuff***
#include "defines.h"

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_sofle_wrapper(...)   LAYOUT(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * NORMAL
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |Space | /Lower  /       \RAISE \  |ENTER | RCTR |  -   |  =   |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_QWERTY] = LAYOUT( \
    QK_GESC,   KC_1,  KC_2,    KC_3,    KC_4,     KC_5,                      KC_6,   KC_7,     KC_8,    KC_9,   KC_0,    KC_BSPC, \

    QK_GESC,   KC_Q,  KC_W,    KC_E,    KC_R,     KC_T,                      KC_Y,   KC_U,     KC_I,    KC_O,   KC_P,    KC_BSPC,  \
    KC_TAB,    KC_A,  KC_S,    KC_D,    KC_F,     KC_G,                      KC_H,   KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
    KC_LSFT,   KC_Z,  KC_X,    KC_C,    KC_V,     KC_B,   KC_MUTE,  XXXXXXX, KC_N,   KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
                        XXXXXXX, XXXXXXX, SYM_ESC, NUM_SPC, MOU_TAB,  KC_BSPC, LT(_NUMBERS, KC_ENT), NAV_DEL, XXXXXXX, XXXXXXX    \
    ),
    /*
    * NORMAL with homerow mods
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |Space | /Lower  /       \RAISE \  |ENTER | RCTR |  -   |  =   |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_MOD] = LAYOUT( \
    QK_GESC, KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                       KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC, \

    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,     KC_G,                       KC_H,   HM_J,     HM_K,    HM_L,    HM_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_MUTE,  XXXXXXX, KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                        XXXXXXX, XXXXXXX, SYM_ESC, NUM_SPC, MOU_TAB,  KC_BSPC, LT(_NUMBERS, KC_ENT), NAV_DEL, XXXXXXX, XXXXXXX    \
    ),

    /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  `   |      |      |      |      |      |                    |   =  |   [  |   ]  |      |      | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   -  |   (  |   )  |      |      |   |  |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|      |   {  |   }  |      |   \  | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_SYMB] = LAYOUT( \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \

    KC_GRV,  XXXXXXX, XXXXXXX, SA_TAB,  A_TAB,   XXXXXXX,                          KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, _______,  \
    _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_PSCR,                          KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, KC_BSLS, \
    _______, KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, XXXXXXX, _______,        _______, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, KC_BSLS, _______, \
                        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,      _______, _______, LT(_NAV, KC_DEL), _______, _______\
    ),
    /* RAISE
    * ,----------------------------------------.                     ,-----------------------------------------.
    * | Esc  |      |      |      |      |      |                    |      |      |      |  _   |      | Bspc |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| DEL  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del |      |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'            '------''---------------------------'
    */
    [_NAV] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_UNDS, _______, KC_BSPC, \

    _______, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, _______, \
    _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX,                        NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, _______, \
    _______, KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, XXXXXXX, _______,       _______,NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______, \
                        _______, _______, LT(_SYMB, KC_ESC), _______, _______,       XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______ \
    ),

    [_NUMBERS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_UNDS, _______, KC_BSPC, \

    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
    _______, KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, XXXXXXX, _______,       _______,XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_SLSH, _______, \
                        _______, _______, XXXXXXX, _______, XXXXXXX,       KC_BSPC, KC_ENT, KC_DEL,  _______, _______ \
    ),
    /* ADJUST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |MACWIN|      |      |      |-------.    ,-------|      |desk <|      |desk >|      |      |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_FUNC] = LAYOUT( \
    QK_BOOT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \

    XXXXXXX , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, KC_PWIN, XXXXXXX, KC_NWIN, XXXXXXX, KC_F12, \
    XXXXXXX , DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                        _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
    ),
    /* MOUSE
    */
    [_MOUSE] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                     KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX ,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, \
    XXXXXXX, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, XXXXXXX , XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , _______,   KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX \
    )
};

// //Keyboard specific layer state code. Mostly moved to userspace
// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     return state;
// }

//Keyboard specific process record. Mostly moved to userspace
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

//Combos - Press multiple keys together as a chord to trigger something else
//
// Currently defined:
//  - Caps Word:     Homerow Shifts = Trigger Caps Word
//                   Both Normal Shifts = Trigger Caps Word
//  - Leader Key:    S + D? Not sure on this combo

const uint16_t PROGMEM combo_homerowShiftsCapsWord[] = {HM_F, HM_J, COMBO_END};
const uint16_t PROGMEM combo_bothShiftsCapsWord[] = {KC_LSFT, KC_RSFT, COMBO_END};
const uint16_t PROGMEM combo_leaderKey1[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_leaderKey2[] = {HM_S, HM_D, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(combo_homerowShiftsCapsWord),
    COMBO_ACTION(combo_bothShiftsCapsWord),
    COMBO(combo_leaderKey1,QK_LEAD),
    COMBO(combo_leaderKey2,QK_LEAD)
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

//Leader Keys - Mostly in userspace but can define keyboard specific actions here
// void leader_start_keymap(void) {
//     return;
// }
// void leader_end_keymap(void) {
//     return;
// }
