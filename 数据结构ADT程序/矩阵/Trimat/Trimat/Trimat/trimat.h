#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType int
#define maxSize 100
typedef struct Trimat {
	ElemType val;
	int i, j;
}Trimat;

void createtrimat(ElemType A[][maxSize], int m, int n, Trimat B[]);
void print(Trimat B[]);
void trstrimat(Trimat A[], Trimat B[]);//¾ØÕóµ¹ÖÃ
void fasttrstrimat(Trimat A[], Trimat B[]);//¾ØÕó¿ìËÙµ¹ÖÃ
void addtrimat(Trimat C[], Trimat A[], Trimat B[]);//¾ØÕóÏà¼Ó
int getvalue(Trimat D[], int i, int j);
void muttrimat(Trimat C[], Trimat A[], Trimat B[], int m, int n, int k);//¾ØÕóÏà³Ë