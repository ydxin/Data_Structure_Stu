#ifndef  _STACK_H_
#define _STACK_H_

#define MAX_SIZE	50
#define FAILED		-1
#define SUCCESS	0

typedef char ElemType;

typedef struct SqStack
{
	ElemType data[MAX_SIZE];
	int top;
}SqStack;

typedef SqStack StackType;
StackType* InitStack();
void DestroyStack(StackType* s);
int StackEmpty(StackType* s);
int Push(StackType* s, ElemType e);
int Pop(StackType* s, ElemType* e);
int GetTop(StackType* s, ElemType* e);
int JudgeSym(ElemType * str);
void Trans(ElemType* exp, ElemType postExp[]);





















































































































































































#endif // ! _STACK_H_
