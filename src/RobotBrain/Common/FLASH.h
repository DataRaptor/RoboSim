#ifndef __PERIPH_FLASH_CONFIG
#define __PERIPH_FLASH_CONFIG

#include "stm32f10x.h"


void FLASH_Init(void);
void FLASH_ReadSettings(uint32_t pageaddress, uint32_t dest, uint16_t size);
void FLASH_WriteSettings(uint32_t source, uint32_t pageaddress, uint16_t size);









#endif
