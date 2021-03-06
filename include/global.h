#ifndef _VVC_GLOBAL_H
#define _VVC_GLOBAL_H
#define VVC_F0

// Core includes.
#ifndef VVC_F0
#define VVC_F0 1
#endif
#ifdef VVC_F0

  #include "stm32f0xx.h"
  #include "stm32f031x6.h"
#elif VVC_L0
  #include "stm32l0xx.h"
#endif

// ----------------------
// Global variables and defines.
#define LED_PIN (1)
// (Core system clock speed; initial value depends on the chip.)
volatile uint32_t core_clock_hz;
volatile unsigned char led_on;

#endif
