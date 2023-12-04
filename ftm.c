/*
 * ftm.c
 *
 *  Created on: 4 dic 2023
 *      Author: Fernando
 */
#include "ftm.h"

static  ftm_chnl_pwm_signal_param_t ftmParam[2];

void ftm_init(){
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
}

void ftm_start(){
	FTM_StartTimer(BOARD_FTM_BASEADDR, kFTM_SystemClock);
}

void ftm_set_duty_cycle(uint8_t chanel, uint8_t duty){
	if(chanel == 0){
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR,  (ftm_chnl_t)BOARD_FIRST_FTM_CHANNEL, kFTM_EdgeAlignedPwm, duty);
	}
	else if(channel == 1){
		FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR,  (ftm_chnl_t)BOARD_SECOND_FTM_CHANNEL, kFTM_EdgeAlignedPwm, duty);
	}
}
