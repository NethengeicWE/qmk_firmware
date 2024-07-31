// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
// 新增功能在此处添加，疑似重复执行

#include QMK_KEYBOARD_H
//#include "pointing_device.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │TG1│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    [0] = LAYOUT_numpad_5x4(
        TG(1)   ,KC_PSLS, KC_PAST, RGB_TOG ,
        KC_7    ,KC_8   , KC_9   , KC_PPLS ,
        KC_4    ,KC_5   , KC_6   , KC_PENT ,
        KC_1    ,KC_2   , KC_3   , KC_NO   , 
        KC_DEL  ,KC_0   , KC_PDOT, KC_RGUI  
    ),

    /*
     * ┌───┬───┬───┬───┐
     * │TG1│ / │ * │ - │
     * ├───┼───┼───┼───┤
     * │Hom│ ↑ │PgU│   │
     * ├───┼───┼───┤ + │
     * │ ← │   │ → │   │
     * ├───┼───┼───┤───┤
     * │End│ ↓ │PgD│   │
     * ├───┴───┼───┤Ent│
     * │Insert │Del│   │
     * └───────┴───┘───┘
     */
    [1] = LAYOUT_numpad_5x4(
        TG(0)  , KC_PAST, KC_PSLS, _______, 
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, KC_ESC
    )
};


