#include "SmartcatAPI.h"
CatAPI smartcatapi;

#include "SmartCat.h"
TitanAPI *titanapi = (TitanAPI*)0x20000D18;



void Loop(void)
{
	uint8 i = 0; 
	i++;
	
	titanapi->BoardSupport.ToggleLED();
}

uint64 data;

int main()
{
	/*Initialize API*/
	InitializeAPI();
	
	/*Initialize Main loop*/
	titanapi->Events.Register(EventTimer1, (TimeSpan){.Millisecond = 10000}, 1, Loop);
	
	
	titanapi->BoardSupport.ToggleLED();
	
	
	data = 0101010;

	
	while(1)
	{
		
	}
}















