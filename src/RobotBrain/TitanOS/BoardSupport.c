#include "BoardSupport.h"

void ToggleLED(void)
{
	GPIOC->ODR ^= GPIO_Pin_13;
}

void LED_OFF(void)
{
	GPIOC->BSRR |= GPIO_BSRR_BS13;
}

void LED_ON(void)
{
	GPIOC->BSRR |= GPIO_BSRR_BR13;
}
