#include "stm32f091xc.h"

#if !defined(LEDS_DEFINED)
	#define LEDS_DEFINED
	
	void InitLeds(void);
	void ByteToLeds(uint8_t data);
	void ToggleLed(uint8_t ledNumber);
	void ByteToLevel(uint8_t level);
#endif
