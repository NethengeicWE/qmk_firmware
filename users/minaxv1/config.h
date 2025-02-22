// Copyright 2023 br Zhang (@NethengeicWE)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
Look familiar?
Things like these are happening all over the galaxy right now.
You could be next.
That is unless you make the most important decision of your life.
Prove to yourself that you have the strength and courage to be free.
Join the Hell Diver.
Become part of an elite peacekeeping force
see exotic new lifeforms
and spread the managed democracy throghout the galaxy
become a hero,become a legend
Become a hell diver
*/
// check the chips: st-info --probe
// flash botloader:st-flash --reset --format binary write "C:\Users\NethengeicWE\Desktop\Board\flash\generic_boot20_pc13.bin" 0x08000000
#pragma once
/*JOYCON*/
#ifdef POINTING_DEVICE_ENABLE
    #define ANALOG_JOYSTICK_X_AXIS_PIN A2
    #define ANALOG_JOYSTICK_Y_AXIS_PIN A1
    #define POINTING_DEVICE_ROTATION_180
#endif
/*RGB MATRIX*/
#ifdef RGB_MATRIX_ENABLE
        // x = 224 / 18 * COL_POSITION = 12.4 *___
        // y =  64 / 4 * ROW_POSITION = 16 *___
        // "matrix":[row,col]
    #define WS2812_DI_PIN B1 // tim3 ch4
    #define WS2812_PWM_DRIVER PWMD3
    #define WS2812_PWM_CHANNEL 4
    #define WS2812_DMA_STREAM STM32_DMA1_STREAM3
    #define WS2812_DMA_CHANNEL 3

    #define RGB_MATRIX_LED_COUNT 85
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_KEYPRESSES

    // RGB EFFECT
    #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 220
    #define RGB_MATRIX_TYPING_HEATMAP_SPREAD 35
    #define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 13
    #define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 13
#endif

#ifdef HAL_USE_SPI
    #define SPI_DRIVER SPID2
    #define SPI_SCK_PIN	A5
    #define SPI_SCK_PAL_MODE 5
    #define SPI_MOSI_PIN A7S
    #define SPI_MOSI_PAL_MODE 5
    #define SPI_MISO_PIN A6
    #define SPI_MISO_PAL_MODE 5
#endif

#ifdef HAL_USE_I2C
    #define I2C_DRIVER I2CD1
    #define I2C1_SCL_PIN B6
    #define I2C1_SCL_PAL_MODE 4
    #define I2C1_SDA_PIN B7
    #define I2C1_SDA_PAL_MODE 4

    #define I2C1_OPMODE	OPMODE_I2C
    #define I2C1_CLOCK_SPEED 400000 // 100000
    #define I2C1_DUTY_CYCLE	FAST_DUTY_CYCLE_2 //STD_DUTY_CYCLE
    #define OLED_SCROLL_TIMEOUT 60000

    #define OLED_FONT_H "font.c"   
    // #define OLED_FONT_START	0	// 自定义字体的起始字符索引
    // #define OLED_FONT_END	223	// 自定义字体的结束字符索引

#endif

#ifdef HAPTIC_ENABLE
    #define SOLENOID_PIN A0
    //#define SOLENOID_PIN_ACTIVE_LOW true
    // don't use this define:pure resistance while reactivate,big current make it hot,especially without the limit.
    // sometimes the solenoid cannot work but the voltage have no problem:current limit from the usb driver while using RGB Matrix
    // One possible fix:Use this define to fix that/reset the solenoid muanually,raise the limit of current could help and louder
#endif

// BOOTMAGIC
#define BOOTMAGIC_LITE_ROW 2
#define BOOTMAGIC_LITE_COLUMN 0

#define LAYER_STATE_8BIT
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
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

git rm keyboards/cablecardesigns/phoenix/keymaps/via/rules.mk
git rm keyboards/ck60i/keymaps/via/keymap.c
git rm keyboards/cutie_club/giant_macro_pad/keymaps/via/keymap.c
git rm keyboards/cutie_club/giant_macro_pad/keymaps/via/rules.mk
git rm keyboards/dc01/arrow/keymaps/via/rules.mk
git rm keyboards/dc01/left/keymaps/via/rules.mk
git rm keyboards/dc01/numpad/keymaps/via/rules.mk
git rm keyboards/dc01/right/keymaps/via/rules.mk
git rm keyboards/demiurge/keymaps/via/keymap.c
git rm keyboards/demiurge/keymaps/via/rules.mk
git rm keyboards/dztech/bocc/keymaps/via/keymap.c
git rm keyboards/evolv/keymaps/via/keymap.c
git rm keyboards/fallacy/keymaps/via/keymap.c
git rm keyboards/flashquark/horizon_z/keymaps/via/keymap.c
git rm keyboards/flashquark/horizon_z/keymaps/via/rules.mk
git rm keyboards/gizmo_engineering/gk6/keymaps/via/keymap.c
git rm keyboards/gizmo_engineering/gk6/keymaps/via/rules.mk
git rm keyboards/hand88/keymaps/via/rules.mk
git rm keyboards/handwired/dactyl_manuform/5x6_5/keymaps/via/keymap.json
git rm keyboards/handwired/dactyl_manuform/5x6_5/keymaps/via/rules.mk
git rm keyboards/idobao/montex/v1rgb/keymaps/via/keymap.c
git rm keyboards/idobao/montex/v1rgb/keymaps/via/rules.mk
git rm keyboards/idobao/montex/v2/keymaps/via/config.h
git rm keyboards/idobao/montex/v2/keymaps/via/keymap.c
git rm keyboards/idobao/montex/v2/keymaps/via/rules.mk
git rm keyboards/iron180/keymaps/via/keymap.c
git rm keyboards/joshajohnson/hub16/keymaps/via/keymap.c
git rm keyboards/kapcave/gskt00/keymaps/via/keymap.c
git rm keyboards/kbdfans/bella/soldered/keymaps/via/keymap.c
git rm keyboards/kbdfans/maja/keymaps/via/keymap.c
git rm keyboards/kbdfans/maja/keymaps/via/rules.mk
git rm keyboards/kbdfans/maja_soldered/keymaps/via/keymap.c
git rm keyboards/kbdfans/maja_soldered/keymaps/via/rules.mk
git rm keyboards/keebio/dsp40/keymaps/via/keymap.c
git rm keyboards/keebsforall/freebirdnp/lite/keymaps/via/rules.mk
git rm keyboards/keebsforall/freebirdnp/pro/keymaps/via/rules.mk
git rm keyboards/keebwerk/mega/ansi/keymaps/via/keymap.c
git rm keyboards/keebwerk/mega/ansi/keymaps/via/readme.md
git rm keyboards/keebwerk/mega/ansi/keymaps/via/rules.mk
git rm keyboards/keychron/q11/ansi_encoder/keymaps/keychron/keymap.c
git rm keyboards/keychron/q11/ansi_encoder/keymaps/keychron/rules.mk
git rm keyboards/keychron/q11/ansi_encoder/keymaps/via/keymap.c
git rm keyboards/keychron/q11/iso_encoder/keymaps/keychron/keymap.c
git rm keyboards/keychron/q11/iso_encoder/keymaps/keychron/rules.mk
git rm keyboards/keychron/q11/iso_encoder/keymaps/via/keymap.c
git rm keyboards/keychron/q11/iso_encoder/rules.mk
git rm keyboards/keychron/q9_plus/ansi_encoder/keymaps/keychron/keymap.c
git rm keyboards/keychron/q9_plus/ansi_encoder/keymaps/keychron/rules.mk
git rm keyboards/keychron/q9_plus/ansi_encoder/keymaps/via/keymap.c
git rm keyboards/kprepublic/jj40/keymaps/via/rules.mk
git rm keyboards/lazydesigners/cassette8/keymaps/via/rules.mk
git rm keyboards/lazydesigners/the60/rev2/keymaps/via/keymap.c
git rm keyboards/lazydesigners/the60/rev2/keymaps/via/rules.mk
git rm keyboards/magic_force/mf17/keymaps/via/keymap.c
git rm keyboards/magic_force/mf34/keymaps/via/keymap.c
git rm keyboards/mechwild/mercutio/keymaps/fancy/keymap.c
git rm keyboards/mechwild/mercutio/keymaps/via/keymap.c
git rm keyboards/melgeek/mach80/keymaps/via/keymap.c
git rm keyboards/melgeek/mach80/keymaps/via/rules.mk
git rm keyboards/melgeek/mj6xy/keymaps/via/keymap.c
git rm keyboards/melgeek/mojo68/keymaps/via/keymap.c
git rm keyboards/melgeek/mojo68/keymaps/via/rules.mk
git rm keyboards/melgeek/tegic/keymaps/via/keymap.c
git rm keyboards/melgeek/tegic/keymaps/via/rules.mk
git rm keyboards/mode/m65ha_alpha/keymaps/via/keymap.c
git rm keyboards/mode/m65hi_alpha/keymaps/via/keymap.c
git rm keyboards/mode/m65s/keymaps/via/keymap.c
git rm keyboards/mode/m75h/keymaps/via/keymap.c
git rm keyboards/mode/m75s/keymaps/via/keymap.c
git rm keyboards/mode/m80v2/m80v2s/keymaps/via/keymap.c
git rm keyboards/monokei/mnk1800s/keymaps/via/readme.md
git rm keyboards/monokei/mnk1800s/keymaps/via/rules.mk
git rm keyboards/monokei/mnk50/keymaps/via/readme.md
git rm keyboards/monokei/mnk50/keymaps/via/rules.mk
git rm keyboards/monokei/mnk75/keymaps/via/rules.mk
git rm keyboards/novelkeys/nk65/keymaps/via/keymap.c
git rm keyboards/novelkeys/nk65/keymaps/via/readme.md
git rm keyboards/novelkeys/nk65/keymaps/via/rules.mk
git rm keyboards/novelkeys/nk65b/keymaps/via/keymap.c
git rm keyboards/novelkeys/nk65b/keymaps/via/readme.md
git rm keyboards/novelkeys/nk65b/keymaps/via/rules.mk
git rm keyboards/novelkeys/nk87/keymaps/via/readme.md
git rm keyboards/novelkeys/nk87/keymaps/via/rules.mk
git rm keyboards/novelkeys/skelett40/keymaps/via/rules.mk
git rm keyboards/novelkeys/skelett60/keymaps/via/rules.mk
git rm keyboards/noxary/378/keymaps/via/keymap.c
git rm keyboards/noxary/valhalla_v2/keymaps/via/keymap.c
git rm keyboards/quantrik/kyuu/keymaps/via/keymap.c
git rm keyboards/quantrik/kyuu/keymaps/via/rules.mk
git rm keyboards/smithrune/iron160/iron160_h/keymaps/via/keymap.c
git rm keyboards/smithrune/iron160/iron160_s/keymaps/via/keymap.c
git rm keyboards/smithrune/iron180/keymaps/via/keymap.c
git rm keyboards/smithrune/iron180v2/v2h/keymaps/via/keymap.c
git rm keyboards/smithrune/iron180v2/v2s/keymaps/via/keymap.c
git rm keyboards/spaceholdings/nebula12/keymaps/via/keymap.c
git rm keyboards/spaceholdings/nebula12/keymaps/via/rules.mk
git rm keyboards/spaceholdings/nebula12b/keymaps/via/keymap.c
git rm keyboards/spaceholdings/nebula68b/solder/keymaps/via/keymap.c
git rm keyboards/spaceholdings/nebula68b/solder/keymaps/via/rules.mk
git rm keyboards/xelus/la_plus/keymaps/via/keymap.c
git add keyboards/smithrune/iron180v2/v2s/keymaps/via/keymap.c
git add keyboards/spaceholdings/nebula12/keymaps/via/keymap.c
git add keyboards/spaceholdings/nebula12/keymaps/via/rules.mk
git add keyboards/spaceholdings/nebula12b/keymaps/via/keymap.c
git add keyboards/spaceholdings/nebula68b/solder/keymaps/via/keymap.c
git add keyboards/spaceholdings/nebula68b/solder/keymaps/via/rules.mk
git add keyboards/xelus/la_plus/keymaps/via/keymap.c
git add users/minaxv1/config.h
git rm keyboards/spaceholdings/nebula68b/solder/keymaps/via/rules.mk
git rm keyboards/xelus/la_plus/keymaps/via/keymap.c