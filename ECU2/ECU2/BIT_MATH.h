/*
 * BIT_MATH.h
 *
 * Created: 25/07/2020 06:38:24 م
 *  Author: Ali
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT)  (REG |= (1<<BIT))
#define CLR_BIT(REG,BIT)  (REG &=~ (1<<BIT))
#define Toggle_BIT(REG,BIT) (REG ^= (1<<BIT))
#define GET_BIT(REG,BIT)  ((REG >> BIT) & (0X01))


#endif /* BIT_MATH_H_ */