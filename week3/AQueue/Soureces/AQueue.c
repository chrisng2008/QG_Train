#include "AQueue.h"
#include <string.h>
#include <stdio.h>
long typeSize;

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue* Q)
{

    for (int i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void*)malloc(typeSize);
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
}

/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue* Q) {
    int i = 0;
    while (Q->length--)
        free(Q->data[i++]);
    exit(0);            /*程序正常运行并退出程序*/
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue* Q) {
    if ((Q->rear + 1) % MAXQUEUE == Q->front)
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue* Q) {
    if (!Q->length) 
        return TRUE;
    return FALSE;
}




/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue* Q, void* e){
    if (Q->front == Q->rear)                    /*队列空的判断*/
        return FALSE;
    memcpy(e, Q->data[0], typeSize);
    return TRUE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue* Q){
    if (Q->front == Q->rear)                    /*队列空的判断*/
        return FALSE;
    return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue* Q, void* data){
    if ((Q->rear + 1) % MAXQUEUE == Q->front)       /*队列满判断*/
        return FALSE;
    memcpy(Q->data[Q->rear], data, typeSize);       /*将data复制给队尾*/
    Q->rear = (Q->rear + 1) % MAXQUEUE;             /*rear指针向后后移一位置*/
                                                    /*若到最后则转到数组头部*/
    Q->length++;
    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue* Q){
    if (Q->front == Q->rear)                    /*队列空的判断*/
        return FALSE;
    Q->front = (Q->front + 1) % MAXQUEUE;       /*front指针后移一位置*/
                                                /*所到最后则转移到数组头部*/
    Q->length--;
    return TRUE;
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue* Q);



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q));



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void* q);




/**
 *  @name        : Status SetType()
 *    @description : 根据用户输入的数据确定泛型
 *    @param         None
 *    @return         : None
 *  @notice      : None
 */
Status SetType(){
    char input[3];
    s_gets(input, 3);
    if (input[0] == 'a' && input[1] == '\0')
    {
        char type= 'i';
        typeSize = sizeof(int);
    }
    else if (input[0] == 'b' && input[1] == '\0')
    {
        char type = 'c';
        typeSize = sizeof(char);
    }
    else if (input[0] == 'c' && input[1] == '\0')
    {
        char type = 'f';
        typeSize = sizeof(float);
    }
    else if (input[0] == 'd' && input[1] == '\0')
    {
        char type = 'd';
        typeSize = sizeof(double);
    }
    else if (input[0] == 'e' && input[1] == '\0')
    {
        char type = 's';
        typeSize = sizeof(char) * 100;
    }
    else if (input [0] == 'f' && input[1] == '\0')
    {
        type = '*';
        typeSize = sizeof(char*);
    }
    else {
        puts("输入错误！请重新输入");
        setType();
    }
}

/**
 *  @name        : char* s_gets(char* st, int n)
 *    @description : 处理用户输入的数据
 *    @param         *st 指针st n 输入最大的长度n
 *    @return         : char *s
 *  @notice      : None
 */
char* s_gets(char* st, int n){
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    // 查找换行符
        if (find)                   //如果地址不是NULL
            *find = '\0';           //在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue;           //处理输入行中剩余的字符
    }
    return ret_val;
}