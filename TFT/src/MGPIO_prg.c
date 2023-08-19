#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_int.h"
#include "MGPIO_prv.h"
#include "MGPIO_cfg.h"


void MGPIO_SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode)
{
	/* Check for forbidden pins PA13 PA14 PA15 PB3 PB4 PB5 */



		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOA->MODER |= Copy_u8Mode<<(Copy_u8Pin*2);
			break;
		case PORTB:
			GPIOB->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOB->MODER |= Copy_u8Mode<<(Copy_u8Pin*2);
			break;
		case PORTC:
			GPIOC->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOC->MODER |= Copy_u8Mode<<(Copy_u8Pin*2);
			break;
		default:
			/* Do nothing */
			break;
		}

}

void MGPIO_SetPinAlterFunc(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Alt)
{
	if(Copy_u8Pin <= 7)
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->AFRL |= Copy_u8Alt<<(Copy_u8Pin*4);
			break;
		case PORTB:
			GPIOB->AFRL |= Copy_u8Alt<<(Copy_u8Pin*4);
			break;
		case PORTC:
			GPIOC->AFRL |= Copy_u8Alt<<(Copy_u8Pin*4);
			break;
		default:
			/* Do nothing */
			break;
		}
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->AFRH |= Copy_u8Alt<<((Copy_u8Pin%8)*4);
			break;
		case PORTB:
			GPIOB->AFRH |= Copy_u8Alt<<((Copy_u8Pin%8)*4);
			break;
		case PORTC:
			GPIOC->AFRH |= Copy_u8Alt<<((Copy_u8Pin%8)*4);
			break;
		default:
			/* Do nothing */
			break;
		}
	}
}

void MGPIO_SetOutputPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutMode, u8 Copy_u8Speed)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->OTYPER &= ~(1<<(Copy_u8Pin));
		GPIOA->OTYPER |= Copy_u8OutMode<<(Copy_u8Pin);
		GPIOA->OSPEEDR &= ~(GPIO_SPEED_MASK<<(Copy_u8Pin*2));
		GPIOA->OSPEEDR |= Copy_u8Speed<<(Copy_u8Pin*2);
		break;
	case PORTB:
		GPIOB->OTYPER &= ~(1<<(Copy_u8Pin));
		GPIOB->OTYPER |= Copy_u8OutMode<<(Copy_u8Pin);
		GPIOB->OSPEEDR &= ~(GPIO_SPEED_MASK<<(Copy_u8Pin*2));
		GPIOB->OSPEEDR |= Copy_u8Speed<<(Copy_u8Pin*2);
		break;
	case PORTC:
		GPIOC->OTYPER &= ~(1<<(Copy_u8Pin));
		GPIOC->OTYPER |= Copy_u8OutMode<<(Copy_u8Pin);
		GPIOC->OSPEEDR &= ~(GPIO_SPEED_MASK<<(Copy_u8Pin*2));
		GPIOC->OSPEEDR |= Copy_u8Speed<<(Copy_u8Pin*2);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void MGPIO_SetInputPin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InMode)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->PUPDR &= ~(GPIO_PUPDR_MASK<<(Copy_u8Pin*2));
		GPIOA->PUPDR |= Copy_u8InMode<<(Copy_u8Pin*2);
		break;
	case PORTB:
		GPIOB->PUPDR &= ~(GPIO_PUPDR_MASK<<(Copy_u8Pin*2));
		GPIOB->PUPDR |= Copy_u8InMode<<(Copy_u8Pin*2);
		break;
	case PORTC:
		GPIOC->PUPDR &= ~(GPIO_PUPDR_MASK<<(Copy_u8Pin*2));
		GPIOC->PUPDR |= Copy_u8InMode<<(Copy_u8Pin*2);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void MGPIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Data)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		*Copy_pu8Data = ((GPIOA->IDR) >> Copy_u8Pin) & 1;
		break;
	case PORTB:
		*Copy_pu8Data = ((GPIOB->IDR) >> Copy_u8Pin) & 1;
		break;
	case PORTC:
		*Copy_pu8Data = ((GPIOC->IDR) >> Copy_u8Pin) & 1;
		break;
	default:
		/* Do nothing */
		break;
	}
}

void MGPIO_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_pu8Data)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->ODR &= ~(1<<(Copy_u8Pin));
		GPIOA->ODR |= Copy_pu8Data<<(Copy_u8Pin);
		break;
	case PORTB:
		GPIOB->ODR &= ~(1<<(Copy_u8Pin));
		GPIOB->ODR |= Copy_pu8Data<<(Copy_u8Pin);
		break;
	case PORTC:
		GPIOC->ODR &= ~(1<<(Copy_u8Pin));
		GPIOC->ODR |= Copy_pu8Data<<(Copy_u8Pin);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void MGPIO_TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->ODR &= ~(1<<(Copy_u8Pin));
		TOG_BIT(GPIOA->ODR,Copy_u8Pin);
		break;
	case PORTB:
		GPIOB->ODR &= ~(1<<(Copy_u8Pin));
		TOG_BIT(GPIOA->ODR,Copy_u8Pin);
		break;
	case PORTC:
		GPIOC->ODR &= ~(1<<(Copy_u8Pin));
		TOG_BIT(GPIOA->ODR,Copy_u8Pin);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void MGPIO_BSRR_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->BSRR |= 1<<(Copy_u8Pin);
		break;
	case PORTB:
		GPIOB->BSRR |= 1<<(Copy_u8Pin);
		break;
	case PORTC:
		GPIOC->BSRR |= 1<<(Copy_u8Pin);
		break;
	default:
		/* Do nothing */
		break;
	}
}

void MGPIO_BSRR_ResetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		GPIOA->BSRR &= ~(1<<(Copy_u8Pin+16));
		break;
	case PORTB:
		GPIOB->BSRR &= ~(1<<(Copy_u8Pin+16));
		break;
	case PORTC:
		GPIOC->BSRR &= ~(1<<(Copy_u8Pin+16));
		break;
	default:
		/* Do nothing */
		break;
	}
}




/*Function to get the pin value*/
u8 MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Result;
	switch(Copy_u8Port)
	{
	case PORTA:
		Result = ((GPIOA->IDR) >> Copy_u8Pin) & 1;     /*Get the pin value*/
		break;
	case PORTB:
		Result = ((GPIOB->IDR) >> Copy_u8Pin) & 1;     /*Get the pin value*/
		break;
	case PORTC:
		Result = ((GPIOC->IDR) >> Copy_u8Pin) & 1;     /*Get the pin value*/
		break;
	default:
		/* DO NOTHING */
		break;

	}
	return Result;
}


