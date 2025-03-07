// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "analog.c"

#define joystick_x_axis A1
#define joystick_y_axis A0
#define range 500

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     */
    [0] = LAYOUT_numpad_5x4(
        TG(1)   ,KC_PSLS, KC_PAST, RGB_TOG ,
        KC_7    ,KC_8   , KC_9   , KC_PPLS ,
        KC_4    ,KC_5   , KC_6   , KC_PENT ,
        KC_1    ,KC_2   , KC_3   , KC_NO   , 
        KC_DEL  ,KC_0   , KC_RGUI, RGB_MOD  
    ),

    /*
     */
    [1] = LAYOUT_numpad_5x4(
        TG(0)  , KC_PAST, KC_PSLS, _______, 
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, KC_ESC
    )
};
/*
            {"matrix": [1, 0], "x": 0, "y": 0, "flags": 4},
            {"matrix": [1, 1], "x": 21, "y": 0, "flags": 4},
            {"matrix": [1, 2], "x": 43, "y": 0, "flags": 4},
            {"matrix": [1, 3], "x": 64, "y": 0, "flags": 4},
            {"matrix": [2, 3], "x": 64, "y": 21, "flags": 4},
            {"matrix": [2, 2], "x": 43, "y": 21, "flags": 4},
            {"matrix": [2, 1], "x": 21, "y": 21, "flags": 4},
            {"matrix": [2, 0], "x": 0, "y": 21, "flags": 4},
            {"matrix": [3, 0], "x": 0, "y": 43, "flags": 4},
            {"matrix": [3, 1], "x": 21, "y": 43, "flags": 4},
            {"matrix": [3, 2], "x": 43, "y": 43, "flags": 4},
            {"matrix": [4, 3], "x": 64, "y": 53, "flags": 4},
            {"matrix": [4, 2], "x": 43, "y": 43, "flags": 4},
            {"matrix": [4, 1], "x": 21, "y": 43, "flags": 4},
            {"matrix": [4, 0], "x": 0, "y": 43, "flags": 4}
*/



/*
void host_keyboard_send(report_keyboard_t *report) {


    if (!driver) return;

    {

    }
    (*driver->send_keyboard)(report);

    if (debug_keyboard) {
        dprint("keyboard_report: ");
        for (uint8_t i = 0; i < KEYBOARD_REPORT_SIZE; i++) {
            dprintf("%02X ", report->raw[i]);
        }
        dprint("\n");
    }
}*/
