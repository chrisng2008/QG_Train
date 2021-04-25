#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "LinkStack.h"
#include<conio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "binary_sort_tree.h"


Status initLStack(LinkStack* s)//初始化栈
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
	S->next = NULL;
	s->top = S;
	s->count = 0;
	return succeed;
}


Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->count == 0)
		return SUCCESS;
	return ERROR;
}



Status getTopLStack(LinkStack* s, NodePtr e)//得到栈顶元素
{
	if (s->count == 0)
		return ERROR;
	else
	    *e = s->top->data;
	return SUCCESS;
}




Status clearLStack(LinkStack* s)//清空栈
{
	if (s->count == 0)
		return ERROR;
	NodePtr e;
	e=(NodePtr)malloc(sizeof(Node));
	for (int i = s->count; i > 0; i--)
	{
		popLStack(s, e);
	}
	return SUCCESS;
}


Status destroyLStack(LinkStack* s)//销毁栈
{
	if (isEmptyLStack(s))
		return ERROR;
	while (s->top!=NULL)
	{
		LinkStackPtr p = s->top;
		s->top = s->top->next;
		free(p);
	}
	s->count = 0;
	return SUCCESS;
}




Status LStackLength(LinkStack* s, int* length)//检测栈长度
{
	*length = s->count;
	return SUCCESS;
}



Status pushLStack(LinkStack* s, NodePtr data)//入栈
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("动态分配内存失败!\n");
		return ERROR;
	}
	p->data = *data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}




Status popLStack(LinkStack* s, NodePtr data)//出栈
{
	//*data = s->top->data;
	*data = s->top->data;
	LinkStackPtr p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}

Status clearScreen()
{
	system("cls");
}


//int read()
//{
//	int i;
//	int value;
//	char num[100];
//	do
//	{
//		printf("请输入数字\n");
//		scanf("%s", num);
//		if (i = strspn(num, "0123456789"))
//		{
//			value = atoi(num);
//			break;
//		}
//		else
//			printf("输入错误，");
//	} while (i == 0);
//	return value;
//}

#endif