#ifndef USB_CORE__
#define USB_CORE__

#include "hw_config.h"
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"
#include "callback.h"




extern volatile uint8_t USB_ReceiveBuffer[VIRTUAL_COM_PORT_DATA_SIZE];
extern volatile uint32_t USB_ReceivedLength ;
extern volatile uint32_t length ;


extern uint8_t USB_SendBuffer[VIRTUAL_COM_PORT_DATA_SIZE];
extern uint32_t USB_PacketSent;
extern uint32_t USB_PacketReceived;




void USB_Initialize(void (*ReceiveCallback)());

void USB_Send(void);



#endif






