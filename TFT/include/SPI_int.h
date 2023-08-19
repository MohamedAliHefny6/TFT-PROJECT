#ifndef SPI_INT_H_
#define SPI_INT_H_


/*DATA FORMAT*/
#define DATA_8_BIT        0
#define DATA_16_BIT       1


/*BAUD RATE*/
#define SPI_CLK_2         0
#define SPI_CLK_4         1
#define SPI_CLK_8         2
#define SPI_CLK_16        3
#define SPI_CLK_32        4
#define SPI_CLK_64        5
#define SPI_CLK_128       6
#define SPI_CLK_256       7


/*MASTER OR SLAVE*/
#define SPI_MASTER        1
#define SPI_SLAVE         0


/*MSB OR LSB*/
#define SPI_MSB_FIRST     0
#define SPI_LSB_FIRST     1



void MSPI_voidInit(void);

u16  MSPI_u16Transceive(u16 Copy_u16Data);

void SPI1_Callback(void (*ptr)(void));






#endif
