#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXSIZE 100
#define ElemType int
typedef struct Node {
	ElemType data;
	struct Node * next;
}Node;

void PrintLinklist(Node * linklist);
void InitLinklist(Node * &linklist);
void CreatLinklist(Node * &linklist, ElemType a[], int n);
int Locate(Node * linklist, ElemType e);
ElemType GetData(Node * linklist, int i);
void InsLinklist(Node * &linklist, int i, ElemType e);
ElemType DelLinklist(Node * &linklist, int i, ElemType &e);
void MergeLinklist(Node * A, Node * B, Node * &C);
int LinklistLength(Node * linklist);
void DestroyLinklist(Node * &linklist);
void ClearLinklist(Node * &linklist);
bool EmptyLinklist(Node * linklist);