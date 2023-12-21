#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(REG,BIT_NO)  	(REG |= (1<<BIT_NO))
#define CLEAR_BIT(REG,BIT_NO)	(REG &= ~(1<<BIT_NO))
#define CHECK_BIT(REG,BIT_NO)	((REG>>BIT_NO)&1)
#define FLIP_BIT(REG,BIT_NO)	(REG ^= (1<<BIT_NO))

#endif