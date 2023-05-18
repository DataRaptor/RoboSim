#ifndef __STOPWATCH_KARNEL_HEADERS__
#define __STOPWATCH_KARNEL_HEADERS__
#include "titanos.h"


typedef struct 
{
	uint8_t  Enabled;
	uint16_t StartCount;
	uint16_t Iteration;
	
//	TimeSpan EllipsedTime;
	
} Stopwatch_Data_t;





extern Stopwatch_Data_t Stopwatch1_Data;
extern Stopwatch_Data_t Stopwatch2_Data;
extern Stopwatch_Data_t Stopwatch3_Data;
extern Stopwatch_Data_t Stopwatch4_Data;
extern Stopwatch_Data_t Stopwatch5_Data;
extern Stopwatch_Data_t Stopwatch6_Data;
extern Stopwatch_Data_t Stopwatch7_Data;
extern Stopwatch_Data_t Stopwatch8_Data;


void Stopwatch_Start(Stopwatch_t StopwatchX);
//void Stopwatch_Stop(Stopwatch_t StopwatchX);
TimeSpan Stopwatch_GetTime(Stopwatch_t StopwatchX);

#endif
