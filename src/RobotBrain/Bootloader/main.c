#include "BlueberryAPI.h"
BlueberryAPI api;
#include "blueberry.h"

uint32_t adr;
int main()
{
	InitializeAPI();
	
	USB_Initialize(CheckforModules);
	
	/*Read Settings from flash*/
	FLASH_Init();
	Settings.CoreClock = 72;
	FLASH_WriteSettings((uint32_t)&Settings, FLASH_Settings_PageAddress, sizeof(Settings));
	FLASH_ReadSettings(FLASH_Settings_PageAddress, (uint32_t)&Settings, sizeof(Settings));
	
	
	
	adr = (uint32_t)&api;
	
	
	
	

	
	
	
	
	
	
	/*Jump to user program*/
	RunApp();
	
	
	
	while(1)
	{

	}
}

