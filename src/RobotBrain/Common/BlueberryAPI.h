#ifndef __BOOTLOADER_API_HEADER__
#define __BOOTLOADER_API_HEADER__

typedef void (*func)(void);


typedef struct
{
	func OnUSBConnect;
	func OnUSBDisconnect;
	func OnUSBDataReceived;
	
	unsigned char *SendBuffer;
	volatile unsigned char *ReceiveBuffer;
	
	unsigned int Sendlength;
	unsigned int ReceivedLength;
	
	func SendData;
	
} USB_t;



typedef struct
{
	unsigned short int Buffer[10];	
	func Init;
	
} ADC_t;



typedef struct
{
	func Reboot;
	unsigned char ClockSpeed;
	func OnCoreClockReset;	
	
	func SetClock_16Mhz;
	func SetClock_24Mhz;
	func SetClock_32Mhz;
	func SetClock_40Mhz;
	func SetClock_48Mhz;
	func SetClock_56Mhz;
	func SetClock_64Mhz;
	func SetClock_72Mhz;
	func SetClock_80Mhz;
	func SetClock_88Mhz;
	func SetClock_96Mhz;
	func SetClock_104Mhz;
	func SetClock_112Mhz;
	func SetClock_120Mhz;
	func SetClock_128Mhz;
	
} SYS_t;

typedef struct
{
	func OnUpdate;
	func OnCCR1Trigger;
	func OnCCR2Trigger;
	func OnCCR3Trigger;
	func OnCCR4Trigger;
	
} TIM_IT_t;

typedef struct
{
	func EXTI0_Callback;
	func EXTI1_Callback;
	func EXTI2_Callback;
	func EXTI3_Callback;
	func EXTI4_Callback;
	func EXTI5_Callback;
	func EXTI6_Callback;
	func EXTI7_Callback;
	func EXTI8_Callback;
	func EXTI9_Callback;
	func EXTI10_Callback;
	func EXTI11_Callback;
	func EXTI12_Callback;
	func EXTI13_Callback;
	func EXTI14_Callback;
	func EXTI15_Callback;
	
} EXTI_IT_t;

typedef struct
{
	TIM_IT_t TIM1_IT;
	TIM_IT_t TIM2_IT;
	TIM_IT_t TIM3_IT;
	TIM_IT_t TIM4_IT;
	
	EXTI_IT_t EXTI_IT;
	
} NVIC_IT_t;


typedef struct
{
	SYS_t SYS;

	USB_t USB;
	ADC_t ADC;
	
	NVIC_IT_t IT;
	
} BlueberryAPI;






#endif
