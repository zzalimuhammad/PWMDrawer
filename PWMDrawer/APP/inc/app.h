/* ???????????????????????????????????????????????????????????????????????? */
/* ?     _              _     _                             _      _   _  ? */
/* ?    / \     _   _  | |_  | |__     ___    _ __   _     / \    | | (_) ? */
/* ?   / _ \   | | | | | __| | '_ \   / _ \  | '__| (_)   / _ \   | | | | ? */
/* ?  / ___ \  | |_| | | |_  | | | | | (_) | | |     _   / ___ \  | | | | ? */
/* ? /_/   \_\  \__,_|  \__| |_| |_|  \___/  |_|    (_) /_/   \_\ |_| |_| ? */
/* ?                                                                      ? */
/* ???????????????????????????????????????????????????????????????????????? */



#ifndef APP_H_
#define APP_H_

#include "std_types.h"
#include "pwm.h"

/* if You use internal PWM signal use Timer0 */
void PWM_Drawer_internal_init(u8 mode,u8 freq,u8 duty); 
/* if you use external PWM source */
void PWM_Drawer_external_init(void);	
/* Draw signal */
void PWM_Draw_Signal(void);	
/* Get Duty , period and Freq */							
void PWM_Get_Signal(void);							


#endif /* APP_H_ */