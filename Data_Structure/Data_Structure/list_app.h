#ifndef  _LIST_APP_H_
#define _LIST_APP_H_

#define MAX_COL 10

typedef struct RowHeadNode
{
	int a[MAX_COL];
	struct RowHeadNode* next;
}RowHeadNode;

typedef struct MaxtriHeadNode
{
	int row, col;
	RowHeadNode* next;
}MaxtriHeadNode;

MaxtriHeadNode* CreateTable();
void DispTable(MaxtriHeadNode* h);
void DestroyTable(MaxtriHeadNode* h);
void DestroyTable(MaxtriHeadNode* h);
MaxtriHeadNode* LinkTable(MaxtriHeadNode* h1, int h1_i, MaxtriHeadNode* h2, int h2_i);

#endif // ! _LIST_APP_H_
