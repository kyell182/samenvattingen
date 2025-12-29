#include "stm32f091xc.h"
#include "timer6.h"

void InitTimer6(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;	// clock voorzien voor de timer
	
	TIM6->PSC = 47999;									// Als je een klok wil op 1000 Hz:
																			// 48 000 000 / (47 999 + 1) = 1000 Hz
	TIM6->ARR = 125;										// Als je iedere 125 ms een interrupt wil... 
																			// 125 stappen van 1 ms.		
	
	TIM6->DIER |= TIM_DIER_UIE;					// Interrupt enable voor timer 6	
	TIM6->CR1 |= TIM_CR1_CEN;						// counter enable
	
	//TIM6->CR1 |= TIM_CR1_OPM;					// one pulse mode kiezen, 
																			// dan stopt de timer na één overflow.
	
	NVIC_SetPriority(TIM6_IRQn, 0);
	NVIC_EnableIRQ(TIM6_IRQn);
}

//void StartTimer6(void)
//{
//	// Volgorde van (groot) belang.		
//	TIM6->CNT = 0;											// Timer resetten	
//	TIM6->EGR |= TIM_EGR_UG;						// registers updaten (in one pulse mode zorgt dit voor het uitzetten van CEN).
//	TIM6->CR1 |= TIM_CR1_CEN;						// counter enable	
//	TIM6->SR &= ~TIM_SR_UIF;						// Interruptvlag resetten	
//	TIM6->DIER |= TIM_DIER_UIE;					// Interrupt enable voor timer 6.
//}

//void StopTimer6(void)
//{	
//	TIM6->DIER &= ~TIM_DIER_UIE;				// Interrupt disable voor timer 6.
//	TIM6->SR &= ~TIM_SR_UIF;						// Interruptvlag resetten
//	TIM6->CR1 &= ~TIM_CR1_CEN;					// counter disable
//}
