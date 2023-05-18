#include "stm32f10x.h"        

void WaitForADCConversion()
{
	// Wait until conversion completion
  while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
}





volatile uint16_t ADCBuffer[2] = {0xAAAA, 0xAAAA};

void InitializeADC(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB, ENABLE);
  
  GPIO_InitTypeDef gpio;
  gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  
  
  gpio.GPIO_Pin = GPIO_Pin_5;
  gpio.GPIO_Speed =  GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &gpio);
  
  gpio.GPIO_Pin = GPIO_Pin_0;
  GPIO_Init(GPIOB, &gpio);
  
  
  
  
	ADC_InitTypeDef ADC_InitStructure;
	DMA_InitTypeDef DMA_InitStructure;

	RCC_ADCCLKConfig(RCC_PCLK2_Div2);
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1 , ENABLE );

	DMA_InitStructure.DMA_BufferSize = 2;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADCBuffer;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1 , ENABLE ) ;

	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_NbrOfChannel = 2;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_Init(ADC1, &ADC_InitStructure);
  
  ADC_ITConfig(ADC1, ADC_IT_EOC , ENABLE);
  
  
//  //Enable ADC conversion complete interrupt
//  NVIC_InitTypeDef NVIC_InitStructure;
//  //Enable DMA1 channel IRQ Channel */
//  NVIC_InitStructure.NVIC_IRQChannel = ADC1_2_IRQn;
//  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
//  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//  NVIC_Init(&NVIC_InitStructure);
  
  
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 1, ADC_SampleTime_13Cycles5);	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 2, ADC_SampleTime_13Cycles5);

	
	
	ADC_Cmd(ADC1 , ENABLE);
	ADC_DMACmd(ADC1 , ENABLE);
	ADC_ResetCalibration(ADC1);

	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);

	while(ADC_GetCalibrationStatus(ADC1));
	ADC_SoftwareStartConvCmd ( ADC1 , ENABLE ) ;
}



//uint16_t cont = 0;
//void ADC1_2_IRQHandler(void)
//{
//  if(ADC_GetITStatus(ADC1, ADC_IT_EOC) != RESET)
//  {
//    //ADCBuffer[0] = 5;
//    
//    cont++;
//    
//    ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);
//  }
//}


