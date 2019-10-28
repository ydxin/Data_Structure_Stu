#pragma once

#define MAX_SIZE 50
#define N 4
#define M 5
extern int symArr[N][N];

typedef struct TupNode
{
	int r;
	int c;
	int d;
}TupNode;

typedef struct TSMatrix
{
	int rows;
	int cols;
	int nums;
	TupNode data[MAX_SIZE];
}TSMatrix;