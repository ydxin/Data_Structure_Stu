#include "ordered_list.h"
#include <stdlib.h>
OLinkNode* CreateOLinkNode(int  a[], int n)
{
	OLinkNode* L = (OLinkNode*)malloc(sizeof(OLinkNode));
	OLinkNode* s;
	OLinkNode* r ;
	OLinkNode* p;
	L->next = NULL;
	int temp = a[0];
	for (int i = 0; i < n; i++)
	{
		p = (OLinkNode*)malloc(sizeof(OLinkNode));
		p->data = a[i];
		p->next = NULL;
		s = L;
		while (s->next &&a[i] >=s->next->data)
		{	
			s = s->next;
		}
		p->next = s ->next;
		s->next = p;
		s = p;
	}
	return L;
}

void DispOLinkList(OLinkNode* L)
{
	OLinkNode* s = L->next;
	s = L->next;
	while (s)
	{
		printf("%d  ", s->data);
		s = s->next;
	}
	printf("\n");
}

void DestroyOLinkList(OLinkNode* L)
{
	OLinkNode* s = L;
	OLinkNode* next = L->next;
	while (next)
	{
		free(s);
		s = next;
		next = next->next;
	}
	free(s);
}

void  OLinkListInsert(OLinkNode* L, int  e)
{
	OLinkNode* p = L;
	while ( p->next&&p->next->data<e)
	{
		p = p->next;
	}
	OLinkNode* t = (OLinkNode*)malloc(sizeof(OLinkNode));
	t->data = e;
	t->next = p->next;
	p->next = t;
}

OLinkNode* UnionOLinkList(OLinkNode* L1, OLinkNode* L2)
{
	OLinkNode* L = (OLinkNode*)malloc(sizeof(OLinkNode));
	OLinkNode* p1 = L1->next;
	OLinkNode* p2 = L2->next;
	OLinkNode* s;
	OLinkNode* r = L;
	while (p1 && p2)
	{
		s = (OLinkNode*)malloc(sizeof(OLinkNode));
		if (p1->data >= p2->data)
		{
			s->data = p2->data;
			p2 = p2->next;
		}
		else
		{
			s->data = p1->data;
			p1 = p1->next;
		}
		r->next = s;
		r = s;
	}
	if (!p1)
	{
		while (p2)
		{
			s = (OLinkNode*)malloc(sizeof(OLinkNode));
			s->data = p2->data;
			r->next = s;
			r = s;
			p2 = p2->next;
		}
	}
	else
	{
		while (p1)
		{
			s = (OLinkNode*)malloc(sizeof(OLinkNode));
			s->data = p1->data;
			r->next = s;
			r = s;
			p1 = p1->next;
		}
	}
	r->next = NULL;
	return L;
}