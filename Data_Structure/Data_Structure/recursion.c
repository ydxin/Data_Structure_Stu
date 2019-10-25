#include "recursion.h"
#include <stdio.h>
#include <stdbool.h>

int mg1[M + 2][N + 2] =
{
	{1,1,1,1,1,1},
	{1,0,0,0,1,1},
	{1,0,1,0,0,1},
	{1,0,0,0,1,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1},
};

void RecuMgPath(int xi, int yi, int xe, int ye, PathType path)
{
	if (xi == xe && yi == ye)
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("The path is : \n");
		for (int i = 0; i < path.length; i++)
			printf("(%d,%d)\n", path.data[i].i, path.data[i].j);		
	}
	else
	{
		int ix = 0;
		int iy = 0;
		if (mg1[xi][yi] == 0)
		{
			int di = 0;
			while (di < 4)
			{
				path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				path.length++;
				switch (di)
				{
				case 0:
					ix = xi - 1;
					iy = yi;
					break;
				case 1:
					ix = xi;
					iy = yi + 1;
					break;
				case 2:
					ix = xi + 1;
					iy = yi;
					break;
				case 3:
					ix = xi;
					iy = yi - 1;
					break;
				default:
					break;
				}
				mg1[xi][yi] = -1;
				RecuMgPath(ix, iy, xe, ye, path);
				mg1[xi][yi] = 0;
				path.length--;
				di++;
			}
		}
	}
}


int Factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return (Factorial(n - 1) * n);
}

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int Hanoi(int n,char x, char y,char z)
{
	if (n == 1)
		printf("(%d,%c,%c)\n", n, x, z);
	else
	{
		Hanoi(n - 1, x, z, y);
		printf("(%d,%c,%c)\n", n, x, z);
		Hanoi(n - 1, y, x, z);
	}
}

double MinArray(double* A, int i )
{
	double min = 0;
	if (i == 0) 
		return A[0];
	else
	{
		min = MinArray(A, i - 1);
		min = min > A[i - 1] ? A[i - 1] : min;
		return min;
	}
}

double MaxArray(double* A, int i)
{
	double max = 0;
	if (i == 0)
		return A[0];
	else
	{
		max = MaxArray(A, i - 1);
		max = max > A[i - 1] ? max : A[i - 1];
		return max;
	}
}

double CalcAver(int* a,int n )
{
	double avr = 0;
	if (n == 1)
		return a[0] / n;
	else
	{
		avr = CalcAver(a, n - 1);
		avr = (avr * (n - 1) + a[n - 1]) / n;
		return avr;
	}
}

int CalcIntBit(int data)
{
	int n = 0;
	if (data / 10 == 0)
		return 1;
	else
	{
		n = 1+ CalcIntBit(data / 10);                                  
		return  n;
	}
}

int StepNums(int n )
{
	if (n == 1 || n == 2)
		return  n;
	else
		return StepNums(n - 1) + StepNums(n - 2);
}