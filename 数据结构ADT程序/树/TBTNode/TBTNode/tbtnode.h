#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType char

typedef struct TBTNode {
	char data;
	int ltag, rtag;//�������
	struct TBTNode * lchild;
	struct TBTNode * rchild;
}TBTNode;

void Visit(TBTNode * bt);//������Ҫ�ķ��ʺ���
void InThread(TBTNode * p, TBTNode * &pre);//��������Զ�����������
void createInThread(TBTNode * root);//�������������������������
TBTNode * First(TBTNode * p);//��pΪ�������������������У����������µĵ�һ�������㷨
TBTNode * Next(TBTNode * p);//�����������������н��p�������µĺ�����
void Inorder(TBTNode * root);//����������������ִ���������
void preThread(TBTNode * p, TBTNode * &pre);//ǰ������Զ�����������
void preorder(TBTNode * root);//ǰ��������������ִ��ǰ�����
void postThread(TBTNode * p, TBTNode * &pre);//��������Զ�����������
