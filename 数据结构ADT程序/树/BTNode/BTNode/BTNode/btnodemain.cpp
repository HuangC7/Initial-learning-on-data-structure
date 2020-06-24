#include "btnode.h"
int main(void)
{
	BTNode * bt;
	ElemType x;
	InitBTNode(bt);
	CreateBTNode(bt);
	cout << "先序遍历是：";
	preorder(bt);
	cout << endl;
	cout << "中序遍历是：";
	inorder(bt);
	cout << endl;
	cout << "后序序遍历是：";
	postorder(bt);
	cout << endl;
	x = Parent(bt, 'a')->data;
	cout << "x的双亲结点是：" << x << endl;
	x = LeftChild(bt, 'b')->data;
	cout << "x的左孩子结点是：" << x << endl;
	x = RightChild(bt, 'b')->data;
	cout << "x的右孩子结点是：" << x << endl;
	return 0;
}