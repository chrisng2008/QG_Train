#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "duLinkedList.h"
int main()
{
	DuLinkedList L;
	InitList_DuL(&L);
	int i, j, k;
	int index;
	CreateList(&L);
	printf("Enter the num the test the function!\n");
	printf("         Enter 0 to leave\n");
	printf("###################################\n");
	printf("##     1. DisplayList            ##\n");
	printf("##     2. InsertBeforeList_DuL   ##\n");
	printf("##     3. InsertAfterList_DuL    ##\n");
	printf("##     4. DeleteList_DuL         ##\n");
	printf("##     5. DestroyList_DuL        ##\n");
	printf("##     6. TraverseList_DuL       ##\n");
	printf("###################################\n");
	do
	{
		scanf("%d", &k);
		switch (k)
		{
		case DISPLAY_DUL:
			Display(&L);
			break;
		case INSERTBEFORE_DuL:
		{
				DuLinkedList r = (DuLinkedList)malloc(sizeof(DuLNode));
				printf("Enter the location of the DuLNode you wnat to insert before!\n");
				scanf("%d", &index);
				printf("Enter the data of the DuLNode you wnat to insert before!\n");
				scanf("%d", &(r->data));
				DuLinkedList p = L;
				for (i = 0; i < index; i++)
					p = p->next;
				if (InsertBeforeList_DuL(p, r))
					printf("Success!");
				else
					printf("False");

				break;
		}
		case INSERTAFTER_DuL:
		{
			DuLinkedList r = (DuLinkedList)malloc(sizeof(DuLNode));
			printf("Enter the location of the DuLNode you wnat to insert after!\n");
			scanf("%d", &index);
			printf("Enter the data of the DuLNode you wnat to insert after!\n");
			scanf("%d", &(r->data));
			DuLinkedList p = L;
			for (i = 0; i < index; i++)
				p = p->next;
			if (InsertAfterList_DuL(p, r))
				printf("Success!");
			else
				printf("False");

			break;
		}

		case DELETELIST_DuL:
			printf("Enter the index of you data of the Node you want to delete\n ");
			scanf("%d", &index);
			DuLinkedList p = L;
			for (i = 2; i < index; i++)
				p = p->next;
			int e;
			if (DeleteList_DuL(p, &e))
				printf("Success!\n The data of the Node is %d\n",e);
			else
				printf("False");
			break;

		case DESTORY_DuL:
			DestroyList_DuL(&L);
			printf("Success!\n");
			break;

		case TRAVERSELIST_Dul:
			printf("This Function will call a visit to traverse you list and print it!\n");
			TraverseList_DuL(L, pf);
			break;
		}

	} while (k != 0);
	return 0;
	system("pause");
}
