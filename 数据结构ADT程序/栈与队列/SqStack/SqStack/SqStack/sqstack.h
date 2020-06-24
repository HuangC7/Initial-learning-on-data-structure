#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 100
#define ElemType int

typedef struct SqStack {
	ElemType data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack &st);
void ClearStack(SqStack &st);
bool IsEmpty(SqStack st);
bool IsFull(SqStack st);
bool Push(SqStack &st, ElemType x);
bool Pop(SqStack &st, ElemType &x);
bool GetTop(SqStack st, ElemType &x);