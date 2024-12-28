// Copyright 2023 QMK
//k SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "keymap_uk.h" // [!code focus]
#include "g/keymap_combo.h" // see https://docs.qmk.fm/features/combo#dictionary-management

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _W_QWERTY,
    _M_QWERTY, // not 100% sure I need this, CG_TOGG may be enough
    _GAME, // will be a base layer; reserved/unused for now
    COMMANDS,
    SYMBOLS,
    ADJUST,
    NUMPAD,
};


// Tap Dance declarations
enum {
    TD_BOOT_CLR_EEPROM,
    TD_SYMBOL_LAYER_HOME_KEYS_F,
    TD_SYMBOL_LAYER_HOME_KEYS_J,
};
tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT_CLR_EEPROM] = ACTION_TAP_DANCE_DOUBLE(QK_BOOTLOADER, QK_CLEAR_EEPROM),
    [TD_SYMBOL_LAYER_HOME_KEYS_F] = ACTION_TAP_DANCE_DOUBLE(KC_F, MO(SYMBOLS)),
    [TD_SYMBOL_LAYER_HOME_KEYS_J] = ACTION_TAP_DANCE_DOUBLE(KC_J, MO(SYMBOLS)),
};


/*
 * blank template for reference

 [_BLANK] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  ),
*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | MINS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                    |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |  A   |  S   |  D   |LT(SYM|  G   |,------.    ,------.|  H   |LT(SYM|  K   |  L   | SCLN |UK_QUO|
 * |------+------+------+------+------+------||      |    | MUTE ||------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   |`------'    `------'|  N   |  M   | COMM | DOT  | SLSH | ENT  |
 * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
 *               |TT(NUM|      | LALT |/ LCTL / SPC  /    \ RSFT \MO(COM\| RGUI | MEH  |      |
 *               |      |      |      /      /      /      \      \      \      |      |      |
 *               `---------------------------------'        `---------------------------------'
 *                                                                                   generated by [keymapviz] */
[_W_QWERTY] = LAYOUT(
   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
   KC_LCTL,  KC_A,   KC_S,    KC_D,    LT(SYMBOLS, KC_F),    KC_G,                          KC_H,    LT(SYMBOLS, KC_J),    KC_K,    KC_L, KC_SCLN,  UK_QUOT,
   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,     XXXXXXX, KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,


   TT(NUMPAD), XXXXXXX, KC_LALT,  KC_LCTL, KC_SPC,                KC_RSFT, MO(COMMANDS), KC_RGUI, KC_MEH, XXXXXXX

   // until 2024-12-17
   // TT(NUMPAD), KC_LALT, KC_LCTL,  MO(SYMBOLS), KC_SPC,                KC_RSFT, MO(COMMANDS), KC_RGUI, KC_MEH, XXXXXXX
   // used until 2024-12-12
   // KC_ESC, MO(NUMPAD), KC_LALT, MO(SYMBOLS), CTL_T(KC_SPC),                KC_RSFT, MO(COMMANDS), KC_RGUI, KC_MEH, XXXXXXX
),


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |      |      |      | EQL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  |                    | PGUP | HOME |  UP  | END  | PSCR |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |OSM(MO|OSM(MO|OSM(MO|OSM(MO| F11  |,------.    ,------.| PGDN | LEFT | DOWN | RGHT |      | DEL  |
 * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
 * |      |C(KC_Z|C(KC_X|C(KC_C|C(KC_V| F12  |`------'    `------'|      | BSPC | ENT  | DEL  | INS  |      |
 * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
 *               |MO(ADJ|      |      |/      /      /    \      \      \|      |      |      |
 *               |      |      |      /      /      /      \      \      \      |      |      |
 *               `---------------------------------'        `---------------------------------'
 *                                                                                   generated by [keymapviz] */
[COMMANDS] = LAYOUT(  /* control layer, right mode shift */
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_EQL,
  _______,  KC_F6,  KC_F7,   KC_F8,  KC_F9, KC_F10,                        KC_PGUP, KC_HOME,   KC_UP, KC_END, KC_PSCR, _______,
  _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_F11,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  XXXXXXX, KC_DEL,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_F12,  _______,       _______, XXXXXXX, KC_BSPC,  KC_ENT, KC_DEL, KC_INS , _______,
          MO(ADJUST), _______, _______, _______, _______,                _______, _______, _______, _______, _______
),


// Symbol row resources
//
// https://github.com/getreuer/qmk-keymap?tab=readme-ov-file#pascal-getreuers-qmk-keymap
// and https://getreuer.info/posts/keyboards/symbol-layer/index.html
// and especially https://github.com/getreuer/qmk-keymap/blob/main/keyboards/zsa/moonlander/keymaps/getreuer/keymap.c
//
// https://github.com/gfolgert/qmk_firmware/blob/master/keyboards/crkbd/keymaps/gfolgert/README.md#intonation


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | UK_1 | UK_2 | UK_3 | UK_4 | UK_5 |                    | UK_6 | UK_7 | UK_8 | UK_9 | UK_0 | EQL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GRV  | LABK | RABK |UK_QUO|UK_DQU|                    | AMPR | DLR  | LBRC | RBRC | PERC |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | EXLM | EQL  | PLUS | MINS |UK_HAS|,------.    ,------.|UK_PIP| COLN | LPRN | RPRN | QUES |      |
 * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
 * |      |UK_BSL| CIRC | ASTR | SLSH |UK_AT |`------'    `------'| UNDS | SCLN | LCBR | RCBR |UK_TIL|      |
 * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
 *               |      |      |      |/      /      /    \      \      \|      |      |      |
 *               |      |      |      /      /      /      \      \      \      |      |      |
 *               `---------------------------------'        `---------------------------------'
 *                                                                                   generated by [keymapviz] */
[SYMBOLS] = LAYOUT( /* symbols layer, left mode shift */
  _______, UK_1,     UK_2,     UK_3,     UK_4,     UK_5,                                UK_6,     UK_7,     UK_8,     UK_9,     UK_0,     KC_EQL,
  /* UK_GRV, KC_EXLM,   UK_AT, UK_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, */
  /*UK_GRV, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                       KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______, */
  /*_______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, S(KC_LBRC),                       S(KC_RBRC), KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,*/
//   _______,  UK_BSLS, KC_COLN, KC_SCLN, KC_COMMA, KC_DOT,  _______, _______,    UK_SLSH, UK_PIPE, _______, _______,_______,  _______,

  // https://github.com/getreuer/qmk-keymap/blob/main/keyboards/zsa/moonlander/keymaps/getreuer/keymap.c
  _______, KC_GRV, KC_LABK, KC_RABK, UK_QUOT, UK_DQUO,                           KC_AMPR, KC_DLR, KC_LBRC, KC_RBRC, KC_PERC, _______,
  _______, KC_EXLM, KC_EQL, KC_PLUS, KC_MINS,  UK_HASH,                          UK_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_QUES, _______,
  _______, UK_BSLS, KC_CIRC, KC_ASTR, KC_SLSH, UK_AT,     _______, _______,      KC_UNDS, KC_SCLN , KC_LCBR, KC_RCBR, UK_TILD,   _______,


  // thumbs
              _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______

),


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |TD_BOO|      |      |      |      |      |                    |      |      |      |      |      | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |CG_NOR|      |      |      |                    |      |      |      |      |CG_NOR|DT_DOW|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |,------.    ,------.|      | VOLD | MUTE | VOLU |      |DT_PRN|
 * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
 * |CG_TOG|      |      |      |      |      |`------'    `------'|CG_SWA| MPRV | MPLY | MNXT |      |DT_UP |
 * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
 *               |      |      |      |/      /      /    \      \      \|      |      |      |
 *               |      |      |      /      /      /      \      \      \      |      |      |
 *               `---------------------------------'        `---------------------------------'
 *                                                                                   generated by [keymapviz] */
  [ADJUST] = LAYOUT(
  TD_BOOT_CLR_EEPROM , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  XXXXXXX  , XXXXXXX, CG_NORM,XXXXXXX ,XXXXXXX,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_NORM, DT_DOWN, /* dynamic tapping term */
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, DT_PRNT,
  CG_TOGG , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, CG_SWAP, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, DT_UP,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______

  ),


/* ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    | PLUS |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |MINUS |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |OSM(MO|OSM(MO|OSM(MO|OSM(MO|      |,------.    ,------.|ASTERI|  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------||      |    |      ||------+------+------+------+------+------|
 * |      |      |      |      |      |      |`------'    `------'|SLASH |  0   | DOT  | DOT  |      |      |
 * `-------------+------+------+------+-.------------.    ,------------.-+------+------+------+-------------'
 *               |      |      |      |/      /      /    \  0   \LT(ADJ\|  0   |      |      |
 *               |      |      |      /      /      /      \      \      \      |      |      |
 *               `---------------------------------'        `---------------------------------'
 *                                                                                   generated by [keymapviz] */
  [NUMPAD] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_PLUS,     KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_MINUS,    KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
    XXXXXXX, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), XXXXXXX,                       KC_ASTERISK, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_SLASH,    KC_0,    KC_DOT,  KC_DOT,  XXXXXXX, _______,
                      _______, _______, _______, _______, _______,     KC_0, LT(ADJUST, KC_DOT), KC_0, XXXXXXX, XXXXXXX
  ),
};




#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_SPC):
            return TAPPING_TERM - 100; 
        default:
            return TAPPING_TERM;
    }
}
#endif 
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_T(KC_SPC):
            return false;
        default:
            return true;
    }
}
#ifdef PERMISSIVE_HOLD_PER_KEY

#endif
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// // #ifdef CONSOLE_ENABLE
// //     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// // #endif
//   return true;
// }

/*

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
     if (index == 1) {
         if (clockwise) {
             tap_code(KC_VOLU);
         } else {
             tap_code(KC_VOLD);
         }
     } else if (index == 0) {
         if (clockwise) {
            tap_code(QK_MOUSE_WHEEL_DOWN);
         } else {
            tap_code(QK_MOUSE_WHEEL_UP);
         }
     }

     return true;
}
#endif ENCODER_ENABLE
*/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_W_QWERTY] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_M_QWERTY] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [_GAME] = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [COMMANDS] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [SYMBOLS] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [ADJUST] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [NUMPAD] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

/* from discord */


/*
// ROTARY ENCODER KEYMAP FOR LEFT AND RIGHT ENCODERS
 // see also https://github.com/RanzQ/qmk-keymaps/blob/main/sofle-rgb/keymap.c#L165

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(TAB_L, TAB_R), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },      // TAB LEFT RIGHT || VOL UP DOWN
    [_SYM] =   { ENCODER_CCW_CW(TAB_L, TAB_R), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },      // TAB LEFT RIGHT || VOL UP DOWN
    [_NUM] =   { ENCODER_CCW_CW(TAB_L, TAB_R), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },      // TAB LEFT RIGHT || VOL UP DOWN
    [_NAV] =   { ENCODER_CCW_CW(TAB_L, TAB_R), ENCODER_CCW_CW(TAB_CTRL_R, TAB_CTRL_L) },      // TAB LEFT RIGHT || TAB CTRL LEFT RIGHT
    [_FUNC] =   { ENCODER_CCW_CW(TAB_L, TAB_R), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },      // TAB LEFT RIGHT || VOL UP DOWN
    [_MEDIA] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },      // SCROLL UP DOWN || VOL UP DOWN
    [_MISC] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },      // SCROLL UP DOWN || VOL UP DOWN
    [_DEV] =   { ENCODER_CCW_CW(PANIC, PANIC), ENCODER_CCW_CW(PANIC, PANIC) },          //    PANIC PANIC || PANIC PANIC
    [_NO] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO) },          //          NO NO || NO NO
};
#endif

*/




#ifdef OLED_ENABLE

// crib source for OLED
// https://github.com/Coko7/sofle/blob/main/keymap.c

// sofle logo from https://github.com/RanzQ/qmk-keymaps/blob/822d45c6035a434dab4a72afa1a5c97fa419f246/sofle-rgb/keymap.c#L176
static void render_logo(void) {
    // Custom logo based on the PCB gecko
    // draw this unrotated
    // static const char PROGMEM raw_sofle_logo[] = {
    //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,  8,  6,  2,  1,  0,  0,  0,  0,  0,  0,128,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,248, 28,  6,  2,  3,  1,  1,  1,225,255, 62,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,120, 28,206,103, 59, 15,  0,  0,192,240,120, 28,207,127, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 63,120,240,192,128,128,  0, 64, 96,112,248,255,222,207, 78, 10,  0,  0,  0,128,192,192, 96,124,112,120, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,129,  7, 15, 28, 60, 56,112,112,224,193,131,  1,  0,  0,  0,  0,128,128,  0,224,240, 16, 24,240, 96,  0,  0,128,224,248,191, 15, 13,  6,  3,  1,  0,128,224,252,223,103, 49, 12,  7,  1,192,224,112, 48, 24,152,248,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,  0,  0,  0,  0, 80,112,112,240,120,252, 12, 28, 56,113,227,119,127, 62, 30, 31, 63, 63, 61,124,124,124,124,124,252,253,255,127,124,124,124,124,124, 56, 56, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 62,255,255,193,128,  0,  0,  0,  0,  0,128,128,193,127, 63,  0,  0, 56,254,255,193, 64, 99, 55, 28, 30, 19, 16,232,252,127,  7,  3,255,  6, 12, 12,  4,  4,  4,127,255,193,192, 64, 32, 16,126,255,199,132,134,130,195, 65, 32, 48,  8,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //     0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64, 63,255, 57,112, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  3,  3,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,126,255,207, 96, 56, 15,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    // };

    // needs 270 rotation - TODO - rotate the image instead?
    static const char PROGMEM raw_greyhound_logo[] = {
        0,0,0,0,0,0,0,192,240,120,60,14,14,6,14,14,28,56,56,56,56,24,24,28,28,28,28,28,28,28,28,28,48,48,56,56,60,62,63,119,113,112,112,96,224,224,192,192,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,63,255,240,0,30,63,63,61,31,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,7,63,252,240,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,254,255,31,126,248,224,192,240,240,240,240,240,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,240,254,127,7,0,0,0,0,1,3,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,240,255,127,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,255,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,240,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,192,224,224,192,195,255,255,0,0,0,0,0,6,255,254,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,0,0,0,3,63,255,254,0,0,0,0,0,127,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,240,0,0,0,0,127,255,252,0,0,0,0,0,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,255,255,224,0,0,0,0,255,255,0,0,0,0,192,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,255,248,0,0,224,255,255,0,0,0,0,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,63,255,248,255,159,129,0,0,0,0,255,255,119,224,224,192,192,192,192,192,192,0,0,0,0,0,0,0,0,0,0,0,15,31,29,30,63,57,62,63,56,30,31,15,0,0,0,0,0,1,1,0,0
    };
    oled_write_raw_P(raw_greyhound_logo, sizeof(raw_greyhound_logo));
}


static void print_status_narrow(void) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Layr:"), false);
    switch (get_highest_layer(layer_state)) {
        case _W_QWERTY:
            oled_write_P(PSTR("QWRTY\n"), false);
            break;
        case COMMANDS:
            oled_write_P(PSTR("Cmds \n"), false);
            break;
        case SYMBOLS:
            oled_write_P(PSTR("Symbl\n"), false);
            break;
        case ADJUST:
            oled_write_P(PSTR("Adjst\n"), false);
            break;
        case NUMPAD:
            oled_write_P(PSTR("NumP \n"), false);
            break;
        default:
            // Or use the write_ln \shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undef\n"), false);
    }

    oled_write_ln_P(PSTR("Mode:"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("Mac\n"), false);
    } else {
        oled_write_ln_P(PSTR("Win\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}


void oled_render_boot(bool bootloader) {
    oled_clear();
    for (int i = 0; i < 16; i++) {
        oled_set_cursor(0, i);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting New Firmware "), false);
        } else {
            oled_write_P(PSTR("Rebooting "), false);
        }
    }

    oled_render_dirty(true);
}

//bool shutdown_user(bool jump_to_bootloader) {
//    oled_render_boot(jump_to_bootloader);
//}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
        // return OLED_ROTATION_180;
    } else {
        // Correct rotation to set here depends on intrisic
        // orientation of the logo defined above.
        return OLED_ROTATION_270;
    }
    return rotation;
}


// this from https://github.com/RanzQ/qmk-keymaps/blob/main/sofle-rgb/keymap.c
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif


// // force debugging on
// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
// }
// // force debugging output
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif
//   return true;
// }
