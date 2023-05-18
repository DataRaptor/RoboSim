#include "titanos.h"

Timer_t EventTimer1_Data;
Timer_t EventTimer2_Data;
Timer_t EventTimer3_Data;
Timer_t EventTimer4_Data;

Timer_t EventTimer5_Data;
Timer_t EventTimer6_Data;
Timer_t EventTimer7_Data;
Timer_t EventTimer8_Data;


void SetEventData(Timer_t *EventTimerX_Data, uint16_t iter, TimeSpan Duration, uint8_t RepeatForever, func Callback)
{
	EventTimerX_Data->IterationTarget = iter;
	EventTimerX_Data->IterationLeft   = iter;
	EventTimerX_Data->RepeatForever   = RepeatForever;
	EventTimerX_Data->StartCount 	    = TIM2->CNT;
	EventTimerX_Data->Callback 		    = Callback;
	EventTimerX_Data->Enabled				  = 1;
	EventTimerX_Data->Duraton				  = Duration;
}


void FilterDuration(TimeSpan *duration)
{
	if(duration->Millisecond >= 1000)
	{
		duration->Second += duration->Millisecond / 1000;
		duration->Millisecond = duration->Millisecond % 1000;
	}	
}

void CalculateTargetCNT(TimeSpan *duration, uint16_t *iter, uint16_t *tcnt, uint16_t CurrCNT, uint16_t Period)
{
	uint16_t s = 0;
	s = duration->Millisecond * (Period / 1000) + CurrCNT;
	if(s >= (1000 * (Period / 1000)))
	{
		*tcnt = s % (1000 * (Period / 1000));
		*iter += s / (1000 * (Period / 1000));
	}
	else
	{
		*tcnt = s;
	}	
}




void Event_Register(EventTimer_t EventTimerX, TimeSpan Duration, uint8 RepeatForever, func Callback)
{
	uint16_t iter = 0, tcnt = 0;
	
	FilterDuration(&Duration);
	
	iter = Duration.Second;
	
	
	
	/*TIM2*/
	if(EventTimerX == EventTimer1)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM2->CNT, TIM2_Period);
		SetEventData(&EventTimer1_Data, iter, Duration, RepeatForever, Callback);
		TIM2->CCR1 = tcnt;	
	}
	else if(EventTimerX == EventTimer2)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM2->CNT, TIM2_Period);
		SetEventData(&EventTimer2_Data, iter, Duration, RepeatForever, Callback);
		TIM2->CCR2 = tcnt;	
	}
	else if(EventTimerX == EventTimer3)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM2->CNT, TIM2_Period);
		SetEventData(&EventTimer3_Data, iter, Duration, RepeatForever, Callback);
		TIM2->CCR3 = tcnt;	
	}
	else if(EventTimerX == EventTimer4)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM2->CNT, TIM2_Period);
		SetEventData(&EventTimer4_Data, iter, Duration, RepeatForever, Callback);
		TIM2->CCR4 = tcnt;	
	}
	
	
	/*TIM3*/
	else if(EventTimerX == EventTimer5)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM3->CNT, TIM3_Period);
		SetEventData(&EventTimer5_Data, iter, Duration, RepeatForever, Callback);
		TIM3->CCR1 = tcnt;	
	}
	else if(EventTimerX == EventTimer6)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM3->CNT, TIM3_Period);
		SetEventData(&EventTimer6_Data, iter, Duration, RepeatForever, Callback);
		TIM3->CCR2 = tcnt;	
	}
	else if(EventTimerX == EventTimer7)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM3->CNT, TIM3_Period);
		SetEventData(&EventTimer7_Data, iter, Duration, RepeatForever, Callback);
		TIM3->CCR3 = tcnt;	
	}
	else if(EventTimerX == EventTimer8)
	{
		CalculateTargetCNT(&Duration, &iter, &tcnt, TIM3->CNT, TIM3_Period);
		SetEventData(&EventTimer8_Data, iter, Duration, RepeatForever, Callback);
		TIM3->CCR4 = tcnt;	
	}
}










