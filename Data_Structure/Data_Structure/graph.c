#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

AdjGraph* CreateAdi(int A[MAXV][MAXV], int n, int e)
{
	ArcNode* p;
	AdjGraph* G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (int i = 0; i < n; i++)
	{
		for (int j=n-1;j>=0;j--)
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	}
	G->n = n;
	G->e = e;
	return G;
}

void DispAdj(AdjGraph* G)
{
	ArcNode* p;
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%3d: ", i);
		while (p)
		{
			printf("%3d[%d]->", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

void DestroyAdj(AdjGraph* G)
{
	ArcNode* pre;
	ArcNode* p;
	for (int i = 0; i < G->n; i++)
	{
		pre = G->adjlist[i].firstarc;
		if (pre)
		{
			p = pre->nextarc;
			while (p)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}			
		}
	}
	free(G);
}

AdjGraph* MatToList(MatGraph g)
{
	ArcNode* p;
	AdjGraph* G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < g.n; i++)
		G->adjlist[i].firstarc = NULL;
	for (int i = 0; i < g.n; i++)
	{
		for (int j = g.n - 1; j >= 0; j--)
		{
			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = g.n;
	G->e = g.e;
	return G;
}

MatGraph* ListToMat(AdjGraph* G)
{
	ArcNode* p;
	MatGraph* g = (MatGraph*)malloc(sizeof(MatGraph));
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		while (p)
		{
			g->edges[i][p->adjvex] = p->weight;
			p = p->nextarc;
		}
	}
	g->n = G->n;
	g->e = G->e;
	return g;
}
