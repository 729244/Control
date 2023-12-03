/*
*	@file GPIO.h
*
*	@Authors Carlos Fernando Orozco Cuetara
*			 Jonathan Azahel Trujillo Zuno
*
*	@brief: This program controls all the interactions between the GPIO.c file and other layers
*
*/
#ifndef GPIO_H_
#define GPIO_H_

#include <stdio.h>
#include "fsl_gpio.h"
#include "fsl_port.h"
#include "fsl_clock.h"
#include "Bits.h"
#include "config.h"


/*! These constants are used to select an specific port in the different API functions*/
typedef enum{GPIO_A, /*!< Definition to select GPIO A */
			 GPIO_B, /*!< Definition to select GPIO B */
			 GPIO_C, /*!< Definition to select GPIO C */
			 GPIO_D, /*!< Definition to select GPIO D */
			 GPIO_E, /*!< Definition to select GPIO E */
			 GPIO_F  /*!< Definition to select GPIO F */
			} gpio_name_t;

typedef struct
{
	uint8_t flag_port_a : 1;
	uint8_t flag_port_b : 1;
	uint8_t flag_port_c : 1;
	uint8_t flag_port_d : 1;
	uint8_t flag_port_e : 1;
} gpio_interrupt_flags_t;


void GPIO_clear_irq_status(gpio_name_t);

uint8_t GPIO_get_irq_status(gpio_name_t);

void gpio_init(void);
void gpio_set_output(GPIO_Type *,uint32_t);
void gpio_clear_output(GPIO_Type *,uint32_t);
BooleanType gpio_get_stopwatch_flag(void);
void gpio_set_stopwatch_flag(BooleanType);
BooleanType gpio_get_hour_start_flag(void);
void gpio_set_hour_start_flag(BooleanType);
BooleanType gpio_get_min_stop_flag(void);
void gpio_set_min_stop_flag(BooleanType);
BooleanType gpio_get_clear_flag(void);
void gpio_set_clear_flag(BooleanType);
BooleanType gpio_get_pin(GPIO_Type *, uint32_t);
BooleanType gpio_get_alarm_on_flag(void);
void gpio_set_alarm_on_flag(BooleanType);

#endif /* GPIO_H_ */
