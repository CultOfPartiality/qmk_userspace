SRC += cultofpartiality.c

AUTO_SHIFT_ENABLE = yes
MOUSEKEY_ENABLE   = yes
CAPS_WORD_ENABLE  = yes # Single word capslock? Should be useful
COMMAND_ENABLE    = no  # Can't use this at the same time as Caps Word
DYNAMIC_MACRO_ENABLE = yes

#Testing Zone
#AUTOCORRECT_ENABLE = yes

#Create a #define for leader key, if keyboard has it enabled in its rules
ifeq ($(strip $(LEADER_ENABLE)), yes)
    OPT_DEFS += -DLEADER_ENABLE
endif

#Create a #define for combos, if keyboard has it enabled in its rules
ifeq ($(strip $(COMBO_ENABLE)), yes)
    OPT_DEFS += -DCOMBO_ENABLE
endif

