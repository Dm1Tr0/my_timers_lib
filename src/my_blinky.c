#include "sk_lib.h"
#include "timers.h"
#include <libopencm3/cm3/cortex.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/rcc.h>

weak_attr void tim7_func(void)
{
    // function that will exicute on tim7 interrupt
}

weak_attr void sys_tick_func(void)
{
    // function that will exicute on sys_tick interrupt
}


int main(void)
{

    rcc_periph_clock_enable(RCC_TIM7);
    rcc_periph_clock_enable(RCC_GPIOD);

    glsk_pins_init(DISCOVER);

    sk_pin_set(sk_io_led_red,1);
        timer_7_init(upd_on_ovf,1000ul , 16ul);
    sk_pin_toggle(sk_io_led_red);

    sk_pin_set(sk_io_led_blue,1);
    timer_sysT_init(10000,STK_CSR_CLKSOURCE_AHB);
    // sk_pin_toggle(sk_io_led_blue);
    cm_enable_interrupts();

    sk_pin pins [] = {sk_io_led_red, sk_io_led_green, sk_io_led_blue, sk_io_led_orange };

    sk_pin_set(sk_io_led_blue,1);
    sk_pin_set(sk_io_led_orange,1);

    t7_delay_sec(1);

    sk_pin_toggle(sk_io_led_blue);

    sys_delay_sec(2);

    sk_pin_toggle(sk_io_led_blue);

    while (1) {
        sk_pin_set(sk_io_led_blue,1);
        sys_delay_ms(1);
        sk_pin_set(sk_io_led_blue,0);
        t7_delay_ms(5);
    }
}
// make USR_IN_DEFS=-DSK_USE_GLSK_DEFINITIONS=1 target to duild
