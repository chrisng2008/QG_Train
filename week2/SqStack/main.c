#include <stdio.h>
#include "SqStack.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    printf("Enter the num the test the function!\n");
	printf("         Enter 0 to leave\n");
	printf("###################################\n");
	printf("##     1. 初始化顺序栈            ##\n");
    printf("##     2. 判断栈是否为空          ##\n");
	printf("##     3. 获取栈顶元素            ##\n");
	printf("##     4. 销毁栈                 ##\n");
	printf("##     5. 获取当前栈的长度        ##\n");
	printf("##     6. 入栈操作               ##\n");
	printf("##     7. 出栈操作               ##\n");
    printf("##     8. 清空当前屏幕           ##\n");
	printf("###################################\n");
/*
	INITSTACK=1,
	ISEMPTYSTACK,
	GETTOPSTACK,
	DESTROYSTACK,
	STACKLENGTH,
	PUSHSTACK,
	POPSTACk,,*/
    int i,n,size;
    scanf_s("%d",&n);
    do
    {
        switch (n)
        {
        case 0:
            break;
        case INITSTACK:
            printf("**********\n");
            printf("请输入你需要栈的大小\n");
            while(i=scanf_s("%d",&size)==ERROR && size>=0)
                printf("请输入正确的数字\n");
            SqStack *s;
            if(initStack(&s,size))
                printf("栈初始化成功！\n\n");
            break;

        case ISEMPTYSTACK:
            if(isEmptyStack(&s))
                printf("该栈为空！\n\n");
            else
                printf("该栈不为空\n\n");
            break;
        case GETTOPSTACK:
            if(getTopStack(&s,&i)){
                printf("获取栈顶元素成功！\n");
                printf("栈顶元素为%d\n\n",i);
            }
            else 
                printf("获取栈顶元素失败！\n\n");
            break;

        case DESTROYSTACK:
            if(destroyStack(&s))
                printf("销毁栈成功\n\n");
            else
                printf("销毁栈失败!\n\n");
            break;
        case STACKLENGTH:
            if(stackLength(&s,&i)){
                printf("获取栈长度成功!\n");
                printf("栈的长度为%d\n\n",i);
            }
            else
                printf("获取栈长度失败\n\n");
            break;
        case PUSHSTACK:
            if(pushStack(&s,&i))
            {
                printf("栈顶元素出栈成功！\n");
                printf("栈顶元素为%d\n\n",i);
            }
            else
                printf("出栈失败!\n\n");
            break;
        case POPSTACk:
            if(popStack(&s,&i)){
                printf("出栈成功！\n");
                printf("出栈的元素是%d\n\n",i);
            }    
            else
                printf("出栈失败！\n\n");
            break;
        /*case CLEARSCREEN:
            if(clearScreen)
                printf("清空屏幕成功！\n");
            printf("Enter the num the test the function!\n");
	        printf("         Enter 0 to leave\n");
        	printf("###################################\n");
	        printf("##     1. 初始化顺序栈            ##\n");
            printf("##     2. 判断栈是否为空          ##\n");
	        printf("##     3. 获取栈顶元素            ##\n");
	        printf("##     4. 销毁栈                 ##\n");
	        printf("##     5. 获取当前栈的长度        ##\n");
	        printf("##     6. 入栈操作               ##\n");
	        printf("##     7. 出栈操作               ##\n");
            printf("##     8. 清空当前屏幕           ##\n");
	        printf("###################################\n");*/
        default:
            printf("输入错误，请输入0-7之前的整数\n");
            break;
        }
    } while (n!=0);
    
    




    return 0;
}