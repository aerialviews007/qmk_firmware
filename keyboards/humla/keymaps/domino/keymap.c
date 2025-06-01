#include QMK_KEYBOARD_H
//#include "autocorrect.h"
#include "autocorrect_data.h"

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

const uint16_t PROGMEM escape[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM delete[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM backslash[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM quote[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM mute[] = {KC_VOLU, KC_VOLD, COMBO_END};


combo_t key_combos[] = {
  COMBO(escape, KC_ESC),
  COMBO(tab, KC_TAB),
  COMBO(delete, KC_DEL),
  COMBO(backslash, KC_BSLS),
  COMBO(quote, KC_QUOT),
  COMBO(mute, KC_MUTE)
};

enum layers {
    _COLEMAK,
    _NUMSYM,
    _MSFN,
    _SET
};

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NUMSYM));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MSFN));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SET));
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK-DH
 * ,----------------------------------.              ,----------------------------------.
 * |    Escape   |      |      |      |              |      |      |      |    Delete   |
 * |   Q  |   W  |   F  |   P  |   B  |              |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |Shft/A| Ctl/R| Alt/S| CMD/T|   G  |              |   M  | CMD/N| Alt/E| Ctl/I|Shft/O|
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |     Tab     |      |      |      |              |      |   Bckslsh   |    Quote    |
 * |   Z  |   X  |   C  |   D  |   V  |              |   K  |   H  |   ,  |   .  |   /  |
 * `------+------+------+------+------+--------------+------+------+------+------+------'
 *                      |      |      |      |  LSFT | LSFT |      |
 *                      | Fn/Ms|  SPC | BSPC |  ENT  | CAPW |NumSym|
 *                      `------------------------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  SFT_T(KC_A), CTL_T(KC_R), ALT_T(KC_S), GUI_T(KC_T), KC_G,                     KC_M, GUI_T(KC_N), ALT_T(KC_E), CTL_T(KC_I), SFT_T(KC_O),
  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,                     KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                            TL_UPPR, KC_SPC, KC_BSPC, KC_ENT, OSM(MOD_LSFT), TL_LOWR
),
/*
 * NUMBERS & SYMBOLS
 * ,----------------------------------.              ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |   !  |   @  |   #  |   $  |   %  |              |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |     Mute    |      |      |      |              |      |      |      |      |      |
 * | VolUp|VolDwn|   `  |   ~  |   _  |              |   -  |   +  |   =  |   [  |   ]  |
 * `------+------+------+------+------+--------------+------+------+------+------+------'
 *                      | TRNS | TRNS | TRNS | TRNS  | TRNS | TRNS |
 *                      `------------------------------------------'
 */

 [_NUMSYM] = LAYOUT(
  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,
  KC_VOLU, KC_VOLD, KC_GRV, KC_TILD, KC_UNDS,                  KC_MINS, KC_PLUS,  KC_EQL, KC_LBRC,  KC_RBRC,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
),
/*
 * MOUSE & FUNCTION
 * ,----------------------------------.              ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |      |              | MSWUP|      | MSUP |      |ScrnCp|
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |  F5  |  F6  |  F7  |  F8  |      |              |MSWDWN| MSLF | MSDW | MSRT |      |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |  F9  |  F10 |  F11 |  F12 |      |              |  UP  |  DWN |  LFT |  RT  | FrcQt|
 * `------+------+------+------+------+--------------+------+------+------+------+------'
 *                      |      |      |      | LCLK  | RCLK |      |
 *                      `------------------------------------------'
 */

 [_MSFN] = LAYOUT(
  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_NO,                   MS_WHLU, KC_NO,    MS_UP,   KC_NO,   LSG(KC_4),
  KC_F5,  KC_F6,   KC_F7,   KC_F8,   KC_NO,                   MS_WHLD, MS_LEFT,  MS_DOWN, MS_RGHT, KC_NO,
  KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_NO,                   KC_UP, KC_DOWN,  KC_LEFT, KC_RGHT,   LAG(KC_ESC),
                            KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2,   KC_NO
),
/*
 * SETTINGS
 * ,----------------------------------.              ,----------------------------------.
 * |      |      |      |      |      |              |      |      |      | RGBTG|AutoCr|
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |      |      |      |      |      |              |      |      |      |      |      |
 * |------+------+------+------+------|              |------+------+------+------+------|
 * |      |      |      |      |      |              |      |      |      |      |      |
 * `------+------+------+------+------+--------------+------+------+------+------+------'
 *                      |      |      |      |       |      |      |
 *                      `------------------------------------------'
 */

 [_SET] = LAYOUT(
  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO, KC_NO,    KC_NO,   UG_TOGG,   AC_TOGG,
  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO, KC_NO,  KC_NO, KC_NO,   KC_NO,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO, KC_NO,  KC_NO, KC_NO,   KC_NO,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS
)

};


