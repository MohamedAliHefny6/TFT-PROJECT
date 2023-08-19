/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : RCC		 				******/
/*********************************************************/

/*LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*RCC*/
#include "MRCC_int.h"
#include "MRCC_prv.h"
#include "MRCC_cfg.h"


/*Function to choose System Clock*/
void MRCC_voidInitSysClk(void)
{
	/*Enable HSE*/
#if RCC_SYS_CLK == RCC_HSE

#if HSE_BYP == HSE_CRY
	/*Disable Bypass*/
	RCC->CR &= ~(1<<CR_HSEBYP);

#elif HSE_BYP == HSE_RC
	/*Enable Bypass*/
	RCC->CR |= (1<<CR_HSEBYP);

#endif

	RCC->CR |= 1<<CR_HSEON;
	while(!GET_BIT(RCC->CR,CR_HSEON+1));

	/*SW clock = HSE -> 01*/
	RCC->CFGR |= (1<<CFGR_SW0);
	RCC->CFGR &= ~(1<<CFGR_SW1);


	/*Enable HSI*/
#elif RCC_SYS_CLK == RCC_HSI
	RCC->CR |= 1<<CR_HSION;
	/*Check the flag*/
	while(!GET_BIT(RCC->CR,CR_HSION+1));

	/*SW clock = HSI -> 00*/
	RCC->CFGR &= ~(1<<CFGR_SW0);
	RCC->CFGR &= ~(1<<CFGR_SW1);


	/*Select PLL source*/
#elif RCC_SYS_CLK == RCC_PLL

#if PLL_SRC == HSE_CLS_SRC
	RCC->PLLCFGR |= 1<<PLLCFGR_PLLSRC;

#elif PLL_SRC == HSI_CLS_SRC
	RCC->PLLCFGR &= ~(1<<PLLCFGR_PLLSRC);

#endif

	/*Enable PLL*/
	RCC->CR |= 1<<CR_PLLON;
	/*Check the flag*/
	while(!GET_BIT(RCC->CR,CR_PLLON+1));

	/*SW clock = HSE -> 01*/
	RCC->CFGR &= ~(1<<CFGR_SW0);
	RCC->CFGR |= (1<<CFGR_SW1);

#else
       /*DO NOTHING*/
#endif


	/* AHP Prescaler: no division,/2,/4,/8/16,/64,/128,/256,/512 */
#if AHP_PRESCALER == PRESCALER_NOT_DIV
	RCC->CFGR &= ~(1<<CFGR_HPRE0);
	RCC->CFGR &= ~(1<<CFGR_HPRE1);
	RCC->CFGR &= ~(1<<CFGR_HPRE2);
	RCC->CFGR &= ~(1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_2
	RCC->CFGR &= ~(1<<CFGR_HPRE0);
	RCC->CFGR &= ~(1<<CFGR_HPRE1);
	RCC->CFGR &= ~(1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_4
	RCC->CFGR |= (1<<CFGR_HPRE0);
	RCC->CFGR &= ~(1<<CFGR_HPRE1);
	RCC->CFGR &= ~(1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_8
	RCC->CFGR &= ~(1<<CFGR_HPRE0);
	RCC->CFGR |= (1<<CFGR_HPRE1);
	RCC->CFGR &= ~(1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_16
	RCC->CFGR |= (1<<CFGR_HPRE0);
	RCC->CFGR |= (1<<CFGR_HPRE1);
	RCC->CFGR &= ~(1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_64
	RCC->CFGR &= ~(1<<CFGR_HPRE0);
	RCC->CFGR &= ~(1<<CFGR_HPRE1);
	RCC->CFGR |= (1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_128
	RCC->CFGR |= (1<<CFGR_HPRE0);
	RCC->CFGR &= ~(1<<CFGR_HPRE1);
	RCC->CFGR |= (1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_256
	RCC->CFGR &= ~(1<<CFGR_HPRE0);
	RCC->CFGR |= (1<<CFGR_HPRE1);
	RCC->CFGR |= (1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#elif AHP_PRESCALER == PRESCALER_DIV_512
	RCC->CFGR |= (1<<CFGR_HPRE0);
	RCC->CFGR |= (1<<CFGR_HPRE1);
	RCC->CFGR |= (1<<CFGR_HPRE2);
	RCC->CFGR |= (1<<CFGR_HPRE3);

#else

#endif
}

/************************************************************************************************/

/*Function To Enable Peripheral AHB1,AHB2,ABP1,ABP2,AHB1L Buses*/
void MRCC_voidEnable_Peripheral(u8 BusId, u8 PeripheralId)
{
	switch(BusId)
	{
	case RCC_AHB1:

		/*Enable peripheral on AHB1*/
		RCC->AHB1ENR |= (1<<PeripheralId);
		break;

		/*Enable peripheral on AHB2*/
	case RCC_AHB2:
		RCC->AHB2ENR |= (1<<PeripheralId);
		break;

		/*Enable peripheral on APB1*/
	case RCC_APB1:
		RCC->APB1ENR |= (1<<PeripheralId);
		break;

		/*Enable peripheral on APB2*/
	case RCC_APB2:
		RCC->APB2ENR |= (1<<PeripheralId);
		break;

		/*Enable peripheral on AHB1L*/
	case RCC_AHP1L:
		RCC->AHB1LPENR |= (1<<PeripheralId);
		break;

	default:
		/*Invalid Bus*/
		break;
	}
}

/************************************************************************************************/

/*Function To Disable Peripheral AHB1,AHB2,ABP1,ABP2,AHB1L Buses*/
void MRCC_voidDisable_Peripheral(u8 BusId, u8 PeripheralId)
{
	switch(BusId)
	{
	    /*Disable peripheral on AHB1*/
	case RCC_AHB1:

		RCC->AHB1ENR &= ~(1<<PeripheralId);
		break;

		/*Disable peripheral on AHB2*/
	case RCC_AHB2:
		RCC->AHB2ENR &= ~(1<<PeripheralId);
		break;

		/*Disable peripheral on APB1*/
	case RCC_APB1:
		RCC->APB1ENR &= ~(1<<PeripheralId);
		break;

		/*Disable peripheral on APB2*/
	case RCC_APB2:
		RCC->APB2ENR &= ~(1<<PeripheralId);
		break;

		/*Disable peripheral on AHB1L*/
	case RCC_AHP1L:
		RCC->AHB1LPENR &= ~(1<<PeripheralId);
		break;

	default:
		/*Invalid Bus*/
		break;
	}
}
