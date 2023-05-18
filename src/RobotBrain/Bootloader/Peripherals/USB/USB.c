#include "USB.h"

#include "BlueberryAPI.h"
extern BlueberryAPI api;


uint8_t USB_SendBuffer[VIRTUAL_COM_PORT_DATA_SIZE];
uint32_t USB_PacketSent=1;
uint32_t USB_PacketReceived=1;



void USB_Initialize(void (*ReceiveCallback)())
{
	receiveCallback = ReceiveCallback;
	
	Set_System();
  Set_USBClock();
  USB_Interrupts_Config();
  USB_Init();
}


void USB_Send(void)
{
	CDC_Send_DATA(api.USB.SendBuffer, api.USB.Sendlength);
}











