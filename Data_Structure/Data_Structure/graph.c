#include "graph.h"

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