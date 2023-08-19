/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : RCC		 				******/
/*********************************************************/

#ifndef MUART_PRV_H
#define MUART_PRV_H

/*UART Registers*/
typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}USART_t;

//#define		MUART_BRR_REG		    *((volatile u32*)0x40011008)
#define		USART1_BASE_ADDRESS		0x40011000								 //UART1 Base Address
#define		MUSART1					((volatile USART_t*)USART1_BASE_ADDRESS)

#define 	USART2_BASE_ADDRESS	    0x40004400								 //UART2 Base Address
#define		MUSART2   				((volatile USART_t*)USART2_BASE_ADDRESS)

#define 	USART6_BASE_ADDRESS	    0x40011400								 //UART3 Base Address
#define		MUSART6   				((volatile USART_t*)USART3_BASE_ADDRESS)


/*Macros for bits*/
//USART_SR
#define		CTS				9		//CTS flag
#define		LBD				8		//LIN break detection flag
#define		TXE				7		//Transmit data register empty
#define		TC				6		//Transmission complete
#define		RXNE		    5		//Read data register not empty
#define		IDLE		    4		//IDLE line detected
#define 	ORE      	    3		//Overrun error
#define 	NF      	    2		//Noise detect flag
#define     FE				1		//Framing error
#define		PE				0		//Parity error

//USART_CR1_Bits
#define 	OVER8      		15		//Oversampling Mode
#define 	UE      	    13		//USART enable
#define		M			    12		//Word length
#define		WAKE		    11		//Wakeup method
#define		PCE				10		//Parity control enable
#define		PS				9		//Parity selection
#define		PEIE		    8		//PE interrupt enable
#define		TXEIE		    7		//TXE interrupt enable
#define		TCIE		    6		//Transmission complete interrupt enable
#define		RXNEIE			5		//RXNE interrupt enable
#define		IDLEIE			4		//IDLE interrupt enable
#define 	TE      	    3		//Transmitter enable
#define 	RE      	    2		//Receiver enable
#define     RWU				1		//Receiver wakeup
#define		SBK				0		//Send break

//USART_CR2_Bits
#define		LINEN			14		//LIN mode enable
#define 	STOP1      		13		//STOP bits
#define		STOP0		    12		//STOP bits
#define		CLKEN		    11		//Clock enable
#define		CPOL		    10		//Clock polarity
#define		CPHA		    9		//Clock phase
#define		LBCL		    8		//Last bit clock pulse
#define		LBDIE		    6		//LIN break detection interrupt enable
#define		LBDL		    5		//lin break detection length
#define 	ADD3      		3		//Address of the USART node
#define 	ADD2     	    2		//Address of the USART node
#define     ADD1		    1		//Address of the USART node
#define		ADD0		    0		//Address of the USART node

//USART_CR3_Bits
#define		ONEBit			11  	//One sample bit method enable
#define		CTSIE		    10		//CTS interrupt enable
#define		CTSE		    9		//CTS enable
#define		RTSE		    8		//RTS enable
#define		DMAT		    7		//DMA enable transmitter
#define		DMAR		    6		//DMA enable receiver
#define		SCEN		    5		//Smartcard mode enable
#define		NACK		    4		//Smartcard NACK enable
#define 	HDSEL      		3		//Half-duplex selection
#define 	IRLP    	    2		//IrDA low-power
#define     IREN		    1		//IrDA mode enable
#define		EIE				0		//Error interrupt enable

/*Macros for Configurations*/	
#define		USART1								0
#define     USART2                              1
#define     USART6								2

#define		USART_16_Oversampling				0
#define		USART_8_Oversampling				1

#define		USART_8BITS_DATA					0
#define		USART_9BITS_DATA					1

#define		USART_PARITY_CONTROL_DISABLED		0
#define		USART_PARITY_CONTROL_ENABLED		1

#define		USART_EVEN_PARITY					0
#define		USART_ODD_PARITY					1

#define		USART_1_STOP_BIT					0
#define		USART_HALF_STOP_BIT					1
#define		USART_2_STOP_BIT					2
#define		USART_1_AND_HALF_STOP_BIT			3

#define		USART_LOW_VALUE						0
#define		USART_HIGH_VALUE					1

#define		USART_READ_FIRST					0
#define		USART_WRITE_FIRST					1

/*Baud Rate Values*/
#define		USART_BAUD_RATE_9600				0				//104
#define		USART_BAUD_RATE_115200				1

#endif
