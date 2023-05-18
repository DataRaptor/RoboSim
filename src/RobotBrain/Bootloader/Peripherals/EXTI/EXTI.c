#include "blueberry.h"


void EXTI0_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line0) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI0_Callback != NULL)
			api.IT.EXTI_IT.EXTI0_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line0);
	}  
}

void EXTI1_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line1) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI1_Callback != NULL)
			api.IT.EXTI_IT.EXTI1_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line1);
	}  
}

void EXTI2_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line2) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI2_Callback != NULL)
			api.IT.EXTI_IT.EXTI2_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line2);
	}  
}

void EXTI3_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line3) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI3_Callback != NULL)
			api.IT.EXTI_IT.EXTI3_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line3);
	}  
}

void EXTI4_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line4) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI4_Callback != NULL)
			api.IT.EXTI_IT.EXTI4_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line4);
	}  
}

void EXTI9_5_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI5_Callback != NULL)
			api.IT.EXTI_IT.EXTI5_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line5);
	}  
	
	if (EXTI_GetITStatus(EXTI_Line6) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI6_Callback != NULL)
			api.IT.EXTI_IT.EXTI6_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line6);
	}

	if (EXTI_GetITStatus(EXTI_Line7) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI7_Callback != NULL)
			api.IT.EXTI_IT.EXTI7_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line7);
	}   
	
	if (EXTI_GetITStatus(EXTI_Line8) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI8_Callback != NULL)
			api.IT.EXTI_IT.EXTI8_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line8);
	} 
	
	if (EXTI_GetITStatus(EXTI_Line9) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI9_Callback != NULL)
			api.IT.EXTI_IT.EXTI9_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line9);
	} 
}

void EXTI15_10_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line10) != RESET) 
  {
		if(api.IT.EXTI_IT.EXTI10_Callback != NULL)
			api.IT.EXTI_IT.EXTI10_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line10);
	}  
	
  if (EXTI_GetITStatus(EXTI_Line11) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI11_Callback != NULL)
			api.IT.EXTI_IT.EXTI11_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line11);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line12) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI12_Callback != NULL)
			api.IT.EXTI_IT.EXTI12_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line12);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line13) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI13_Callback != NULL)
			api.IT.EXTI_IT.EXTI13_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line13);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line14) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI14_Callback != NULL)
			api.IT.EXTI_IT.EXTI14_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line14);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line15) != RESET) 
  {
    if(api.IT.EXTI_IT.EXTI15_Callback != NULL)
			api.IT.EXTI_IT.EXTI15_Callback();
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line15);
	} 
}








