#include "AppLauncher.h"
#include "stm32f10x.h"


#define SMARTCAT_START_ADDRESS  0x08006000


void RunApp(void)
{
//	u32 appJumpAddress;
//	void (*GoToApp)();

//	appJumpAddress = *((volatile u32*)(address + 4));
//	GoToApp = (void (*)())appJumpAddress;
//	//SCB->VTOR = address;
//	__set_MSP(*((volatile u32*) address)); //stack pointer (to RAM) for USER app in this address
//	
//	GoToApp();
	
	u32 appJumpAddress;
	void (*GoToApp)(void);

	appJumpAddress = *((volatile u32*)(SMARTCAT_START_ADDRESS + 4));
	GoToApp = (void (*)(void))appJumpAddress;
	//__set_MSP(*((volatile u32*) SMARTCAT_START_ADDRESS)); //stack pointer (to RAM) for USER app in this address
	GoToApp();
}

