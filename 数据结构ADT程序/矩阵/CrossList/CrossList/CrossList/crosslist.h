#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType float
#define maxSize 100

typedef struct OLNode {
	int row, col;					//�кź��к�
	struct OLNode * right, * down;	//ָ���ұ߽����·�����ָ��
	ElemType val;
}OLNode;
typedef struct {
	OLNode * rhead, * chead;		//ָ����ͷ��������ָ��
	int m, n, k;					//�����������������Լ�����������
}CrossList;

int createcrossListmat(ElemType A[][maxSize], int m, int n, int k, CrossList &M);