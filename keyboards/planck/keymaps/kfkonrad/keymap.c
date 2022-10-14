#include QMK_KEYBOARD_H
#include "kfkonrad.h"
#ifdef AUDIO_ENABLE
    #include "user_song_list.h"
#endif

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
    KFK_M1 = SAFE_RANGE,
    KFK_M2
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Lshft |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LCtrl |   -  | LAlt | LGui | Lower|    Space    | Raise|   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_UP,   KC_ENT,
    KC_LCTL, KC_MINS, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_SLSH,   KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* LOWER
 * .-----------------------------------------------------------------------------------.
 * |      |   @  |      |      |      |      |      |   7  |   8  |   9  |   (  |   )  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   [  |   ]  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |Lshft |      |      |      |      |   `  |   ~  |   1  |   2  |   3  |   {  |   }  |
 * |------+------+------+------+------+------+------|------+------+------+------+------|
 * |LCtrl |      | LAlt | LGui | Lower|             |Raise |   \  |   0  |   -  |   =  |
 * `-----------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, ALGR(KC_Q), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_LPRN, KC_RPRN,
    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_LBRC, KC_RBRC,
    KC_LSFT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_TILD, KC_1,    KC_2,    KC_3,    KC_LCBR, KC_RCBR,
    KC_LCTL, XXXXXXX,    KC_LALT, KC_LGUI, LOWER,   XXXXXXX, XXXXXXX, RAISE,   KC_BSLS, KC_0,    KC_MINS, KC_EQL
  ),

/* RAISE
 * .-----------------------------------------------------------------------------------.
 * | Mute |  F7  |  F8  |  F9  |  F12 |      |      |      |      |      | PGUP |Lshft |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * | Vol+ |  F4  |  F5  |  F6  |  F11 |      |      |      |      |      | PGDN | BRI+ |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * | Vol- |  F1  |  F2  |  F3  |  F10 |   `  |   ~  |      |      |      |      | BRI- |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LCtrl |      | LAlt | LGui |Lower |             | Raise|      | |<<  | >/|| | >>|  |
 * `-----------------------------------------------------------------------------------'
 */

  [_RAISE] = LAYOUT_planck_grid(
    KC_MUTE, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_LSFT,
    KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_BRIU,
    KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
    KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT
  ),

/* ADJUST (LOWER + RAISE)
 * ,-----------------------------------------------------------------------------------.
 * | RGB  | HUE+ | SAT+ | BRGT+|      |KFK_M1|      |      |      |      |Reset |Debug |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RGBMOD| HUE- | SAT- | BRGT-|      |KFK_M2|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |Aud on|Mus on|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |LOWER |             |RAISE |      |      |Audoff|Musoff|
 * `-----------------------------------------------------------------------------------'
 */
 
[_ADJUST] = LAYOUT_planck_grid(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KFK_M1,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   DEBUG,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KFK_M2,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   MU_ON,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, AU_OFF,  MU_OFF
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef AUDIO_ENABLE
float zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
float zelda_treasure[][2] = SONG(ZELDA_TREASURE);

void keyboard_post_init_user() {
  KFK_PLAY_SONG(ZELDA_PUZZLE_BPM, zelda_puzzle);
}

void shutdown_user() {
    uint16_t timer_start = timer_read();
    KFK_PLAY_SONG(ZELDA_TREASURE_BPM, zelda_treasure);
    // this can be 250ms shorter than the song because of the timer delay
    // introduced by the calling function reset_keyboard
    while (timer_elapsed(timer_start) < ZELDA_TREASURE_DURATION - 250) wait_ms(1);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  KFK_INITIALIZE_PROCESS_RECORD_USER();
  switch (keycode) {
    case KC_BSPC: return KFK_SEND_INSTEAD_WHEN_SHIFT(KC_DEL) && KFK_SEND_INSTEAD_WHEN_CTRL(KC_DEL);
    #ifdef AUDIO_ENABLE
      case KFK_M1: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(ZELDA_PUZZLE_BPM, zelda_puzzle);
      case KFK_M2: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(ZELDA_TREASURE_BPM, zelda_treasure);
    #endif
  }
  return true;
}
