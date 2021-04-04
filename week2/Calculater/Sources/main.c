#include <stdio.h>
#include "sqstack.h"
#define  MAX 255
int main()
{
    char str[MAX];/*储存表达式*/
    printf("请输入你要计算的表达式:\n");
    gets(str);

    int i = 0;
    int value = 0;      /*储存数字*/
    int flag = 0;       /*标识作用*/
    int old_ope;

    sqstack* snum, * sope;      /*定义两个栈，一个储存字符，一个储存数字*/

    snum = sqstack_create();  // 创建存放数字的栈

    sope = sqstack_create();  // 创建存放运算符号的栈

    while (str[i] != '\0')
    {
        //获取输入的数字
        if (str[i] >= '0' && str[i] <= '9')
        {
            value = value * 10 + str[i] - '0';
            flag = 1;
        }
        else//ope
        {
            if (flag)
            {
                //flag = 1说明value里面存储了数字，将其入栈
                sqstack_push(snum, value);
                //num标志清零，value存放数字的变量清零
                flag = 0;
                value = 0;
            }
            if (str[i] == ')')
            {
                //如果是右括号，则
                deal_bracket(snum, sope);
            }
            else//+-*/(等情况 
            {
                deal_ope(snum, sope, str[i]);
            }
        }
        i++;
    }
    //如果flag = 1.说明value里面还有数值,将其入栈 
    if (flag)
    {
        sqstack_push(snum, value);
    }
    //然后将符号与数字依次出栈计算。数字出栈计算完成之后回再次在calc中入栈
    while (!sqstack_is_empty(sope))
    {
        sqstack_pop(sope, &old_ope);
        calc(snum, old_ope);
    }
    //取出数字栈最后剩下的数字，就是最后的答案
    sqstack_pop(snum, &value);
    //打印结果
    printf("%s = %d\n", str, value);

    return 0;
}
