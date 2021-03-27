#include <time.h>

//初始化操作，创建一个空的线性表
#define OK 1
#define ERROR 1
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node, *LinkList;

/*初始化一个链表*/
LinkList InitList();

/*按顺序打印整个链表*/
void Display(LinkList* L);

/*随机产生n个元素的值，建立带头节点的链表*/
void CreateList(LinkList* L, int n);

/*定位某结点的位置*/
int LocateElem(LinkList* L, ElemType e);

/*输入元素的位置，输入元素的值*/
int GetItem(LinkList L, int i, ElemType* e);

//单链表的插入
int ListInsert(LinkList L, int i, ElemType e);

//判断链表是否为空
int ListEmpty(LinkList L);

//清空链表
int ClearList(LinkList *L);

//删除链表元素
int ListDelete(LinkList *L,int i,ElemType *e);

int ListLength(LinkList* L);





