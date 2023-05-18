#include "stm32f10x.h"
#include "TIMs.h"

#define PERIOD 1000

/*For Motor Driver*/
//void ConfigureTIM4()
//{
//	TIM_TimeBaseInitTypeDef timer;
//	TIM_OCInitTypeDef timerPWM;
//	
//	
//	TIM_TimeBaseStructInit(&timer);
//	timer.TIM_Prescaler = 720;
//	timer.TIM_Period = PERIOD;
//	timer.TIM_ClockDivision = 0;
//	timer.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM4, &timer);

//	TIM_OCStructInit(&timerPWM);
//	timerPWM.TIM_Pulse = 10;
//	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
//	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
//	timerPWM.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	TIM_OC1Init(TIM4, &timerPWM);
//	TIM_OC2Init(TIM4, &timerPWM);
//	TIM_OC3Init(TIM4, &timerPWM);
//	TIM_OC4Init(TIM4, &timerPWM);
//	
//  TIM_Cmd(TIM4, ENABLE);
//	
//	TIM4->CCR1 = 0;
//	TIM4->CCR2 = 0;
//	TIM4->CCR3 = 0;
//	TIM4->CCR4 = 0;	
//}


/*For Counters*/
//void ConfigureTIM123()
//{



////	
////	TIM_TimeBaseStructInit(&timer);
////	timer.TIM_Prescaler = 7200;
////	timer.TIM_Period = 65000;
////	timer.TIM_ClockDivision = 0;
////	timer.TIM_CounterMode = TIM_CounterMode_Up;
////	
//	
//	TIM1->PSC = 7200;
//	TIM2->PSC = 20000;
//	TIM3->PSC = 20000;
//	
//	//TIM_TimeBaseInit(TIM1, &timer);
//  TIM_Cmd(TIM1, ENABLE);
//	
//	
//	//TIM_TimeBaseInit(TIM2, &timer);
//  TIM_Cmd(TIM2, ENABLE);
//	
//	
//	//TIM_TimeBaseInit(TIM3, &timer);
//  TIM_Cmd(TIM3, ENABLE);
//	
//	
//}




