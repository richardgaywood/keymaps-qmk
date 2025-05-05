// Copyright 2023 Jason Hazel (@jasonhazel)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM_PER_KEY
#define ONESHOT_TAP_TOGGLE 10
#define ONESHOT_TIMEOUT 500
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD


// 'q' key
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0



// cirque settings
// https://docs.qmk.fm/features/pointing_device
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE



// CIRQUE_PINNACLE_ABSOLUTE_MODE: Reports absolute x, y, z (touch pressure)
//   coordinates and up to 5 hw buttons connected to the trackpad
// CIRQUE_PINNACLE_RELATIVE_MODE: Reports x/y deltas, scroll and up
//   to 3 buttons (2 of them can be from taps, see gestures) connected
//   to trackpad. Supports taps on secondary side of split. Saves about
//   2k of flash compared to absolute mode with all features.
#define CIRQUE_PINNACLE_POSITION_MODE  CIRQUE_PINNACLE_RELATIVE_MODE



// (Optional) Enable tap to "left click". Works on both sides of a split keyboard.
#define CIRQUE_PINNACLE_TAP_ENABLE

// (Optional) Tap in upper right corner (half of the finger needs to be outside of
// the trackpad) of the trackpad will result in "right click".
// Relative mode only!
// CIRQUE_PINNACLE_TAP_ENABLE must be enabled.
#define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE

// Absolute mode:
// Touch originating in outer ring can trigger scroll by moving along
// the perimeter. Near side triggers vertical scroll and far side
// triggers horizontal scroll.
//
// Relativve mode: enables side scroll. Touch originating on the
// right side can trigger vertical scroll (IntelliSense trackpad style).
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE




// CIRQUE_PINNACLE_ATTENUATION
// lowest sensitivity is default - EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
// also 1X, 2X, 3X

