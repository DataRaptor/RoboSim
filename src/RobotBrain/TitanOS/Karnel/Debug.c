#include "titanos.h"


void Watch_Register(char varname[], uint32_t address, uint32_t size_t)
{
	/*This function will be called when GetWatchDef request is sent to the MCU*/
	
	
	
}

void Config_Register()
{
	
}


uint32_t testvar = 12;

void On_GetWatchDefReq()
{
	Watch_Register("testvar", (uint32_t)&testvar, sizeof(testvar));
	
	
}

void On_GetConfDefReq()
{
	
	
	
}

















