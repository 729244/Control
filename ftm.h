/*
 * ftm.h
 *
 *  Created on: 4 dic 2023
 *      Author: Fernando
 */

#ifndef FTM_H_
#define FTM_H_

#include "fsl_ftm.h"
#include "Bits.h"
#include "fsl_port.h"

#define FTM_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)

#define BOARD_FTM_BASEADDR       FTM0
#define BOARD_FIRST_FTM_CHANNEL  0U
#define BOARD_SECOND_FTM_CHANNEL 1U
#define BOARD_THIRD_FTM_CHANNEL 2U
#define BOARD_FOUR_FTM_CHANNEL 3U

#define DEMO_PWM_FREQUENCY (24000U)
#define FTM_PWM_ON_LEVEL kFTM_HighTrue


#endif /* FTM_H_ */
