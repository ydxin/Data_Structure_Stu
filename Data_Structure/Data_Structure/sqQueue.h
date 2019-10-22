#ifndef _SQ_QUEUE_H_
#define _SQ_QUEUE_H_

#define MAX_SIZE 50

typedef int ElemType;

//采用队尾和队首指针的循环队列结构会少一个空间
//采用队首和count计数的循环队列结构可以达到满空间

typedef struct SqQueue
{
	ElemType data[MAX_SIZE];
	int front;
	int rear;
}SqQueue;

typedef struct SqQueue1
{
	ElemType data[MAX_SIZE];
	int front;
	int count;
}SqQueue1;

#endif // !_SQ_QUEUE_H_
