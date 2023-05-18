#include "stm32f10x.h"        




void TIM8_EventHandler_Initialize(void)
{

  
  
  
  
  
  
}



void TIM1_SetCounter()
{
	TIM_SetCounter(TIM1, 0);
}

uint16_t TIM1_GetCounter()
{
	return TIM_GetCounter(TIM1);
}




void TIM2_SetCounter()
{
	TIM_SetCounter(TIM2, 0);
}


uint16_t TIM2_GetCounter()
{
	return TIM_GetCounter(TIM2);
}




void TIM3_SetCounter()
{
	TIM_SetCounter(TIM3, 0);
}

uint16_t TIM3_GetCounter()
{
	return TIM_GetCounter(TIM3);
}




//uint16_t TIM1_Timers[255];

///*Max Range: */
//void TIM1_SetCounter(uint8_t CounterID)
//{
//	TIM1_Timers[CounterID] = TIM1->CNT;
//}

//uint16_t TIM1_GetCounter(uint8_t CounterID)
//{
//	uint8_t start = TIM1_Timers[CounterID];
//	uint16_t current = TIM1->CNT;
//	
//	if(start > current)
//	{
//		return (65535 - start - current);
//	}
//	else
//	{
//		return (current - start);
//	}
//}





//uint16_t TIM2_Timers[255];

///*Max Range: */
//void TIM2_SetCounter(uint8_t CounterID)
//{
//	TIM2_Timers[CounterID] = TIM2->CNT;
//}

//uint8_t start;
//uint16_t current;
//uint16_t TIM2_GetCounter(uint8_t CounterID)
//{
//	start = TIM2_Timers[CounterID];
//	current = TIM2->CNT;
//	
//	if(start > current)
//	{
//		return (65535 - start - current);
//	}
//	else
//	{
//		return (current - start);
//	}
//}





//uint16_t TIM3_Timers[255];

///*Max Range: */
//void TIM3_SetCounter(uint8_t CounterID)
//{
//	TIM3_Timers[CounterID] = TIM3->CNT;
//}

//uint16_t TIM3_GetCounter(uint8_t CounterID)
//{
//	uint8_t start = TIM3_Timers[CounterID];
//	uint16_t current = TIM3->CNT;
//	
//	if(start > current)
//	{
//		return (65535 - start - current);
//	}
//	else
//	{
//		return (current - start);
//	}
//}









