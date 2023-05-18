#include "SmartCat.h"

#define SIMULATOR      "sim"
#define SENSOR_TEST    "senstest"
#define MANUAL_CONTROL "mancontrol"

void OnSerialDataReceived(void)
{
	if(HeaderCmp(SIMULATOR, titanapi->Serial.ReceiveBuffer))
	{
		CheckSimulatorCommand();
	}
	else if(HeaderCmp(MANUAL_CONTROL, titanapi->Serial.ReceiveBuffer))
	{
		CheckManualCommand();
	}
	else if(HeaderCmp(SENSOR_TEST, titanapi->Serial.ReceiveBuffer))
	{
		CheckSensorTestCommand();
	}
	else 
	{
		//Passing to Client Cat is not requires at this time
		
	}	
}




void InitializeAPI(void)
{
	titanapi->Serial.OnSerialDataReceived = OnSerialDataReceived;
	
	
	
	
	
	
	
	
	
}














