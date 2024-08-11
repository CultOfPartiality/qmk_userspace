
#include QMK_KEYBOARD_H
#include "cultofpartiality.h"

// Keyboard Specific Enums - Layers and Keycodes
// Most of the standard bits are defined in the userspace, so only extras need to be defined here
// Each starts after the *SAFE_RANGE_KB, which is the enum in the userspace, which starts after *SAFE_RANGE
enum custom_keycodes {
  QWERTY = SAFE_RANGE_KB,
};
enum layer_names{
    _NUMPAD = LAYERS_SAFE_RANGE_KB,
    _MOUSE,
    _SETTINGS
};

//Layer keycode defines
#define NUMPAD MO(_NUMPAD)

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_redox_wrapper(...)   LAYOUT(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_PSCR,                           XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    KC_DEL,                            KC_RBRC, KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_F5,           KC_UP,   KC_DOWN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_LGUI, KC_LALT, NUMPAD,       KC_SYMB,     NUM_SPC, MOU_ENT,         KC_BSPC, KC_ENT,      KC_NAV,          KM_CSHT, KC_EQL,  KC_RGUI, KC_RCTL
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_GRV,  XXXXXXX, SA_TAB,  A_TAB,   XXXXXXX, _______,                           _______, KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_PSCR, _______,                           _______, KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, DM_PLY1, DM_PLY2, XXXXXXX, _______, _______,         _______, _______, XXXXXXX, XXXXXXX	,XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______,      _______,     KC_SPC, _______,         _______, _______,     _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T, _______,                           _______, NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M, _______,                           _______, NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B, _______, _______,         _______, XXXXXXX, NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, XXXXXXX,      _______,     KC_SPC,  _______,         _______, _______,     _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX,                           XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, KC_PWIN, XXXXXXX, KC_NWIN, XXXXXXX, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1, DM_REC2, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     NM_OFF,  XXXXXXX, XXXXXXX, XXXXXXX,      _______,     XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,     _______,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUMBERS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, NUM_L4T, NUM_L3T, NUM_L2T, NUM_L1T, NUM_L0T, XXXXXXX,                           XXXXXXX, NUM_R0T, NUM_R1T, NUM_R2T, NUM_R3T, NUM_R4T, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, NUM_L4M, NUM_L3M, NUM_L2M, NUM_L1M, NUM_L0M, XXXXXXX,                           XXXXXXX, NUM_R0M, NUM_R1M, NUM_R2M, NUM_R3M, NUM_R4M, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, NUM_L4B, NUM_L3B, NUM_L2B, NUM_L1B, NUM_L0B, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, NUM_R0B, NUM_R1B, NUM_R2B, NUM_R3B, NUM_R4B, _______,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, _______,      XXXXXXX,     _______, XXXXXXX,         _______, KC_ENT,      _______,      _______, _______, _______, _______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX,                           XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX, _______,         KC_BTN1, KC_BTN3,     KC_BTN2,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, KC_EQL,  KC_PSLS, KC_PAST, KC_PMNS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PPLS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PENT, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, _______,      XXXXXXX,     XXXXXXX, XXXXXXX,         XXXXXXX, _______,     KC_0,         KC_0,    KC_DOT,  KC_PENT, XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SETTINGS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};

layer_state_t highest_layer = 0;

//Keyboard specific layer state code. Mostly moved to userspace
layer_state_t layer_state_set_keymap(layer_state_t state) {
    //Map the highest layer out to be used by LEDs
    highest_layer = get_highest_layer(state);
    return state;
}

//Housekeeping - Called at the end of a cycle. Update LEDs here
void housekeeping_task_user(void){
    if(leader_sequence_active()){
        red_led_on;
        blu_led_on;
    }
    else if(is_caps_word_on() || host_keyboard_led_state().caps_lock){
        red_led_on;
        grn_led_on;
        blu_led_on;
    }
    else if (highest_layer > _MOD){
        switch (highest_layer) {
            case _SYMB:
                set_led_green;
                break;
            case _NAV:
                set_led_blue;
                break;
            default:
                set_led_red;
                break;
        }
    }
    else{
        set_led_off;
    }

}

//Combos - Moved to userspace
