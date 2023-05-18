#ifndef __HAL_Timer
#define __HAL_Timer

#include "stm32f10x.h"


void TIM8_EventHandler_Initialize(void);



void TIM1_SetCounter(void);
uint16_t TIM1_GetCounter(void);

void TIM2_SetCounter(void);
uint16_t TIM2_GetCounter(void);


void TIM3_SetCounter(void);
uint16_t TIM3_GetCounter(void);


#endif
