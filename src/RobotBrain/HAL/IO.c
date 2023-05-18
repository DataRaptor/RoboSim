#include "stm32f10x.h"

void ToggleLED()
{
	GPIOC->ODR ^= GPIO_Pin_13;
}






