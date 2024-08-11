#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

// Split sections into different file for clarity
#include "defines.h"

//  The following define allows for multi-key definition macros
#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   /**/                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,

    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   /**/                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                   /**/                     KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   /**/                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

    KC_LCTL, KC_LGUI, KC_LALT, KC_V,                                     /**/                                        KM_CSHT, KC_EQL,  KC_RGUI, KC_RCTL,
                                    SYM_ESC, NUM_SPC, MOU_TAB,  KC_PGUP, /**/ KC_1,    KC_BSPC,   NAV_ENT, NAV_DEL,
                                                      KC_DEL,   KC_PGDN, /**/ KC_5,    KC_6
    ),
    [_SYMB] = LAYOUT_wrapper(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          /**/                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,

    _______, _______________SYM_LEFT_TOP________________,                        /**/                       _______________SYM_RIGHT_TOP_______________, KC_F12,
    _______, _______________SYM_LEFT_MID________________,                        /**/                       _______________SYM_RIGHT_MID_______________, KC_BSLS,
    _______, _______________SYM_LEFT_BOT________________,                        /**/                       _______________SYM_RIGHT_BOT_______________, _______,
    _______, _______, _______, _______,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, _______, _______, _______, /**/ _______, _______, _______, NAV_DEL,
                                                                _______, _______, /**/ _______, _______
    ),
    [_NAV] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,                        /**/                       _______, _______, _______, _______, _______, _______,

    XXXXXXX, _______________NAV_LEFT_TOP________________,                        /**/                       _______________NAV_RIGHT_TOP_______________, _______,
    XXXXXXX, _______________NAV_LEFT_MID________________,                        /**/                       _______________NAV_RIGHT_MID_______________, XXXXXXX,
    _______, _______________NAV_LEFT_BOT________________,                        /**/                       _______________NAV_RIGHT_BOT_______________, _______,
    _______, _______, _______, _______,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                SYM_ESC, _______, _______, _______, /**/ _______, _______, _______, _______,
                                                                _______, _______, /**/ _______, _______
    ),
    [_FUNC] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          /**/                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, KC_PWIN, XXXXXXX, KC_NWIN, XXXXXXX, KC_F12,
    NM_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                _______, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                                XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX
    ),
    [_NUMBERS] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    _______, _______________NUM_LEFT_TOP________________,                        /**/                       _______________NUM_RIGHT_TOP_______________, _______,
    _______, _______________NUM_LEFT_MID________________,                        /**/                       _______________NUM_RIGHT_MID_______________, _______,
    _______, _______________NUM_LEFT_BOT________________,                        /**/                       _______________NUM_RIGHT_BOT_______________, _______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                XXXXXXX, _______, XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_BSPC,   KC_ENT,  KC_DEL,
                                                                XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX
    ),
    [_MOUSE] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                XXXXXXX, XXXXXXX, XXXXXXX, _______, /**/ XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2,
                                                                XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX
    )
};

// //Keyboard specific layer state code. Mostly moved to userspace
// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     return state;
// }

//Keyboard specific preocess record. Mostly moved to userspace
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

//Combos - Press multiple keys together as a chord to trigger something else
// Moved to userspace
