/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : RCC		 				******/
/*********************************************************/
											    
/*LIB*/
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"


/*MCAL*/
#include	"MUART_int.h"
#include	"MUART_prv.h"
#include	"MUART_cfg.h"

void (*MUART_CALLPTR)(void) = NULL;			//Global pointer to function for callback function
void (*MUART2_CALLPTR)(void) = NULL;			//Global pointer to function for callback function


void   MUSART_voidInit1	(void)
/*UART Init Function*/
{
//---------------USART1---------------
	if(	USART_NUM == USART1)
	{
		/*over-sampling*/
		    if ( USART_OVERSAMLING == USART_16_Oversampling){
			CLR_BIT(MUSART1 -> CR1 , OVER8);}

		/*Word Length*/
		if		(USART_WORD_LENGTH == USART_8BITS_DATA){
			CLR_BIT(MUSART1 -> CR1 , M);
		}



		/*Parity Control Enable*/
		if		(USART_u8_PARITY_CONTROL == USART_PARITY_CONTROL_DISABLED){
			CLR_BIT(MUSART1 -> CR1 , PCE);}

		///*Parity Selection*/
		//#if		USART_PARITY_SELECTION == USART_EVEN_PARITY
		//	CLR_BIT(MUSART1 -> USART_CR1 , USART_PS);
		//#elif	USART_PARITY_SELECTION == USART_ODD_PARITY
		//	SET_BIT(MUSART1 -> USART_CR1 , USART_PS);
		//#endif

		/*Stop Bits*/
		if	(	USART_STOP_BITS == USART_1_STOP_BIT){
			CLR_BIT(MUSART1 -> CR2 , STOP0);
			CLR_BIT(MUSART1 -> CR2 , STOP1);
		}

		///*Clock Polarity*/
		//#if		USART_POLARITY == USART_LOW_VALUE
		//	CLR_BIT(MUSART1 -> USART_CR2 , USART_CPOL);
		//#elif	USART_POLARITY == USART_HIGH_VALUE
		//	SET_BIT(MUSART1 -> USART_CR2 , USART_CPOL);
		//#endif
		//
		///*Clock Phase*/
		//#if		USART_PHASE == USART_READ_FIRST
		//	CLR_BIT(MUSART1 -> USART_CR2 , USART_CPHA);
		//#elif	USART_PHASE == USART_WRITE_FIRST
		//	SET_BIT(MUSART1 -> USART_CR2 , USART_CPHA);
		//#endif

		/*Set Baud Rate*/
		//#if  USART_BAUD_RATE == USART_BAUD_RATE_9600
		//	MUSART1 -> USART_BRR = USART_BAUD_RATE_9600;
		//#endif

		/*Baud rate*/
		MUSART1 -> BRR = (104<<4)|(3);
		//MUSART1 -> BRR = 0x68;
		/*Enable Transmitter*/
		SET_BIT(MUSART1 -> CR1 , TE);

		/*Enable Receiver*/
		SET_BIT(MUSART1 -> CR1 , RE);

		/*Enable Interrupt*/
		SET_BIT(MUSART1 -> CR1 , RXNEIE);

		///*Enable USART*/
		//SET_BIT(MUSART1 -> CR1 , UE);
		//
		///*Clear Status Register*/
		MUSART1 -> SR = 0;
	}



}

/******************************************************************************************************/
void	MUART_voidEnable(void)
/*UART enable function*/
{
	/*Enable USART*/
	SET_BIT(MUSART1 -> CR1 , UE);
	SET_BIT(MUSART2 -> CR1 , UE);

}

/******************************************************************************************************/
void	MUART_voidDisable(void)
/*UART Disable function*/
{
	/*Enable USART*/
	CLR_BIT(MUSART1 -> CR1 , UE);
}

/******************************************************************************************************/
void	MUART_voidCallBack(void(*ptr)(void))
/*UART Callback function*/
{  if(ptr != NULL)
	{
		MUART_CALLPTR = ptr;
	}
}

/******************************************************************************************************/
void	USART1_IRQHandler(void)
/*USART IRQ function*/
{
	if(MUART_CALLPTR != NULL)
	{
		MUART_CALLPTR();
	}
}

/******************************************************************************************************/
void 	MUSART_voidTransmitChar	(u8 Copy_u8Data)
/*function to transmit char*/
{
	#if		USART_NUM == USART1
	    MSTK_voidDelayMsec(20);
		MUSART1 -> DR = Copy_u8Data;

		while(!GET_BIT (MUSART1 -> SR , 7));

	#elif	USART_NUM == USART2
		MUSART2 -> USART_DR = Copy_u8Data;
		while(GET_BIT (MUSART2 -> USART_SR , USART_TC) == 0);
	#elif	USART_NUM == MUSART6
		USART  -> USART_DR = Copy_u8Data;
		while(GET_BIT (MUSART6 -> USART_SR , USART_TC) == 0);
	#endif
}

/******************************************************************************************************/
  u8 	MUSART_u8ReceiveChar(u8 *Copy_pu8ReceivedByte)
/*Function to receive char*/
{
	u8 Local_enuFunctionState = 1;

	if(Copy_pu8ReceivedByte != NULL)
	{
		#if		USART_NUM == USART1
			while((GET_BIT((MUSART1-> SR), RXNE) == 0));
			*Copy_pu8ReceivedByte = MUSART1 -> DR;
		#elif	USART_NUM == USART2
			while((GET_BIT((MUSART2 -> USART_SR), USART_RXNE) == 0));
			*Copy_pu8ReceivedByte = MUSART2 -> USART_DR;
		#elif	USART_NUM == USART6
			while((GET_BIT((MUSART6 -> USART_SR), USART_RXNE) == 0));
			*Copy_pu8ReceivedByte = MUSART6 -> USART_DR;
		#endif
	}

	else
	{
		 Local_enuFunctionState = 0;
	}

	return Local_enuFunctionState;

}

/******************************************************************************************************/
void 	MUSART_voidTransmitString	(u8 Copy_u8DataArr[])
/*function to transmit string*/
{
	u8 Local_u8Counter = 0;
	#if	USART_NUM == USART1
		while (Copy_u8DataArr[Local_u8Counter] != '\0')
		{
			MUSART1 -> DR = Copy_u8DataArr[Local_u8Counter];
			while(GET_BIT (MUSART1 -> SR , TC) == 0);
			Local_u8Counter++;
		}
	#elif	USART_NUM == USART2
		while (Copy_u8DataArr[Local_u8Counter] != '\0')
		{
			MUSART2 -> USART_DR = Copy_u8DataArr[Local_u8Counter];
			while(GET_BIT (MUSART2 -> USART_SR , USART_TC) == 0);
			Local_u8Counter++;
		}
	#elif	USART_NUM == USART6
		while (Copy_u8DataArr[Local_u8Counter] != '\0')
		{
			MUSART6 -> USART_DR = Copy_u8DataArr[Local_u8Counter];
			while(GET_BIT (MUSART6 -> USART_SR , USART_TC) == 0);
			Local_u8Counter++;
		}
	#endif
}

/******************************************************************************************************/
u8 	MUSART_ReceiveString(u8 *Copy_pu8ReceivedData)
/*function to receive string*/
{
	u8 Local_enuFunctionState = 1;
	u8 Local_u8Counter = 0;
	u8 Local_u8ReceivedData;

	if(Copy_pu8ReceivedData != NULL)
	{
		while(Local_u8ReceivedData != '#')
		{
			MUSART_u8ReceiveChar(&Local_u8ReceivedData);
			Copy_pu8ReceivedData[Local_u8Counter] = Local_u8ReceivedData ;
			Local_u8Counter++;
		}
		Copy_pu8ReceivedData[Local_u8Counter] = '\0';
	}
	else
	{
		 Local_enuFunctionState = 0;
	}

	return Local_enuFunctionState;
}

/******************************************************************************************************/
u8 UART_READ_DATA(void)
{
	 while(GET_BIT( MUSART1->SR,5)==0);
	 return (u8) MUSART1->DR;

}



/**********************************************************************************************************/

void   MUSART_voidInit2	(void)
/*UART Init Function*/
{
//---------------USART1---------------
	if	(USART_NUM2 == USART2)
	{
			/*oversampling*/
			if     (USART_OVERSAMLING == USART_16_Oversampling){
				CLR_BIT(MUSART2 -> CR1 , OVER8);}

			/*Word Length*/
			if		(USART_WORD_LENGTH == USART_8BITS_DATA){
				CLR_BIT(MUSART2 -> CR1 , M);}


			/*Parity Control Enable*/
			if		(USART_u8_PARITY_CONTROL == USART_PARITY_CONTROL_DISABLED){
				CLR_BIT(MUSART2 -> CR1 , PCE);}


			/*Parity Selection*/
			if		(USART_PARITY_SELECTION == USART_EVEN_PARITY){
				CLR_BIT(MUSART2 -> CR1 , PS);}

			/*Stop Bits*/
			if	(	USART_STOP_BITS == USART_1_STOP_BIT){
				CLR_BIT(MUSART2 -> CR2 , STOP0);
				CLR_BIT(MUSART2 -> CR2 , STOP1);}

			/*Baud rate*/
					MUSART2 -> BRR = (104<<4)|(3);
					//MUSART1 -> BRR = 0x68;
					/*Enable Transmitter*/
					SET_BIT(MUSART2 -> CR1 , TE);

					/*Enable Receiver*/
					SET_BIT(MUSART2 -> CR1 , RE);

					/*Enable Interrupt*/
					SET_BIT(MUSART2 -> CR1 , RXNEIE);

					///*Enable USART*/
					//SET_BIT(MUSART1 -> CR1 , UE);
					//
					///*Clear Status Register*/
					MUSART2 -> SR = 0;


	}
}

void MUART_voidEnable2(void)
{
	SET_BIT(MUSART2 -> CR1 , UE);
}

u8 UART2_READ_DATA(void)
{
	 while(GET_BIT( MUSART2->SR,5)==0);
	 return (u8) MUSART2->DR;

}


void 	MUSART2_voidTransmitChar	(u8 Copy_u8Data)

{
	 MSTK_voidDelayMsec(20);
			MUSART2 -> DR = Copy_u8Data;

			while(!GET_BIT (MUSART2 -> SR , 7));

}

void	MUART2_voidCallBack(void(*ptr)(void))

{  if(ptr != NULL)
	{
		MUART2_CALLPTR = ptr;
	}
}

void	USART2_IRQHandler(void)
/*USART IRQ function*/
{
	if(MUART2_CALLPTR != NULL)
	{
		MUART2_CALLPTR();
	}
}


