/*********************************************************/
/******				ARM_Project  				    ******/
/******				SWC : SYSTICK					******/
/*********************************************************/

#ifndef STK_PRV_H
#define STK_PRV_H


/* Base address of Systick timer */
#define   MSTK_BASE_ADDRESS     (0xE000E010)


/* Structure representing the STK register map */
typedef struct
{
	u32 CTRL;       /* SysTick Control and Status Register */
	u32 LOAD;       /* SysTick Reload Value Register */
	u32 VAL;        /* SysTick Current Value Register */
	u32 CALIB;      /* SysTick Calibration Value Register */
}STK_t;


#define   MSTK_REG              ((volatile STK_t*)(MSTK_BASE_ADDRESS))


/* Sysrick Control and Status Register */
#define STK_ENABLE  0
#define TICKINT		1
#define CLKSOURCE	2
#define COUNTFLAG	16



#endif
