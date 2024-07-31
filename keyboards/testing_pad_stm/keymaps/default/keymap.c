// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD
//#include "drashna.h"
//#include "analog.h"
//#include "pointing_device.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │TG1│ / │ * │ ~ │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ + │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┤Ent|
     * │ 1 │ 2 │ 3 │   │
     * ├───┼───┼───┼───┼───┐
     * │DEL| 0 │ . │   │WIN│
     * └───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_testing_pad(
        TG(1)   ,KC_PSLS, KC_PAST, KC_GRV  ,
        KC_7    ,KC_8   , KC_9   , KC_PPLS ,
        KC_4    ,KC_5   , KC_6   , KC_PENT ,
        KC_1    ,KC_2   , KC_3   , KC_NO   , 
        KC_DEL  ,KC_0   , KC_PDOT, KC_RGUI  
    ),
    /*
     * ┌───┬───┬───┬───┐
     * │TG1│PGU│PGD│ ~ │
     * ├───┼───┼───┼───┤
     * │F7 │F8 │F9 │F12│
     * ├───┼───┼───┼───┤
     * │F4 │F5 │F6 │   │
     * ├───┼───┼───┤Ent|
     * │F1 │F2 │F3 │   │
     * ├───┼───┼───┼───┼───┐
     * │DEL|F10│F11│   │WIN│
     * └───┴───┴───┴───┴───┘
     */
    [1] = LAYOUT_testing_pad(
        TG(0)  , KC_PAST, KC_PSLS, _______, 
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
    )
};





/*
analogic_device_init();
pointing_device_init_kb();
#define QK_JOYSTICK_BUTTON_0 KC_MS_U
#define QK_JOYSTICK_BUTTON_1 KC_MS_D
#define QK_JOYSTICK_BUTTON_2 KC_MS_L
#define QK_JOYSTICK_BUTTON_3 KC_MS

int16_t a
void joystick_to_mousekey(){

}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(A8, 900, 575, 285), 
    JOYSTICK_AXIS_IN(A9, 900, 575, 285)
}
Note:
[900,575) -> [-128,O)
 575 -> 0
(575,285] -> (0,128]
*/
