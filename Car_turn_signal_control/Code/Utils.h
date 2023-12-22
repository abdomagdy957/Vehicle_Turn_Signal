
#ifndef UTILS_H_
#define UTILS_H_

#define  SET_BIT(REG,BIT)			(REG |= (1<<BIT))
#define  CLEAR_BIT(REG,BIT)			(REG &= ~(1<<BIT))
#define  TOGGLE_BIT(REG,BIT)		(REG ^= (1<<BIT))
#define  READ_BIT(REG,BIT)			((REG>>BIT)&1)



#endif /* UTILS_H_ */