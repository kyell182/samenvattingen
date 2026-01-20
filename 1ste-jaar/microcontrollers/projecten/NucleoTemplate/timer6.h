#if !defined(TIMER6_DEFINED)
	#define TIMER6_DEFINED
	
	void InitTimer6(void);
//	void StartTimer6(void);
//	void StopTimer6(void);

//	// Gebruik van de timer interrupt in de main.c, als volgt:
//	// Interrupt van Timer 6 opvangen.
//	void TIM6_IRQHandler(void)
//	{
//		if((TIM6->SR & TIM_SR_UIF) == TIM_SR_UIF)
//		{
//			// Interruptvlag resetten
//			TIM6->SR &= ~TIM_SR_UIF;
//			
//			...
//		}
//	}
#endif
