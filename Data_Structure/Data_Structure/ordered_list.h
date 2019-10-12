#ifndef  _ORDERED_LIST_H_
#define _ORDERED_LIST_H_


#define FAILED			0
#define SUCCESS		1

typedef struct OLNode
{
	int data;
	struct OLNode* next;
}OLinkNode;

OLinkNode* CreateOLinkNode(int  a[], int n);
void DispOLinkList(OLinkNode* L);
void DestroyOLinkList(OLinkNode* L);
void  OLinkListInsert(OLinkNode* L, int  e);
OLinkNode* UnionOLinkList(OLinkNode* L1, OLinkNode* L2);
#endif // ! _ORDERED_LIST_H_
