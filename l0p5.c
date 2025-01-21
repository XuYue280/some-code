/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_ftm.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */

void pwm_setup_RED()
{
	ftm_config_t ftmInfo_RED;//responsible for configuring FTM
	ftm_chnl_pwm_signal_param_t ftmParam_RED;//configure the PWM(Pulse Width Modulation) channel
	ftmParam_RED.chnlNumber = kFTM_Chnl_1;//RED: FTM3_CH1 BLUE: FTM3_CH4  GREEN: FTM3_CH5
	ftmParam_RED.level = kFTM_HighTrue;
	ftmParam_RED.dutyCyclePercent = 0;
	ftmParam_RED.firstEdgeDelayPercent = 0U;
	ftmParam_RED.enableComplementary = false;
	ftmParam_RED.enableDeadtime = false;

	FTM_GetDefaultConfig(&ftmInfo_RED);//use default config for FTM

	FTM_Init(FTM3, &ftmInfo_RED);//initialize FTM
	FTM_SetupPwm(FTM3, &ftmParam_RED, 1U, kFTM_EdgeAlignedPwm, 5000U, CLOCK_GetFreq(
	kCLOCK_BusClk));//set up PWM
	FTM_StartTimer(FTM3, kFTM_SystemClock);
}

void pwm_setup_GREEN()
{
	ftm_config_t ftmInfo_GREEN;//responsible for configuring FTM
	ftm_chnl_pwm_signal_param_t ftmParam_GREEN;//configure the PWM(Pulse Width Modulation) channel
	ftmParam_GREEN.chnlNumber = kFTM_Chnl_5;//RED: FTM3_CH1 BLUE: FTM3_CH4  GREEN: FTM3_CH5
	ftmParam_GREEN.level = kFTM_HighTrue;
	ftmParam_GREEN.dutyCyclePercent = 0;
	ftmParam_GREEN.firstEdgeDelayPercent = 0U;
	ftmParam_GREEN.enableComplementary = false;
	ftmParam_GREEN.enableDeadtime = false;

	FTM_GetDefaultConfig(&ftmInfo_GREEN);//use default config for FTM

	FTM_Init(FTM3, &ftmInfo_GREEN);//initialize FTM
	FTM_SetupPwm(FTM3, &ftmParam_GREEN, 1U, kFTM_EdgeAlignedPwm, 5000U, CLOCK_GetFreq(
	kCLOCK_BusClk));//set up PWM
	FTM_StartTimer(FTM3, kFTM_SystemClock);
}

void pwm_setup_BLUE()
{
	ftm_config_t ftmInfo_BLUE;//responsible for configuring FTM
	ftm_chnl_pwm_signal_param_t ftmParam_BLUE;//configure the PWM(Pulse Width Modulation) channel
	ftmParam_BLUE.chnlNumber = kFTM_Chnl_4;//RED: FTM3_CH1 BLUE: FTM3_CH4  GREEN: FTM3_CH5
	ftmParam_BLUE.level = kFTM_HighTrue;
	ftmParam_BLUE.dutyCyclePercent = 0;
	ftmParam_BLUE.firstEdgeDelayPercent = 0U;
	ftmParam_BLUE.enableComplementary = false;
	ftmParam_BLUE.enableDeadtime = false;

	FTM_GetDefaultConfig(&ftmInfo_BLUE);//use default config for FTM

	FTM_Init(FTM3, &ftmInfo_BLUE);//initialize FTM
	FTM_SetupPwm(FTM3, &ftmParam_BLUE, 1U, kFTM_EdgeAlignedPwm, 5000U, CLOCK_GetFreq(
	kCLOCK_BusClk));//set up PWM
	FTM_StartTimer(FTM3, kFTM_SystemClock);
}

// map hexadecimal input into decimal output (0-255 -> 0-100)
unsigned int mapping(unsigned int hex_input){
	if (hex_input >= 0 && hex_input <= 0xFF){
		return (hex_input * 100) / 255;
	}
	else{
		printf("Invalid hex input, please retry");
		return 0;
	}
}

int main(void)
{
    char ch;
    uint32_t duty_cycle = 0;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    pwm_setup_RED();
    pwm_setup_GREEN();
    pwm_setup_BLUE();

    unsigned int RR, GG, BB;
    printf("Enter duty cycle to control the brightness (hex)");
    scanf("%2x %2x %2x",&RR, &GG, &BB);//make 3 reading from 6 digit input
    printf("The duty cycle you input is R = %x, G = %x, B=%x, ",RR, GG, BB);
    //PRINTF("hello world.\r\n");

    FTM_UpdatePwmDutycycle(FTM3, kFTM_Chnl_1, kFTM_EdgeAlignedPwm, mapping(RR));
    FTM_SetSoftwareTrigger(FTM3, true);
    FTM_UpdatePwmDutycycle(FTM3, kFTM_Chnl_5, kFTM_EdgeAlignedPwm, mapping(GG));
    FTM_SetSoftwareTrigger(FTM3, true);
    FTM_UpdatePwmDutycycle(FTM3, kFTM_Chnl_4, kFTM_EdgeAlignedPwm, mapping(BB));
    FTM_SetSoftwareTrigger(FTM3, true);
    while (1)
    {
//        ch = GETCHAR();
//        PUTCHAR(ch);
    }
}
