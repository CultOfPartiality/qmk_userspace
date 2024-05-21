
#pragma once

// Due to homerow modes, combos work better here for Caps Word
#undef BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Adding new leader key functions, which I think will be neat
// I'll test here, and if I like I'll move to userspace (assuming AVR's have memory for it)
// Getting into the leader key so far has been triggered by combos on the home layer
#define LEADER_TIMEOUT 300      //Timeout in milliseconds to hit the sequence
#define LEADER_PER_KEY_TIMING   //Each key in the sequence restarts the timer
#define LEADER_NO_TIMEOUT       //After hitting the leader key, no timeout to start the sequence
