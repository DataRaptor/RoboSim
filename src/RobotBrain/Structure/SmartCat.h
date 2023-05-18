#ifndef SmartCat__
#define SmartCat__


enum Junction_t
{
	_0101010 = 1,   //plus
	_0100010 = 2,		//BottomT
	_1000000 = 3,		//LeftV
	_0000001 = 4,		//RightV
	_0101000 = 5,   //RightT
	_0001010 = 6,   //LeftT
	_0100000 = 7,   //LeftL
	_0000010 = 8,   //RightL
	
};

enum Action_t
{
	GoLeft          = 100, 
	GoRight         = 001, 
	Ignore          = 010, 
	SweepLeft2line  = 200, 
	SweepRight2line = 002,
	SweepLeft3line  = 300, 
	SweepRight3line = 003,	
	
};


class JunctionCommand
{
	Junction_t Junction;
	Action_t   Action;
};


class Path
{
	public:
	unsigned char Size;
	JunctionCommand Junctions[];
};








#endif