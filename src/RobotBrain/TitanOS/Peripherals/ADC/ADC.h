#ifndef __HAL_ADC
#define __HAL_ADC

#include "stm32f10x.h"


//extern volatile uint16_t ADCBuffer[11];

//void WaitForADCConversion(void);





void ADC_PA0_Init(void);
void ADC_PA1_Init(void);
void ADC_PA2_Init(void);
void ADC_PA3_Init(void);
void ADC_PA4_Init(void);
void ADC_PA5_Init(void);
void ADC_PA6_Init(void);
void ADC_PA7_Init(void);
void ADC_PB0_Init(void);
void ADC_PB1_Init(void);


uint16_t ADC_PA0(void);
uint16_t ADC_PA1(void);
uint16_t ADC_PA2(void);
uint16_t ADC_PA3(void);
uint16_t ADC_PA4(void);
uint16_t ADC_PA5(void);
uint16_t ADC_PA6(void);
uint16_t ADC_PA7(void);
uint16_t ADC_PB0(void);
uint16_t ADC_PB1(void);





#endif
