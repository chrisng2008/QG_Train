#include "SqStack.h"

Status initStack(SqStack *s,int sizes)//初始化栈
{
    s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
    s->top=0;
    s->size=sizes;
}
    



Status isEmptyStack(SqStack *s)//判断栈是否为空
{
    if (s->top==0)
        return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
    if(s->top==0)
        return ERROR;
    *e=s->elem[s->top];
    return SUCCESS;
}

Status clearStack(SqStack *s)//清空栈
{
    int e;
	for(int i=s->top;i>0;i--)
    {
        popStack(s,&e);
        printf("%d",e);
    }
    return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
    free(s->elem);
    s->top = 0;
    s->size = 0;
	return SUCCESS;
}
Status stackLength(SqStack *s,int *length)//检测栈长度
{
    *length=s->top+1;
    return SUCCESS;
}



Status pushStack(SqStack *s,ElemType data)//入栈
{
    if(s->top==s->size-1)/*判断栈是否已满*/
        return ERROR;
    s->top++;
    s->elem[s->top]=data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//出栈
{
    if(s->top==0)
        return ERROR;
    *data=s->elem[--s->top];
    return SUCCESS;
}