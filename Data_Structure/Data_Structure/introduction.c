#include "introduction.h"
#include <stdio.h>
#include "public.h"
/*
1. ����Ԫ�������ݵĻ�����λ
2. ���νṹ����ʼ�ڵ� : a   �ն˽ڵ㣺b,e,i,g
3. �߼��ṹ�ͼ�����޹أ��洢�ṹ������֮����߼���ϵ��
	������еı�ʾ��
*/

int  SumN( int (* in) [N])
{
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			s = s + in[i][j];
		}
	}
	return s;
}

void Swap(int a, int b, int c)
{
	if (a > b)
	{
		if (c > a)
			printf("%d  %d  %d", c, a, b);
		if (c<b)
			printf("%d  %d  %d", a, b, c);
		else
			printf("%d  %d  %d", a, c, b);
	}
	else
	{
		if (c>b)
			printf("%d  %d  %d", c, b, a);
		if (c<a)
			printf("%d  %d  %d", b, a, c);
		else 
			printf("%d  %d  %d", b, c, a);
	}
}

void FindMaxAndMin(int *a,int len)
{
	int max = a[0];
	int min = a[0];

	for (int i = 1; i < len; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	printf("max: %d  min: %d  ", max, min);
	printf("\n%d", len);
}

void SumExp(int n,int flag)
{

	int sum = 0;
	char *ch;
	start = clock();
	if (flag == ADD)
	{
		for (int i = 1; i <= n; i++)
		{
			sum = sum + i;
		}
		ch = "ADD";
	}
	if (flag == GAUSS)
	{
		sum = (1 + n)*n / 2;
		ch = "GAUSS";
	}
	stop = clock();
	duration = stop - start;
	printf("%s time is %f", ch, duration);
}

