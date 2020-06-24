#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXSIZE 100
#define ElemType int
typedef struct SeqList {
	ElemType data[MAXSIZE];
	int last;
}SeqList;

void InitSeqlist(SeqList &seqlist);
void CreateSeqlist(SeqList &seqlist, ElemType data[], int n);
void PrintSeqlist(SeqList seqlist);
ElemType GetData(SeqList seqlist, int i);
int Locate(SeqList seqlist, ElemType e);
void InsSeqlist(SeqList &seqlist, int i, ElemType e);
ElemType DelSeqlist(SeqList &seqlist, int i, ElemType &e);
void Merge2Seqlist(SeqList la, SeqList lb, SeqList &lc);
int ListLength(SeqList seqlist);
void DestroyList(SeqList& seqList);
void ClearList(SeqList& seqlist);
bool EmptyList(SeqList seqlist);
void Delxtoy(SeqList &seqlist, ElemType x, ElemType y);
void Paixu(SeqList &seqlist);
void Delequal(SeqList &seqlist);