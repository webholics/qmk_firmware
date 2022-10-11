#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE,
    LAYER_GAMING,
    LAYER_SETTINGS,
    LAYER_FN
};

// Tab dance for FN key
// ----------------------------------------------------------------------------------------------

enum unicode_names {
    UM_LC_SS,
    UM_LC_AE,
    UM_UC_AE,
    UM_LC_OE,
    UM_UC_OE,
    UM_LC_UE,
    UM_UC_UE,
};

const uint32_t PROGMEM unicode_map[] = {
    [UM_LC_SS] = 0xDF,  // ß
    [UM_LC_AE] = 0xE4, // ä
    [UM_UC_AE] = 0xC4, // Ä
    [UM_LC_OE] = 0xF6, // ö
    [UM_UC_OE] = 0xD6, // Ö
    [UM_LC_UE] = 0xFC, // ü
    [UM_UC_UE] = 0xDC, // Ü
};

// Keymaps
// ----------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[LAYER_BASE] = LAYOUT_65_ansi_blocker(
			KC_GESC,                KC_1,       KC_2,       KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,         KC_MINS,  KC_EQL,  KC_BSPC,   KC_DEL,
		    KC_TAB,                 KC_Q,       KC_W,       KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,         KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			CTL_T(KC_CAPS),         KC_A,       KC_S,       KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,      KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,                KC_Z,       KC_X,       KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,      KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL,                KC_LALT,    KC_LGUI,                  KC_SPC,                         KC_RGUI,  MO(LAYER_FN), KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[LAYER_GAMING] = LAYOUT_65_ansi_blocker(
			KC_TRNS,                KC_TRNS,     KC_TRNS,    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
		    KC_TRNS,                KC_TRNS,     KC_TRNS,    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
			KC_LCTL,                KC_TRNS,     KC_TRNS,    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS,
		    KC_TRNS,                KC_TRNS,     KC_TRNS,    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS,
		    KC_TRNS,                KC_TRNS,     KC_TRNS,                     LCTL(KC_SPC),              KC_TRNS,          KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS),
		[LAYER_SETTINGS] = LAYOUT_65_ansi_blocker(
			TO(LAYER_BASE),         UC_M_MA,     UC_M_WC,    UC_M_LN,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_TRNS,
		    KC_TRNS,                RGB_TOG,     RGB_MOD,    RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    QK_BOOT,  KC_TRNS,
			KC_TRNS,                RGB_SPI,     RGB_SPD,    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                EEP_RST,  KC_TRNS,
		    KC_TRNS,                KC_TRNS,     KC_TRNS,    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS,
		    KC_TRNS,                KC_TRNS,     KC_TRNS,                     KC_TRNS,                   KC_TRNS,          KC_TRNS,    KC_TRNS,                KC_TRNS,  KC_TRNS),
		[LAYER_FN] = LAYOUT_65_ansi_blocker(
			KC_GRAVE,               KC_F1,                       KC_F2,          KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,                   KC_F8,   KC_F9,                     KC_F10,     KC_F11,     KC_F12,     KC_DEL,   TO(LAYER_BASE),
		    KC_TRNS,                KC_TRNS,                     KC_TRNS,        KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, XP(UM_LC_UE, UM_UC_UE),  KC_TRNS, XP(UM_LC_OE, UM_UC_OE),    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  TO(LAYER_GAMING),
			KC_TRNS,                XP(UM_LC_AE, UM_UC_AE),      X(UM_LC_SS),    KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS,                   KC_TRNS,    KC_TRNS,                KC_TRNS,  TO(LAYER_SETTINGS),
		    KC_TRNS,                KC_TRNS,                     KC_TRNS,        KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS,                   KC_TRNS,    KC_TRNS,                KC_VOLU,  KC_MUTE,
		    KC_TRNS,                KC_TRNS,                     KC_TRNS,                         KC_MPLY,                                   KC_TRNS,                            KC_TRNS,    KC_MPRV,                KC_VOLD,  KC_MNXT),
};

