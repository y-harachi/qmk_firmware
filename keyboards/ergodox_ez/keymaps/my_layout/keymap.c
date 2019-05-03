#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * Japanese :
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |ESC     |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |\|      |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |Tab     |   Q  |   W  |   E  |   R  |   T  | [    |           | {    |   Y  |   U  |   I  |   O  |   P  |-       |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |LCtrl   |A     |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|: / Cmd |
 * |--------+------+------+------+------+------| ]    |           | }    |------+------+------+------+------+--------|
 * | LShift |Z     |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |/ / L1|_/RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LGui  |LAlt  |AltShf|GuiSft|Lang2/L1|                                     |Lang1/L1|LEFT|UP  |Down  |RIGHT     |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                       |LGuiEnt|Home  |       |PgUp  |Del   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |End   |       |PgDn  |        |      |
 *                                 | Space|LShift|------|       |------|Back    |Enter |
 *                                 |      |      |Enter |       |Del   |Space   |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,
  KC_TAB,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    JA_LBRC,
  KC_LCTL,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         KC_Z, KC_X,          KC_C,    KC_V,    KC_B,    JA_RBRC,
  KC_LGUI, KC_LALT,     LALT(KC_LSFT), LGUI(KC_LSFT),LT(SYMB,KC_LANG2),
                                                           LGUI(KC_ENT),   KC_HOME,
                                                                          KC_END,
                                                         KC_SPC, KC_LSFT, KC_ENT,
  // right hand
  KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           JA_ENVL,
  LSFT(JA_LBRC),     KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,         KC_MINS,
  KC_H,         KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), GUI_T(JA_CLON),
  LSFT(JA_RBRC), KC_N,    KC_M,    KC_COMM, KC_DOT,            LT(SYMB, KC_SLSH), SFT_T(JA_ENUN),
  LT(SYMB,KC_LANG1),KC_LEFT, KC_UP, KC_DOWN, KC_RGHT,
  KC_PGUP,KC_DEL,
  KC_PGDN,
  KC_DEL, KC_BSPC, KC_ENT
),
/* Keymap 1: Symbol Layer
 * 
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Esc      |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |^~      |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |      |7     |8     |9     |@     |[       |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   [  |   ]  |   `  |------|           |------|      |4     |5     |6     |   +  |]       |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   (  |   )  |   ~  |      |           |      |   &  |1     |2     |3     |   /  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |0     |    . |      |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, JA_AT,   LSFT(JA_LBRC), LSFT(JA_RBRC), LSFT(JA_ENVL), KC_TRNS,
  KC_TRNS, KC_HASH, KC_DLR,  JA_LBRC, JA_RBRC, KC_GRV,
  KC_TRNS, KC_PERC, JA_HAT, LSFT(KC_8), LSFT(KC_9), LSFT(JA_HAT), KC_TRNS,
  EPRM,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  JA_HAT,
  KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    JA_AT, JA_LBRC,
           KC_TRNS, KC_4,    KC_5,    KC_6,    LSFT(KC_SCLN), JA_RBRC,
  KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_TRNS,
  KC_0, KC_DOT,  KC_TRNS,    LSFT(KC_MINS),  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |Mute  |      |      |      |      |      |Sleep   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |VolUp |Home  |PgDn  |PgUp  |End   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|Left  |DOWN  |UP    |Right |      |  Play  |
 * |--------+------+------+------+------+------|      |           |VolDn |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |Reset |       |Sleep |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, RESET,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSFT(LCTL(KC_POWER)),
  KC_VOLU, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS, KC_TRNS,
           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_MPLY,
  KC_VOLD, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  LSFT(LCTL(KC_POWER)), KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
