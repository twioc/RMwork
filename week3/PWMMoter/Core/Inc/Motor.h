/*
 * Motor.h
 *
 *  Created on: Oct 23, 2025
 *      Author: gg
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include <stdint.h>

#define MAX_SPEED 100

void Motor_Init();
void MotorForward(uint8_t speed);
void MotorBackward(uint8_t speed);

#endif /* INC_MOTOR_H_ */
