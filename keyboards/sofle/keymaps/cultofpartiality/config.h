#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_RIGHT

// Chasing space savings
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define GRAVE_ESC_CTRL_OVERRIDE

#define TAPPING_TOGGLE 1

// Testing space saving by limiting layers to 8, saves ~50 bytes?
//#define LAYER_STATE_8BIT

