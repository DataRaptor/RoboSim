#ifndef __HAL_USART
#define __HAL_USART

#include "stm32f10x.h"









void USART3_Init(void);


void USARTSend_String(char *pucBuffer);

void USARTSend_Data(char *pucBuffer, uint16_t size);






#endif
