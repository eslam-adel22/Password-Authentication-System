/*
 * BIT_MATH.h
 *
 *  Created on: Aug 28, 2026
 *      Author: tisla
 */

#ifndef INCLUDE_COMMON_BIT_MATH_H_
#define INCLUDE_COMMON_BIT_MATH_H_

#define SET_BIT(REG , BIT_NO)       REG |= (1 << BIT_NO)
#define CLR_BIT(REG , BIT_NO)       REG &= ~(1 << BIT_NO)
#define TOGGLE_BIT(REG , BIT_NO)    REG ^= (1 << BIT_NO)
#define READ_BIT(REG , BIT_NO)      (REG >> BIT_NO) &1

#endif /* INCLUDE_COMMON_BIT_MATH_H_ */
