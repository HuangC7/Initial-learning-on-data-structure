#include "sqqueue.h"

void InitQueue(SqQueue &qu) {
	qu.front = qu.rear = 0;
}

bool IsEmpty(SqQueue qu) {
	if (qu.front == qu.rear)
		return true;
	else
		return false;
}

bool IsFull(SqQueue qu) {
	if ((qu.rear + 1) % MAXSIZE == qu.front)
		return true;
	else
		return false;
}

bool EnterQueue(SqQueue &qu, ElemType x) {
	if (IsFull(qu))
		return false;
	qu.rear = (qu.rear + 1) % MAXSIZE;
	qu.data[qu.rear] = x;
	return true;
}

bool DeleteQueue(SqQueue &qu, ElemType &x) {
	if (IsEmpty(qu))
		return false;
	qu.front = (qu.front + 1) % MAXSIZE;
	x = qu.data[qu.front];
	return true;
}

bool GetHead(SqQueue qu, ElemType &x) {
	if (IsEmpty(qu))
		return false;
	x = qu.data[qu.front];
	return true;
}

void ClearQueue(SqQueue &qu) {
	qu.front = qu.rear = 0;
}