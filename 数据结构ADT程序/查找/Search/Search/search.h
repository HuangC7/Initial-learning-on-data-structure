#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define maxSize 100

/* 索引表 */
typedef struct {
	int key;//假设表内元素为int型
	int low, high;//记录某块中第一个和最后一个元素的位置
}indexElem;
indexElem index[maxSize];//定义索引表，maxSize是已定义的常量
/* 二叉排序树 */
#define LH +1//左高
#define EH 0//等高
#define RH -1//右高
typedef struct BTNode {
	int key;//这里将data改为key，代表关键字
	int bf;//结点的平衡因子
	struct BTNode * lchild;
	struct BTNode * rchild;
}BTNode;
int Delete(BTNode * &p) {
	BTNode * q, *s;
	//从二叉排序树中删除结点p，并重接它的左或右子树
	if (p->rchild == NULL) {//右子树空则只需重接它的左子树
		q = p;
		p = p->lchild;
		free(q);
	}else if (p->lchild == NULL) {//只需重接它的右子树
		q = p;
		p = p->rchild;
		free(q);
	}else {//左右子树均不空
		q = p;
		s = p->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}//转左，然后向右到尽头
		p->key = s->key;//s指向被删结点的“前驱”
		if (q != p) q->rchild = s->lchild;//重接*q的右子树
		else q->lchild = s->lchild;//重接*q的左子树
		delete(s);
	}
	return 1;
}
void R_Rotate(BTNode * &p) {
	/*对以*p为根的二叉排序树作右旋处理，处理之后p指向新的树根结点
	，即旋转处理之前的左子树的根结点*/
	BTNode * lc = p->lchild;//lc指向的*p的左子树根结点
	p->lchild = lc->rchild;//lc的右子树挂接为*p的左子树
	lc->rchild = p;
	p = lc;//p指向新的根结点
}
void L_Rotate(BTNode * &p) {
	/*对以*p为根的二叉排序树作左旋处理，处理之后p指向新的树根结点
	，即旋转处理之前的右子树的根结点*/
	BTNode * rc = p->rchild;//rc指向的*p的右子树根结点
	p->rchild = rc->lchild;//rc的左子树挂接为*p的右子树
	rc->lchild = p;
	p = rc;//p指向新的根结点
}
void LeftBalance(BTNode * &bt) {
	//对以指针bt所指结点为根的二叉树作左旋平衡处理，本算法结束时，指针bt指向新的根结点
	BTNode * lc = bt->lchild;//lc指向*bt的左子树根结点
	switch (lc->bf){//检查*bt的左子树的平衡度，并作相应平衡处理
		case LH: {//新结点插入在*bt的左孩子的左子树上，要作单右旋处理
			bt->bf = lc->bf = EH;
			R_Rotate(bt);
			break;
		}
		case RH: {//新结点插入在*bt的左孩子的右子树上，要作双旋处理（先左后右）
			BTNode * rd = lc->rchild;//rd指向*bt的左孩子的右子树根
			switch (rd->bf){//修改*bt及其左孩子的平衡因子
				case LH: {
					bt->bf = RH;
					lc->bf = EH;
					break;
				}
				case EH: {
					bt->bf = lc->bf = EH;
					break;
				}
				case RH:{
					bt->bf = EH;
					lc->bf = LH;
					break;
				}
			}
			rd->bf = EH;
			L_Rotate(bt->lchild);//对*bt的左子树作左旋平衡处理
			R_Rotate(bt);//对*bt作右旋平衡处理
		}
	}
}
void RightBalance(BTNode * &bt) {
	//对以指针bt所指结点为根的二叉树作右旋平衡处理，本算法结束时，指针bt指向新的根结点
	BTNode * rc = bt->rchild;//rc指向*bt的右子树根结点
	switch (rc->bf) {//检查*bt的右子树的平衡度，并作相应平衡处理
		case LH: {//新结点插入在*bt的右孩子的左子树上，要作双旋处理(先右后左)
			BTNode * ld = rc->lchild;//ld指向*bt的右孩子的左子树根
			switch (ld->bf) {//修改*bt及其右孩子的平衡因子
				case LH: {
					bt->bf = EH;
					rc->bf = RH;
					break;
				}
				case EH: {
					bt->bf = rc->bf = EH;
					break;
				}
				case RH: {
					bt->bf = LH;
					rc->bf = EH;
					break;
				}
			}
			ld->bf = EH;
			R_Rotate(bt->rchild);//对*bt的右子树作右旋平衡处理
			L_Rotate(bt);//对*bt作左旋平衡处理
			break;
		}
		case RH: {//新结点插入在*bt的右孩子的右子树上，要作单左旋处理
			bt->bf = rc->bf = EH;
			L_Rotate(bt);
		}
	}
}

int Search(int a[], int n, int k);//顺序查找法算法
int Bsearch(int R[], int low, int high, int k);//折半查找法算法
int IndexSearch(indexElem index[], int n, int R[], int k);//分块查找法算法
BTNode * BSTSearch(BTNode * bt, int key);//二叉排序树查找关键字的算法
int BSTInsert(BTNode * &bt, int key);//二叉排序树插入关键字的算法
void CreateBST(BTNode * &bt, int key[], int n);//二叉排序树的构造算法
int DeleteBST(BTNode * &bt, int key);//二叉排序树删除关键字的算法
int InsertAVL(BTNode * &bt, int key, bool &taller);//平衡二叉排序树插入关键字的算法
int CreateAVL(BTNode * &bt, int key[], int n, bool &taller);//平衡二叉排序树的构造算法