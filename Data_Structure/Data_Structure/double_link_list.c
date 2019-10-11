#include "double_link_list.h"
#include <stdio.h>
#include <stdlib.h>
DLinkNode* CreateDLinkListF(int  a[], int n)
{
	DLinkNode* L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
	L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		s->prior = L;
		if (L->next)
			L->next->prior = s;
		L->next = s;
	}
	return L;
}

DLinkNode* CreateDLinkListR(int a[], int n)
{
	DLinkNode* L = (DLinkNode*)malloc(sizeof(DLinkNode));
	DLinkNode* r = L ;
	DLinkNode* p;
	L->next = NULL;
	L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		DLinkNode* s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;

	return L;
}


DLinkNode* InitDLinkList()
{
	DLinkNode* L;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	if (!L)
		return FAILED;
	L->prior = NULL;
	L->next = NULL;
	return L;
}

void DestroyDLinkList(DLinkNode* L)
{
	DLinkNode* s = L;
	DLinkNode* next = L->next;
	while (next)
	{
		free(s);
		s = next;
		next = next->next;
	}
	free(s);
}

int DLinkListEmpty(DLinkNode* L)
{
	return (L->next == NULL);
}

int DLinkListLength(DLinkNode* L)
{
	int n = 0;
	DLinkNode* s = L;
	while (s->next)
	{
		n++;
		s = s->next;
	}
	return n;

}

void DispDLinkList(DLinkNode* L)
{
	DLinkNode* s = L->next;
	while (s)
	{
		printf("%d  ", s->data);
		s = s->next;
	}
	printf("\n");
}

int GetDLinkElem(DLinkNode* L, int i, int* e)
{
	DLinkNode* s = L->next;
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
int LocateDLinkElem(DLinkNode* L, int e)
{
	DLinkNode* s = L;
	int i = 1;
	while (s->next && s->data != e)
	{
		s = s->next;
		i++;
	}
	if (s->next == NULL) return FAILED;
	else return i;
}

int DLinkListInsert(DLinkNode* L, int i, int e)
{
	if (i < 0)  return FAILED;
	int j = 0;
	DLinkNode* s = L;
	s = L;
	int n = 1;
	while (n < i && s)
	{
		s = s->next;
		n++;
	}
	if (!s ) return FAILED;
	else
	{
		DLinkNode* r = (DLinkNode*)malloc(sizeof(DLinkNode));
		r->data = e;
		r->next = s->next;
		r->prior = s;
		if (s->next)
			s->next->prior = r;
		s->next = r;
		return SUCCESS;
	}

}

int DLinkListDelete(DLinkNode* L, int i, int* e)
{
	if (i < 1) return FAILED;
	int j = 1; 
	DLinkNode* p = L;
	DLinkNode* q;
	while (j < i && p)
	{
		j++;
		p = p->next;
	}
	q = p->next;
	if (q) return FAILED;
	p->next = q->next;
	if (p->next)
		p->next->prior = q;
	free(p);
	return SUCCESS;
}

void DlinkReverse(DLinkNode* L)
{
	DLinkNode* p = L->next;
	DLinkNode* q;
	L->next = NULL;
	while (p)
	{
		q = p->next;
		p->next = L->next;
		if (L->next)
			L->next->prior = p;
		L->next = p;
		p->prior = L;
		p = q;
	}
}

void SortDlink(DLinkNode* L)
{
	DLinkNode* pre;
	DLinkNode* q;
	DLinkNode* p = L->next->next;
	L->next->next = NULL;	
	while (p)
	{
		pre = L;
		q = p->next;
		while (pre->next && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		p->prior = pre;
		if (pre->next)
			pre->next ->prior= p;
		pre->next = p;
		p = q;
		

	}

}