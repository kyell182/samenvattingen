// Includes.
#include "stm32f091xc.h"
#include "stdio.h"
#include "stdbool.h"
#include "leds.h"
#include "buttons.h"
#include "usart2.h"
#include "ad.h"

// Functie prototypes.
void SystemClock_Config(void);
void InitIo(void);
void WaitForMs(uint32_t timespan);

// Variabelen aanmaken. 
// OPM: het keyword 'static', zorgt ervoor dat de variabele enkel binnen dit bestand gebruikt kan worden.
static uint8_t count = 0;
static volatile uint32_t ticks = 0;

// Entry point.
int main(void)
{
	// Initialisaties.
	SystemClock_Config();
	InitIo();
	InitButtons();
	InitLeds();
	InitUsart2(9600);
	//InitAd();
	
	// Laten weten dat we opgestart zijn, via de USART2 (USB).
	StringToUsart2("Reboot\r\n");
	
	// Oneindige lus starten.
	while (1)
	{	
		// Doe hier eens iets anders dan rechtstreeks GPIO input in te lezen...
		// ...
	}
}

// Functie om extra IO's te initialiseren.
void InitIo(void)
{
	// SYSCFG clock enable.  										
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	
	// PA4 (SW2) koppelen aan EXTI 4.
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PA;
	
	// Falling edge detecteren
	EXTI->FTSR = EXTI->FTSR | EXTI_FTSR_TR4;
	
	// Interrupt toelaten
	EXTI->IMR = EXTI->IMR | EXTI_IMR_MR4;
	
	// Eén van de 4 prioriteiten kiezen. Als er twee interrupts zijn met dezelfde
	// prioriteit, wordt eerst diegene afgehandeld die de laagste 'position' heeft (zie vector table NVIC in datasheet).
	NVIC_SetPriority(EXTI4_15_IRQn,0);
	
	// Interrupt effectief toelaten.
	NVIC_EnableIRQ(EXTI4_15_IRQn);
}

// Interrupt handler aanmaken. De definities van de handler kan je vinden in
// startup_stp32f091xc.s.
void EXTI4_15_IRQHandler(void) 
{	
	// Als het een interrupt is van PA4, de LED's inschakelen.
	if((EXTI->PR & EXTI_PR_PR4) == EXTI_PR_PR4)
	{
		// Doe iets (LED's inschakelen, naar UART schrijven, ...).
		// ...
		// Good practice: stuur dit niet rechtstreeks aan, maar werk via hulpvariabele (zie les).
		
		// Interrupt (pending) vlag wissen door
		// een 1 te schrijven: EXTI->PR |= EXTI_PR_PR4;
		EXTI->PR |= EXTI_PR_PR4;	
	}	
}

/*
Mogelijke oplossing als je teveel dender zou ervaren...
Maak de globale variabele 'uint32_t lastInterruptTime' aan en plaats onderstaande code in de interrupt handler:

//...

uint32_t currentTime = ticks;
if((currentTime - lastInterruptTime) > 200)
{
  //plaats hier jouw code: 
  //if((EXTI->PR & EXTI_PR_PR...
  //{
  //...
  //}

  lastInterruptTime = currentTime;
}

//...
*/

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
