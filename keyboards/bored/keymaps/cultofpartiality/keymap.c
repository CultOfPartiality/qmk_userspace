#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

// Allows for multi-key definition macros for the keymap in userspace
#define LAYOUT_bored_grid_wrapper(...)   LAYOUT_ortho_5x14(__VA_ARGS__)

enum planck_layers {
  _NUMPAD = LAYERS_SAFE_RANGE_KB
};

//This enum starts after first the standard keycodes, then the userspace keycodes
enum planck_keycodes {
  QWERTY = SAFE_RANGE_KB,
  BACKLIT
};

//Layer key defines
#define NUMPAD MO(_NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    * .---------.-----------------------------------------------------------------------------------.---------.
    * |         | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |         |
    * |---------|------+------+------+------+------+------+------+------+------+------+------+------|---------|
    * |         | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |         |
    * |---------|------+------+------+------+------+-------------+------+------+------+------+------|---------|
    * |         |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |         |
    * |---------|------+------+------+------+------+------|------+------+------+------+------+------|---------|
    * |         | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |         |
    * |---------|------+------+------+------+------+------+------+------+------+------+------+------|---------|
    * |         | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |         |
    * `---------'-----------------------------------------------------------------------------------'---------'
    */
    [_QWERTY] = LAYOUT_ortho_5x14(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ _______, _______, /**/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    /**/ KC_PSCR, _______, /**/ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,    /**/ KC_DEL,  _______, /**/ KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    /**/ KC_F5,   _______, /**/ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMPAD,  KC_SYMB, NUM_SPC, /**/ KC_ENT,  KC_BSPC, /**/ NAV_ENT, KC_NAV,   KM_CSHT, KC_RALT, KC_RGUI, KC_RCTL
    ),


    /* Lower
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
    [_SYMB] = LAYOUT_bored_grid_wrapper(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
    KC_TILD, _______________SYM_LEFT_TOP________________, /**/ _______, _______, /**/ _______________SYM_RIGHT_TOP_______________, KC_DEL,
    KC_DEL,  _______________SYM_LEFT_MID________________, /**/ _______, _______, /**/ _______________SYM_RIGHT_MID_______________, KC_BSLS,
    _______, _______________SYM_LEFT_BOT________________, /**/ _______, _______, /**/ _______________SYM_RIGHT_BOT_______________, _______,
    _______, _______, _______, XXXXXXX, _______, KC_SPC,  /**/ _______, _______, /**/ _______, _______, XXXXXXX, _______, _______, _______
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |Pg Up |LWord |  UP  |RWord |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |Pg Dn |  LF  |  DN  |  RT  |   ]  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home |ISO / | End  |Pg Dn |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_NAV] = LAYOUT_bored_grid_wrapper(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ _______, _______, /**/ KC_6,    KC_7,    KC_8,    KC_UNDS, KC_0,    KC_BSPC,
    _______, _______________NAV_LEFT_TOP________________, /**/ _______, _______, /**/ _______________NAV_RIGHT_TOP_______________, KC_DEL,
    _______, _______________NAV_LEFT_MID________________, /**/ _______, _______, /**/ _______________NAV_RIGHT_MID_______________, KC_BSLS,
    _______, _______________NAV_LEFT_BOT________________, /**/ _______, _______, /**/ _______________NAV_RIGHT_BOT_______________, _______,
    _______, _______, _______, XXXXXXX, _______, KC_SPC,  /**/ _______, _______, /**/ _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_NUMBERS] = LAYOUT_bored_grid_wrapper(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ _______, _______, /**/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    _______, _______________NUM_LEFT_TOP________________, /**/ _______, _______, /**/ _______________NUM_RIGHT_TOP_______________, KC_DEL,
    _______, _______________NUM_LEFT_MID________________, /**/ _______, _______, /**/ _______________NUM_RIGHT_MID_______________, KC_BSLS,
    _______, _______________NUM_LEFT_BOT________________, /**/ _______, _______, /**/ _______________NUM_RIGHT_BOT_______________, _______,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, /**/ _______, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______
    ),

    /* Adjust (Lower + Raise)
    *                      v------------------------RGB CONTROL--------------------v
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FUNC] = LAYOUT_ortho_5x14(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, /**/ _______, _______, /**/ _______, KC_PWIN, _______, KC_NWIN, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, /**/ _______, _______, /**/ _______, _______, _______, _______, _______, _______,
    NM_OFF,  _______, _______, XXXXXXX, _______, KC_SPC,  /**/ _______, _______, /**/ _______, _______, XXXXXXX, _______, _______, _______
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
    [_NUMPAD] = LAYOUT_ortho_5x14(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX,
    _______, _______, _______, _______, XXXXXXX, KC_SPC,  /**/ _______, _______, /**/ _______, KC_0,    KC_0,    KC_DOT,  KC_ENT,  _______
    )

};

// //Keyboard specific layer state code. Mostly moved to userspace
// layer_state_t layer_state_set_keymap(layer_state_t state) {
//     return state;
// }

// //Keyboard specific preocess record. Mostly moved to userspace
// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

//Combos - Press multiple keys together as a chord to trigger something else
//
//Moved to userspace


//Leader Keys - Moved bulk to userspace, can define keyboard specific actions if needed
