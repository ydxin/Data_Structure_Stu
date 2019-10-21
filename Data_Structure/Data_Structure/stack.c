#include "stack.h"
#include <stdlib.h>

StackType* InitStack()
{
	StackType* s = (StackType*)malloc(sizeof(StackType));
	s->top = -1;
}

void DestroyStack(StackType* s)
{
	free(s);
}

int StackEmpty(StackType* s)
{
	return (s->top == -1);
}

int Push(StackType* s, ElemType e)
{
	if (s->top == MAX_SIZE - 1) return FAILED;
	s->data[++s->top] = e;
	return SUCCESS;
}

int Pop(StackType* s, ElemType* e)
{
	if (s->top == -1) return FAILED;
	*e = s->data[s->top--];
	return SUCCESS;

}

int GetTop(StackType* s, ElemType* e)
{
	if (s->top == -1) return FAILED;
	*e = s->data[s->top];
	return SUCCESS;
}

int JudgeSym(ElemType * str)
{
	StackType* s = InitStack();
	ElemType a ;
	ElemType* e=&a;
	for (int i = 0; str[i] != 0; i++)
		Push(s, str[i]);
	for (int i = 0; str[i] != 0; i++)
	{
		Pop(s, e);
		if (str[i] != (*e))
		{
			DestroyStack(s);
			return FAILED;
		}
	}
	DestroyStack(s);
	return SUCCESS;

}

void Trans(ElemType* exp, ElemType postExp[])
{

}
