#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define RGBLIGHT_LED_COUNT 1
#define RGBLIGHT_LAYERS

#define FLOW_TAP_TERM 150

#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
