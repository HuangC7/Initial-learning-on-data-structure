#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType float
#define maxSize 100

typedef struct OLNode {
	int row, col;					//行号和列号
	struct OLNode * right, * down;	//指向右边结点和下方结点的指针
	ElemType val;
}OLNode;
typedef struct {
	OLNode * rhead, * chead;		//指向两头结点数组的指针
	int m, n, k;					//矩阵行数、列数、以及非零结点总数
}CrossList;

int createcrossListmat(ElemType A[][maxSize], int m, int n, int k, CrossList &M);