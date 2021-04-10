#include <stdio.h>
#include "LQueue.h"
#pragma warning(disable : 4996)

void* data = NULL, * d = NULL;
void* e = NULL;
char* s_gets(char* st, int n);
void select();
void Display();
void setType();
int main() 
{
    setType();
    LQueue Q;
    InitLQueue(&Q);         /*初始化队列*/
    Display();
    select(Q);
    return 0;
    system("pause");
}

void setType()
{
    char choose;
    printf("请选择数据类型：\na.整型\nb.字符型\nc.浮点型\n");
    scanf("%c", &choose);
    switch (choose) {
    case 'a':
        typeSize = sizeof(int);
        break;
    case 'b':
        typeSize = sizeof(char);
        break;
    case 'c':
        typeSize = sizeof(double);
        break;
    //case 'd':
    //    typeSize= sizeof(char) * 100;
        
    default:
        printf("请输入正确的指令！\n");
        break;
    }
    while (getchar() != '\n')continue;
}
void Display()
{
    printf("###################################\n");
    printf("##     1. 销毁队列并退出程序     ##\n");
    printf("##     2. 判断队列是否为空       ##\n");
    printf("##     3. 获取队列头元素         ##\n");
    printf("##     4. 获取队列的长度         ##\n");
    printf("##     5. 入队操作               ##\n");
    printf("##     6. 出队操作               ##\n");
    printf("##     7. 清空队列               ##\n");
    printf("##     8. 遍历队列并打印元素     ##\n");
    printf("##     9. 清空当前屏幕           ##\n");
    printf("###################################\n");
}

void select(LQueue Q)
{
    int n;
    switch (getInt())
    {

    case 1:
        DestoryLQueue(&Q);
        puts("销毁成功！");
        exit(0);
        break;

    case 2:
        if (IsEmptyLQueue(&Q))
            printf("该队列为空\n");
        else printf("该队列不为空\n");
        break;
    case 3:
        e = (void*)malloc(sizeof(typeSize));
        if (GetHeadLQueue(&Q, e)) {
            printf("该队头元素为");
            if (typeSize == 4)
                printf("%d\n", *(int*)e);
            if (typeSize == 1)
                printf("%c\n", *(char*)e);
            if (typeSize == 8)
                printf("%lf\n", *(double*)e);
            break;
        }
    case 4:
        if (LengthLQueue(&Q))printf("该队列长度为%zu\n", Q.length);
        else printf("该队列为空\n");
        break;
    case 5:
        printf("请输入入队数据：\n");
        if (typeSize == 1) {
            setbuf(stdin, NULL);
            d = (char*)malloc(sizeof(char));
            scanf(" %c", (char*)d);
            printf("%c", *(char*)d);
        }
        if (typeSize == 4)
        {
            d = (int*)malloc(sizeof(int));
            while (scanf("%d", (int*)d) != 1) {
                printf("请输入正确类型\n");
                while (getchar() != '\n');
            }
            printf("%d", *(int*)d);
        }
        if (typeSize == 8) 
        {
            d = (double*)malloc(sizeof(double));
            while (scanf("%lf", (double*)d) != 1) 
            {
                printf("请输入正确类型\n");
                while (getchar() != '\n');
            }
            printf("%lf", *(double*)d);
        }
        //if (type == sizeof(char) * 100)
        //{
        //    char c[100];
        //    puts("请输入数据");
        //    s_gets(d, 100);
        //    EnAQueue(Q, &c);
        //}
        data = (void*)malloc(sizeof(typeSize));
        memcpy(data, d, typeSize);
        if (EnLQueue(&Q, data))printf("入队成功！\n");
        else printf("入队失败！\n");
        break;
        
    case 6:
        if (IsEmptyLQueue(&Q))printf("该队已空！\n");
        else {
            if (DeLQueue(&Q))printf("出队成功！\n");
            else printf("出队失败！\n");
        }
        break;
    case 7:
        ClearLQueue(&Q);
        printf("清空完成\n");
        break;
    case 8:
        if (!(TraverseLQueue(&Q, e)))printf("无法遍历\n");
        break;
    case 9:
        system("cls");
        Display();
        break;
    default:
        printf("请输入正确的指令！\n");
        break;
    }
    select(Q);
}


char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    fflush(stdin);
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;

}