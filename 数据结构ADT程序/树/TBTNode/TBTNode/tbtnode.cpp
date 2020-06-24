#include "tbtnode.h"
void Visit(TBTNode * bt) {
	cout << bt->data << " ";
}
void InThread(TBTNode * p, TBTNode * &pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);//递归，左子树线索化
		if (p->lchild == NULL) {//建立当前结点的前驱线索
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && p->rchild == NULL) {//建立前序结点的后序线索
			pre->rchild = p;
			p->rtag = 1;
		}
		pre = p;//pre指向当前的p，作为p将要指向的下一个结点的前驱结点指示指针
		p = p->rchild;//p指向一个新结点，此时pre和p分别指向的结点形成了一个前驱后继对
						//为下一次线索的连接做准备
		InThread(p, pre);//递归，右子树线索化
	}
}
void createInThread(TBTNode * root) {
	TBTNode * pre = NULL;//前驱结点指针
	if (root != NULL) {
		InThread(root, pre);
		pre->rchild = NULL;//非空二叉树，线索化
		pre->rtag = 1;//后处理中序最后一个结点
	}

}
TBTNode * First(TBTNode * p) {
	while (p->ltag == 0)
		p = p->lchild;//最左下结点（不一定是叶结点）
	return p;
}
TBTNode * Next(TBTNode * p) {
	if (p->rtag == 0)
		return First(p->rchild);
	else
		return p->rchild;//rtag == 1,直接返回后继线索
}
void Inorder(TBTNode * root) {
	for (TBTNode * p = First(root); p != NULL; p = Next(p))
		Visit(p);//Visit()是已经定义的访问p所指结点的函数
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
		/* 注意，这里在递归入口处有限制条件，左、右指针不是线索才能继续递归 */
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
			while (p->ltag == 0) {//左指针不是线索，则边访问边左移
				Visit(p);
				p = p->lchild;
			}
			Visit(p);//此时p左指针必为线索，但还没有被访问，则访问
			p = p->rchild;//此时p左孩子不存在，则右指针若非空，
							//则不论是否为线索都指向其后继
		}
	}
}
void postThread(TBTNode * p, TBTNode * &pre) {
	if (p != NULL) {
		postThread(p->lchild, pre);//递归，左子树线索化
		postThread(p->rchild, pre);//递归，右子树线索化
		if (p->lchild == NULL) {//建立当前结点的前驱结点
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && p->rchild == NULL) {//建立前驱结点的后继结点
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
	}
}