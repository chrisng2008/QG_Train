#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList.h"


int main()
{
	printf("Enter the num the test the function!\n");
	printf("         Enter 0 to leave\n");
	printf("###################################\n");
	printf("##     1. DisplayLis             ##\n");
	printf("##     2. InsertList             ##\n");
	printf("##     3. DeleteList             ##\n");
	printf("##     4. TraverseList           ##\n");
	printf("##     5. SearchList             ##\n");
	printf("##     6. ReverseList            ##\n");
	printf("##     7. IsLoopList             ##\n");
	printf("##     8. ReverseEvenLis         ##\n");
	printf("##     9. FindMidNode            ##\n");
	printf("###################################\n");
	LinkedList L;
	InitList(&L);
	CreateList(L, 5);
	LinkedList p;
	Display(L);
	int i, j;
	int n;
	do
	{
		scanf("%d", &n);
		switch (n)
		{
		case 1:Display(L); break;


		case 2:
		{
			int i, index;
			int j = 1;
			LinkedList p = (LinkedList)malloc(sizeof(LNode));
			printf("Enter the data of the Node you want to insert\n");
			scanf("%d", &(p->data));
			/*p->next = NULL;*/
			printf("Enter the index of the Node you want to insert\n");
			scanf("%d", &index);
			LinkedList* r = L;
			while (r && j < index)
			{
				*r = (*r)->next;
				++j;
			}
			InsertList(*r, p);
			Display(L); break;
		}


		case 3:
		{
			printf("Enter the data you want to delete");
			scanf("%d", &i);
			p = L;
			while (p)
			{
				if (p->data == i)
					break;
			}
			DeleteList(L, &j);

		}


		case 4:TraverseList(&L, pf); break;


		case 5:
		{
			printf("Please enter the data you want to search!\n");
			scanf("%d", &i);
			printf("%d", SearchList(L, i)); break;

			if (SearchList(L, i) == SUCCESS)
				printf("The data is in the list");
			else
				printf("The data is not in the list");
			break;
		}

		case 6:if (ReverseList(L) == SUCCESS)
			printf("ReverseList success!"); break;

		case 7:
			if (IsLoopList(L) == SUCCESS)
				printf("This is  a LoopList");
			else
				printf("This is not a LoopList");
			break;
		case 8:
		{
			p = ReverseEvenList(L);
			while (p)
			{
				printf("%d  ", p->data);
				p = p->next;
			}
			break;
		}


		case 9:
		{
			p = FindMidNode(L);
			printf("%d", p->data);
			break;
		}

		}
			
	} while (n != 0);
	return 0;
}
