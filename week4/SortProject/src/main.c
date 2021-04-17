#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <ctype.h>
#include "sort.h"
#include <time.h>

int getInt();
void menu();
void select(int *array,int *temp,int size);
int getInt();
char* s_gets(char* st, int n);
void RandonArray(int array[],int size);


int main()
{
    puts("欢迎来到排序算法测试系统");
    puts("接下需要测试的排序算法有");
    puts("将为你创建一个随机整数数组!");
    int size = read();
    printf("%d",size);
    int *array = (int *)calloc(size, sizeof(int));
    int *temp = (int *)calloc(size, sizeof(int));
    getRandArray(array,size);
    Display(array,size);
    menu();
    select(array,temp,size);
    return 0;
    system("pause");
}



void menu()
{
    printf("\n");
    puts("########################");
    puts("##  1.插入排序        ##");
    puts("##  2.归并排序        ##");
    puts("##  3.快速排序(递归)  ##");
    puts("##  4.快速排序(非递归)##");
    puts("##  5.计数排序        ##");
    puts("##  6.基数排序        ##");
    puts("##  7.颜色排序        ##");
    puts("##  8.找第k大的数     ##");
    puts("##  9.遍历打印数组    ##");
    puts("##  10.数组乱序       ##");
    puts("##  11.清空屏幕       ##");
    puts("########################");
    printf("\n");
}

int read()
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
    return value;
}

void select(int *array,int *temp,int size)
{
    puts("请选择功能");
    int n;
    switch (getInt())
    {
        case 1:
            insertSort(array,size);
            printf("插入排序后的数组为：");
            Display(array,size);
            break;
        case 2:
            MergeSort(array,0,size-1,temp);
            printf("归并排序后的数组为：");
            Display(array,size);
            break;
        case 3:
            QuickSort_Recursion(array,0,size-1);
            Display(array,size);
            break;
        case 4:
            //QuickSort()
            break;
        case 5:
        {
            int max=GetNumTop(array,1,size);
            CountSort(array,size,max);
            Display(array,size);
            break;
        }
        case 6:
            break;
        case 7:
            printf("我们将为你生成一个大小为%d的只含有0，1，2的数组\n",size);
            int *colorarray = (int *)calloc(size, sizeof(int));
            getcolorArray(colorarray,size);
            printf("随机生成的数组为：");
            Display(colorarray,size);
            ColorSort(colorarray,size);
            Display(colorarray,size);
            free(colorarray);
            break;
        case 8:
            puts("请输入你需要找的第几大的数：");
            int k =read();
            int max=GetNumTop(array,k,size);
            printf("第%d大的数为%d\n",k,max);
            break;
        case 9:
            Display(array,size);
        case 10:
            RandonArray(array,size);
            Display(array,size);
            break;
        case 11:
            system("cls");
            menu();
            break;
        default:
            break;

    }
    select(array,temp,size);
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

void RandonArray(int array[],int size)
{
    int i;
    srand((unsigned int) time(NULL));
    for (i = 0; i < size; i++)
    {
        array[i] = rand()%100 + 1;
    }

}
