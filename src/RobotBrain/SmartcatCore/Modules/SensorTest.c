#include "SmartCat.h"

#define GET_SONAR "getsonar"
#define GET_IR    "getir"
#define GET_ENCODER "getencoder"

void CheckSensorTestCommand(void)
{
	if(HeaderCmp(GET_SONAR, titanapi->Serial.ReceiveBuffer))
	{
		/*Update sensor value*/
		
		
	}
	else if(HeaderCmp(GET_IR, titanapi->Serial.ReceiveBuffer))
	{
		/*Get Motor values*/
		
		
	}	
	else if(HeaderCmp(GET_ENCODER, titanapi->Serial.ReceiveBuffer))
	{
		/*Get Motor values*/
		
		
	}		
}


















