#pragma once
#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE 

#undef STM32_PWM_USE_TIM3
#define STM32_PWM_USE_TIM3 TRUE

#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE
#define STM32_I2C_BUSY_TIMEOUT 50       // 如果未收到响应，则 I2C 命令中止之前的时间（以毫秒为单位）
#define STM32_I2C_XXX_IRQ_PRIORITY 10   // 硬件驱动程序 XXX 的中断优先级（这是专家设置）	
#define STM32_I2C_USE_DMA TRUE          // 启用/禁用 MCU 将数据传输卸载到 DMA 单元的能力	TRUE
#define STM32_I2C_XXX_DMA_PRIORITY 1    // 硬件驱动程序 XXX 的 DMA 单元优先级（这是专家设置）

//#undef STM32_SPI_USE_SPI2
//#define STM32_SPI_USE_SPI2 TRUE

