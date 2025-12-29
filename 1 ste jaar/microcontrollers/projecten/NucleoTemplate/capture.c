#include "stm32f091xc.h"
#include "capture.h"

void InitCapture(void)
{
	// Clock inschakelen voor TIM3
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	GPIOC->MODER &= ~GPIO_MODER_MODER8;  
	GPIOC->MODER |= GPIO_MODER_MODER8_1; // Alternate Function mode
	// TIM3_CH3 als capture pin instellen
	//GPIOC->AFR[1] &= ~GPIO_AFRH_AFSEL8; // PC8 -> AFRH p. 170 in reference manual, function 0 (TIM3_CH3) p. 43 in datasheet

  // Timer configureren
  TIM3->PSC = 47; // Prescaler: 48MHz / (47+1) = 1MHz (1 µs resolutie)
  TIM3->ARR = 0xFFFF; // Max tellerwaarde

  // Input capture op Channel 3
  TIM3->CCMR2 |= TIM_CCMR2_CC3S_0; // CC1 als input
  TIM3->CCER &= ~TIM_CCER_CC3P; // Capture op rising edge
  TIM3->CCER |= TIM_CCER_CC3E; // Capture enable
    
  // Interrupt inschakelen
  TIM3->DIER |= TIM_DIER_CC3IE;
  NVIC_EnableIRQ(TIM3_IRQn);

  // Timer starten
  TIM3->CR1 |= TIM_CR1_CEN;
}