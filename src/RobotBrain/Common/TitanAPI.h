#ifndef __TITAN_API__
#define __TITAN_API__


typedef char int8;
typedef short int int16;
typedef int int32;
typedef long long int int64;

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef unsigned long long int uint64;


typedef struct 
{
	unsigned short int Second;
	unsigned short int Millisecond;
	
} TimeSpan;

typedef enum
{
	EventTimer1 = 1,
	EventTimer2 = 2,
	EventTimer3 = 3,
	EventTimer4 = 4,
	EventTimer5 = 5,
	EventTimer6 = 6,
	EventTimer7 = 7,
	EventTimer8 = 8
	
} EventTimer_t;


typedef enum 
{
	Stopwatch1 = 1,
	Stopwatch2 = 2,
	Stopwatch3 = 3,
	Stopwatch4 = 4,
	Stopwatch5 = 5,
	Stopwatch6 = 6,
	Stopwatch7 = 7,
	Stopwatch8 = 8,
	
} Stopwatch_t;


typedef enum
{
	PortA = 1, 
	PortB = 2, 
	PortC = 3, 
	PortD = 4, 
	PortE = 5, 
	PortF = 6,
}Port_t;

typedef enum
{
	Input = 1,
	Output = 2,
} Mode_t;


typedef void (*func)(void);
typedef void (*func1)(unsigned int);

typedef void (*func_exti)(Port_t Port, unsigned char Pin, func RaisingCallBack, func FallingCallBack);

typedef struct
{
	func GPIO_PA0_Digital_OUT;
	func GPIO_PA1_Digital_OUT;
	func GPIO_PA2_Digital_OUT;
	func GPIO_PA3_Digital_OUT;
	func GPIO_PA4_Digital_OUT;
	func GPIO_PA5_Digital_OUT;
	func GPIO_PA6_Digital_OUT;
	func GPIO_PA7_Digital_OUT;
	func GPIO_PA8_Digital_OUT;
	func GPIO_PA9_Digital_OUT;
	func GPIO_PA10_Digital_OUT;
	//func GPIO_PA11_Digital_OUT;
	//func GPIO_PA12_Digital_OUT;
	func GPIO_PA13_Digital_OUT;
	func GPIO_PA14_Digital_OUT;
	func GPIO_PA15_Digital_OUT;

	func GPIO_PB0_Digital_OUT;
	func GPIO_PB1_Digital_OUT;
	func GPIO_PB2_Digital_OUT;
	func GPIO_PB3_Digital_OUT;
	func GPIO_PB4_Digital_OUT;
	func GPIO_PB5_Digital_OUT;
	func GPIO_PB6_Digital_OUT;
	func GPIO_PB7_Digital_OUT;
	func GPIO_PB8_Digital_OUT;
	func GPIO_PB9_Digital_OUT;
	func GPIO_PB10_Digital_OUT;
	//func GPIO_PB11_Digital_OUT;
	//func GPIO_PB12_Digital_OUT;
	func GPIO_PB13_Digital_OUT;
	func GPIO_PB14_Digital_OUT;
	func GPIO_PB15_Digital_OUT;

	func GPIO_PC13_Digital_OUT;
	func GPIO_PC14_Digital_OUT;
	func GPIO_PC15_Digital_OUT;
}GPIO_t;





typedef struct
{
	
}FLASH_t;


typedef struct
{
	
}PWM_t;


typedef struct
{
	
}TIM_t;


typedef struct
{
	func_exti EXTIx_Init;
}EXTI_t;


typedef struct
{
	func1 RunApp;
	
} App_t;

typedef struct
{
	func OnSerialDataReceived;
	
	unsigned char *SendBuffer;
	volatile unsigned char *ReceiveBuffer;
	
	unsigned int Sendlength;
	unsigned int ReceivedLength;
	
	func SendData;
	
} Serial_t;


typedef void (*event)(EventTimer_t EventTimerX, TimeSpan Duration, uint8 RepeatForever, func Callback);
typedef struct 
{
	event Register;
	
} Events_t;


typedef void (*stopwatch_start)(Stopwatch_t StopwatchX);
typedef TimeSpan (*stopwatch_gettim)(Stopwatch_t StopwatchX);
typedef struct 
{
	stopwatch_start Start;
	stopwatch_gettim GetTime;
	
} Stopwatches_t;



typedef struct
{
	func ToggleLED;
	func LED_ON;
	func LED_OFF;
		
} Board_t;

typedef struct 
{
	GPIO_t GPIO;
	EXTI_t EXTI1;
	
	App_t App;
	Serial_t Serial;
	Events_t Events;
	
	Stopwatches_t Stopwatch;
	
	Board_t BoardSupport;
}TitanAPI;







#endif
