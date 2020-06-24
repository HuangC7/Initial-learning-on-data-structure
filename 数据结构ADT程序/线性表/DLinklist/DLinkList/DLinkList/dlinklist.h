#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define ElemType int
#define MAXSIZE 100

typedef struct DLNode {
	ElemType data;
	DLNode * next;
	DLNode * prior;
};

void InitDLinklist(DLNode * &L);
void CreateDLinklist(DLNode * &L, ElemType a[], int n);
void PrintDLinklist(DLNode * L);