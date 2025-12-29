#include "stm32f091xc.h"
#include "ad.h"

// AD-module initialiseren
void InitAd(void)
{
	// Poort A 0 als analoge ingang (potentiometer op het Nucleo Extension Shield).
	GPIOA->MODER |= GPIO_MODER_MODER0;
	
	// AD-module van klok voorzien.
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	
	// Right alignment (optioneel).
	ADC1->CFGR1 &= ~ADC_CFGR1_ALIGN;						

	// AD enable'n.
	ADC1->CR |= ADC_CR_ADEN; 									
	while ((ADC1->ISR & ADC_ISR_ADRDY) == 0);

	// AD-kanaal 0 kiezen (verbonden met de connector voor analog input).
	ADC1->CHSELR = ADC_CHSELR_CHSEL0;
	
	// Tragere sample rate kiezen (voor hoogimpedante analoge bronnen).
	ADC1->SMPR |= ADC_SMPR_SMP_0 | ADC_SMPR_SMP_1 | ADC_SMPR_SMP_2;		
}

// De blokkerende versie van de AD-conversie.
uint16_t GetAdValue(void)
{
	uint32_t temp = 0;
	
	ADC1->CR |= ADC_CR_ADSTART; 								// Start de AD-omzetting.	
	while ((ADC1->ISR & ADC_ISR_EOSEQ) == 0);		// Wachten op einde sequentie (sequentie bestaat hier uit één conversie).	
	ADC1->ISR |= ADC_ISR_EOSEQ;									// Vlag wissen.
	temp = ADC1->DR;
	
	return (uint16_t)temp;
}
