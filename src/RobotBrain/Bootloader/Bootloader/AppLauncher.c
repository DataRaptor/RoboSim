#include "AppLauncher.h"
#include "stm32f10x.h"

//#define NVIC_VectTab_FLASH      (0x00000000)
#define FLASH_DISK_START_ADDRESS  0x08004000

void RunApp(void)
{
	
//	SCB->VTOR = NVIC_VectTab_FLASH | (AP_START_SECTOR & (unsigned int)0x1FFFFF80);

//	void (*user_code_entry)(void);


//	// the jump to new vector table.
//	NVIC_SetVectorTable(NVIC_VectTab_FLASH, AP_START_SECTOR);
//	user_code_entry = (void (*)(void))((AP_START_SECTOR)+1);

//	// jumps to new position of vector class
//	user_code_entry();
	
	
//	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x4000);
//	
//	u32 appJumpAddress;
//	void (*GoToApp)();

//	//appJumpAddress = *((volatile u32*)((0x08004000) + 4));
//	GoToApp = (void (*)(void))((0x08004000)+1);
//	//SCB->VTOR = address;
//	
//	__set_MSP(*((volatile u32*) 0x08004000)); //stack pointer (to RAM) for USER app in this address
//	
//	GoToApp();
//	
	
	
//	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x4000);
//	
//	u32 appJumpAddress;
//	void (*GoToApp)();

//	appJumpAddress = *((volatile u32*)(0x08004000 + 4));
//	GoToApp = (void (*)())appJumpAddress;
//	//SCB->VTOR = address;
//	
//	//__set_MSP(*((volatile u32*) 0x04004000)); //stack pointer (to RAM) for USER app in this address
//	
//	GoToApp();
	
	
	
	u32 appJumpAddress;
	void (*GoToApp)(void);

	appJumpAddress = *((volatile u32*)(FLASH_DISK_START_ADDRESS + 4));
	GoToApp = (void (*)(void))appJumpAddress;
	__set_MSP(*((volatile u32*) FLASH_DISK_START_ADDRESS)); //stack pointer (to RAM) for USER app in this address
	GoToApp();
}

