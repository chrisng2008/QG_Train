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
	
	LinkedList p = ReverseEvenList(L);
	while (p)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	return 0;
}