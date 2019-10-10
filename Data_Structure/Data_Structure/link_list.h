#ifndef  _LINK_LIST_H_
#define _LINK_LIST_H_

#define IS_EMPTY		0
#define NOT_EMPTY	1

#define MAX_SIZE		50

#define FAILED			0
#define SUCCESS		1


typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;


LinkNode* CreateLinkListF(ElemType a[], int n);
LinkNode* CreateLinkListR(ElemType a[], int n);
LinkNode* InitLinkList();
void DestroyLinkList(LinkNode* L);
int LinkListEmpty(LinkNode* L);
int LinkListLength(LinkNode* L);
void DispLinkList(LinkNode* L);
int GetLinkElem(LinkNode* L, int i, ElemType* e);
int LocateLinkElem(LinkNode* L, ElemType e);
int LinkListInsert(LinkNode* L, int i, ElemType e);
int LinkListDelete(LinkNode* L, int i, ElemType* e);
void SplitLink(LinkNode* L, LinkNode** L1, LinkNode** L2);
void DelMaxLinkNode(LinkNode* L);
void SortLink(LinkNode* L);
#endif // ! _LINK_LIST_H_
