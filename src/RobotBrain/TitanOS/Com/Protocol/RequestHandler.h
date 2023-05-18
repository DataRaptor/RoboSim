#ifndef __KARNER_COMMANDS_HEADER__
#define __KARNER_COMMANDS_HEADER__

#include "stm32f10x.h"

#define WHORU       "*WHORU"
#define GET_TEMP    "*GETTEMP"
#define LOAD_PROG   "*LOADPROG"
#define LOAD_OS     "*LOADOS"
#define GET_FREQ    "*GETFREQ"
#define SET_FREQ    "*SETFREQ"
#define GET_CONF    "*GETCONF"
#define GET_WATCH   "*GETWATCH"
#define GET_VAL     "*GETVAL"
#define SET_VAL     "*SETVAL"
#define SAVE_CONFIG "*SAVECONFIG"



#define SUCCESS			"SUCCESS"
#define RBTNAME			"SMARTCAT"


void CheckModules(void);




#endif
