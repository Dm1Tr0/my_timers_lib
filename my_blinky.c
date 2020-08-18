#include "sk_lib.h"
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/rcc.h>

void interrupt_init()
{

    const uint8_t group = 2;
    const uint8_t subgroup = 0;
    nvic_set_priority(NVIC_EXTI0_IRQ, (group << 2) | subgroup);

    rcc_periph_clock_enable(RCC_SYSCFG);

    exti_select_source(EXTI0, GPIOA);
    exti_set_trigger(EXTI0, EXTI_TRIGGER_RISING);	// ACTIVE HIGH, so trigger on 0->1 transition
    exti_enable_request(EXTI0);
    exti_reset_request(EXTI0);

    // Now finally enable it
    nvic_enable_irq(NVIC_EXTI0_IRQ);
    cm_enable_interrupts();
}

void timer7_init()
{

}

void systic_int()
{

}


void mod_groupe_set(sk_pin * pins)
{
    sk_arr_foreach(a_pin, pins) {
        sk_pin_mode(a_pin);
    }

}

int main(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOD);

    sk_pin pin_group [] = {sk_io_led_red, sk_io_led_green, sk_io_led_orange,sk_io_btn_usr};
    mod_groupe_set(pin_group);

    sk_pin_set(sk_io_led_red,1);
    interrupt_init();
    sk_pin_toggle(sk_io_led_red);
}
