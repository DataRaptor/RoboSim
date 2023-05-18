#include "FLASH.h"
#include "stm32f10x.h"


void FLASH_Init(void) {
	/* Next commands may be used in SysClock initialization function
	   In this case using of FLASH_Init is not obligatorily */
	/* Enable Prefetch Buffer */
	FLASH_PrefetchBufferCmd( FLASH_PrefetchBuffer_Enable);
	/* Flash 2 wait state */
	FLASH_SetLatency( FLASH_Latency_2);
}


void FLASH_ReadSettings(uint32_t pageaddress, uint32_t dest, uint16_t size) {
	uint16_t words = size / 4;
	//Read settings
	uint32_t *source_addr = (uint32_t *)pageaddress;
	uint32_t *dest_addr = (void *)&dest;
	for (uint16_t i=0; i<words; i++) {
		*dest_addr = *(__IO uint32_t*)source_addr;
		source_addr++;
		dest_addr++;
	}
}


void FLASH_WriteSettings(uint32_t source, uint32_t pageaddress, uint16_t size) {
	uint16_t words = size / 4;
	FLASH_Unlock();
	FLASH_ErasePage(pageaddress);

	// Write settings
	uint32_t *source_addr = (void *)&source;
	uint32_t *dest_addr = (uint32_t *) pageaddress;
	for (uint16_t i=0; i<words; i++) {
		FLASH_ProgramWord((uint32_t)dest_addr, *source_addr);
		source_addr++;
		dest_addr++;
	}

	FLASH_Lock();
}



