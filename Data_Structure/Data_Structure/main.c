#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include "link_queue.h"
#include "recursion.h"
#include "array.h"
#include "search.h"
void PrintString(char *ch);

int main()
{
	RecType R[11];
	int a[11] = { 2,3,10,15,20,25,28,29,30,35,40 };
	for (int i = 0; i < 11; i++)
	{
		R[i].data =1 ;
		R[i].key = a[i];
	}
	
	int aa= BinSearchRes(R, 0, 10, 11, 26);
	//printf("%d\n", a);




	system("pause");
	return 0;
}




void PrintString(char* ch)
{
	int len = strlen(ch);
	for (int i = 0; i < len; i++)
		printf("%c",ch[i]);
	printf("\n");
}

void IdxSearch(IdxType I[],int Idxlen,RecType R[],int n,int k)
{
	int s = n / Idxlen + 1;//idxLen是总块数，s是每块的长度
	int low = 0;
	int high = Idxlen-1;
	int mid = 0;
	int i = 0;
	while (low <= high)
	{
		mid = (low + mid - 1) / 2;
		if (I[mid].key >= k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	i = I[high + 1].link;
	while (i <= I[high + 1].link + s - 1 && R[i].key != k)
		i++;
	if (i <= I[high + 1].link + s - 1)
		return i + 1;
	else
		return 0;
}

bool InsertBST(BSTNode* bt, int k)
{
	if (bt == NULL)
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;
	}
	else if (k == bt->key)
		return InsertBST(bt->lchild, k);
	else
		return InsertBST(bt->rchild, k);
}

BSTNode* CreateBST(int A[], int n)
{
	BSTNode* bt = NULL;
	int i = 0;
	while (i < n)
	{
		InsertBST(bt, A[i]);
		i++;
	}
	return  bt;
}

BSTNode* SearchBST(BSTNode* bt, int k)
{
	if (bt == NULL || bt->key == k)
		return bt;
	if (k < bt->key)
		return SearchBST(bt->lchild, k);
	else
		return SearchBST(bt->rchild, k);
}

BSTNode* SearchBST1(BSTNode* bt, int k, BSTNode* f1,BSTNode* fp)
{
	if (bt == NULL)
	{
		fp = NULL;
		return NULL;
	}
	else if (k == bt->key)
	{
		fp = f1;
		return bt;
	}
	else if (k < bt->key)
		return SearchBST(bt->lchild, k, bt, fp);
	else
		return SearchBST(bt->rchild, k, bt, fp);
}

void MaxMinNode(BSTNode* p)
{
	if (p)
	{
		if (p->lchild)
			printf("lchild max : %d\n", Maxnode(p->lchild));

		if (p->rchild)
			printf("rchild min : %d\n", Minnode(p->rchild));
	}
}

int Maxnode(BSTNode* p)
{
	while (p->rchild)
		p = p->rchild;
	return p->data;
}

int Minnode(BSTNode* p)
{
	while (p->lchild)
		p = p->lchild;
	return p->data;
}