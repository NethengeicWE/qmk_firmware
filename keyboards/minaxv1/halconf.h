#pragma once
#include_next <halconf.h>

#undef HAL_USE_ADC
#define HAL_USE_ADC TRUE

#undef HAL_USE_PWM
#define HAL_USE_PWM TRUE

// SPI for wireless
/*
#undef HAL_USE_SPI
#define HAL_USE_SPI TRUE
#define SPI_USE_WAIT TRUE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
*/

// I2C for OLED

#undef HAL_USE_I2C
#define HAL_USE_I2C TRUE
