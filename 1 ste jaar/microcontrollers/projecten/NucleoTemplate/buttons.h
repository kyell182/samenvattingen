#include "stm32f091xc.h"
#include "stdbool.h"

#if !defined(BUTTONS_DEFINED)
	#define BUTTONS_DEFINED
	
	void InitButtons(void);
	bool SW1Active(void);	
	bool SW2Active(void);
	bool SW3Active(void);
	bool SW4Active(void);
	bool UserButtonActive(void);
#endif
