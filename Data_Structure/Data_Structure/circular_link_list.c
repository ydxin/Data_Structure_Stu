#include "circular_link_list.h"

int CountCirSLinkList(CirSLinkNode* L,int x)
{
	CirSLinkNode* p = L->next;
	int i = 0;
	while (p!=L)
	{
		if (p->data ==x)
			i++;
		p = p->next;
	}
	return i;
}

int DelCirDLinkList(CirDLinkNode* L,int x)
{
	CirDLinkNode* p = L->next;
	while (p!=L &&p->data !=x)
		p = p->next;
	if (p == L)   FAILED;
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
	return SUCCESS;
}

int SymCirDLinkList(CirDLinkNode* L)
{
	CirDLinkNode* h = L->next;
	CirDLinkNode* r = L->prior;
	int isSame = 1;
	while (isSame)
	{
		if (h->data != r->data)
			isSame = 0;
		else
		{
			if ((h->next == r->prior) || (h == r->prior)) break;
			h = h->next;
			r = r->prior;
		}
	}
	return  isSame;
}