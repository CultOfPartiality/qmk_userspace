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
//custom: window during which after typing ". " where a roll from (e.g.) "j" to "w" will trigger a "W" instead of "jw"
#define HOMEROW_SHIFT_TRIGGER_ON_ROLLS_WINDOW 900

//Auto Shift - Only used if autoshift is enabled on a keyboard
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT 170
#define AUTO_SHIFT_NO_SETUP

//Caps Word - Single word capslock.
//  Rather than use the inbuild "BOTH_SHIFTS_TURNS_ON_CAPS_WORD", use combos so the homerow
//  mods work with it without false triggers
#define CAPS_WORD_INVERT_ON_SHIFT

//Combos
#define COMBO_TERM 30
#define COMBO_STRICT_TIMER

//Remove the default tapping term
//  The tapping term is used for a number of timings:
//      - Deciding between layer-tap keystrokes or layer hold action (this is raw)
//      - Homerow mod activations (these take the tapping term below and add/subtract from it)
#undef  TAPPING_TERM
#define TAPPING_TERM 170

//Increase time between register and unregister of automates taps
//Probably helps when using RDP
#undef TAP_CODE_DELAY
#define TAP_CODE_DELAY 30

//Leader key functions
#define LEADER_TIMEOUT 300      //Timeout in milliseconds to hit the sequence
#define LEADER_PER_KEY_TIMING   //Each key in the sequence restarts the timer
#define LEADER_NO_TIMEOUT       //After hitting the leader key, no timeout to start the sequence

//Dynamic Macros
#define DYNAMIC_MACRO_DELAY 10  //Delay between each keystroke

//Layer Lock
#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.
