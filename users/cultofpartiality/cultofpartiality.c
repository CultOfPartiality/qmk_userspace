#include "cultofpartiality.h"

////// Global state
bool gNornalModeActive = false;

////// Global process record user

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //If caps word is enabled, we don't want to send the escape keystroke that turns it off
        case KC_ESC:
        case QK_GESC:
            if (is_caps_word_on()){
                caps_word_off();
                return false;
            }
            return true;

        // Register alt, tap Tab, unregister alt when SYMB layer turns off
        case A_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_TAB);
            }
            return false;

        // Register alt, tap Shift-Tab, unregister alt when SYMB layer turns off
        case SA_TAB:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code16(S(KC_TAB));
            }
            return false;

        //Turn on/off normal mode
        case NM_ON:
            if (record->event.pressed) {
                ACTIVATE_NORMAL_MODE();
            }
            return false;
        case NM_OFF:
            if (record->event.pressed) {
                DEACTIVATE_NORMAL_MODE();
            }
            return false;

        // Treat this only as a space key if in normal mode
        case NUM_SPC:
            if( IS_NORMAL_MODE_ON() ) {
                if(record->event.pressed) register_code(KC_SPC);
                else                      unregister_code(KC_SPC);
                return  false;
            }

        // If normal mode is active, then don't use the homerow mods
        case HM_A:
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_SCLN:
        case HM_QUOT:
        case HM_L:
        case HM_K:
        case HM_J:
            if( IS_NORMAL_MODE_ON() ) {
                if(record->event.pressed) register_code(keycode & 0xFF);
                else                      unregister_code(keycode & 0xFF);
                return  false;
            }
    }

    //Run the keyboard specific code, if defined
    return process_record_keymap(keycode,record);
}

////// Global layer state set user

__attribute__ ((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    static bool AltTabLayer_Prev_Enabled;

    //As part of the special alt-tab, clear the alt modifier when leaving symbol layer
    if(IS_LAYER_OFF_STATE(state,_SYMB) && AltTabLayer_Prev_Enabled){
        unregister_code(KC_LALT);
    }
    //Update memory for next time
    AltTabLayer_Prev_Enabled = IS_LAYER_ON_STATE(state,2);

    //Handle accessing the function layer with both normal layer keys
    layer_state_t modifiedState = update_tri_layer_state(state, _SYMB, _NAV, _FUNC);

    //Run any keyboard specific code, then finally, return the new layer state
    return layer_state_set_keymap(modifiedState);
}

////// Per key tapping term
// Since my pinkies are pretty slow (or is this an ulner nerve issue?), we'll increase the tapping term for them for home row mods
// The super/gui key is often only used whith purpose, so can be a bit higher a lil' bit
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {

    //In normal mode, we'll always use the "hold" trigger, but we'll set the tapping term to 0 to make it happen instantly
    if( IS_NORMAL_MODE_ON() ){
        switch (keycode) {
            case HM_A:
            case HM_S:
            case HM_D:
            case HM_F:
            case HM_SCLN:
            case HM_QUOT:
            case HM_L:
            case HM_K:
            case HM_J:
            case NUM_SPC:
            case NAV_ENT:
                return 0;
        }
    }

    switch (keycode) {
        //Homerow Ctrl - Take longer to trigger the hold action for left hand, shorter for right hand
        case HM_A:
            return TAPPING_TERM + 20;
        case HM_SCLN:
        case HM_QUOT:
            return TAPPING_TERM - 20;
        //Homerow GUI - Take much longer to trigger the hold action
        case HM_S:
        case HM_L:
            return TAPPING_TERM + 40;
        //Homerow Shift - Take less than the tapping term to trigger the hold action
        case HM_F:
        case HM_J:
            return TAPPING_TERM - 40;
        default:
            return TAPPING_TERM;
    }
}

/////// Per-key permissive hold for layer taps, so we can very quicky use arrows or hyphens
// The layer numbers will need to match across all keyboards, so use the standardised layer names in the userspace
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_DEL:
        case NAV_ENT:
        case SYM_ESC:
        case KC_NAV:
        case KC_SYMB:
        case HM_F:
        case HM_J:
        case HM_SCLN:
        case HM_QUOT:
            // Immediately select the hold action when another key is tapped.
            return true;
        case NUM_SPC:
           if( IS_NORMAL_MODE_ON() )    return true;
           else                         return false;
        default:
            // Do the normal checks for tap/hold
            return false;
    }
}

//To avoid ever hitting escape unless we hit it by itself, always trigger the hold action if another key is pressed
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_DEL:
        case NAV_ENT:
        case SYM_ESC:
        case KC_NAV:
        case KC_SYMB:
            // Immediately select the hold action when another key is pressed.
            return true;
        case NUM_SPC:
           if( IS_NORMAL_MODE_ON() )    return true;
           else                         return false;
        default:
            // Do the normal checks for tap/hold
            return false;
    }
}

//Need to be able to double tap things like mod-tap backspace, but not homerow mods
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {

    if( IS_NORMAL_MODE_ON() )   return TAPPING_TERM;

    switch (keycode) {
        case HM_A:
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_SCLN:
        case HM_QUOT:
        case HM_L:
        case HM_K:
        case HM_J:
        case NUM_SPC: //To be able to quickly add a space and then type a number? Can't double tap space though....
            return QUICK_TAP_TERM;
        default:
            return TAPPING_TERM;
    }
}

////// Auto shift adjustment
// Stop auto shifting in particular circumstances, such as if on number layer
// This is an override of the default function from "/quantum/process_keycode/process_caps_word.c", will need to update this as QMK updates.
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {

    // Don't autoshift at all on the numbers layer
    if (IS_LAYER_ON(_NUMBERS)) return false;

    // Deactivate autoshift if the "normal" keyboard global is active
    if (IS_NORMAL_MODE_ON()) return false;

    switch (keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
        case AUTO_SHIFT_ALPHA:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
        case AUTO_SHIFT_NUMERIC:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
        case AUTO_SHIFT_SPECIAL:
#    endif
            return true;
    }
    return get_custom_auto_shifted_key(keycode, record);
}

////// Normal Mode Activation Handler
// When setting:
//   - Disable combos (if used by keyboard)
// When clearing, undo the above
void activate_normal_mode(bool activate){
    gNornalModeActive = activate;
    if(gNornalModeActive){
        #ifdef MAX_COMBO_LENGTH
        combo_disable();
        #endif
    }
    else{
        #ifdef MAX_COMBO_LENGTH
        combo_enable();
        #endif
    }
}

 /*----------------------------------------------------------------*\
 |      Leader Keys - Type a sequence to trigger an action          |
 \*----------------------------------------------------------------*/

#ifdef LEADER_ENABLE

    // Keyboard specific functions, to run after the userspace ones.
    // Defined as weak, so it can be overridden in keymap

    __attribute__ ((weak))
    void leader_start_keymap(void){
        return;
    }
    __attribute__ ((weak))
    void leader_end_keymap(void){
        return;
    }

    void leader_start_user(void) {
        //Run the keyboard's specific leader key start code
        leader_start_keymap();
    }

    void leader_end_user(void) {
        // "homerowMODs" -> Activate the homerow mods layer as the default layer
        if (leader_sequence_three_keys(KC_M,KC_O,KC_D)) {
            set_single_persistent_default_layer(_MOD);
            DEACTIVATE_NORMAL_MODE();
        }
        // "QWErty" -> Activate the standard QWERTY layer as the default layer
        else if (leader_sequence_three_keys(KC_Q,KC_W,KC_E)) {
            set_single_persistent_default_layer(_QWERTY);
        }
        // "NORmal" -> Activate normal mode for playing games
        else if (leader_sequence_three_keys(KC_N,KC_O,KC_R)) {
            ACTIVATE_NORMAL_MODE();
        }
        // "BOOT" -> Boots the microcontroller for flashing
        else if (leader_sequence_four_keys(KC_B,KC_O,KC_O,KC_T)) {
            reset_keyboard();
        }

        //Run the keyboard's specific leader key end code
        leader_end_keymap();
    }

#endif
