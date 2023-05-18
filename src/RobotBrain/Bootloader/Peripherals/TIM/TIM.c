#include "stm32f10x.h"
#include "blueberry.h"
#include "TIM.h"



void TIM1_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM1, TIM_IT_Update))
	{
		if(api.IT.TIM1_IT.OnUpdate != NULL)
			api.IT.TIM1_IT.OnUpdate();
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
	}
	
	
	/*Channel 1*/
	if(TIM_GetITStatus(TIM1, TIM_IT_CC1))
	{
		if(api.IT.TIM1_IT.OnCCR1Trigger != NULL)
			api.IT.TIM1_IT.OnCCR1Trigger();
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);
	}
	
	/*Channel 2*/
	if(TIM_GetITStatus(TIM1, TIM_IT_CC2))
	{
		if(api.IT.TIM1_IT.OnCCR2Trigger != NULL)
			api.IT.TIM1_IT.OnCCR2Trigger();
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_CC2);
	}

	/*Channel 3*/
	if(TIM_GetITStatus(TIM1, TIM_IT_CC3))
	{
		if(api.IT.TIM1_IT.OnCCR3Trigger != NULL)
			api.IT.TIM1_IT.OnCCR3Trigger();
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_CC3);
	}	
	
	/*Channel 4*/
	if(TIM_GetITStatus(TIM1, TIM_IT_CC4))
	{
		if(api.IT.TIM1_IT.OnCCR4Trigger != NULL)
			api.IT.TIM1_IT.OnCCR4Trigger();
		
		TIM_ClearITPendingBit(TIM1, TIM_IT_CC4);
	}
}





void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		if(api.IT.TIM2_IT.OnUpdate != NULL)
			api.IT.TIM2_IT.OnUpdate();
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
	
	
	/*Channel 1*/
	if(TIM_GetITStatus(TIM2, TIM_IT_CC1))
	{
		if(api.IT.TIM2_IT.OnCCR1Trigger != NULL)
			api.IT.TIM2_IT.OnCCR1Trigger();
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC1);
	}
	
	/*Channel 2*/
	if(TIM_GetITStatus(TIM2, TIM_IT_CC2))
	{
		if(api.IT.TIM2_IT.OnCCR2Trigger != NULL)
			api.IT.TIM2_IT.OnCCR2Trigger();
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC2);
	}

	/*Channel 3*/
	if(TIM_GetITStatus(TIM2, TIM_IT_CC3))
	{
		if(api.IT.TIM2_IT.OnCCR3Trigger != NULL)
			api.IT.TIM2_IT.OnCCR3Trigger();
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC3);
	}	
	
	/*Channel 4*/
	if(TIM_GetITStatus(TIM2, TIM_IT_CC4))
	{
		if(api.IT.TIM2_IT.OnCCR4Trigger != NULL)
			api.IT.TIM2_IT.OnCCR4Trigger();
		
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC4);
	}
}







void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update))
	{
		if(api.IT.TIM3_IT.OnUpdate != NULL)
			api.IT.TIM3_IT.OnUpdate();
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
	
	
	/*Channel 1*/
	if(TIM_GetITStatus(TIM3, TIM_IT_CC1))
	{
		if(api.IT.TIM3_IT.OnCCR1Trigger != NULL)
			api.IT.TIM3_IT.OnCCR1Trigger();
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC1);
	}
	
	/*Channel 2*/
	if(TIM_GetITStatus(TIM3, TIM_IT_CC2))
	{
		if(api.IT.TIM3_IT.OnCCR2Trigger != NULL)
			api.IT.TIM3_IT.OnCCR2Trigger();
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC2);
	}

	/*Channel 3*/
	if(TIM_GetITStatus(TIM3, TIM_IT_CC3))
	{
		if(api.IT.TIM3_IT.OnCCR3Trigger != NULL)
			api.IT.TIM3_IT.OnCCR3Trigger();
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC3);
	}	
	
	/*Channel 4*/
	if(TIM_GetITStatus(TIM3, TIM_IT_CC4))
	{
		if(api.IT.TIM3_IT.OnCCR4Trigger != NULL)
			api.IT.TIM3_IT.OnCCR4Trigger();
		
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC4);
	}
}








void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4, TIM_IT_Update))
	{
		if(api.IT.TIM4_IT.OnUpdate != NULL)
			api.IT.TIM4_IT.OnUpdate();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	}
	
	
	/*Channel 1*/
	if(TIM_GetITStatus(TIM4, TIM_IT_CC1))
	{
		if(api.IT.TIM4_IT.OnCCR1Trigger != NULL)
			api.IT.TIM4_IT.OnCCR1Trigger();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC1);
	}
	
	/*Channel 2*/
	if(TIM_GetITStatus(TIM4, TIM_IT_CC2))
	{
		if(api.IT.TIM4_IT.OnCCR2Trigger != NULL)
			api.IT.TIM4_IT.OnCCR2Trigger();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC2);
	}

	/*Channel 3*/
	if(TIM_GetITStatus(TIM4, TIM_IT_CC3))
	{
		if(api.IT.TIM4_IT.OnCCR3Trigger != NULL)
			api.IT.TIM4_IT.OnCCR3Trigger();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC3);
	}	
	
	/*Channel 4*/
	if(TIM_GetITStatus(TIM4, TIM_IT_CC4))
	{
		if(api.IT.TIM4_IT.OnCCR4Trigger != NULL)
			api.IT.TIM4_IT.OnCCR4Trigger();
		
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC4);
	}
}




