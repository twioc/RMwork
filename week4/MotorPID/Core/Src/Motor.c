/*
 * Motor.c
 *
 *  Created on: Oct 23, 2025
 *      Author: gg
 */
#include "Motor.h"
#include "main.h"
#include "tim.h"

void Motor_Init(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

static inline void SetInPWM(uint8_t duty){
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,duty);
}

void MotorForward(uint8_t speed){
	if(speed>MAX_SPEED){
		speed = MAX_SPEED;
	}
	HAL_GPIO_WritePin(MotorBin1_GPIO_Port, MotorBin1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(MotorBin2_GPIO_Port, MotorBin2_Pin, GPIO_PIN_RESET);

	SetInPWM(speed);
}

void MotorBackward(uint8_t speed){
	if(speed>MAX_SPEED){
		speed = MAX_SPEED;
	}
	HAL_GPIO_WritePin(MotorBin1_GPIO_Port, MotorBin1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MotorBin2_GPIO_Port, MotorBin2_Pin, GPIO_PIN_SET);

	SetInPWM(speed);
}
