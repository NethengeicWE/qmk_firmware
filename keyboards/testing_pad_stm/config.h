// Copyright 2023 br Zhang (@NethengeicWE)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
//#include "config_common.h" "pointing_device_driver" : "analog_joystick", 

#define MATRIX_ROWS 5
#define MATRIX_ROWS_PINS {B1,B2,B3,B4,B5} 

#define MATRIX_COLS 4
#define MATRIX_COLS_PINS {A1,A2,A3,A4} 

//#define ANALOG_JOYSTICK_X_AXIS_PIN A0
//#define ANALOG_JOYSTICK_Y_AXIS_PIN A5
//#define ADC_NUM_CHANNELS 1

//#define JOYSTICK_AXIS_COUNT 2
//#define ANALOG_JOYSTICK_AXIS_MIN 0
// #define ANALOG_JOYSTICK_AXIS_MAX 512
//#define ANALOG_JOYSTICK_SPEED_MAX 1023




/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 * #define JOYSTICK_BUTTON_COUNT 16
   
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT