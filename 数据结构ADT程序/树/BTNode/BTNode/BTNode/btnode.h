#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType char
#define maxSize 100
typedef struct BTNode{
	ElemType data;
	struct BTNode * lchild;
	struct BTNode * rchild;
}BTNode;

void Visit(BTNode * bt);//������Ҫ�ķ��ʺ���
void InitBTNode(BTNode * &bt);
void CreateBTNode(BTNode * &bt);
void DestoryBTNode(BTNode * &bt);
int EmpytBTNode(BTNode * bt);
ElemType Root(BTNode * bt);
BTNode * Parent(BTNode * bt, ElemType x);//����x��˫�׽��
BTNode * LeftChild(BTNode * bt, ElemType x);//����x�����ӽ��
BTNode * RightChild(BTNode * bt, ElemType x);//����x���Һ��ӽ��
void preorder(BTNode * bt);//�������
void inorder(BTNode * bt);//�������
void postorder(BTNode * bt);//�������
void level(BTNode * bt);//��α���
void preorderNonrecursion(BTNode * bt);//��������ǵݹ��㷨
void inorderNonrecursion(BTNode * bt);//��������ǵݹ��㷨
void postorderNonrecursion(BTNode * bt);//��������ǵݹ��㷨
void ClearBTNode(BTNode * &bt);