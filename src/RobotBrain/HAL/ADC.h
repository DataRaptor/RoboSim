#ifndef __HAL_ADC
#define __HAL_ADC

#include "stm32f10x.h"


extern volatile uint16_t ADCBuffer[2];

void WaitForADCConversion(void);

void InitializeADC(void);
#endif
