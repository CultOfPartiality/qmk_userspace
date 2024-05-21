/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define MIDI_BASIC

#define GRAVE_ESC_CTRL_OVERRIDE

// Adding new leader key functions, which I think will be neat
// I'll test here, and if I like I'll move to userspace (assuming AVR's have memory for it)
// Getting into the leader key so far has been triggered by combos on the home layer
#define LEADER_TIMEOUT 300      //Timeout in milliseconds to hit the sequence
#define LEADER_PER_KEY_TIMING   //Each key in the sequence restarts the timer
#define LEADER_NO_TIMEOUT       //After hitting the leader key, no timeout to start the sequence

// Due to homerow modes, combos work better here for Caps Word
#undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD
