#ifndef  _TREE_H_
#define _TREE_H_
#define N 50

typedef struct HTNode
{
	char data;
	double weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;

typedef struct HCode
{
	char cd[N];
	int start;
}HCode;



void CreateHT(HTNode ht[], int n0);
void CreateHCode(HTNode ht[], HCode hcd[], int n0);

#endif // ! _TREE_H_
