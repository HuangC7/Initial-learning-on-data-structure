#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define maxSize 100

/* ������ */
typedef struct {
	int key;//�������Ԫ��Ϊint��
	int low, high;//��¼ĳ���е�һ�������һ��Ԫ�ص�λ��
}indexElem;
indexElem index[maxSize];//����������maxSize���Ѷ���ĳ���
/* ���������� */
#define LH +1//���
#define EH 0//�ȸ�
#define RH -1//�Ҹ�
typedef struct BTNode {
	int key;//���ｫdata��Ϊkey������ؼ���
	int bf;//����ƽ������
	struct BTNode * lchild;
	struct BTNode * rchild;
}BTNode;
int Delete(BTNode * &p) {
	BTNode * q, *s;
	//�Ӷ�����������ɾ�����p�����ؽ��������������
	if (p->rchild == NULL) {//����������ֻ���ؽ�����������
		q = p;
		p = p->lchild;
		free(q);
	}else if (p->lchild == NULL) {//ֻ���ؽ�����������
		q = p;
		p = p->rchild;
		free(q);
	}else {//��������������
		q = p;
		s = p->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}//ת��Ȼ�����ҵ���ͷ
		p->key = s->key;//sָ��ɾ���ġ�ǰ����
		if (q != p) q->rchild = s->lchild;//�ؽ�*q��������
		else q->lchild = s->lchild;//�ؽ�*q��������
		delete(s);
	}
	return 1;
}
void R_Rotate(BTNode * &p) {
	/*����*pΪ���Ķ�����������������������֮��pָ���µ��������
	������ת����֮ǰ���������ĸ����*/
	BTNode * lc = p->lchild;//lcָ���*p�������������
	p->lchild = lc->rchild;//lc���������ҽ�Ϊ*p��������
	lc->rchild = p;
	p = lc;//pָ���µĸ����
}
void L_Rotate(BTNode * &p) {
	/*����*pΪ���Ķ�����������������������֮��pָ���µ��������
	������ת����֮ǰ���������ĸ����*/
	BTNode * rc = p->rchild;//rcָ���*p�������������
	p->rchild = rc->lchild;//rc���������ҽ�Ϊ*p��������
	rc->lchild = p;
	p = rc;//pָ���µĸ����
}
void LeftBalance(BTNode * &bt) {
	//����ָ��bt��ָ���Ϊ���Ķ�����������ƽ�⴦�����㷨����ʱ��ָ��btָ���µĸ����
	BTNode * lc = bt->lchild;//lcָ��*bt�������������
	switch (lc->bf){//���*bt����������ƽ��ȣ�������Ӧƽ�⴦��
		case LH: {//�½�������*bt�����ӵ��������ϣ�Ҫ������������
			bt->bf = lc->bf = EH;
			R_Rotate(bt);
			break;
		}
		case RH: {//�½�������*bt�����ӵ��������ϣ�Ҫ��˫������������ң�
			BTNode * rd = lc->rchild;//rdָ��*bt�����ӵ���������
			switch (rd->bf){//�޸�*bt�������ӵ�ƽ������
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
			L_Rotate(bt->lchild);//��*bt��������������ƽ�⴦��
			R_Rotate(bt);//��*bt������ƽ�⴦��
		}
	}
}
void RightBalance(BTNode * &bt) {
	//����ָ��bt��ָ���Ϊ���Ķ�����������ƽ�⴦�����㷨����ʱ��ָ��btָ���µĸ����
	BTNode * rc = bt->rchild;//rcָ��*bt�������������
	switch (rc->bf) {//���*bt����������ƽ��ȣ�������Ӧƽ�⴦��
		case LH: {//�½�������*bt���Һ��ӵ��������ϣ�Ҫ��˫������(���Һ���)
			BTNode * ld = rc->lchild;//ldָ��*bt���Һ��ӵ���������
			switch (ld->bf) {//�޸�*bt�����Һ��ӵ�ƽ������
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
			R_Rotate(bt->rchild);//��*bt��������������ƽ�⴦��
			L_Rotate(bt);//��*bt������ƽ�⴦��
			break;
		}
		case RH: {//�½�������*bt���Һ��ӵ��������ϣ�Ҫ������������
			bt->bf = rc->bf = EH;
			L_Rotate(bt);
		}
	}
}

int Search(int a[], int n, int k);//˳����ҷ��㷨
int Bsearch(int R[], int low, int high, int k);//�۰���ҷ��㷨
int IndexSearch(indexElem index[], int n, int R[], int k);//�ֿ���ҷ��㷨
BTNode * BSTSearch(BTNode * bt, int key);//�������������ҹؼ��ֵ��㷨
int BSTInsert(BTNode * &bt, int key);//��������������ؼ��ֵ��㷨
void CreateBST(BTNode * &bt, int key[], int n);//�����������Ĺ����㷨
int DeleteBST(BTNode * &bt, int key);//����������ɾ���ؼ��ֵ��㷨
int InsertAVL(BTNode * &bt, int key, bool &taller);//ƽ���������������ؼ��ֵ��㷨
int CreateAVL(BTNode * &bt, int key[], int n, bool &taller);//ƽ������������Ĺ����㷨