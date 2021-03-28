#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "linkedList.h"

int main()
{
	LinkedList L;/*Define a new LNode*/
	InitList(&L);/*Init a new List*/
	int i, j, k;
	int index;
	printf("Enter the length of the List\n");
	scanf("%d", &i);
	CreateList(&L,i);/*Create a random list*/

	printf("Enter the num the test the function!\n");
	printf("         Enter 0 to leave\n");
	printf("###################################\n");
	printf("##     1. DisplayList            ##\n");
	printf("##     2. InsertList             ##\n");
	printf("##     3. DeleteList             ##\n");
	printf("##     4. TraverseList           ##\n");
	printf("##     5. SearchList             ##\n");
	printf("##     6. ReverseList            ##\n");
	printf("##     7. IsLoopList             ##\n");
	printf("##     8. ReverseEvenLis         ##\n");
	printf("##     9. FindMidNode            ##\n");
	printf("###################################\n");
	do
	{
		scanf("%d", &k);
		switch (k)
		{
		case DISPLAY:
			Display(&L);
			break;

		case INSERTLIST:
		{

			LinkedList r = (LinkedList)malloc(sizeof(LNode));
			printf("Enter the data of the Node you want to insert\n");
			scanf("%d", &(r->data));
			printf("Enter the index of the Node you want to insert\n");
			scanf("%d", &index);
			LinkedList p = L;
			for (i = 0; i < index; i++)
				p = p->next;
			InsertList(p, r);
			Display(&L);
			break;
		}


		case DELETELIST:
		{
			printf("Enter the index of the LNode you want to delete\n");
			scanf("%d", &index);
			LinkedList p = L;
			for (i = 1; i < index; i++)
				p = p->next;
			int e;
			DeleteList(p, &e);
			printf("The data of the LNode you delete is %d\n",e);
			break;
		}

		case TRAVERSELIST:
		{
			printf("This Function will call a visit to traverse you list and print it!\n");
			TraverseList(L,pf);
			break;
		}
		case SEARCHLIST:
			printf("Please enter the data you want to search!\n");
			scanf("%d", &i);
			if (SearchList(L, i))
				printf("The data is in the list\n");
			else
				printf("The data is not in the list\n");
			break;

		case REVERSELIST:
			if(ReverseList(&L))
				printf("Success!\n");
			else
				printf("False!\n");
			break;
		case ISLOOPLIST:
			if(IsLoopList(L))
				printf("This list is a LoopList\n");
			else
				printf("This list is not a LoopList\n");
			break;

		case REVERSEEVENLIST:
			{
				LinkedList p = ReverseEvenList(&L);
				while(p)
				{
					printf("%d  ",p->data);
					p=p->next;
				}
				break;
			}


		case FINDMIDNODE:
			{
				LinkedList p;
				p=FindMidNode(&L);
				printf("The data of the middle Node is %d\n",p->data);
				break;
			}

		}
	} while (k != 0);
	return 0;
	system ("pause");
}
