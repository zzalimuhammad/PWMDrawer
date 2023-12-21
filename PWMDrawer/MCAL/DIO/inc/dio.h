/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */



#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"

/* define DDRx */

#define DDRA	*((volatile u8 *)0x3A)
#define DDRB	*((volatile u8 *)0x37)
#define DDRC	*((volatile u8 *)0x34)
#define DDRD	*((volatile u8 *)0x31)

/* define POTRx */

#define PORTA	*((volatile u8 *)0x3B)
#define PORTB	*((volatile u8 *)0x38)
#define PORTC	*((volatile u8 *)0x35)
#define PORTD	*((volatile u8 *)0x32)

/* define PINx */

#define PINA	*((volatile u8 *)0x39)
#define PINB	*((volatile u8 *)0x36)
#define PINC	*((volatile u8 *)0x33)
#define PIND	*((volatile u8 *)0x30)

/* define Input / Output */

#define OUTPUT				(1)
#define INPUT				(0)

/* define Logic 1,0 */

#define HIGH				(1)
#define LOW					(0)

/* define Ports IDs */

#define PORTA_ID			(0)
#define PORTB_ID			(1)
#define PORTC_ID			(2)
#define PORTD_ID			(3)

/* define Pins IDs */

#define PIN0				(0)
#define PIN1				(1)
#define PIN2				(2)
#define PIN3				(3)
#define PIN4				(4)
#define PIN5				(5)
#define PIN6				(6)
#define PIN7				(7)

/* Function Declaration  */

/* This function set pin direction , write 1 to be OUTPUT write 0 to be INPUT */
void dio_setPinDirection	(u8 portId, u8 pinId, u8 direction);
 
/* This function write on pin , write 1 to be HIGH write 0 to be LOW */
void dio_writeChannel		(u8 portId, u8 pinId, u8 level);

/* This function Read value from pin  */
u8 dio_readChannel			(u8 portId, u8 pinId);

/* This function toggle pin Status */
void dio_flipChannel		(u8 portId, u8 pinId);

/*This function Enable internal pull up resistor */
void dio_enablePullUp		(u8 portId, u8 pinId);

#endif /* DIO_H_ */