#include "header.h"
#include "malloc.h"

/*传入一个链表，获取第n个元素,并将元素传入e中*/
int GetItem(LinkList *L, int i, ElemType* e)
{
    LinkList p;
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
    return OK;
}

int ListInsert(LinkList *L, int i,ElemType e)
{
    int j = 1;
    LinkList p,s;
    p = *L;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    //生成新结点
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}   



int ListEmpty(LinkList *L)
{
    if ((*L)->next == NULL)
        return TRUE;
    return FALSE;
}

int ClearList(LinkList *L)
{
    LinkList p,s;
    p = (*L)->next;
    while (p)
    {
        s = p->next;
        free(p);
        p = s;
    }
    (*L)->next = NULL;
    return OK;
}

int ListDelete(LinkList* L, int i, ElemType* e)
{
    LinkList p, s;
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
    return OK;

}

int ListLength(LinkList* L)
{
    LinkList p;
    p = (*L)->next;
    int j = 0;
    while (p)
    {
        p = p->next;
        j++;
    }
    return j;
}


int LocateElem(LinkList* L, ElemType e)
{
    LinkList p;
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

void CreateList(LinkList *L,int n)
{
    srand(time(0));//初始化随机种子
    int i;
    * L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    LinkList p;
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;//生成1-100的随机数;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void Display(LinkList* L)//打印链表
{
    LinkList p;
    p = (*L)->next;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}

LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}
