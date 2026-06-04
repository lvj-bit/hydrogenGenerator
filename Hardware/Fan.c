#include "stm32f10x.h"  
#include "Fan.h"

//风扇初始化
void Fan_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
		
}


void Fan_ON(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
	
}	

void Fan_OFF(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
	
}
