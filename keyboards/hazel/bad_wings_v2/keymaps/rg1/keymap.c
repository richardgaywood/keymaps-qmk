#include QMK_KEYBOARD_H

#include "keymap_uk.h"

#include "pointing_device/pointing_device_auto_mouse.h"
// #include "features/layer_lock.h"

// #define CIRQUE_CPI_MIN 400
// #define CIRQUE_CPI_MAX 1200
// #define CIRQUE_CPI_STEP 100

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

#define CIRQUE_CPI 300

// Modify these values to adjust the mouse drag_scroll speed
#define SCROLL_DIVISOR_H 32.0
#define SCROLL_DIVISOR_V 32.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;
// store state of drag scroll as the key is pressed and released
bool set_scrolling = false;

enum bad_wings_layers {
    QWERTY,
    COMMANDS,
    SYMBOLS,
    ADJUST,
    NUMPAD,
    AUTO_MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT,
        MEH(KC_Z), LGUI_T(KC_X), LALT_T(KC_C), KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        // thumbs
        KC_LCTL, OSL(SYMBOLS), KC_SPC, OSM(MOD_RSFT), MO(COMMANDS), LT(NUMPAD,KC_ENT)
    ),

    [COMMANDS] = LAYOUT_split_3x5_3(
        KC_GRV, KC_LT, KC_GT, KC_QUOT, KC_AT, KC_AMPR, KC_DLR, KC_LBRC, KC_RBRC, KC_PERC,
        KC_EXLM, KC_EQL, KC_PLUS, KC_MINS, KC_NUHS, LSFT(KC_NUBS), KC_COLN, KC_LCBR, KC_RCBR, KC_QUES,
        KC_NUBS, KC_CIRC, KC_ASTR, KC_SLSH, KC_DQUO, KC_UNDS, KC_SCLN, KC_LCBR, KC_RCBR, KC_PIPE,
        // thumbs
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),


    [SYMBOLS] = LAYOUT_split_3x5_3(
        KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_BSPC,
        KC_TAB, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B), KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT,
        // thumbs
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [ADJUST] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO,
        CL_TOGG, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_F5, KC_F6, KC_F7, KC_F8, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,
        // thumbs
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NUMPAD] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO,
        KC_NO, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_DOT, KC_4, KC_5, KC_6, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_NO,
        // thumbs
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [AUTO_MOUSE] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, QK_MOUSE_WHEEL_UP,                                  QK_MOUSE_WHEEL_UP, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, QK_MOUSE_WHEEL_DOWN,                                QK_MOUSE_WHEEL_DOWN, KC_NO, KC_NO, KC_NO, KC_NO,
        // thumbs
        DRAG_SCROLL, MS_BTN1, MS_BTN2,                                                      KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
    set_auto_mouse_layer(AUTO_MOUSE);
    pointing_device_set_cpi(CIRQUE_CPI);
};

// Function to handle mouse reports and perform drag scrolling
// code heavily cribbed from https://docs.qmk.fm/features/pointing_device#advanced-drag-scroll
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            // lock the mouse layer on
            layer_lock_on(AUTO_MOUSE);
            set_auto_mouse_enable(false);
            break;
        default:
            layer_lock_off(AUTO_MOUSE);
            set_auto_mouse_enable(true);
            break;
    }
    return true;
}

// Function to handle layer changes and disable drag scrolling when not in AUTO_MOUSE_DEFAULT_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != AUTO_MOUSE) {
        set_scrolling = false;
    }
    return state;
}
