#ifndef __FRAMEWORK_SERIAL_COM__
#define __FRAMEWORK_SERIAL_COM__

#include "stm32f10x.h"


typedef unsigned char byte;




typedef enum
{
	UploadProgram = 300,
	UploadOs      = 889,
	Reset         = 340,
	GetVariable   = 100,
	SetVariable   = 102,
	SaveConfig    = 104,
	GetWatchDef   = 600,
	GetConfigDef  = 602,
	Success       = 200,
	Error         = 500,
	Print         = 400,
	Forbidden     = 403,
	
} Header;



typedef struct 
{
	Header header;
	
	
} BufferStruc;







#endif
