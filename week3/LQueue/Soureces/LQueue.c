#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL)printf("初始化失败\n");
    else {
        p->next = NULL;
        Q->front = p;
        Q->rear = p;
        Q->length = 0;
        printf("初始化完成\n");
    }
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
    ClearLQueue(Q);
    free(Q->front);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->length == 0)return 1;
    else return 0;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
    if (IsEmptyLQueue(Q))return 0;
    else {
        memcpy(e, Q->front->next->data, typeSize);
        return 1;
    }
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) {
    return (int)Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        printf("申请内存失败！\n");
        return 0;
    }
    else {
        p->data = (void*)malloc(typeSize);
        memcpy(p->data, data, typeSize);
        p->next = NULL;
        Q->rear->next = p;
        Q->rear = p;
        Q->length++;
        return 1;
    }
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    p = Q->front->next;
    Q->front->next = p->next;
    if (Q->rear == p)Q->rear = Q->front;
    free(p);
    Q->length--;
    return 1;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
    if (Q->length == 0)return;
    else {
        Node* p = NULL, * q = NULL;
        Q->rear = Q->front;
        p = Q->rear->next;
        Q->rear->next = NULL;
        while (p->next != NULL) {
            q = p;
            p = p->next;
            free(q);
        }
        free(p);
        Q->length = 0;
        return;
    }
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
    if (IsEmptyLQueue(Q))return 0;
    else {
        Node* p = NULL;
        for (p = Q->front->next; p->next != NULL; p = p->next)LPrint(p->data);
        LPrint(p->data);
        printf("\n");
        return 1;
    }
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) {
    if (typeSize == 4)printf("%d", *(int*)q);
    if (typeSize == 1)printf("%c", *(char*)q);
    if (typeSize == 8)printf("%lf", *(double*)q);
    printf("<-");
}

int getInt()
{
    char in[11];
    int t;

    s_gets(in, 11);
    t = atoi(in);
    if (t == 0) {
        if (in[1] != 0 || in[2] != '\0')
        {
            t = getInt();
        }
    }
    return t;
}
