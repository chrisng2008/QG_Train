#include"header.h"

//void PrintList(LinkList L)
//{
//	LinkList p;
//	p = L->next;
//	while (p)
//	{
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}

LinkList* createHead()
{
	LinkList *L = (LinkList)malloc(sizeof(Node));

	(*L)->next = NULL;
	return L;
}