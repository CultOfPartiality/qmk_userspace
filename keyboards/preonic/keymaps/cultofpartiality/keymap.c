// Normal QMK keyboard include and Userspace
#include QMK_KEYBOARD_H
#include "cultofpartiality.h"

// Keyboard Specific Enums - Layers and Keycodes
// Most of the standard bits are defined in the userspace, so only extras need to be defined here
// Each starts after the *SAFE_RANGE_KB, which is the enum in the userspace, which starts after *SAFE_RANGE
// enum preonic_layers {
//   _CUSTOM = LAYERS_SAFE_RANGE_KB
// };
enum preonic_keycodes {
  BACKLIT = SAFE_RANGE_KB,
};

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_preonic_grid_wrapper(...)   LAYOUT_ortho_5x12(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty (with or without Homerow mods)
    * ,-----------------------------------------------------------------------------------.
    * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_ortho_5x12(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    /**/ KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_DEL,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    /**/ KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    /**/ KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SYMB, KC_SYMB, NUM_SPC, /**/ KC_ENT,  KC_NAV,   KM_CSHT,  KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_MOD] = LAYOUT_ortho_5x12(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    /**/ KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_DEL,
    KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    /**/ KC_H,    HM_J,     HM_K,     HM_L,    HM_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    /**/ KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SYMB, KC_SYMB, NUM_SPC, /**/ KC_ENT,  KC_NAV,   KM_CSHT,  KC_RALT, KC_RGUI, KC_RCTL
    ),

    /* Lower - Symbols
    *      Standardised easy-access keys from userspace to keep all boards in sync
    * ,-----------------------------------------+-----------------------------------------.
    * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------+-----------------------------------------'
    */
    [_SYMB] = LAYOUT_preonic_grid_wrapper(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    XXXXXXX, _______________SYM_LEFT_TOP________________, /**/ _______________SYM_RIGHT_TOP_______________, KC_F12,
    XXXXXXX, _______________SYM_LEFT_MID________________, /**/ _______________SYM_RIGHT_MID_______________, KC_BSLS,
    _______, _______________SYM_LEFT_BOT________________, /**/ _______________SYM_RIGHT_BOT_______________, _______,
    _______, _______, _______, _______, _______, KC_SPC,  /**/ _______, _______, _______, _______, _______, _______
    ),

    /* Raise - Navigation
    *      Standardised easy-access keys from userspace to keep all boards in sync
    * ,-----------------------------------------|-----------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   _  |   0  | Bksp |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------|-----------------------------------------'
    */
    [_NAV] = LAYOUT_preonic_grid_wrapper(
    _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
    _______, _______________NAV_LEFT_TOP________________, /**/ _______________NAV_RIGHT_TOP_______________, _______,
    _______, _______________NAV_LEFT_MID________________, /**/ _______________NAV_RIGHT_MID_______________, _______,
    _______, _______________NAV_LEFT_BOT________________, /**/ _______________NAV_RIGHT_BOT_______________, _______,
    _______, _______, _______, _______, _______, KC_SPC,       _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

    [_NUMBERS] = LAYOUT_preonic_grid_wrapper(
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
    [_FUNC] = LAYOUT_ortho_5x12(
    QK_BOOT, KC_F2,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, KC_PWIN, _______, KC_NWIN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    NM_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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

//Combos
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

//Leader Keys - Mostly in userspace but can define keyboard specific actions here
// void leader_start_keymap(void) {
// }
// void leader_end_keymap(void) {
// }

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
