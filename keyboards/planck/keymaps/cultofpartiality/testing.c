
#include QMK_KEYBOARD_H

#ifdef TESTING
/*TESTING ZONE*/
// Tap Dance declarations
enum {
    TD_Ctrl_A,
};

void dance_ctrl_a(tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_Ctrl_A] = ACTION_TAP_DANCE_FN(dance_ctrl_a)
};

void dance_ctrl_a(tap_dance_state_t *state, void *user_data){
    switch (state->count) {
        case 1:
            tap_code(KC_A);
            break;
        case 2:
            tap_code16(C(KC_A));
            break;
    }
}

/*END TESTING ZONE*/
#endif
