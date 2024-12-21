/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include "keymap_norwegian.h"
#include "os_detection.h"
#include "quantum.h"
#include QMK_KEYBOARD_H
#include "keymap_us.h"
// #include "keymap_norwegian.h"
#include "sendstring_norwegian.h"
#include "quantum_keycodes.h"
#include "action_layer.h"

#include "keycodes.h"
#include "num_word.h"

static os_variant_t host_os = OS_UNSURE;

// KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    NO_Q,    NO_W,    NO_E,    NO_R,    NO_T,                         NO_Y,    NO_U,    NO_I,    NO_O,   NO_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    NO_G,                         NO_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCN, NO_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     OSL(_FN),  _MED_Z,    NO_X,    NO_C,    NO_V,    NO_B,                         NO_N,    NO_M, NO_COMM,  NO_DOT, NO_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC, _BTN_BS,  KC_SPC,    KC_ENT, NO_MINS, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [_NOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, NO_ARNG,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, NO_OSTR,   NO_AE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, NO_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, NO_SCLN
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, NO_CIRC, XXXXXXX, XXXXXXX,                      _______,    NO_J,    NO_K, NO_PERC, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    NO_6,    NO_4,    NO_0,    NO_2,   NUM_G,                      NO_ASTR,   NO_3,     NO_1,    NO_5,    NO_7, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, _______, NO_PLUS,    NO_8, XXXXXXX,                      XXXXXXX,   NO_9,  _______, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           CANCEL, KC_BSPC, _______,     NO_EQL, _______, NO_UNDS
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, NO_CIRC, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, NO_PERC, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   NO_AT, NO_TILD,  NO_DLR, NO_EXLM, XXXXXXX,                      NO_ASTR, NO_AMPR, NO_HASH, XXXXXXX, NO_PIPE,  NO_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, NO_PLUS,  ARRFAT, XXXXXXX,                      XXXXXXX,   ARRSL, XXXXXXX, XXXXXXX, NO_BSLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_BSPC, _______,     NO_EQL, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_BTN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   SSAVE, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, WS_DECR,  WS_INC,   PRNT3,   PRNT4,   PRNT5,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    SUND,    SCUT,    SCPY,    SPST, KC_CAPS,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     TG(_NOR),    CMDD,    CMDI, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,      RAYCA,MO(_ADJ), XXXXXXX
                                       //`--------------------------'  `--------------------------'
  ),

    [_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_F6,   KC_F4,  KC_F10,   KC_F2,  KC_F12,                       KC_F11,   KC_F3,   KC_F1,   KC_F5,   KC_F7, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_F8, XXXXXXX,                      XXXXXXX,   KC_F9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_MED] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BRID, XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJ] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX,  OS_STR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_num_word(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case ARRFAT:
            if (record->event.pressed) {
                SEND_STRING(" => ");
            }
            return false;
        case ARRSL:
            if (record->event.pressed) {
                SEND_STRING(" -> ");
            }
            return false;
        case OS_STR:
            if (record->event.pressed) {
                switch (host_os) {
                    case OS_MACOS:
                        SEND_STRING("MAC");
                        break;
                    case OS_IOS:
                        SEND_STRING("IOS");
                        break;
                    case OS_WINDOWS:
                        SEND_STRING("WIN");
                        break;
                    case OS_LINUX:
                        SEND_STRING("LINUX");
                        break;
                    case OS_UNSURE:
                        SEND_STRING("UNSURE");
                        break;
                }
            }
            return false;
        case NUMWO:
            process_num_word_activation(record);
            return false;
        case CANCEL:
            layer_off(_NUM);
            return false;
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
const uint16_t caps_combo[] PROGMEM = {NO_C, NO_COMM, COMBO_END};

const uint16_t combo_LBRC[] PROGMEM = {NO_C, NO_V, COMBO_END};
const uint16_t combo_RBRC[] PROGMEM = {NO_M, NO_COMM, COMBO_END};

const uint16_t combo_LCBR[] PROGMEM = {HOME_S, HOME_D, COMBO_END};
const uint16_t combo_RCBR[] PROGMEM = {HOME_K, HOME_L, COMBO_END};

const uint16_t combo_LPRN[] PROGMEM = {HOME_D, HOME_F, COMBO_END};
const uint16_t combo_RPRN[] PROGMEM = {HOME_J, HOME_K, COMBO_END};

const uint16_t combo_LABK[] PROGMEM = {NO_X, NO_C, COMBO_END};
const uint16_t combo_RABK[] PROGMEM = {NO_COMM, NO_DOT, COMBO_END};

const uint16_t combo_L_NUM[] PROGMEM = {KC_SPC, KC_ENT, COMBO_END};


combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),          // J and , => activate Caps Word.

    COMBO(combo_LBRC, NO_LBRC),
    COMBO(combo_RBRC, NO_RBRC),

    COMBO(combo_LCBR, NO_LCBR),
    COMBO(combo_RCBR, NO_RCBR),

    COMBO(combo_LPRN, NO_LPRN),
    COMBO(combo_RPRN, NO_RPRN),

    COMBO(combo_LABK, NO_LABK),
    COMBO(combo_RABK, NO_RABK),

    COMBO(combo_L_NUM, NUMWO)
};


bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }

    host_os = detected_os;
    return true;
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t scln_override = ko_make_basic(MOD_MASK_SHIFT, NO_SCLN, NO_COLN);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override,
	&scln_override
};
