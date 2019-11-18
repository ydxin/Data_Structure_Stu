#include <stdbool.h>
#ifndef  _SEARCH_H_
#define _SEARCH_H_

#define MAXI 50
#define MAXM 10
#define NULL_KEY	-1
#define DEL_KEY		-2

typedef struct RecType
{
	int  key;
	int data;
}RecType;

typedef struct IdxType
{
	int key;
	int link;
}IdxType;


typedef struct BSTNode
{
	int key;
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode;

/***************B tree *****************/
typedef struct BTNode
{
	int keynum;
	int key[MAXM];  //key[0]不用
	struct node* parent;
	struct node* ptr[MAXM];
}BTNode;
/**************************************/

typedef struct HashTable
{
	int key;
	int count;
}HashTable;




int SeqSearch(RecType R[], int n, int k);
int SeqSearchKey(RecType R[], int n, int k); //增加哨兵
int BinSearch(RecType R[], int n, int k);
int BinSearchRes(RecType R[], int start, int end, int n, int k);
void IdxSearch(IdxType I[], int Idxlen, RecType R[], int n, int k);
bool InsertBST(BSTNode* bt, int k);
BSTNode* CreateBST(int A[], int n);
BSTNode* SearchBST(BSTNode* bt, int k);
BSTNode* SearchBST1(BSTNode* bt, int k, BSTNode* f1, BSTNode* fp);
void MaxMinNode(BSTNode* p);
int Maxnode(BSTNode* p);
int Minnode(BSTNode* p);
void CreateHT1(HashTable ha[], int* n, int m, int p, int keys[], int nl);
void InsertHT(HashTable ha[], int* n, int m, int p, int k);
void DeleteHT(HashTable ha[], int* n, int m, int p, int k);
void SearchHT(HashTable ha[], int* n, int m, int p, int k);

#endif // ! _SEARCH_H_
