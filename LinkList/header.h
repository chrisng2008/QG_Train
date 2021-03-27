#pragma once
#include "malloc.h"
typedef int ElemType;
typedef struct LinkList
{
	ElemType data;
	struct LinkList* next;
}Node, * LinkList;
//´´½¨Á´±í
LinkList* createHead();

void PrintList(LinkList L);











