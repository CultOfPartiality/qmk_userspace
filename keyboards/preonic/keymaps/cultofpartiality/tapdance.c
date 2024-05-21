#include "tapdance.h"
#include QMK_KEYBOARD_H
#include "defines.h"

/////////////////////
//tap dance stuff
/////////////////////

// Initialize tap structure associated with tap dance keys
static td_tap_t raise_tap_state = {
    .is_press_action = true,
    .state = TD_NONE,
	.layer = _NAV
};
static td_tap_t lower_tap_state = {
    .is_press_action = true,
    .state = TD_NONE,
	.layer = _SYMB
};

// Determine the current tap dance state
td_state_t cur_dance_layer(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2){
		if (!state->pressed) return TD_DOUBLE_TAP;
		else return TD_UNKNOWN;
	}
    else return TD_UNKNOWN;
}

void td_layer_key_finished(qk_tap_dance_state_t *state, void *user_data){
	//The specific layer is stored in the user data
	td_tap_t* TapDanceData = (td_tap_t *)user_data;
	TapDanceData->state = cur_dance_layer(state);
    switch (TapDanceData->state) {
        case TD_SINGLE_TAP:
            set_oneshot_layer(TapDanceData->layer,ONESHOT_START);
            break;
        case TD_SINGLE_HOLD:
            layer_on(TapDanceData->layer);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(TapDanceData->layer)) {
                // If already set, then switch it off
                layer_off(TapDanceData->layer);
            } else {
                // If not already set, then switch the layer on
                layer_on(TapDanceData->layer);
            }
            break;
        default:
            break;
    }
	update_tri_layer(_SYMB, _NAV, _FUNC);
}

void td_layer_key_reset(qk_tap_dance_state_t *state, void *user_data) {
	//The specific layer is stored in the user data
	td_tap_t* TapDanceData = (td_tap_t *)user_data;
    // If the key was held down and now is released then switch off the layer
    switch(TapDanceData->state){
		case TD_SINGLE_TAP:
			clear_oneshot_layer_state(ONESHOT_PRESSED);
			break;
		case TD_SINGLE_HOLD:
			layer_off(TapDanceData->layer);
			break;
		default:
            break;
    }
    TapDanceData->state = TD_NONE;
	update_tri_layer(_SYMB, _NAV, _FUNC);
}


#define ACTION_TAP_DANCE_LAYER_CONTROL(td_tap_t_layer){ \
			.fn = {NULL, td_layer_key_finished, td_layer_key_reset},\
			.user_data = (void *)&(td_tap_t_layer),\
			.custom_tapping_term = 150\
		}

#define ACTION_TAP_DANCE_ALPHA(td_tap_t_alpha){ \
			.fn = {NULL, td_alpha_key_finished, td_alpha_key_reset},\
			.user_data = (void *)&(td_tap_t_alpha),\
			.custom_tapping_term = 185\
		}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
	//Layer control
	[TD_NAV] = ACTION_TAP_DANCE_LAYER_CONTROL(raise_tap_state),
	[TD_SYMB] = ACTION_TAP_DANCE_LAYER_CONTROL(lower_tap_state)
};
