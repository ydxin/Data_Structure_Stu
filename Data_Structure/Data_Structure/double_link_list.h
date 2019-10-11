#ifndef _DOUBLE_LINK_LIST_H_
#define _DOUBLE_LINK_LIST_H_

#define FAILED			0
#define SUCCESS		1


typedef struct DNode
{
	int data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;


DLinkNode* CreateDLinkListF(int  a[], int n);
DLinkNode* CreateDLinkListR(int a[], int n);
DLinkNode* InitDLinkList();
void DestroyDLinkList(DLinkNode* L);
int DLinkListEmpty(DLinkNode* L);
int DLinkListLength(DLinkNode* L);
void DispDLinkList(DLinkNode* L);
int GetDLinkElem(DLinkNode* L, int i, int* e);
int LocateDLinkElem(DLinkNode* L, int e);
int DLinkListInsert(DLinkNode* L, int i, int e);
int DLinkListDelete(DLinkNode* L, int i, int* e);
void DlinkReverse(DLinkNode* L);
void SortDlink(DLinkNode* L);


#endif // !_DOUBLE_LINK_LIST_H_


