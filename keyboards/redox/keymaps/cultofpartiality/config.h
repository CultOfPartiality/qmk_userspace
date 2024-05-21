#pragma once

// Adding new leader key functions, which I think will be neat
// I'll test here, and if I like I'll move to userspace (assuming AVR's have memory for it)
// Getting into the leader key so far has been triggered by combos on the home layer
#define LEADER_TIMEOUT 300      //Timeout in milliseconds to hit the sequence
#define LEADER_PER_KEY_TIMING   //Each key in the sequence restarts the timer
#define LEADER_NO_TIMEOUT       //After hitting the leader key, no timeout to start the sequence

// Due to homerow modes, combos work better here for Caps Word
#undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Upped, as I was getting double triggers (mostly on the work board though...?)
//  Debounce algo is per key, eager on the downstroke, deferred on the up stroke, so should be less issue with pushing debounce timer higher
//  Letting go of homerow mod and layers (mainly to then trigger number layer) means 25ms is too high, 20ms might still be
#define DEBOUNCE 18
