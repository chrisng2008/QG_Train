#include "sqstack.h"


/*优先级判断函数*/
/*（的优先级最小，+和-的优先级居中，*和/的优先级最先*/
int get_pri(int ope)
{
    switch (ope)
    {
    case '(':   return 0;
    case '+':
    case '-':   return 1;
    case '*':
    case '/':   return 2;
    default:   return -1;
    }
}
/*计算栈顶的元素，计算完后再次入栈*/
void calc(sqstack* snum, int ope)
{
    int n, n1, n2;
    //依次获得数值栈的栈顶两个数
    sqstack_pop(snum, &n1);
    sqstack_pop(snum, &n2);
    //计算
    switch (ope)
    {
    case '+':   n = n1 + n2; break;
    case '-':   n = n2 - n1; break;
    case '*':   n = n1 * n2; break;
    case '/':   n = n2 / n1; break;
    }
    //计算完成再次入栈
    sqstack_push(snum, n);
}
/* 只有符号才会进入该函数 */
void deal_ope(sqstack* snum, sqstack* sope, int ope)
{
    int old_ope;
    //如果sope符号栈是空栈或者符号为‘(’
    if (sqstack_is_empty(sope) || ope == '(')
    {
        sqstack_push(sope, ope);
        return;
    }

    sqstack_top(sope, &old_ope);
    //将当前的符号栈的栈顶符号与传入的符号进行优先级比较
    if (get_pri(ope) > get_pri(old_ope))
    {
        //传入符号大于当前栈顶，则将传入符号入栈
        sqstack_push(sope, ope);
        return;
    }
    //如果传入的符号优先级小于当前栈顶符号
    while (get_pri(ope) <= get_pri(old_ope))
    {
        //将当前栈顶的符号取出与数字栈中顶端的两个数字进行计算
        sqstack_pop(sope, &old_ope);
        calc(snum, old_ope);
        //如果计算完毕之后符号栈为空则break;
        if (sqstack_is_empty(sope))
        {
            break;
        }
        //再次取出一个当前栈符号与传入符号比较
        sqstack_top(sope, &old_ope);
    }
    //进行完毕优先级计算之后，再将新传入的符号入栈
    sqstack_push(sope, ope);
}
/*处理),如果遇到),则将（前的所有符号出栈然后计算*/
void deal_bracket(sqstack* snum, sqstack* sope)
{
    int old_ope;
    //获得当前的符号栈的栈顶符号
    sqstack_top(sope, &old_ope);
    //直到找到预期配对的左括号。因为正确的算式中左右括号一定是配对的
    while (old_ope != '(')
    {
        //当前符号出栈然后将数字出栈两个进行计算,在括号内优先级最高，
        sqstack_pop(sope, &old_ope);
        calc(snum, old_ope);
        //然后再次取出当前符号栈栈顶符号，至到出现‘(’
        sqstack_top(sope, &old_ope);
    }
    //最后将出现的左扩号出栈丢弃
    sqstack_pop(sope, &old_ope);
}