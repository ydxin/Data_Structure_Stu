#ifndef  _GRAPH_H_
#define _GRAPH_H_


#define INF 32767
#define MAXV 10
#define MAX_SIZE 50

typedef struct VertexType
{
	int no;
	int i;
}VertexType;

typedef struct MatGraph
{
	int edges[MAXV][MAXV];
	int n;
	int e;
	VertexType vexs[MAXV];
}MatGraph;

typedef struct ANode
{
	int adjvex;
	struct ANode* nextarc;
	int weight;

}ArcNode;

typedef struct  VNode
{
	int info;
	ArcNode* firstarc;
}VNode;

typedef struct AdjGraph
{
	VNode adjlist[MAXV];
	TopVNode adjlist1[MAXV];
	int n;
	int e;
}AdjGraph;


typedef struct  Edge
{
	int u;
	int v;
	int w;
}Edge;

typedef struct TopVNode
{
	VertexType data;
	int count;
	ArcNode* firstarc;
}TopVNode;


AdjGraph* CreateAdi(int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph* G);
MatGraph* ListToMat(AdjGraph* G);
AdjGraph* MatToList(MatGraph g);
void Prim(MatGraph g, int v);
void Dijkstra(MatGraph g, int v);
void Dispath(MatGraph g, int dist[], int path[], int s[], int v);
void Floyd(MatGraph g);
void TopSort(AdjGraph* G);
#endif // ! _GRAPH_H_
