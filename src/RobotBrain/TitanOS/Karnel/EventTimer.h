#ifndef __EVENTTIMER_KARNEL_HEADER__
#define __EVENTTIMER_KARNEL_HEADER__

#include "titanos.h"

typedef struct
{
	uint8_t  Enabled;
	uint16_t StartCount;
	uint16_t IterationTarget;
	uint16_t IterationLeft;
	TimeSpan Duraton;
	uint8_t  RepeatForever;
	func     Callback;
	
} Timer_t;




extern Timer_t EventTimer1_Data;
extern Timer_t EventTimer2_Data;
extern Timer_t EventTimer3_Data;
extern Timer_t EventTimer4_Data;
extern Timer_t EventTimer5_Data;
extern Timer_t EventTimer6_Data;
extern Timer_t EventTimer7_Data;
extern Timer_t EventTimer8_Data;


void Event_Register(EventTimer_t EventTimerX, TimeSpan Duration, uint8_t RepeatForever, func Callback);


#endif
