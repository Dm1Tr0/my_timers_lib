#include "macro.h"
#include <libopencm3/stm32/gpio.h>
#include <stdbool.h>

enum port_num {
    sk_port_A = 0
    sk_port_B = 1
    sk_port_C = 2
    sk_port_D = 3
    sk_port_E = 4
    sk_port_F = 5
    sk_port_G = 6
}

struct sk_size_optim(1) gpio_pin {
    uint8_t inv     : 1;
    uint8_t pin     : 4;
    uint8_t port    : 3;
};

void sk_attr_inline_only sk_port_num_to_gpio (enum num port) {
    GPIO_PORT_A_BASE + (GPIO_PORT_A_BASE - GPIO_PORT_A_BASE ) * port;
}



#if SK_USE_GLSK_DEFINITIONS
// some STM32F4DISCOVERY pins
extern const sk_pin sk_io_led_orange;
extern const sk_pin sk_io_led_red;
extern const sk_pin sk_io_led_green;
extern const sk_pin sk_io_led_blue;
extern const sk_pin sk_io_btn_usr;
// some GL-SK pins
extern const sk_pin sk_io_btn_right;
extern const sk_pin sk_io_btn_mid;
extern const sk_pin sk_io_btn_left;
extern const sk_pin sk_io_btn_up;
extern const sk_pin sk_io_btn_down;
extern const sk_pin sk_io_lcd_bkl;
extern const sk_pin sk_io_eth_led;
#endif
