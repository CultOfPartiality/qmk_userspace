#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
	TD_DOUBLE_HOLD,
	TD_TRIPLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
	int layer;
	int keycode;
} td_tap_t;

// Tap dance "keys"
enum td_keycodes {
	TD_SYMB,
	TD_NAV
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void td_layer_key_finished(qk_tap_dance_state_t *state, void *user_data);
void td_layer_key_reset(qk_tap_dance_state_t *state, void *user_data);
