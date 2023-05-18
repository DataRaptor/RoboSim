#include "SmartCat.h"


Line_t IRArray_Line;
IRarray_t IRArray = { .Threshold = {1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800, 1800},
                      .Confidence = {0,0,0,0,0,0,0,0,0,0},
                      .Data = {0,0,0,0,0,0,0,0,0,0},
                      .DataBuffer = {0,0,0,0,0,0,0,0,0,0},
                      .ConfThreshold = 10,
                      .HysteresisBandRange = 250,
                      .InvertData = 1,
                      
                      .Line.dt = 65535
                      };


         

int8 i = 0;
void IRArray_Update()
{
	
	/*Convert ADC Data to Binary Data*/
	/*------------------------------------------*/
	IRArray_ProcessData();
	
	
	
	/*Update Line Defination*/
	/*------------------------------------------*/
	IRArray_UpdateLineDefination();
	
	
	
	/*Update Line Exist*/
	/*------------------------------------------*/
	IRArray_UpdateSingleLineExist();
	
	
	
	/*Calculate Error*/
	/*------------------------------------------*/
	IRArray_CalculateError();
	
	
	
	/*Calculate dt*/
	/*------------------------------------------*/
	IRArray_Calculate_dt();
	
	
	
	/*Update Left Right Middle Flag Values*/
	/*------------------------------------------*/
	IRArray_UpdatePattern();
	

}






void IRArray_ProcessData()
{
	for(i = 0; i < 10; i++)
	{
		if(IRArray.ADCBuffer[i] > (IRArray.Threshold[i] + IRArray.HysteresisBandRange))
		{
			/*ADC Value is above threshold*/
			
			if(IRArray.DataBuffer[i] == 0)
			{
				/*ADC Value is High but Line.Data[i] value is 0*/
				IRArray.Confidence[i]++;		//Increase Confidance for 1
				
				if(IRArray.Confidence[i] > IRArray.ConfThreshold)
				{
					IRArray.DataBuffer[i] = 1;
					IRArray.Confidence[i] = 0;
				}
			}
			else
			{
				/*ADC Value is High  and  Line.Data[i] value is also 1*/
				
				IRArray.Confidence[i] = 0;
			}
		}
		else if(IRArray.ADCBuffer[i] < (IRArray.Threshold[i] - IRArray.HysteresisBandRange))
		{
			/*ADC value is below threshold*/
			
			if(IRArray.DataBuffer[i] == 0)
			{
				/*ADC Value is Low  and  Line.Data[i] value is also 0*/
				
				IRArray.Confidence[i] = 0;
			}
			else
			{
				/*ADC Value is Low  but  Line.Data[i] value is 1*/
				
				IRArray.Confidence[i]++;		//Increase Confidance for 0
				
				if(IRArray.Confidence[i] > IRArray.ConfThreshold)
				{
					IRArray.DataBuffer[i] = 0;
					IRArray.Confidence[i] = 0;
				}
			}
		}
		else
		{
			IRArray.Confidence[i] = 0;
		}
	}	
	
	
	/*Update Data from DataBuffer*/
	if(IRArray.InvertData == 1)
	{
		for(i = 0; i < 10; i++)
		{
			if(IRArray.DataBuffer[i] == 0)
				IRArray.Data[i] = 1;
			else
				IRArray.Data[i] = 0;
		}
	}
	else
	{
		for(i = 0; i < 10; i++)
		{
			IRArray.Data[i] = IRArray.DataBuffer[i];
		}
	}
}








void IRArray_UpdateLineDefination()
{
	IRArray.LeftIndex = -1;
	for(i = 0; i < 10; i++)
	{
		if(IRArray.Data[i] == 1)
		{
			IRArray.LeftIndex = i;
			break;
		}
	}
	
	IRArray.RightIndex = -1;
	for(i = 9; i >= 0; --i)
	{
		if(IRArray.Data[i] == 1)
		{
			IRArray.RightIndex = i;
			break;
		}
	}
	
	if(IRArray.LeftIndex == -1)
	{
		IRArray.Line.LineWidth = 0;
	}	
	else
	{
		IRArray.Line.LineWidth = IRArray.RightIndex - IRArray.LeftIndex + 1;
	}
}








uint8 lineexisttemp;
void IRArray_UpdateSingleLineExist()
{
	
	lineexisttemp = 1;
	
	if(IRArray.Line.LineWidth == 0)
		lineexisttemp = 0;
	else
	{
		for(i = IRArray.LeftIndex + 1; i < IRArray.RightIndex; i++)
		{
			if(IRArray.Data[i] == 0)
				lineexisttemp = 0;
		}
	}
	
	
	IRArray.Line.SingleLineExist = lineexisttemp;
}








uint8 RL, RR, LL, LR, tmp;






void IRArray_CalculateError()
{
	if(IRArray.Line.SingleLineExist == 1)
	{
		uint8 found = 0;
		uint8 LF = 0, RF = 0;
		
		/*LL*/
		tmp = 0;
		for(i = 0; i <= 4; i++)
		{
			if(IRArray.Data[i] == 1)
			{
				found = 1;
				LF = 1;
				break;
			}
			if(IRArray.Data[i] != 1)
			{
				tmp++;
			}
		}
		if(found != 1)
			LL = 0;
		else
			LL = tmp;
		
		

		/*LR*/
		found = 0;
		tmp = 0;
		for(i = 4; i >= 0; --i)
		{
			if(IRArray.Data[i] == 1)
			{
				found = 1;
				break;
			}
			if(IRArray.Data[i] != 1)
			{
				tmp++;
			}
		}
		if(found != 1)
			LR = 0;
		else
			LR = tmp;
		
		
		
		/*RL*/
		found = 0;
		tmp = 0;
		for(i = 5; i <= 9; i++)
		{
			if(IRArray.Data[i] == 1)
			{
				found = 1;
				RF = 1;
				break;
			}
			if(IRArray.Data[i] != 1)
			{
				tmp++;
			}
		}
		if(found != 1)
			RL = 0;
		else
			RL = tmp;
		
		
		
		
		/*RR*/
		found = 0;
		tmp = 0;
		for(i = 9; i >= 5; --i)
		{
			if(IRArray.Data[i] == 1)
			{
				found = 1;
				break;
			}
			if(IRArray.Data[i] != 1)
			{
				tmp++;
			}
		}
		if(found != 1)
			RR = 0;
		else
			RR = tmp;

		
		
		
		if(LF == 0 & RF == 0)
		{
			/*Do not update Error*/
		}
		else if(RF == 0)
		{
			IRArray.Line.Error = - (5 + LR - LL);
		}
		else if(LF == 0)
		{
			IRArray.Line.Error = (5 + RL - RR);
		}
		else
		{
			IRArray.Line.Error = (5 + RL - RR) - (5 + LR - LL);
		}
		
		
		
	}
}








int8 Last_LeftIndex = -125;
int8 Last_RightIndex = -125;

uint16 Left_dt = 65535;
uint16 Right_dt = 65535;


void IRArray_Calculate_dt()
{
//  if(IRArray.Line.SingleLineExist == 0)
//    goto END;
//		
//	if(Last_LeftIndex == -125)
//	{
//		Last_LeftIndex = IRArray.LeftIndex;
//		TIM2_SetCounter();
//	}
//  
//  if(Last_RightIndex == -125)
//	{
//		Last_RightIndex = IRArray.RightIndex;
//		TIM3_SetCounter();
//	}
//  
//	
//	
//	if(Last_LeftIndex != IRArray.LeftIndex)
//	{	
//		Left_dt = TIM2_GetCounter();
//		TIM2_SetCounter();
//		
//    
//    
//    if(IRArray.Data[9] == 1)
//    {
//      IRArray.Line.dt = (Left_dt / 2);	
//    }
//    else
//    {
//      IRArray.Line.dt = (Left_dt / 4) + (Right_dt / 4);	
//    }
//    
//		
//		Last_LeftIndex = IRArray.LeftIndex;
//	}
//	
//	if(Last_RightIndex != IRArray.RightIndex)
//	{		
//		Right_dt = TIM3_GetCounter();
//		TIM3_SetCounter();
//		
//    
//    if(IRArray.Data[0] == 1)
//    {
//      IRArray.Line.dt = (Right_dt / 2);
//    }
//    else
//    {
//      IRArray.Line.dt = (Left_dt / 4) + (Right_dt / 4);	
//    }
//		
//			
//		Last_RightIndex = IRArray.RightIndex;
//	}		

//  
//  END:;

}









void IRArray_UpdatePattern()
{
	if(IRArray.Data[0] == 1 && IRArray.Data[1] == 1)
	{
		IRArray.Line.LL = 1;
	}
	else
	{
		IRArray.Line.LL = 0;
	}
	
	if(IRArray.Data[8] == 1 && IRArray.Data[9] == 1)
	{
		IRArray.Line.RR = 1;
	}
	else
	{
		IRArray.Line.RR = 0;
	}	

	
	
	
	if(IRArray.Data[1] == 0 || IRArray.Data[2] == 0 || IRArray.Data[3] == 0)
		IRArray.Line.LR = 0;
	else
		IRArray.Line.LR = 1;
	
	
	if(IRArray.Data[6] == 0 || IRArray.Data[7] == 0 || IRArray.Data[8] == 0)
		IRArray.Line.RL = 0;
	else
		IRArray.Line.RL = 1;
	
	
	if(IRArray.Data[4] == 1 || IRArray.Data[5] == 1)
		IRArray.Line.M = 1;
	else
		IRArray.Line.M = 0;
	

	

	
	
	IRArray.Line.AllZero = 1;
	IRArray.Line.AllOne = 1;
	for(i = 0; i < 10; i++)
	{
		if(IRArray.Data[i] == 1)
			IRArray.Line.AllZero = 0;
		else
			IRArray.Line.AllOne = 0;
	}
}




void Clear_Flags()
{
  Left_dt = 65535;
  Right_dt = 65535;
  
  IRArray.Line.dt = 65535;
  
  
  
}












//void IRARRAY::Calibrate()
//{
//	//Delay_1s(8);

//	
//	
//	/*Update lower threshold*/
//	for(i = 0; i < 10; i++)
//	{
//			LowerThreshold[i] = 4095;		
//	}
//	
//	/*Update higher threshold*/
//	for(i = 0; i < 10; i++)
//	{
//			HigherThreshold[i] = 0;		
//	}
//	
//	
//	
//	uint32_t CalibrateCounter = 0;
//	/*Run calibration*/
//	while(1)
//	{
//		for(i = 0; i < 10; i++)
//		{
//			if(ADCBuffer[i] < LowerThreshold[i])
//				LowerThreshold[i] = ADCBuffer[i];
//			else if(ADCBuffer[i] > HigherThreshold[i])
//				HigherThreshold[i] = ADCBuffer[i];
//		}
//		
//		
//		if(CalibrateCounter > 300000)
//		{
//			break;
//		}
//		else 
//		{
//			CalibrateCounter++;
//		}
//	}
//	

//	
//	
//	/*Calculate Threshold*/
//	for(i = 0; i < 10; i++)
//	{
//		Threshold[i] = LowerThreshold[i] / 2;
//		Threshold[i] += HigherThreshold[i] /2;
//	}
//	
//	

//	
//		
//	DoCalibrate = 0;
//	
//	
//	

//}




