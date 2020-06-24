#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define ElemType char

typedef struct TBTNode {
	char data;
	int ltag, rtag;//线索标记
	struct TBTNode * lchild;
	struct TBTNode * rchild;
}TBTNode;

void Visit(TBTNode * bt);//遍历需要的访问函数
void InThread(TBTNode * p, TBTNode * &pre);//中序遍历对二叉树线索化
void createInThread(TBTNode * root);//中序遍历建立中序线索二叉树
TBTNode * First(TBTNode * p);//以p为根的中序线索二叉树中，中序序列下的第一个结点的算法
TBTNode * Next(TBTNode * p);//在中序线索二叉树中结点p在中序下的后序结点
void Inorder(TBTNode * root);//中序线索二叉树上执行中序遍历
void preThread(TBTNode * p, TBTNode * &pre);//前序遍历对二叉树线索化
void preorder(TBTNode * root);//前序线索二叉树上执行前序遍历
void postThread(TBTNode * p, TBTNode * &pre);//后序遍历对二叉树线索化
