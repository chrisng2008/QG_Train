#include "calc.h"
#include <stdio.h>

sqstack* sqstack_create()/*创建栈*/
{
	sqstack *s;
	s=(sqstack*)malloc(sizeof(*s));
	s->top=-1;
	return s;
}
Status sqstack_push(sqstack *s, int data) /*入栈*/
{
	if(s->top==MAXSIZE-1)/*如果入栈超过栈空间*/
		return ERROR;
	s->data[++s->top]=data;
	return SUCCESS;

}

Status sqstack_pop(sqstack *s, int *e) /*出栈*/
{
	if (s->top == -1)
		return ERROR;
	*e = s->data[s->top];
	s->top--;
	return SUCCESS;
}
Status sqstack_top(sqstack *s, int *e) /*查看栈顶的值*/
{
	if (s->top == -1)
		return ERROR;
	*e = s->data[s->top];
	return SUCCESS;
}
Status sqstack_is_empty(sqstack* s)/*判断栈是否为空*/
{
	if (s->top == 0)
		return SUCCESS;
}
Status sqstack_display(sqstack* s)/*显示栈内容,调试时用*/
{
	if (s->top == -1)
		return ERROR;
	for (int i = s->top; i >= 0; i--)
	{
		printf("%d  ", s->data[i]);
		printf("\n");
	}
	return SUCCESS;
}