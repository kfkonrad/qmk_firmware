#pragma once

#include QMK_KEYBOARD_H

extern uint8_t mod_state;

#define KFK_INITIALIZE_PROCESS_RECORD_USER() \
    mod_state = get_mods();

bool kfk_send_instead_when(int keycode, keyrecord_t *record, uint8_t mask);

#define KFK_SEND_INSTEAD_WHEN_SHIFT(keycode) \
  return kfk_send_instead_when(keycode, record, MOD_MASK_SHIFT);

#define KFK_SEND_INSTEAD_WHEN_CTRL(keycode) \
  return kfk_send_instead_when(keycode, record, MOD_MASK_CTRL);

#define KFK_SEND_INSTEAD_WHEN_ALT(keycode) \
  return kfk_send_instead_when(keycode, record, MOD_MASK_ALT);

#define KFK_SEND_INSTEAD_WHEN_GUI(keycode) \
  return kfk_send_instead_when(keycode, record, MOD_MASK_GUI);

#define KFK_PLAY_SONG(bpm, songname) \
    audio_set_tempo(bpm); \
    PLAY_SONG(songname); \

#define KFK_PLAY_SONG_FROM_PROCESS_RECORD_USER(bpm, songname) \
    if (record->event.pressed) { \
        KFK_PLAY_SONG(bpm, songname) \
    } \
    return false;

#define ZELDA_TREASURE_DURATION 1500
#define ZELDA_PUZZLE_DURATION 2500

#define ZELDA_TREASURE_BPM 70
#define ZELDA_PUZZLE_BPM 90
