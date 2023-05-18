#ifndef __HAL_MotorEncoder
#define __HAL_MotorEncoder

#include "stm32f10x.h"


void Encoder_Init(void);


/*Left Right Speed count for speed measurement*/
extern uint16_t lstcnt;
extern uint16_t rstcnt;

typedef struct
{

  uint32_t LStepCnt;
  uint32_t RStepCnt;
  
  uint16_t LSpeed;
  uint16_t RSpeed;
  

  
  uint8_t LTask_Complete;
  uint8_t RTask_Complete;
  

}Encoder_t;

extern Encoder_t Encoder;


void Encoder_Update(void);








#endif
