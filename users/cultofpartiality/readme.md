# Userspace - CultOfPartiality
Sick of copying settings from keyboard to keyboard as I keep developing my own layout, I've put all the common layout, code and settings into this userspace as QMK allows. Now, whenever I compile a board with the keymap of "cultofpartiality" this userspace will get included automatically.

## Standardised Layouts
The goal is to have standard keymap layouts across all keyboards I ues. This means the arrow keys, mouse mode keys, and other keys committed to muscle memory are always in the same place. So far this is only for the "inner block" of keys (all those reached one up or down from the eight finger home positions, and the index fingers' inner row).

Progress so far:
 - Navigation
 - Number Layer
 - Symbols (starting to) 

## Standardising Code
As I started experimenting with QMK features it got annoying looking for the latest keyboard I'd been messing with to adapt the settings from for the current keyboard to get the same feature. So things like process_keypress_user and layer_set_user have received their own userspace versions. These function gets added to the end of each keyboard's user version, to run if the keyboard doesn't have an override. For instance:
 - The Alt-Tab keys need to know when a layer is switched off
 - Blocking the escape code from being sent if the key was hit to deactivate caps-word

## Standard settings
### Mouse Mode
Mouse mode has a number of tuning components for speed and accdeleration and delays. As such, when I finally sit down to tune these to work smoothly I'd want these to propagate to the other boards.

These keys used to be included in the standardised NAV layer, but now need a new home...

### Caps Word and Caps Lock
Press both shifts and trigger "caps lock" until the end of the current word.
Press both shifts again and this activates true caps lock.
Escape at anypoint cancels either, without actually sending the escape code to the computer.

### Standard Combos
* Caps word/lock
* Leader key

### Leader Key
Allow activation of functionality to be done using mnemonics. Most often used for special configuration, like activating Normal Mode

### Normal Mode
Pretty much just for playing games. Turns off layer activation on Space, deactivates leader key and homerow mods


## TODO
- Change leader key combo
- More layers, accessable to the thumbs on space/enter?
    - Getting a sore hand when holding nav key (an inwards movement). Others solve this with alternating hands, but single hand nav is too important I think
        - Maybe using the enter key, to move the action over 1U?
    - There's an idea, mouse mode with right hand movement, left hand click?
    - It was good, but homerow mods have ruined that unified-nav layer for now
- Live definable macros
    - Consisten location?
- Mod tap for left hand activation of shortcuts with homerow mods (tap and hold for Ctrl-A?)
- Homerow mod tuning
    - Make shift more snappy
        - Lower tapping term?
    - Timeout to avoid triggering GUI and Ctrl unless haven't been typing for a time?
