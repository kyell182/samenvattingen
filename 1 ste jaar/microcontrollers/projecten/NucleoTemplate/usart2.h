#include "stm32f091xc.h"

#if !defined(USART2_DEFINED)
	#define USART2_DEFINED
	
	void InitUsart2(uint32_t baudRate);	
	void StringToUsart2(char* string);
#endif


/*

Usage in main.c

void USART2_IRQHandler(void)
{
	if((USART2->ISR & USART_ISR_RXNE) == USART_ISR_RXNE)
	{
		// Byte ontvangen, lees hem om alle vlaggen te wissen.
		uint8_t temp = USART2->RDR;		
		
		...
	}
}

*/
