#ifndef __TEMPERATURE_H
#define __TEMPERATURE_H

void Temperature_Init(void);
uint8_t Temperature_Get(void);
uint16_t Read_ADC(uint8_t channel);
uint16_t Get_Adc_Average(uint16_t ch, uint16_t times);
uint8_t temp_data(void);

#endif
