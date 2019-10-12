#include "list_app.h"
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>

MaxtriHeadNode*  CreateTable()
{
	int row = 0;
	int col = 0;
	MaxtriHeadNode* h = (MaxtriHeadNode*)malloc(sizeof(MaxtriHeadNode));
	h->next = NULL;
	RowHeadNode* r = h ->next;
	printf("Please input the row num: ");
	scanf("%d", &h->row);
	printf("Please input the col num: ");
	scanf("%d", &h->col);
	for (row = 0; row < h->row; row++)
	{
		RowHeadNode* s = (RowHeadNode*)malloc(sizeof(RowHeadNode));
		printf("Please input the %d row,%d data : \n", row + 1,h->col);
		
		for (col = 0; col < h->col; col++)
		{
			scanf("%d", &s->a[col]);
		}
		if (!h->next) h->next = s;
		else r ->next= s;
		r = s;
	}
	r->next = NULL;
	return h;
}

void DispTable(MaxtriHeadNode* h)
{
	RowHeadNode* p = h->next;
	printf("**********************************\n");
	while (p)
	{
		for (int i = 0; i < h->col; i++)
			printf("\t%d", p->a[i]);
		printf("\n");
		p = p->next;
	}
	printf("**********************************\n");
}

void DestroyTable(MaxtriHeadNode* h)
{
	RowHeadNode* pre = h->next;
	RowHeadNode* p = h->next->next;
	while (p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
	free(h);
}

MaxtriHeadNode* LinkTable(MaxtriHeadNode* h1, int h1_i,MaxtriHeadNode* h2,int h2_i)
{
	int row = 0;
	int col = h1->col + h2->col;
	RowHeadNode* p1 = h1->next;
	RowHeadNode* p2 = h2->next;
	RowHeadNode* t;
	MaxtriHeadNode* head = (MaxtriHeadNode*)malloc(sizeof(MaxtriHeadNode));
	head->next = NULL;	
	RowHeadNode* r= head->next;
	while (p1)
	{
		while (p2)
		{
			if ((p1->a[h1_i - 1]) == (p2->a[h2_i - 1]))
			{
				t = (RowHeadNode*)malloc(sizeof(RowHeadNode));
				//以下两行存在bug，memcpy时字节数过大；会导致堆被破坏
				//注意检查实际memcpy的空间，过大时容易占用到未分配的空间，然后malloc时会提示堆被破坏；
				//memcpy(t->a, p1->a, h1->col * sizeof(p1->a));
				//memcpy(&t->a[h1->col], p2->a, h2->col * sizeof(p1->a));  
				for (int idata = 0; idata < h1->col; idata++)
					t->a[idata] = p1->a[idata];
				for (int idata = 0; idata < h2->col; idata++)
					t->a[idata+h1->col] = p2->a[idata];
				if (!head->next)  head->next = t;
				else  r->next = t;
				r = t;
				row++;
			}
			p2 = p2->next;
		}
		p2 = h2->next;
		p1 = p1->next;
	}
	r->next = NULL;
	head->col = col;
	head->row = row;
	return head;
}