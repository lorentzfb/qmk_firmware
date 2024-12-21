#pragma once

#include QMK_KEYBOARD_H

// #include "keymap_us.h"
#include "keymap_norwegian.h"
// #include "sendstring_norwegian.h"
#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"

enum layer_names {
    _BL,
    _NOR,
    _NUM,
    _SYM,
    _BTN,
    _FN,
    _MED,
    _ADJ
};

// https://docs.qmk.fm/custom_quantum_functions#defining-a-new-keycode
enum custom_keycodes {
    ARRFAT = QK_USER, // =>
    ARRSL, // ->
    NUMWO,
    CANCEL,
    OS_STR,
    // NO_AE,
    // NO_O,
    // NO_AA
};

// Left-hand home row mods
#define HOME_A LALT_T(NO_A)
// #define HOME_S LT(_SYM, KC_S)
#define HOME_S LGUI_T(NO_S)
#define HOME_D LT(_SYM, NO_D)
#define HOME_F LSFT_T(NO_F)

// Right-hand home row mods
#define HOME_J RSFT_T(NO_J)
// #define HOME_K RGUI_T(KC_K)
#define HOME_K LT(_SYM, NO_K)
// #define HOME_L LT(_SYM, KC_L)
#define HOME_L RGUI_T(NO_L)
#define HOME_SCN RALT_T(NO_SCLN)

// Layer toggles
#define _BTN_BS LT(_BTN, KC_BSPC)
#define _NUM_V LT(_NUM, NO_V)
#define _MED_Z LT(_MED, NO_Z)

// Aerospace window resizing
#define WS_INC LALT(LSFT(NO_PLUS))
#define WS_DECR LALT(LSFT(NO_MINS))

// Mac print screen
#define PRNT3 LSFT(LGUI(NO_3))
#define PRNT4 LSFT(LGUI(NO_4))
#define PRNT5 LSFT(LGUI(NO_5))

// Cut, Copy, Paste, Undo
// Moved to home row
#define SCUT LGUI(NO_X)
#define SCPY LGUI(NO_C)
#define SPST LGUI(NO_V)
#define SUND LGUI(NO_Z)

// Raycast or spotlight (MEH: Hold Left Control, Shift and Alt)
#define RAYCA MEH(NO_R)

// Increase/decrease buffer size
#define CMDI LGUI(NO_MINS)
#define CMDD LGUI(NO_PLUS)

// Save/write
#define SSAVE LGUI(NO_S)

// Norwegian (When using US International)
// #define NO_AE LALT(KC_QUOT) // æ
// #define NO_O LALT(KC_O)     // ø
// #define NO_AA RALT(KC_A)    // å

// Shift-g for Vim goto line
#define NUM_G LSFT(NO_G)
