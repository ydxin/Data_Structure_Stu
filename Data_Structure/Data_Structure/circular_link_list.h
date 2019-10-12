#ifndef  _CIRCULAR_LINK_LIST_H_
#define _CIRCULAR_LINK_LIST_H_

#define FAILED		1
#define SUCCESS	0

typedef struct CirSLinkNode
{
	int data;
	struct CirSLinkNode* next;
}CirSLinkNode;

typedef struct CirDLinkNode
{
	int data;
	struct CirDLinkNode* next;
	struct CirDLinkNode* prior;
}CirDLinkNode;



#endif // ! _CIRCULAR_LINK_LIST_H_
