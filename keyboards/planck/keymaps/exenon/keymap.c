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
enum planck_layers { _AZERTY, _AZERTY_SYMBOL, _SYMBOL, _FUNCTION, _WEIRD };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Write bépo when the system is configured in AZERTY
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   B  |   É  |   P  |   O  |   Z  |   W  |   V  |   D  |   L  |   J  | Back |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Shift|   A  |   U  |   I  |   E  |   M  |   C  |   T  |   S  |   R  |   N  | Enter|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Tab  |   È  |   À  |   Y  |   X  |   Ç  |   K  |   Q  |   G  |   H  |   F  | :    |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | MOVL | Ctrl | Alt  | META | Lower|    Space    |Raise | Left | Down |  Up  | Right|
     * `-----------------------------------------------------------------------------------'
     */
    [_AZERTY] = LAYOUT_planck_grid(KC_ESC, KC_B, FR_EACU, KC_P, KC_O, KC_Z, KC_W, KC_V, KC_D, KC_L, KC_J, KC_BSPC, KC_LSFT, KC_A, KC_U, KC_I, KC_E, KC_M, KC_C, KC_T, KC_S, KC_R, KC_N, KC_ENT, KC_TAB, FR_EGRV, FR_AGRV, KC_Y, KC_X, FR_CCED, KC_K, KC_Q, KC_G, KC_H, KC_F, FR_COLN, MO(1), KC_LCTL, KC_LALT, KC_LGUI, KC_WWW_BACK, KC_SPC, KC_SPC, KC_WWW_FORWARD, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT),

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
    [_AZERTY_SYMBOL] = LAYOUT_planck_grid(_______, FR_UNDS, FR_QUES, FR_HASH, FR_EXLM, FR_SCLN, FR_COLN, FR_AMPR, FR_DLR, FR_TILD, FR_PIPE, _______, _______, FR_AT, FR_QUOT, FR_LCBR, FR_RCBR, FR_COMM, FR_CIRC, FR_LPRN, FR_RPRN, FR_PLUS, FR_MINS, _______, _______, FR_BSLS, FR_SLSH, FR_LABK, FR_RABK, FR_DOT, FR_QUOT, FR_LBRC, FR_RBRC, _______, FR_EQL, FR_PERC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};
