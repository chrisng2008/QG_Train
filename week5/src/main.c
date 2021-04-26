//
// Created by Chris on 2021/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
#include "LinkStack.h"
#include "LQueue.h"
#include <string.h>
#include "LinkList.h"
void menu();
void select(BinarySortTree T);
void print();
int getInt();
BinarySortTree T;
char* s_gets(char* st, int n);

int main()
{
    if(BST_init(&T))
        puts("初始化二叉树成功！");
    menu();
    select(T);
    return 0;
    system("pause");
}

void select(BinarySortTree T)
{
    switch(getInt())
    {
        case 0:
            exit(0);
            break;
        case 1:
        {
            ElemType data;
            puts("请输入要查找的数字：");
            data=getInt();
            if(BST_search(&T,data))
                puts("查找成功，二叉树中含有此元素！");
            else
                puts("查找失败，二叉树不含有此元素!");
            break;
        }


        case 2:
        {
            //插入数字
            puts("请输入你要插入的数字");
            int num;
            scanf("%d",&num);
            if(BST_insert(&T,num))
                puts("插入数字成功");
            else
                puts("插入数字失败");

            break;
        }
        case 3:
        {
            //删除数字
            ElemType m;
            puts("请输入你要删除的数字：");
            scanf("%d",&m);
            if(BST_delete(&T,m))
                puts("删除数字成功！");
            else
                puts("删除数字失败");
            break;
        }
        case 4:
        {
            //递归前序遍历
            if(BST_preorderR(&T,print))
            {
                printf("\n递归前序遍历成功！\n");
            }
            else
                printf("\n递归前序遍历失败！\n");
            break;
        }
        case 5:
        {
            if(BST_inorderR(&T,print))
                puts("递归中序遍历成功！");
            else
                puts("递归中序遍历失败！");
            //递归中序遍历
            break;
        }
        case 6:
        {
            //递归后序遍历
            if(BST_postorderR(&T,print))
                puts("递归后序遍历成功");
            else
                puts("递归后序遍历失败！");
            break;
        }
        case 7:
        {
            //非递归前序遍历
            if(BST_preorderI(&T,print))
                puts("非递归前序遍历成功！");
            else
                puts("非递归前序遍历失败");
            break;
        }
        case 8:
        {
            //非递归中序遍历
            if(BST_inorderI(&T,print))
                puts("非递归中序遍历成功！");
            else
                puts("非递归中序遍历失败！");
            break;
        }
        case 9:
        {
            //非递归后序遍历
            if(BST_postorderI(&T,print))
                puts("非递归后序遍历成功！");
            else
                puts("非递归后序遍历失败！");
            break;
        }
        case 10:
        {
            //层序遍历
            if(BST_levelOrder(&T,print))
                puts("层次遍历成功！");
            else
                puts("层次遍历失败！");
            break;
        }
        case 11:
        {
            //清空屏幕
            system("cls");//清空屏幕
            menu();//显示菜单
            break;

        }
        default:
            puts("输入错误，请输入数字");
            break;
    }
    select(T);
}


void menu()
{
    printf("\n");
    puts("欢迎来到排序二叉树测试系统");
    puts("########################");
    puts("##  0.退出程序        ##");
    puts("##  1.查找数字        ##");
    puts("##  2.插入数字        ##");
    puts("##  3.删除数字        ##");
    puts("##  4.递归前序遍历    ##");
    puts("##  5.递归中序遍历    ##");
    puts("##  6.递归后序遍历    ##");
    puts("##  7.非递归前序遍历  ##");
    puts("##  8.非递归中序遍历  ##");
    puts("##  9.非递归后序遍历  ##");
    puts("##  10.层序遍历      ##");
    puts("##  11.清空屏幕       ##");
    puts("########################");
    printf("\n");
}

void print(NodePtr T)
{
    printf("%d  ",T->value);
}

int getInt()
{
    int i;
    int value;
    char num[100];
    do
    {
        printf("请输入数字\n");
        scanf("%s", num);
        if (i = strspn(num, "0123456789"))
        {
            value = atoi(num);
            break;
        }
        else
            printf("输入错误，");
    } while (i == 0);
    fflush(stdin);
    return value;
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