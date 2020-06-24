#include "tbtnode.h"
void Visit(TBTNode * bt) {
	cout << bt->data << " ";
}
void InThread(TBTNode * p, TBTNode * &pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);//�ݹ飬������������
		if (p->lchild == NULL) {//������ǰ����ǰ������
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && p->rchild == NULL) {//����ǰ����ĺ�������
			pre->rchild = p;
			p->rtag = 1;
		}
		pre = p;//preָ��ǰ��p����Ϊp��Ҫָ�����һ������ǰ�����ָʾָ��
		p = p->rchild;//pָ��һ���½�㣬��ʱpre��p�ֱ�ָ��Ľ���γ���һ��ǰ����̶�
						//Ϊ��һ��������������׼��
		InThread(p, pre);//�ݹ飬������������
	}
}
void createInThread(TBTNode * root) {
	TBTNode * pre = NULL;//ǰ�����ָ��
	if (root != NULL) {
		InThread(root, pre);
		pre->rchild = NULL;//�ǿն�������������
		pre->rtag = 1;//�����������һ�����
	}

}
TBTNode * First(TBTNode * p) {
	while (p->ltag == 0)
		p = p->lchild;//�����½�㣨��һ����Ҷ��㣩
	return p;
}
TBTNode * Next(TBTNode * p) {
	if (p->rtag == 0)
		return First(p->rchild);
	else
		return p->rchild;//rtag == 1,ֱ�ӷ��غ������
}
void Inorder(TBTNode * root) {
	for (TBTNode * p = First(root); p != NULL; p = Next(p))
		Visit(p);//Visit()���Ѿ�����ķ���p��ָ���ĺ���
}
void preThread(TBTNode * p, TBTNode * &pre) {
	if (p != NULL) {
		if (p->lchild == NULL) {
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && p->rchild == NULL) {
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		/* ע�⣬�����ڵݹ���ڴ�����������������ָ�벻���������ܼ����ݹ� */
		if (p->ltag == 0)
			preThread(p->lchild, pre);
		if (p->rtag == 0)
			preThread(p->rchild, pre);
	}
}
void preorder(TBTNode * root) {
	if (root != NULL) {
		TBTNode * p = root;
		while (p != NULL) {
			while (p->ltag == 0) {//��ָ�벻����������߷��ʱ�����
				Visit(p);
				p = p->lchild;
			}
			Visit(p);//��ʱp��ָ���Ϊ����������û�б����ʣ������
			p = p->rchild;//��ʱp���Ӳ����ڣ�����ָ�����ǿգ�
							//�����Ƿ�Ϊ������ָ������
		}
	}
}
void postThread(TBTNode * p, TBTNode * &pre) {
	if (p != NULL) {
		postThread(p->lchild, pre);//�ݹ飬������������
		postThread(p->rchild, pre);//�ݹ飬������������
		if (p->lchild == NULL) {//������ǰ����ǰ�����
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && p->rchild == NULL) {//����ǰ�����ĺ�̽��
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
	}
}