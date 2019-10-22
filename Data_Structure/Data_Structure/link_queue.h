#ifndef  _LINK_QUEUE_H_
#define _LINK_QUEUE_H_
#include <stdbool.h>
typedef int ElemType;

typedef struct qQueue
{
	ElemType data;
	struct qQueue* next;
}qQueue;

typedef struct LinkQueue
{
	qQueue* front;
	qQueue* rear;

}LinkQueue;


LinkQueue* InitLinkQueue();
void DestroyLinkQueue(LinkQueue* s);
bool  LinkQueueEmpty(LinkQueue* s);
void EnLinkQueue(LinkQueue* s, ElemType e);
void DeLinkQueue(LinkQueue* s, ElemType* e);

//只带尾指针的循环队列
qQueue* InitRearQueue();
void EnRearQueue(qQueue** s, ElemType e);
bool	RearQueue(qQueue* s, ElemType* e);
bool RearQueueEmpty(qQueue* s);
//
#endif // ! _LINK_QUEUE_H_
