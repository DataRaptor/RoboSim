#ifndef __INSTRUCTIONS__HEADER__
#define __INSTRUCTIONS__HEADER__

#include "Syntax.h"


class InstructionBase
{
	public:
	static bool JmptoNxt;
	static unsigned char PathIndex;
	static bool LoadPath;
	
};



class var : InstructionBase
{
	private:
	int value;
	public:
	var()
	{
		value = 0;
	}
		
	int operator < (int i)
	{
		if(value < i)
			return 1;
		else 
			return 0;
	}
	
	int operator > (int i)
	{
		if(value > i)
			return 1;
		else 
			return 0;
	}
	
	int operator == (int i)
	{
		if(value == i)
			return 1;
		else 
			return 0;
	}	
	
	int operator = (int i)
	{
		if(JmptoNxt != true)
		{
			value = i;
			return 1;
		}
		else 
			return 0;
	}
	
//	var operator ++()
//	{
//		var newvar;
//		newvar.value = ++value;
//		return newvar;
//	}
	var operator ++(int i)
	{
		var newvar;
		newvar.value = ++value;
		return newvar;
	}
	
	var operator --(int i)
	{
		var newvar;
		newvar.value = --value;
		return newvar;
	}
};


class COMP_t : InstructionBase
{
	public:
	int operator [](int i)
	{
		if(JmptoNxt == true)
			return 0;
		
		if(i == 0)
		{
			JmptoNxt = true;
		}
		return 1;
	}
};



class LOAD_t : InstructionBase 
{
	public:
	int operator [](var i)
	{
		if(JmptoNxt == true)
			return 0;

		
		return 1;
	}
};



class INCR_t : InstructionBase
{
	public:
	int operator [](var &i)
	{
		if(JmptoNxt == true)
			return 0;
		
		i++;
		return 1;
	}
};



class DECR_t : InstructionBase
{
	public:
	int operator [](var &i)
	{
		if(JmptoNxt == true)
			return 0;		

		i--;
		return 1;
	}
};



class ASIN_t : InstructionBase
{
	public:
	int operator [] (int i)
	{
		if(JmptoNxt == true)
			return 0;		

		return 1;
	}
};



class CALL_t : InstructionBase
{
	public:
	int operator [] (func i)
	{
		if(JmptoNxt == true)
			return 0;		
		
		i();

		return 1;
	}
};
















#endif
