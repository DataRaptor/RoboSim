#include "titanos.h"

Stopwatch_Data_t Stopwatch1_Data;
Stopwatch_Data_t Stopwatch2_Data;
Stopwatch_Data_t Stopwatch3_Data;
Stopwatch_Data_t Stopwatch4_Data;

Stopwatch_Data_t Stopwatch5_Data;
Stopwatch_Data_t Stopwatch6_Data;
Stopwatch_Data_t Stopwatch7_Data;
Stopwatch_Data_t Stopwatch8_Data;


TimeSpan CalculateEllipsedTime(uint16_t StartCNT, uint16_t Iteration, uint16_t EndCNT, uint16_t Period)
{
	if(StartCNT < EndCNT)
	{
		return (TimeSpan){ .Second = (Iteration), .Millisecond = (EndCNT - StartCNT) / (Period / 1000)};
	}
	else if(StartCNT > EndCNT)
	{
		return (TimeSpan){ .Second = (Iteration - 1), .Millisecond = (1000 - ((StartCNT - EndCNT) / (Period / 1000))) };
	}
	else 
	{
		return (TimeSpan){ .Second = Iteration, .Millisecond = 0};
	}
}

void Set_Stopwatch_StartData(Stopwatch_Data_t *StopwatchX_Data, uint16_t StartCount)
{
	StopwatchX_Data->Iteration = 0;
	StopwatchX_Data->Enabled = 1;
	StopwatchX_Data->StartCount = StartCount;
}

void Stopwatch_Start(Stopwatch_t StopwatchX)
{
	if(StopwatchX == Stopwatch1)
		Set_Stopwatch_StartData(&Stopwatch1_Data, TIM2->CNT);
	
	else if(StopwatchX == Stopwatch2)
		Set_Stopwatch_StartData(&Stopwatch2_Data, TIM2->CNT);
	
	else if(StopwatchX == Stopwatch3)
		Set_Stopwatch_StartData(&Stopwatch3_Data, TIM2->CNT);
	
	else if(StopwatchX == Stopwatch4)
		Set_Stopwatch_StartData(&Stopwatch4_Data, TIM2->CNT);
	
	
	//Stopwatch 5 - 8 Uses TIM3
	else if(StopwatchX == Stopwatch5)
		Set_Stopwatch_StartData(&Stopwatch5_Data, TIM3->CNT);
	
	else if(StopwatchX == Stopwatch6)
		Set_Stopwatch_StartData(&Stopwatch6_Data, TIM3->CNT);
	
	else if(StopwatchX == Stopwatch7)
		Set_Stopwatch_StartData(&Stopwatch7_Data, TIM3->CNT);
	
	else if(StopwatchX == Stopwatch8)
		Set_Stopwatch_StartData(&Stopwatch8_Data, TIM3->CNT);
}


/*void Stopwatch1_Resume()
{
	Stopwatch1_Data.Enabled = 1;
	Stopwatch1_Data.StartCount = TIM2->CNT;
}

void Stopwatch1_Pause()
{
	//Add ellipsed time to Stopwatch1_Data.EllipsedTime
	Stopwatch1_Data.Enabled = 0;
}*/


void Set_Stopwatch_StopData(Stopwatch_Data_t *StopwatchX_Data)
{
	StopwatchX_Data->Enabled = 0;
	StopwatchX_Data->StartCount = 0;
	StopwatchX_Data->Iteration = 0;
}

//void Stopwatch_Stop(Stopwatch_t StopwatchX)
//{
//	if(StopwatchX == Stopwatch1)
//		Set_Stopwatch_StopData(&Stopwatch1_Data);
//	
//	else if(StopwatchX == Stopwatch2)
//		Set_Stopwatch_StopData(&Stopwatch2_Data);
//	
//	else if(StopwatchX == Stopwatch3)
//		Set_Stopwatch_StopData(&Stopwatch3_Data);
//	
//	else if(StopwatchX == Stopwatch4)
//		Set_Stopwatch_StopData(&Stopwatch4_Data);
//	
//	
//	//Stopwatch 5 to Stopwatch 8 Use TIM3
//	else if(StopwatchX == Stopwatch5)
//		Set_Stopwatch_StopData(&Stopwatch5_Data);
//	
//	else if(StopwatchX == Stopwatch6)
//		Set_Stopwatch_StopData(&Stopwatch6_Data);
//	
//	else if(StopwatchX == Stopwatch7)
//		Set_Stopwatch_StopData(&Stopwatch7_Data);
//	
//	else if(StopwatchX == Stopwatch8)
//		Set_Stopwatch_StopData(&Stopwatch8_Data);

//}

TimeSpan Stopwatch_GetTime(Stopwatch_t StopwatchX)
{
	if(StopwatchX == Stopwatch1 && Stopwatch1_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch1_Data.StartCount, Stopwatch1_Data.Iteration, TIM2->CNT, TIM2_Period);
	
	else if(StopwatchX == Stopwatch2 && Stopwatch2_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch2_Data.StartCount, Stopwatch2_Data.Iteration, TIM2->CNT, TIM2_Period);
	
	else if(StopwatchX == Stopwatch3 && Stopwatch3_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch3_Data.StartCount, Stopwatch3_Data.Iteration, TIM2->CNT, TIM2_Period);
	
	else if(StopwatchX == Stopwatch4 && Stopwatch4_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch4_Data.StartCount, Stopwatch4_Data.Iteration, TIM2->CNT, TIM2_Period);
	
	
	//Stopwatch 5 - 8 Uses TIM3
	else if(StopwatchX == Stopwatch5 && Stopwatch5_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch5_Data.StartCount, Stopwatch5_Data.Iteration, TIM3->CNT, TIM3_Period);
	
	else if(StopwatchX == Stopwatch6 && Stopwatch6_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch6_Data.StartCount, Stopwatch6_Data.Iteration, TIM3->CNT, TIM3_Period);
	
	else if(StopwatchX == Stopwatch7 && Stopwatch7_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch7_Data.StartCount, Stopwatch7_Data.Iteration, TIM3->CNT, TIM3_Period);
	
	else if(StopwatchX == Stopwatch8 && Stopwatch8_Data.Enabled == 1)
		return CalculateEllipsedTime(Stopwatch8_Data.StartCount, Stopwatch8_Data.Iteration, TIM3->CNT, TIM3_Period);
	
	else 
		return (TimeSpan){ .Second = 0, .Millisecond = 0};
}

