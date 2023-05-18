#ifndef __Sonar_IO_HEADER__
#define __Sonar_IO_HEADER__

#include "SmartCat.h"

typedef struct 
{
  uint16 Sonar1_Value;
  uint16 Sonar2_Value;
  uint16 Sonar3_Value;
  
}Sonar_t;
extern Sonar_t Sonar;



void Sonar_Initialize(void);


void Sonar1_Trigger(uint8 State);
void Sonar2_Trigger(uint8 State);
void Sonar3_Trigger(uint8 State);


uint8 Sonar1_Response(void);
uint8 Sonar2_Response(void);
uint8 Sonar3_Response(void);


#endif
