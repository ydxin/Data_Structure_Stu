#ifndef _SQ_QUEUE_H_
#define _SQ_QUEUE_H_

#define MAX_SIZE 50

typedef int ElemType;

//���ö�β�Ͷ���ָ���ѭ�����нṹ����һ���ռ�
//���ö��׺�count������ѭ�����нṹ���Դﵽ���ռ�

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
