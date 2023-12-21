/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */


#ifndef PWM_H_
#define PWM_H_

/* include used LIB */

#include "std_types.h"


/* Define " Timer0 " Registers */

#define TCCR0		(*(volatile u8*)0x53)	/* Timer counter control register */

/* Define all 8 Bits of TCCR0 */

#define CS00	 (0)	 // Bit number 0 of register  
#define CS01	 (1)	 // Bit number 1 of register 
#define CS02	 (2)	 // Bit number 2 of register 
#define WGM01	 (3)	 // Bit number 3 of register 
#define COM00	 (4)	 // Bit number 4 of register 
#define COM01	 (5)	 // Bit number 5 of register 
#define WGM00	 (6)	 // Bit number 6 of register 
#define FOC0	 (7)	 // Bit number 7 of register 

#define TCNT0		(*(volatile u8*)0x52)	/* register hold the timer Count and it is incremented on every timer "tick". */
#define OCR0		(*(volatile u8*)0x5C)	/* Output Compare Register */

/* Define Timer0 Top  */

#define Timer0Top			   (255)

/* Define all " Timer0 " Modes */

#define Timer0Stopped			(0b00000000)		// Timer 0 is OFF
#define Time0Normal				(0b00000000)		// Timer 0 in Normal Mode
#define Timer0CTC				(0b00001000)		// Timer 0 in CTC Mode 
#define Timer0FastPWM			(0b01101000)		// Timer 0 in Fast PWM Mode
#define Timer0PhaseCorrectPWM	(0b01100000)		// Timer 0 in Phase Correct PWM Mode

/* Define all Timer 0 Clock Value */

#define ClockValue_0KHZ			(0b00000000)		// timer is OFF
#define ClockValue_16000KHZ		(0b00000001)		// Fclk
#define ClockValue_2000KHZ		(0b00000010)		// Fclk/8
#define ClockValue_250KHZ		(0b00000011)		// Fclk/64
#define ClockValue_62KHZ		(0b00000100)		// Fclk/256
#define ClockValue_15KHZ		(0b00000101)		// Fclk/1024

/* Define all Timer 0 Fast PWM Freq */

#define PWM_F_62_5KHZ			(0)		// If you choice Flck
#define PWM_F_7_8KHZ			(1)		// If you choice Flck/8
#define PWM_F_1KHZ				(2)		// If you choice Flck/64
#define PWM_F_244HZ				(3)		// If you choice Flck/256
#define PWM_F_61HZ				(4)		// If you choice Flck/1024

/*	Define all Timer 0 Phase correct PWM Freq	*/

#define PWM_F_31_25KHZ			(0)		// If you choice Flck
#define PWM_F_3_9KHZ			(1)		// If you choice Flck/8
#define PWM_F_500HZ				(2)		// If you choice Flck/64
#define PWM_F_122HZ				(3)		// If you choice Flck/256
#define PWM_F_30_5HZ			(4)		// If you choice Flck/1024

/* PWM Function */

void PWM_Start(u8 mode,u8 clk);		// This function Generate PWM Signal 

/* mode is it Fast PWM or Phase Correct PWM */
/* clk is a Clock source which it start from 0 to 1024 prescaler */

void PWM_SetDuty(u8 duty);			// This function Generate PWM signal with " duty " DutyCycle

/* duty is a DutyCycle value of PWM wave it a value for 0 % to 100 % " (0 >> 255) " */
 
#endif /* PWM_H_ */