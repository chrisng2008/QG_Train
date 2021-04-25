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
    menu();
    select(T);

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
            //初始化二叉树
            if(BST_init(&T))
                puts("初始化二叉树成功！");
            break;
        }
        case 2:
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


        case 3:
        {
            //插入数字
            puts("请输入你要插入的数字");
            int num;
            scanf("%d",&num);
            if(BST_insert(&T,num))
                puts("插入数字成功");
            else
                puts("插入数字失败");
//            printf("%d",T.root->value);
//            if(T.root->left!=NULL)
//                printf("%d",T.root->left->value);
//            if(T.root->right!=NULL)
//                printf("%d",T.root->right->value);
            break;
        }
        case 4:
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
        case 5:
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
        case 6:
        {
            if(BST_inorderR(&T,print))
                puts("递归中序遍历成功！");
            else
                puts("递归中序遍历失败！");
            //递归中序遍历
            break;
        }
        case 7:
        {
            //递归后序遍历
            if(BST_postorderR(&T,print))
                puts("递归后序遍历成功");
            else
                puts("递归后序遍历失败！");
            break;
        }
        case 8:
        {
            //非递归前序遍历
            if(BST_preorderI(&T,print))
                puts("非递归前序遍历成功！");
            else
                puts("非递归前序遍历失败");
            break;
        }
        case 9:
        {
            //非递归中序遍历
            if(BST_inorderI(&T,print))
                puts("非递归中序遍历成功！");
            else
                puts("非递归中序遍历失败！");
            break;
        }
        case 10:
        {
            //非递归后序遍历
            if(BST_postorderI(&T,print))
                puts("非递归后序遍历成功！");
            else
                puts("非递归后序遍历失败！");
            break;
        }
        case 11:
        {
            //层序遍历
            if(BST_levelOrder(&T,print))
                puts("层次遍历成功！");
            else
                puts("层次遍历失败！");
            break;
        }
        case 12:
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
    puts("##  1.初始化二叉树    ##");
    puts("##  2.查找数字        ##");
    puts("##  3.插入数字        ##");
    puts("##  4.删除数字        ##");
    puts("##  5.递归前序遍历    ##");
    puts("##  6.递归中序遍历    ##");
    puts("##  7.递归后序遍历    ##");
    puts("##  8.非递归前序遍历  ##");
    puts("##  9.非递归中序遍历  ##");
    puts("##  10.非递归后序遍历  ##");
    puts("##  11.层序遍历      ##");
    puts("##  12.清空屏幕       ##");
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