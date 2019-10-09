#ifndef  _LINK_LIST_H_
#define _LINK_LIST_H_

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;


LinkNode* CreateListF(ElemType a[], int n);
LinkNode* CreateListR(ElemType a[], int n);
LinkNode* InitList();
void DestroyList(LinkNode* L);
int ListEmpty(LinkNode* L);
int ListLength(LinkNode* L);
void DispList(LinkNode* L);
int GetElem(LinkNode* L, int i, ElemType* e);
int LocateElem(LinkNode* L, ElemType e);
int ListInsert(LinkNode* L, int i, ElemType e);
int ListDelete(LinkNode* L, int i, ElemType* e);



#endif // ! _LINK_LIST_H_
