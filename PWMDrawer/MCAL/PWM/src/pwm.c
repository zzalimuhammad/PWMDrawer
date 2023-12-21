/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */ 

/* include used LIB */

#include "pwm.h"
#include "dio.h"

void PWM_Start(u8 mode,u8 clk)
{
	
	DDRB=DDRB|(1<<3);		// Set OC0 As a Output >> PB3
	
	/*	set mode	*/
	
	TCCR0 |= mode ;			// Set Mode Of PWM
	 
	/*	set Clk Source	*/
		
	TCCR0 |= clk ;			// Set Clk Source from 0 >> 1024 Prescaler
	
}

void PWM_SetDuty(u8 duty)
{
	
	// Set DutyCycle
	
	OCR0 = ((f32)duty/100)*(Timer0Top);		// Set DutyCycle from 0 % >> 100 % "(0>>255)"
	 
}