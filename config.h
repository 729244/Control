/*
*	@file config.h
*
*	@Authors Carlos Fernando Orozco Cuetara
*			 Jonathan Azahel Trujillo Zuno
*
*	@brief: Part of the api that contains macros needed for general functions in the app
*
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#include "MK64F12.h"
#include "Bits.h"

#define B2_P1 2
#define B3_P2 3
#define B10_P3 10
#define B11_P4 11
#define C11_P5 11
#define C10_P6 10
#define B20_P7 20
#define D1_P8 1

#define C3_P1 3
#define C2_P2 2
#define A2_P3 2
#define B23_P4 23
#define A1_P5 1
#define B9_P6 9
#define C17_P7 17
#define C16_P8 16

#define CLEAR_FLAGS 0xFFFF

#define GPIO_BASE_ADDR(GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE)
#define GPIO_BASE_PTR(GPIOA, GPIOB, GPIOC, GPIOD)



#endif /* CONFIG_H_ */
