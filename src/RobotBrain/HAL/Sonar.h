#ifndef __Sonar_IO
#define __Sonar_IO

#include "stm32f10x.h"


typedef struct 
{
  uint16_t Sonar1_Value;
  uint16_t Sonar2_Value;
  uint16_t Sonar3_Value;
  
}Sonar_t;
extern Sonar_t Sonar;



void Sonar_Initialize(void);


void Sonar1_Trigger(uint8_t State);
void Sonar2_Trigger(uint8_t State);
void Sonar3_Trigger(uint8_t State);


uint8_t Sonar1_Response(void);
uint8_t Sonar2_Response(void);
uint8_t Sonar3_Response(void);


#endif
