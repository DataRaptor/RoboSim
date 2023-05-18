#ifndef __HAL_MotorDriver
#define __HAL_MotorDriver

#include "stm32f10x.h"


typedef struct
{
  uint16_t L;
  uint16_t R;
} StepTarget_t;


typedef struct
{
  uint16_t L;
  uint16_t R;
} TaskActive_t;


typedef struct
{
  uint16_t L;
  uint16_t R;
} MaxSpeed_t;


typedef struct
{
  uint16_t L;
  uint16_t R;
} SpeedTarget_t;

typedef struct
{
  int8_t L;
  int8_t R;
} Direction_t;

typedef struct
{
  uint16_t L;
  uint16_t R;
} Power_t;



typedef struct
{
  StepTarget_t  StepTarget;
  TaskActive_t  TaskActive;
  MaxSpeed_t    MaxSpeed;
  SpeedTarget_t SpeedTarget;
  Power_t       Power;
  Direction_t   Direction;
  uint16_t      UpdatePrescaler;
  
} Motor_t;

extern Motor_t MotorDriver;






void Motor_Init(void);



void Motor_Update_L(void);
void Motor_Update_R(void);
void Motor_UpdateSpeed(void);





void Motor_LeftSpeed(uint16_t speed, int8_t dir);
void Motor_RightSpeed(uint16_t speed, int8_t dir);






#endif
