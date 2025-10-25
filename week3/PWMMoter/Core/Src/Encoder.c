/*
 * Encoder.c
 *
 *  Created on: Oct 24, 2025
 *      Author: gg
 */
#include "Encoder.h"
#include "tim.h"
#include "main.h"

void EncoderInit(){
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

short EncoderRead(){
	short count = (short)__HAL_TIM_GET_COUNTER(&htim3);
	return count;
}
