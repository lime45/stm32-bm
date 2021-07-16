#include "main.h"


static void initialize_gpiob(void)
{

    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // B3 is connected to an LED on the 'Nucleo' board.
    //    It should be set to push-pull low-speed output.
    /* 
     * each port gets 2 bytes of the MODE register (hence LED_PIN *2)
     * 1st one sets MODER for this port to 0x00, keeping others the same
     * 2nd sets port to output: 0 = input, 1 = output, 2 = alt func mode, 3 = analog mode
     * 3rd sets to output push-pull
     */
    GPIOB->MODER  &= ~(0x3 << (LED_PIN*2));
    GPIOB->MODER  |=  (0x1 << (LED_PIN*2));
    GPIOB->OTYPER &= ~(1 << LED_PIN);
}

static void setup_timers(void)
{
    // Initial clock setup.
    // Reset the Flash 'Access Control Register', and
    // then set 1 wait-state and enable the prefetch buffer.
    // (The device header files only show 1 bit for the F0
    //  line, but the reference manual shows 3...)
    FLASH->ACR &= ~(0x00000017);
    FLASH->ACR |=  (FLASH_ACR_LATENCY |
            FLASH_ACR_PRFTBE);
    // Configure the PLL to (HSI / 2) * 12 = 48MHz.
    // Use a PLLMUL of 0xA for *12, and keep PLLSRC at 0
    // to use (HSI / PREDIV) as the core source. HSI = 8MHz.
    RCC->CFGR  &= ~(RCC_CFGR_PLLMUL |
            RCC_CFGR_PLLSRC);
    RCC->CFGR  |=  (RCC_CFGR_PLLSRC_HSI_DIV2 |
            RCC_CFGR_PLLMUL12);
    // Turn the PLL on and wait for it to be ready.
    RCC->CR    |=  (RCC_CR_PLLON);
    while (!(RCC->CR & RCC_CR_PLLRDY)) {};
    // Select the PLL as the system clock source.
    RCC->CFGR  &= ~(RCC_CFGR_SW);
    RCC->CFGR  |=  (RCC_CFGR_SW_PLL);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {};
    // Set the global clock speed variable.
    core_clock_hz = 48000000;

    // Enable the GPIOB clock.
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    // Enable the TIM2 clock.
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Setup GPIO pin B3 as push-pull output, no pupdr.
    GPIOB->MODER   &= ~(3 << (LED_PIN*2));
    GPIOB->MODER   |=  (1 << (LED_PIN*2));
    GPIOB->OTYPER  &= ~(1 << LED_PIN);
    GPIOB->PUPDR   &= ~(3 << (LED_PIN*2));

    // Enable the NVIC interrupt for TIM2.
    // (Timer peripheral initialized and used elsewhere)
    NVIC_SetPriority(TIM2_IRQn, 0x03);
    NVIC_EnableIRQ(TIM2_IRQn);
    // Start the timer.
    start_timer(TIM2, 1);

}
/* Main program. */
int main(void)
{
    led_on = 0;

    initialize_gpiob();

    setup_timers();

    // uint32_t gpiob_input = GPIOB->IDR;
    GPIOB->ODR |= (1 << LED_PIN);
    while (1) {
        GPIOB->ODR ^= (1 << LED_PIN);
    }
}


