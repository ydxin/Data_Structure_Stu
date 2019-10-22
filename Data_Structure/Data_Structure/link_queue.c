#include <stdio.h>
#include "link_queue.h"
#include <stdlib.h>
#include <stdbool.h>
LinkQueue* InitLinkQueue()
{
	LinkQueue* s = (LinkQueue*)malloc(sizeof(LinkQueue));
	s->front = s->rear = NULL;
	return s;
}

void DestroyLinkQueue(LinkQueue* s)
{
	qQueue* pre = s->front;
	qQueue* p = s;
	if (pre)
	{
		p = pre->next;
		while (p)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(s);
}


bool  LinkQueueEmpty(LinkQueue* s)
{
	return (s->front == NULL);
}

void EnLinkQueue(LinkQueue* s,ElemType e)
{
	qQueue* t = (qQueue*)malloc(sizeof(qQueue));
	t->data = e;
	if (s->front == NULL)
		s->front = s->rear = t;
	else
	{
		s->rear->next = t;
		s->rear = t;
	}
	t->next = NULL;
}

void DeLinkQueue(LinkQueue* s,ElemType * e)
{
	if (s->rear == NULL)
		return false;
	qQueue* t = s->front ;
	if (t->next == NULL)
		s->front = s->rear = NULL;
	else
		s->front = t->next;
	*e = t->data;
	free(t);
	return true;
}


//只带尾指针的循环队列
qQueue* InitRearQueue()
{
	qQueue* s = NULL;
	return s;
}

void EnRearQueue(qQueue** s,ElemType e)
{	
		qQueue* t = (qQueue*)malloc(sizeof(qQueue));
		t->data = e;
		if (!s)
		{
			t->next = t;			
			*s = t;
		}
		t->next = (*s)->next;
		(*s)->next = t;
		(*s) = t;			
}

bool	RearQueue(qQueue* s, ElemType* e)
{
	if (s == NULL)
		return false;
	qQueue* t = s->next;
	if (s->next = s)
	{
		*e = s->next;
		free(s);
		s = NULL;
	}
	else
	{
		*e = t->data;
		s->next = t->next;
		free(t);
	}
	return true;
}

bool RearQueueEmpty(qQueue* s)
{
	return (s == NULL);
}


void QueueNumber(int n)
{
	int e = 0;
	LinkQueue* s = InitLinkQueue();
	for (int i =1; i <= n; i++)
		EnLinkQueue(s, i);	
	while (!LinkQueueEmpty(s))
	{
		DeLinkQueue(s, &e);
		printf("%d\t", e);
		if (!LinkQueueEmpty(s) )
		{
			DeLinkQueue(s, &e);
			EnLinkQueue(s, e);
		}
	}
	printf("\n");
	
}



//