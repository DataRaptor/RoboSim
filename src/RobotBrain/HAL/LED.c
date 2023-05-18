#include "LED.h"

void LED_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
  GPIO_InitTypeDef gpio;
  gpio.GPIO_Mode = GPIO_Mode_Out_PP;
  gpio.GPIO_Speed = GPIO_Speed_50MHz;
  
  
  gpio.GPIO_Pin = GPIO_Pin_4;
  GPIO_Init(GPIOA, &gpio);
  
  gpio.GPIO_Pin = GPIO_Pin_5;
  GPIO_Init(GPIOA, &gpio);

  gpio.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOA, &gpio);

  gpio.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOA, &gpio);  
}





void LED1_Toggle(void)
{
  GPIOA->ODR ^= GPIO_Pin_4;
}

void LED2_Toggle(void)
{
  GPIOA->ODR ^= GPIO_Pin_5;
}

void LED3_Toggle(void)
{
  GPIOA->ODR ^= GPIO_Pin_6;
}

void LED4_Toggle(void)
{
  GPIOA->ODR ^= GPIO_Pin_7;
}



void LED1(uint8_t state)
{
  if(state == 0)
    GPIOA->BSRR |= GPIO_BSRR_BR4;
  else
    GPIOA->BSRR |= GPIO_BSRR_BS4;
}

void LED2(uint8_t state)
{
  if(state == 0)
    GPIOA->BSRR |= GPIO_BSRR_BR5;
  else
    GPIOA->BSRR |= GPIO_BSRR_BS5;  
}

void LED3(uint8_t state)
{
  if(state == 0)
    GPIOA->BSRR |= GPIO_BSRR_BR6;
  else
    GPIOA->BSRR |= GPIO_BSRR_BS6;   
}

void LED4(uint8_t state)
{
  if(state == 0)
    GPIOA->BSRR |= GPIO_BSRR_BR7;
  else
    GPIOA->BSRR |= GPIO_BSRR_BS7;   
}













