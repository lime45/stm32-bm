#include "main.h"

void EXTI0_1_IRQ_handler(void);
volatile unsigned char led_on;

static void initialize_gpiob(void)
{

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
}

static void setup_interrupts()
{

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
}

static void setup_timers(void)
{
    // Initial clock setup.
#ifdef VVC_F0
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
#elif VVC_L0
    // Set the Flash ACR to use 1 wait-state
    // and enable the prefetch buffer and pre-read.
    FLASH->ACR |=  (FLASH_ACR_LATENCY |
            FLASH_ACR_PRFTEN |
            FLASH_ACR_PRE_READ);
    // Enable the HSI oscillator, since the L0 series boots
    // to the MSI one.
    RCC->CR    |=  (RCC_CR_HSION);
    while (!(RCC->CR & RCC_CR_HSIRDY)) {};
    // Configure the PLL to use HSI16 with a PLLDIV of
    // 2 and PLLMUL of 4.
    RCC->CFGR  &= ~(RCC_CFGR_PLLDIV |
            RCC_CFGR_PLLMUL |
            RCC_CFGR_PLLSRC);
    RCC->CFGR  |=  (RCC_CFGR_PLLDIV2 |
            RCC_CFGR_PLLMUL4 |
            RCC_CFGR_PLLSRC_HSI);
    // Enable the PLL and wait for it to stabilize.
    RCC->CR    |=  (RCC_CR_PLLON);
    while (!(RCC->CR & RCC_CR_PLLRDY)) {};
    // Select the PLL as the system clock source.
    RCC->CFGR  &= ~(RCC_CFGR_SW);
    RCC->CFGR  |=  (RCC_CFGR_SW_PLL);
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)) {};
    // Set the global clock speed variable.
    core_clock_hz = 32000000;
#endif

#ifdef VVC_F0
    // Enable the GPIOB clock.
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
#elif VVC_L0
    // Enable the GPIOB clock.
    RCC->IOPENR   |= RCC_IOPENR_IOPBEN;
  #endif
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
  start_timer(TIM2, 1000);

}
/* Main program. */
int main(void)
{
    led_on = 0;

    initialize_gpiob();

    setup_interrupts();

    setup_timers();

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


