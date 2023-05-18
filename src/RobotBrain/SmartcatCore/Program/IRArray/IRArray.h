#ifndef __IRArrayModule
#define __IRArrayModule

#include "SmartCat.h"
                 
void Clear_Flags(void);



typedef struct 
{
	uint8 LineWidth;
  
	int8 Error;
  
	uint16 dt;
	
	uint8 SingleLineExist;
	
	
	uint8 LL, LR;
	uint8 M;
	uint8 RL, RR;
	
	uint8 AllZero;
	uint8 AllOne;
  
}Line_t;




typedef struct
{
  volatile uint16 ADCBuffer[10];
  
  uint16 Confidence[10];
  uint16 ConfThreshold;
	
  uint16 LowerThreshold[10];
  uint16 HigherThreshold[10];
  uint16 Threshold[10];
    
  uint8 Data[10];
  uint8 DataBuffer[10];
  uint16 HysteresisBandRange;

  uint8 InvertData;
  
  
  Line_t Line;
  
  
  int8 LeftIndex;
	int8 RightIndex;
  
}IRarray_t;
extern IRarray_t IRArray;






void IRArray_Update(void);
void IRArray_ProcessData(void);
void IRArray_UpdateLineDefination(void);
void IRArray_UpdateSingleLineExist(void);
void IRArray_CalculateError(void);
void IRArray_Calculate_dt(void);
void IRArray_UpdatePattern(void);







#endif
