#include "stm32f10x.h"                  // Device header
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "Buzzer.h"
#include "LightSensor.h"
#include "OLED.h"
#include "rcc.h"
#include "Relay.h"
#include "Liquid.h"
#include "Pressure.h"
#include "Temperature.h"
#include "Hydrogen.h"
#include "Screen.h"
#include "Valve.h"
#include "Fan.h"
#include "Process.h"


int main(void)
{
	//uint16_t i_a,i_b,i_c,i_d;
	//uint16_t ;
	uint32_t Water = 0; //水位数据
	uint16_t Tem_buff[5] = {0}; //温度数据
	//配置系统时钟
	SystemCLK_Init(RCC_PLLMul_9);//配置系统时钟
	//初始化继电器端口
	Relay_Init();
	//初始化液位传感器
	Liquid_Init();
	//初始化压力传感器
	Pressure_Init();
	//初始化温度传感器
	Temperature_Init();
	//初始化氢气传感器
	Hydrogen_Init();
	//初始化屏幕
	Screen_Init();
	//初始化阀门
	Valve_Init();
	//初始化风扇
	Fan_Init();
	
	while(1)
	{
		Delay_ms(1);
		if(sResult->OpenState == 1 )
		{
			Process_Start();
		}
		
		if(sResult->OpenState == 2 )
		{
			Process_End();
		}
		
		if(sResult->OpenState == 3 )
		{
			//Process_Pause();
		}
	}
}
