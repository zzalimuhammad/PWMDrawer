/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */

#include "std_types.h"
#include "glcd.h"
#include "pwm.h"
#include "app.h"
#include "icu.h"
#include "string.h"

extern int duty;

/* If you use internal MC PWM "Timer0" use this function to initiation the APP */

void PWM_Drawer_internal_init(u8 mode,u8 freq,u8 duty)
{
	GLCD_Init();
	GLCD_ClearAll();
	PWM_Start(mode,freq);
	PWM_SetDuty(duty);
}

/* if u use external PWM Signal Source use this function to initiation the APP */

void PWM_Drawer_external_init(void)
{
	GLCD_Init();
	GLCD_ClearAll();
}

/* Use this Function to Draw a Signal Waveform anywise intrenal or external */

void PWM_Draw_Signal(void)
{
	int pereidon=0; 
	int pereidoff=0;
	/* Start time arrow */
	
	char arrow[15]={0};
	strcat(arrow,"$"); // left arrow 

	
	
	/* Start square wave */
	char pulse [40];
	strcat(pulse,"&");	//rising edge
	
	
	
	/* This loop in order to Generate the waves 
	is completely synchronized with the duty and the time of on and off */
	for (u32 i = 0;i<2;i++)
	{
		for (u32 j=0;j<(duty/10);j++)
		{
			strcat(pulse,"'");	//on time
			pereidon++;
		}
		strcat(pulse,")");	//falling edge
		for (u32 k=0;k<(10-(duty/10));k++)
		{
			strcat(pulse,"("); // off time
			pereidoff++;
		}
		strcat(pulse,"&");	// rising edge
	}
	
	
	/* This loop made To make the arrow completely in sync with the cycle time */
	for(int i=(pereidon+pereidoff)/2;i>0;i--)
	{
		strcat(arrow,"#"); // arrow body
	}
	strcat(arrow,"@"); // right arrow
	
	GLCD_String(6,arrow,Left); /* Display arrow */
	GLCD_String(7,pulse,Left); /* Display squareWave */
	
}

/* Use this function to Get all 3 the PWM signal parameters Duty frequency and period time */

void PWM_Get_Signal(void)
{
	ICU_GetPWM();
}