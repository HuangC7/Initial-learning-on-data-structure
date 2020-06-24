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

void Visit(BTNode * bt);//遍历需要的访问函数
void InitBTNode(BTNode * &bt);
void CreateBTNode(BTNode * &bt);
void DestoryBTNode(BTNode * &bt);
int EmpytBTNode(BTNode * bt);
ElemType Root(BTNode * bt);
BTNode * Parent(BTNode * bt, ElemType x);//返回x的双亲结点
BTNode * LeftChild(BTNode * bt, ElemType x);//返回x的左孩子结点
BTNode * RightChild(BTNode * bt, ElemType x);//返回x的右孩子结点
void preorder(BTNode * bt);//先序遍历
void inorder(BTNode * bt);//中序遍历
void postorder(BTNode * bt);//后序遍历
void level(BTNode * bt);//层次遍历
void preorderNonrecursion(BTNode * bt);//先序遍历非递归算法
void inorderNonrecursion(BTNode * bt);//中序遍历非递归算法
void postorderNonrecursion(BTNode * bt);//后序遍历非递归算法
void ClearBTNode(BTNode * &bt);