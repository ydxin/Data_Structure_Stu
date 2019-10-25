#include <stdio.h>
#include "app_stack.h"
#include <stdlib.h>
#include <stdbool.h>
int mg[M + 2][N + 2] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,1,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};

SqMgStack* InitSqStack()
{
	SqMgStack* s = (SqMgStack*)malloc(sizeof(SqMgStack));
	s->top = -1;
	return s;
}

void PopSqStack(SqMgStack* s,Box* e)
{
	if (s->top == -1)
		return;
	*e = s->data[s->top--] ;
}

void PushSqStack(SqMgStack* s, Box e)
{
	if (s->top == MAX_SIZE - 1)
		return;
	s->data[ ++s->top] = e;
}

int SqStackEmpty(SqMgStack* s)
{
	return (s->top == -1);
}

void DestroySqStack(SqMgStack* s)
{
	free(s);
}

bool MgPath(int xi,int yi,int xe,int ye)
{
	SqMgStack* st = InitSqStack();
	Box path[MAX_SIZE], e;
	mg[xi][yi] = -1;
	bool find;
	int iMg = 0;
	int jMg = 0;
	int i = 0;
	int j = 0;
	int adj = 0;
	e.i = xi;
	e.j = yi;
	e.adj = -1;
	PushSqStack(st, e);
	while (!SqStackEmpty(st))
	{
		GetSqStack(st, &e);
		i = e.i;
		j = e.j;
		adj = e.adj;
		if (i == xe && j == ye)
		{
			FindThePath(st, path);
			return true;
		}
		find = false;
		while (adj < 4 && !find)
		{
			adj++;
			switch (adj)
			{
			case 0:
				iMg = i - 1 ;
				jMg = j ;
				break;
			case 1:
				iMg = i;
				jMg = j +1 ;
				break;
			case 2:
				iMg = i +1;
				jMg = j  ;
				break;
			case 3:
				iMg = i ;
				jMg = j  -1;
				break;
			default:
				break;
			}
			if (mg[iMg][jMg] == 0)  find = true;
		}
		if (find)
		{
			st->data[st->top].adj = adj;
			e.i = iMg;
			e.j = jMg;
			e.adj = -1;
			PushSqStack(st, e);
			mg[iMg][jMg] = -1;
		}
		else
		{
			PopSqStack(st, &e);
			mg[e.i][e.j] = 0;
		}
	}
	DestroySqStack(st);
	return false;
}

void GetSqStack(SqMgStack* s, Box* e)
{
	*e = s->data[s->top];
}

void FindThePath(SqMgStack* s, Box* box)
{
	Box e;
	printf("The path is £º \n");
	int k = 0;
	while (!SqStackEmpty(s))
	{
		PopSqStack(s, &e);
		box[k++] = e;
	}
	while (k > 0)
	{
		k--;
		printf("(%d,%d)\n", box[k].i, box[k].j);
	}
	DestroySqStack(s);
	return;

}

