#ifndef __Buzzer_IO
#define __Buzzer_IO

#include "stm32f10x.h"


void Buzzer_Beep(uint16_t BeepDuration, uint16_t Frequency);
void Buzzer_Beep_430(void);
void Buzzer_Beep_470(void);
void Buzzer_Beep_500(void);
void Buzzer_Beep_530(void);
void Buzzer_Beep_540(void);
void Buzzer_Beep_2300(void);	



#endif
