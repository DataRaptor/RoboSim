#ifndef __COMPILER__HEADER__
#define __COMPILER__HEADER__

#include "Syntax.h"
#include "Instructions.h"




enum Junctions
{
	_0101010 = 1,
	_0111010 = 2,
	_0001010 = 3,
	_0100000 = 4
};

enum Action
{
	_010 = 5,
	_001 = 6,
	_100 = 7
};


extern var P0, P1, P2, P3, P4, P5, P6, P7, P8, P9;
extern var A0, A1, A2, A3, A4, A5, A6, A7, A8, A9;
extern var F0, F1, F2, F3, F4, F5, F6, F7, F8, F9;
extern var L0, L1;




class ACTION_t
{
	public:
		
	ACTION_t operator [] (int i)
	{
		ACTION_t newaction;
		return newaction;
	}	
};


class PATH_t : InstructionBase
{
	public:
	
	PATH_t operator  | (int a)
	{
		PATH_t newpath;
		
		return newpath;
	}
	PATH_t operator ^ (int input)
	{
		PATH_t newpath;
		
		return newpath;
	}
};




//typedef void (*func)(void);



class Program
{
	public:


	
	PATH_t PATH;
	
	ACTION_t ACTION;
	COMP_t COMP;
	LOAD_t LOAD;
	INCR_t INCR;
	DECR_t DECR;
	ASIN_t ASIN;
	CALL_t CALL;
	int ENDA;
	
	
	public:
	virtual void Code()
	{ }
	
};















#endif
