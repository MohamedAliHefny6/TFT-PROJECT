#ifndef SPI_PRV_H_
#define SPI_PRV_H_



#define   SPI1_BASE_ADDRESS      (0x40013000)
#define   SPI2_BASE_ADDRESS      (0x40003800)
#define   SPI3_BASE_ADDRESS      (0x40003C00)
#define   SPI4_BASE_ADDRESS      (0x40013400)


typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR ;
}SPI_t;


#define   SPI1_REG         ((volatile SPI_t*)SPI1_BASE_ADDRESS)

#define   SPI2_REG         ((volatile SPI_t*)SPI2_BASE_ADDRESS)

#define   SPI3_REG         ((volatile SPI_t*)SPI3_BASE_ADDRESS)

#define   SPI4_REG         ((volatile SPI_t*)SPI4_BASE_ADDRESS)



#define CR1_CPHA          0
#define CR1_CPOL          1
#define CR1_MSTR          2
#define CR1_BR0           3
#define CR1_BR1           4
#define CR1_BR2           5
#define CR1_SPE           6
#define CR1_LSB_FIRST     7
#define CR1_SSI           8
#define CR1_SSM           9
#define CR1_RXONLY        10
#define CR1_DFF           11
#define CR1_CRCNEXT       12
#define CR1_CRCEN         13
#define CR1_BIDIOE        14
#define CR1_BIDIMODE      15


#define CR2_RXDMAEN       0
#define CR2_TXDMAEN       1
#define CR2_SSOE          2
#define CR2_FRF           4
#define CR2_ERRIE         5
#define CR2_RXNEIE        6
#define CR2_TXNEIE        7


#define SR_RXNE           0
#define SR_TXE            1
#define SR_CHSIDE         2
#define SR_UDR            3
#define SR_CRCERR         4
#define SR_MODF           5
#define SR_OVR            6
#define SR_BSY            7
#define SR_FRE            8


#define I2SCFGR_CHLEN       0
#define I2SCFGR_DATLEN0     1
#define I2SCFGR_DATLEN1     2
#define I2SCFGR_CKPOL       3
#define I2SCFGR_I2SSTD0     4
#define I2SCFGR_I2SSTD1     5
#define I2SCFGR_PCMSYNC     7
#define I2SCFGR_I2SCFG0     8
#define I2SCFGR_I2SCFG1     9
#define I2SCFGR_I2SE        10
#define I2SCFGR_I2SMOD      11


#define I2SPR_ODD           8
#define I2SPR_MCKOE         9




#endif
