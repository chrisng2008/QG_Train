#include "header.h"
#include "malloc.h"

/*传入一个链表，获取第n个元素,并将元素传入e中*/
int GetItem(LinkedList *L, int i, ElemType* e)
{
    LinkedList p;
    p = (*L)->next;//使P指向L的第一个结点
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)//p为空或者i<0时返回ERROR
        return ERROR;
    *e = p->data;
    return SUCCESS;
}

int ListInsert(LinkedList*L, int i,ElemType e)
{
    int j = 1;
    LinkedList p,s;
    p = *L;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    //生成新结点
    s = (LinkedList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return SUCCESS;
}   



int ListEmpty(LinkedList*L)
{
    if ((*L)->next == NULL)
        return SUCCESS;
    return ERROR;
}

int ClearList(LinkedList*L)
{
    LinkedList p,s;
    p = (*L)->next;
    while (p)
    {
        s = p->next;
        free(p);
        p = s;
    }
    (*L)->next = NULL;
    return SUCCESS;
}

int ListDelete(LinkedList* L, int i, ElemType* e)
{
    LinkedList p, s;
    int j = 1;
    p = *L;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
        return ERROR;
    s = p->next;
    *e = s->data;
    p->next = p->next->next;
    free(s);
    return SUCCESS;

}

int ListLength(LinkedList* L)
{
    LinkedList p;
    p = (*L)->next;
    int j = 0;
    while (p)
    {
        p = p->next;
        j++;
    }
    return j;
}


int LocateElem(LinkedList* L, ElemType e)
{
    LinkedList p;
    p = (*L);
    int j = 0;
    while (p)
    {
        p = p->next;
        j++;
        if (p->data == e)
            break;
    }
    printf("%d\n", j);
    return j;
}

void CreateList(LinkedList *L,int n)
{
    srand(time(0));//初始化随机种子
    int i;
    * L = (LinkedList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    LinkedList p;
    for (i = 0; i < n; i++)
    {
        p = (LinkedList)malloc(sizeof(LNode));
        p->data = rand() % 100 + 1;//生成1-100的随机数;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void Display(LinkedList* L)//打印链表
{
    LinkedList p;
    p = (*L)->next;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkedList InitList()
{
    LinkedList L = (LinkedList)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}
