#include "linkedList.h"



/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    return OK;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList p, s;
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

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (p == NULL || q == NULL)
        return ERROR;
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList r;
    r = p->next;
    p->next = p->next->next;
    *e = r->data;
    free(r);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
   LinkedList p = L->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

void pf(ElemType e) {
    printf("%d ", e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LinkedList p;
    p = L->next;
    while(p)
    {
        if (p->data == e)
            return SUCCESS;
        p = p->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList p,r, q;
    p = NULL;
    r = (*L)->next;
    q = r->next;
    if (r == NULL || q == NULL)/*判断是否为空表或者只有一个节点*/
        return;
    while (q) {
        r->next = p; // 倒置结点
        p = r;       // p指向新倒置的结点
        r = q;       // 前进一个结点
        q = q->next;
    }
    r->next = p;     // 处理最后一个结点
    (*L)->next = r;  // head指向倒置后的链表
    printf("\n");
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    if (L == NULL || L->next == NULL)
        return ERROR;
    LinkedList fast,  slow;
    fast = L->next->next;
    slow = L->next;
    while (1) {
        if (!fast || !slow)
            return ERROR;
        if (fast == slow)
            return SUCCESS;
        else {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L) {
    LinkedList dummyHead = (LinkedList)malloc(sizeof(LNode));//创建虚拟结点
    dummyHead->next = (*L)->next;//虚拟结点的next指向联保第一个结点
    LinkedList cur = dummyHead;
    while (cur->next != NULL && cur->next->next != NULL) {
        LinkedList tmp = cur->next; // 记录临时节点
        LinkedList tmp1 = cur->next->next->next; // 记录临时节点

        cur->next = cur->next->next;    // 步骤一
        cur->next->next = tmp;          // 步骤二
        cur->next->next->next = tmp1;   // 步骤三

        cur = cur->next->next; // cur移动两位，准备下一轮交换
    }
    LinkedList p = dummyHead->next;
    free(dummyHead);
    return p;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L) {
    LinkedList fast, slow, p;
    fast = *L;
    slow = *L;

    while (fast && fast->next)
    {
        p = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void CreateList(LinkedList* L, int n)
{
    srand(time(0));//初始化随机种子
    int i;
    *L = (LinkedList)malloc(sizeof(LNode));
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
