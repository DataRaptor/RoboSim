//#include "SmartCat.h"

//uint16_t sval = 0;
//uint16_t counts = 0;

//volatile uint8_t FLAG_ECHO = 0;


//uint16_t Sonar_GetValue(uint16_t input)
//{
//  uint16_t Sonar;
//	// 354000 - Sound speed (mm/sec)
//	// 72000000 - F_CPU
//	// 16 - Timer Prescaler
//	// Result = mm
//	Sonar = (354/2) * input / (72000 / 72);
//	if (Sonar > 4000) Sonar = 4000;
//	if (Sonar < 20) Sonar = 20;

//	return (uint16_t)Sonar;
//}


//Sonar_t Sonar = {
//    .Sonar1_Value = 0,
//    .Sonar2_Value = 0,
//    .Sonar3_Value = 0
//};



//void Sonar_Initialize(void)
//{
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
//  
//  
//  GPIO_InitTypeDef gpio;
//	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;

//	/*PC9*/
//	gpio.GPIO_Pin = GPIO_Pin_9;
//	GPIO_Init(GPIOC, &gpio);	
//	
//	/*PA11*/
//	gpio.GPIO_Pin = GPIO_Pin_11;
//	GPIO_Init(GPIOA, &gpio);
//	
//	/*PA12*/
//	gpio.GPIO_Pin = GPIO_Pin_12;
//	GPIO_Init(GPIOA, &gpio);	
//	
//	
//	
//  
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;
//	gpio.GPIO_Mode = GPIO_Mode_IPU;
//	
//	/*PA8*/
//	gpio.GPIO_Pin = GPIO_Pin_8;
//	GPIO_Init(GPIOA, &gpio);
//	
//	/*PA9*/
//	gpio.GPIO_Pin = GPIO_Pin_9;
//	GPIO_Init(GPIOA, &gpio);	

//	/*PA10*/
//	gpio.GPIO_Pin = GPIO_Pin_10;
//	GPIO_Init(GPIOA, &gpio);
//  





//  /*---------------------For measuring pulse width-------------------------*/
//  /* Timer TIM1 enable clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

//	/* Timer TIM1 settings */
//	TIM_TimeBaseInitTypeDef timer_base;
//	TIM_TimeBaseStructInit(&timer_base);
//	timer_base.TIM_CounterMode = TIM_CounterMode_Up;
//	timer_base.TIM_Prescaler = 72;
//	TIM_TimeBaseInit(TIM1, &timer_base);
//	TIM_Cmd(TIM1, ENABLE);





//  /*-----------------------For Triggering-------------------------*/
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
//  
//  TIM_TimeBaseInitTypeDef TIMER_InitStructure;
//  NVIC_InitTypeDef NVIC_InitStructure;
//  TIM_TimeBaseStructInit(&TIMER_InitStructure);
//  
//  TIMER_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//  TIMER_InitStructure.TIM_Prescaler = 7200;
//  TIMER_InitStructure.TIM_Period = 5000;
//  
//  
//  TIM_OCInitTypeDef  TIM_OCInitStructure;
//  TIM_OCStructInit (&TIM_OCInitStructure);
//  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Active;
//  TIM_OCInitStructure.TIM_Pulse = 130;
//  TIM_OC1Init (TIM2, &TIM_OCInitStructure);
//  
//  
//  TIM_TimeBaseInit(TIM2, &TIMER_InitStructure);
//  
//  TIM_ITConfig(TIM2, TIM_IT_Update | TIM_IT_CC1 , ENABLE);
//  
//  
//  TIM_Cmd(TIM2, ENABLE);
//  
//  
//  

//  /* NVIC Configuration */
//  /* Enable the TIM2_IRQn Interrupt */
//  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);



//  
//  /*--------------------EXTI----------------------------*/
//	/* Set variables used */
//  

//	EXTI_InitTypeDef EXTI_InitStruct;
//	NVIC_InitTypeDef NVIC_InitStruct;

//	/* Enable clock for AFIO */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);




//	/* Add IRQ vector to NVIC */
//	NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
//	/* Set priority */
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
//	/* Set sub priority */
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
//	/* Enable interrupt */
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
//	/* Add to NVIC */
//	NVIC_Init(&NVIC_InitStruct);


//	/* Add IRQ vector to NVIC */
//	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
//	/* Set priority */
//	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
//	/* Set sub priority */
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x01;
//	/* Enable interrupt */
//	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
//	/* Add to NVIC */
//	NVIC_Init(&NVIC_InitStruct);



//  /*Sonar 1-------------------------------------------*/
//	/* Tell system that you will use PA8 for EXTI_Line8 */
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
//  
//	/* PA8 is connected to EXTI_Line8 */
//	EXTI_InitStruct.EXTI_Line = EXTI_Line8;
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//	EXTI_Init(&EXTI_InitStruct);
//  
//  
//  
//  /*Sonar 2-------------------------------------------*/
//	/* Tell system that you will use PA10 for EXTI_Line10 */
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource10);
//  
//	/* PA10 is connected to EXTI_Line10 */
//	EXTI_InitStruct.EXTI_Line = EXTI_Line10;
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//	EXTI_Init(&EXTI_InitStruct);
//  
//  
//  
//  /*Sonar 3-------------------------------------------*/
//	/* Tell system that you will use PA9 for EXTI_Line9 */
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource9);
//  
//	/* PA9 is connected to EXTI_Line9 */
//	EXTI_InitStruct.EXTI_Line = EXTI_Line9;
//	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
//	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
//	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//	EXTI_Init(&EXTI_InitStruct);
//}




//uint16_t Sonar1_StartedAt = 0;
//uint16_t Sonar2_StartedAt = 0;
//uint16_t Sonar3_StartedAt = 0;



//void EXTI15_10_IRQHandler(void)
//{
//  /*Sonar2--------------------------------------*/
//  if (EXTI_GetITStatus(EXTI_Line10) != RESET) 
//  {
//    // Rising
//		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) != 0) 
//			Sonar2_StartedAt = TIM_GetCounter(TIM1);
//    
//    
//    // Falling
//		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 0) 
//			Sonar.Sonar2_Value = Sonar_GetValue(TIM_GetCounter(TIM1) - Sonar2_StartedAt);


//		/* Clear interrupt flag */
//		EXTI_ClearITPendingBit(EXTI_Line10);
//	}  
//}

//void EXTI9_5_IRQHandler(void) 
//{
//	/*Sonar1--------------------------------------*/
//	if (EXTI_GetITStatus(EXTI_Line8) != RESET) 
//  {
//    // Rising
//		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) != 0) 
//      Sonar1_StartedAt = TIM_GetCounter(TIM1);
//    
//    
//    // Falling
//		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == 0) 
//			Sonar.Sonar1_Value = Sonar_GetValue(TIM_GetCounter(TIM1) - Sonar1_StartedAt);
//		

//		/* Clear interrupt flag */
//		EXTI_ClearITPendingBit(EXTI_Line8);
//	}
//  
//  
//  
//  /*Sonar3--------------------------------------*/
//  if (EXTI_GetITStatus(EXTI_Line9) != RESET) 
//  {
//    // Rising
//		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) != 0) 
//			Sonar3_StartedAt = TIM_GetCounter(TIM1);
//    
//    
//    // Falling
//		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9) == 0) 
//			Sonar.Sonar3_Value = Sonar_GetValue(TIM_GetCounter(TIM1) - Sonar3_StartedAt);

//    
//		/* Clear interrupt flag */
//		EXTI_ClearITPendingBit(EXTI_Line9);
//	}
//}



//uint16_t RightCount = 0;

//void TIM2_IRQHandler(void)
//{
//  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//  {
//    LED4(1);
//    
//    //Trigger all Sonar Sensor
//    GPIOC->BSRR |= GPIO_BSRR_BS9;
//    GPIOA->BSRR |= GPIO_BSRR_BS11;	
//    GPIOA->BSRR |= GPIO_BSRR_BS12;
//    
//    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//    
//    
//    

//    //Check if Motor Speed is Zero
//    if(lstcnt == 0)
//      Encoder.LSpeed = 0;
//    
//    if(rstcnt == 0)
//      Encoder.RSpeed = 0;
//    
//    
//    lstcnt = 0;
//    rstcnt = 0; 
//    
//    
//    Motor_UpdateSpeed();
//  }
//  
//  
//  
//  if (TIM_GetITStatus (TIM2, TIM_IT_CC1) != RESET) 
//  {
//    GPIOC->BSRR |= GPIO_BSRR_BR9;
//    GPIOA->BSRR |= GPIO_BSRR_BR11;
//    GPIOA->BSRR |= GPIO_BSRR_BR12;
//    
//    LED4(0);
//    
//    FLAG_ECHO = 1;
//    
//    TIM_SetCounter(TIM1,0);
// 
//    TIM_ClearITPendingBit (TIM2, TIM_IT_CC1);
//  }
//}







//void Sonar1_Trigger(uint8_t State)
//{
//	if(State == 0)
//		GPIOC->BSRR |= GPIO_BSRR_BR9;
//	else
//		GPIOC->BSRR |= GPIO_BSRR_BS9;
//}

//void Sonar2_Trigger(uint8_t State)
//{
//	if(State == 0)
//		GPIOA->BSRR |= GPIO_BSRR_BR11;
//	else
//		GPIOA->BSRR |= GPIO_BSRR_BS11;	
//}

//void Sonar3_Trigger(uint8_t State)
//{

//	if(State == 0)
//		GPIOA->BSRR |= GPIO_BSRR_BR12;
//	else
//		GPIOA->BSRR |= GPIO_BSRR_BS12;	
//}




//uint8_t Sonar1_Response(void)
//{
//	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8);
//}

//uint8_t Sonar2_Response(void)
//{
//	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10);
//}

//uint8_t Sonar3_Response(void)
//{
//	return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9);
//}



















