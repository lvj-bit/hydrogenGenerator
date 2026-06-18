#include "stm32f10x.h"                  // Device header
#include "Temperature.h"
#include "Delay.h"
#include <math.h>

//温度传感器初始化 adc采样
void Temperature_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_ADC1,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOB, &GPIO_InitStruct);	
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 5;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_Cmd(ADC1,ENABLE);
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
}

uint8_t Temperature_Get(void)
{
	return temp_data();
}

uint16_t Read_ADC(uint8_t channel)
{
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,channel,ADC_SampleTime_55Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
	uint16_t adc_val = ADC_GetConversionValue(ADC1);
	return adc_val ;
}

uint16_t Get_Adc_Average(uint16_t channel, uint16_t times)
{
	uint32_t temp_val = 0;
	uint16_t i;
	for(i = 0; i< times; i++)
	{
		temp_val += Read_ADC(channel);
		Delay_ms(5);
		
	}
	
	return temp_val / times;
}

//电压换算成温度
/*  NTC热敏：Rt = R*EXP(B*(1/T1-1/T2))
	Rt是热敏电阻在T1温度下的阻值
	R是热敏电阻在T2常温下的标称阻值
	B是热敏电阻的参数
	EXP是e的n次方
	T1和T2指的是开尔文温度，273.15+摄氏度
*/
uint8_t temp_data(void)
{
	float temp;
	float Rt = 0;			
	float Rp = 10000; //上拉电阻
	float T2 = 273.15+25;
	float Bx = 3950;
	float ka = 273.15;
	float vol = 0;
	vol = (float)(Get_Adc_Average(ADC_Channel_5,10)*3.3/4096);//采样
	Rt = (3.3-vol)*10000/vol; 
	temp = 1.0/(1.0/T2+log(Rt/Rp)/Bx)-ka+0.5;
	return temp;
}

