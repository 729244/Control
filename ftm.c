/*
 * ftm.c
 *
 *  Created on: 4 dic 2023
 *      Author: Fernando
 */
#include "ftm.h"

static  ftm_chnl_pwm_signal_param_t ftmParam[4];

void ftm_init(){
	//Pin config
	CLOCK_EnableClock(kCLOCK_PortC);

    PORT_SetPinMux(PORTC, 1U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTC, 2U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTC, 4U, kPORT_MuxAlt4);
    PORT_SetPinMux(PORTC, 5U, kPORT_MuxAlt7);

	ftm_config_t ftmInfo;
    FTM_GetDefaultConfig(&ftmInfo);
    /* Calculate the clock division based on the PWM frequency to be obtained */
    ftmInfo.prescale = FTM_CalculateCounterClkDiv(BOARD_FTM_BASEADDR, DEMO_PWM_FREQUENCY, FTM_SOURCE_CLOCK);
    /* Initialize FTM module */
    FTM_Init(BOARD_FTM_BASEADDR, &ftmInfo);

    /* Configure ftm params with frequency 24kHZ */
    ftmParam[0].chnlNumber            = (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL;
    ftmParam[0].level                 = FTM_PWM_ON_LEVEL;
    ftmParam[0].dutyCyclePercent      = 0U;
    ftmParam[0].firstEdgeDelayPercent = 0U;
    ftmParam[0].enableComplementary   = false;
    ftmParam[0].enableDeadtime        = false;

    ftmParam[1].chnlNumber            = (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL;
    ftmParam[1].level                 = FTM_PWM_ON_LEVEL;
    ftmParam[1].dutyCyclePercent      = 0U;
    ftmParam[1].firstEdgeDelayPercent = 0U;
    ftmParam[1].enableComplementary   = false;
    ftmParam[1].enableDeadtime        = false;

    ftmParam[2].chnlNumber            = (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL;
    ftmParam[2].level                 = FTM_PWM_ON_LEVEL;
    ftmParam[2].dutyCyclePercent      = 0U;
    ftmParam[2].firstEdgeDelayPercent = 0U;
    ftmParam[2].enableComplementary   = false;
    ftmParam[2].enableDeadtime        = false;

    ftmParam[3].chnlNumber            = (ftm_chnl_t)BOARD_FOUR_FTM_CHANNEL;
    ftmParam[3].level                 = FTM_PWM_ON_LEVEL;
    ftmParam[3].dutyCyclePercent      = 0U;
    ftmParam[3].firstEdgeDelayPercent = 0U;
    ftmParam[3].enableComplementary   = false;
    ftmParam[3].enableDeadtime        = false;

    FTM_SetupPwm(BOARD_FTM_BASEADDR, ftmParam, 4U, kFTM_EdgeAlignedPwm, DEMO_PWM_FREQUENCY, FTM_SOURCE_CLOCK);

    /*FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl0InterruptEnable);
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl1InterruptEnable);
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl2InterruptEnable);
    FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_Chnl3InterruptEnable);

    EnableIRQ(FTM0_IRQn);
    EnableIRQ(FTM1_IRQn);
    EnableIRQ(FTM2_IRQn);
    EnableIRQ(FTM3_IRQn);
     */

}

void ftm_start(){
	FTM_StartTimer(BOARD_FTM_BASEADDR, kFTM_SystemClock);
}

void ftm_set_duty_cycle(uint8_t chanel, uint8_t duty){
	if(chanel == 0){
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR,  (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, duty);
	}
	else if(chanel == 1){
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR,  (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, duty);
	}
	else if(chanel == 2){
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR,  (ftm_chnl_t)BOARD_THIRD_FTM_CHANNEL, kFTM_EdgeAlignedPwm, duty);
	}
	else if(chanel == 3){
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR,  (ftm_chnl_t)BOARD_FOUR_FTM_CHANNEL, kFTM_EdgeAlignedPwm, duty);
	}
}
