#include "SmartCat.h"

#define UPDATE "update"
#define GET    "get"

void CheckSimulatorCommand(void)
{
	if(HeaderCmp(UPDATE, titanapi->Serial.ReceiveBuffer))
	{
		/*Update sensor value*/
		
		
	}
	else if(HeaderCmp(GET, titanapi->Serial.ReceiveBuffer))
	{
		/*Get Motor values*/
		
		
	}
}





















