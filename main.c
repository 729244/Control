
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
#include "I2C.h"
#include "pit.h"
#include "NVIC.h"
#include "GPIO.h"
#include "encoder.h"
#include "ftm.h"
#include "fsl_clock.h"

#define KP = 3;
static void CLOCK_CONFIG_SetFllExtRefDiv(uint8_t frdiv)
{
    MCG->C1 = ((MCG->C1 & ~MCG_C1_FRDIV_MASK) | MCG_C1_FRDIV(frdiv));
}

int main(void) {
    CLOCK_SetSimSafeDivs();
    /* Initializes OSC0 according to board configuration. */
    CLOCK_InitOsc0(&oscConfig_BOARD_BootClockRUN);
    CLOCK_SetXtal0Freq(oscConfig_BOARD_BootClockRUN.freq);
    /* Configure the Internal Reference clock (MCGIRCLK). */
    CLOCK_SetInternalRefClkConfig(mcgConfig_BOARD_BootClockRUN.irclkEnableMode,
                                  mcgConfig_BOARD_BootClockRUN.ircs,
                                  mcgConfig_BOARD_BootClockRUN.fcrdiv);
    /* Configure FLL external reference divider (FRDIV). */
    CLOCK_CONFIG_SetFllExtRefDiv(mcgConfig_BOARD_BootClockRUN.frdiv);
    /* Set MCG to PEE mode. */
    CLOCK_BootToPeeMode(mcgConfig_BOARD_BootClockRUN.oscsel,
                        kMCG_PllClkSelPll0,
                        &mcgConfig_BOARD_BootClockRUN.pll0Config);
    /* Set the clock configuration in SIM module. */
    CLOCK_SetSimConfig(&simConfig_BOARD_BootClockRUN);
    /* Set SystemCoreClock variable. */
    SystemCoreClock = BOARD_BOOTCLOCKRUN_CORE_CLOCK;

	i2c_pin_init();
	i2c_config();
	pit_init();
	gpio_init();
	ftm_init();
	ftm_start();



	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_5);

	NVIC_global_enable_interrupts;

	uint8_t data[2] = {0, 0};
	uint8_t address = 1;
	uint8_t data_size = 2;
	int16_t voltage = 0;
	uint16_t encoder_1 = 0;

	int16_t voltage_ref = 0;
	uint16_t encoder_1_ref = 0;

	uint8_t encoder_giro = 0;
	float current_giro = 0;
	float radianes_giro = 0;
	float error = 0;
	float salida = 0;
	float cycle = 0;
	float Im1 = 0;
	float em1 = 0;

	pit_set_timer(PIT_CH0, 100);

	pit_start_timer(PIT_CH0);

    while(1) {
    	uint8_t pit_flag = PIT_get_irq_status(PIT_CH0);
    	if(pit_flag){
    		PIT_clear_irq_status(PIT_CH0);
    		pit_flag = FALSE;
    		encoder_giro = read_encoder(0);
    		//current_giro = INA219_get_current(0);
    		radianes_giro = encoder_giro *0.0495;
    		error = 1 - radianes_giro;
    		salida = error*15 + (Im1 + em1*1*0.0001);
    		cycle = salida/12*100;
    		if(0 > cycle){
    			cycle = cycle * -1;
    			if(100 < cycle)
    			{
    				cycle = 100;
    			}
    			ftm_set_duty_cycle(0, 0);
    			ftm_set_duty_cycle(2, (uint8_t)cycle);
    		}
    		else{
    			if(100 < cycle)
    			{
    				cycle = 100;
    			}
    			ftm_set_duty_cycle(2, 0);
    			ftm_set_duty_cycle(0, (uint8_t)cycle);
    		}
    	}
    	FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);
    }
    return 0 ;
}
