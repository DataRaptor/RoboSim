#include "TitanAPI.h"


uint8 HeaderCmp(char header[], volatile uint8 data[])
{
	char *ptr = header;
	
	uint8 i = 0;
	while(1)
	{
		if(*ptr == 0 && data[i] != ' ')
			return 0;
		if(data[i] == ' ' && *ptr != 0)
			return 0;
			
		if(data[i] == ' ' && *ptr == 0)
			break;
		
		
		if(*ptr != data[i])
			return 0;
		
		i++;
		ptr++;
	}
	
	i++;
	
	
	//Shift all value to left
	for(uint8 j = i; j < 64; j++)
	{
		data[j - i] = data[j]; 
	}
	
	return i;
}






