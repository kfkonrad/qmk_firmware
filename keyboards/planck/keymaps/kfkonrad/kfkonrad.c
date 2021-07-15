#include "kfkonrad.h"

uint8_t mod_state = false;

bool kfk_send_instead_when_shifted(keyrecord_t *record, int keycode) {
    static bool key_registered;
    if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(keycode);
            key_registered = true;
            set_mods(mod_state);
            return false;
        }
    } else {
        if (key_registered) {
            unregister_code(keycode);
            key_registered = false;
            return false;
        }
    }
    return true;
}
