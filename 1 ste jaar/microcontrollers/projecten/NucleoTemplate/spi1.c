#include "stm32f091xc.h"
#include "spi1.h"

void InitSpi1(void)
{
	// Poort A van klok voorzien (mocht dit nog niet gebeurd zijn).
	RCC->AHBENR = RCC->AHBENR | RCC_AHBENR_GPIOAEN;
	
	// RCC_APBxENR registers instellen zodat de SPI-modules een klok krijgt.
	RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_SPI1EN;		//SPI1 enable
	
	// SPI1 moet op de alternate function pinnen komen
	GPIOA->MODER = (GPIOA->MODER & ~(GPIO_MODER_MODER5)) | (GPIO_MODER_MODER5_1);			//PA5 moet alternate function zijn
	GPIOA->MODER = (GPIOA->MODER & ~(GPIO_MODER_MODER6)) | (GPIO_MODER_MODER6_1);			//PA6 moet alternate function zijn
	GPIOA->MODER = (GPIOA->MODER & ~(GPIO_MODER_MODER7)) | (GPIO_MODER_MODER7_1);			//PA7 moet alternate function zijn
	GPIOA->AFR[0] &= 0x11011111;															// in Alternate Function Register Low [0], aangeven dat PA5 SCK1 moet zijn (AF0) (zie datasheet STM32F091RC, p43).
	GPIOA->AFR[0] &= 0x10111111;															// in Alternate Function Register Low [0], aangeven dat PA6 SDI1 moet zijn (AF0) (zie datasheet STM32F091RC, p43).
	GPIOA->AFR[0] &= 0x01111111;															// in Alternate Function Register Low [0], aangeven dat PA7 SDo1 moet zijn (AF0) (zie datasheet STM32F091RC, p43).
	
	// SPI1 mode instellen
	SPI1->CR1 = SPI1->CR1 | SPI_CR1_BR_2 | SPI_CR1_BR_1 | SPI_CR1_BR_0;			// BR[2:0] = 111 => fPCLK/256 = 48 000 000 / 256 = 187 500 Hz
	SPI1->CR1 = SPI1->CR1 & ~SPI_CR1_CPOL;														// klok laag als idle (standaard na reset)
	SPI1->CR1 = SPI1->CR1 & ~SPI_CR1_CPHA;														// data input bij eerste flank (standaard na reset)
	SPI1->CR1 = SPI1->CR1 & ~SPI_CR1_BIDIMODE;													// 2-line unidirectional data mode selected (2 lijnen, maar slechts 1 gebruiken)
	SPI1->CR1 = SPI1->CR1 & ~SPI_CR1_LSBFIRST; 													// data is transmitted with the MSB first
	SPI1->CR1 |= SPI_CR1_SSM;																	// Software slave management enabled (geen pin gebruiken voor slave select)
	SPI1->CR1 |= SPI_CR1_SSI;																	// Internal slave select (optioneel)	
	SPI1->CR1 |=  SPI_CR1_MSTR;																	// master mode
	SPI1->CR2 = (SPI1->CR2 & ~(SPI_CR2_DS)) | SPI_CR2_DS_0 | SPI_CR2_DS_1 | SPI_CR2_DS_2;		// 8-bit data (optioneel, want ook zo na reset)		
	SPI1->CR2 = SPI1->CR2 & ~SPI_CR2_FRF;														// SPI Motorola mode (standaard na reset)
	SPI1->CR2 |= SPI_CR2_FRXTH;																	// 8-bit RX FIFO	
	SPI1->CR1 |= SPI_CR1_SPE;																	// SPI enable	
}

void ByteToSpi1(uint8_t data)
{
	// SPI1 data verzenden	
	*(uint8_t *)&(SPI1->DR) = data;					// verzend data (let op, cast zeker naar 8-bit anders worden 16 klokpulsen gegeven)
	while((SPI1->SR & SPI_SR_BSY) == SPI_SR_BSY); 	// wacht tot verzenden gedaan is
}
