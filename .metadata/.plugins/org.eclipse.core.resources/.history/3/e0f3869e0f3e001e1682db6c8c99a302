/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : RCC		 				******/
/*********************************************************/

#ifndef		_MUART_INT_H
#define		_MUART_INT_H


void   MUSART_voidInit1	(void);					/*UART enable function*/
void   MUSART_voidInit2 (void);
void			MUART_voidEnable				(void);
void			MUART_voidDisable				(void);						/*UART Disable function*/
void			MUART_voidCallBack				(void(*ptr)(void));			/*UART Callback function*/
void 			MUSART_voidTransmitChar			(u8 Copy_u8Data);			/*USART IRQ function*/
void 			MUSART_voidTransmitString   	(u8 Copy_u8DataArr[]);		/*function to transmit char*/
u8          	MUSART_u8ReceiveChar			(u8 *Copy_pu8ReceivedByte);	/*Function to receive char*/
u8				MUSART_ReceiveString			(u8 *Copy_pu8ReceivedData);	/*function to transmit string*/
u8              UART_READ_DATA                  (void);
void MUART_voidEnable2(void);
u8 UART2_READ_DATA(void);
void 	MUSART2_voidTransmitChar	(u8 Copy_u8Data);
void	MUART2_voidCallBack(void(*ptr1)(void));

	
#endif
