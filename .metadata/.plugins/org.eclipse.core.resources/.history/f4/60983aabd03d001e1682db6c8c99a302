/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : SYSTICK					******/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_int.h"
#include "STK_prv.h"
#include "STK_cfg.h"

/* Global callback function pointer for SysTick */
static void (*GlobalSTK_Callback)(void)=NULL;
/* Global single flag */
static u8   Global_u8SingleFlag;


/*Initialize the SysTick timer*/
void MSTK_voidInit(void)
{
	/* Set clock source */
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(MSTK_REG->CTRL,CLKSOURCE);

#elif STK_CLK_SOURCE == STK_AHB_DIV_8
	CLR_BIT(MSTK_REG->CTRL,CLKSOURCE);

#else

#endif
}

/***********************************************************************************************/

/*Enable or disable the SysTick interrupt*/
void MSTK_voidIntState(u8 Copy_u8IntState)
{
	/* Interrupt enable or disable*/
	if(Copy_u8IntState == MSTK_INT_ENABLE)
	{
		SET_BIT(MSTK_REG->CTRL,TICKINT);
	}
	else if(Copy_u8IntState == MSTK_INT_DISABLE)
	{
		CLR_BIT(MSTK_REG->CTRL,TICKINT);

	}
}

/***********************************************************************************************/

/*Start the SysTick timer with the given ticks value*/
void MSTK_voidStart(u32 Copy_u8TicksValue)
{
	/* Clearing VAL register */
	MSTK_REG->VAL = 0;

	/* Load value in LOAD register */
	MSTK_REG->LOAD = Copy_u8TicksValue;

	/* Enable the Systick Counter */
	SET_BIT(MSTK_REG->CTRL,STK_ENABLE);
}

/***********************************************************************************************/

/*Read the SysTick flag indicating if the timer has reached zero*/
u8 MSTK_u8ReadFlag(void)
{
	/* Reading the flag */
	return (GET_BIT(MSTK_REG->CTRL,COUNTFLAG));
}

/***********************************************************************************************/

/*Delay the execution for the specified number of microseconds*/
void MSTK_voidDelayUsec(u32 Copy_u8DelayUsec)
{
	/* Check if the delay is greater than or equal to 2 microseconds */
	if (Copy_u8DelayUsec >= 2)
	{
		/* Disable the SysTick interrupt */
		MSTK_voidIntState(MSTK_INT_DISABLE);

		/* Set the preload value in the LOAD register by multiplying the delay by 2 */
		MSTK_voidStart(Copy_u8DelayUsec * 2);

		/* Wait until the delay passed by checking the COUNTFLAG */
		while (MSTK_u8ReadFlag() == 0);
	}
}

/***********************************************************************************************/

/*Delay the execution for the specified number of milliseconds*/
void MSTK_voidDelayMsec(u32 Copy_u8DelayMsec)
{
	/* Disable the SysTick interrupt */
	MSTK_voidIntState(MSTK_INT_DISABLE);

	/* Set the preload value in the LOAD register by multiplying the delay by 2000 */
	MSTK_voidStart(Copy_u8DelayMsec * 2000);

	/* Wait until the delay passed by checking the COUNTFLAG */
	while (MSTK_u8ReadFlag() == 0);
}

/***********************************************************************************************/

/*Set an interval for a single execution of an action after a specified number of ticks*/
void MSTK_voidSetInterval_single(u32 Copy_u8TicksValue, void (*CallbackFunc)(void))
{
	/*Set callback function*/
	GlobalSTK_Callback = CallbackFunc;

	/*Set single flag*/
	Global_u8SingleFlag=1;

	/*Clearing VAL register*/
	MSTK_REG->VAL = 0;

	/*Load value in LOAD register*/
	MSTK_REG->LOAD = Copy_u8TicksValue;

	/*Enable the Systick Counter*/
	SET_BIT(MSTK_REG->CTRL,STK_ENABLE);
}

/***********************************************************************************************/

/*Set an interval for periodic execution of an action with a specified interval in ticks*/
void MSTK_voidSetInterval_Periodic(u32 Copy_u8TicksValue, void (*CallbackFunc)(void))
{
	/*Set callback function*/
	GlobalSTK_Callback = CallbackFunc;

	/*Clear single flag*/
	Global_u8SingleFlag=0;

	/*Clearing VAL register*/
	MSTK_REG->VAL = 0;

	/*Load value in LOAD register*/
	MSTK_REG->LOAD = Copy_u8TicksValue;

	/*Enable the Systick Counter*/
	SET_BIT(MSTK_REG->CTRL,STK_ENABLE);
}

/***********************************************************************************************/

/*Get the elapsed time in ticks since the last timer start*/
u32  MSTK_u32GetElapsedTime(void)
{
	/* Calculating the Elapsed time */
	return ((MSTK_REG->LOAD)-(MSTK_REG->VAL)) ;
}

/***********************************************************************************************/

/*Get the remaining time in ticks until the next action execution*/
u32  MSTK_u32GetRemainingTime(void)
{
	/* Calculating the Remaining time */
	return MSTK_REG->VAL ;
}

/******************************** ISR for SYSTICK Timer ****************************************/

/*SysTick interrupt handler*/
void Systick_Handler(void)
{
	if(GlobalSTK_Callback != NULL)
	{
		GlobalSTK_Callback();
	}
	if(Global_u8SingleFlag)
	{
		Global_u8SingleFlag = 0 ;
		/* Stop the timer */
		CLR_BIT(MSTK_REG->CTRL,STK_ENABLE);
	}
}
/******************************** Disable SYSTICK Timer ****************************************/

void Systick_Disable(void){
	CLR_BIT( MSTK_REG-> CTRL , STK_ENABLE);
}