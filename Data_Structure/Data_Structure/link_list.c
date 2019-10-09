#include "link_list.h"
#include <stdio.h>
LinkNode* CreateListF(ElemType a[], int n)
{
	LinkNode* L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
	return L;
}

LinkNode* CreateListR(ElemType a[], int n)
{
	LinkNode* L = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* r = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		LinkNode* s= (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

LinkNode* InitList()
{
	LinkNode* L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	return L;
}

void DestroyList(LinkNode* L)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* next = (LinkNode*)malloc(sizeof(LinkNode));
	s = L;
	next = L->next;
	while (next != NULL)
	{
	}
}

int ListEmpty(LinkNode* L)
{
	return (L->next == NULL);
 }

int ListLength(LinkNode* L)
{

}

void DispList(LinkNode* L)
{

}

int GetElem(LinkNode* L, int i, ElemType* e)
{

}

int LocateElem(LinkNode* L, ElemType e)
{

}

int ListInsert(LinkNode* L, int i, ElemType e)
{

}

int ListDelete(LinkNode* L, int i, ElemType* e)
{

}