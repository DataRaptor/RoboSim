#include "blueberry.h"

void CheckBootloaderCommand(void)
{
	if(HeaderCmp(LOADOS))
	{
		//Load firmware
		
	}
	else if(HeaderCmp(RESET))
	{
		//Reset Core
		
	}
}





















