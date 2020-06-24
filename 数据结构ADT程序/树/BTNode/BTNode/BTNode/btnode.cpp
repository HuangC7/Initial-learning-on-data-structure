#include "btnode.h"
//遍历需要的访问函数
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
//先序遍历
void preorder(BTNode * bt) {
	if (bt != NULL) {
		Visit(bt);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}
//中序遍历
void inorder(BTNode * bt) {
	if (bt != NULL) {
		inorder(bt->lchild);
		Visit(bt);
		inorder(bt->rchild);
	}
}
//后序遍历
void postorder(BTNode * bt){
	if (bt != NULL) {
		postorder(bt->lchild);
		postorder(bt->rchild);
		Visit(bt);
	}
}
//层次遍历
void level(BTNode * bt) {
	int front, rear;
	BTNode * que[maxSize];//定义一个循环队列，用来记录将要访问的层次上的结点
	front = rear = 0;
	BTNode * q;
	if (bt != NULL) {
		rear = (rear + 1) % maxSize;
		que[rear] = bt;//根结点入队
		while (front != rear) {//当列队不为空的时候进行循环
			front = (front + 1) % maxSize;
			q = que[front];//队头结点出队
			Visit(q);//访问队头结点
			if (q->lchild != NULL) {//如果左子树不空，则左子树的根结点入队
				rear = (rear + 1) % maxSize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {//如果右子树不空，则右子树的根结点入队
				rear = (rear + 1) % maxSize;
				que[rear] = q->rchild;
			}
		}
	}
}
//先序遍历非递归算法
void preorderNonrecursion(BTNode * bt) {
	if (bt != NULL) {
		BTNode * Stack[maxSize];//定义一个栈
		int top = -1;
		BTNode * p;
		Stack[++top] = bt;//根结点入栈
		while (top != -1) {//栈空循环退出，遍历结束
			p = Stack[top--];//出栈并输出栈顶元素
			Visit(p);//Visit函数访问p的函数
			if(p->rchild != NULL)//栈顶元素的右孩子存在，则右孩子入栈
				Stack[++top] = p->rchild;
			if(p->lchild != NULL)//栈顶元素的左孩子存在，则左孩子入栈
				Stack[++top] = p->lchild;
		}
	}
}
//中序遍历非递归算法
void inorderNonrecursion(BTNode * bt) {
	if (bt != NULL) {
		BTNode * Stack[maxSize]; int top = -1;
		BTNode * p;
		p = bt;
		while (top != -1 || p != NULL) {
			while (p != NULL) {//左孩子存在，则左孩子入栈
				Stack[++top] = p;
				p = p->lchild;
			}
			if (top != -1) {//在栈不空的情况下出栈并输出栈结点
				p = Stack[top--];
				Visit(p);//Visit()是访问p的函数，在这里执行打印结点值的操作
				p = p->rchild;
			}
		}
	}
}
//后序遍历非递归算法
void postorderNonrecursion(BTNode * bt) {
	if (bt != NULL) {
		/* 定义两个栈 */
		BTNode * Stack1[maxSize]; int top1 = -1;
		BTNode * Stack2[maxSize]; int top2 = -1;
		BTNode * p = NULL;
		Stack1[++top1] = bt;
		while (top1 != -1) {
			p = Stack1[top1--];
			Stack2[++top2] = p;//注意这里和先序遍历的区别，输出改为入Stack2
			/* 注意下边这两个if语句和先序遍历的区别，左，右孩子的入栈顺序相反 */
			if (p->lchild != NULL)
				Stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				Stack1[++top1] = p->rchild;
		}
		while (top2 != -1) {
			/* 出栈序列即为后序遍历序列 */
			p = Stack2[top2--];
			Visit(p);//Visit()是访问p的函数，在这里执行打印结点值的操作
		}
	}
}
void ClearBTNode(BTNode * &bt) {
	ClearBTNode(bt->lchild);
	ClearBTNode(bt->rchild);
	free(bt);
}