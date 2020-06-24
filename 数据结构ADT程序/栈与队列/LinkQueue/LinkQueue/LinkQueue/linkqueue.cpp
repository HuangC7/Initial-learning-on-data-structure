#include "linkqueue.h"

void InitQueue(LiQueue * &lqu) {
	lqu = (LiQueue *)malloc(sizeof(LiQueue));
	lqu->front = lqu->rear = NULL;
}

bool IsEmpty(LiQueue * lqu) {
	if (lqu->rear == NULL || lqu->front == NULL)
		return true;
	else
		return false;
}

bool EnterQueue(LiQueue * lqu, ElemType x) {
	QNode * p;
	p = (QNode *)malloc(sizeof(QNode));
	if (p == NULL)
		return false;
	p->data = x;
	p->next = NULL;
	if (lqu->rear == NULL)
		lqu->front = lqu->rear = p;
	else {
		lqu->rear->next = p;
		lqu->rear = p;
	}
	return true;
}

bool DeleteQueue(LiQueue * lqu, ElemType &x) {
	QNode * p;
	if (lqu->rear == NULL)
		return false;
	else
		p = lqu->front;
	if (lqu->front == lqu->rear)
		lqu->front = lqu->rear = NULL;
	else
		lqu->front = lqu->rear->next;
	x = p->data;
	free(p);
	return true;
}
bool GetHead(LiQueue * lqu, ElemType &x) {
	if (IsEmpty(lqu))
		return false;
	x = lqu->front->data;
	return true;
}
void ClearQueue(LiQueue * &lqu) {
	free(lqu);
	lqu->front = lqu->rear = NULL;
}