/*
 * PID.c
 *
 *  Created on: Oct 31, 2025
 *      Author: gg
 */
#include "PID.h"
#include "main.h"
#include <stdbool.h>
#include "math.h"



//PID初始化函数
void PID_Init(PID_Increment_Struct *PID,float p,float i,float d){
	PID->Kp = p;
	PID->Ki = i;
	PID->Kd = d;
}


//PID计算函数
float PID_Increment(PID_Increment_Struct *PID, float Current, float Target)
{
    float err,                                                                                                       //误差
        out,                                                                                                         //输出
        proportion,                                                                                                  //比例
        differential;                                                                                                //微分
    err = (float)Target - (float)Current;                                                                            //计算误差
    proportion = (float)err - (float)PID->Error_Last1;                                                               //计算比例项
    differential = (float)err - 2 * (float)PID->Error_Last1 + (float)PID->Error_Last2;                               //计算微分项
    out = (float)PID->Out_Last + (float)PID->Kp * proportion + (float)PID->Ki * err + (float)PID->Kd * differential; //计算PID
    PID->Error_Last2 = PID->Error_Last1;                                                                             //更新上上次误差
    PID->Error_Last1 = err;                                                                                          //更新误差
    PID->Out_Last = out;                                                                                             //更新上此输出
    return out;
}
