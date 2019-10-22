#include "sqQueue.h"
#include <stdlib.h>
#include <stdbool.h>
SqQueue* InitQueue()
{
	SqQueue* s = (SqQueue*)malloc(sizeof(SqQueue));
	s->front =0;
	s->rear = 0;
	return s;
}

void	 DestroyQueue(SqQueue* s)
{
	free(s);
}

int QueueEmpty(SqQueue* s)
{
	return (s->front == s->rear);
}

bool EnQueue(SqQueue* s, ElemType e)
{
	if ((s->rear +1) / MAX_SIZE ==s->front )
		return false;
	s->rear =(s->rear +1) / MAX_SIZE;
	s->data[s->rear] = e;
	return true;
}

bool DeQueue(SqQueue* s, ElemType* e)
{
	if (QueueEmpty(s))
		return  false;	
	*e = s->data[++(s->front)];
	return true;
}

