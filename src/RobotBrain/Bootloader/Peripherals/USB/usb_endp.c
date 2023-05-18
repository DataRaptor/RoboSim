/**
  ******************************************************************************
  * @file    usb_endp.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Endpoint routines
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_mem.h"
#include "hw_config.h"
#include "usb_istr.h"
#include "usb_pwr.h"
#include "callback.h"

#include "BlueberryAPI.h"
extern BlueberryAPI api;


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Interval between sending IN packets in frame number (1 frame = 1ms) */
#define VCOMPORT_IN_FRAME_INTERVAL             5
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern volatile uint32_t USB_PacketSent;
extern volatile uint32_t USB_PacketReceived;
extern volatile uint8_t USB_ReceiveBuffer[64];
uint32_t USB_ReceivedLength;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : EP1_IN_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void EP1_IN_Callback (void)
{
  USB_PacketSent = 1;
}

/*******************************************************************************
* Function Name  : EP3_OUT_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
unsigned char running = 0;
void EP3_OUT_Callback(void)
{
  USB_PacketReceived = 1;
  USB_ReceivedLength = GetEPRxCount(ENDP3);
  PMAToUserBufferCopy((unsigned char*)USB_ReceiveBuffer, ENDP3_RXADDR, USB_ReceivedLength);
	
	
	//USB Recieve Check
	if (bDeviceState == CONFIGURED)
	{
		CDC_Receive_DATA();
		
		
		//Call Process Data Function
		if(running == 0 )
		{
			running = 1;
			api.USB.ReceivedLength = USB_ReceivedLength;
			receiveCallback();
			running = 0;
		}
		
	}
	
	
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
