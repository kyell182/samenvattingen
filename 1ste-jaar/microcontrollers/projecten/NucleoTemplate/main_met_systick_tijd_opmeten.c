// Basiscode voor het starten van eender welk project op een Nucleo-F091RC met Nucleo Extension Shield V2.
//
// OPM:
//	- via 'Project -> Manage -> Select software packs' kies je bij Keil::STM32F0xx_DFP voor versie 2.0.0.
//	- via 'Options for Target -> C/C++' zet je de compiler op C11, optimizations op default en warnings op AC5-like.
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
#include "string.h"

// Functie prototypes.
void SystemClock_Config(void);
void InitIo(void);
void WaitForMs(uint32_t timespan);
void DoSomeStuff();

// Variabelen aanmaken. 
// OPM: het keyword 'static', zorgt ervoor dat de variabele enkel binnen dit bestand gebruikt kan worden.
static volatile uint32_t ticks = 0;
static uint32_t startTijd = 0;
static uint32_t eindTijd = 0;
static uint32_t tijdsduur = 0;
static float tijdsduurMs = 0;
static char info[100];

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
	
	// Laten weten dat we opgestart zijn, via de USART2 (USB).
	StringToUsart2("Reboot\r\n");
	
	// Oneindige lus starten.
	while (1)
	{	
		// ...
		// Opmeten
		
		// Begintijd vaststellen
		startTijd = SysTick->VAL;
		
		// Beetje uitrusten
		DoSomeStuff();

		// Eindtijd vaststellen
		eindTijd = SysTick->VAL;

		// Controleren of er geen underflow/roll over geweest is (onder nul gezakt).
		if ((SysTick->CTRL & 0x10000) == 0)
		{
				tijdsduur = startTijd - eindTijd;
				tijdsduurMs = (float)tijdsduur / 48;
				sprintf(info, "\r\nDe opgemeten tijdsduur van 'DoSomeStuff()' is: %d klokcycli.", tijdsduur);
				StringToUsart2(info);
				sprintf(info, "\r\nDit staat gelijk met: %.2f microseconden.", tijdsduurMs);
				StringToUsart2(info);
		}
		else
		{
				tijdsduur = 0;
				sprintf(info, "\r\nDe opgemeten tijdsduur van 'DoSomeStuff()' is onbekend (SysTick underflow).");
				StringToUsart2(info);
		}
		// ...
		
		WaitForMs(200);
	}
	
	// Terugkeren zonder fouten... (unreachable).
	return 0;
}

// Functie om extra IO's te initialiseren.
void InitIo(void)
{
	// Initialisatie
	
	// SysTick uitschakelen
	SysTick->CTRL = 0;

	// 24-bit 'reload' getal op maximum zetten zodat we
	// aftellen van maximumwaarde na bereiken van 0.
	SysTick->LOAD = 0xFFFFFF;

	// Huidige waarde op nul zetten zodat straks onmiddellijk
	// gereset wordt op 0xFFFFFF.
	SysTick->VAL = 0;

	// HCLK selecteren en SysTick Timer enable (geen interrupt toelaten).
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

	// Wachten om herladen van de teller (met 0xFFFFFF)
	while (SysTick->VAL == 0);
}

void DoSomeStuff()
{
	// Enkele "zware" berekeningen ...
	for(uint32_t counter = 0; counter < 20000; counter++)
	{
		__NOP();
	}
}

// Handler die iedere 20 ms afloopt. 
// Ingesteld met SystemCoreClockUpdate() en SysTick_Config().
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
	
	SystemCoreClockUpdate(); // Nieuwe waarde van de core frequentie opslaan 
													 // in SystemCoreClock variabele.
													 
	SysTick_Config(960000);	 // Interrupt genereren. Zie core_cm0.h, om na iedere
													 // 20 ms een interrupt te hebben op SysTick_Handler().
													 // 48 000 000 / 960 000 = 50 keer per seconde => 20 ms.
													 // Let op: SysTick is 24-bit breed, dus maximumwaarde
													 //	is 16 777 215.
}
