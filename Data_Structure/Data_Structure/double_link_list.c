#include "double_link_list.h"
#include <stdio.h>
DLinkNode* CreateDLinkListF(int  a[], int n)
{
	DLinkNode* L = (DLinkNode*)calloc(sizeof(DLinkNode));
	L->next = NULL;
	L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		s->prior = L;
		L->next->prior = s;
		L->next = s;
	}
}

DLinkNode* CreateDLinkListR(int a[], int n)
{
	DLinkNode* L = (DLinkNode*)calloc(sizeof(DLinkNode));
	L->next = NULL;
	L->prior = NULL;
}


DLinkNode* InitDLinkList()
{
	DLinkNode* L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
	return L;
}