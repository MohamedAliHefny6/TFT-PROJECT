/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : RCC		 				******/
/*********************************************************/

#ifndef MRCC_PRV_H
#define MRCC_PRV_H


/* Base Address of RCC */
#define   RCC_BASE_ADDRESS    (0x40023800)


/*Structure representing the GPIO register map*/
typedef struct
{
	u32 CR;             /* Clock control register */
	u32 PLLCFGR;        /* PLL configuration register */
	u32 CFGR;           /* Clock configuration register */
	u32 CIR;            /* Clock interrupt register */
	u32 AHB1RSTR;       /* AHB1 peripheral reset register */
	u32 AHB2RSTR;       /* AHB2 peripheral reset register */
	u32 reserved0;
	u32 reserved1;
	u32 APB1RSTR;       /* APB1 peripheral reset register */
	u32 APB2RSTR;       /* APB2 peripheral reset register */
	u32 reserved2;
	u32 reserved3;
	u32 AHB1ENR;        /* AHB1 peripheral clock enable register */
	u32 AHB2ENR;        /* AHB2 peripheral clock enable register */
	u32 reserved4;
	u32 reserved5;
	u32 APB1ENR;        /* APB1 peripheral clock enable register */
	u32 APB2ENR;        /* APB2 peripheral clock enable register */
	u32 reserved6;
	u32 reserved7;
	u32 AHB1LPENR;      /* AHB1 peripheral clock enable in low power mode register */
	u32 AHB2LPENR;      /* AHB2 peripheral clock enable in low power mode register */
	u32 reserved8;
	u32 reserved9;
	u32 APB1LPENR;      /* APB1 peripheral clock enable in low power mode register */
	u32 APB2LPENR;      /* APB2 peripheral clock enable in low power mode register */
	u32 reserved10;
	u32 reserved11;
	u32 BDCR;           /* Backup domain control register */
	u32 CSR;            /* Control/status register */
	u32 reserved12;
	u32 reserved13;
	u32 SSCGR;          /* Spread spectrum clock generation register */
	u32 PLLI2SCFGR;     /* PLLI2S configuration register */
	u32 reserved14;
	u32 DCKCFGR;        /* Dedicated Clocks Configuration Register */
}RCC_t;


#define   RCC        ((volatile RCC_t*)RCC_BASE_ADDRESS)


/*Clock Source Options*/
#define   RCC_HSI              0
#define   RCC_HSE              1
#define   RCC_PLL              3

/*HSE Crystal oscillator or RC*/
#define   HSE_CRY              0
#define   HSE_RC               1

/*HSI or HSE Clock source*/
#define   HSI_CLS_SRC          0
#define   HSE_CLS_SRC          1


/*RCC_CR Register*/
#define   CR_HSION             0
#define   CR_HSIRDY            1
#define   CR_HSEON             16
#define   CR_HSERDY            17
#define   CR_HSEBYP            18
#define   CR_CSSON             19
#define   CR_PLLON             24
#define   CR_PLLRDY            25
#define   CR_PLLI2SON          26
#define   CR_PLLI2SRDY         27

/*RCC_PLLCFGR Register*/
#define   PLLCFGR_PLLSRC       22

/*RCC_CFGR Register*/
#define   CFGR_SW0             0
#define   CFGR_SW1             1
#define   CFGR_SWS0            2
#define   CFGR_SWS1            3
#define   CFGR_I2SSCR          23
#define   CFGR_HPRE0           4
#define   CFGR_HPRE1           5
#define   CFGR_HPRE2           6
#define   CFGR_HPRE3           7

/*RCC_CIR Register*/
#define   CIR_LSIRDYIE         8
#define   CIR_LSERDYIE         9
#define   CIR_HSIRDYIE         10
#define   CIR_HSERDYIE         11
#define   CIR_PLLRDYIE         12
#define   CIR_PLL2SRDYIE       13
#define   CIR_LSIRDYC          16
#define   CIR_LSERDYC          17
#define   CIR_HSIRDYC          18
#define   CIR_HSERDYC          19
#define   CIR_PLLRDYC          20
#define   CIR_PLLI2SRDYC       21
#define   CIR_CSSC             23







#endif
