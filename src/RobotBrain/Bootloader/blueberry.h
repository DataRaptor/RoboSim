#ifndef __BLUEBERRY_INLUDE_HEADER
#define __BLUEBERRY_INLUDE_HEADER

#include "stm32f10x.h"

#include "USB.h"
#include "Common.h"

#include "String.h"

#include "GPIO.h"
#include "FLASH.h"
#include "USART.h"
#include "SYSCLK.h"

#include "Protocol.h"
#include "RequestHandler.h"

#include "BootMod.h"
#include "CoreMod.h"

#include "ApiFunctions.h"


/*Bootloader Files*/
#include "AppLauncher.h"
#include "FirmwareUpdate.h"


#include "BlueberryAPI.h"
extern BlueberryAPI api;


#include "Settings.h"
#define  FLASH_Settings_PageAddress 0x8003400

#endif
