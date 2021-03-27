#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList.h"

int main()
{
	LinkedList L;
	InitList(&L);
	int n;
	scanf("%d", &n);
	CreateList(L, n);
	Display(L);
	int i = 2;
	DeleteList(p, &n);
	printf("%d", n);
	return 0;
}