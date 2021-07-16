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
