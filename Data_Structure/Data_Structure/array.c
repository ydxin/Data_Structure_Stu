#include "array.h"
#include <stdio.h>

int symArr[N][N] =
{
	{1,2,3,4},
	{2,2,3,4},
	{3,3,3,4},
	{4,4,4,4}
};

void Josephus(int n, int num)
{
	int p[MAX_SIZE];
	for (int i = 0; i < n; i++)
		p[i] = i + 1;
	printf("³ö¶ÓË³Ðò:\t");
	int t = 0;
	for (int i = n; i > 0; i--)
	{
		t = (t + num - 1) % i;
		printf("%d\t", p[t]);
		for (int j = t + 1; j < i; j++)
			p[j - 1] = p[j];
	}
}

void CreateMat(TSMatrix* t, int(*A)[N])
{
	t->rows = M;
	t->cols = N;
	t->nums = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] != 0)
			{
				t->data[t->nums].r = i;
				t->data[t->nums].c = j;
				t->data[t->nums].d = A[i][j];
				t->nums++;
			}
		}
	}
}
