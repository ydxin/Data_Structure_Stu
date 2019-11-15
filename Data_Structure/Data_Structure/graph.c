//#include "graph.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//AdjGraph* CreateAdi(int A[MAXV][MAXV], int n, int e)
//{
//	ArcNode* p;
//	AdjGraph* G = (AdjGraph*)malloc(sizeof(AdjGraph));
//	for (int i = 0; i < n; i++)
//		G->adjlist[i].firstarc = NULL;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j=n-1;j>=0;j--)
//			if (A[i][j] != 0 && A[i][j] != INF)
//			{
//				p = (ArcNode*)malloc(sizeof(ArcNode));
//				p->adjvex = j;
//				p->weight = A[i][j];
//				p->nextarc = G->adjlist[i].firstarc;
//				G->adjlist[i].firstarc = p;
//			}
//	}
//	G->n = n;
//	G->e = e;
//	return G;
//}
//
//void DispAdj(AdjGraph* G)
//{
//	ArcNode* p;
//	for (int i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstarc;
//		printf("%3d: ", i);
//		while (p)
//		{
//			printf("%3d[%d]->", p->adjvex, p->weight);
//			p = p->nextarc;
//		}
//		printf("^\n");
//	}
//}
//
//void DestroyAdj(AdjGraph* G)
//{
//	ArcNode* pre;
//	ArcNode* p;
//	for (int i = 0; i < G->n; i++)
//	{
//		pre = G->adjlist[i].firstarc;
//		if (pre)
//		{
//			p = pre->nextarc;
//			while (p)
//			{
//				free(pre);
//				pre = p;
//				p = p->nextarc;
//			}			
//		}
//	}
//	free(G);
//}
//
//AdjGraph* MatToList(MatGraph g)
//{
//	ArcNode* p;
//	AdjGraph* G = (AdjGraph*)malloc(sizeof(AdjGraph));
//	for (int i = 0; i < g.n; i++)
//		G->adjlist[i].firstarc = NULL;
//	for (int i = 0; i < g.n; i++)
//	{
//		for (int j = g.n - 1; j >= 0; j--)
//		{
//			if (g.edges[i][j] != 0 && g.edges[i][j] != INF)
//			{
//				p = (ArcNode*)malloc(sizeof(ArcNode));
//				p->adjvex = j;
//				p->weight = g.edges[i][j];
//				p->nextarc = G->adjlist[i].firstarc;
//				G->adjlist[i].firstarc = p;
//			}
//		}
//	}
//	G->n = g.n;
//	G->e = g.e;
//	return G;
//}
//
//MatGraph* ListToMat(AdjGraph* G)
//{
//	ArcNode* p;
//	MatGraph* g = (MatGraph*)malloc(sizeof(MatGraph));
//	for (int i = 0; i < G->n; i++)
//	{
//		p = G->adjlist[i].firstarc;
//		while (p)
//		{
//			g->edges[i][p->adjvex] = p->weight;
//			p = p->nextarc;
//		}
//	}
//	g->n = G->n;
//	g->e = G->e;
//	return g;
//}
//
//
//void Prim(MatGraph g, int v)
//{
//	int lowcost[MAXV];
//	int MIN;
//	int closest[MAXV];
//	int k = 0;
//	for (int i = 0; i < g.n; i++)
//	{
//		closest[i] = v;
//		lowcost[i] = g.edges[v][i];
//	}
//	for (int i = 1; i < g.n; i++)
//	{
//		MIN = INF;
//		for (int j = 0; j < g.n; j++)
//		{
//			if (lowcost[j] != 0 && lowcost[j] < MIN)
//			{
//				MIN = lowcost[j];
//				k = j;
//			}
//		}
//		printf("(%d,%d) : %d\n", closest[k], k, MIN);
//		lowcost[k] = 0;
//		for (int j = 0; j < g.n; j++)
//		{
//			if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j])
//			{
//				lowcost[j] = g.edges[k][j];
//				closest[j] = k;
//			}
//		}
//	}
//}
//
//
//void Dijkstra(MatGraph g, int v)
//{
//	int dist[MAXV];
//	int path[MAXV];
//	int s[MAXV];
//	int minDis = 0;
//	int u = 0;
//	for (int i = 0; i < g.n; i++)
//	{
//		dist[i] = g.edges[v][i];//从邻接矩阵中获取权值
//		s[i] = 0;//为1表示顶点在S中，0在U中
//		if (g.edges[v][i] < INF)
//			path[i] = v;
//		else
//			path[i] = -1;
//	}
//	s[v] = 1;
//	path[v] = 0;
//	for (int i = 0; i < g.n-1; i++)
//	{
//		minDis = INF;
//		for (int j = 0; j < g.n; j++)
//		{
//			if (s[j] == 0 && dist[j] < minDis)
//			{
//				minDis = dist[j];
//				u= j;
//			}
//		}
//		s[u] = 1;
//		for (int i = 0; i < g.n; i++)
//		{
//			if (s[i] == 0)
//			{
//				if (g.edges[u][i] < INF && g.edges[u][i] + dist[u] < dist[i])
//				{
//					dist[i] = g.edges[u][i] + dist[u];
//					path[i] = u;
//				}
//			}
//		}
//	}
//	Dispath(g, dist, path, s, v);
//}
//
//void Dispath(MatGraph g, int dist[], int path[], int s[], int v)
//{
//	int apath[MAXV];
//	int d;
//	int k;
//	for (int i = 0; i < g.n; i++)
//	{
//		if (s[i] == 1 && i != v)
//		{
//			printf("从顶点%d到顶点%d得路径长度为：%d\t路径为：", v, i, dist[i]);
//			d = 0;
//			apath[d] = i;
//			k = path[i];
//			if (k == -1)
//				printf("无路径\n");
//			else
//			{
//				while (k != v)
//				{
//					d++;
//					apath[d] = k;
//					k = path[k];
//				}
//				d++;
//				apath[d] = v;
//				for (int i = d; i >= 0; i--)
//				{
//					printf("%d\t", apath[i]);
//				}
//				printf("\n");
//			}
//		}
//	}
//}
//
//void Floyd(MatGraph g)
//{
//	int A[MAXV][MAXV];
//	int path[MAXV][MAXV];
//	for (int i = 0; i < g.n; i++)
//	{
//		for (int j = 0;j < g.n; j++)
//		{ 
//			A[i][j] = g.edges[i][j];
//			if (i != j && g.edges[i][j] < INF)
//			{
//				path[i][j] = i;
//			}
//			else
//				path[i][j] = -1;
//		}
//	}
//
//	for (int k = 0; k < g.n; k++)
//	{
//		for (int i = 0; i < g.n; i++)
//		{
//			for (int j = 0; j < g.n; j++)
//			{
//				if (A[i][j] > A[i][k] + A[k][j])
//				{
//					A[i][j] = A[i][k] + A[k][j];
//					path[i][j] = path[k][j];
//				}
//			}
//		}
//	}
//}
//
//void TopSort(AdjGraph* G)
//{
//	int St[MAXV];
//	int top = -1;
//	ArcNode* p;
//	for (int i = 0; i < G->n; i++)
//	{
//		p = G->adjlist1[i].firstarc;
//		while (p)
//		{
//			G->adjlist1[p->adjvex].count++;
//			p = p->nextarc;
//		}
//	}
//
//	for (int i = 0; i < G->n; i++)
//	{
//		if (G->adjlist1[i].count == 0)
//		{
//			top++;
//			St[top] = i;
//		}
//	}
//
//	while (top > -1)
//	{
//		int i;
//		i = St[top]; 
//		top--;
//		printf("%d", i);
//		p = G->adjlist1[i].firstarc;
//		while (p)
//		{
//			int j;
//			j = p->adjvex;
//			G->adjlist1[j].count--;
//			if (G->adjlist1[j].count == 0)
//			{
//				top ++;
//				St[top] = j;
//			}
//			p = p->nextarc;
//		}
//	}
//
//
//}