#include QMK_KEYBOARD_H
#include "cultofpartiality.h"

// Keyboard Specific Enums - Layers and Keycodes
// Most of the standard bits are defined in the userspace, so only extras need to be defined here
// Each starts after the *SAFE_RANGE_KB, which is the enum in the userspace, which starts after *SAFE_RANGE

enum sofle_layers {
	_MOUSE = LAYERS_SAFE_RANGE_KB
};

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_sofle_wrapper(...)   LAYOUT(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(\
    QK_GESC, KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                       KC_6,   KC_7,     KC_8,    KC_9,    KC_0,    KC_BSPC, \

    QK_GESC, KC_Q,  KC_W,    KC_E,    KC_R,     KC_T,                      KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_TAB,  HM_A,  HM_S,    HM_D,    HM_F,     KC_G,                      KC_H,   HM_J,     HM_K,    HM_L,    HM_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,     KC_B,   KC_MUTE,  XXXXXXX, KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                    XXXXXXX, XXXXXXX, SYM_ESC, NUM_SPC, MOU_ENT,  KC_BSPC, NAV_ENT, NAV_DEL, XXXXXXX, XXXXXXX    \
    ),

    [_SYMB] = LAYOUT_sofle_wrapper( \
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \

    KC_GRV,  _______________SYM_LEFT_TOP________________,                          _______________SYM_RIGHT_TOP_______________, _______,  \
    _______, _______________SYM_LEFT_MID________________,                          _______________SYM_RIGHT_MID_______________, KC_BSLS, \
    _______, _______________SYM_LEFT_BOT________________, _______,        _______, _______________SYM_RIGHT_BOT_______________, _______, \
                        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,      _______, _______, LT(_NAV, KC_DEL), _______, _______\
    ),

    [_NAV] = LAYOUT_sofle_wrapper( \
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_UNDS, _______, KC_BSPC, \

    _______, _______________NAV_LEFT_TOP________________,                        _______________NAV_RIGHT_TOP_______________, _______, \
    _______, _______________NAV_LEFT_MID________________,                        _______________NAV_RIGHT_MID_______________, _______, \
    _______, _______________NAV_LEFT_BOT________________, _______,       _______,_______________NAV_RIGHT_BOT_______________, _______, \
                        _______, _______, LT(_SYMB, KC_ESC), _______, _______,       XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______ \
    ),

    [_NUMBERS] = LAYOUT_sofle_wrapper( \
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, KC_UNDS, _______, KC_BSPC, \

    _______, _______________NUM_LEFT_TOP________________,                        _______________NUM_RIGHT_TOP_______________, _______, \
    _______, _______________NUM_LEFT_MID________________,                        _______________NUM_RIGHT_MID_______________, _______, \
    _______, _______________NUM_LEFT_BOT________________, _______,       _______,_______________NUM_RIGHT_BOT_______________, _______, \
                      _______, _______, XXXXXXX, _______, XXXXXXX,       KC_BSPC, KC_ENT, KC_DEL,  _______, _______ \
    ),

    [_FUNC] = LAYOUT( \
    QK_BOOT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \

    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, KC_PWIN, XXXXXXX, KC_NWIN, XXXXXXX, KC_F12, \
    NM_OFF,  DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                      _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______ \
    ),

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
        trigger_caps_funcs();
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

#ifdef OLED_ENABLE

static void print_status_narrow_user(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    if (IS_NORMAL_MODE_ON()){
		oled_write_ln_P(PSTR("NORM"), false);
        oled_write_P(PSTR("MOD"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Func\n"), false);
            break;
        case _NUMBERS:
            oled_write_P(PSTR("Nums\n"), false);
            break;
		case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), true);
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("CPSWD"), is_caps_word_on());
}

static void render_logo_user(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow_user();
    } else {
        render_logo_user();
    }
    return false;
}

#endif
