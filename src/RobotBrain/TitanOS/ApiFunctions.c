#include "ApiFunctions.h"
#include "titanos.h"


void OnUSBDataRecieved(void)
{
	titanapi.Serial.ReceiveBuffer = blueberry32->USB.ReceiveBuffer;
	titanapi.Serial.ReceivedLength = blueberry32->USB.ReceivedLength;
	
	if(titanapi.Serial.OnSerialDataReceived != NULL)
		titanapi.Serial.OnSerialDataReceived();
}

void OnWirelessDataReceived(void)
{
//	titanapi.Serial.ReceiveBuffer = /*buffer*/;
//	titanapi.Serial.ReceivedLength = /*buffer length*/;
//	
//	if(titanapi.Serial.OnSerialDataReceived != NULL)
//		titanapi.Serial.OnSerialDataReceived();	
}

void Serial_Send()
{
	/*Send Data through USB*/
	
	
	/*Send Same Data Through Wireless if Configured*/
}


void InitializeAPI(void)
{
	/*Notify TitanOs when command recieved*/
	blueberry32->USB.OnUSBDataReceived = OnUSBDataRecieved;
	
	
	blueberry32->IT.TIM2_IT.OnUpdate = TIM2_OnUpdate;
	blueberry32->IT.TIM2_IT.OnCCR1Trigger = TIM2_CCR1_Trigger;
	blueberry32->IT.TIM2_IT.OnCCR2Trigger = TIM2_CCR2_Trigger;
	blueberry32->IT.TIM2_IT.OnCCR3Trigger = TIM2_CCR3_Trigger;
	blueberry32->IT.TIM2_IT.OnCCR4Trigger = TIM2_CCR4_Trigger;
	
	blueberry32->IT.TIM3_IT.OnUpdate = TIM3_OnUpdate;
	blueberry32->IT.TIM3_IT.OnCCR1Trigger = TIM3_CCR1_Trigger;
	blueberry32->IT.TIM3_IT.OnCCR2Trigger = TIM3_CCR2_Trigger;
	blueberry32->IT.TIM3_IT.OnCCR3Trigger = TIM3_CCR3_Trigger;
	blueberry32->IT.TIM3_IT.OnCCR4Trigger = TIM3_CCR4_Trigger;
	
	titanapi.Events.Register = Event_Register;
	
	titanapi.Stopwatch.Start = Stopwatch_Start;
	titanapi.Stopwatch.GetTime = Stopwatch_GetTime;
	
	
	/*USB & Serial Communication*/
	titanapi.Serial.SendData = Serial_Send;
	
	
	/*Board Support*/
	titanapi.BoardSupport.ToggleLED = ToggleLED;
	titanapi.BoardSupport.LED_ON = LED_ON;
	titanapi.BoardSupport.LED_OFF = LED_OFF;
}




