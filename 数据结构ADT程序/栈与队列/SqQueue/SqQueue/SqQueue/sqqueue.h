#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 50
#define ElemType int

typedef struct SqQueue {
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue &qu);
bool IsEmpty(SqQueue qu);
bool IsFull(SqQueue qu);
bool EnterQueue(SqQueue &qu, ElemType x);
bool DeleteQueue(SqQueue &qu, ElemType &x);
bool GetHead(SqQueue qu, ElemType &x);
void ClearQueue(SqQueue &qu);