#include "titanos.h"

/*TIM1: Controlling Servo*/
uint8_t TIM1_Initialized = 0;
void TIM1_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
	
	TIM_DeInit(TIM1);
	
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1600;
	TIM_TimeBaseInitStructure.TIM_Period = 7200;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
	
	TIM_Cmd(TIM1, ENABLE);
	
	
	TIM1_Initialized = 1;
}





//TIM2 for Delay and Stopwatch and Events
uint8_t TIM2_Initialized = 0;
uint16_t TIM2_Period = 0;
void TIM2_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	TIM_DeInit(TIM2);
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
	
	
	
	TIM_TimeBaseInitStructure.TIM_Prescaler = ((blueberry32->SYS.ClockSpeed) * 100);
	TIM_TimeBaseInitStructure.TIM_Period = 10000;
	TIM2_Period = 10000;
//	if(blueberry32->SYS.ClockSpeed <= 64)
//	{
//		TIM_TimeBaseInitStructure.TIM_Prescaler = ((blueberry32->SYS.ClockSpeed) * 1000);
//		TIM_TimeBaseInitStructure.TIM_Period = 1000;
//		TIM2_Period = 1000;
//	}
//	else
//	{
//		TIM_TimeBaseInitStructure.TIM_Prescaler = ((blueberry32->SYS.ClockSpeed) * 100);
//		TIM_TimeBaseInitStructure.TIM_Period = 10000;
//		TIM2_Period = 10000;
//	}
	
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_CC3, ENABLE);
	TIM_ITConfig(TIM2, TIM_IT_CC4, ENABLE);	
	
	
	NVIC_InitTypeDef nvic;
	/* Set priority */
	nvic.NVIC_IRQChannelPreemptionPriority = 0x00;
	/* Set sub priority */
	nvic.NVIC_IRQChannelSubPriority = 0x00;
	/* Enable interrupt */
	nvic.NVIC_IRQChannelCmd = ENABLE;
	/* Add to NVIC */
	nvic.NVIC_IRQChannel = TIM2_IRQn;	
	NVIC_Init(&nvic);
	
	
	
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//	TIM_DeInit(TIM2);
//	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 7200;
//	TIM_TimeBaseInitStructure.TIM_Period = 10000;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
//	TIM_Cmd(TIM2, ENABLE);
//	
//	
//	
//	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//	TIM_ITConfig(TIM2, TIM_IT_CC1, ENABLE);
//	TIM_ITConfig(TIM2, TIM_IT_CC2, ENABLE);
//	TIM_ITConfig(TIM2, TIM_IT_CC3, ENABLE);
//	TIM_ITConfig(TIM2, TIM_IT_CC4, ENABLE);	
//	
//	
//	NVIC_InitTypeDef nvic;
//	/* Set priority */
//	nvic.NVIC_IRQChannelPreemptionPriority = 0x01;
//	/* Set sub priority */
//	nvic.NVIC_IRQChannelSubPriority = 0x02;
//	/* Enable interrupt */
//	nvic.NVIC_IRQChannelCmd = ENABLE;
//	/* Add to NVIC */
//	nvic.NVIC_IRQChannel = TIM2_IRQn;	
//	NVIC_Init(&nvic);
//	
//	
	
	
	TIM2_Initialized = 1;
}





//TIM2 for Delay and Stopwatch and Events
uint8_t TIM3_Initialized = 0;
uint16_t TIM3_Period = 0;
void TIM3_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	TIM_DeInit(TIM3);
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
	
	
	
	
	TIM_TimeBaseInitStructure.TIM_Prescaler = ((blueberry32->SYS.ClockSpeed) * 100);
	TIM_TimeBaseInitStructure.TIM_Period = 10000;
	TIM3_Period = 10000;
//	if(blueberry32->SYS.ClockSpeed <= 64)
//	{
//		TIM_TimeBaseInitStructure.TIM_Prescaler = ((blueberry32->SYS.ClockSpeed) * 1000);
//		TIM_TimeBaseInitStructure.TIM_Period = 1000;
//		TIM3_Period = 1000;
//	}
//	else
//	{
//		TIM_TimeBaseInitStructure.TIM_Prescaler = ((blueberry32->SYS.ClockSpeed) * 100);
//		TIM_TimeBaseInitStructure.TIM_Period = 10000;
//		TIM3_Period = 10000;
//	}
	
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	TIM_Cmd(TIM3, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_CC1, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_CC2, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_CC3, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_CC4, ENABLE);
	
	/* Set priority */
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	/* Set sub priority */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
	/* Enable interrupt */
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	/* Add to NVIC */
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;	
	NVIC_Init(&NVIC_InitStruct);
	
	
	TIM3_Initialized = 1;
}






/*TIM4: For controllin speed of motor*/
uint8_t TIM4_Initialized = 0;
void TIM4_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	TIM_DeInit(TIM4);
	
	TIM_TimeBaseStructInit(&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInitStructure.TIM_Prescaler = 720;
	TIM_TimeBaseInitStructure.TIM_Period = 7200;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
	
	TIM_Cmd(TIM4, ENABLE);
	
	
	
	TIM4_Initialized = 1;
}








void CheckEventTimer(EventTimer_t EventTimerX, Timer_t *EventTimerX_Data)
{
	if(EventTimerX_Data->IterationLeft == 0)
	{
		if(EventTimerX_Data->Callback != NULL)
			EventTimerX_Data->Callback();
		
		if(EventTimerX_Data->RepeatForever == 1)
		{
			//Re Register the event;
			Event_Register(EventTimerX, EventTimerX_Data->Duraton, EventTimerX_Data->RepeatForever, EventTimerX_Data->Callback);
		}
		else
		{
			EventTimerX_Data->Enabled = 0;
		}
	}
}

void DecreaseIteration_EventTimer(Timer_t *EventTimerX_Data)
{
	if(EventTimerX_Data->Enabled == 1)
	{
		if(EventTimerX_Data->IterationLeft != 0)
		{
			EventTimerX_Data->IterationLeft--;
		}
	}	
}

void IncreaseIteration_Stopwatch(Stopwatch_Data_t *StopwatchX_Data)
{
	if(StopwatchX_Data->Enabled == 1)
	{
		StopwatchX_Data->Iteration++;
	}	
}





void TIM2_OnUpdate(void)
{
	DecreaseIteration_EventTimer(&EventTimer1_Data);
	DecreaseIteration_EventTimer(&EventTimer2_Data);
	DecreaseIteration_EventTimer(&EventTimer3_Data);
	DecreaseIteration_EventTimer(&EventTimer4_Data);
	
	
	/*Stopwatch 1-4*/
	IncreaseIteration_Stopwatch(&Stopwatch1_Data);
	IncreaseIteration_Stopwatch(&Stopwatch2_Data);
	IncreaseIteration_Stopwatch(&Stopwatch3_Data);
	IncreaseIteration_Stopwatch(&Stopwatch4_Data);
}

void TIM2_CCR1_Trigger(void)
{
	CheckEventTimer(EventTimer1, &EventTimer1_Data);
}

void TIM2_CCR2_Trigger(void)
{
	CheckEventTimer(EventTimer2, &EventTimer2_Data);
}

void TIM2_CCR3_Trigger(void)
{
	CheckEventTimer(EventTimer3, &EventTimer3_Data);
}

void TIM2_CCR4_Trigger(void)
{
	CheckEventTimer(EventTimer4, &EventTimer4_Data);
}





//void TIM2_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2, TIM_IT_Update))
//	{
//		
//		DecreaseIteration_EventTimer(&EventTimer1_Data);
//		DecreaseIteration_EventTimer(&EventTimer2_Data);
//		DecreaseIteration_EventTimer(&EventTimer3_Data);
//		DecreaseIteration_EventTimer(&EventTimer4_Data);
//		
//		
//		/*Stopwatch 1-4*/
//		IncreaseIteration_Stopwatch(&Stopwatch1_Data);
//		IncreaseIteration_Stopwatch(&Stopwatch2_Data);
//		IncreaseIteration_Stopwatch(&Stopwatch3_Data);
//		IncreaseIteration_Stopwatch(&Stopwatch4_Data);
//		
//		
//		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//	}
//	
//	
//	/*Channel 1*/
//	if(TIM_GetITStatus(TIM2, TIM_IT_CC1))
//	{
//		CheckEventTimer(EventTimer1, &EventTimer1_Data);
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
//	}
//	
//	/*Channel 2*/
//	if(TIM_GetITStatus(TIM2, TIM_IT_CC2))
//	{
//		CheckEventTimer(EventTimer2, &EventTimer2_Data);
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
//	}

//	/*Channel 3*/
//	if(TIM_GetITStatus(TIM2, TIM_IT_CC3))
//	{
//		CheckEventTimer(EventTimer3, &EventTimer3_Data);
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);
//	}	
//	
//	/*Channel 4*/
//	if(TIM_GetITStatus(TIM2, TIM_IT_CC4))
//	{
//		CheckEventTimer(EventTimer4, &EventTimer4_Data);
//		TIM_ClearITPendingBit(TIM2, TIM_IT_CC4);
//	}
//}



void TIM3_OnUpdate(void)
{
	DecreaseIteration_EventTimer(&EventTimer5_Data);
	DecreaseIteration_EventTimer(&EventTimer6_Data);
	DecreaseIteration_EventTimer(&EventTimer7_Data);
	DecreaseIteration_EventTimer(&EventTimer8_Data);
	
	
	/*Stopwatch 5-8*/
	IncreaseIteration_Stopwatch(&Stopwatch5_Data);
	IncreaseIteration_Stopwatch(&Stopwatch6_Data);
	IncreaseIteration_Stopwatch(&Stopwatch7_Data);
	IncreaseIteration_Stopwatch(&Stopwatch8_Data);	
}

void TIM3_CCR1_Trigger(void)
{
	CheckEventTimer(EventTimer5, &EventTimer5_Data);
}

void TIM3_CCR2_Trigger(void)
{
	CheckEventTimer(EventTimer6, &EventTimer6_Data);
}

void TIM3_CCR3_Trigger(void)
{
	CheckEventTimer(EventTimer7, &EventTimer7_Data);
}

void TIM3_CCR4_Trigger(void)
{
	CheckEventTimer(EventTimer8, &EventTimer8_Data);
}



//void TIM3_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM3, TIM_IT_Update))
//	{
//		
//		DecreaseIteration_EventTimer(&EventTimer5_Data);
//		DecreaseIteration_EventTimer(&EventTimer6_Data);
//		DecreaseIteration_EventTimer(&EventTimer7_Data);
//		DecreaseIteration_EventTimer(&EventTimer8_Data);
//		
//		
//		/*Stopwatch 5-8*/
//		IncreaseIteration_Stopwatch(&Stopwatch5_Data);
//		IncreaseIteration_Stopwatch(&Stopwatch6_Data);
//		IncreaseIteration_Stopwatch(&Stopwatch7_Data);
//		IncreaseIteration_Stopwatch(&Stopwatch8_Data);
//		
//		
//		
//		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
//	}	
//	
//	/*Channel 1*/
//	if(TIM_GetITStatus(TIM3, TIM_IT_CC1))
//	{
//		CheckEventTimer(EventTimer5, &EventTimer5_Data);
//		TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
//	}
//	
//	/*Channel 2*/
//	if(TIM_GetITStatus(TIM3, TIM_IT_CC2))
//	{
//		CheckEventTimer(EventTimer6, &EventTimer6_Data);
//		TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
//	}

//	/*Channel 3*/
//	if(TIM_GetITStatus(TIM3, TIM_IT_CC3))
//	{
//		CheckEventTimer(EventTimer7, &EventTimer7_Data);
//		TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);
//	}	
//	
//	/*Channel 4*/
//	if(TIM_GetITStatus(TIM3, TIM_IT_CC4))
//	{
//		CheckEventTimer(EventTimer8, &EventTimer8_Data);
//		TIM_ClearITPendingBit(TIM3, TIM_IT_CC4);
//	}
//}




