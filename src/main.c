#include "main.h"

void EXTI0_1_IRQ_handler(void);
volatile unsigned char led_on;

/* Main program. */
int main(void) {
    led_on = 0;

    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // Initialize the GPIOB pins.
    // B1 should be set to 'input' mode with pull-up.
    GPIOB->MODER  &= ~(0x3 << (BUTTON_PIN*2));
    GPIOB->PUPDR  &= ~(0x3 << (BUTTON_PIN*2));
    GPIOB->PUPDR  |=  (0x1 << (BUTTON_PIN*2));
    // B3 is connected to an LED on the 'Nucleo' board.
    //    It should be set to push-pull low-speed output.
    GPIOB->MODER  &= ~(0x3 << (LED_PIN*2));
    GPIOB->MODER  |=  (0x1 << (LED_PIN*2));
    GPIOB->OTYPER &= ~(1 << LED_PIN);

    // part 5 "bare metal" tutorial: interrupts
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    // Set SYSCFG to connect the button EXTI line to GPIOB.
    SYSCFG->EXTICR[(BUTTON_PIN/4)] &= ~(0xF << ((BUTTON_PIN % 4) * 4));
    SYSCFG->EXTICR[(BUTTON_PIN/4)] |=  (0x1 << ((BUTTON_PIN % 4) * 4));
    // Setup the button's EXTI line as an interrupt.
    EXTI->IMR  |=  (1 << BUTTON_PIN);
    // Disable the 'rising edge' trigger (button release).
    EXTI->RTSR &= ~(1 << BUTTON_PIN);
    // Enable the 'falling edge' trigger (button press).
    EXTI->FTSR |=  (1 << BUTTON_PIN);
    // Enable the NVIC interrupt for EXTI0 and EXTI1 at minimum priority.
    NVIC_SetPriority(EXTI0_1_IRQn, 0x03);
    NVIC_EnableIRQ(EXTI0_1_IRQn);

    // uint32_t gpiob_input = GPIOB->IDR;
    GPIOB->ODR |= (1 << LED_PIN);
    while (1) {
    }
}

void EXTI0_1_IRQ_handler(void)
{
    if (EXTI->PR & (1 << BUTTON_PIN)) {
        // Clear the EXTI status flag.
        EXTI->PR |= (1 << BUTTON_PIN);
        if (!led_on) {
            GPIOB->ODR ^= (1 << LED_PIN);
        }
         // Toggle the global 'led on?' variable.
        led_on = !led_on;
    }
}


