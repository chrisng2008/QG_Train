#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define NULL 0
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

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

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
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
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
Status popLStack(LinkStack *s,ElemType *data);//出栈
Status clearScreen();


#endif 
