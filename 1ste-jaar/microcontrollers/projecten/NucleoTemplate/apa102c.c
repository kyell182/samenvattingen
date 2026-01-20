#include "stm32f091xc.h"
#include "apa102c.h"
#include "spi1.h"

// Verstuur de data over SPI1. Let op: zorg dat SPI1 reeds geïnitialiseerd is.
void UpdateAPA102CLeds(APA102C led[])
{
	uint8_t index = 0;
	
	ByteToSpi1(0);															// Start frame.
	ByteToSpi1(0);
	ByteToSpi1(0);
	ByteToSpi1(0);
	
	for(index = 0; index < NUMBER_OF_APA102C_LEDS; index++)
	{	
		ByteToSpi1(led[index].brightness | 0b11100000);		// 5-bit intensiteit.
		ByteToSpi1(led[index].blue);											// Blauw.
		ByteToSpi1(led[index].green);											// Groen.
		ByteToSpi1(led[index].red);												// Rood.
	}
	
	ByteToSpi1(255);														// End frame.
	ByteToSpi1(255);
	ByteToSpi1(255);
	ByteToSpi1(255);
}
