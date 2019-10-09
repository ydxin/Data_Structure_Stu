#ifndef  _LINEAR_LIST_H_
#define _LINEAR_LIST_H_

#define IS_EMPTY		0
#define NOT_EMPTY	1

#define MAX_SIZE		50

#define FAILED			0
#define SUCCESS		1

typedef int ElemType;
typedef struct SqList
{
	ElemType data[MAX_SIZE];
	int length;
}SqList,*pSqList;


SqList* CreateList(ElemType a[], int n);
SqList* InitList();
void	 DestroyList(SqList* L);
int	 ListEmpty(SqList* L);
int	 ListLength(SqList* L);
void  DispList(SqList* L);
int     GetElem(SqList* L,int i, ElemType*e);
int	 LocateElem(SqList* L,ElemType e);
int     ListInsert(SqList* L,int i,ElemType e);
int     ListDelete(SqList* L,int i,ElemType* e);
void DelListElem(SqList* L, ElemType e);
void Partition(SqList* L);
void OddToEven(SqList* L);


#endif // ! _LINEAR_LIST_H_
