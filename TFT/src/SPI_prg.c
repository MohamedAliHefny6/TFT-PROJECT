#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_int.h"

#include "SPI_int.h"
#include "SPI_prv.h"
#include "SPI_cfg.h"

static void (*SPI1_CALLBACK_PTR)(void);

void MSPI_voidInit(void)
{
	MGPIO_SetPinMode(PORTA,PIN6,ALT_FUNC); /*MISO1*/
	MGPIO_SetPinMode(PORTA,PIN7,ALT_FUNC); /*MOSI1*/
	MGPIO_SetPinMode(PORTA,PIN5,ALT_FUNC); /*SCK1*/

	MGPIO_SetPinAlterFunc(PORTA,PIN6,AF5_SPI1_TO_SPI4); /*MISO1*/
	MGPIO_SetPinAlterFunc(PORTA,PIN7,AF5_SPI1_TO_SPI4); /*MOSI1*/
	MGPIO_SetPinAlterFunc(PORTA,PIN5,AF5_SPI1_TO_SPI4); /*SCK1*/

	/*Master mode or Slave mode*/
#if SPI_MASTER_SLAVE == SPI_MASTER
	SPI1_REG->CR1 |= (1<<CR1_MSTR);

#elif SPI_MASTER_SLAVE == SPI_SLAVE
	SPI1_REG->CR1 &= ~(1<<CR1_MSTR);

#else

#endif

	SPI1_REG->CR1 |= (1<<CR1_SSI); //SSI
	SPI1_REG->CR1 |= (1<<CR1_SSM); //SSM

	/*CPOL - CPHA*/
	SPI1_REG->CR1 |= (1<<CR1_CPHA);
	SPI1_REG->CR1 |= (1<<CR1_CPOL);

	/*Baud Rate*/
#if SPI_BAUD_RATE == SPI_CLK_2
	SPI1_REG->CR1 &= ~(1<<CR1_BR0);
	SPI1_REG->CR1 &= ~(1<<CR1_BR1);
	SPI1_REG->CR1 &= ~(1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_4
	SPI1_REG->CR1 |= (1<<CR1_BR0);
	SPI1_REG->CR1 &= ~(1<<CR1_BR1);
	SPI1_REG->CR1 &= ~(1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_8
	SPI1_REG->CR1 &= ~(1<<CR1_BR0);
	SPI1_REG->CR1 |= (1<<CR1_BR1);
	SPI1_REG->CR1 &= ~(1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_16
	SPI1_REG->CR1 |= (1<<CR1_BR0);
	SPI1_REG->CR1 |= (1<<CR1_BR1);
	SPI1_REG->CR1 &= ~(1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_32
	SPI1_REG->CR1 &= ~(1<<CR1_BR0);
	SPI1_REG->CR1 &= ~(1<<CR1_BR1);
	SPI1_REG->CR1 |= (1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_64
	SPI1_REG->CR1 |= (1<<CR1_BR0);
	SPI1_REG->CR1 &= ~(1<<CR1_BR1);
	SPI1_REG->CR1 |= (1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_128
	SPI1_REG->CR1 &= ~(1<<CR1_BR0);
	SPI1_REG->CR1 |= (1<<CR1_BR1);
	SPI1_REG->CR1 |= (1<<CR1_BR2);

#elif SPI_BAUD_RATE == SPI_CLK_256
	SPI1_REG->CR1 |= (1<<CR1_BR0);
	SPI1_REG->CR1 |= (1<<CR1_BR1);
	SPI1_REG->CR1 |= (1<<CR1_BR2);

#else

#endif

	/*MSB or LSB first*/
#if SPI_MSB_LSB == SPI_MSB_FIRST
	SPI1_REG->CR1 &= ~(1<<CR1_LSB_FIRST);

#elif SPI_MSB_LSB == SPI_MSB_FIRST
	SPI1_REG->CR1 |= (1<<CR1_LSB_FIRST);

#else

#endif

	/*Data format*/
#if DATA_FRAME_FORMAT == DATA_8_BIT
	SPI1_REG->CR1 &= ~(1<<CR1_DFF);

#elif DATA_FRAME_FORMAT == DATA_16_BIT
	SPI1_REG->CR1 |= (1<<CR1_DFF);

#else

#endif

	/*ENABLE SPI*/
	SPI1_REG->CR1 |= (1<<CR1_SPE);
}

u16  MSPI_u16Transceive(u16 Copy_u16Data)
{
	SPI1_REG->DR = Copy_u16Data ;

	while(GET_BIT(SPI1_REG->SR,SR_BSY)==1);

	return (u8) SPI1_REG->DR;
}

void SPI1_Callback(void (*ptr)(void))
{
	SPI1_CALLBACK_PTR = ptr;
}

void SPI1_IRQHandler(void)
{
	SPI1_CALLBACK_PTR();
}
