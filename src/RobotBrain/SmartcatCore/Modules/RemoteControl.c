#include "SmartCat.h"

#define UPDATE "update"

void CheckManualCommand(void)
{
	if(HeaderCmp(UPDATE, titanapi->Serial.ReceiveBuffer))
	{
		/*Update Motor Driver value*/
		
		
	}
}























