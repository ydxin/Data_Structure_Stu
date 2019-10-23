#include "recursion.h"
#include <stdio.h>
#include <stdbool.h>

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