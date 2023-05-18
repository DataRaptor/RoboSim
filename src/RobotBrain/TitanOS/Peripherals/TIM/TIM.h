#ifndef __TIMERPEREPHERAL_INCLUDE_HEADER
#define __TIMERPEREPHERAL_INCLUDE_HEADER

#include "stm32f10x.h"

void TIM1_Init(void);
void TIM2_Init(void);
void TIM3_Init(void);
void TIM4_Init(void);


extern uint16_t TIM2_Period;
extern uint16_t TIM3_Period;


extern uint8_t TIM1_Initialized;
extern uint8_t TIM2_Initialized;
extern uint8_t TIM3_Initialized;
extern uint8_t TIM4_Initialized;



void TIM2_OnUpdate(void);
void TIM2_CCR1_Trigger(void);
void TIM2_CCR2_Trigger(void);
void TIM2_CCR3_Trigger(void);
void TIM2_CCR4_Trigger(void);

void TIM3_OnUpdate(void);
void TIM3_CCR1_Trigger(void);
void TIM3_CCR2_Trigger(void);
void TIM3_CCR3_Trigger(void);
void TIM3_CCR4_Trigger(void);



#endif
