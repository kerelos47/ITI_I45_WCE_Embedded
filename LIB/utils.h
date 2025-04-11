#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(REG, BIT_NO)	(REG |= (1<<BIT_NO))
#define CLEAR_BIT(REG, BIT_NO)	(REG&= (~(1<<BIT_NO)))
#define TOGGLE_BIT(REG, BIT_NO)	(REG^= (1<<BIT_NO))
#define GET_BIT(REG, BIT_NO)	((REG>>BIT_NO) & 0x01)
#define WRITE_BIT(REG, BIT_NO, VAL) ((REG) = ((REG) & ~(1 << (BIT_NO))) | ((VAL) << (BIT_NO)))


#endif
