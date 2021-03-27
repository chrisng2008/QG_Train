#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <string.h>
typedef int ElemType;

int main()
{
	LinkList* L = InitList();
	//创建新链表，并随机初始化链表
	printf("创建一个新链表，请输入元素的个数\n");
	int n;
	int index;
	scanf("%d", &n);
	CreateList(L, n);
	Display(L);
	int length = ListLength(L);
	printf("%d", length);
	/*printf("请输入获取元素的位置\n");
	scanf("%d", &n);
	
	ElemType e;
	GetItem(L, n, &e);
	printf("%d", e);
	printf("请输入你要检索的元素\n");
	scanf("%d", &n);
	LocateElem(L, n);

	printf("请输入你要插入的元素,以及需要插入的位置");
	scanf("%d%d", &n,&index);

	ListInsert(L, index, n);
	Display(L);*/

	/*ClearList(L);
	if (ListEmpty(L) == TRUE)
		printf("This List is empty");
	else
		printf("This List is not empty");*/
	/*int e;*/
	//scanf("%d", &n);
	//ListDelete(L, n, &e);
	//printf("%d\n", e);
	//Display(L);





	return 0;
	////遍历链表;
	//printf("你所创建的链表为\n");
	//ListIter(L);
	//printf("请输入你要获取元素的位置");
	//scanf("%d", &n);
	//ElemType e;
	//GetItem(L, n, &e);
	//printf("获取的元素是%d", &e);
	//return 0;
}


