#include<stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <time.h>

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
    int i,j,key;
        for (i=1;i<n;i++){
                key = *(a+i);
                j=i-1;
                for(j=i-1;j>=0&&*(a+j)>key;j--)
                    a[j+1] = a[j];
                a[j+1] = key;
        }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    {
        int i=begin;  //把数组a[0,10]中的a[0,4]和a[5,9]合并，把两个第一个元素下标给i,j
        int j=mid+1;
        int end1=mid;  //把最后一个元素赋值给end1,end2
        int end2=end;
        int k=0;
        while(i<=end1&&j<=end2)   //两个数组元素进行比较，并赋值到temp中
        {
            if(a[i]<a[j])
                temp[k++]=a[i++];
            else
                temp[k++]=a[j++];
        }
        while(i<=end1)
            temp[k++]=a[i++];   //如果其中一个元素有剩余，则说明剩下的都是大的了，直接赋值给temp中
        while(j<=end2)
            temp[k++]=a[j++];
        for(i=0;i<k;i++)
            a[begin+i]=temp[i];//把temp中的内容给A
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin<end)
    {
        int middle = (begin + end) / 2; //求出中间的位置
        MergeSort(a, begin, middle, temp);
        MergeSort(a, middle + 1, end, temp);  //分别对两个分开的数组再分
        MergeArray(a, begin, middle, end, temp);//合并两个数组
    }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
    int pivot;
    if(begin<end)
    {
        pivot =Partition(a,begin,end);
        QuickSort_Recursion(a,begin,pivot-1);
        QuickSort_Recursion(a,pivot+1,end);
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size)
{

}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
    int pivotkey;
    pivotkey=*(a+begin);
    while(begin<end)
    {
        while(begin<end && *(a+end)>=pivotkey)
            end--;
        int temp;
        temp = *(a+begin);
        *(a+begin)=*(a+end);
        *(a+end)=temp;
        while(begin<end&&*(a+begin)<=pivotkey)
            begin ++;
        temp = *(a+begin);
        *(a+begin)=*(a+end);
        *(a+end)=temp;
    }
    return begin;//返回枢纽的下标
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
    int *p =(int*)malloc(sizeof(int)*size);
    int *q = (int*)malloc(sizeof(int)*(max+1));
    for (int i = 0; i < max; ++i)
    {
        q[i] = 0;//将q指向的数组所有元素置0
    }

    //保存数组a中每个元素出现的个数，将排序交给了q数组(其顺序在q数组中就是有序的)

    for (int j = 0; j < size; ++j)
    {
        q[a[j]]++ ;
    }

    //将所有计数次数累加
    for (int i = 1; i < max; ++i)
    {
        q[i] = q[i] + q[i-1];
    }

    //将元素重新输入
    for (int i = size-1; i >= 0; --i)
    {
    //次数大小最小为1、数组开始为0
        p[q[a[i]]-1] = a[i];
        q[a[i]]--;
    }

    for (int j = 0; j < size; ++j)
    {
        a[j] = p[j];
    }
    //不要忘了释放分配的空间
    free(p);
    free(q);
    }


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
    int* radixArrays[10];    //指针数组
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int*)malloc(sizeof(int) * (size + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= 10; pos++)    //从个位开始到31位
    {
        for (int i = 0; i < size; i++)    //分配过程
        {
            int num = GetNumInPos(a[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = a[i];
        }

        for (int i = 0, j = 0; i < 10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }
}


// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
    int p0 = 0, p1 = 0;
    int temp;
    for (int i = 0; i < size; ++i) {
        if (a[i] == 1)
        {
            temp=a[i];
            a[i]=a[p1];
            a[p1]=temp;
            ++p1;
        }
        else if (a[i] == 0) {
            temp=a[i];
            a[i]=a[p0];
            a[p0]=temp;
            if (p0 < p1) {
                temp=a[i];
                a[i]=a[p1];
                a[p1]=temp;
            }
            ++p0;
            ++p1;
        }
    }
}

/**
 *  @name        : int GetNumTop(int num, int k,int size)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int GetNumTop(int *a,int k,int size)
{
    int *c= (int*)malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)
        c[i]=a[i];
    QuickSort(c,size);
    int max=c[size-k];
    return max;
}

/**
 *  @name        : void getRandArray(int array[], int size)
 *  @description : 返回一个大小为size的随机数整型数组
 *  @param       : 数组的大小size,array
 */
void getRandArray(int array[], int size)
{
    int i;
    srand((unsigned int) time(NULL));
    for (i = 0; i < size; i++)
	{
		array[i] = rand()%100 + 1;
	}
}

void getcolorArray(int array[], int size)
{
    int i;
    srand((unsigned int) time(NULL));
    for (i = 0; i < size; i++)
    {
        array[i] = rand()%3;
    }
}


void Display(int array[],int size)
{
	int i;
	printf("\n");
	for (i=0;i<size;i++)
		printf("%d  ",array[i]);
    printf("\n");
}
