/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : RCC		 				******/
/*********************************************************/

#ifndef MRCC_CFG_H
#define MRCC_CFG_H



/*
 * options:   RCC_HSE  or  RCC_HSI  or  RCC_PLL
 */
#define    RCC_SYS_CLK      RCC_HSE


/*
 * options:   Prescaler (0,/2,/4,/8,/16,/64,/128,/256,/512)
 */
#define    AHP_PRESCALER   PRESCALER_NOT_DIV



/*
 * options:   HSE_CRY  or  HSE_RC
 */
#define    HSE_BYP         HSE_CRY

/*
 * options:   HSE_CLS_SRC  or  HSI_CLS_SRC
 */
#define    PLL_SRC        HSE_CLS_SRC






#endif
