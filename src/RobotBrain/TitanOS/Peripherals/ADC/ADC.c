#include "titanos.h"        


void ADC_PA0_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void ADC_PA1_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);	
}

void ADC_PA2_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void ADC_PA3_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void ADC_PA4_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void ADC_PA5_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void ADC_PA6_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void ADC_PA7_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);		
}

void ADC_PB0_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);		
}

void ADC_PB1_Init(void)
{
	if(blueberry32->ADC.Init != NULL)
		blueberry32->ADC.Init();
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);		
}



uint16_t ADC_PA0(void)
{
	return blueberry32->ADC.Buffer[0];
}

uint16_t ADC_PA1(void)
{
	return blueberry32->ADC.Buffer[1];
}

uint16_t ADC_PA2(void)
{
	return blueberry32->ADC.Buffer[2];
}

uint16_t ADC_PA3(void)
{
	return blueberry32->ADC.Buffer[3];
}

uint16_t ADC_PA4(void)
{
	return blueberry32->ADC.Buffer[4];
}

uint16_t ADC_PA5(void)
{
	return blueberry32->ADC.Buffer[5];
}

uint16_t ADC_PA6(void)
{
	return blueberry32->ADC.Buffer[6];
}

uint16_t ADC_PA7(void)
{
	return blueberry32->ADC.Buffer[7];
}

uint16_t ADC_PB0(void)
{
	return blueberry32->ADC.Buffer[8];
}

uint16_t ADC_PB1(void)
{
	return blueberry32->ADC.Buffer[9];
}







