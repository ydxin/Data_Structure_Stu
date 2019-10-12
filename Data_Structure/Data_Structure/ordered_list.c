#include "ordered_list.h"
#include <stdlib.h>
OLinkNode* CreateOLinkNode(int  a[], int n)
{
	OLinkNode* L = (OLinkNode*)malloc(sizeof(OLinkNode));
	OLinkNode* r = L;
	OLinkNode* p;
	for (int i = 0; i < n; i++)
	{
		p = (OLinkNode*)malloc(sizeof(OLinkNode));
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;	
	return L;
}