#include "duLinkedList.h"
#include "malloc.h"
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    *L = (DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->next = NULL;
	(*L)->prior = NULL;
    (*L)->data = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p;
    while (*L) 
    {
        p = (*L)->next;
        free(*L);
        *L = p;
        if (p)
            p->prior = NULL;
    }
    return SUCCESS;
	
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (!p)
        return ERROR;
    if (p->prior) {
        p->prior->next = q;
        q->prior = p->prior;
    }
    q->next = p;
    p->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (p->next == NULL&&p->prior==NULL)
    {
        q->prior = NULL;
        q->next = p;
        p->prior = q;
    }
    else
    {
        q->next = p->next;
        q->prior = p;
        p->next->prior = q;
        p->next = q;
    }
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    *e = p->next->data;
    p = p->next;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    DuLinkedList p = L;
        while (p) {
            visit(p->data);
            p = p->next;
        }
        printf("\n");
    
}
void pf(ElemType e) {
    printf("%d  ", e);
}

//void CreateDuLList(DuLinkedList* L)
//{
//    int i;
//    srand(time(0));//初始化随机种子
//    DuLinkedList p=L;
//    for (i = 0; i < 5; i++)
//    {
//        DuLinkedList r = (DuLinkedList)malloc(sizeof(DuLNode));
//        r->data= rand() % 100 + 1;//生成1-100的随机数;
//        InsertAfterList_DuL(p, r);
//    }
//}
void Display(DuLinkedList * L)//打印链表
{
    DuLinkedList p = *L;
    do {
        if (p == NULL)
        {
            printf("The list is empty\n");
            break;
        }
            
        printf("%d ", p->data);
        p = p->next;
    } while (p);
    printf("\n");
}
void CreateList(DuLinkedList *L)
{
     
     srand(time(0));//初始化随机种子
     for (int i = 0; i < 5; i++)
     {
         DuLinkedList r = (DuLinkedList)malloc(sizeof(DuLNode));
         r->prior = NULL;
         r->data= rand() % 100 + 1;//生成1-100的随机数;
         DuLinkedList p = *L;
         r->next = p;
         p->prior = r;
         *L = r;
     }

}