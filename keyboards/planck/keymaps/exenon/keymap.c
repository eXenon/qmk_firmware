/* Copyright 2017 Xavier Nunn
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

#include QMK_KEYBOARD_H

// Import keymaps stuff
#include "keymap_french.h"

// Unassigned keys
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// LED Control
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT true
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#include "rgb_matrix.h"

// Define layers
enum planck_layers { _AZERTY, _AZERTY_SYMBOL, _NUMPAD, _WEIRD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Write bépo when the system is configured in AZERTY
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   B  |   É  |   P  |   O  |   Z  |   W  |   V  |   D  |   L  |   J  | Back |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Shift|   A  |   U  |   I  |   E  |   M  |   C  |   T  |   S  |   R  |   N  | Enter|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Tab  |   È  |   À  |   Y  |   X  |   Ç  |   K  |   Q  |   G  |   H  |   F  | :    |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | ->N  | Ctrl | Alt  | META | ->AS |    Space    | ->W  | Left | Down |  Up  | Right|
     * `-----------------------------------------------------------------------------------'
     */
    [_AZERTY] = LAYOUT_planck_grid(
            KC_ESC,  KC_B,    FR_EACU, KC_P,    KC_O,  KC_Z,    KC_W,   KC_V,  KC_D,    KC_L,    KC_J,  KC_BSPC,
            KC_LSFT, KC_A,    KC_U,    KC_I,    KC_E,  KC_M,    KC_C,   KC_T,  KC_S,    KC_R,    KC_N,  KC_ENT,
            KC_TAB,  FR_EGRV, FR_AGRV, KC_Y,    KC_X,  FR_CCED, KC_K,   KC_Q,  KC_G,    KC_H,    KC_F,  FR_COLN,
            MO(2),   KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC,  KC_SPC, MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
    ),

    /* Write bépo when the system is configured in AZERTY - symbol layer
     * ,-----------------------------------------------------------------------------------.
     * |      |   _  |   ?  |   #  |   !  |   ;  |   :  |   &  |   $  |   ~  |   |  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   @  |   "  |   {  |   }  |   ,  |   ^  |   (  |   )  |   +  |   -  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |   \  |   /  |   <  |   >  |   .  |   '  |   [  |   ]  |   *  |   =  |   %  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_AZERTY_SYMBOL] = LAYOUT_planck_grid(
            _______, FR_UNDS, FR_QUES, FR_HASH, FR_EXLM, FR_SCLN, FR_COLN, FR_AMPR, FR_DLR,  FR_TILD, FR_PIPE, _______,
            _______, FR_AT,   FR_QUOT, FR_LCBR, FR_RCBR, FR_COMM, FR_CIRC, FR_LPRN, FR_RPRN, FR_PLUS, FR_MINS, _______,
            _______, FR_BSLS, FR_SLSH, FR_LABK, FR_RABK, FR_DOT,  FR_QUOT, FR_LBRC, FR_RBRC, _______, FR_EQL,  FR_PERC,
            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Numpad layer
     * ,-----------------------------------------------------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  | Vol+ | Vol- |   7  |   8  |   9  |   /  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |  F5  |  F6  |  F7  |  F8  | Prev | Next |   4  |   5  |   6  |   *  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |  F9  |  F10 |  F11 |  F12 | Play | Mute |   1  |   2  |   3  |   -  |   =  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      |   0  |      |   +  |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_AZERTY_SYMBOL] = LAYOUT_planck_grid(
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_VOLU, KC_VOLD, KC_P7,   KC_P8, KC_P9,   KC_PSLS, _______,
            _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MPRV, KC_MNXT, KC_P4,   KC_P5, KC_P6,   KC_PAST, _______,
            _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPLY, KC_MUTE, KC_P1,   KC_P2, KC_P3,   KC_PMNS, FR_EQL,
            _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, _______, KC_PPLS, _______
    )
};
