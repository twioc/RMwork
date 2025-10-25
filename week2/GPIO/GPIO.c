#include <stdio.h>

typedef struct {
    int GPIO_Speed;
}GPIOInit;

typedef enum{
    GPIO_Speed_2MHz,
    GPIO_Speed_10MHz,
    GPIO_Speed_50MHz
}GPIOSPEED;

void GPIO_StructureInit(GPIOInit *GPIOInitstructure)
{
    GPIOInitstructure->GPIO_Speed = GPIO_Speed_2MHz;
    printf("初始化成功\n");
}

int main(){
    GPIOInit gpioinitstructure;
    GPIO_StructureInit(&gpioinitstructure);
    return 0;
}