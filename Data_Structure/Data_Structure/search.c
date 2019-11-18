#include "search.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int m;
int max;
int min;


void IdxSearch(IdxType I[], int Idxlen, RecType R[], int n, int k)
{
	int s = n / Idxlen + 1;//idxLen是总块数，s是每块的长度
	int low = 0;
	int high = Idxlen - 1;
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

BSTNode* SearchBST1(BSTNode* bt, int k, BSTNode* f1, BSTNode* fp)
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

int SeqSearch(RecType R[], int n, int k)
{
	int i = 0;
	while (i < n && R[i].key != k)
		i++;
	if (i >= n)
		return 0;
	else
		return i + 1;
}

int SeqSearchKey(RecType R[], int n, int k) //增加哨兵
{
	int i = 0;
	R[n].key = k;
	while (R[i].key != k)
		i++;
	if (i == n)
		return 0;
	else
		return i + 1;
}

int BinSearch(RecType R[],int n, int k)
{
	int low = 0;
	int high = n - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (k == R[mid].key)
			return mid + 1;
		if (k < R[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

int BinSearchRes(RecType R[], int start,int end,int n, int k)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;
		if (R[mid].key == k)
			return mid + 1;
		if (R[mid].key > k)
			BinSearchRes(R, start, mid - 1, n, k);
		else
			BinSearchRes(R, mid + 1, end, n, k);
	}
	else
		return -1;
}

void CreateHT1(HashTable ha[],int* n,int m,int p,int keys[],int nl)
{
	for (int i = 0; i < m; i++)
	{
		ha[i].key = NULL_KEY;
		ha[i].count = 0;
	}
	n = 0;
	for (int i = 0; i < nl ; i++)	
		InsertHT(ha, n, m, p, keys[i]);	
}

void InsertHT(HashTable ha[], int* n, int m, int p, int k)
{
	int adr;
	adr = k % p;
	if (ha[adr].key == NULL_KEY || ha[adr].key == DEL_KEY)
	{
		ha[adr].key = k;
		ha[adr].count = 1;
	}
	else
	{
		int i = 1;
		do
		{
			adr = (adr + 1) % m;
			i++;
		} while (ha[adr].key != NULL_KEY && ha[adr].key != DEL_KEY);
		ha[adr].key = k;
		ha[adr].count = i;
	}
	(*n)++;
}

void DeleteHT(HashTable ha[], int* n, int m, int p, int k)
{
	int adr = k % p;
	while (ha[adr].key != NULL_KEY && ha[adr].key != k)
		adr = (adr + 1) % m;
	if (ha[adr].key == k)
	{
		ha[adr].key = DEL_KEY;
		return  true;
	}
	else
		return false;
	
}

void SearchHT(HashTable ha[], int* n, int m, int p, int k)
{
	int adr = k % p;
	int i = 1;
	while (ha[adr].key != NULL_KEY && ha[adr].key != k)
	{
		i++;
		adr = (adr + 1) % m;
	}
	if (ha[adr].key == k)
		return true;
	else
		return false;
	
}