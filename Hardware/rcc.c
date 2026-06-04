#include "stm32f10x.h"  
#include "rcc.h"


void SystemCLK_Init(uint32_t RCC_PLLMul_x)
{
	uint32_t HSEStartUpStatus = 0;
	RCC_DeInit(); //rcc重置为默认状态
	RCC_HSEConfig(RCC_HSE_ON); //使能
	HSEStartUpStatus = RCC_WaitForHSEStartUp(); //启动
	
	if(HSEStartUpStatus == SUCCESS)
	{
		//使能预取指
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		//设置等待
		FLASH_SetLatency(FLASH_Latency_2);
		//配置三总线分频因子
		RCC_HCLKConfig( RCC_SYSCLK_Div1 );
        RCC_PCLK1Config( RCC_HCLK_Div2 );
        RCC_PCLK2Config( RCC_HCLK_Div1 );
		
		//配置PLL的时钟源和倍频因子
		RCC_PLLConfig( RCC_PLLSource_HSE_Div1, RCC_PLLMul_x );
		//使能PLL
		RCC_PLLCmd(ENABLE);
		//等待PLL稳定
        while( RCC_GetFlagStatus( RCC_FLAG_PLLRDY ) == RESET );
        
        //选择系统时钟
        RCC_SYSCLKConfig( RCC_SYSCLKSource_PLLCLK );
        
        //等待系统时钟稳定
        while( RCC_GetSYSCLKSource() != 0x08 );
	}
	
	
}

