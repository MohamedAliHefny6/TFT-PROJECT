
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "SPI_int.h"
#include "TFT_int.h"
#include "STK_int.h"
#include "TFT_img.h"


void main(void)
{
	    MRCC_voidInitSysClk();
		MSTK_voidInit();
		MRCC_voidEnable_Peripheral(RCC_AHB1,AHB1ENR_GPIOAEN);
		MRCC_voidEnable_Peripheral(RCC_APB2,APB2ENR_SPI1EN);

		MGPIO_SetPinMode(PORTA,PIN0,OUTPUT);
		MGPIO_SetPinMode(PORTA,PIN1,OUTPUT);
		MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);
		MGPIO_SetOutputPinMode(PORTA,PIN1,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);

		MSPI_voidInit();

		HTFT_voidInit();




  while (1)
    {
	  /////////////// GIF /////////////////////
	  HTFT_voidDisplay(Image1);
	  HTFT_voidDisplay(Image2);
	  HTFT_voidDisplay(Image3);
	  HTFT_voidDisplay(Image4);
	  HTFT_voidDisplay(Image5);
	  HTFT_voidDisplay(Image6);

    }
}



