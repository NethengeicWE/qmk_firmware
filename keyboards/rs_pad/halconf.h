#define HAL_USE_PWM TRUE
#define HAL_USE_PAL TRUE
#define HAL_USE_I2C TRUE

#undef HAL_USE_ADC
#define HAL_USE_ADC TRUE

#include_next <halconf.h>