#include "sqstack.h"
//优先级判断函数
int get_pri(int ope);

/*（的优先级最小，+和-的优先级居中，*和/的优先级最先*/
void calc(sqstack* snum, int ope);

/* 只有符号才会进入该函数 */
void deal_ope(sqstack* snum, sqstack* sope, int ope);

/*如果检测到符号时')',则执行该函数，参数为数字栈和符号栈*/
void deal_bracket(sqstack* snum, sqstack* sope);