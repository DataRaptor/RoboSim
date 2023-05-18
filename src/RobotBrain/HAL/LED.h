#ifndef __HAL_LED
#define __HAL_LED

#include "stm32f10x.h"


void LED_Init(void);


void LED1_Toggle(void);
void LED2_Toggle(void);
void LED3_Toggle(void);
void LED4_Toggle(void);


void LED1(uint8_t state);
void LED2(uint8_t state);
void LED3(uint8_t state);
void LED4(uint8_t state);

#endif
