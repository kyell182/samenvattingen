#include "stm32f091xc.h"

#if !defined(APA102C_DEFINED)
	#define APA102C_DEFINED
	
	#define DEFAULT_LED_BRIGHTNESS 100			// Helderheid van de RGB-LED bij opstarten.
	#define NUMBER_OF_APA102C_LEDS 3
	
	typedef struct{
		uint8_t brightness;
		uint8_t red;
		uint8_t green;
		uint8_t blue;		
	} APA102C;		
	
	void UpdateAPA102CLeds(APA102C led[]);
#endif
