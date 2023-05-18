#include "Compiler.h"

void function();

class Track1 : Program
{
	public:
	void Code()
	{
		
		ACTION
		[INCR [P0]]
		[ASIN [P1 = 12]]
		[CALL [function]];
		
		
		
		ACTION
		[INCR [P0]];
		
		
//		ACTION /*Check Triangle*/ 
//		[COMP [L0 == 00100010]]
//		[COMP [P0 == 2]]
//		[COMP [P1 == 1]]
//		//[LOAD [1]]
//		[INCR [P0]]
//		[ENDA];
//		
//		
//		PATH /*Triangle*/
//		^ 0
//		|_0101010 |_010
//		|_0111010 |_001
//		|_0001010 |_100;
	}
};


