// Basiscode voor het starten van eender welk project op een Nucleo-F091RC met Nucleo Extension Shield V2.
//
// OPM:
//	- via 'Project -> Manage -> Select software packs' kies je bij Keil::STM32F0xx_DFP voor versie 2.0.0.
//	- via 'Options for Target ...' zet je de compiler op C99 (en eventueel op AC5-like warnings).
// 
// Versie: 20242025

// Includes.
#include "stm32f091xc.h"
#include "stdio.h"
#include "stdbool.h"
#include "leds.h"
#include "buttons.h"
#include "usart2.h"
#include "ad.h"
#include "capture.h"

// Functie prototypes.
void SystemClock_Config(void);
void InitIo(void);
void WaitForMs(uint32_t timespan);

// Variabelen aanmaken. 
// OPM: het keyword 'static', zorgt ervoor dat de variabele enkel binnen dit bestand gebruikt kan worden.
static volatile uint32_t ticks = 0;
bool startNieuweMeting = true;
bool toonResultaat = false;
uint32_t startTijd = 0;
uint32_t stopTijd = 0;

// Entry point.
int main(void)
{
	// Initialisaties.
	SystemClock_Config();
	InitIo();
	//InitButtons();
	//InitLeds();
	InitUsart2(9600);
	//InitAd();
	InitCapture();
	
	// Laten weten dat we opgestart zijn, via de USART2 (USB).
	StringToUsart2("Reboot\r\n");
	
	// Oneindige lus starten.
	while (1)
	{	
		if(startNieuweMeting)
		{
			// Trigger starten voor de HC-SR04
			GPIOC->ODR |= GPIO_ODR_2; // Trigger op 1 zetten
			WaitForMs(1);
			GPIOC->ODR &= ~GPIO_ODR_2; // Trigger op 0 zetten
			startNieuweMeting = false;
		}
		
		if(toonResultaat)
		{
			// Tijdsverschil berekenen
      uint32_t tijdsduur = (stopTijd >= startTijd) ? (stopTijd - startTijd) : ((0xFFFF - startTijd) + stopTijd);
			
      // Berekening afstand
      double tijdInSeconden = (double)tijdsduur / 1000000; // Omzetten van µs naar s
      double afstandInCM = (tijdInSeconden * 340.0 * 100.0) / 2;

      // Output naar USART
      char text[30];
      sprintf(text, "Afstand: %.2f cm\r\n", afstandInCM);
      StringToUsart2(text);
			
			toonResultaat = false;
			startNieuweMeting = true;
		}

		WaitForMs(500);
	}
}

// Functie om extra IO's te initialiseren.
void InitIo(void)
{
	// Clock voor GPIOC inschakelen.
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOCEN;
	
	// PC2 (trigger) als output zetten
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER2) | GPIO_MODER_MODER2_0;
}

void TIM3_IRQHandler(void) {

	// Capture event voor Channel 3
  if (TIM3->SR & TIM_SR_CC3IF) 
	{ 
		if ((TIM3->CCER & TIM_CCER_CC3P) == 0) 
		{
			startTijd = TIM3->CCR3;
			TIM3->CCER |= TIM_CCER_CC3P; // Volgende capture op falling edge		
    } 
		else 
		{
			stopTijd = TIM3->CCR3;
      TIM3->CCER &= ~TIM_CCER_CC3P; // Volgende capture op rising edge
			toonResultaat = true;
    }

    // Interrupt vlag resetten
    TIM3->SR &= ~TIM_SR_CC3IF;
  }
}

// Handler die iedere 1ms afloopt. Ingesteld met SystemCoreClockUpdate() en SysTick_Config().
void SysTick_Handler(void)
{
	ticks++;
}

// Wachtfunctie via de SysTick.
void WaitForMs(uint32_t timespan)
{
	uint32_t startTime = ticks;
	
	while(ticks < startTime + timespan);
}

// Klokken instellen. Deze functie niet wijzigen, tenzij je goed weet wat je doet.
void SystemClock_Config(void)
{
	RCC->CR |= RCC_CR_HSITRIM_4;														// HSITRIM op 16 zetten, dit is standaard (ook na reset).
	RCC->CR  |= RCC_CR_HSION;																// Internal high speed oscillator enable (8MHz)
	while((RCC->CR & RCC_CR_HSIRDY) == 0);									// Wacht tot HSI zeker ingeschakeld is
	
	RCC->CFGR &= ~RCC_CFGR_SW;															// System clock op HSI zetten (SWS is status geupdatet door hardware)	
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);	// Wachten to effectief HSI in actie is getreden
	
	RCC->CR &= ~RCC_CR_PLLON;																// Eerst PLL uitschakelen
	while((RCC->CR & RCC_CR_PLLRDY) != 0);									// Wacht tot PLL zeker uitgeschakeld is
	
	RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;								// 01: HSI/PREDIV selected as PLL input clock
	RCC->CFGR2 |= RCC_CFGR2_PREDIV_DIV2;										// prediv = /2		=> 4MHz
	RCC->CFGR |= RCC_CFGR_PLLMUL12;													// PLL multiplied by 12 => 48MHz
	
	FLASH->ACR |= FLASH_ACR_LATENCY;												//  meer dan 24 MHz, dus latency op 1 (p 67)
	
	RCC->CR |= RCC_CR_PLLON;																// PLL inschakelen
	while((RCC->CR & RCC_CR_PLLRDY) == 0);									// Wacht tot PLL zeker ingeschakeld is

	RCC->CFGR |= RCC_CFGR_SW_PLL; 													// PLLCLK selecteren als SYSCLK (48MHz)
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);	// Wait until the PLL is switched on
		
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;												// SYSCLK niet meer delen, dus HCLK = 48MHz
	RCC->CFGR |= RCC_CFGR_PPRE_DIV1;												// HCLK niet meer delen, dus PCLK = 48MHz	
	
	SystemCoreClockUpdate();																// Nieuwe waarde van de core frequentie opslaan in SystemCoreClock variabele
	SysTick_Config(48000);																	// Interrupt genereren. Zie core_cm0.h, om na ieder 1ms een interrupt 
																													// te hebben op SysTick_Handler()
}