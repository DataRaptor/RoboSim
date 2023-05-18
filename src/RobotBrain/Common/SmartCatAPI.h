#ifndef __SMARTCAT_API_HEADER__
#define __SMARTCAT_API_HEADER__

#include "TitanAPI.h"

typedef struct
{
	float Kp;
	float Kd;
	float Ki;
	
} Controller_t;


typedef struct
{
	Controller_t Speed;
	Controller_t Motion;
	Controller_t WallFollow;
	Controller_t Cave;
	
} ControllerCollection;

typedef enum
{
	Analog
} SensorType_t;

typedef struct
{
	uint8 SensorCount;
	SensorType_t SensorType;
	
} LineSensor_t;


typedef struct
{
	LineSensor_t         LineSensor;
	ControllerCollection Controllers;
	
	
} SmartCatInitTypedef;






typedef struct
{
	int8 ui;
	
} CatAPI;







#endif
