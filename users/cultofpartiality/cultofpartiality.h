/* ________  ____  __________  __________  ___    ____  _____________    __    ____________  __
  / ____/ / / / / /_  __/ __ \/ ____/ __ \/   |  / __ \/_  __/  _/   |  / /   /  _/_  __/\ \/ /
 / /   / / / / /   / / / / / / /_  / /_/ / /| | / /_/ / / /  / // /| | / /    / /  / /    \  /
/ /___/ /_/ / /___/ / / /_/ / __/ / ____/ ___ |/ _, _/ / / _/ // ___ |/ /____/ /  / /     / /
\____/\____/_____/_/  \____/_/   /_/   /_/  |_/_/ |_| /_/ /___/_/  |_/_____/___/ /_/     /_/
Userspace definition

Note - Fun heading are the "SMALL" font from https://ascii.today/
*/
#pragma once
#include "quantum.h"

/* ___ _    ___  ___   _   _      ___ _____ _ _____ ___ ___
  / __| |  / _ \| _ ) /_\ | |    / __|_   _/_\_   _| __/ __|
 | (_ | |_| (_) | _ \/ _ \| |__  \__ \ | |/ _ \| | | _|\__ \
  \___|____\___/|___/_/ \_\____| |___/ |_/_/ \_\_| |___|___/
Global variables to add extra functionality     */

//Normal mode -> No autoshift, homerow mods, space-key number layer, combos
extern bool gNornalModeActive;
void activate_normal_mode(bool);
#define ACTIVATE_NORMAL_MODE() activate_normal_mode(true)
#define DEACTIVATE_NORMAL_MODE() activate_normal_mode(false)
#define IS_NORMAL_MODE_ON() gNornalModeActive

/*_   _ ___ ___ ___  ___ ___  _   ___ ___   ___ _   _ _  _  ___ _____ ___ ___  _  _ ___
 | | | / __| __| _ \/ __| _ \/_\ / __| __| | __| | | | \| |/ __|_   _|_ _/ _ \| \| / __|
 | |_| \__ \ _||   /\__ \  _/ _ \ (__| _|  | _|| |_| | .` | (__  | |  | | (_) | .` \__ \
  \___/|___/___|_|_\|___/_|/_/ \_\___|___| |_|  \___/|_|\_|\___| |_| |___\___/|_|\_|___/
Userspace version of normal functions, that should be run inside the normal function in
each standardised keyboard to trigger my standard functionality (if the keyboard doesn't
have functionality that should overide this).                                         */

bool process_record_userspace(uint16_t keycode, keyrecord_t *record);
layer_state_t layer_state_set_userspace(layer_state_t state);

/* ___ _____ _  _ ___ ___   ___ _   _ _  _  ___ _____ ___ ___  _  _ ___
  / _ \_   _| || | __| _ \ | __| | | | \| |/ __|_   _|_ _/ _ \| \| / __|
 | (_) || | | __ | _||   / | _|| |_| | .` | (__  | |  | | (_) | .` \__ \
  \___/ |_| |_||_|___|_|_\ |_|  \___/|_|\_|\___| |_| |___\___/|_|\_|___/
Funciton prototypes as required for special funcitonality             */

void trigger_caps_funcs(void);

/*___ _____ _   _  _ ___   _   ___ ___    _      ___   _____ ___  ___
 / __|_   _/_\ | \| |   \ /_\ | _ \   \  | |    /_\ \ / / __| _ \/ __|
 \__ \ | |/ _ \| .` | |) / _ \|   / |) | | |__ / _ \ V /| _||   /\__ \
 |___/ |_/_/ \_\_|\_|___/_/ \_\_|_\___/  |____/_/ \_\_| |___|_|_\|___/
Each keyboard should have at minimum these layers. The order matters for other functions*/

enum global_layers {
    _QWERTY,
	_MOD,
    _SYMB,
    _NAV,
    _NUMBERS,
    _FUNC,
    LAYERS_SAFE_RANGE_KB //Must be last, enabled custom layers to be defined per keyboard
};

/* ___ _   _ ___ _____ ___  __  __   _  _______   _____ ___  ___  ___ ___
  / __| | | / __|_   _/ _ \|  \/  | | |/ / __\ \ / / __/ _ \|   \| __/ __|
 | (__| |_| \__ \ | || (_) | |\/| | | ' <| _| \ V / (_| (_) | |) | _|\__ \
  \___|\___/|___/ |_| \___/|_|  |_| |_|\_\___| |_| \___\___/|___/|___|___/
  Keycode Stuff - For Simplifing Layout & Custom Functionality          */

// Custom keycodes defined at the userspace level
enum global_keycodes {
  A_TAB = SAFE_RANGE,
  SA_TAB,
  NM_ON,
  NM_OFF,
  SAFE_RANGE_KB //Must be last, enabled custom keycodes to be defined per keyboard
};

//This key can be populated when desired, as opposed to a pass-through _______ or blocker XXXXXXX which should stay once in place
#define _SPARE_ XXXXXXX

//Keys with modifier: Control
#define KC_CLFT C(KC_LEFT)
#define KC_CRHT C(KC_RIGHT)
#define KM_CSHT C(KC_LSFT)
#define KM_UNDO C(KC_Z)
#define KM_CUT  C(KC_X)
#define KM_COPY C(KC_C)
#define KM_PAST C(KC_V)
#define KC_REDO C(KC_Y)

//Keys with modifiers: Control and GUI
#define KC_PWIN C(G(KC_LEFT))
#define KC_NWIN C(G(KC_RIGHT))

//Homerow mods
#define HM_A    LCTL_T(KC_A)
#define HM_S    LGUI_T(KC_S)
#define HM_D    LALT_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_SCLN RCTL_T(KC_SCLN)
#define HM_QUOT RCTL_T(KC_QUOT)
#define HM_L    RGUI_T(KC_L)
#define HM_K    RALT_T(KC_K)
#define HM_J    RSFT_T(KC_J)

//Standard thumb keys
#define NUM_SPC LT(_NUMBERS,KC_SPC)
#define MOU_TAB LT(_MOUSE,  KC_TAB)
#define MOU_ENT LT(_MOUSE,  KC_ENT)
#define SYM_ESC LT(_SYMB,   KC_ESC)
#define NAV_DEL LT(_NAV,    KC_DEL)
#define NAV_ENT LT(_NAV,    KC_ENT)

//Other layer keys
#define KC_SYMB MO(_SYMB)
#define KC_NAV MO(_NAV)

/*___ _____ _   _  _ ___   _   ___ ___    _      ___   _____  _   _ _____ ___
 / __|_   _/_\ | \| |   \ /_\ | _ \   \  | |    /_\ \ / / _ \| | | |_   _/ __|
 \__ \ | |/ _ \| .` | |) / _ \|   / |) | | |__ / _ \ V / (_) | |_| | | | \__ \
 |___/ |_/_/ \_\_|\_|___/_/ \_\_|_\___/  |____/_/ \_\_| \___/ \___/  |_| |___/
 Standard format for the "inner block" of keys:

       |  Pinky Ring  Mid   Index Inner      Inner Index Mid   Ring  Pinky |
-------+---------------------------------  --------------------------------+
Top    |  L4T,  L3T,  L2T,  L1T,  L0T   |  | R0T,  R1T,  R2T,  R3T,  R4T   |
Middle |  L4M,  L3M,  L2M,  L1M,  L0M   |  | R0T,  R1T,  R2T,  R3T,  R4T   |
Bottom |  L4B,  L3B,  L2B,  L1B,  L0B   |  | R0B,  R1B,  R2B,  R3B,  R4B   |
-------+---------------------------------  --------------------------------+


 Navigation Layer
+----------------------------------------------        -----------------------------------------------+
| XXXXXXX, XXXXXXX, Mouse U, XXXXXXX, M-Whl U |        | MMBtn,   Ctrl-L,  Up,      Ctrl-R,   Page Up |
| Ctrl,    GUI,     Alt,     Shift,   Delete  |        | LMBtn,   Left,    Down,    Right,    Page Dn |
| _______, Ctrl-X,  Ctrl-C,  Ctrl-V,  XXXXXXX |        | RMBtn,   Home,    XXXXXXX, End,      XXXXXXX |
+----------------------------------------------        -----------------------------------------------+

 Number Layer
+---------------------------------------------+        +----------------------------------------------+
| !,       @,       #,       $,       %       |        | ^,       &,       *,       (,        )       |
| 1,       2,       3,       4,       5       |        | 6,       7,       8,       9,        0       |
| Ctrl-Z,  Ctrl-X,  Ctrl-C,  Ctrl-V,  Ctrl-Y  |        | +,       -,       Comma,   Period,   /       |
+---------------------------------------------+        +----------------------------------------------+

 Symbol Layer?
+---------------------------------------------+        +----------------------------------------------+
| `,       ,        S-A Tab, Alt-Tab, XXXXXXX |        | =,       [,       ],       SPARE,   SPARE    |
| Ctrl,    GUI,     Alt,     Shift,   PrntScn |        | -,       (,       ),       SPARE,   |        |
| XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX |        | +,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  |
+---------------------------------------------+        +----------------------------------------------+
*/

#define NAV_L4T XXXXXXX
#define NAV_L4M KC_LCTL
#define NAV_L4B _______
#define NAV_L3T XXXXXXX
#define NAV_L3M KC_LGUI
#define NAV_L3B KM_CUT
#define NAV_L2T KC_MS_U
#define NAV_L2M KC_LALT
#define NAV_L2B KM_COPY
#define NAV_L1T XXXXXXX
#define NAV_L1M KC_LSFT
#define NAV_L1B KM_PAST
#define NAV_L0T KC_WH_U
#define NAV_L0M KC_DEL
#define NAV_L0B XXXXXXX

#define NAV_R0T KC_BTN3
#define NAV_R0M KC_BTN1
#define NAV_R0B KC_BTN2
#define NAV_R1T KC_CLFT
#define NAV_R1M KC_LEFT
#define NAV_R1B KC_HOME
#define NAV_R2T KC_UP
#define NAV_R2M KC_DOWN
#define NAV_R2B XXXXXXX
#define NAV_R3T KC_CRHT
#define NAV_R3M KC_RIGHT
#define NAV_R3B KC_END
#define NAV_R4T KC_PGUP
#define NAV_R4M KC_PGDN
#define NAV_R4B XXXXXXX

#define _______________NAV_LEFT_TOP________________        NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T
#define _______________NAV_LEFT_MID________________        NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M
#define _______________NAV_LEFT_BOT________________        NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B

#define _______________NAV_RIGHT_TOP_______________        NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T
#define _______________NAV_RIGHT_MID_______________        NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M
#define _______________NAV_RIGHT_BOT_______________        NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B

/* Symbol Layer */

#define SYM_L4T KC_GRV
#define SYM_L4M KC_LCTL
#define SYM_L4B XXXXXXX
#define SYM_L3T XXXXXXX
#define SYM_L3M KC_LGUI
#define SYM_L3B XXXXXXX
#define SYM_L2T SA_TAB
#define SYM_L2M KC_LALT
#define SYM_L2B DM_PLY1
#define SYM_L1T A_TAB
#define SYM_L1M KC_LSFT
#define SYM_L1B DM_PLY2
#define SYM_L0T XXXXXXX
#define SYM_L0M KC_PSCR
#define SYM_L0B XXXXXXX

#define SYM_R0T KC_EQL
#define SYM_R0M KC_MINS
#define SYM_R0B KC_PLUS
#define SYM_R1T KC_LBRC
#define SYM_R1M KC_LPRN
#define SYM_R1B XXXXXXX
#define SYM_R2T KC_RBRC
#define SYM_R2M KC_RPRN
#define SYM_R2B XXXXXXX
#define SYM_R3T XXXXXXX
#define SYM_R3M XXXXXXX
#define SYM_R3B XXXXXXX
#define SYM_R4T XXXXXXX
#define SYM_R4M KC_PIPE
#define SYM_R4B XXXXXXX

#define _______________SYM_LEFT_TOP________________        SYM_L4T, SYM_L3T, SYM_L2T, SYM_L1T, SYM_L0T
#define _______________SYM_LEFT_MID________________        SYM_L4M, SYM_L3M, SYM_L2M, SYM_L1M, SYM_L0M
#define _______________SYM_LEFT_BOT________________        SYM_L4B, SYM_L3B, SYM_L2B, SYM_L1B, SYM_L0B

#define _______________SYM_RIGHT_TOP_______________        SYM_R0T, SYM_R1T, SYM_R2T, SYM_R3T, SYM_R4T
#define _______________SYM_RIGHT_MID_______________        SYM_R0M, SYM_R1M, SYM_R2M, SYM_R3M, SYM_R4M
#define _______________SYM_RIGHT_BOT_______________        SYM_R0B, SYM_R1B, SYM_R2B, SYM_R3B, SYM_R4B

/* Number Layer */

#define NUM_L4T KC_EXLM
#define NUM_L4M KC_1
#define NUM_L4B KM_UNDO
#define NUM_L3T KC_AT
#define NUM_L3M KC_2
#define NUM_L3B KM_CUT
#define NUM_L2T KC_HASH
#define NUM_L2M KC_3
#define NUM_L2B KM_COPY
#define NUM_L1T KC_DLR
#define NUM_L1M KC_4
#define NUM_L1B KM_PAST
#define NUM_L0T KC_PERC
#define NUM_L0M KC_5
#define NUM_L0B KC_REDO

#define NUM_R0T KC_CIRC
#define NUM_R0M KC_6
#define NUM_R0B KC_PLUS
#define NUM_R1T KC_AMPR
#define NUM_R1M KC_7
#define NUM_R1B KC_MINS
#define NUM_R2T KC_ASTR
#define NUM_R2M KC_8
#define NUM_R2B KC_COMM
#define NUM_R3T KC_LPRN
#define NUM_R3M KC_9
#define NUM_R3B KC_DOT
#define NUM_R4T KC_RPRN
#define NUM_R4M KC_0
#define NUM_R4B KC_SLSH

#define _______________NUM_LEFT_TOP________________        NUM_L4T, NUM_L3T, NUM_L2T, NUM_L1T, NUM_L0T
#define _______________NUM_LEFT_MID________________        NUM_L4M, NUM_L3M, NUM_L2M, NUM_L1M, NUM_L0M
#define _______________NUM_LEFT_BOT________________        NUM_L4B, NUM_L3B, NUM_L2B, NUM_L1B, NUM_L0B

#define _______________NUM_RIGHT_TOP_______________        NUM_R0T, NUM_R1T, NUM_R2T, NUM_R3T, NUM_R4T
#define _______________NUM_RIGHT_MID_______________        NUM_R0M, NUM_R1M, NUM_R2M, NUM_R3M, NUM_R4M
#define _______________NUM_RIGHT_BOT_______________        NUM_R0B, NUM_R1B, NUM_R2B, NUM_R3B, NUM_R4B
