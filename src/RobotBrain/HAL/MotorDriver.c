#include "stm32f10x.h"
#include "MotorDriver.h"
#include "../System/Delay.h"
#include "Encoder.h"


#define PERIOD 1000

Motor_t MotorDriver = {
    .StepTarget  = {.L = 0, .R = 0 },
    .TaskActive  = {.L = 0, .R = 0 },
    .MaxSpeed    = {.L = 0, .R = 0 },
    .SpeedTarget = {.L = 0, .R = 0 },
    .Direction   = {.L = 0, .R = 0 },
};



void Motor_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  
  
  GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	
	gpio.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_2;
	GPIO_Init(GPIOA, &gpio);
	
	gpio.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOA, &gpio);
  
  
  
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
 
  TIM_TimeBaseInitTypeDef timer;
	TIM_OCInitTypeDef timerPWM;
	
	
	TIM_TimeBaseStructInit(&timer);
	timer.TIM_Prescaler = 72;
	timer.TIM_Period = PERIOD;
	timer.TIM_ClockDivision = 0;
	timer.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM5, &timer);

	TIM_OCStructInit(&timerPWM);
	timerPWM.TIM_Pulse = 0;
	timerPWM.TIM_OCMode = TIM_OCMode_PWM1;
	timerPWM.TIM_OutputState = TIM_OutputState_Enable;
	timerPWM.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM5, &timerPWM);
	TIM_OC2Init(TIM5, &timerPWM);
	TIM_OC3Init(TIM5, &timerPWM);
	TIM_OC4Init(TIM5, &timerPWM);
	
  TIM_Cmd(TIM5, ENABLE);
	
	TIM5->CCR1 = 0;
	TIM5->CCR2 = 0;
	TIM5->CCR3 = 0;
	TIM5->CCR4 = 0;	
}






int32_t L_LastError = 0;
int32_t R_LastError = 0;

uint16_t L_dt = 65000;
uint16_t R_dt = 65000;


int32_t L_Error = 0;
int32_t R_Error = 0;
int32_t B_Error = 0; //Balance error



uint16_t M_Kp = 10;
uint16_t M_Kd = 5;
uint16_t M_Ki = 0;

int32_t M_Intregral = 0;

uint16_t L_Power = 0;
uint16_t R_Power = 0;

uint8_t GoStraight_started = 0;

uint32_t L_LastStep = 0;
uint32_t R_LastStep = 0;



int32_t pid_val = 0;
int32_t de = 0;
uint16_t Motor_PID(uint16_t CurrentPower, int32_t error, int32_t lasterror, uint16_t dt)
{
  de = error - lasterror;
  M_Intregral += de;
  pid_val = error / M_Kp + (de * M_Kd) / dt;// +  M_Intregral / M_Ki;
  
  if(pid_val < 0)
  {
    if(CurrentPower < -pid_val)
      pid_val = -CurrentPower;
  }
  
  return (CurrentPower + pid_val);
}



uint8_t Executing_Motor_Update_L = 0;
void Motor_Update_L(void)
{
  if(Executing_Motor_Update_L == 1)
    goto END;  
  Executing_Motor_Update_L = 1;
  
  
  L_Power = MotorDriver.Power.L;
  
  //Calculate Error
  L_Error = (int32_t)(MotorDriver.SpeedTarget.L - Encoder.LSpeed);
  
  
  //Calculate dt
  L_dt = 100 / (Encoder.LStepCnt - L_LastStep);
  
  
  L_Power = Motor_PID(L_Power, L_Error, L_LastError, L_dt);
  
  
  if(L_Power > 1000)
    L_Power = 1000;
  
  
  Motor_LeftSpeed (L_Power, MotorDriver.Direction.L);
  
  MotorDriver.Power.L = L_Power;
  L_LastError = L_Error;
  L_LastStep = Encoder.LStepCnt;
  
  
  Executing_Motor_Update_L = 0;
  END:;
}


uint8_t Executing_Motor_Update_R = 0;
void Motor_Update_R(void)
{
  if(Executing_Motor_Update_R == 1)
    goto END;
  Executing_Motor_Update_R = 1;

  
  R_Power = MotorDriver.Power.R;
  
  //Calculate Error
  R_Error = (int32_t)(MotorDriver.SpeedTarget.R - Encoder.RSpeed);
  
  
  //Calculate dt
  R_dt = 100 / (Encoder.RStepCnt - R_LastStep);
  
  
  R_Power = Motor_PID(R_Power, R_Error, R_LastError, R_dt);
  
  
  if(R_Power > 1000)
    R_Power = 1000;
  
  
  Motor_RightSpeed (R_Power, MotorDriver.Direction.R);
  
  MotorDriver.Power.R = R_Power;
  R_LastError = R_Error;
  R_LastStep = Encoder.RStepCnt;
  
  
  Executing_Motor_Update_R = 0;
  END:;
}


uint32_t L_LastStep_B = 0;  //Starting Step Count no
uint32_t R_LastStep_B = 0;
void Motor_Adjust()
{
  B_Error = (int32_t)((uint32_t)(Encoder.RStepCnt - R_LastStep_B) - (uint32_t)(Encoder.LStepCnt - L_LastStep_B));
  /*If Positive Rotate Right*/
  
  pid_val = B_Error * M_Kp;
  
  
  L_Power = MotorDriver.Power.L;
  L_Power -= (-pid_val);
  if(L_Power > 1000)
    L_Power = 1000;
  Motor_LeftSpeed (L_Power, MotorDriver.Direction.L);
  MotorDriver.Power.L = L_Power;
  
  
  R_Power = MotorDriver.Power.R;
  R_Power += (-pid_val);
  if(R_Power > 1000)
    R_Power = 1000;
  Motor_LeftSpeed (R_Power, MotorDriver.Direction.R);
  MotorDriver.Power.R = R_Power;  
  
}

void Motor_UpdateSpeed(void)
{

  /*Update L R speed to meed the targeted speed*/
  Motor_Update_L();
  Motor_Update_R();
  
  
  /*Adjust L R Speed to go straignt*/
  if((MotorDriver.SpeedTarget.L == MotorDriver.SpeedTarget.R) && (GoStraight_started == 0))
  {
    GoStraight_started = 1;
    L_LastStep_B = Encoder.LStepCnt;
    R_LastStep_B = Encoder.RStepCnt;
  }
  else if(MotorDriver.SpeedTarget.L != MotorDriver.SpeedTarget.R)
  {
    GoStraight_started = 0;
  }
  
  
  if(GoStraight_started == 1)
  {
    Motor_Adjust();
  }
  
  
}







void Motor_LeftSpeed(uint16_t speed, int8_t dir)
{
	if(dir >= 0)
	{
		//Reset Backward Speed - VVI
		TIM5->CCR4 = 0;
		

		
		//Set Forward Speed;
		TIM5->CCR3 = speed;
	}
	else
	{
		//Reset Forward Speed - VVI
		TIM5->CCR3 = 0;
		
		
		//Set Backward Speed;
		TIM5->CCR4 = speed;
	}
}


void Motor_RightSpeed(uint16_t speed, int8_t dir)
{
	if(dir >= 0)
	{
		//Reset Backward Speed - VVI
		TIM5->CCR2 = 0;
		

		//Set Forward Speed;
		TIM5->CCR1 = speed;
	}
	else
	{
		//Reset Forward Speed - VVI
		TIM5->CCR1 = 0;
		
		
		//Set Backward Speed;
		TIM5->CCR2 = speed;
	}
}




