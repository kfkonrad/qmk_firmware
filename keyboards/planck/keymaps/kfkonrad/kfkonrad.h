#pragma once

#include QMK_KEYBOARD_H

extern uint8_t mod_state;

#define KFK_INITIALIZE_PROCESS_RECORD_USER() \
    mod_state = get_mods();

bool kfk_send_instead_when_shifted(keyrecord_t *record, int keycode);

#define KFK_SEND_INSTEAD_WHEN_SHIFTED(keycode) \
  return kfk_send_instead_when_shifted(record, keycode);
