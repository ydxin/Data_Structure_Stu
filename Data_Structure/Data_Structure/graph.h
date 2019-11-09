#ifndef  _GRAPH_H_
#define _GRAPH_H_


#define INF 32767
#define MAXV 30


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
	int n;
	int e;
}AdjGraph;

AdjGraph* CreateAdi(int A[MAXV][MAXV], int n, int e);
void DispAdj(AdjGraph* G);
MatGraph* ListToMat(AdjGraph* G);
AdjGraph* MatToList(MatGraph g);





#endif // ! _GRAPH_H_
