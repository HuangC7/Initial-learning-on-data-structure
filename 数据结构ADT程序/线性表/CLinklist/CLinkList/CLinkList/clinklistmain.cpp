#include "clinklist.h"
int main(void)
{
	CLNode * CL;
	int n;
	ElemType data[MAXSIZE];

	InitCLinklist(CL);
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
		CreateCLinklist(CL, data, n);
		PrintCLinklist(CL);
	}

	return 0;
}