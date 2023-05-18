#ifndef __EXTI_PEREPHERAL_HEADER
#define __EXTI_PEREPHERAL_HEADER

#include "titanos.h"


//void EXTIx_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin_X, uint8_t GPIO_PinSourceX, uint16_t EXTI_LineX, func RaisingCallBack, func FallingCallBack);


void EXTIx_Init(Port_t Port, uint8_t Pin, func RaisingCallBack, func FallingCallBack);





#endif
