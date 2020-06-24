#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define ElemType int

typedef struct QNode {
	ElemType data;
	struct QNode * next;
}QNode;
typedef struct LiQueue {
	QNode * front;
	QNode * rear;
}LiQueue;

void InitQueue(LiQueue * &lqu);
bool IsEmpty(LiQueue * lqu);
bool EnterQueue(LiQueue * lqu, ElemType x);
bool DeleteQueue(LiQueue * lqu, ElemType &x);
bool GetHead(LiQueue * lqu, ElemType &x);
void ClearQueue(LiQueue * &lqu);