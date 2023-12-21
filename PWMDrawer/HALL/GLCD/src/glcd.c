/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */

#include "Font_Header.h"
#include "glcd.h"
#include "clock.h"

#include <stdio.h>



void GLCD_Init()			/* GLCD initialize function */
{
	Data_Port_Dir = 0xFF;
	Command_Port_Dir = 0xFF;
	/* Select both left & right half of display & Keep reset pin high */
	Command_Port |= (1 << CS1) | (1 << CS2) | (1 << RST);
	_delay_ms(20);
	GLCD_Command(0x3E);		/* Display OFF */
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */
	GLCD_Command(0xC0);		/* Set z address (start line=0) */
	GLCD_Command(0x3F);		/* Display ON */
}

void GLCD_Command(char Command)		/* GLCD command function */
{
	Data_Port = Command;		/* Copy command on data pin */
	Command_Port &= ~(1 << RS);	/* Make RS LOW for command register*/
	Command_Port &= ~(1 << RW);	/* Make RW LOW for write operation */
	Command_Port |=  (1 << EN);	/* HIGH-LOW transition on Enable */
	_delay_us(5);
	Command_Port &= ~(1 << EN);
	_delay_us(5);
}

void GLCD_Data(char Data)		/* GLCD data function */
{
	Data_Port = Data;		/* Copy data on data pin */
	Command_Port |=  (1 << RS);	/* Make RS HIGH for data register */
	Command_Port &= ~(1 << RW);	/* Make RW LOW for write operation */
	Command_Port |=  (1 << EN);	/* HIGH-LOW transition on Enable */
	_delay_us(5);
	Command_Port &= ~(1 << EN);
	_delay_us(5);
}



void GLCD_ClearAll()			/* GLCD all display clear function */
{
	int i,j;
	/* Select both left & right half of display */
	Command_Port |= (1 << CS1) | (1 << CS2);
	for(i = 0; i < TotalPage; i++)
	{
		GLCD_Command((0xB8) + i);/* Increment page */
		for(j = 0; j < 64; j++)
		{
			GLCD_Data(0);	/* Write zeros to all 64 column */
		}
	}
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */
}

/* This Function Display String From custom char */

void GLCD_String(char page_no, char *str,u8 side)/* GLCD string write function */
{
	unsigned int i, column;
	unsigned int Page = ((0xB8) + page_no);
	unsigned int Y_address = 0;
	float Page_inc = 0.5;
	
	if (side==0)
	{
		Command_Port |= (1 << CS1);	/* Select Left half of display */
		Command_Port &= ~(1 << CS2);
	}
	else
	{
		Command_Port |= (1 << CS2);	/* Select Left Right of display */
		Command_Port &= ~(1 << CS1);
	}
	
	
	
	GLCD_Command(Page);
	for(i = 0; str[i] != 0; i++)	/* Print char in string till null */
	{
		if (Y_address > (1024-(((page_no)*128)+FontWidth)))
		break;
		if (str[i]!=32)
		{
			for (column=1; column<=FontWidth; column++)
			{
				if ((Y_address+column)==(128*((int)(Page_inc+0.5))))
				{
					if (column == FontWidth)
					break;
					GLCD_Command(0x40);
					Y_address = Y_address + column;
					Command_Port ^= (1 << CS1);
					Command_Port ^= (1 << CS2);
					GLCD_Command(Page + Page_inc);
					Page_inc = Page_inc + 0.5;
				}
			}
		}
		if (Y_address>(1024-(((page_no)*128)+FontWidth)))
		break;
		if((font[((str[i]-32)*FontWidth)+4])==0 || str[i]==32)
		{
			for(column=0; column<FontWidth; column++)
			{
				GLCD_Data(font[str[i]-32][column]);
				if((Y_address+1)%64==0)
				{
					Command_Port ^= (1 << CS1);
					Command_Port ^= (1 << CS2);
					GLCD_Command((Page+Page_inc));
					Page_inc = Page_inc + 0.5;
				}
				Y_address++;
			}
		}
		else
		{
			for(column=0; column<FontWidth; column++)
			{
				GLCD_Data(font[str[i]-32][column]);
				if((Y_address+1)%64==0)
				{
					Command_Port ^= (1 << CS1);
					Command_Port ^= (1 << CS2);
					GLCD_Command((Page+Page_inc));
					Page_inc = Page_inc + 0.5;
				}
				Y_address++;
			}
			GLCD_Data(0);
			Y_address++;
			if((Y_address)%64 == 0)
			{
				Command_Port ^= (1 << CS1);
				Command_Port ^= (1 << CS2);
				GLCD_Command((Page+Page_inc));
				Page_inc = Page_inc + 0.5;
			}
		}
	}
	GLCD_Command(0x40);	/* Set Y address (column=0) */
}
