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

#include "planck.h"

// Import keymaps stuff
#include "keymap_bepo.h"
#include "keymap_french.h"

// Unassigned keys
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// LED Control
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT true
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#include "rgb_matrix.h"

// Define layers
enum planck_layers {
  _BEPO,
  _SYMBOL,
  _FUNCTION,
  _WEIRD,
  _AZERTY,
  _AZERTY_SYMBOL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Es/Sh : Esc on tap, Shift on hold */

/* Bépo base layer
 * ,-----------------------------------------------------------------------------------.
 * | LAY1 |   B  |   É  |   P  |   O  |   Z  |   W  |   V  |   D  |   L  |   J  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Es/Sh|   A  |   U  |   I  |   E  |   M  |   C  |   T  |   S  |   R  |   N  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   È  |   À  |   Y  |   X  |   Ç  |   K  |   Q  |   G  |   H  |   F  | :    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUM  | Ctrl | Alt  | Super| Lower|    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = {
  {       MO(_FUNCTION),    BP_B, BP_ECUT,    BP_P,       BP_O,    BP_Z,    BP_W,        BP_V,    BP_D,    BP_L,    BP_J,  KC_BSPC},
  {MT(MOD_RSFT, KC_ESC),    BP_A,    BP_U,    BP_I,       BP_E,    BP_M,    BP_C,        BP_T,    BP_S,    BP_R,    BP_N,   KC_ENT},
  {              KC_TAB, BP_EGRV, BP_AGRV,    BP_Y,       BP_X, BP_CCED,    BP_K,        BP_Q,    BP_G,    BP_H,    BP_F, BP_COLON},
  {         TG(_AZERTY), KC_LCTL, KC_LALT, KC_LGUI, MO(_WEIRD),  KC_SPC,  KC_SPC, MO(_SYMBOL), KC_LEFT, KC_DOWN,   KC_UP,  KC_RGHT}
},

/* Symbol layer
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
[_SYMBOL] = {
  {_______,BP_UNDS,BP_QEST, BP_HASH, BP_EXLM, BP_SCLN, BP_COLN, BP_AMPR,  BP_DLR, BP_DTLD, BP_PIPE, _______ },
  {_______,  BP_AT,BP_DQOT, BP_LCBR, BP_RCBR, BP_COMM, BP_DCRC, BP_LPRN, BP_RPRN, BP_PLUS, BP_MINS, _______ },
  {_______,BP_BSLS,BP_SLSH, BP_LESS, BP_GRTR,  BP_DOT, BP_APOS, BP_LBRC, BP_RBRC, BP_ASTR,  BP_EQL, BP_PERC },
  {_______,_______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
},


/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  | Vol- | Vol+ |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | Play | Stop |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | Prev | Next |   1  |   2  |   3  | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = {
  {_______,  KC_F1,  KC_F2,   KC_F3,   KC_F4, KC_VOLD, KC_VOLU,    BP_7,    BP_8,    BP_9, BP_MINS, _______ },
  {_______,  KC_F5,  KC_F6,   KC_F7,   KC_F8, KC_MPLY, KC_MSTP,    BP_4,    BP_5,    BP_6, BP_PLUS, _______ },
  {_______,  KC_F9, KC_F10,  KC_F11,  KC_F12, KC_MPRV, KC_MNXT,    BP_1,    BP_2,    BP_3,  KC_ENT, _______ },
  {_______,_______,_______, _______, _______, _______, _______, _______,    BP_0,  BP_DOT, _______, _______ }
},


/* Weird layer
 * ,-----------------------------------------------------------------------------------.
 * |      |   …  |   ’  |   `  |   Œ  |   ə  |   ˘  |   ¤  |   ¶  |  «/“ |  »/” |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   Æ  |   ù  |   ¼  |   ½  |   ¯  |   ©  |   —  |   ẞ  |   ±  |   −  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   °  |   ÷  |   ≤  |   ≥  |  Ins |  DGr |      | grec |   ×  |   ≠  |   ‰  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_WEIRD] = {
  {_______,BP_ELPS,BP_APOS,  BP_GRV,   BP_OE, BP_SCWA, BP_DBRV, BP_DCUR, BP_PARG, BP_LGIL, BP_RGIL, _______ },
  {_______,  BP_AE,BP_UGRV, BP_1QRT, BP_1HLF, BP_DMCR, BP_CPRT, BP_NDSH, BP_SRPS, BP_PSMS, BP_MDSH, _______ },
  {_______,BP_DEGR,BP_OBEL, BP_LEQL, BP_GEQL,  KC_INS, BP_DGRK, XXXXXXX, BP_DGRK, BP_TIMS, BP_DIFF, BP_PMIL },
  {_______,_______,_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END }
},


/* Write bépo when the system is configured in AZERTY
 * ,-----------------------------------------------------------------------------------.
 * |      |   B  |   É  |   P  |   O  |   Z  |   W  |   V  |   D  |   L  |   J  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   U  |   I  |   E  |   M  |   C  |   T  |   S  |   R  |   N  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   È  |   À  |   Y  |   X  |   Ç  |   K  |   Q  |   G  |   H  |   F  | :    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BÉPO | Ctrl | Alt  | XXXXX| Lower|    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = {
  {    _______,    KC_B, FR_EACU,    KC_P,       KC_O,    FR_Z,    FR_W,        KC_V,    KC_D,    KC_L,    KC_J, _______},
  {    _______,    FR_A,    KC_U,    KC_I,       KC_E,    FR_M,    KC_C,        KC_T,    KC_S,    KC_R,    KC_N, _______},
  {    _______, FR_EGRV, FR_AGRV,    KC_Y,       KC_X, FR_CCED,    KC_K,        FR_Q,    KC_G,    KC_H,    KC_F, FR_COLN},
  {TG(_AZERTY), KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,  KC_SPC,  KC_SPC, MO(_AZERTY_SYMBOL), KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT}
},

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
[_AZERTY_SYMBOL] = {
  {    _______, FR_UNDS, FR_QUES, FR_HASH, FR_EXLM, FR_SCLN, FR_COLN, FR_AMP, FR_DLR,    FR_TILD, FR_PIPE, _______},
  {    _______,    FR_AT,    FR_QUOT,    FR_LCBR,   FR_RCBR,    FR_COMM, FR_CCIRC,        FR_LPRN,    FR_RPRN,    FR_PLUS,    FR_MINS, _______},
  {    _______, FR_BSLS, FR_SLSH, FR_LESS, FR_GRTR, FR_DOT, FR_APOS, FR_LBRC, FR_RBRC,    FR_MU, FR_EQL, FR_PERC},
  {_______, _______, _______, _______, _______,  _______,  _______, _______, _______,_______,   _______, _______}
}


};

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

/*
 *
 * RGB definitions
 *
 */



const uint8_t RGB_CONFIG [][DRIVER_LED_TOTAL] = {

/* Bépo base layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   B  |   É  |   P  |   O  |   Z  |   W  |   V  |   D  |   L  |   J  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   U  |   I  |   E  |   M  |   C  |   T  |   S  |   R  |   N  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Esc  |   È  |   À  |   Y  |   X  |   Ç  |   K  |   Q  |   G  |   H  |   F  | :    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUM  | Ctrl | Alt  | Super| Lower|    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
{
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1
},

/* Symbol layer
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
{
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
},


/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  | Vol- | Vol+ |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  | Play | Stop |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 | Prev | Next |   1  |   2  |   3  | Enter|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
{
    0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0
},


/* Weird layer
 * ,-----------------------------------------------------------------------------------.
 * |      |   …  |   ’  |   `  |   Œ  |   ə  |   ˘  |   ¤  |   ¶  |   «  |   »  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   Æ  |   ù  |   ¼  |   ½  |   ¯  |   ©  |   —  |   ẞ  |   ±  |   −  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   °  |   ÷  |   ≤  |   ≥  |  Ins |  DGr |   “  |   ”  |   ×  |   ≠  |   ‰  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDn | PgUp |  End |
 * `-----------------------------------------------------------------------------------'
 */
{
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2
},

};

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        switch (layer) {
            case _BEPO:
                if (RGB_CONFIG[layer][i] == 2) {
                    rgb_matrix_set_color (i, 0x99, 0xF5, 0xFF) ;
                } else if (RGB_CONFIG[layer][i] == 1) {
                    rgb_matrix_set_color (i, 0x00, 0xFF, 0xFF) ;
                } else {
                    rgb_matrix_set_color (i, 0x00, 0x60, 0x60) ;
                }
                break;
            case _SYMBOL:
                if (RGB_CONFIG[layer][i] == 2) {
                    rgb_matrix_set_color (i, 0x99, 0xF5, 0xFF) ;
                } else if (RGB_CONFIG[layer][i] == 1) {
                    rgb_matrix_set_color (i, 0x00, 0xFF, 0xFF) ;
                } else {
                    rgb_matrix_set_color (i, 0x00, 0x60, 0x60) ;
                }
                break;
            case _FUNCTION:
                if (RGB_CONFIG[layer][i] == 2) {
                    rgb_matrix_set_color (i, 0x99, 0xF5, 0xFF) ;
                } else if (RGB_CONFIG[layer][i] == 1) {
                    rgb_matrix_set_color (i, 0x00, 0xFF, 0xFF) ;
                } else {
                    rgb_matrix_set_color (i, 0x00, 0x60, 0x60) ;
                }
                break;
            case _WEIRD:
                if (RGB_CONFIG[layer][i] == 2) {
                    rgb_matrix_set_color (i, 0x99, 0xF5, 0xFF) ;
                } else if (RGB_CONFIG[layer][i] == 1) {
                    rgb_matrix_set_color (i, 0x00, 0xFF, 0xFF) ;
                } else {
                    rgb_matrix_set_color (i, 0x00, 0x60, 0x60) ;
                }
                break;
            default: //  for any other layers, or the default layer
                break;
        }
    }
}
