/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NM,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Num  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, MO(_NM),KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Num 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |      |      |      |      | Tab  |   7  |  8   |   9  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  /   |   4  |  5   |   6  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  *   |   1  |  2   |   3  |  +   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |  00  |   .  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_NM] = {
  {_______, _______, _______, _______, _______, _______, _______, KC_TAB,  KC_7,    KC_8,   KC_9,   KC_BSPC},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_SLSH, KC_4,    KC_5,   KC_6,   KC_MINS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_ASTR, KC_1,    KC_2,   KC_3,   KC_PLUS},
  {_______, MO(_NM), _______, _______, _______, _______, _______, _______, KC_0,    KC_0,   KC_DOT, KC_ENT }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |   W  |      |      |      |      | BTN1 | BTN3 | BTN2 |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |      |      |      |   -  |   =  |      |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   [  |   ]  |      |      |      |      |   <  |  >   |  ?   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, _______, KC_MS_U, _______, _______, _______, _______, KC_BTN1, KC_BTN3,    KC_BTN2,   _______,    KC_BSPC},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PLUS, _______, _______, KC_MINS, KC_EQL,     _______,   _______,    KC_BSLS},
  {_______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, S(KC_COMM), S(KC_DOT), S(KC_SLSH), _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT,    KC_VOLD,   KC_VOLU,    KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   {  |   }  |      |      |      |      |   (  |   )  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC},
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE},
  {_______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug |      |      |      |      |      |      |Pg Up |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |PgDown| Home | End  | Left | Down | Up   | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, KC_PGUP, _______ ,_______, _______, KC_DEL },
  {_______, _______, _______, KC_PGDN, KC_HOME, KC_END,  KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case NUM_PAD:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_NUM_PAD);
    //   }
    //   return false;
    //   break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}