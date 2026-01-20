#include "stm32f091xc.h"
#include "i2c1.h"

void InitI2C1(void)
{
	// Tijdens het communiceren naar 5V-apparaten kan het zijn dat de gewenste snelheid niet bereikt kan worden met de
	// interne pull-ups... Voorzie dus best externe pull-ups (naar 5V) op PB8 en PB9. Of voorzie een level shifter.
	
	// Pinnen van de I²C1 instellen als alternate function.	
	// PB8 => SCL-pin (5V tolerant)
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER8) | GPIO_MODER_MODER8_1;			// Alternate function op PB8.
	GPIOB->AFR[1] |= 0x00000001;																									// Alternate function AF1 (zie datasheet STM32F091RC, p44).
	//GPIOB->PUPDR |= GPIO_PUPDR_PUPDR8_0;																				// Pull-up van pin inschakelen (naar 3V3).

	// PB9 => SDA-pin (5V tolerant)
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER9) | GPIO_MODER_MODER9_1;			// Alternate function.
	GPIOB->AFR[1] |= 0x00000010;
	//GPIOB->PUPDR |= GPIO_PUPDR_PUPDR9_0;																				// Pull-up van pin inschakelen (naar 3V3).
	
	// HSI als input voor I2C1-module = 8MHz (default)
	RCC->CFGR3 &= ~RCC_CFGR3_I2C1SW;
	
	// I²C1-module van een klok voorzien
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	
	// 7-bit adres voor het communiceren met een slave (geen 10-bit) (optioneel).
	I2C1->CR2 &= ~I2C_CR2_ADD10;
	
	// Auto end mode uitzetten. Automatisch stop niet verzenden na versturen laatste byte, TC vlag pollen in de plaats, daarna stop genereren. (optioneel)
	I2C1->CR2 &= ~I2C_CR2_AUTOEND;
	
	// Timing correct instellen (via AN4235 en Excel bestand van ST).
	// 100kHz vertrekkende vanuit 8MHz (HSI)
	I2C1->TIMINGR = 0x00201D2B;
	
	// I²C1-module enable
	I2C1->CR1 |= I2C_CR1_PE;	
}

// Schrijf één byte naar een bepaald I²C-apparaat.
void I2C1WriteRegister(uint8_t deviceAddress, uint8_t registerToWrite, uint8_t dataToWrite)
{
	// Schrijfactie.
	I2C1->CR2 &= ~I2C_CR2_RD_WRN;
	
	// Slave address waarmee gecommuniceerd moet worden invullen.
	I2C1->CR2 &= 0xFFFFFF00;													// Slave address resetten.
	I2C1->CR2 |= (deviceAddress << 1);								// Adres klaarzetten.
	
	// Aantal te versturen bytes, waarna een stop gegenereerd moet worden (TC vlag wordt gezet).
	I2C1->CR2 &= ~I2C_CR2_NBYTES;											// NBYTES wissen.
	I2C1->CR2 |= (2 << 16);														// 2 bytes te versturen, dus 2 in NBYTES plaatsen.			

	// Start conditie.
	I2C1->CR2 |= I2C_CR2_START;
	
	// Bytes versturen.
	while((I2C1->ISR & I2C_ISR_TXE) != I2C_ISR_TXE);	// Is verzendbuffer leeg?	
	I2C1->TXDR = registerToWrite;											// Direction versturen.
	while((I2C1->ISR & I2C_ISR_TXE) != I2C_ISR_TXE);	// Is verzendbuffer leeg?	
	I2C1->TXDR = dataToWrite;													// 12 elektrodes instellen.
	
	// Stop conditie.	
	while((I2C1->ISR & I2C_ISR_TC) != I2C_ISR_TC);		// Wacht op transmission complete.	
	I2C1->CR2 |= I2C_CR2_STOP;
}

// Lees één byte van een bepaald I²C-apparaat.
uint8_t I2C1ReadRegister(uint8_t deviceAddress, uint8_t registerToRead)
{
	// Tijdelijke variabele voor het opslaan van I²C-data.
	uint8_t temp = 0;
	
	// Leesactie starten via een schrijfactie: registeradres klaarzetten om later uit te lezen.
	I2C1->CR2 &= ~I2C_CR2_RD_WRN;
	
	// Slave address waarmee gecommuniceerd moet worden invullen.
	I2C1->CR2 &= 0xFFFFFF00;													// Slave address resetten.
	I2C1->CR2 |= (deviceAddress << 1);								// Adres klaarzetten.
	
	// Aantal te versturen bytes, waarna een RESTART gegenereerd moet worden (TC vlag wordt gezet).
	I2C1->CR2 &= ~I2C_CR2_NBYTES;											// NBYTES wissen.
	I2C1->CR2 |= (1 << 16);														// 1 byte te versturen, dus 1 in NBYTES plaatsen.			

	// Start conditie.
	I2C1->CR2 |= I2C_CR2_START;
	
	// Byte versturen.		
	while((I2C1->ISR & I2C_ISR_TXE) != I2C_ISR_TXE);	// Is verzendbuffer leeg?	
	I2C1->TXDR = registerToRead;
	
	// Wacht op transmission complete. Daarna restart doen.	
	while((I2C1->ISR & I2C_ISR_TC) != I2C_ISR_TC);
	
	// Leesactie van resultaat.
	I2C1->CR2 |= I2C_CR2_RD_WRN;
	
	// Slave address waarmee gecommuniceerd moet worden invullen.
	I2C1->CR2 &= 0xFFFFFF00;													// Slave address resetten.
	I2C1->CR2 |= (deviceAddress << 1);								// Adres van de module meegeven, de module antwoordt dan terug met de gevraagde gegevens.
																								
	// Aantal te ontvangen bytes, waarna een stop gegenereerd moet worden (TC vlag wordt gezet).
	I2C1->CR2 &= ~I2C_CR2_NBYTES;											// NBYTES wissen.
	I2C1->CR2 |= (1 << 16);														// 1 byte te ontvangen, dus 1 in NBYTES plaatsen.
	
	// RESTART conditie.
	I2C1->CR2 |= I2C_CR2_START;
	
	// Ontvangen data uitlezen.
	while(!(I2C1->ISR & I2C_ISR_RXNE));								// Wachten tot RX buffer not empty is.
	temp = (uint8_t)I2C1->RXDR;												// Ontvangen byte opslaan en vlaggen wissen.
	
	// Stop conditie.	
	while((I2C1->ISR & I2C_ISR_TC) != I2C_ISR_TC);		// Wacht op transmission complete.	
	I2C1->CR2 |= I2C_CR2_STOP;
	
	return temp;
}
