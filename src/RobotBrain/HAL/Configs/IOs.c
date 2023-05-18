#include "stm32f10x.h"
#include "IOs.h"


void ConfigureMotorPort()
{
//	GPIO_InitTypeDef gpio;
//	gpio.GPIO_Mode = GPIO_Mode_AF_PP;
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;
//	
//	gpio.GPIO_Pin = GPIO_Pin_6;
//	GPIO_Init(GPIOB, &gpio);
//	
//	gpio.GPIO_Pin = GPIO_Pin_7;
//	GPIO_Init(GPIOB, &gpio);
//	
//	gpio.GPIO_Pin = GPIO_Pin_8;
//	GPIO_Init(GPIOB, &gpio);
//	
//	gpio.GPIO_Pin = GPIO_Pin_9;
//	GPIO_Init(GPIOB, &gpio);
}


void ConfigureLED()
{
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
	gpio.GPIO_Speed = GPIO_Speed_50MHz;
	
	gpio.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(GPIOC, &gpio);
}




void ConfigureSonarPins()
{

//	GPIO_InitTypeDef gpio;
//	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;

//	/*B13*/
//	gpio.GPIO_Pin = GPIO_Pin_13;
//	GPIO_Init(GPIOB, &gpio);	
//	
//	/*B15*/
//	gpio.GPIO_Pin = GPIO_Pin_15;
//	GPIO_Init(GPIOB, &gpio);
//	
//	/*A9*/
//	gpio.GPIO_Pin = GPIO_Pin_9;
//	GPIO_Init(GPIOA, &gpio);	
//	
//	
//	
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;
//	gpio.GPIO_Mode = GPIO_Mode_IPD;
//	
//	/*B14*/
//	gpio.GPIO_Pin = GPIO_Pin_14;
//	GPIO_Init(GPIOB, &gpio);
//	
//	/*A8*/
//	gpio.GPIO_Pin = GPIO_Pin_8;
//	GPIO_Init(GPIOA, &gpio);	

//	/*A10*/
//	gpio.GPIO_Pin = GPIO_Pin_10;
//	GPIO_Init(GPIOA, &gpio);
	
	
}





void ConfigureBuzzerPort()
{
//	GPIO_InitTypeDef gpio;
//	gpio.GPIO_Mode = GPIO_Mode_Out_PP;
//	gpio.GPIO_Pin = GPIO_Pin_11;
//	gpio.GPIO_Speed = GPIO_Speed_50MHz;
//	
//	GPIO_Init(GPIOB, &gpio);
}



