#include "stm32f091xc.h"
#include "stdbool.h"
#include "buttons.h"

// Knoppen als input initialiseren.
void InitButtons(void)
{
	// Clock voor GPIOA inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOAEN;
	
	// Clock voor GPIOB inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOBEN;
	
	// Clock voor GPIOC inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOCEN;	
	
	// Alle pinnen met drukknoppen verbonden, op input zetten.
	GPIOA->MODER = GPIOA->MODER & ~GPIO_MODER_MODER1;
	GPIOA->MODER = GPIOA->MODER & ~GPIO_MODER_MODER4;	
	GPIOB->MODER = GPIOB->MODER & ~GPIO_MODER_MODER0;
	GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODER1;
	GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODER13;
}

bool SW1Active(void)
{
	// SW1 actief?
	if((GPIOA->IDR & GPIO_IDR_1) != GPIO_IDR_1)
			return true;
	else
			return false;
}		
	
bool SW2Active(void)
{
	// SW2 actief?
	if((GPIOA->IDR & GPIO_IDR_4) != GPIO_IDR_4)
			return true;
	else
			return false;
}

bool SW3Active(void)
{
	// SW3 actief?
	if((GPIOB->IDR & GPIO_IDR_0) != GPIO_IDR_0)
			return true;
	else
			return false;
}

bool SW4Active(void)
{
	// SW4 actief?
	if((GPIOC->IDR & GPIO_IDR_1) != GPIO_IDR_1)
			return true;
	else
			return false;
}

bool UserButtonActive(void)
{
	// User button actief?
	if((GPIOC->IDR & GPIO_IDR_13) != GPIO_IDR_13)
			return true;
	else
			return false;
}
