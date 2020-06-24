#include "dlinklist.h"
int main(void)
{
	DLNode * L;
	int n;
	ElemType data[MAXSIZE];

	InitDLinklist(L);
	printf("请输入数据元素的个数n=");
	cin >> n;
	if (n <= 0) {
		printf("输入个数不合法，请重新输入！\n");
	}
	else {
		printf("\n请输入%d个数据元素：", n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		CreateDLinklist(L, data, n);
		PrintDLinklist(L);
	}

	return 0;
}