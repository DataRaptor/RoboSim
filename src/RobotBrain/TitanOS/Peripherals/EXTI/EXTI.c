#include "titanos.h"

void __EXTIx_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_X, uint8_t GPIO_PinSourceX, uint16_t EXTI_LineX, func RaisingCallBack, func FallingCallBack);


func EXTI0_RaisingCallback;
func EXTI1_RaisingCallback;
func EXTI2_RaisingCallback;
func EXTI3_RaisingCallback;
func EXTI4_RaisingCallback;
func EXTI5_RaisingCallback;
func EXTI6_RaisingCallback;
func EXTI7_RaisingCallback;
func EXTI8_RaisingCallback;
func EXTI9_RaisingCallback;
func EXTI10_RaisingCallback;
func EXTI11_RaisingCallback;
func EXTI12_RaisingCallback;
func EXTI13_RaisingCallback;
func EXTI14_RaisingCallback;
func EXTI15_RaisingCallback;

func EXTI0_FallingCallback;
func EXTI1_FallingCallback;
func EXTI2_FallingCallback;
func EXTI3_FallingCallback;
func EXTI4_FallingCallback;
func EXTI5_FallingCallback;
func EXTI6_FallingCallback;
func EXTI7_FallingCallback;
func EXTI8_FallingCallback;
func EXTI9_FallingCallback;
func EXTI10_FallingCallback;
func EXTI11_FallingCallback;
func EXTI12_FallingCallback;
func EXTI13_FallingCallback;
func EXTI14_FallingCallback;
func EXTI15_FallingCallback;


GPIO_TypeDef* EXTI0_Port;
GPIO_TypeDef* EXTI1_Port;
GPIO_TypeDef* EXTI2_Port;
GPIO_TypeDef* EXTI3_Port;
GPIO_TypeDef* EXTI4_Port;
GPIO_TypeDef* EXTI5_Port;
GPIO_TypeDef* EXTI6_Port;
GPIO_TypeDef* EXTI7_Port;
GPIO_TypeDef* EXTI8_Port;
GPIO_TypeDef* EXTI9_Port;
GPIO_TypeDef* EXTI10_Port;
GPIO_TypeDef* EXTI11_Port;
GPIO_TypeDef* EXTI12_Port;
GPIO_TypeDef* EXTI13_Port;
GPIO_TypeDef* EXTI14_Port;
GPIO_TypeDef* EXTI15_Port;


void DummyFunction(){ }


void EXTI_Initialize()
{
	/* Enable clock for AFIO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);


	
	/* Set priority */
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	/* Set sub priority */
//	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	/* Enable interrupt */
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	/* Add to NVIC */
	
	
	
	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;	
	NVIC_Init(&NVIC_InitStruct);
	
	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;	
	NVIC_Init(&NVIC_InitStruct);	
	
	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;	
	NVIC_Init(&NVIC_InitStruct);		
	
	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;	
	NVIC_Init(&NVIC_InitStruct);	
	
	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 4;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;	
	NVIC_Init(&NVIC_InitStruct);	

	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 5;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_Init(&NVIC_InitStruct);

	/* Add IRQ vector to NVIC */
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 6;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_Init(&NVIC_InitStruct);

}

void EXTI0_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line0) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI0_Port, GPIO_Pin_0) != 0) 
		{
			EXTI0_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI0_Port, GPIO_Pin_0) == 0) 
		{
			EXTI0_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line0);
	}  
}

void EXTI1_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line1) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI1_Port, GPIO_Pin_1) != 0) 
		{
			EXTI1_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI1_Port, GPIO_Pin_1) == 0) 
		{
			EXTI1_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line1);
	}  
}

void EXTI2_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line2) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI2_Port, GPIO_Pin_2) != 0) 
		{
			EXTI2_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI2_Port, GPIO_Pin_2) == 0) 
		{
			EXTI2_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line2);
	}  
}

void EXTI3_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line3) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI3_Port, GPIO_Pin_3) != 0) 
		{
			EXTI3_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI3_Port, GPIO_Pin_3) == 0) 
		{
			EXTI3_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line3);
	}  
}

void EXTI4_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line4) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI4_Port, GPIO_Pin_4) != 0) 
		{
			EXTI4_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI4_Port, GPIO_Pin_4) == 0) 
		{
			EXTI4_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line4);
	}  
}

void EXTI9_5_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line5) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI5_Port, GPIO_Pin_5) != 0) 
		{
			EXTI5_RaisingCallback();
		}
    
		// Falling
		if (GPIO_ReadInputDataBit(EXTI5_Port, GPIO_Pin_5) == 0) 
		{
			EXTI5_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line5);
	}  
	
	if (EXTI_GetITStatus(EXTI_Line6) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI6_Port, GPIO_Pin_6) != 0) 
		{
			EXTI6_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI6_Port, GPIO_Pin_6) == 0) 
		{
			EXTI6_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line6);
	}

	if (EXTI_GetITStatus(EXTI_Line7) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI7_Port, GPIO_Pin_7) != 0) 
		{
			EXTI7_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI7_Port, GPIO_Pin_7) == 0) 
		{
			EXTI7_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line7);
	}   
	
	if (EXTI_GetITStatus(EXTI_Line8) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI8_Port, GPIO_Pin_8) != 0) 
		{
			EXTI8_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI8_Port, GPIO_Pin_8) == 0) 
		{
			EXTI8_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line8);
	} 
	
	if (EXTI_GetITStatus(EXTI_Line9) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI9_Port, GPIO_Pin_9) != 0) 
		{
			EXTI9_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI9_Port, GPIO_Pin_9) == 0) 
		{
			EXTI9_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line9);
	} 
}

void EXTI15_10_IRQHandler(void)
{
  if (EXTI_GetITStatus(EXTI_Line10) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI10_Port, GPIO_Pin_10) != 0) 
		{
			EXTI10_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI10_Port, GPIO_Pin_10) == 0) 
		{
			EXTI10_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line10);
	}  
	
  if (EXTI_GetITStatus(EXTI_Line11) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI11_Port, GPIO_Pin_11) != 0) 
		{
			EXTI11_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI11_Port, GPIO_Pin_11) == 0) 
		{
			EXTI11_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line11);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line12) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI12_Port, GPIO_Pin_12) != 0) 
		{
			EXTI12_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI12_Port, GPIO_Pin_12) == 0) 
		{
			EXTI12_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line12);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line13) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI13_Port, GPIO_Pin_13) != 0) 
		{
			EXTI13_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI13_Port, GPIO_Pin_13) == 0) 
		{
			EXTI13_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line13);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line14) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI14_Port, GPIO_Pin_14) != 0) 
		{
			EXTI14_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI14_Port, GPIO_Pin_14) == 0) 
		{
			EXTI14_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line14);
	} 
	
  if (EXTI_GetITStatus(EXTI_Line15) != RESET) 
  {
    // Rising
		if (GPIO_ReadInputDataBit(EXTI15_Port, GPIO_Pin_15) != 0) 
		{
			EXTI15_RaisingCallback();
		}
    
    // Falling
		if (GPIO_ReadInputDataBit(EXTI15_Port, GPIO_Pin_15) == 0) 
		{
			EXTI15_FallingCallback();
		}
		
		/* Clear interrupt flag */
		EXTI_ClearITPendingBit(EXTI_Line15);
	} 
}





void Set_EXTI_Port_Clock(GPIO_TypeDef* PortX, GPIO_TypeDef* EXTIx_Port)
{
	if(PortX == GPIOA)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	}
	else if(PortX == GPIOB)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	}
	else if(PortX == GPIOC)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	}
	else if(PortX == GPIOD)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	}
	else if(PortX == GPIOE)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	}
	else if(PortX == GPIOF)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	}
}

void CheckNullFunction(func a, func b)
{
	if(a == NULL)
		a = DummyFunction;
	if(b == NULL)
		b = DummyFunction;
}



void EXTIx_Init(Port_t port, unsigned char Pin, func RaisingCallBack, func FallingCallBack)
{
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin_X;
	uint8_t GPIO_PinSourceX;
	uint16_t EXTI_LineX;
	
	
	if(port == PortA)
	{
		GPIOx = GPIOA;
	}
	else if(port == PortB)
	{
		GPIOx = GPIOB;
	}
	else if(port == PortC)
	{
		GPIOx = GPIOC;
	}
	else if(port == PortD)
	{
		GPIOx = GPIOD;
	}
	else if(port == PortE)
	{
		GPIOx = GPIOE;
	}
	else if(port == PortF)
	{
		GPIOx = GPIOF;
	}
	
	
	if(Pin == 0)
	{
		GPIO_Pin_X = GPIO_Pin_0;
		GPIO_PinSourceX = GPIO_PinSource0;
		EXTI_LineX = EXTI_Line0;
	}
	else if(Pin == 1)
	{
		GPIO_Pin_X = GPIO_Pin_1;
		GPIO_PinSourceX = GPIO_PinSource1;
		EXTI_LineX = EXTI_Line1;		
	}
	else if(Pin == 2)
	{
		GPIO_Pin_X = GPIO_Pin_2;
		GPIO_PinSourceX = GPIO_PinSource2;
		EXTI_LineX = EXTI_Line2;		
	}
	else if(Pin == 3)
	{
		GPIO_Pin_X = GPIO_Pin_3;
		GPIO_PinSourceX = GPIO_PinSource3;
		EXTI_LineX = EXTI_Line3;		
	}
	else if(Pin == 4)
	{
		GPIO_Pin_X = GPIO_Pin_4;
		GPIO_PinSourceX = GPIO_PinSource4;
		EXTI_LineX = EXTI_Line4;		
	}
	else if(Pin == 5)
	{
		GPIO_Pin_X = GPIO_Pin_5;
		GPIO_PinSourceX = GPIO_PinSource5;
		EXTI_LineX = EXTI_Line5;		
	}
	else if(Pin == 6)
	{
		GPIO_Pin_X = GPIO_Pin_6;
		GPIO_PinSourceX = GPIO_PinSource6;
		EXTI_LineX = EXTI_Line6;		
	}
	else if(Pin == 7)
	{
		GPIO_Pin_X = GPIO_Pin_7;
		GPIO_PinSourceX = GPIO_PinSource7;
		EXTI_LineX = EXTI_Line7;		
	}
	else if(Pin == 8)
	{
		GPIO_Pin_X = GPIO_Pin_8;
		GPIO_PinSourceX = GPIO_PinSource8;
		EXTI_LineX = EXTI_Line8;		
	}
	else if(Pin == 9)
	{
		GPIO_Pin_X = GPIO_Pin_9;
		GPIO_PinSourceX = GPIO_PinSource9;
		EXTI_LineX = EXTI_Line9;		
	}
	else if(Pin == 10)
	{
		GPIO_Pin_X = GPIO_Pin_10;
		GPIO_PinSourceX = GPIO_PinSource10;
		EXTI_LineX = EXTI_Line10;		
	}
	else if(Pin == 11)
	{
		GPIO_Pin_X = GPIO_Pin_11;
		GPIO_PinSourceX = GPIO_PinSource11;
		EXTI_LineX = EXTI_Line11;		
	}
	else if(Pin == 12)
	{
		GPIO_Pin_X = GPIO_Pin_12;
		GPIO_PinSourceX = GPIO_PinSource12;
		EXTI_LineX = EXTI_Line12;		
	}
	else if(Pin == 13)
	{
		GPIO_Pin_X = GPIO_Pin_13;
		GPIO_PinSourceX = GPIO_PinSource13;
		EXTI_LineX = EXTI_Line13;		
	}
	else if(Pin == 14)
	{
		GPIO_Pin_X = GPIO_Pin_14;
		GPIO_PinSourceX = GPIO_PinSource14;
		EXTI_LineX = EXTI_Line14;		
	}	
	else if(Pin == 15)
	{
		GPIO_Pin_X = GPIO_Pin_15;
		GPIO_PinSourceX = GPIO_PinSource15;
		EXTI_LineX = EXTI_Line15;		
	}	
	
	__EXTIx_Init(GPIOx, GPIO_Pin_X, GPIO_PinSourceX, EXTI_LineX, RaisingCallBack, FallingCallBack);
}


uint8_t EXTI_Initialized = 0;
void __EXTIx_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_X, uint8_t GPIO_PinSourceX, uint16_t EXTI_LineX, func RaisingCallBack, func FallingCallBack)
{
	if(EXTI_Initialized == 0)
	{
		EXTI_Initialize();
		EXTI_Initialized = 1;
	}
	
	
	
	if(EXTI_LineX == EXTI_Line0)
	{
		EXTI0_RaisingCallback = RaisingCallBack;
		EXTI0_FallingCallback = FallingCallBack;
		
		CheckNullFunction(EXTI0_RaisingCallback, EXTI0_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI0_Port);
		
		EXTI0_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line1)
	{
		EXTI1_RaisingCallback = RaisingCallBack;
		EXTI1_FallingCallback = FallingCallBack;		
		
		CheckNullFunction(EXTI1_RaisingCallback, EXTI1_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI1_Port);
		
		EXTI1_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line2)
	{
		EXTI2_RaisingCallback = RaisingCallBack;
		EXTI2_FallingCallback = FallingCallBack;		
		
		CheckNullFunction(EXTI2_RaisingCallback, EXTI2_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI2_Port);
		
		EXTI2_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line3)
	{
		EXTI3_RaisingCallback = RaisingCallBack;
		EXTI3_FallingCallback = FallingCallBack;	

		CheckNullFunction(EXTI3_RaisingCallback, EXTI3_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI3_Port);
		
		EXTI3_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line4)
	{
		EXTI4_RaisingCallback = RaisingCallBack;
		EXTI4_FallingCallback = FallingCallBack;	

		CheckNullFunction(EXTI4_RaisingCallback, EXTI4_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI4_Port);
		
		EXTI4_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line5)
	{
		EXTI5_RaisingCallback = RaisingCallBack;
		EXTI5_FallingCallback = FallingCallBack;	

		CheckNullFunction(EXTI5_RaisingCallback, EXTI5_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI5_Port);
		
		EXTI5_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line6)
	{
		EXTI6_RaisingCallback = RaisingCallBack;
		EXTI6_FallingCallback = FallingCallBack;	

		CheckNullFunction(EXTI6_RaisingCallback, EXTI6_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI6_Port);
		
		EXTI6_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line7)
	{
		EXTI7_RaisingCallback = RaisingCallBack;
		EXTI7_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI7_RaisingCallback, EXTI7_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI7_Port);
		
		EXTI7_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line8)
	{
		EXTI8_RaisingCallback = RaisingCallBack;
		EXTI8_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI8_RaisingCallback, EXTI8_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI8_Port);
		
		EXTI8_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line9)
	{
		EXTI9_RaisingCallback = RaisingCallBack;
		EXTI9_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI9_RaisingCallback, EXTI9_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI9_Port);
		
		EXTI9_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line10)
	{
		EXTI10_RaisingCallback = RaisingCallBack;
		EXTI10_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI10_RaisingCallback, EXTI10_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI10_Port);
		
		EXTI10_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line11)
	{
		EXTI11_RaisingCallback = RaisingCallBack;
		EXTI11_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI11_RaisingCallback, EXTI11_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI11_Port);
		
		EXTI11_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line12)
	{
		EXTI12_RaisingCallback = RaisingCallBack;
		EXTI12_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI12_RaisingCallback, EXTI12_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI12_Port);
		
		EXTI12_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line13)
	{
		EXTI13_RaisingCallback = RaisingCallBack;
		EXTI13_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI13_RaisingCallback, EXTI13_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI13_Port);
		
		EXTI13_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line14)
	{
		EXTI14_RaisingCallback = RaisingCallBack;
		EXTI14_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI14_RaisingCallback, EXTI14_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI14_Port);
		
		EXTI14_Port = GPIOx;
	}
	else if(EXTI_LineX == EXTI_Line15)
	{
		EXTI15_RaisingCallback = RaisingCallBack;
		EXTI15_FallingCallback = FallingCallBack;

		CheckNullFunction(EXTI15_RaisingCallback, EXTI15_FallingCallback);
		Set_EXTI_Port_Clock(GPIOx, EXTI15_Port);
		
		EXTI15_Port = GPIOx;
	}
	else 
		goto END;
	
	
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_X;
	
	if(GPIOx == GPIOA)
	{
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSourceX);
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
	else if(GPIOx == GPIOB)
	{
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSourceX);
		GPIO_Init(GPIOB, &GPIO_InitStructure);
	}
	else if(GPIOx == GPIOC)
	{
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSourceX);
		GPIO_Init(GPIOC, &GPIO_InitStructure);
	}
	else if(GPIOx == GPIOD)
	{
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSourceX);
		GPIO_Init(GPIOD, &GPIO_InitStructure);
	}
	else if(GPIOx == GPIOE)
	{
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSourceX);
		GPIO_Init(GPIOE, &GPIO_InitStructure);
	}
	else if(GPIOx == GPIOF)
	{
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOF, GPIO_PinSourceX);
		GPIO_Init(GPIOF, &GPIO_InitStructure);
	}
		
	EXTI_InitStruct.EXTI_Line = EXTI_LineX;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	
	END:;
}








