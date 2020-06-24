#include "btnode.h"
//������Ҫ�ķ��ʺ���
void Visit(BTNode * bt) {
	cout << bt->data << " ";
}
void InitBTNode(BTNode * &bt) {
	bt = NULL;
}
void CreateBTNode(BTNode * &bt) {
	char ch;
	cin >> ch;
	if (ch == '#')
		bt = NULL;
	else {
		bt = (BTNode *)malloc(sizeof(BTNode));
		bt->data = ch;
		CreateBTNode(bt->lchild);
		CreateBTNode(bt->rchild);
	}
}
void DestoryBTNode(BTNode * &bt) {
	if (bt != NULL) {
		if (bt->lchild != NULL) DestoryBTNode(bt->lchild);
		if (bt->rchild != NULL) DestoryBTNode(bt->rchild);
		free(bt);
		bt = NULL;
	}
}
int EmpytBTNode(BTNode * bt) {
	if (bt == NULL) return 1;
	else return 0;
}
ElemType Root(BTNode * bt) {
	if(bt != NULL) return bt->data;
	else return false;
}
BTNode * Parent(BTNode * bt, ElemType x) {
	if (bt->data == x) return NULL;
	BTNode * t;
	if (bt == NULL) return NULL;
	if (bt->lchild != NULL) 
		if (bt->lchild->data == x) return bt;
	if (bt->rchild != NULL)
		if (bt->rchild->data == x) return bt;
	t = Parent(bt->lchild, x);
	if (t != NULL) return t;
	t = Parent(bt->rchild, x);
	return t;
}
BTNode * LeftChild(BTNode * bt, ElemType x) {
	BTNode * t;
	if (bt == NULL) return NULL;
	if(bt != NULL)
		if (bt->data == x) return bt->lchild;
	t = LeftChild(bt->lchild, x);
	if (t != NULL) return t;
	t = LeftChild(bt->rchild, x);
	return t;
}
BTNode * RightChild(BTNode * bt, ElemType x) {
	BTNode * t;
	if (bt == NULL) return NULL;
	if (bt != NULL)
		if (bt->data == x) return bt->rchild;
	t = LeftChild(bt->lchild, x);
	if (t != NULL) return t;
	t = LeftChild(bt->rchild, x);
	return t;
}
//�������
void preorder(BTNode * bt) {
	if (bt != NULL) {
		Visit(bt);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
//�������
void inorder(BTNode * bt) {
	if (bt != NULL) {
		inorder(bt->lchild);
		Visit(bt);
		inorder(bt->rchild);
	}
}
//�������
void postorder(BTNode * bt){
	if (bt != NULL) {
		postorder(bt->lchild);
		postorder(bt->rchild);
		Visit(bt);
	}
}
//��α���
void level(BTNode * bt) {
	int front, rear;
	BTNode * que[maxSize];//����һ��ѭ�����У�������¼��Ҫ���ʵĲ���ϵĽ��
	front = rear = 0;
	BTNode * q;
	if (bt != NULL) {
		rear = (rear + 1) % maxSize;
		que[rear] = bt;//��������
		while (front != rear) {//���жӲ�Ϊ�յ�ʱ�����ѭ��
			front = (front + 1) % maxSize;
			q = que[front];//��ͷ������
			Visit(q);//���ʶ�ͷ���
			if (q->lchild != NULL) {//������������գ����������ĸ�������
				rear = (rear + 1) % maxSize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {//������������գ����������ĸ�������
				rear = (rear + 1) % maxSize;
				que[rear] = q->rchild;
			}
		}
	}
}
//��������ǵݹ��㷨
void preorderNonrecursion(BTNode * bt) {
	if (bt != NULL) {
		BTNode * Stack[maxSize];//����һ��ջ
		int top = -1;
		BTNode * p;
		Stack[++top] = bt;//�������ջ
		while (top != -1) {//ջ��ѭ���˳�����������
			p = Stack[top--];//��ջ�����ջ��Ԫ��
			Visit(p);//Visit��������p�ĺ���
			if(p->rchild != NULL)//ջ��Ԫ�ص��Һ��Ӵ��ڣ����Һ�����ջ
				Stack[++top] = p->rchild;
			if(p->lchild != NULL)//ջ��Ԫ�ص����Ӵ��ڣ���������ջ
				Stack[++top] = p->lchild;
		}
	}
}
//��������ǵݹ��㷨
void inorderNonrecursion(BTNode * bt) {
	if (bt != NULL) {
		BTNode * Stack[maxSize]; int top = -1;
		BTNode * p;
		p = bt;
		while (top != -1 || p != NULL) {
			while (p != NULL) {//���Ӵ��ڣ���������ջ
				Stack[++top] = p;
				p = p->lchild;
			}
			if (top != -1) {//��ջ���յ�����³�ջ�����ջ���
				p = Stack[top--];
				Visit(p);//Visit()�Ƿ���p�ĺ�����������ִ�д�ӡ���ֵ�Ĳ���
				p = p->rchild;
			}
		}
	}
}
//��������ǵݹ��㷨
void postorderNonrecursion(BTNode * bt) {
	if (bt != NULL) {
		/* ��������ջ */
		BTNode * Stack1[maxSize]; int top1 = -1;
		BTNode * Stack2[maxSize]; int top2 = -1;
		BTNode * p = NULL;
		Stack1[++top1] = bt;
		while (top1 != -1) {
			p = Stack1[top1--];
			Stack2[++top2] = p;//ע�������������������������Ϊ��Stack2
			/* ע���±�������if��������������������Һ��ӵ���ջ˳���෴ */
			if (p->lchild != NULL)
				Stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				Stack1[++top1] = p->rchild;
		}
		while (top2 != -1) {
			/* ��ջ���м�Ϊ����������� */
			p = Stack2[top2--];
			Visit(p);//Visit()�Ƿ���p�ĺ�����������ִ�д�ӡ���ֵ�Ĳ���
		}
	}
}
void ClearBTNode(BTNode * &bt) {
	ClearBTNode(bt->lchild);
	ClearBTNode(bt->rchild);
	free(bt);
}