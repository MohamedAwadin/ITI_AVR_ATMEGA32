#ifndef UTILS_H_
#define UTILS_H_

/*****************************Utils***********************************/
#define SET_BIT(REG, BIT)			(REG = REG | (1 << BIT))
#define CLEAR_BIT(REG, BIT)			(REG = REG & (~(1 << BIT)))
#define READ_BIT(REG, BIT)			((REG>>BIT) & 1)
#define TOGGLE_BIT(REG, BIT)        (REG = REG ^ (1 << BIT))
#define WRITE_BIT(REG, BIT, VALUE)  (REG = (REG&(~(1<<BIT)))|(VALUE << BIT))
/***********************************************************************/


#endif /*UTILS_H_*/ 