/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */

#ifndef GLCD_H_
#define GLCD_H_

#include "dio.h"
#include "std_types.h"


#define Data_Port			PORTA	/* Define data port for GLCD */
#define Command_Port		PORTC	/* Define command port for GLCD */
#define Data_Port_Dir		DDRA	/* Define data port for GLCD */
#define Command_Port_Dir	DDRC	/* Define command port for GLCD */

#define RS					PIN0		/* Define control pins */
#define RW					PIN1		/* Define control pins */
#define EN					PIN2		/* Define control pins */
#define CS1					PIN3		/* Define control pins */
#define CS2					PIN4		/* Define control pins */
#define RST					PIN5		/* Define control pins */

#define Left				(0)			/* Define side */
#define Right				(1)			/* Define control pins */

#define TotalPage			8			/* number of pages */


void GLCD_Init(void);		/* initiation function */
void GLCD_Command(char Command);	/* send instruction */
void GLCD_ClearAll(void);		/* clear all on screen */
void GLCD_String(char page_no, char *str,u8 side);		/* Display string from custom char */






#endif /* GLCD_H_ */