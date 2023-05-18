#include "ApiFunctions.h"
#include "USB.h"


void InitializeAPI(void)
{
	/*System API Initialization*/
	api.SYS.OnCoreClockReset = NULL;
	api.SYS.Reboot = NVIC_SystemReset;
	
	
	
	/*System Clock Functions*/
	api.SYS.SetClock_16Mhz  = SYSCLK_16Mhz;
	api.SYS.SetClock_24Mhz  = SYSCLK_24Mhz;
	api.SYS.SetClock_32Mhz  = SYSCLK_32Mhz;
	api.SYS.SetClock_40Mhz  = SYSCLK_40Mhz;
	api.SYS.SetClock_48Mhz  = SYSCLK_48Mhz;
	api.SYS.SetClock_56Mhz  = SYSCLK_56Mhz;
	api.SYS.SetClock_64Mhz  = SYSCLK_64Mhz;
	api.SYS.SetClock_72Mhz  = SYSCLK_72Mhz;
	api.SYS.SetClock_80Mhz  = SYSCLK_80Mhz;
	api.SYS.SetClock_88Mhz  = SYSCLK_88Mhz;
	api.SYS.SetClock_96Mhz  = SYSCLK_96Mhz;
	api.SYS.SetClock_104Mhz = SYSCLK_104Mhz;
	api.SYS.SetClock_112Mhz = SYSCLK_112Mhz;
	api.SYS.SetClock_120Mhz = SYSCLK_120Mhz;
	api.SYS.SetClock_128Mhz = SYSCLK_128Mhz;
	
	
	
	/*Initialize Interrupt*/
	api.IT.TIM1_IT.OnUpdate = NULL;
	api.IT.TIM1_IT.OnCCR1Trigger = NULL;
	api.IT.TIM1_IT.OnCCR2Trigger = NULL;
	api.IT.TIM1_IT.OnCCR3Trigger = NULL;
	api.IT.TIM1_IT.OnCCR4Trigger = NULL;
	
	api.IT.TIM2_IT.OnUpdate = NULL;
	api.IT.TIM2_IT.OnCCR1Trigger = NULL;
	api.IT.TIM2_IT.OnCCR2Trigger = NULL;
	api.IT.TIM2_IT.OnCCR3Trigger = NULL;
	api.IT.TIM2_IT.OnCCR4Trigger = NULL;
	
	api.IT.TIM3_IT.OnUpdate = NULL;
	api.IT.TIM3_IT.OnCCR1Trigger = NULL;
	api.IT.TIM3_IT.OnCCR2Trigger = NULL;
	api.IT.TIM3_IT.OnCCR3Trigger = NULL;
	api.IT.TIM3_IT.OnCCR4Trigger = NULL;

	api.IT.TIM4_IT.OnUpdate = NULL;
	api.IT.TIM4_IT.OnCCR1Trigger = NULL;
	api.IT.TIM4_IT.OnCCR2Trigger = NULL;
	api.IT.TIM4_IT.OnCCR3Trigger = NULL;
	api.IT.TIM4_IT.OnCCR4Trigger = NULL;
	
	
	
	/*Exti Interrupts*/
	api.IT.EXTI_IT.EXTI0_Callback = NULL;
	api.IT.EXTI_IT.EXTI1_Callback = NULL;
	api.IT.EXTI_IT.EXTI2_Callback = NULL;
	api.IT.EXTI_IT.EXTI3_Callback = NULL;
	api.IT.EXTI_IT.EXTI4_Callback = NULL;
	api.IT.EXTI_IT.EXTI5_Callback = NULL;
	api.IT.EXTI_IT.EXTI6_Callback = NULL;
	api.IT.EXTI_IT.EXTI7_Callback = NULL;
	api.IT.EXTI_IT.EXTI8_Callback = NULL;
	api.IT.EXTI_IT.EXTI9_Callback = NULL;
	api.IT.EXTI_IT.EXTI10_Callback = NULL;
	api.IT.EXTI_IT.EXTI11_Callback = NULL;
	api.IT.EXTI_IT.EXTI12_Callback = NULL;
	api.IT.EXTI_IT.EXTI13_Callback = NULL;
	api.IT.EXTI_IT.EXTI14_Callback = NULL;
	api.IT.EXTI_IT.EXTI15_Callback = NULL;

	
	
	/*USB API Initialization*/
	api.USB.SendBuffer = USB_SendBuffer;
	api.USB.ReceiveBuffer = USB_ReceiveBuffer;
	api.USB.SendData = USB_Send;
	api.USB.OnUSBDataReceived = NULL;
}





