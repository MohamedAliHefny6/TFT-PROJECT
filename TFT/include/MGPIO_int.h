#ifndef MGPIO_INT_H
#define MGPIO_INT_H


/*       Port Macros         */
#define   PORTA    0
#define   PORTB    1
#define   PORTC    2


/*       Pin Macros         */
#define   PIN0     0
#define   PIN1     1
#define   PIN2     2
#define   PIN3     3
#define   PIN4     4
#define   PIN5     5
#define   PIN6     6
#define   PIN7     7
#define   PIN8     8
#define   PIN9     9
#define   PIN10    10
#define   PIN11    11
#define   PIN12    12
#define   PIN13    13
#define   PIN14    14
#define   PIN15    15


/*********** Mode Macros *************/
#define   INPUT       0
#define   OUTPUT      1
#define   ALT_FUNC    2
#define   ANALOG      3


/*********** OUTPUT Mode Macros *************/
#define   OUTPUT_PUSH_PULL     0
#define   OUTPUT_OPEN_DRAIN    1


/************ OUTPUT Speed Macros ***********/
#define   OUTPUT_LOW         0
#define   OUTPUT_MEDIUM      1
#define   OUTPUT_HIGH        2
#define   OUTPUT_VHIGH       3


/*********** INPUT Mode Macros *************/
#define   INPUT_FLOAT        0
#define   INPUT_PULLUP       1
#define   INPUT_PULLDOWN     2


/*********** OUTPUT STATE **************/
#define   PIN_LOW            0
#define   PIN_HIGH           1


/*********** ALTERNATIVE FUNC ************/
#define   AF0_SYSTEM                  0
#define   AF1_TIM1_TIM2               1
#define   AF2_TIM3_TO_TIM5            2
#define   AF3_TIM9_TO_TIM11           3
#define   AF4_I2C1_TO_I2C3            4
#define   AF5_SPI1_TO_SPI4            5
#define   AF6_SPI3                    6
#define   AF7_USART1_USART2           7
#define   AF8_USART6                  8
#define   AF9_I2C2_I2C3               9
#define   AF10_OTG_FS                 10
#define   AF11                        11
#define   AF12_SDIO                   12
#define   AF13                        13
#define   AF14                        14
#define   AF15_EVENTOUT               15



void MGPIO_SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);

void MGPIO_SetOutputPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8OutMode, u8 Copy_u8Speed);

void MGPIO_SetPinAlterFunc(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Alt);

void MGPIO_SetInputPin(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InMode);

void MGPIO_GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_pu8Data);

void MGPIO_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_pu8Data);

void MGPIO_TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void MGPIO_BSRR_SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void MGPIO_BSRR_ResetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 MGPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);



#endif

