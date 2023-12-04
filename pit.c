/* Made by:

	Carlos Fernando Orozco Cuetara

	&

	Jonathan Azahel Trujillo Zuno

	2023

	brief: This program controls the PIT for general usage, inicialization, timer configurations,
		   channel selection, and interrupt service routines

*/

#include <pit.h>




volatile static pit_interrupt_flags_t p_intr_status_flag = {0,0,0};

static void (*pit_channel_0_callback)() = 0;
static void (*pit_channel_1_callback)() = 0;
static void (*pit_channel_2_callback)() = 0;

void pit_init (void)
{
	 pit_config_t pitConfig;
	 PIT_GetDefaultConfig(&pitConfig);
	 PIT_Init(PIT_BASEADDR, &pitConfig);
	 PIT_EnableInterrupts(PIT_BASEADDR, PIT_CH0, kPIT_TimerInterruptEnable);
	 PIT_EnableInterrupts(PIT_BASEADDR, PIT_CH1, kPIT_TimerInterruptEnable);
	 PIT_EnableInterrupts(PIT_BASEADDR, PIT_CH2, kPIT_TimerInterruptEnable);
}



void PIT0_IRQHandler(void){
	p_intr_status_flag.flag_pit_ch0 = TRUE;
	if(pit_channel_0_callback)
	{
		pit_channel_0_callback();
	}
	PIT_ClearStatusFlags(PIT_BASEADDR, PIT_CH0, INTERRUPT_MASK);
}

void PIT1_IRQHandler(void){
	p_intr_status_flag.flag_pit_ch1 = TRUE;
	if(pit_channel_1_callback)
	{
		pit_channel_1_callback();
	}
	PIT_ClearStatusFlags(PIT_BASEADDR, PIT_CH1, INTERRUPT_MASK);
}

void PIT2_IRQHandler(void){
	p_intr_status_flag.flag_pit_ch2 = TRUE;
	if(pit_channel_2_callback)
	{
		pit_channel_2_callback();
	}
	PIT_ClearStatusFlags(PIT_BASEADDR, PIT_CH2, INTERRUPT_MASK);
}

void PIT_clear_irq_status(pit_name_t pit)
{
	if(PIT_CH0 == pit)
	{
		p_intr_status_flag.flag_pit_ch0 = FALSE;
	}
	else if(PIT_CH1 == pit)
	{
		p_intr_status_flag.flag_pit_ch1 = FALSE;
	}
	else if(PIT_CH2 == pit)
	{
		p_intr_status_flag.flag_pit_ch2 = FALSE;
	}
}

uint8_t PIT_get_irq_status(pit_name_t pit)
{
	uint8_t status = 0;

	if(PIT_CH0 == pit)
	{
		status = p_intr_status_flag.flag_pit_ch0;
	}
	else if(PIT_CH1 == pit)
	{
		status = p_intr_status_flag.flag_pit_ch1;
	}
	else if(PIT_CH2 == pit)
	{
		status = p_intr_status_flag.flag_pit_ch2;
	}


	return(status);
}

void pit_start_timer(pit_name_t pit)
{
	PIT_StartTimer(PIT_BASEADDR, pit);
}

void pit_stop_timer(pit_name_t pit)
{
	PIT_StopTimer(PIT_BASEADDR, pit);
}

void pit_set_timer(pit_name_t pit, uint64_t time_us)
{
	PIT_SetTimerPeriod(PIT_BASEADDR, pit, USEC_TO_COUNT(time_us, PIT_SOURCE_CLOCK));
}




void pit_callback_init(pit_name_t pit, void (*handler)(void))
{
	if(PIT_CH0 == pit)
	{
		pit_channel_0_callback = handler;
	}
	else if(PIT_CH1 == pit)
	{
		pit_channel_1_callback = handler;
	}
	else if(PIT_CH2 == pit)
	{
		pit_channel_2_callback = handler;
	}
}

