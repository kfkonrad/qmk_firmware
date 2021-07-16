#include "kfkonrad.h"

uint8_t mod_state = false;

bool kfk_send_instead_when(int keycode, keyrecord_t *record, uint8_t mask) {
    static bool key_registered;
    if (record->event.pressed) {
        if (mod_state & mask) {
            del_mods(mask);
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
