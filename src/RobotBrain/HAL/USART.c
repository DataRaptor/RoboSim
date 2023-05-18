#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"

#include "../System/IRArray.h"
#include "../System/Core.h"


#define LineStructSIZE sizeof(IRArray.Line)
#define RX_BUF_SIZE 50

uint8_t RX_FLAG_END_LINE = 0;
uint16_t RXi;
uint8_t RXc;
uint8_t RX_BUF[RX_BUF_SIZE] = {'\0'};



void clear_RXBuffer(void)
{
    for (RXi = 0; RXi < RX_BUF_SIZE; RXi++)
        RX_BUF[RXi] = '\0';
    RXi = 0;
}







void USART3_Init(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	

    /* NVIC Configuration */
    NVIC_InitTypeDef NVIC_InitStructure;
    /* Enable the USARTx Interrupt */
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);


    /* Configure the GPIOs */
    GPIO_InitTypeDef GPIO_InitStructure;


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);


    /* Configure the USART3 */
    USART_InitTypeDef USART_InitStructure;


    /* USART3 configuration ------------------------------------------------------*/
    /* USART3 configured as follow:
		- BaudRate = 115200 baud
		- Word Length = 8 Bits
		- One Stop Bit
		- No parity
		- Hardware flow control disabled (RTS and CTS signals)
		- Receive and transmit enabled
		- USART Clock disabled
		- USART CPOL: Clock is active low
		- USART CPHA: Data is captured on the middle
		- USART LastBit: The clock pulse of the last data bit is not output to
			the SCLK pin
	 */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;


    USART_Init(USART3, &USART_InitStructure);


    /* Enable USART3 */
    USART_Cmd(USART3, ENABLE);


    /* Enable the USART3 Receive interrupt: this interrupt is generated when the
		USART3 receive data register is not empty */
    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

}




void UpdateLine()
{
  if(RX_BUF[0] == 'D' && RX_BUF[1] == 'A' && RX_BUF[2] == 'T' && RX_BUF[3] == 'A')
  {
    IRArray.Line.Error = (int8_t)RX_BUF[4] - 9;
    
    IRArray.Data[0] = RX_BUF[5];
    IRArray.Data[1] = RX_BUF[6]; 
    IRArray.Data[2] = RX_BUF[7]; 
    IRArray.Data[3] = RX_BUF[8]; 
    IRArray.Data[4] = RX_BUF[9]; 
    IRArray.Data[5] = RX_BUF[10]; 
    IRArray.Data[6] = RX_BUF[11]; 
    IRArray.Data[7] = RX_BUF[12]; 
    IRArray.Data[8] = RX_BUF[13]; 
    IRArray.Data[9] = RX_BUF[14]; 
    
    
    IRArray.Line.LL = RX_BUF[15];
    IRArray.Line.LR = RX_BUF[16];
    IRArray.Line.M  = RX_BUF[17];
    IRArray.Line.RL = RX_BUF[18];
    IRArray.Line.RR = RX_BUF[19];
    
    
    IRArray.Line.AllZero = RX_BUF[20];
    IRArray.Line.AllOne = RX_BUF[21];
    IRArray.Line.SingleLineExist = RX_BUF[22];
    

    
    IRArray.Line.dt = convertFrom8To16(RX_BUF[23], RX_BUF[24]);
    
    IRArray.Line.LineWidth = RX_BUF[25];
    
  }
  
  
}




void USART3_IRQHandler(void)
{
    if ((USART3->SR & USART_FLAG_RXNE) != (u16)RESET)
    {
        RXc = USART_ReceiveData(USART3);
        RX_BUF[RXi] = RXc;
        RXi++;

        if (RXc != 13)
        {
            if (RXi > RX_BUF_SIZE - 1)
            {
                clear_RXBuffer();
            }
        }
        else
        {
          RX_FLAG_END_LINE = 1;
          
          UpdateLine();
          
          clear_RXBuffer();
        }
    }
}






//void USARTSend_String(char *pucBuffer)
//{
//  while (*pucBuffer)
//  {
//      USART_SendData(USART3, *pucBuffer++);
//      while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
//  }
//}



//uint16_t ii = 0;
//void USARTSend_Data(char *pucBuffer, uint16_t size)
//{
//  for(ii = 0; ii < size; ii++)
//  {
//    USART_SendData(USART3, pucBuffer[ii]);
//    while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);    
//  }
//}











