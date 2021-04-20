#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <ctype.h>
#include "sort.h"
#include <time.h>
#include <io.h>
int size;
int getInt();
void menu();
void select(int *array,int *temp,int size);
int getInt();
char* s_gets(char* st, int n);
void RandonArray(int array[],int size);
typedef long clock_t;
int isRandom = 1;
int rank(int *array,int size);






int main()
{
    int *array =NULL;
    puts("欢迎来到排序算法测试系统");
    FILE *fp;
    fp=fopen("RandomArray.txt", "r");
    if ( fp == NULL )
    {
        printf("本地文件不存在，将为你创建一个数组\n");
        puts("请输入数组的大小");
        size=setSize();
        array = (int *)malloc(sizeof(int)*size);
        WriteArray(size);
        ReadArray(size-1,array);
    }
    else
    {
        puts("本地数组文件已存在，现在为你读取");
        int max = 500000;
        size =  0;
        int i;
        FILE *pf;
        pf = fopen("RandomArray.txt","r");
        int* arrsize=(int*)malloc(sizeof(int)*max);
        for(i = 0; !feof(pf); i++)
        {
            fscanf(pf, "%d", &arrsize[i]);
            size++;
        }
        free (arrsize);
        array = (int *)malloc(sizeof(int)*size);
        ReadArray(size,array);
    }
    fclose(fp);
    int *temp = (int *)calloc(size, sizeof(int));
    menu();
    select(array,temp,size);
    return 0;
    system("pause");
}



void menu()
{
    printf("\n");
    puts("########################");
    puts("##  0.退出程序        ##");
    puts("##  1.插入排序        ##");
    puts("##  2.归并排序        ##");
    puts("##  3.快速排序(递归)  ##");
    puts("##  4.快速排序(非递归)##");
    puts("##  5.计数排序        ##");
    puts("##  6.基数排序        ##");
    puts("##  7.颜色排序        ##");
    puts("##  8.找第k大的数     ##");
    puts("##  9.遍历打印数组    ##");
    puts("##  10.排序时常排行   ##");
    puts("##  11.数组乱序       ##");
    puts("##  12.清空屏幕       ##");
    puts("########################");
    printf("\n");
}

void select(int *array,int *temp,int size)
{
    puts("请选择功能");
    int n;
    switch (getInt())
    {
        case 1:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    insertSort(array,size);
                    end = clock();
                    double insert_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("归并排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",insert_time);
                    isRandom = 0;
                }
                else
                    puts("请排序前输入11使数组乱序");
                break;

            }
        case 2:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    MergeSort(array,0,size-1,temp);
                    end = clock();
                    double MergeSort_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("归并排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",MergeSort_time);
                    isRandom = 0;
                }
                else
                    puts("请排序前输入11使数组乱序");
                break;
            }

        case 3:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    QuickSort_Recursion(array,0,size-1);
                    end = clock();
                    double QuickSort_Recursion_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("快速排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",QuickSort_Recursion_time);
                    isRandom = 0;

                }
                else
                    puts("请排序前输入11使数组乱序");
                break;
            }

        case 4:
            if(isRandom==1)
            {
                clock_t start,end;
                start = clock();
                QuickSort(array,size);
                end = clock();
                double QuickSort_time = (double)(end - start) / CLOCKS_PER_SEC;
                puts("快速排序非递归完成，请按9查看排序后的数组");
                printf("所消耗的时间为 %f secs\n",QuickSort_time);
            }
            else
                puts("请排序前输入11使数组乱序");
            break;
        case 5:
        {
            if(isRandom==1)
            {
                    clock_t start,end;
                    start = clock();
                    int max=GetKTop(array,1,size); //获取最大的数;
                    CountSort(array,size,max);
                    end = clock();
                    double CountSort_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("计数排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",CountSort_time);
                    isRandom = 0;
            }
            else
                puts("请排序前输入11使数组乱序");
            break;

        }
        case 6:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    RadixCountSort(array,size);
                    end = clock();
                    double RadixCountSort_time = (double)(end-start)/ CLOCKS_PER_SEC;
                    puts("基数排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",RadixCountSort_time);
                    isRandom = 0;
                }
                else
                    puts("请排序前输入11使数组乱序");
                break;
            }

        case 7:
            if(isRandom==1)
            {
                    printf("我们将为你生成一个大小为%d的只含有0，1，2的数组\n",size);
                    int *colorarray = (int *)calloc(size, sizeof(int));
                    getcolorArray(colorarray,size);
                    clock_t start,end;
                    start = clock();
                    ColorSort(colorarray,size);
                    end = clock();
                    double ColorSort_time = (double)(end-start)/ CLOCKS_PER_SEC;
                    puts("颜色排序完成，现在我们开始打印排序后的数组");
                    Display(colorarray,size);
                    printf("所消耗的时间为 %f secs\n",ColorSort_time);
                    isRandom = 0;
                    free(colorarray);
            }
            else
                puts("请排序前输入11使数组乱序");
            break;
        case 8:
            puts("请输入你需要找的第几大的数：");
            int k;
            scanf("d",&k);
            int max=GetKTop(array,k,size);
            printf("第%d大的数为%d\n",k,max);
            break;
        case 9:
            Display(array,size);
            puts("遍历打印数组完成，输入12清空屏幕");
            break;
        case 10:
            rank(array,size);
            break;
        case 11:
            MakeRand(array, size);
            puts("数组乱序成功！");
            isRandom = 1;
            break;
        case 12:
            system("cls");
            menu();
            break;
        case 0:
            exit(0);
            break;
        default:
            puts("输入错误，请输入0-11之间的整数");
            break;
    }
    select(array,temp,size);
}

int getInt()
{
    int i;
    int value;
    char num[100];
    do
    {
        printf("请输入数字\n");
        scanf_s("%s", num);
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

int setSize()
{
    int size;
    size = getInt();
    return size;
}

int rank(int *array,int size)
{
    int i;
    int *copy = (int*)malloc(sizeof(int)*size);

    clock_t start,end;
    start = clock();
    for(i=0;i<size;i++)
        copy[i]=array[i];
    insertSort(copy,size);
    end = clock();
    double insert_time = (double)(end - start) / CLK_TCK;
    sortNode  timeRank[6];
    timeRank[0].time = insert_time;
    strcpy(timeRank[0].s, "insertSort");


    start = clock();
    for(i=0;i<size;i++)
        copy[i]=array[i];
    int *temp = (int *)calloc(size, sizeof(int));
    MergeSort(copy,0,size-1,temp);
    end = clock();
    double MergeSort_time = (double)(end - start) / CLK_TCK;
    timeRank[1].time = MergeSort_time;
    strcpy(timeRank[1].s, "MergeSort");


    start = clock();
    for(i=0;i<size;i++)
        copy[i]=array[i];
    QuickSort_Recursion(copy,0,size-1);
    end = clock();
    double QuickSort_Recursion_time = (double)(end - start) / CLK_TCK;
    timeRank[2].time = QuickSort_Recursion_time;
    strcpy(timeRank[2].s, "QuickSort_Recursion");


    start = clock();
    QuickSort(copy,size);
    end = clock();
    for(i=0;i<size;i++)
        copy[i]=array[i];
    double QuickSort_time = (double)(end - start) / CLK_TCK;
    timeRank[3].time = QuickSort_time;
    strcpy(timeRank[3].s, "QuickSort");


    start = clock();
    for(i=0;i<size;i++)
        copy[i]=array[i];
    int max=GetKTop(array,1,size); //获取最大的数;
    CountSort(copy,size,max);
    end = clock();
    double CountSort_time = (double)(end - start) / CLK_TCK;
    timeRank[4].time = CountSort_time;
    strcpy(timeRank[4].s, "CountSort");


    start = clock();
    for(i=0;i<size;i++)
        copy[i]=array[i];
    RadixCountSort(copy,size);
    end = clock();
    double RadixCountSort_time = (double)(end - start) / CLK_TCK;
    timeRank[5].time = RadixCountSort_time;
    strcpy(timeRank[5].s, "RadixCountSort");

    insertSort_double(timeRank,6);
    for (i=0;i<6;i++) {
        printf("排行为：%d.%s  %f ms\n", i + 1, timeRank[i].s, timeRank[i].time);
    }
    free(copy);
}

