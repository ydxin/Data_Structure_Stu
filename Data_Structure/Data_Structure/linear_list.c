#include "linear_list.h"
#include <stdlib.h>
#include <stdio.h>

/*****************线性表的顺序存储结构*****************/
SqList* CreateList(ElemType a[], int n)
{
	int i = 0;
	SqList* L = (SqList *)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[i] = a[i];
		i++;
	}
	L-> length = i;
	return L;
}

SqList* InitList()
{
	SqList* L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	return L;
}

void	 DestroyList(SqList* L)
{
	free(L);
}

int	 ListEmpty(SqList* L)
{
	return (L->length == 0);
}

int ListLength(SqList* L)
{
	return (L->length );
}

void  DispList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d  ", L->data[i]);
	printf("\n");
}

int GetElem(SqList* L, int i, ElemType* e)
{
	if (i<1 || i>L->length)
		return FAILED;
	*e = L->data[i - 1];
	return SUCCESS;
}

int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return FAILED;
	else
		return i + 1;
}

int  ListInsert(SqList* L, int i, ElemType e)
{
	if (i<1 || i>L->length)
		return FAILED;
	i--;
	for (int j = L->length; j > i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;
	return SUCCESS;
}

int  ListDelete(SqList* L, int i, ElemType* e)
{
	if (i<1 || i>L->length)
		return FAILED;
	i--;
	*e = L->data[i];
	for (int j = i; j < L->length -1; j++)
		L->data[j] = L->data[j + 1];
	L->length--;
	return SUCCESS;
}

//删除值为e的所有元素
void DelListElem(SqList* L,ElemType e) 
{
	int k = 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] != e)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;

	/*int k = 0;
	int i = 0;
	while (i < L->length)
	{
		if (L->data[i] == e)
			k++;
		else
			L->data[i - k] = L->data[i];
		i++;
	}
	L->length -= k;*/
}  

//将比第一位大的移到它后面，比它小的移到前面
void Partition(SqList* L)   
{
	int temp = L->data[0];
	int i = 0;
	int j = L->length - 1;
	while (i < j)
	{
		while (i<j && L->data[j]>temp)
			j--;
		L->data[i] = L->data[j];
		while (i < j && L->data[i] <= temp)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = temp;

}   //

//把所有奇数移到偶数前面
void OddToEven(SqList* L)
{
	int i = 0;
	int j = L->length - 1;
	int temp = L->data[0];
	while (i < j)
	{
		while (i < j && L->data[j] % 2 == 0)
			j--;
		L->data[i] = L->data[j];
		while (i < j && L->data[i] % 2 == 1)
			i++;
		L->data[j] = L->data[i];
	}
	L->data[i] = temp;
}



