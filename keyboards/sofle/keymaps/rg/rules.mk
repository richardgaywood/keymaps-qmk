#TRI_LAYER_ENABLE = yes # started enabled


# duplicating settings from the default sofle config here, for reference
SPLIT_KEYBOARD = yes
ENCODER_ENABLE = yes
OLED_ENABLE = yes
# "The swap-hands action allows support for one-handed typing without requiring a separate layer."
# SWAP_HANDS_ENABLE = yes


# these settings from sofle default map
# https://github.com/qmk/qmk_firmware/blob/user-keymaps-still-present/keyboards/sofle/keymaps/default/rules.mk
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug


# my settings
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
VIA_ENABLE = yes
# COMBO_ENABLE = yes

# tap dance, mod tap, etc
TAP_DANCE_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes


# these settings are used in keyhhive fork
# https://github.com/qmk/qmk_firmware/blob/user-keymaps-still-present/keyboards/sofle/keyhive/rules.mk
#BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
#MOUSEKEY_ENABLE = no        # Mouse keys
#COMMAND_ENABLE = no         # Commands for debug and configuration
#NKRO_ENABLE = yes           # Enable N-Key Rollover

