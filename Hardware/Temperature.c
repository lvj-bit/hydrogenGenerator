#include "stm32f10x.h"                  // Device header
#include "Temperature.h"

//温度传感器初始化 adc采样
void Temperature_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);	
}

uint8_t Temperature_Get(void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
}

