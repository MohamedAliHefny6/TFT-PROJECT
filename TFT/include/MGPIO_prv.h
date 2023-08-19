#ifndef MGPIO_PRV_H
#define MGPIO_PRV_H



#define   GPIOA_BASE_ADDRESS     (0x40020000)

#define   GPIOB_BASE_ADDRESS     (0x40020400)

#define   GPIOC_BASE_ADDRESS     (0x40020800)

typedef struct
{
	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDR;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;
}GPIOx_t;


#define   GPIOA        ((volatile GPIOx_t*)GPIOA_BASE_ADDRESS)

#define   GPIOB        ((volatile GPIOx_t*)GPIOB_BASE_ADDRESS)

#define   GPIOC        ((volatile GPIOx_t*)GPIOC_BASE_ADDRESS)


#define   GPIO_MODE_MASK      3    /* (1 1) Clear them to be (0 0) (Clear)> Access 3ala Nadafa */
#define   GPIO_SPEED_MASK     3    /* TWO BITS */
#define   GPIO_PUPDR_MASK     3



#endif
