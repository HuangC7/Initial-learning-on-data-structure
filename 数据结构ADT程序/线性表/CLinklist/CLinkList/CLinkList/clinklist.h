#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define ElemType int
#define MAXSIZE 100

typedef struct CLNode {
	ElemType data;
	CLNode * next;
}CLNode;

void InitCLinklist(CLNode * &CL);
void CreateCLinklist(CLNode * &CL, ElemType a[], int n);
void PrintCLinklist(CLNode * CL);