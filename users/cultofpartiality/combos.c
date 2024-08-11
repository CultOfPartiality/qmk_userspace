//See "https://github.com/qmk/qmk_firmware/issues/21137" for info around needed this file

#pragma once

#include "quantum.h"
#include "cultofpartiality.h"

/*Combos*/
const uint16_t PROGMEM combo_homerowShiftsCapsWord[] = {HM_F, HM_J, COMBO_END};
const uint16_t PROGMEM combo_leaderKey2[] = {HM_S, HM_D, COMBO_END};
const uint16_t PROGMEM combo_homerowTab[] = {HM_A, HM_S, COMBO_END};
const uint16_t PROGMEM combo_addDelete[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_F5[] = {KC_R, KC_T, COMBO_END};


 /*----------------------------------------------------------------*\
 |      Combos - Tap multiple keys to trigger an action             |
 \*----------------------------------------------------------------*/
 //There's difficult moving this to the userspace... Lets see what we can get away with

combo_t key_combos[] = {
    COMBO_ACTION(combo_homerowShiftsCapsWord),
    COMBO(combo_leaderKey2,QK_LEAD),
    COMBO(combo_homerowTab,KC_TAB),
    COMBO(combo_addDelete, KC_DEL),
    COMBO(combo_F5, KC_F5),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed)
        trigger_caps_funcs();
      break;
  }
}
