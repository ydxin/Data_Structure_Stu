#include "link_list.h"
#include <stdio.h>
#include <stdlib.h>
LinkNode* CreateLinkListF(ElemType a[], int n)
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

LinkNode* CreateLinkListR(ElemType a[], int n)
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
	return L;
}

LinkNode* InitLinkList()
{
	LinkNode* L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	return L;
}

void DestroyLinkList(LinkNode* L)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* next = (LinkNode*)malloc(sizeof(LinkNode));
	s = L;
	next = L->next;
	while (next )
	{
		free(s);
		s = next;
		next = next->next;
	}
	free(s);
}

int LinkListEmpty(LinkNode* L)
{
	return (L->next == NULL);
 }

int LinkListLength(LinkNode* L)
{
	int n = 0;
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	while (s->next)
	{
		n++;
		s = s->next;
	}
	return n;
}

void DispLinkList(LinkNode* L)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = L->next;
	while (s)
	{
		printf("%d  ", s->data);
		s = s->next;
	}
	printf("\n");
}

int GetLinkElem(LinkNode* L, int i, ElemType* e)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = L->next;
	if (i < 0) return FAILED;
	int n = 1;
	while (n < i && s)
	{
		n++;
		s = s->next;
	}
	if (!s) return FAILED;
	else
	{
		*e = s->data;
		return SUCCESS;

	}

}

int LocateLinkElem(LinkNode* L, ElemType e)
{
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = L;
	int i = 1;
	while (s->next && s->data != e)
	{
		s = s->next;
		i++;
	}
	if (s->next == NULL) return FAILED;
	else return i;

}

int LinkListInsert(LinkNode* L, int i, ElemType e)
{
	if (i <= 0) return FAILED;
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = L;
	int n = 1;
	while (n < i && s->next)
	{
		s = s->next;
		n++;
	}
	if (s->next == NULL) return FAILED;
	else
	{
		LinkNode* r = (LinkNode*)malloc(sizeof(LinkNode));
		r->data = e;
		r->next = s->next;
		s->next = r;
		return SUCCESS;
	}
	
}

int LinkListDelete(LinkNode* L, int i, ElemType* e)
{
	if (i <= 0) return FAILED;
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = L;	
	int n = 1;
	while ( n < i && s->next)
	{
		s = s->next;
		n++;
	}
	if (s->next == NULL) return FAILED;
	else
	{
		LinkNode* q = (LinkNode*)malloc(sizeof(LinkNode));
		q = s->next;
		s->next = q->next;
		free(q);
		return SUCCESS;
	}
}

