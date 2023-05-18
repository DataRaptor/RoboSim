#include "blueberry.h"


uint8_t SYSCLK_CLK = 72;

void SYSCLK_Set(uint32_t RCC_PLLMul_x)
{
//	/* Reset the RCC clock configuration to the default reset state(for debug purpose) */
//  /* Set HSION bit */
//  RCC->CR |= (uint32_t)0x00000001;
//	
//	
//	
//	/* Reset HSEON, CSSON and PLLON bits */
//  RCC->CR &= (uint32_t)0xFEF6FFFF;

//  /* Reset HSEBYP bit */
//  RCC->CR &= (uint32_t)0xFFFBFFFF;

//  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
//  RCC->CFGR &= (uint32_t)0xFF80FFFF;
//	
	
	
	
		ErrorStatus HSEStartUpStatus;
    RCC_DeInit();
    RCC_HSEConfig( RCC_HSE_ON);
    HSEStartUpStatus = RCC_WaitForHSEStartUp();

    if (HSEStartUpStatus == SUCCESS)
    {
        RCC_HCLKConfig( RCC_SYSCLK_Div1);
        RCC_PCLK2Config( RCC_HCLK_Div1);
        RCC_PCLK1Config( RCC_HCLK_Div2);
        RCC_PLLConfig(0x00010000, RCC_PLLMul_x);
        RCC_PLLCmd( ENABLE);
        while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
        {
        }

        RCC_SYSCLKConfig( RCC_SYSCLKSource_PLLCLK);

        while (RCC_GetSYSCLKSource() != 0x08)
        {
        }
				
				
				if(RCC_PLLMul_x == RCC_PLLMul_2)
					SYSCLK_CLK = 16;
				else if(RCC_PLLMul_x == RCC_PLLMul_3)
					SYSCLK_CLK = 24;
				else if(RCC_PLLMul_x == RCC_PLLMul_4)
					SYSCLK_CLK = 32;
				else if(RCC_PLLMul_x == RCC_PLLMul_5)
					SYSCLK_CLK = 40;
				else if(RCC_PLLMul_x == RCC_PLLMul_6)
					SYSCLK_CLK = 48;
				else if(RCC_PLLMul_x == RCC_PLLMul_7)
					SYSCLK_CLK = 56;
				else if(RCC_PLLMul_x == RCC_PLLMul_8)
					SYSCLK_CLK = 64;
				else if(RCC_PLLMul_x == RCC_PLLMul_9)
					SYSCLK_CLK = 72;
				else if(RCC_PLLMul_x == RCC_PLLMul_10)
					SYSCLK_CLK = 80;
				else if(RCC_PLLMul_x == RCC_PLLMul_11)
					SYSCLK_CLK = 88;
				else if(RCC_PLLMul_x == RCC_PLLMul_12)
					SYSCLK_CLK = 96;
				else if(RCC_PLLMul_x == RCC_PLLMul_13)
					SYSCLK_CLK = 104;
				else if(RCC_PLLMul_x == RCC_PLLMul_14)
					SYSCLK_CLK = 112;
				else if(RCC_PLLMul_x == RCC_PLLMul_15)
					SYSCLK_CLK = 120;
				else if(RCC_PLLMul_x == RCC_PLLMul_16)
					SYSCLK_CLK = 128;		
				
				
				
				//On Core Speed Reset
				if(api.SYS.OnCoreClockReset != NULL)
					api.SYS.OnCoreClockReset();	
    }
    else
    {
        while (1)
        {
        }
    }
		
		
		
}





void SYSCLK_16Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_2);
}

void SYSCLK_24Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_3);
}

void SYSCLK_32Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_4);
}

void SYSCLK_40Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_5);
}

void SYSCLK_48Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_6);
}

void SYSCLK_56Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_7);
}

void SYSCLK_64Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_8);
}

void SYSCLK_72Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_9);
}

void SYSCLK_80Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_10);
}

void SYSCLK_88Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_11);
}

void SYSCLK_96Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_12);
}

void SYSCLK_104Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_13);
}

void SYSCLK_112Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_14);
}

void SYSCLK_120Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_15);
}

void SYSCLK_128Mhz(void)
{
	SYSCLK_Set(RCC_PLLMul_16);
}





