#ifndef __HAL_MotorEncoder__HEADER__
#define __HAL_MotorEncoder__HEADER__

#include "SmartCat.h"

void Encoder_Init(void);


/*Left Right Speed count for speed measurement*/
extern uint16 lstcnt;
extern uint16 rstcnt;

typedef struct
{

  uint32 LStepCnt;
  uint32 RStepCnt;
  
  uint16 LSpeed;
  uint16 RSpeed;
  

  
  uint8 LTask_Complete;
  uint8 RTask_Complete;
  

}Encoder_t;

extern Encoder_t Encoder;


void Encoder_Update(void);








#endif
