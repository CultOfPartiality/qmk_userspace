#pragma once

//Allow Control Escape to work
#define GRAVE_ESC_CTRL_OVERRIDE

//Mouse Keys Configuration
#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL           16      //ms between cursor movements
#define MOUSEKEY_INITIAL_SPEED      100
#define MOUSEKEY_MOVE_DELTA         7       //Speed step size
#define MOUSEKEY_ACCELERATED_SPEED  1400    //?
#define MOUSEKEY_BASE_SPEED         1600    //Max speed at which acceleration stops

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_TERM_PER_KEY
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define QUICK_TAP_TERM_PER_KEY
#define QUICK_TAP_TERM 50

//Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 170
#define AUTO_SHIFT_NO_SETUP

//Caps Word - Single word capslock.
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_INVERT_ON_SHIFT

//Combos
#define COMBO_TERM 20
#define COMBO_STRICT_TIMER

//Remove the default tapping term
//  The tapping term is used for a number of timings:
//      - Deciding between layer-tap keystrokes or layer hold action (this is raw)
//      - Homerow mod activations (these take the tapping term below and add/subtract from it)
#undef  TAPPING_TERM
#define TAPPING_TERM 170

//Increase time between register and unregister of automates taps
#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 5


