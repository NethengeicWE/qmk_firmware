// Copyright 2023 br Zhang (@NethengeicWE)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/*MATRIX*/
#define MATRIX_ROWS 5
#define MATRIX_ROWS_PINS {B0,A7,A3,A2,B9} 
#define MATRIX_COLS 4
#define MATRIX_COLS_PINS {B12,A6,A5,A4} 

/*RGB MATRIX*/
//x = 224 / 3 * COL_POSITION = 75 *___
//y =  64 / 4 * ROW_POSITION = 16 *___
//#define WS2812_BYTE_ORDER RGB
#define WS2812_DI_PIN B1 // tim3 ch4
#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 4
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 3

#define RGB_MATRIX_LED_COUNT 19
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
//#define USB_MAX_POWER_CONSUMPTION 1000

#define SOLENOID_PIN A0
#define SOLENOID_PIN_ACTIVE_LOW true

/*JOYSTICK*/
//#define ANALOG_JOYSTICK_X_AXIS_PIN A0
//#define ANALOG_JOYSTICK_Y_AXIS_PIN A1
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
