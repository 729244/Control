/*
*	@file GPIO.c
*
*	@Authors Carlos Fernando Orozco Cuetara
*			 Jonathan Azahel Trujillo Zuno
*
*	@brief: This program controls the general input output on the system and its interrupts
*
*/
#include "GPIO.h"



volatile static gpio_interrupt_flags_t g_intr_status_flag = {0};

void PORTC_IRQHandler(void)
{
	g_intr_status_flag.flag_port_c = TRUE;
	GPIO_PortClearInterruptFlags(GPIOC, CLEAR_FLAGS);
}

void PORTB_IRQHandler(void)
{


	g_intr_status_flag.flag_port_b = TRUE;


	GPIO_PortClearInterruptFlags(GPIOB, CLEAR_FLAGS);
}

void PORTA_IRQHandler(void)
{

	g_intr_status_flag.flag_port_a = TRUE;


	GPIO_PortClearInterruptFlags(GPIOA, CLEAR_FLAGS);
}

void gpio_init(void)
{
	gpio_pin_config_t gpio_input_config = {
			        kGPIO_DigitalInput,
			        0,
			    };

	CLOCK_EnableClock(kCLOCK_PortA);
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortD);
	CLOCK_EnableClock(kCLOCK_PortE);


	 PORT_SetPinMux(PORTB, B18_P1, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B18_P1, &gpio_input_config);

	 PORT_SetPinMux(PORTB, B19_P2, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B18_P1, &gpio_input_config);

	 PORT_SetPinMux(PORTB, B10_P3, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B10_P3, &gpio_input_config);

	 PORT_SetPinMux(PORTB, B11_P4, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B11_P4, &gpio_input_config);

	 PORT_SetPinMux(PORTC, C11_P5, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOC, C11_P5, &gpio_input_config);

	 PORT_SetPinMux(PORTC, C10_P6, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOC, C10_P6, &gpio_input_config);

	 PORT_SetPinMux(PORTB, B20_P7, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B20_P7, &gpio_input_config);

	 PORT_SetPinMux(PORTD, D1_P8, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOD, D1_P8, &gpio_input_config);


	 PORT_SetPinMux(PORTC, C3_P1, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOC, C3_P1, &gpio_input_config);

	 PORT_SetPinMux(PORTE, E24_P2, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOE, E24_P2, &gpio_input_config);

	 PORT_SetPinMux(PORTA, A2_P3, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOA, A2_P3, &gpio_input_config);

	 PORT_SetPinMux(PORTB, B23_P4, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B23_P4, &gpio_input_config);

	 PORT_SetPinMux(PORTA, A1_P5, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOA, A1_P5, &gpio_input_config);

	 PORT_SetPinMux(PORTB, B9_P6, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOB, B9_P6, &gpio_input_config);

	 PORT_SetPinMux(PORTC, C17_P7, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOC, C17_P7, &gpio_input_config);

	 PORT_SetPinMux(PORTC, C16_P8, kPORT_MuxAsGpio);
	 GPIO_PinInit(GPIOC, C16_P8, &gpio_input_config);





}


void GPIO_clear_irq_status(gpio_name_t gpio)
{
	if(GPIO_A == gpio)
	{
		g_intr_status_flag.flag_port_a = FALSE;
	}
	else
	{
		g_intr_status_flag.flag_port_c = FALSE;
	}
}

uint8_t GPIO_get_irq_status(gpio_name_t gpio)
{
	uint8_t status = 0u;

	if(GPIO_A == gpio)
	{
		status = g_intr_status_flag.flag_port_a;
	}
	else
	{
		status = g_intr_status_flag.flag_port_c;
	}

	return(status);
}

void gpio_set_output(GPIO_Type *port,uint32_t pin)
{
	GPIO_PortSet(port, 1 << pin);
}

void gpio_clear_output(GPIO_Type *port,uint32_t pin)
{
	GPIO_PortClear(port, 1 << pin);
}



BooleanType gpio_get_pin(GPIO_Type *port, uint32_t pin)
{
	return GPIO_PinRead(port, pin);
}


