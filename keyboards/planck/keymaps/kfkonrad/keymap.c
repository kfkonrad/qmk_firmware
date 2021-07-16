#include QMK_KEYBOARD_H
#include "kfkonrad.h"

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Lshft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LCtrl |   -  | LAlt | LGui | Lower|    Space    | Raise|   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_UP,   KC_ENT,
    KC_LCTL, KC_MINS, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_SLSH,   KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* LOWER
 * .-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   (  |   )  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   [  |   ]  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |Lshft |      |      |      |      |   `  |   ~  |   1  |   2  |   3  |   {  |   }  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |LCtrl |      | LAlt | LGui | Lower|             |Raise |   \  |   0  |      |   =  |
 * `-----------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_LPRN, KC_RPRN,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_LBRC, KC_RBRC,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_TILD, KC_1,    KC_2,    KC_3,    KC_LCBR, KC_RCBR,
    KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, LOWER,   XXXXXXX, XXXXXXX, RAISE,   KC_BSLS, KC_0, XXXXXXX, KC_EQL
  ),

/* RAISE
 * .-----------------------------------------------------------------------------------.
 * | Mute |  F7  |  F8  |  F9  |  F12 |      |      |      |      |      |      |      |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ |  F4  |  F5  |  F6  |  F11 |      |      |      |      |      |      |      |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- |  F1  |  F2  |  F3  |  F10 |   `  |   ~  |      |      |      |      |Lshft |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LCtrl |      | LAlt | LGui |Lower |             | Raise|      | |<<  | >/|| | >>|  |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT_planck_grid(
    KC_MUTE, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
    KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT
  ),

/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * | RGB  | HUE+ | SAT+ | BRGT+|      |      |      |      |      |      |Reset |Debug |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RGBMOD| HUE- | SAT- | BRGT-|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |LOWER |             |RAISE |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   DEBUG,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  KFK_INITIALIZE_PROCESS_RECORD_USER();
  switch (keycode) {
    case KC_BSPC: KFK_SEND_INSTEAD_WHEN_SHIFT(KC_DEL);
  }
  return true;
}
