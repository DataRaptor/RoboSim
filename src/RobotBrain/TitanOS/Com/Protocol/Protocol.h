#ifndef __PROTOCOL_KARNER_HEADER__
#define __PROTOCOL_KARNER_HEADER__


#include "stm32f10x.h"



void Serial_SendData(char header[], void *data, uint8_t size);

void FillStruct(uint8_t startindex, void *strct, uint8_t size);

uint8_t HeaderCmp(char header[]);








#endif
