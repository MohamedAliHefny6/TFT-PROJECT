
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "STK_int.h"

#include "LCD.h"
#include "keypad_int.h"
#include "LEDMATRIX_int.h"
#include "Servo_Motor.h"

#include "MUART_int.h"
#include "MNVIC_int.h"

#include "SYS_INIT.h"
#include "MEXTI_int.h"

#define MEXTI0   6
#define MEXTI1   7
u8 arr;
u8 user;
u8 user70;
u8 motionsenser;
u8 flag_motion =0;


s32 entire ;
s32 space = 3 ;


u8 user1_flag = 0 ;
u8 user2_flag = 0 ;
u8 user3_flag = 0 ;


int main(void)
{

	SYS_INIT();



		EXTI_INIT();



		Servo1_Entry_Gate_Init();
		Servo2_Exit_Gate_Init();




		//MUSART2_voidTransmitChar('1');




while (1){



}




















}


void ENTER_GATE(void)
{
	user = UART_READ_DATA();
	if (entire >= 4 && space <= -1){

				LCD_Clear();
				MSTK_voidDelayMsec(200);
				LCD_SetCursor(0,0);
				LCD_WriteString("GARAGE IS FULL ");
				MNVIC_DisablePerInt(MEXTI0);

			}

if (user == user1 || user == user2 || user == user3)
{

if (user == user1 ){
	if( user1_flag ==0 )
	{
		MUSART_voidTransmitChar('1');
		ENTERY_LED_ON();
		EXIT_LED_OFF();

        entire ++;
	    space -- ;
		MNVIC_EnableInterrupt(MEXTI0);
		MEXTI_voidSetPortExtiCfg(EXTI_LINE0,PORTA);
		MEXTI_voidSetTriggerSource(EXTI_LINE0,ON_CHANGE);

		MSTK_voidDelayMsec(2000);
		LCD_Clear();
		MSTK_voidDelayMsec(200);
		LCD_SetCursor(0,0);
		LCD_WriteString("CARS : ");
		LCD_SetCursor(0,8);
		LCD_WriteNumber(entire);
		LCD_SetCursor(1,0);
		LCD_WriteString("FREE : ");
		LCD_SetCursor(1,8);
		LCD_WriteNumber(space);

	}
	if (user1_flag == 1)
	{

		LCD_Clear();
				MSTK_voidDelayMsec(200);
				LCD_SetCursor(0,0);
				LCD_WriteString("CARS INSIDE !");
				MNVIC_DisablePerInt(MEXTI0);
				MGPIO_SetPinValue(PORTB,PIN0,1);
				MSTK_voidDelayMsec(2000);
						LCD_Clear();
						MSTK_voidDelayMsec(200);
						LCD_SetCursor(0,0);
						LCD_WriteString("CARS : ");
						LCD_SetCursor(0,8);
						LCD_WriteNumber(entire);
						LCD_SetCursor(1,0);
						LCD_WriteString("FREE : ");
						LCD_SetCursor(1,8);
						LCD_WriteNumber(space);


	}
	user1_flag = 1;
}

if (user == user2 ){
	if( user2_flag ==0 )
	{
		MUSART_voidTransmitChar('1');
		ENTERY_LED_ON();
				EXIT_LED_OFF();

        entire ++;
	    space -- ;
		MNVIC_EnableInterrupt(MEXTI0);
		MEXTI_voidSetPortExtiCfg(EXTI_LINE0,PORTA);
		MEXTI_voidSetTriggerSource(EXTI_LINE0,ON_CHANGE);

		MSTK_voidDelayMsec(2000);
		LCD_Clear();
		MSTK_voidDelayMsec(200);
		LCD_SetCursor(0,0);
		LCD_WriteString("CARS : ");
		LCD_SetCursor(0,8);
		LCD_WriteNumber(entire);
		LCD_SetCursor(1,0);
		LCD_WriteString("FREE : ");
		LCD_SetCursor(1,8);
		LCD_WriteNumber(space);

	}
	if (user2_flag == 1)
	{

		LCD_Clear();
		MSTK_voidDelayMsec(200);
				LCD_SetCursor(0,0);
				LCD_WriteString("CARS INSIDE !");
				MNVIC_DisablePerInt(MEXTI0);
				MSTK_voidDelayMsec(2000);
						LCD_Clear();
						MSTK_voidDelayMsec(200);
						LCD_SetCursor(0,0);
						LCD_WriteString("CARS : ");
						LCD_SetCursor(0,8);
						LCD_WriteNumber(entire);
						LCD_SetCursor(1,0);
						LCD_WriteString("FREE : ");
						LCD_SetCursor(1,8);
						LCD_WriteNumber(space);



	}
	user2_flag = 1;
}

if (user == user3 ){
	if( user3_flag ==0 )
	{
		MUSART_voidTransmitChar('1');
		ENTERY_LED_ON();
				EXIT_LED_OFF();

        entire ++;
	    space -- ;
		MNVIC_EnableInterrupt(MEXTI0);
		MEXTI_voidSetPortExtiCfg(EXTI_LINE0,PORTA);
		MEXTI_voidSetTriggerSource(EXTI_LINE0,ON_CHANGE);

		MSTK_voidDelayMsec(2000);
		LCD_Clear();
		MSTK_voidDelayMsec(200);
		LCD_SetCursor(0,0);
		LCD_WriteString("CARS : ");
		LCD_SetCursor(0,8);
		LCD_WriteNumber(entire);
		LCD_SetCursor(1,0);
		LCD_WriteString("FREE : ");
		LCD_SetCursor(1,8);
		LCD_WriteNumber(space);
	}
	if (user3_flag == 1)
	{

		LCD_Clear();
				MSTK_voidDelayMsec(200);
				LCD_SetCursor(0,0);
				LCD_WriteString("CARS INSIDE !");
				MNVIC_DisablePerInt(MEXTI0);
				MSTK_voidDelayMsec(2000);
						LCD_Clear();
						MSTK_voidDelayMsec(200);
						LCD_SetCursor(0,0);
						LCD_WriteString("CARS : ");
						LCD_SetCursor(0,8);
						LCD_WriteNumber(entire);
						LCD_SetCursor(1,0);
						LCD_WriteString("FREE : ");
						LCD_SetCursor(1,8);
						LCD_WriteNumber(space);
	}
	user3_flag = 1;
}


}



if (user != user1 && user != user2 && user != user3)
{
		LCD_Clear();
		MSTK_voidDelayMsec(200);
		LCD_SetCursor(0,0);
		LCD_WriteString("WRONG PASSWORD");
		MSTK_voidDelayMsec(2000);
				LCD_Clear();
				MSTK_voidDelayMsec(200);
				LCD_SetCursor(0,0);
				LCD_WriteString("CARS : ");
				LCD_SetCursor(0,8);
				LCD_WriteNumber(entire);
				LCD_SetCursor(1,0);
				LCD_WriteString("FREE : ");
				LCD_SetCursor(1,8);
				LCD_WriteNumber(space);
}


}









void SERVO_ENTER(void){
Servo1_Entry_Gate(MGPIO_voidGetPinValue(PORTB,PIN10));
MGPIO_TogglePinValue(PORTB,PIN10);


}


void EXIT_GATE (void)
{
	user70 = UART2_READ_DATA();


	if (user70 == user1 || user70 == user2 || user70 == user3)
	{

	if (user70 == user1 ){

		if( user1_flag == 1 )
		{
			MUSART_voidTransmitChar('1');
			ENTERY_LED_OFF();
			EXIT_LED_ON();
	        entire --;
		    space ++ ;
			MNVIC_EnableInterrupt(MEXTI1);
			MEXTI_voidSetPortExtiCfg(EXTI_LINE1,PORTA);
			MEXTI_voidSetTriggerSource(EXTI_LINE1,ON_CHANGE);

			MSTK_voidDelayMsec(2000);
			LCD_Clear();
			MSTK_voidDelayMsec(200);
			LCD_SetCursor(0,0);
			LCD_WriteString("CARS : ");
			LCD_SetCursor(0,8);
			LCD_WriteNumber(entire);
			LCD_SetCursor(1,0);
			LCD_WriteString("FREE : ");
			LCD_SetCursor(1,8);
			LCD_WriteNumber(space);

		}
		if (user1_flag == 0)
		{

			LCD_Clear();
					MSTK_voidDelayMsec(200);
					LCD_SetCursor(0,0);
					LCD_WriteString("CAR NOT HERE !");
					MNVIC_DisablePerInt(MEXTI1);

					MSTK_voidDelayMsec(2000);
							LCD_Clear();
							MSTK_voidDelayMsec(200);
							LCD_SetCursor(0,0);
							LCD_WriteString("CARS : ");
							LCD_SetCursor(0,8);
							LCD_WriteNumber(entire);
							LCD_SetCursor(1,0);
							LCD_WriteString("FREE : ");
							LCD_SetCursor(1,8);
							LCD_WriteNumber(space);


		}
		user1_flag = 0;
	}

	if (user70 == user2 ){

		if( user2_flag ==1 )
		{
			MUSART_voidTransmitChar('1');
			ENTERY_LED_OFF();
						EXIT_LED_ON();

	        entire --;
		    space ++ ;
			MNVIC_EnableInterrupt(MEXTI1);
			MEXTI_voidSetPortExtiCfg(EXTI_LINE1,PORTA);
			MEXTI_voidSetTriggerSource(EXTI_LINE1,ON_CHANGE);

			MSTK_voidDelayMsec(2000);
			LCD_Clear();
			MSTK_voidDelayMsec(200);
			LCD_SetCursor(0,0);
			LCD_WriteString("CARS : ");
			LCD_SetCursor(0,8);
			LCD_WriteNumber(entire);
			LCD_SetCursor(1,0);
			LCD_WriteString("FREE : ");
			LCD_SetCursor(1,8);
			LCD_WriteNumber(space);

		}
		if (user2_flag == 0)
		{

			LCD_Clear();
			MSTK_voidDelayMsec(200);
					LCD_SetCursor(0,0);
					LCD_WriteString("CAR NOT HERE !");
					MNVIC_DisablePerInt(MEXTI1);
					MSTK_voidDelayMsec(2000);
							LCD_Clear();
							MSTK_voidDelayMsec(200);
							LCD_SetCursor(0,0);
							LCD_WriteString("CARS : ");
							LCD_SetCursor(0,8);
							LCD_WriteNumber(entire);
							LCD_SetCursor(1,0);
							LCD_WriteString("FREE : ");
							LCD_SetCursor(1,8);
							LCD_WriteNumber(space);



		}
		user2_flag = 0;
	}

	if (user70 == user3 ){

		if( user3_flag ==1 )
		{
			MUSART_voidTransmitChar('1');
			ENTERY_LED_OFF();
						EXIT_LED_ON();

	        entire --;
		    space ++ ;
			MNVIC_EnableInterrupt(MEXTI1);
			MEXTI_voidSetPortExtiCfg(EXTI_LINE1,PORTA);
			MEXTI_voidSetTriggerSource(EXTI_LINE1,ON_CHANGE);

			MSTK_voidDelayMsec(1500);
			LCD_Clear();
			MSTK_voidDelayMsec(200);
			LCD_SetCursor(0,0);
			LCD_WriteString("CARS : ");
			LCD_SetCursor(0,8);
			LCD_WriteNumber(entire);
			LCD_SetCursor(1,0);
			LCD_WriteString("FREE : ");
			LCD_SetCursor(1,8);
			LCD_WriteNumber(space);
		}
		if (user3_flag == 0)
		{

			LCD_Clear();
					MSTK_voidDelayMsec(200);
					LCD_SetCursor(0,0);
					LCD_WriteString("CAR NOT HERE !");
					MNVIC_DisablePerInt(MEXTI1);
					MSTK_voidDelayMsec(2000);
							LCD_Clear();
							MSTK_voidDelayMsec(200);
							LCD_SetCursor(0,0);
							LCD_WriteString("CARS : ");
							LCD_SetCursor(0,8);
							LCD_WriteNumber(entire);
							LCD_SetCursor(1,0);
							LCD_WriteString("FREE : ");
							LCD_SetCursor(1,8);
							LCD_WriteNumber(space);
		}
		user3_flag = 0;
	}


	}



	if (user70 != user1 && user70 != user2 && user70 != user3)
	{
			LCD_Clear();
			MSTK_voidDelayMsec(200);
			LCD_SetCursor(0,0);
			LCD_WriteString("WRONG PASSWORD");
			MSTK_voidDelayMsec(2000);
					LCD_Clear();
					MSTK_voidDelayMsec(200);
					LCD_SetCursor(0,0);
					LCD_WriteString("CARS : ");
					LCD_SetCursor(0,8);
					LCD_WriteNumber(entire);
					LCD_SetCursor(1,0);
					LCD_WriteString("FREE : ");
					LCD_SetCursor(1,8);
					LCD_WriteNumber(space);
	}


}

void SERVO_EXIT (void)
{
	Servo2_Exit_Gate(MGPIO_voidGetPinValue(PORTB,PIN0));
	MGPIO_TogglePinValue(PORTB,PIN0);

}


