#include "LED.h"
#include "stm32f10x.h"
#include "Encoder.h"
#include "../HAL/ADC.h"
#include "MotorDriver.h"


uint16_t lstcnt = 0;
uint16_t rstcnt = 0;

Encoder_t Encoder = {
    .LStepCnt = 0,
    .RStepCnt = 0,
  
    .LSpeed = 0,
    .RSpeed = 0,

};



#define ConfThreshold 5
#define HysteresisBandRange 350

uint16_t Threshold[2] = {3400, 3400};

uint16_t Encoder_Data[2] = {0, 0};
uint16_t Last_Encoder_Data[2] = {0, 0};

uint16_t Confidence[2] = {0, 0};



void Encoder_Init(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);  
  
	TIM3->PSC = 72;
  TIM_Cmd(TIM3, ENABLE);
  
  
	TIM4->PSC = 72;
  TIM_Cmd(TIM4, ENABLE);
  
  
}


uint16_t Leftspeed = 0;
uint16_t Rightspeed = 0;


uint8_t i = 0;
void Encoder_Update(void)
{
	for(i = 0; i < 2; i++)
	{
		if(ADCBuffer[i] > (Threshold[i] + HysteresisBandRange))
		{
			/*ADC Value is above threshold*/
			
			if(Encoder_Data[i] == 0)
			{
				/*ADC Value is High but Line.Data[i] value is 0*/
				Confidence[i]++;		//Increase Confidance for 1
				
				if(Confidence[i] > ConfThreshold)
				{
					Encoder_Data[i] = 1;
					Confidence[i] = 0;
				}
			}
			else
			{
				/*ADC Value is High  and  Line.Data[i] value is also 1*/
				
				Confidence[i] = 0;
			}
		}
		else if(ADCBuffer[i] < (Threshold[i] - HysteresisBandRange))
		{
			/*ADC value is below threshold*/
			
			if(Encoder_Data[i] == 0)
			{
				/*ADC Value is Low  and  Line.Data[i] value is also 0*/
				
				Confidence[i] = 0;
			}
			else
			{
				/*ADC Value is Low  but  Line.Data[i] value is 1*/
				
				Confidence[i]++;		//Increase Confidance for 0
				
				if(Confidence[i] > ConfThreshold)
				{
					Encoder_Data[i] = 0;
					Confidence[i] = 0;
				}
			}
		}
		else
		{
			Confidence[i] = 0;
		}
	}	
	
	
  //For Left encoder
  if(Last_Encoder_Data[0] != Encoder_Data[0])
  {
    Encoder.LStepCnt++;
    lstcnt++;
    
    
    //Left Encoder 0
    if(Encoder_Data[0] == 1)
    {
      TIM_SetCounter(TIM3, 0);      
    }
    else
    {
      Leftspeed = TIM_GetCounter(TIM3) / 10;
      if(Leftspeed > 2300)
        Leftspeed = 2300;
      
      Encoder.LSpeed = 2300 - Leftspeed;
      
      
      Motor_Update_L();
    }
    
    Last_Encoder_Data[0] = Encoder_Data[0];
  }
  
  
  //For Right encoder
  if(Last_Encoder_Data[1] != Encoder_Data[1])
  {
    Encoder.RStepCnt++;
    rstcnt++;
    
    //Right Ecoder 1
    if(Encoder_Data[1] == 1)
    {
      TIM_SetCounter(TIM4, 0);
    }
    else
    {
      Rightspeed = TIM_GetCounter(TIM4) / 10;
      if(Rightspeed > 2300)
        Rightspeed = 2300;
      
      Encoder.RSpeed = 2300 - Rightspeed;
      
      
      Motor_Update_R();
    }  
    

    
    Last_Encoder_Data[1] = Encoder_Data[1];
  }
}











