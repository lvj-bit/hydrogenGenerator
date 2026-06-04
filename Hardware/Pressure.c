#include "stm32f10x.h"                  // Device header
#include "Pressure.h"

//压力传感器初始化
void Pressure_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);	
}

uint8_t Pressure_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5);
}





