#include "dlinklist.h"
int main(void)
{
	DLNode * L;
	int n;
	ElemType data[MAXSIZE];

	InitDLinklist(L);
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
		CreateDLinklist(L, data, n);
		PrintDLinklist(L);
	}

	return 0;
}