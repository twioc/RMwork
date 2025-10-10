#include <stdio.h>
#include "RM.h"

void IIC_Start()
{
    SDA_High();
    SCL_High();
    //视情况这里可能需要添加延时
    SDA_Low();
    SCL_Low();
}

void IIC_Stop()
{
    SDA_Low();
    SCL_High();
    //视情况这里可能需要添加延时
    SDA_High();
}

void IIC_ReceiveAck()
{
    SDA_Low();
    SCL_High();
    //视情况这里可能需要添加延时
    SCL_Low();
    SDA_High();
}

void IIC_SendByte(unsigned char byte)
{
    for (int i = 0; i < 8; i++)
    {
        if (byte & 0x80) // 发送最高位
            SDA_High();
        else
            SDA_Low();
        SCL_High();
        //视情况这里可能需要添加延时
        SCL_Low();
        byte <<= 1; // 左移一位，准备发送下一位
    }
    SDA_High(); // 释放数据线，准备接收ACK
}

void IIC_SendData(unsigned char slave_address, unsigned char register_address, unsigned char data)
{
    IIC_Start();
    IIC_SendByte(slave_address << 1); // 发送从机地址+写位
    IIC_ReceiveAck();
    IIC_SendByte(register_address); // 发送寄存器地址
    IIC_ReceiveAck();
    IIC_SendByte(data); // 发送数据
    IIC_ReceiveAck();
    IIC_Stop();
}

int main()
{
    return 0;
}