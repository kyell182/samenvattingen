#include "stm32f091xc.h"

#if !defined(I2C1_DEFINED)
	#define I2C1_DEFINED
	
	void InitI2C1(void);
	void I2C1WriteRegister(uint8_t deviceAddress, uint8_t registerToWrite, uint8_t dataToWrite);
	uint8_t I2C1ReadRegister(uint8_t deviceAddress, uint8_t registerToRead);
#endif
