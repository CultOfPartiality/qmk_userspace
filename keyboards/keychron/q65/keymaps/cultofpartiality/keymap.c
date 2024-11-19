/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum q65_layers{
    MAC_BASE = LAYERS_SAFE_RANGE_KB,
    _FN1,
    _FN2,
    _FN3
};

#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT LAYERS_SAFE_RANGE_KB+3

#undef DIP_SWITCH_ENABLE

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

//  The following define allows for multi-key definition macros
#define LAYOUT_ansi_73_wrapper(...)   LAYOUT_ansi_73(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_73(
        KC_MUTE, QK_GESC, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_DEL,
        _______, KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_HOME,
        _______, KC_TAB,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_PGUP,
        _______, KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_PGDN,
        _______, KC_LCTL, KC_LOPT,  KC_LCMD,                             KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_QWERTY] = LAYOUT_ansi_73(
        KC_MUTE, QK_GESC, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_DEL,
        _______, KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_HOME,
        _______, KC_TAB,  HM_A,     HM_S,     HM_D,    HM_F,    KC_G,    KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN,  KC_QUOT,            KC_ENT,           KC_PGUP,
        _______, KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,   KC_PGDN,
        _______, KC_LCTL, KC_LWIN,  KC_LALT,                             NAV_SPC,                            KC_RALT,  MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_NAV] = LAYOUT_ansi_73_wrapper(
        KC_MUTE, QK_GESC, KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_DEL,
        _______, _______, KC_Q,     _______________NAV_LEFT_TOP________________,  _______________NAV_RIGHT_TOP_______________,   KC_RBRC,  KC_BSLS,          KC_HOME,
        _______, _______, HM_A,     _______________NAV_LEFT_MID________________,  _______________NAV_RIGHT_MID_______________,             KC_ENT,           KC_PGUP,
        _______, _______,           _______________NAV_LEFT_BOT________________,  _______________NAV_RIGHT_BOT_______________,             KC_RSFT, KC_UP,   KC_PGDN,
        _______, _______, _______,  _______,                             KC_SPC,                             KC_RALT,  MO(_FN2), MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),



    [_FN1] = LAYOUT_ansi_73(
        RGB_TOG, KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        _______, RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______, _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, _______, _______,
        _______, _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN2] = LAYOUT_ansi_73(
        RGB_TOG, KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        _______, RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______, _______,           _______,  _______, _______, _______, _______, NK_TOGG, _______, _______, _______,  _______,            _______, _______, _______,
        _______, _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN3] = LAYOUT_ansi_73(
        QK_BOOT, KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______, RGB_RMOD, RGB_VAD,  RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______, _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, _______, _______,
        NM_OFF,  _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FN1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_FN3] = { ENCODER_CCW_CW(_______, _______)}
};
#endif // ENCODER_MAP_ENABLE
