#include "stm32f10x.h"                  // Device header
#include "Relay.h"
#include "Liquid.h"
#include "Pressure.h"
#include "Temperature.h"
#include "Hydrogen.h"
#include "Screen.h"
#include "Valve.h"
#include "Fan.h"


void Process_Start(void)
{
	Fan_ON();
	Valve_ON();
	Relay_ON();
	
}
	
void Process_Close(void)
{
	Fan_OFF();
	Valve_OFF();
	Relay_OFF();
	
}

void Fan_Pause(void)
{
	Relay_OFF();
	
	
}
