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

// cirque settings
// https://docs.qmk.fm/features/pointing_device
#define CIRQUE_PINNACLE_POSITION_MODE  CIRQUE_PINNACLE_ABSOLUTE_MODE

// Touch originating in outer ring can trigger scroll by moving along
// the perimeter. Near side triggers vertical scroll and far side
// triggers horizontal scroll.
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

#define CIRQUE_PINNACLE_DIAMETER_MM 35

// CIRQUE_PINNACLE_ATTENUATION
// lowest sensitivity is default - EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_4X
// also 1X, 2X, 3X

// enable or disable taps
#define CIRQUE_PINNACLE_TAP_ENABLE
