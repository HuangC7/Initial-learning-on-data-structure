#include "btnode.h"
int main(void)
{
	BTNode * bt;
	ElemType x;
	InitBTNode(bt);
	CreateBTNode(bt);
	cout << "��������ǣ�";
	preorder(bt);
	cout << endl;
	cout << "��������ǣ�";
	inorder(bt);
	cout << endl;
	cout << "����������ǣ�";
	postorder(bt);
	cout << endl;
	x = Parent(bt, 'a')->data;
	cout << "x��˫�׽���ǣ�" << x << endl;
	x = LeftChild(bt, 'b')->data;
	cout << "x�����ӽ���ǣ�" << x << endl;
	x = RightChild(bt, 'b')->data;
	cout << "x���Һ��ӽ���ǣ�" << x << endl;
	return 0;
}