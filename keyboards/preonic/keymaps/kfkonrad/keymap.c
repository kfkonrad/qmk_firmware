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
    KFK_M2,
    KFK_M3,
    KFK_M4,
    KFK_M5,
    KFK_M6
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,      KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,    KC_DEL,
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,      KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_UP,   KC_ENT,
  KC_LCTL, KC_MINS, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_SLSH,   KC_LEFT, KC_DOWN, KC_RIGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | PGUP |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | PGDN |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM,    KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  XXXXXXX, ALGR(KC_Q), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_LPRN, KC_PGDN,
  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_LBRC, KC_RBRC,
  KC_LSFT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_TILD, KC_1,    KC_2,    KC_3,    KC_LCBR, KC_RCBR,
  KC_LCTL, XXXXXXX,    KC_LALT, KC_LGUI, LOWER,   XXXXXXX, XXXXXXX, RAISE,   KC_BSLS, KC_0,    KC_MINS, KC_EQL
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | PGUP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | PGDN |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGUP,
  KC_MUTE, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,
  KC_VOLU, KC_F4,   KC_F5,   KC_F6,   KC_F11,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU,
  KC_VOLD, KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_GRV,  KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,
  KC_LCTL, XXXXXXX, KC_LALT, KC_LGUI, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KFK_M1,  KFK_M4,  XXXXXXX, XXXXXXX, XXXXXXX, RESET,   DEBUG,
  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KFK_M2,  KFK_M5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KFK_M3,  KFK_M6, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   MU_ON,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, AU_OFF,  MU_OFF
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef AUDIO_ENABLE
float kfk_tune1[][2] = SONG(KFK_TUNE1);
float kfk_tune2[][2] = SONG(KFK_TUNE2);
float windows_xp_startup[][2] = SONG(WINDOWS_XP_STARTUP_SOUND);
float windows_xp_shutdown[][2] = SONG(WINDOWS_XP_SHUTDOWN_SOUND);
float zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
float zelda_treasure[][2] = SONG(ZELDA_TREASURE);

void keyboard_post_init_user() {
  KFK_PLAY_SONG(WINDOWS_XP_STARTUP_SOUND_BPM, windows_xp_startup);
}

void shutdown_user() {
    uint16_t timer_start = timer_read();
    KFK_PLAY_SONG(WINDOWS_XP_SHUTDOWN_SOUND_BPM, windows_xp_shutdown);
    // this can be 250ms shorter than the song because of the timer delay
    // introduced by the calling function reset_keyboard
    while (timer_elapsed(timer_start) < SHUTDOWN_DURATION - 250) wait_ms(1);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  KFK_INITIALIZE_PROCESS_RECORD_USER();
  switch (keycode) {
    case KC_BSPC: return KFK_SEND_INSTEAD_WHEN_SHIFT(KC_DEL) && KFK_SEND_INSTEAD_WHEN_CTRL(KC_DEL);
    #ifdef AUDIO_ENABLE
      case KFK_M1: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(KFK_TUNE1_BPM, kfk_tune1);
      case KFK_M2: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(KFK_TUNE2_BPM, kfk_tune2);
      case KFK_M3: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(WINDOWS_XP_STARTUP_SOUND_BPM, windows_xp_startup);
      case KFK_M4: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(WINDOWS_XP_SHUTDOWN_SOUND_BPM, windows_xp_shutdown);
      case KFK_M5: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(ZELDA_PUZZLE_BPM, zelda_puzzle);
      case KFK_M6: KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(ZELDA_TREASURE_BPM, zelda_treasure);
    #endif
  }
  return true;
}
