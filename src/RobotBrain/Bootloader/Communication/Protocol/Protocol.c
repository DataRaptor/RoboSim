#include "blueberry.h"



uint8_t buffer[63];
uint8_t bufferidx = 0;
void Serial_SendData(char header[], void *data, uint8_t size)
{
	/*Clear Buffer*/
	for(uint8_t i = 0; i < 64; i++)
		buffer[i] = 0;
	
	
	bufferidx = 0;
	
	/*Copy header to buffer*/
	char *ptr = header;
	while(*ptr != '\0')
	{
		buffer[bufferidx] = *ptr;
		
		bufferidx++;
		ptr++;
	}
	
	buffer[bufferidx] = ' ';
	bufferidx++;	
	
	
	/*Copy Data to buffer*/
	char *csrc = (char *)data;
	uint8_t dataidx = 0;
	while(bufferidx < 64 && dataidx < size)
	{
		buffer[bufferidx] = csrc[dataidx];
		
		dataidx++;
		bufferidx++;
	}
	
		
	CDC_Send_DATA((uint8_t*)buffer, bufferidx);
}




void Serial_SendString(char header[], char str[])
{
	/*Clear Buffer*/
	for(uint8_t i = 0; i < 64; i++)
		buffer[i] = 0;
	
	
	bufferidx = 0;
	
	/*Copy header to buffer*/
	char *ptr = header;
	while(*ptr != '\0')
	{
		buffer[bufferidx] = *ptr;
		
		bufferidx++;
		ptr++;
	}
	
	buffer[bufferidx] = ' ';
	bufferidx++;	
	
	/*Copy Data to buffer*/
	ptr = str;
	while(*ptr != '\0')
	{
		buffer[bufferidx] = *ptr;
		
		bufferidx++;
		ptr++;
	}
	
	//End of message
	buffer[bufferidx] = '\r';
	bufferidx++;	
	

	CDC_Send_DATA((uint8_t*)buffer, bufferidx);
}




void FillStruct(uint8_t startindex, void *strct, uint8_t size)
{
	/*Copy buffer to structure*/
	char *dest = (char *)strct;
	uint8_t dataidx = 0;
	uint8_t bufferidx = startindex;
	while(bufferidx < 64 && dataidx < size)
	{
		dest[dataidx] = USB_ReceiveBuffer[bufferidx]; 
		
		dataidx++;
		bufferidx++;
	}
}





uint8_t HeaderCmp(char header[])
{
	char *ptr = header;
	
	uint8_t i = 0;
	while(1)
	{
		if(*ptr == 0 && USB_ReceiveBuffer[i] != ' ')
			return 0;
		if(USB_ReceiveBuffer[i] == ' ' && *ptr != 0)
			return 0;
			
		if(USB_ReceiveBuffer[i] == ' ' && *ptr == 0)
			break;
		
		
		if(*ptr != USB_ReceiveBuffer[i])
			return 0;
		
		i++;
		ptr++;
	}
	
	i++;
	
	
	//Shift all value to left
	for(uint8_t j = i; j < 64; j++)
	{
		USB_ReceiveBuffer[j - i] = USB_ReceiveBuffer[j]; 
	}
	
	
	return i;
}























