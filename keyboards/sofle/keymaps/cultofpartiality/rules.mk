# To clean up development split operations into multiple files
#SRC += oled.c encoder.c
#SRC += encoder.c

# Keyboard specific rules not in Userspace
OLED_ENABLE = no
#OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes

# Chasing space gains
LTO_ENABLE = yes
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no  #Saves ~550 bytes (~2%)

# Can this fit in the memory
COMBO_ENABLE = yes
LEADER_ENABLE = yes

TRI_LAYER_ENABLE = no
