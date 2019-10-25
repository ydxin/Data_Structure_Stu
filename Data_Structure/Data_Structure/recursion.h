#ifndef  _RECURSION_H_
#define _RECURSION_H_

#define MAX_SIZE	50
#define M				4
#define N				4

extern int mg1[M + 2][N + 2];

typedef struct Box
{
	int i;
	int j;
}Box;

typedef struct PathType
{
	Box data[MAX_SIZE];
	int length;
}PathType;



int Factorial(int n);
int Fibonacci(int n);
int Hanoi(int n, char x, char y, char z);
double MinArray(double *A, int i);
double MaxArray(double* A, int i);
double CalcAver(int* a, int n);
void RecuMgPath(int xi, int yi, int xe, int ye, PathType path);
int CalcIntBit(int data);




#endif // ! _RECURSION_H_
