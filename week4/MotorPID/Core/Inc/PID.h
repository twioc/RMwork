/*
 * PID.h
 *
 *  Created on: Oct 31, 2025
 *      Author: gg
 */

#ifndef INC_PID_H_
#define INC_PID_H_

typedef struct __PID_Increment_Struct
{
    float Kp, Ki, Kd;  //系数
    float Error_Last1; //上次误差
    float Error_Last2; //上次误差
    float Out_Last;    //上次输出
} PID_Increment_Struct;

void PID_Init(PID_Increment_Struct *PID,float p,float i,float d);
float PID_Increment(PID_Increment_Struct *PID, float Current, float Target);

#endif /* INC_PID_H_ */
