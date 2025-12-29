#include "stm32f091xc.h"
#include "usart2.h"

void InitUsart2(uint32_t baudRate)
{
	// Clock voor GPIOA inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOAEN;
	
	// Pinnen van de USART2 instellen als alternate function.	
	// PA2 => TX-pin
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER2) | GPIO_MODER_MODER2_1;		// Alternate function op PA2
	GPIOA->AFR[0] |= 0x00000100;																								// USART2_TX is alternate function AF1 (zie datasheet STM32F091RC, p41).

	// PA3 => RX-pin
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER3) | GPIO_MODER_MODER3_1;		// Alternate function op PA3
	GPIOA->AFR[0] |= 0x00001000;
		
	// Usart module van een klok voorzien
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	
	// Baudrate zetten
	USART2->BRR = 48000000/baudRate;
	
	// Reception overrun disable. Als nieuwe byte aankomt terwijl
	// vorige nog niet verwerkt is, geen overrun error genereren.
	USART2->CR3 |= USART_CR3_OVRDIS;
	
	// USART inschakelen
	USART2->CR1 |= USART_CR1_UE;
	
	// Transmitter enable
	USART2->CR1 |= USART_CR1_TE;	
	
//	// Interrupt voor de receiver enable (receiver buffer not empty interrupt enable)
//	USART2->CR1 |= USART_CR1_RXNEIE;
//	
//	// Koppeling van interrupt maken met de NVIC
//	NVIC_SetPriority(USART2_IRQn, 0);
//	NVIC_EnableIRQ(USART2_IRQn);
//	
//	// Receiver enable
//	USART2->CR1 |= USART_CR1_RE;
}

void StringToUsart2(char* string)
{
	uint8_t indexer = 0;
	
	while(string[indexer] != 0)
	{
		// Byte versturen.
		USART2->TDR = (uint8_t)string[indexer++];
		
		// Wachten tot byte vertuurd is.
		while((USART2->ISR & USART_ISR_TC) != USART_ISR_TC);
	}
}

/*
// printf redirecting. Op die manier kan je 'printf("Hallo wereld");' gebruiken
// i.p.v. 'StringToUsart2("Hallo wereld");'.
//
// Vergeet USART 2 niet in te stellen (en InitUsart2() op te roepen).
struct __FILE
{
  int handle;
	// Whatever you require here. If the only file you are using is
	// standard output using printf() for debugging, no file handling
	// is required.
	//
	// https://community.arm.com/developer/tools-software/tools/f/keil-forum/34791/how-printf-to-specific-usart
};
// FILE is typedef’d in stdio.h.
FILE __stdout;

int fputc(int ch, FILE *f)
{
	// Your implementation of fputc().	
	
	// Byte versturen.
	USART2->TDR = ch;
	
	// Wachten tot byte vertuurd is.
	while((USART2->ISR & USART_ISR_TC) != USART_ISR_TC);	
  
  return ch;
}
*/
