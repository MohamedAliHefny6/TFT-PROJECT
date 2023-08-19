/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : TFT   					******/
/*********************************************************/

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*GPIO*/
#include "MGPIO_int.h"

/*SYSTICK*/
#include "STK_int.h"

/*SPI*/
#include "SPI_int.h"

/*TFT*/
#include "TFT_int.h"
#include "TFT_prv.h"
#include "TFT_cfg.h"


/*Function to adjust reset sequence of TFT display*/
void HTFT_voidReset(void)
{
	/* Set TFT_RESET pin to HIGH */
	MGPIO_voidSetPinValue(PORTA,TFT_RESET,PIN_HIGH);

	/* Delay 100 microseconds */
	MSTK_voidDelayUsec(100);

	/* Set TFT_RESET pin to LOW */
	MGPIO_voidSetPinValue(PORTA,TFT_RESET,PIN_LOW);

	/* Delay 10 microseconds */
	MSTK_voidDelayUsec(10);

	/* Set TFT_RESET pin to HIGH */
	MGPIO_voidSetPinValue(PORTA,TFT_RESET,PIN_HIGH);

	/* Delay 100 microseconds */
	MSTK_voidDelayUsec(100);

	/* Set TFT_RESET pin to LOW */
	MGPIO_voidSetPinValue(PORTA,TFT_RESET,PIN_LOW);

	/* Delay 100 microseconds */
	MSTK_voidDelayUsec(100);

	/* Set TFT_RESET pin to HIGH */
	MGPIO_voidSetPinValue(PORTA,TFT_RESET,PIN_HIGH);

	/* Delay 120 microseconds */
	MSTK_voidDelayUsec(120);
}

/**********************************************************************************************/

/*Function to write command to TFT display*/
void HTFT_voidWriteCommand(u8 Copy_u8Cmd)
{
	/* Set TFT_A0 pin to LOW */
	MGPIO_voidSetPinValue(PORTA,TFT_A0,PIN_LOW);

	/* Transmit the command over SPI */
	MSPI_u16Transceive(Copy_u8Cmd);
}

/**********************************************************************************************/

/*Function to write data to TFT display*/
void HTFT_voidWriteData(u8 Copy_u8Data)
{
	/* Set TFT_A0 pin to HIGH */
	MGPIO_voidSetPinValue(PORTA,TFT_A0,PIN_HIGH);

	/* Transmit the data over SPI */
	MSPI_u16Transceive(Copy_u8Data);
}

/**********************************************************************************************/

/*Function to initialize the TFT display*/
void HTFT_voidInit(void)
{
	/* Reset the TFT display */
	HTFT_voidReset();

	/* Send sleep-out command */
	HTFT_voidWriteCommand(0x11);

	/* Delay 150 milliseconds */
	MSTK_voidDelayMsec(150);

	/* Send color mode ID command */
	HTFT_voidWriteCommand(0x3A);

	/* Select RGB565 color mode */
	HTFT_voidWriteData(0x05);

	/* Send display on command to the TFT display */
	HTFT_voidWriteCommand(0x29);
}

/**********************************************************************************************/

/*Function to display an image on TFT display*/
void HTFT_voidDisplay(u16 *Copy_u16Image)
{
	/* Set X position for the TFT display (0,127) */
	HTFT_voidWriteCommand(0x2A);

	/* Start at bottom-right of TFT display (0,0) */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);

	/* End at bottom-left of TFT display (0,127) */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(127);

	/* Set Y position for the TFT display (0,159) */
	HTFT_voidWriteCommand(0x2B);

	/* Start at bottom-right of TFT display (0,0) */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(0);

	/* End at Top-right of TFT display (0,159) */
	HTFT_voidWriteData(0);
	HTFT_voidWriteData(159);

	/* Command to send image to the TFT display */
	HTFT_voidWriteCommand(0x2C);

	/* Iterate over the pixel data array and send each pixel data to the TFT display */
	for(u16 i = 0 ; i < 20480 ; i++)
	{
		/* Extract the lower 8 bits of the pixel data */
		u8 Local_u8LOW = (u8) Copy_u16Image[i];

		/* Extract the higher 8 bits of the pixel data */
		u8 Local_u8HIGH = (u8) (Copy_u16Image[i]>>8);

		/* Send the higher 8 bits of pixel data over SPI */
		HTFT_voidWriteData(Local_u8HIGH);

		/* Send the lower 8 bits of pixel data over SPI */
		HTFT_voidWriteData(Local_u8LOW);
	}
}
