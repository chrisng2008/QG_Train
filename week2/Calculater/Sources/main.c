#include <stdio.h>
#include "calc.h"
Status get_pri(int ope)//判断优先级函数
{
	switch (ope)
	{
	case '(':return 0;
	case '+':
	case '-':return 1;
	case '*':
	case '/': return 2;
	default:return -1;
	}
}

Status compute(sqstack* snum, int ope)
{
	int n, n1, n2;
	//获取栈顶的两个值
	sqstack_pop(snum, &n1);
	sqstack_pop(snum, &n2);
	//计算
	switch (ope)
	{
	case '+':n = n1 + n2; break;
	case '-':n = n2 - n1; break;
	case '*':n = n2 * n1; break;
	case '/':n = n2 / n1; break;
	}
	/*计算完成后入栈*/
	sqstack_push(snum, n);
}

/*只有符号才会入栈*/
Status compute_ope(sqstack* snum,sqstack* sope, int ope)
{
	int old_ope;
	//如果sope符号栈是空战或者符号为'('
	if (sqstack_is_empty(sope) || ope == '(')
	{
		//将符号入栈
		sqstack_push(sope, ope);
		return;
		sqstack_top(sope, old_ope);//获得当前栈顶项
	}
	//如果入栈符号大于栈顶符号，直接入栈
	if (get_pri(ope) > get_pri(old_ope))
	{
		sqstack_push(sope, ope);
		return;
	}
	while (get_pri(ope) <= get_pri(old_ope))
	{
		sqstack_pop(sope, &old_ope);
		compute(snum, old_ope);
		if (sqstack_is_empty(sope))
			break;
	}
	sqstack_push(sope, ope);
}
//处理‘)’符号
void deal_back(sqstack* snum, sqstack* sope, int ope)
{
	int old_ope;
	//获得当前栈顶符号
	sqstack_top(sope, &old_ope);
	while (old_ope != '(')
	{
		sqstack_pop(sope, &old_ope);
		compute(snum, old_ope);
		sqstack_top(snum, &old_ope);
	}
	sqstack_pop(sope, &old_ope);
}

int main()
{
	char str[MAXSIZE];
	/*储存表达式*/
	printf("请输入你需要计算的表达式:\n");
	int value = 0;
	int flag = 0;
	int old_ope;
	int i = 0;

	sqstack* snum, * sope;
	/*创建两个栈，一个储存数字一个储存符号*/
	snum = sqstack_create();/*储存数字*/
	sope = sqstack_create();/*储存符号*/
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9'){
			value = value*10+str[i] - '0';
			flag = 1;
		}
		else
		{
			if (flag)
			{
				/*flag = 1说明value中储存了数字,入栈*/
				sqstack_push(snum, value);
				//标志变量清零
				flag = 0;
				value = 0;
			}
			if(str[i]==')')
			{
				deal_back(snum,sope, str[i]);
			}
			else
			{
				deal_ope(snum, sope, str[i]);
			}
			i++;
		}
		
	}
	if (flag == 1)
	{
		sqstack_push(snum, value);
	}
	while (!sqstack_is_empty(sope))
	{
		sqstack_pop(sope, &old_ope);
		compute(snum, old_ope);
	}
	sqstack_pop(snum, &value);
	printf("%s = %d\n", str, value);


	return 0;
}