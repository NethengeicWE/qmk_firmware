// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*
dev keymap:Test for the 54keys layout

*/

#include <quantum.h>
#include "analog.c"
#include "oled.c"
#include <send_string_keycodes.h>
// #include "print.h"

// configerationL:joystick -> direct_key
#define joystick_x_axis A4
#define joystick_y_axis A3
#define TASTING_VERSION FALSE
    
enum my_keycode{
    RGB_ANIM = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // 圣徒，你知道人类将你那些倒下的同胞制成弹药给我们使用吗
    // 这就是生命的轮回，这个概念你永远也无法理解的
    [0] = LAYOUT_minax(
        TO(1)   ,KC_F12 ,KC_F11 ,KC_F10 ,KC_F9  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_PGUP,
        KC_PGDN ,KC_F4  ,KC_F3  ,KC_F2  ,KC_F1  ,KC_BTN1,KC_ENT ,        KC_DEL ,KC_GRV ,
        KC_ESC  ,KC_TAB ,KC_CAPS,KC_LSFT,KC_LCTL,KC_LGUI,KC_Z   ,KC_A   ,KC_Q   ,KC_1   ,
        KC_2    ,KC_W   ,KC_S   ,KC_X   ,KC_LALT,KC_SPC ,KC_C   ,KC_D   ,KC_E   ,KC_3   ,
        KC_4    ,KC_R   ,KC_F   ,KC_V   ,LT(2,KC_UP)  ,        KC_B   ,KC_G   ,KC_T   ,KC_5   ,
        KC_6    ,KC_Y   ,KC_H   ,KC_N   ,TT(1) ,KC_RALT,KC_M   ,KC_J   ,KC_U   ,KC_7   ,
        KC_8    ,KC_I   ,KC_K   ,KC_COMM,KC_DOT ,KC_RGUI,KC_SLSH,KC_L   ,KC_O   ,KC_9   ,
        KC_0    ,KC_P   ,KC_SCLN,KC_RSFT,KC_APP ,KC_RCTL,KC_UP  ,KC_QUOT,KC_LBRC,KC_MINS,
        KC_EQUAL,KC_RBRC,KC_BSLS,KC_ENT ,KC_BSPC
    ),                                                                                                    
    // 通过斗争与胜利，这个社会已经实现了每一个年轻文明的抱负：
    // 一个有着统一目标的家园，一条通往璀璨群星的道路
   [1] = LAYOUT_minax(
        // Super Shift Layer
        TO(0)   ,KC_7   ,KC_4   ,KC_1   ,KC_BSPC,KC_0   ,KC_2   ,KC_5   ,KC_8   ,KC_PAST,
        KC_PSLS ,KC_9   ,KC_6   ,KC_3   ,KC_DOT ,KC_BTN2,_______,        KC_PPLS,KC_PMNS,
        KC_ESC  ,_______,_______,_______,_______,_______,KC_1   ,KC_4   ,KC_7   ,_______,
        _______ ,KC_8   ,KC_5   ,KC_2   ,_______,_______,KC_3   ,KC_6   ,KC_9   ,_______,
        _______ ,KC_PPLS,KC_PSLS,KC_ENT ,_______,        _______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______
    ),
    // 自然进化一直以来只能用一个简单且粗暴的词来形容：失败
    // 如今，我们将亲自定义成功
    [2] = LAYOUT_minax(
        // Fn Layer
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,        _______,_______,
        _______ ,_______,_______,_______,_______,_______,KC_F1  ,KC_F5  ,KC_F9  ,_______,
        _______ ,KC_F10 ,KC_F6  ,KC_F2  ,_______,_______,KC_F3  ,KC_F7  ,KC_F11 ,_______,
        _______ ,KC_F12 ,KC_F8  ,KC_F4  ,_______,        _______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,
        _______ ,_______,_______,_______,_______
    )
    // Strange game
    // the only way to win is not to play
};

// 处理自定义按键功能
bool rgb_anim = 1;
uint8_t mod_state;
bool process_record_kb(uint16_t keycode, keyrecord_t *record){
    #ifdef CONSOLE_ENABLE
        // debug
        // uprintf("x: %hd,y:%hd,lr:%d,ud:%d\n", x,y,isLRpressed,isUDpressed);
    #endif
    mod_state = get_mods();
    
    switch(keycode){
        case RGB_ANIM: // rgb_switch
            if (record -> event.pressed) rgb_anim ^= 1; 
            return true;
        #ifdef TASTING_VERSION // Modified Key：shift+backspace = delete
            case KC_BSPC: {
                static bool delkey_registered;
                if (record->event.pressed) {
                    if (mod_state & MOD_MASK_SHIFT) {
                        del_mods(MOD_MASK_SHIFT);
                        register_code(KC_DEL);
                        delkey_registered = true;
                        set_mods(mod_state);
                        return false;
                    }
                } else { 
                    if (delkey_registered) {
                        unregister_code(KC_DEL);
                        delkey_registered = false;
                        return false;
                    }
                }
                return true;
            } 
        #endif 
        default:
            return true;
    }
}

// debug使用
bool process_record_user(uint16_t keycode, keyrecord_t *record){
    #ifdef CONSOLE_ENABLE
        //uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif 
    return true;
}
#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
    debug_enable=true;
}
#endif

// RGB指示灯
#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (rgb_anim == 0) rgb_matrix_set_color_all(0,0,0);
    if (get_highest_layer(layer_state) == 0) rgb_matrix_set_color(76, 0  , 0  , 0  );
    if (get_highest_layer(layer_state) == 1) rgb_matrix_set_color(76, 255, 0  , 0  );
    if (get_highest_layer(layer_state) == 2) rgb_matrix_set_color(76, 255, 255, 0  );

    if (host_keyboard_led_state().caps_lock) rgb_matrix_set_color(78, 255, 255, 255);
    else rgb_matrix_set_color(78,  0,  0,  0);
    return true;
}
#endif

// 键位覆写
#ifdef KEY_OVERRIDE_ENABLE
    const key_override_t hom_key_override = 
        ko_make_basic(MOD_MASK_SHIFT, KC_PGUP, KC_HOME);
    const key_override_t end_key_override = 
        ko_make_basic(MOD_MASK_SHIFT, KC_PGDN, KC_END);
    const key_override_t del_key_override = 
        ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
    const key_override_t bsc_key_override = 
        ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_BSPC);
    

    const key_override_t **key_overrides = (const key_override_t *[]){
        &hom_key_override,
        &end_key_override,
        &del_key_override,
        &bsc_key_override,
        NULL 
    };
#endif

// oled屏幕
#ifdef OLED_ENABLE
// The following functions are provided by HiryKun: https://gitee.com/hriykun/sample-code-for-qmk-tutorial/tree/master/OLED%E5%8D%95%E8%89%B2%E5%B1%8F
    /**
     * @brief 在指定位置写入图片
     * @param *data 图片数据
     * @param weight 图片宽度（单位像素）
     * @param height 图片高度（单位像素）
     * @param col 写入位置左上角横坐标（单位字符）
     * @param line 写入位置左上角纵坐标（单位字符）
     * @return void
    */
    void oled_write_raw_pic(const char *data, uint8_t weight, uint8_t height, uint8_t col, uint8_t line) {
        uint8_t page_height = (height + 7) / 8;
        for(uint8_t now_page = 0; now_page < page_height; now_page++) {
            oled_set_cursor(col, line + now_page);
            oled_write_raw_P(data + now_page * weight, weight);
        }
    }

    /**
     * @brief 在指定位置写入字库中的大图像
     * @param *data 图像数据
     * @param weight 图片宽度（单位字符）
     * @param height 图片高度（单位字符）
     * @param col 写入位置左上角横坐标（单位字符）
     * @param line 写入位置左上角纵坐标（单位字符）
     * @param invert 是否反色
     * @return void
    */
    void oled_write_big_font(const char *data, uint8_t weight, uint8_t height, uint8_t col, uint8_t line, bool invert) {
        for(uint8_t now_page = 0; now_page < height; now_page++) {
            uint8_t page[weight + 1];
            memcpy(page, data + now_page * weight, weight);
            page[weight] = '\0';
            oled_set_cursor(col, line + now_page);
            oled_write_P((const char *)page, invert);
        }
    }
    // 自定义函数
    bool oled_task_user() {
        oled_write_raw_P((const char *)background_0,sizeof(background_0));
        /*
        oled_write_P(PSTR("LAYER: "),false);
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_P(PSTR("Funpad"), false);
                break;
            case 1:
                oled_write_P(PSTR("Numpad"), false);
                break;
            case 2:
                oled_write_P(PSTR("Config"), false);
                break;
            default:
                oled_write_P(PSTR("WTF???"), false);
        }
        */
        
        return true;
    }
#endif

// 摇杆功能实现：L0层代替方向键，L1层代替鼠标
#ifdef POINTING_DEVICE_ENABLE
    report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {
    if (get_highest_layer(layer_state) == 0) {
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return pointing_device_task_user(mouse_report);
    }
#endif
bool isUDpressed = 0;
bool isLRpressed = 0;
bool rgb_matrix_indicators_user(void){
    // why use this: running all the time.
    int16_t x = analogReadPin(A4);
    int16_t y = analogReadPin(A3);
    #ifdef CONSOLE_ENABLE
        // debug
        // uprintf("x: %hd,y:%hd,lr:%d,ud:%d\n", x,y,isLRpressed,isUDpressed);
    #endif
    if (get_highest_layer(layer_state) == 0) {
        if (x > 710 && isLRpressed == 0) {
            send_string(SS_DOWN(X_LEFT));
            isLRpressed = 1;
        } 
        if (x < 210 && isLRpressed == 0) {
            send_string(SS_DOWN(X_RIGHT));
            isLRpressed = 1;
        }
        if (210 < x && x < 710 ) {
            if (isLRpressed == 1) {
                send_string(SS_UP(X_LEFT));
                send_string(SS_UP(X_RIGHT));
                isLRpressed = 0;
            }
        }
        if (y > 710 && isUDpressed == 0) {
            send_string(SS_DOWN(X_UP));
            isUDpressed = 1;
        } 
        if (y < 210 && isUDpressed == 0) {
            send_string(SS_DOWN(X_DOWN));
            isUDpressed = 1;
        }
        if (y < 710 && y > 210) {
            if (isUDpressed == 1) {
                send_string(SS_UP(X_UP));
                send_string(SS_UP(X_DOWN));
                isUDpressed = 0;
            }
        }
    } 
    return true;
}
// v3开发日志：
// 1. 人民的忠诚度主要取决于生活水平的上升或下降，而非生活水平本身
// Pop loyalty is altered whenever their Standard of Living increases or declines from its current value instead of the living standard itself.
// 2. 忠诚人口是会老去的，随着一代又一代人死去然后被下一代替代，越来越少的人会记得你30年前为国家所做的伟大事业，而开始思考你最近为他们做了些什么
// As generations die off and are replaced by new ones, less and less people will remember all the great things you did for the country 30 years ago and will start wondering instead what you've done for them lately.




/*
RGB_MATRIX_NONE = 0,                     // 无效果
RGB_MATRIX_SOLID_COLOR = 1,              // 静态单色，不支持速度调节
RGB_MATRIX_ALPHAS_MODS,                  // 静态双色，速度控制次色调
RGB_MATRIX_GRADIENT_UP_DOWN,             // 静态上下渐变，速度控制渐变程度
RGB_MATRIX_GRADIENT_LEFT_RIGHT,          // 静态左右渐变，速度控制渐变程度
RGB_MATRIX_BREATHING,                    // 单色呼吸动画
RGB_MATRIX_BAND_SAT,                     // 单色带状饱和度渐变，从左到右滚动
RGB_MATRIX_BAND_VAL,                     // 单色带状亮度渐变，从左到右滚动
RGB_MATRIX_BAND_PINWHEEL_SAT,            // 单色3叶旋转风车，饱和度渐变
RGB_MATRIX_BAND_PINWHEEL_VAL,            // 单色3叶旋转风车，亮度渐变
RGB_MATRIX_BAND_SPIRAL_SAT,              // 单色螺旋渐变，饱和度渐变
RGB_MATRIX_BAND_SPIRAL_VAL,              // 单色螺旋渐变，亮度渐变
RGB_MATRIX_CYCLE_ALL,                    // 全键盘单色循环全渐变
RGB_MATRIX_CYCLE_LEFT_RIGHT,             // 全渐变从左到右滚动
RGB_MATRIX_CYCLE_UP_DOWN,                // 全渐变从上到下滚动
RGB_MATRIX_CYCLE_OUT_IN,                 // 全渐变由外向内滚动
RGB_MATRIX_CYCLE_OUT_IN_DUAL,            // 全双渐变由外向内滚动
RGB_MATRIX_RAINBOW_MOVING_CHEVRON,       // 全渐变V形滚动，从左到右
RGB_MATRIX_CYCLE_PINWHEEL,               // 全渐变中心旋转风车
RGB_MATRIX_CYCLE_SPIRAL,                 // 全渐变中心螺旋旋转
RGB_MATRIX_DUAL_BEACON,                  // 全渐变中心旋转
RGB_MATRIX_RAINBOW_BEACON,               // 更紧密的全渐变中心旋转
RGB_MATRIX_RAINBOW_PINWHEELS,            // 全双渐变两侧旋转
RGB_MATRIX_FLOWER_BLOOMING,              // 前半部分从左到右滚动，后半部分从右到左滚动
RGB_MATRIX_RAINDROPS,                    // 随机改变单个按键的色调
RGB_MATRIX_JELLYBEAN_RAINDROPS,          // 随机改变单个按键的色调和饱和度
RGB_MATRIX_HUE_BREATHING,                // 色调轻微上移，然后返回
RGB_MATRIX_HUE_PENDULUM,                 // 色调波浪状向右上移动，然后向左返回
RGB_MATRIX_HUE_WAVE,                     // 色调波浪状上下移动
RGB_MATRIX_PIXEL_FRACTAL,                // 单色分形填充按键，水平脉冲至边缘
RGB_MATRIX_PIXEL_FLOW,                   // 沿LED线路脉冲RGB流动，使用随机色调
RGB_MATRIX_PIXEL_RAIN,                   // 随机点亮按键，使用随机色调
RGB_MATRIX_TYPING_HEATMAP,               // 测量您的打字热度！
RGB_MATRIX_DIGITAL_RAIN,                 // 著名的计算机模拟
RGB_MATRIX_SOLID_REACTIVE_SIMPLE,        // 按下按键时的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_REACTIVE,               // 静态单色，按下按键时色调脉冲，然后淡出为当前色调
RGB_MATRIX_SOLID_REACTIVE_WIDE,          // 单个按键附近的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE,     // 多个按键附近的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_REACTIVE_CROSS,         // 单个按键所在列和行的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_REACTIVE_MULTICROSS,    // 多个按键所在列和行的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_REACTIVE_NEXUS,         // 单个按键所在列和行的色调和亮度脉冲远离按键，然后淡出亮度
RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS,    // 多个按键所在列和行的色调和亮度脉冲远离按键，然后淡出亮度
RGB_MATRIX_SPLASH,                       // 从单个按键开始的全渐变和亮度脉冲，然后淡出亮度
RGB_MATRIX_MULTISPLASH,                  // 从多个按键开始的全渐变和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_SPLASH,                 // 从单个按键开始的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_SOLID_MULTISPLASH,            // 从多个按键开始的色调和亮度脉冲，然后淡出亮度
RGB_MATRIX_STARLIGHT,                    // LED随机开关，保持用户设置的颜色
RGB_MATRIX_STARLIGHT_DUAL_HUE,           // LED随机开关，保持用户设置的颜色，修改色调+-30
RGB_MATRIX_STARLIGHT_DUAL_SAT,           // LED随机开关，保持用户设置的颜色，修改饱和度+-30
RGB_MATRIX_RIVERFLOW,                    // 通过按键位置偏移动画来模拟河流流动的呼吸动画修改
*/










