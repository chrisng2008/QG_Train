#include <time.h>

//初始化操作，创建一个空的线性表
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
}LNode, * LinkedList;
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

/*初始化一个链表*/
LinkedList InitList();

/*按顺序打印整个链表*/
void Display(LinkedList* L);

/*随机产生n个元素的值，建立带头节点的链表*/
void CreateList(LinkedList* L, int n);

/*定位某结点的位置*/
int LocateElem(LinkedList* L, ElemType e);

/*输入元素的位置，输入元素的值*/
int GetItem(LinkedList L, int i, ElemType* e);

//单链表的插入
int ListInsert(LinkedList L, int i, ElemType e);

//判断链表是否为空
int ListEmpty(LinkedList L);

//清空链表
int ClearList(LinkedList*L);

//删除链表元素
int ListDelete(LinkedList*L,int i,ElemType *e);

int ListLength(LinkedList* L);





