#include QMK_KEYBOARD_H
#include "animation.c"

/*按键映射*/
/*关于keymap和层的解读，详见 https://docs.qmk.fm/#/feature_layers 和 https://docs.qmk.fm/#/keymap */
/*可用的键详见 https://docs.qmk.fm/#/keycodes */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/*默认层*/
    [0] = LAYOUT (
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_DEL , TO(1)  ,
	KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, KC_HOME,
	KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC, KC_BSLS, KC_PSCR,
	KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
	KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,          KC_UP  ,
	KC_LCTL, KC_LWIN, KC_LALT,                   KC_SPC ,                            KC_RALT, MO(1)  , KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT	//MO()所指层的相同位置，需要写KC_TRNS，不能是XXXXXXX
    ),
	/*Fn层*/
    [1] = LAYOUT (
    QK_BOOT, EE_CLR , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0)  ,
	XXXXXXX, RGB_HUI, RGB_SAI, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, RGB_HUD, RGB_SAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_VAI,
	XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                            XXXXXXX, KC_TRNS, RGB_TOG, XXXXXXX, RGB_VAD, RGB_MOD	//MO()所指层的相同位置，需要写KC_TRNS，不能是XXXXXXX
    )
};	//这里的分号一定不要忘记

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI) }
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_90; /*将屏幕旋转90度*/
}

bool oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case 0: /*如果在默认层*/
			render_anime1(); /*显示图形一*/
			break;
        case 1: /*如果在Fn层*/
			render_anime2(); /*显示图形二*/
			break;
    }
   return false;
}
#endif
