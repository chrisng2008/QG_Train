#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "binary_sort_tree.h"
typedef enum function
{
	INITSTACK = 1,
	ISEMPTY,
	GETTOPLSTACK,
	CLEARLSTACK,
	DESTORYLSTACK,
	LSTACKLENGTH,
	PUSHSTACK,
	POPLSTACK,
	CLEARSCREEN,
}function;

typedef  struct StackNode
{
	Node data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,NodePtr e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,NodePtr data);//入栈
Status popLStack(LinkStack *s,NodePtr data);//出栈
Status clearScreen();
int read();


#endif 
