#include "SqStack.h"

Status initStack(SqStack* s, int sizes)//³õÊ¼»¯Õ»
{
    s->elem = (ElemType*)malloc(sizeof(ElemType) * sizes);
    s->top = -1;
    s->size = sizes;
}




Status isEmptyStack(SqStack* s)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
    if (s->top == 0)
        return SUCCESS;
}

Status getTopStack(SqStack* s, ElemType* e) //µÃµ½Õ»¶¥ÔªËØ
{
    if (s->top == -1)
        return ERROR;
    *e = s->elem[s->top];
    return SUCCESS;
}

Status clearStack(SqStack* s)//Çå¿ÕÕ»
{
    if (s->top == -1)
        return ERROR;
    s->top = -1;
    return SUCCESS;
    
    
}

Status destroyStack(SqStack* s)//Ïú»ÙÕ»
{
    free(s->elem);
    s->top = 0;
    s->size = 0;
    return SUCCESS;
}
Status stackLength(SqStack* s, int* length)//¼ì²âÕ»³¤¶È
{
    *length = s->top+1;
    return SUCCESS;
}



Status pushStack(SqStack* s, ElemType data)//ÈëÕ»
{
    if (s->top == s->size - 1)/*ÅÐ¶ÏÕ»ÊÇ·ñÒÑÂú*/
        return ERROR;
    s->top++;
    s->elem[s->top] = data;
    return SUCCESS;
}
Status popStack(SqStack* s, ElemType* data)//³öÕ»
{
    if (s->top == -1)
        return ERROR;
    *data = s->elem[s->top];
    s->top--;
    return SUCCESS;
}

void clearScreen()
{
    system("cls");
}