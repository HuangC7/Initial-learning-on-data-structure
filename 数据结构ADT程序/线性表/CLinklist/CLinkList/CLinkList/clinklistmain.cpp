#include "clinklist.h"
int main(void)
{
	CLNode * CL;
	int n;
	ElemType data[MAXSIZE];

	InitCLinklist(CL);
	printf("����������Ԫ�صĸ���n=");
	cin >> n;
	if (n <= 0) {
		printf("����������Ϸ������������룡\n");
	}
	else {
		printf("\n������%d������Ԫ�أ�", n);
		for (int i = 0; i < n; i++) {
			cin >> data[i];
		}
		CreateCLinklist(CL, data, n);
		PrintCLinklist(CL);
	}

	return 0;
}