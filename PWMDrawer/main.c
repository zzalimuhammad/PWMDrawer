

#include "app.h"

/* For internal PWM "Timer0" : Just copy & paste ! */
// modes :
// Timer0FastPWM
// Timer0PhaseCorrectPWM

// freq :

// ClockValue_16000KHZ			>> 62.5 KHz
// ClockValue_2000KHZ			>> 7.8	KHZ

int main(void)
{
	/* Internal PWM SIGNAl */
	
    //PWM_Drawer_internal_init(Timer0FastPWM,ClockValue_16000KHZ,50);
	
	/* External PWM SIGNAl */
	
	PWM_Drawer_external_init();
	
    while (1) 
    {
		PWM_Get_Signal();	//Signal measurement
		PWM_Draw_Signal();	//Sign drawing
    }
}

