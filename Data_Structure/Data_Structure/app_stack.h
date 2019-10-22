#ifndef  _APP_STACK_H_
#define _APP_STACK_H_
#include <stdbool.h>
#define	M					8
#define	N					8
#define	MAX_SIZE    50

extern int mg[M + 2][N + 2]; 
typedef struct Box
{
	int i;
	int j;
	int adj;
}Box;

typedef struct SqMgStack
{
	Box data[MAX_SIZE];
	int top;
}SqMgStack;

SqMgStack* InitSqStack();
void PopSqStack(SqMgStack* s, Box* e);
void PushSqStack(SqMgStack* s, Box e);
int SqStackEmpty(SqMgStack* s);
void DestroySqStack(SqMgStack* s);
bool MgPath(int xi, int yi, int xe, int ye);
void FindThePath(SqMgStack* s, Box* box);
void GetSqStack(SqMgStack* s, Box* e);
#endif // ! _APP_STACK_H_
