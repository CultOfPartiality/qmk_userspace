#pragma once

// Each layer gets a name for readability, in an enum to ensure unique numbering
enum layer_names{
    _NUMPAD = LAYERS_SAFE_RANGE_KB,
    _MOUSE,
    _SETTINGS

};

// Custom keycodes
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MOD_ENA,
  MOD_DIS,
};

/* Shortcuts to make keymap more readable */

//Layer changes
#define SYM_L   MO(_SYMB)
#define NAV_L   MO(_NAV)
#define SET_L   MO(_SETTINGS)
#define NUM_L   MO(_NUMPAD)
#define MOUSE   MO(_MOUSE)
