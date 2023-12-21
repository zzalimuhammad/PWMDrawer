/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */

#include "dio.h"
#include "std_types.h"
#include "bit_math.h"

void dio_setPinDirection(u8 portId, u8 pinId, u8 direction)
{
		switch(portId)
		{
			case PORTA_ID:
			if (direction == OUTPUT) //output
			{
				SET_BIT(DDRA,pinId);
			}
			else //input
			{
				CLEAR_BIT(DDRA,pinId);
			}
			break;
			
			case PORTB_ID:
			if (direction == OUTPUT) //output
			{
				SET_BIT(DDRB,pinId);
			}
			else //input
			{
				CLEAR_BIT(DDRB,pinId);
			}
			break;
			
			case PORTC_ID:
			if (direction == OUTPUT) //output
			{
				SET_BIT(DDRC,pinId);
			}
			else //input
			{
				CLEAR_BIT(DDRC,pinId);
			}
			break;
			
			case PORTD_ID:
			if (direction == OUTPUT) //output
			{
				SET_BIT(DDRD,pinId);
			}
			else //input
			{
				CLEAR_BIT(DDRD,pinId);
			}
			break;
		}
}

void dio_writeChannel(u8 portId, u8 pinId, u8 level)
{
	switch(portId)
	{
		case PORTA_ID:
		if (level == HIGH)
		{
			SET_BIT(PORTA,pinId);
		}
		else if (level == LOW)
		{
			CLEAR_BIT(PORTA,pinId);
		}
		else
		{
			/*	do nothing	*/
		}
		break;
		
		case PORTB_ID:
		if (level == HIGH)
		{
			SET_BIT(PORTB,pinId);
		}
		else if (level == LOW)
		{
			CLEAR_BIT(PORTB,pinId);
		}
		else
		{
			/*	do nothing	*/
		}
		
		break;

		case PORTC_ID:
		if (level == HIGH)
		{
			SET_BIT(PORTC,pinId);
		}
		else if (level == LOW)
		{
			CLEAR_BIT(PORTC,pinId);
		}
		else
		{
			/*	do nothing	*/
		}
		break;

		case PORTD_ID:
		if (level == HIGH)
		{
			SET_BIT(PORTD,pinId);
		}
		else if (level == LOW)
		{
			CLEAR_BIT(PORTD,pinId);
		}
		else
		{
			/*	do nothing	*/
		}
		break;
	}
}

u8 dio_readChannel(u8 portId, u8 pinId)
{
	u8 loc_pinRead = LOW;
	switch (portId)
	{
		case PORTA_ID:
		loc_pinRead = CHECK_BIT(PINA,pinId);
		break;
		
		case PORTB_ID:
		loc_pinRead = CHECK_BIT(PINB,pinId);
		break;

		case PORTC_ID:
		loc_pinRead = CHECK_BIT(PINC,pinId);
		break;
		
		case PORTD_ID:
		loc_pinRead = CHECK_BIT(PIND,pinId);
		break;
	}
	return loc_pinRead;
}

void dio_flipChannel(u8 portId, u8 pinId)
{
	switch(portId)
	{
		case PORTA_ID:
		FLIP_BIT(PORTA,pinId);
		break;
		
		case PORTB_ID:
		FLIP_BIT(PORTB,pinId);
		break;
		
		case PORTC_ID:
		FLIP_BIT(PORTC,pinId);
		break;
		
		case PORTD_ID:
		FLIP_BIT(PORTD,pinId);
		break;
	}
}

void dio_enablePullUp(u8 portId, u8 pinId)
{
	
	/* to enable pull up resistor  */
	/* Set DDRxn = 0 , PORTxn =1 , PINxn = | */
	
	switch (portId)
	{
		case PORTA_ID:
		SET_BIT(PORTA,pinId);
		break;
		
		case PORTB_ID:
		SET_BIT(PORTB,pinId);
		break;
		
		case PORTC_ID:
		SET_BIT(PORTC,pinId);
		break;
		
		case PORTD_ID:
		SET_BIT(PORTD,pinId);
		break;
	}
}



