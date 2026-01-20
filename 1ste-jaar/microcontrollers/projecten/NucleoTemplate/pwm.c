#include "stm32f091xc.h"
#include "pwm.h"

void InitPwm(void)
{
	// Gebruik Timer 1 voor het genereren van een PWM-signaal. Mik op 50Hz frequentie en een resolutie van 10-bit.
	// PWM aanmaken voor pin PA8 en PA9. PA8 is verbonden met LED6 van de Nucleo Extension shield 
	// en PA9 met een servomotor. Op die manier kan je ook visueel de PWM iet-of-wat controleren.
	uint16_t pwm = 0;		// 1000 <= PWM <= 2000
	
	// PA8/LED6 moet TIM1_CH1 worden via alternate function 2
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER8) | GPIO_MODER_MODER8_1;		// Alternate function op PA8
	GPIOA->AFR[1] |= 0x00000002;		// Alternate function 2
	
	// PA9/modelbouwservo moet TIM1_CH2 worden via alternate function 2
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER9) | GPIO_MODER_MODER9_1;		// Alternate function op PA9
	GPIOA->AFR[1] |= 0x00000020;		// Alternate function 2
	
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;			// Clock voorzien voor de timer1.	
	TIM1->PSC = 47; 												// Prescaler op 1/48 => 48000000/48 => 1 µs per puls
	TIM1->ARR = 20000; 											// Periode van 20 ms want: 1µs * 20000 = 20ms of  = 1/48000000 * 48 * 20000 = 20ms
	pwm = 1000;															// Gewenste PWM-waarde (1000 <= pwm <= 2000). Want modelbouw-ESC verwacht minstens 1ms en maximum 2ms.
	TIM1->CCR1 = pwm; 											// Aantijd voor OC1 (Output Compare) voor CH1: PA8
	TIM1->CCR2 = pwm; 											// Aantijd voor OC2 voor CH2: PA9
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE; 	// PWM mode 1 op OC1/PA8, enable preload register op OC1 (OC1PE = 1)
	TIM1->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE; 	// PWM mode 1 op OC2/PA9, enable preload register op OC2 (OC2PE = 1)
	TIM1->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E; 														// Enable OC1 (en OC2) output.
	TIM1->BDTR |= TIM_BDTR_MOE; 																						// Enable output (MOE = 1).
	TIM1->CR1 |= TIM_CR1_CEN; 																							// Enable counter (CEN = 1).
	TIM1->EGR |= TIM_EGR_UG; 																								// Force update generation (UG = 1).
}

// pPwm = aantijd tussen 1000 en 2000 (µs).
void SetPwm(uint16_t pPwm)
{
	TIM1->CCR1 = pPwm; 										// Aantijd voor OC1
	TIM1->CCR2 = pPwm; 										// Aantijd voor OC2
	//TIM1->EGR |= TIM_EGR_UG; 							// Force update generation (UG = 1).
}

//void EnablePWM(void)
//{
//	// PA8/LED6 moet TIM1_CH1 worden via alternate function 2
//	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER8) | GPIO_MODER_MODER8_1;		// Alternate function op PA8
//	GPIOA->AFR[1] |= 0x00000002;		// Alternate function 2
//	
//	// PA9/modelbouwservo moet TIM1_CH2 worden via alternate function 2
//	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER9) | GPIO_MODER_MODER9_1;		// Alternate function op PA9
//	GPIOA->AFR[1] |= 0x00000020;		// Alternate function 2
//	
//	// Enable output (MOE = 1).
//	TIM1->BDTR |= TIM_BDTR_MOE; 																					
//}

//void DisablePWM(void)
//{
//	// Disable output (MOE = 0).
//	TIM1->BDTR &= ~TIM_BDTR_MOE; 																					
//	
//	// PA8/LED6 als (laag ohmige) output zetten om storing bij aanraking pin te voorkomen.
//	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER8) | GPIO_MODER_MODER8_0;
//	
//	// PA9 als (laag ohmige) output zetten.
//	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER9) | GPIO_MODER_MODER9_0;
//}
