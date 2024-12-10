// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MASTER_LEFT

// I just think caps word is neat
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// MOAR LAYERS for via
#define DYNAMIC_KEYMAP_LAYER_COUNT 15

// tap dance etc config
#define TAPPING_TERM 225
#define TAPPING_TERM_PER_KEY // not used... yet
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define OLED_TIMEOUT 60000

// OS detection
#define OS_DETECTION_KEYBOARD_RESET
#define OS_DETECTION_DEBOUNCE 200

// interesting looking crib sources:
// https://github.com/Coko7/sofle/blob/main/config.h


#define LAYER_LOCK_IDLE_TIMEOUT 180000  // in milliseconds.
		
// encoder stuff
// https://docs.qmk.fm/features/encoders
// #define ENCODER_A_PINS_RIGHT { encoder1a, encoder2a }
// #define ENCODER_B_PINS_RIGHT { encoder1b, encoder2b }
// #define ENCODER_RESOLUTIONS_RIGHT { 2, 4 }
//
// #define ENCODER_DIRECTION_FLIP
// #define ENCODER_RESOLUTION 4
// #define ENCODER_RESOLUTIONS { 4, 2 }
//
//
