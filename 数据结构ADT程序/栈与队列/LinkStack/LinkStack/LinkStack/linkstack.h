#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXSIZE 100
#define ElemType int
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode;

void InitStack(LNode * &lst);
void ClearStack(LNode * &lst);
bool IsEmpty(LNode * lst);
bool IsFull(LNode * lst);
bool Push(LNode * lst, ElemType x);
bool Pop(LNode * lst, ElemType &x);
bool GetTop(LNode * lst, ElemType &x);