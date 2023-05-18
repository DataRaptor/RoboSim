#include "blueberry.h"

void CheckforModules()
{
	if(HeaderCmp(BOOTLOADER))
	{
		CheckBootloaderCommand();
	}
	else if(HeaderCmp(CORE))
	{
		CheckCoreCommand();
	}
	else 
	{
		//Pass to OS
		if(api.USB.OnUSBDataReceived != NULL)
			api.USB.OnUSBDataReceived();
	}
}


