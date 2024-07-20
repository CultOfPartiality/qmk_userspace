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
    _BUTTON = LAYERS_SAFE_RANGE_KB,
    _MOUSE,
};
// enum keycodes {
//   A_TAB = SAFE_RANGE_KB,
//   SA_TAB,
// };

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_split_3x6_4_wrapper(...)   LAYOUT_split_3x6_4(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY]   = LAYOUT_split_3x6_4(
    /*  -------, -------, -------, -------, -------, -------, -------, -------, /##/ -------, -------, -------, -------, -------, -------, -------, -------,*/
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      /**/                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                      /**/                   KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, HM_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      /**/                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_1,    SYM_ESC, NUM_SPC, MOU_ENT, /**/ KC_BSPC, NAV_ENT, NAV_DEL, KC_2
    ),

    [_NAV]    = LAYOUT_split_3x6_4_wrapper(
    /*  -------, -------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------, -------,*/
        _______, _______________NAV_LEFT_TOP________________,                  /**/                   _______________NAV_RIGHT_TOP_______________, _______,
        _______, _______________NAV_LEFT_MID________________,                  /**/                   _______________NAV_RIGHT_MID_______________, _______,
        _______, _______________NAV_LEFT_BOT________________,                  /**/                   _______________NAV_RIGHT_BOT_______________, _______,
                                            _______, SYM_ESC, KC_SPC,  KC_ENT, /**/ U_NA,    U_NA,    U_NA,    _______
    ),

    [_SYMB]    = LAYOUT_split_3x6_4_wrapper(
    /*  -------, -------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------, -------,*/
        _______, _______________SYM_LEFT_TOP________________,                  /**/                   _______________SYM_RIGHT_TOP_______________, _______,
        _______, _______________SYM_LEFT_MID________________,                  /**/                   _______________SYM_RIGHT_MID_______________, KC_BSLS,
        _______, _______________SYM_LEFT_BOT________________,                  /**/                   _______________SYM_RIGHT_BOT_______________, _______,
                                            _______, U_NA,    U_NA,    U_NA,   /**/ KC_BSPC, KC_ENT,  NAV_DEL, _______
    ),

    [_NUMBERS]    = LAYOUT_split_3x6_4_wrapper(
      /*-------, -------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------, -------,*/
        _______, _______________NUM_LEFT_TOP________________,                  /**/                   _______________NUM_RIGHT_TOP_______________, _______,
        _______, _______________NUM_LEFT_MID________________,                  /**/                   _______________NUM_RIGHT_MID_______________, _______,
        _______, _______________NUM_LEFT_BOT________________,                  /**/                   _______________NUM_RIGHT_BOT_______________, _______,
                                            _______, U_NA,    U_NA,    U_NA,   /**/ KC_BSPC, KC_ENT,  KC_DEL, _______
    ),

    [_FUNC]    = LAYOUT_split_3x6_4(
    /*-------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                    /**/                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, _______,
        _______, U_NU,    SA_TAB,  U_NU,    A_TAB,   U_NU,                     /**/                   U_NU,    KC_PWIN, U_NU,    KC_NWIN, KC_F11, _______,
        NM_OFF,  DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, U_NU,                     /**/                   U_NU,    U_NU,    U_NU,    U_NU,    KC_F12, _______,
                                             _______, U_NA,    U_NA,    U_NA,   /**/ U_NA,    U_NA,    U_NA, _______
    ),

    [_MOUSE]  = LAYOUT_split_3x6_4(
    /*-------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        _______, QK_BOOT, U_NU,     U_NU,   U_NU,    U_NU,                     /**/                   U_NU,    KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,
        _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, U_NU,                     /**/                   U_NU,    KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
        _______, U_NU,    KC_ALGR, U_NU,    U_NU,    U_NU,                     /**/                   U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    _______,
                                             _______, U_NA,    U_NA,    U_NA,   /**/ KC_BTN1, KC_BTN3, KC_BTN2, _______
    ),

    //Why is this still here?
    [_BUTTON] = LAYOUT_split_3x6_4(
    /*-------, -------, -------, -------, -------, -------, -------,/##/ -------, -------, -------, -------, -------, -------, -------,*/
        _______, KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, KC_REDO,                  /**/                   KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, KC_REDO, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                    /**/                   KC_NO,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
        _______, KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, KC_REDO,                  /**/                   KM_UNDO, KM_CUT,  KM_COPY, KM_PAST, KC_REDO, _______,
                                             _______, KC_BTN2, KC_BTN3, KC_BTN1,/**/ KC_BTN1, KC_BTN3, KC_BTN2, _______
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
//  - Caps Word:    Homerow Shifts = Trigger Caps Word
//  - Homerow Tab:

const uint16_t PROGMEM combo_homerowShiftsCapsWord[] = {HM_F, HM_J, COMBO_END};
const uint16_t PROGMEM combo_leaderKey2[] = {HM_S, HM_D, COMBO_END};
const uint16_t PROGMEM combo_homerowTab[] = {HM_A, HM_S, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(combo_homerowShiftsCapsWord),
    COMBO(combo_leaderKey2,QK_LEAD),
    COMBO(combo_homerowTab,KC_TAB),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed)
        caps_word_on();
      break;
  }
}
