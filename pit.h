/* Made by:

	Carlos Fernando Orozco Cuetara

	&

	Jonathan Azahel Trujillo Zuno

	2023

	brief: This program controls the interactions between PIT.c and other layers

*/

#ifndef PIT_H_
#define PIT_H_

#include "Bits.h"
#include <stdint.h>
#include "fsl_pit.h"
#include "bits.h"

typedef enum{PIT_CH0, /*!< Definition to select GPIO A */
			 PIT_CH1, /*!< Definition to select GPIO B */
			 PIT_CH2, /*!< Definition to select GPIO C */
			 PIT_CH3 /*!< Definition to select GPIO F */
			} pit_name_t;

typedef struct
{
	uint8_t flag_pit_ch0 : 1;
	uint8_t flag_pit_ch1 : 1;
	uint8_t flag_pit_ch2 : 1;
	uint8_t flag_pit_ch3 : 1;
} pit_interrupt_flags_t;

#define NSEC_TO_COUNT(us, clockFreqInHz) (uint64_t)(((uint64_t)(us) * (clockFreqInHz)) / 1000U)

#define PIT_BASEADDR PIT
#define PIT_CHANNEL  kPIT_Chnl_0
#define PIT_IRQ_ID   PIT0_IRQn
/* Get source clock for PIT driver */
#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)
#define time_selector_of 4
#define TIME_0 1000000u //1 second
#define TIME_1 10000u //10 milliseconds
#define TIME_2 100u //10o microseconds

#define INTERRUPT_MASK 0xFFFF

void pit_init (void);
void PIT_clear_irq_status(pit_name_t);
uint8_t PIT_get_irq_status(pit_name_t);
void pit_start_timer(pit_name_t);
void pit_stop_timer(pit_name_t);
void pit_set_timer(pit_name_t, uint64_t);
void pit_callback_init(pit_name_t , void (*)(void));

#define NSEC_TO_COUNT(us, clockFreqInHz) (uint64_t)(((uint64_t)(us) * (clockFreqInHz)) / 1000U)

#endif /* PIT_H_ */
