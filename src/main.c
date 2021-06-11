#include "main.h"

/* Main program. */
int main(void) {
#if 1
	// Keep track of whether the button is pressed.
	uint8_t button_down = 0;
	
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

	// uint32_t gpiob_input = GPIOB->IDR;
	GPIOB->ODR |= (1 << LED_PIN);
	while (1) {
		// Invert the IDR register since '0' means 'pressed'.
		uint32_t idr_val = ~GPIOB->IDR;
		if (idr_val & (1 << BUTTON_PIN)) {
			// The button is pressed; if it was not already
			// pressed, change the LED state.
			if (!button_down) {
				GPIOB->ODR ^= (1 << LED_PIN);
			}
			button_down = 1;
		}
		else {
			button_down = 0;
		}
	}
#else
	int val = 0;
	while (1) {
		val += 1;
	}
#endif
}
