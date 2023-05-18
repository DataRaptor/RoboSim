#include "TitanAPI.h"
TitanAPI titanapi;
#include "titanos.h"


BlueberryAPI *blueberry32 = (BlueberryAPI*)0x20000148;

void Callback2(void)
{
	uint8_t i = 12;
	i++;
}


void OnClockReset(void)
{
	TIM2_Init();
	TIM3_Init();
}

void OnTIM2_Update()
{
	int i = 12;
	i++;
	
	GPIOC->ODR ^= GPIO_Pin_13;
}

uint32 addr;
int main()
{
	/*Load values to TitanOs API*/
	InitializeAPI();
	
	addr = (uint32)&titanapi;
	
	GPIO_PC13_Digital_OUT();
	GPIOC->BSRR |= GPIO_BSRR_BR13;
	
	
	TIM2_Init();
	TIM3_Init();
	
	
	blueberry32->SYS.OnCoreClockReset = OnClockReset;
	
	//blueberry32->IT.TIM2_IT.OnUpdate = OnTIM2_Update;
	
	
	
	
	
	//blueberry32->SYS.SetClock_40Mhz();
	
	
	/*Call Smartcat*/
	RunApp();
	
	while(1)
	{
		
		
	}
}

