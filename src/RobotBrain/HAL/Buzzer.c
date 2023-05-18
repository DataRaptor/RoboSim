#include "stm32f10x.h"
#include "Buzzer.h"


uint16_t beepDuration;
uint16_t frequency;

void Buzzer_Beep(uint16_t BeepDuration, uint16_t Frequency)
{
	beepDuration = BeepDuration;
	frequency = Frequency;
	
	for(uint16_t i = 0; i < beepDuration; i++)
	{
		for(uint16_t j = 0; j < frequency; j++);
		
		GPIOB->ODR ^= GPIO_Pin_11;
	}
	
	
}


void Buzzer_Beep_430()
{
	Buzzer_Beep(700, 430);
}

void Buzzer_Beep_470()
{
	Buzzer_Beep(700, 470);
}

void Buzzer_Beep_500()		//***
{
	Buzzer_Beep(700, 500);
}


void Buzzer_Beep_530()
{
	Buzzer_Beep(700, 530);
}

void Buzzer_Beep_540()
{
	Buzzer_Beep(700, 540);
}




void Buzzer_Beep_2300()		// ***
{
	for(uint16_t i = 0; i < 700; i++)
	{
		for(uint16_t j = 0; j < 2300; j++);
		
		GPIOB->ODR ^= GPIO_Pin_11;
	}
}





