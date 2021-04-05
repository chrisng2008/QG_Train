#include <stdio.h>
#include "SqStack.h"
int main()
{
    printf("Enter the num the test the function!\n");
    printf("         Enter 0 to leave\n");
    printf("###################################\n");
    printf("##     1. 初始化顺序栈            ##\n");
    printf("##     2. 判断栈是否为空          ##\n");
    printf("##     3. 获取栈顶元素            ##\n");
    printf("##     4. 清空顺序栈              ##\n");
    printf("##     5. 销毁顺序栈              ##\n");
    printf("##     6. 获取顺序栈的长度        ##\n");
    printf("##     7. 入栈操作                ##\n");
    printf("##     8. 出栈操作                ##\n");
    printf("##     9. 清空屏幕                ##\n");
    printf("###################################\n");

    int i, n, size, exist=0;
    SqStack* s;
    do
    { 
        n = read();
        switch (n)
        {
        case 0:
            break;
        case INITSTACK:
            if (exist==0)
            {
                printf("请输入你需要栈的大小\n");
                scanf_s("%d", &size);
                if (initStack(&s, size))
                    printf("栈初始化成功！\n\n");
                exist = 1;     
            }
            else if (exist == 1)
            {
                printf("对不起，初始化栈前请先销毁栈\n\n");
            }
            break;
        case ISEMPTYSTACK:
            if (exist == 1)
            {
                if (isEmptyStack(&s))
                    printf("该栈为空！\n\n");
                else
                    printf("该栈不为空\n\n");
            }
            else if(exist == 0)
                printf("对不起，该栈不存在！\n\n");
            break;
        case GETTOPSTACK:
            if (exist == 1)
            {
                if (getTopStack(&s, &i)) {
                    printf("获取栈顶元素成功！\n");
                    printf("栈顶元素为%d\n\n", i);
                }
                else
                    printf("获取栈顶元素失败！该栈为空！\n\n");
            }
            else if (exist == 0)
            {
                printf("对不起，获取栈顶元素时请初始化栈!\n\n");
            }
            
            break;

        case CLEARSTACK:
            if (exist == 1)
            {
                if (clearStack(&s))
                    printf("清空栈成功！\n\n");
            }
            else if (exist == 0)
            {
                printf("对不起，该栈不存在！\n\n");
            }
            break;
        case DESTORYSTACK:
            if (exist == 1)
            {
                if (destroyStack(&s)) {
                    printf("销毁栈成功\n\n");
                    exist = 0;
                }
            }
            else if (exist == 0)
            {
                printf("对不起，销毁栈前请初始化栈\n\n");
            }
           
                
            else
                printf("销毁栈失败!\n\n");
            break;
        case STACKLENGTH:
            if (exist == 1)
            {
                if (stackLength(&s, &i)) {
                    printf("获取栈长度成功!\n");
                    printf("栈的长度为%d\n\n", i);
                }
                else
                    printf("获取栈长度失败\n\n");
            }
            else if (exist == 0)
            {
                printf("对不起，该栈不存在。获取栈长度前请初始化栈！\n\n");
            }
            break;
        case PUSHSTACK:
        {
            if (exist == 1)
            {
                ElemType data;
                printf("请输入入栈元素的值\n");
                scanf_s("%d", &data);
                if (pushStack(&s, data))
                {
                    printf("入栈成功！\n");
                    getTopStack(&s, &data);
                    printf("栈顶元素为%d\n\n", data);
                }
                else
                    printf("入栈失败!\n\n");
            }
            else if (exist == 0)
                printf("对不起，该栈不存在，入栈前初始化栈\n\n");
            break;
        }
        case POPSTACK:
            if (exist == 1)
            {
                if (popStack(&s, &i)) {
                    printf("出栈成功！\n");
                    printf("出栈的元素是%d\n\n", i);
                }
                else
                    printf("出栈失败！\n\n");
            }
            else if (exist == 0)
            {
                printf("对不起，该栈不存在，出栈前请初始化栈!\n\n");
            }
            break;
            case CLEARSCREEN:
                clearScreen();
                printf("Enter the num the test the function!\n");
                printf("         Enter 0 to leave\n");
                printf("###################################\n");
                printf("##     1. 初始化顺序栈            ##\n");
                printf("##     2. 判断栈是否为空          ##\n");
                printf("##     3. 获取栈顶元素            ##\n");
                printf("##     4. 清空顺序栈              ##\n");
                printf("##     5. 销毁顺序栈              ##\n");
                printf("##     6. 获取顺序栈的长度        ##\n");
                printf("##     7. 入栈操作                ##\n");
                printf("##     8. 出栈操作                ##\n");
                printf("##     9. 清空屏幕                ##\n");
                printf("###################################\n");
                break;
        default:
            printf("输入错误，请输入0-8之间的整数\n");
            break;
        }
    } while (n != 0);

    return 0;
    system("pause");
}