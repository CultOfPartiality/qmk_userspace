#pragma once

// Upped, as I was getting double triggers (mostly on the work board though...?)
//  Debounce algo is per key, eager on the downstroke, deferred on the up stroke, so should be less issue with pushing debounce timer higher
//  Letting go of homerow mod and layers (mainly to then trigger number layer) means 25ms is too high, 20ms might still be
//#define DEBOUNCE 18
