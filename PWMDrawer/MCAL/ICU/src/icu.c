/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */


#include "icu.h"
#include "clock.h"
#include "glcd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int duty;

/* Function That get all PWM parameter duty,frequency and period time */
void ICU_GetPWM(void) 
{
	unsigned int A,B,C,Ton,T;;
	char duty_cycle[7]={0};
	char frequency[14]={0};

		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);  	/* Clear ICF (Input Capture flag) flag */

		TCCR1B = 0xC1;  	/* Rising edge, no prescaler ,Noise cansceld */
		while ((TIFR&(1<<ICF1)) == 0);
		A = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
		TCCR1B = 0xC1;  	/* Falling edge, no prescaler Noise cansceld */
		while ((TIFR&(1<<ICF1)) == 0);
		B = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */
		
		TCCR1B = 0x81;  	/* Rising edge, no prescaler Noise cansceld */
		while ((TIFR&(1<<ICF1)) == 0);
		C = ICR1;  		/* Take value of capture register */
		TIFR = (1<<ICF1);  	/* Clear ICF flag */

		TCCR1B = 0;  		/* Stop the timer */
		
		if(A<B && B<C)  	/* Check for valid condition, 
					to avoid timer overflow reading */
		{
			Ton=C-B;
			T=B-A;
			
			
			/* Calculate frequency */
			u32 freq= F_CPU/T;
			freq=freq/1000;
			
			/* Calculate duty cycle */
			duty =((float) Ton /(float)T)*100;
 
			/* Calculate Time */
			f32 time =(1/(f32)freq);
			
			/* Display frequency */
			ltoa(freq,frequency,10);
			char fr[100]="Freq:";
			char hz[5]="Khz";
			strcat(fr,frequency);
			strcat(fr,hz);
			GLCD_String(1,fr,Left);
			/* Display Duty */
			sprintf(duty_cycle,"   Duty:%d",duty);
			strcat(duty_cycle,"%");
			GLCD_String(1,duty_cycle,Right);
			
			/* Display Time */
			Time2String(time);
			
		}
		
		else
		{
			GLCD_ClearAll();
			GLCD_String(1,"OUT OF RANGE!!",Left);
		}
		_delay_ms(50);
	
}

/* Function That Convert time float value to String */
void Time2String(f32 data) 
{
	
	int cnt=0;
	char d[10];
	while( data <1)
	{
		
		data=data *10;
		cnt++;
	}
	data=data*10;
	ltoa(data,d,10);
	char ti[100]="";
	char sec[5]="ms";
	strcat(ti,"0.");
	for (int i = 0 ; i<(cnt-1);i++)
	{
		strcat(ti,"0");
	}
	strcat(ti,d);
	
	//strcat(ti,A);
	strcat(ti,sec);
	GLCD_String(4,ti,Left);
	
}

