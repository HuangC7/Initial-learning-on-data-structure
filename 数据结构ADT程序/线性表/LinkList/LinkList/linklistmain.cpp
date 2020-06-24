#include "linklist.h"
int main(void) {
	Node *Linklist = NULL;
	Node *A, *B, *C;
	int choice;
	ElemType data[MAXSIZE] = { 0 };
	ElemType e = 0;
	int n;
	int i;
	int no;

	while (1) {
		printf("...........................................\n");
		printf("1.��ʼ��������������1��\n");
		printf("2.����������������2��\n");
		printf("3.��ֵ���ҵ�����������3��\n");
		printf("4.��λ���ҵ�����������4��\n");
		printf("5.���뵥������һ������Ԫ�أ�������5��\n");
		printf("6.ɾ����������һ������Ԫ�أ�������6��\n");
		printf("7.�ϲ�����������������7��\n");
		printf("8.��ѯ������ĳ��ȣ�������8��\n");
		printf("9.���ٵ�����������9��\n");
		printf("10��յ�����������10��\n");
		printf("11.ȷ���������Ƿ�Ϊ��11��\n");
		printf("12.�ټ���������12��\n");
		printf("������������(1---12)��");
		scanf("%d", &choice);
		switch (choice) {
			case 1: {
				InitLinklist(Linklist);
				break;
			}
			case 2: {
				printf("����������Ԫ�صĸ���n=");
				scanf("%d", &n);
				if (n <= 0) {
					printf("����������Ϸ������������룡\n");
				}
				else {
					printf("\n������%d������Ԫ�أ�", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &data[i]);
					}
					CreatLinklist(Linklist, data, n);
					PrintLinklist(Linklist);
				}
				break;
			}
			case 3: {
				printf("������Ҫ���ҵ�����Ԫ��ֵ��");
				scanf("%d", &e);
				no = Locate(Linklist, e);
				if (no == -1) {
					printf("\nû���������Ԫ�ء�\n");
				}
				else {
					printf("����Ԫ�أ�%d�ڵ������е�%dλ\n", e, no);
				}
				break;
			}
			case 4: {
				printf("������Ҫ���ҵ�����Ԫ�ص���ţ�");
				scanf("%d", &no);
				if (no <= 0) {
					printf("����λ�÷Ƿ�,����������!\n");
				}
				else {
					e = GetData(Linklist, no);
					if (e == -1) {
						printf("����λ�÷Ƿ�,����������!\n");
					}
					else {
						printf("\n���ҵ�������Ԫ��ֵ�ǣ�%d\n", e);
					}		
				}	
				break;
			}
			case 5: {
				printf("\n��������Ԫ��ǰ�ĵ�����\n");
				PrintLinklist(Linklist);
				printf("������Ҫ���������Ԫ�ص���ţ�");
				scanf("%d", &no);
				if (no <= 0) {
					printf("����λ�÷Ƿ�,����������!\n");
				}
				else {
					printf("\n������Ҫ���������Ԫ�أ�");
					scanf("%d", &e);
					InsLinklist(Linklist, no, e);
					printf("\n��������Ԫ�غ�ĵ�����:");
					PrintLinklist(Linklist);
				}
				break;
			}
			case 6: {
				printf("\nɾ������Ԫ��ǰ�ĵ�����\n");
				PrintLinklist(Linklist);
				printf("������Ҫɾ��������Ԫ�ص���ţ�");
				scanf("%d", &no);
				if (no <= 0) {
					printf("����λ�÷Ƿ�,����������!\n");
				}else {
					if (DelLinklist(Linklist, no, e)) {
						printf("\nɾ��������Ԫ���ǣ�%d\n", e);
						printf("\nɾ������Ԫ�غ�ĵ�����:");
						PrintLinklist(Linklist);
					}else {
						printf("����λ�÷Ƿ���\n");
					}
				}
				break;
			}
			case 7: {
				InitLinklist(A);
				InitLinklist(B);
				InitLinklist(C);
				printf("\n����������A\n");
				printf("����������Ԫ�صĸ���n=:");
				scanf("%d", &n);
				if (n <= 0) {
					printf("����������Ϸ������������룡\n");
					break;
				}
				else {
					printf("\n������%d������Ԫ�أ�", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &data[i]);
					}
					CreatLinklist(A, data, n);
					PrintLinklist(A);
				}
				printf("\n����������B\n");
				printf("����������Ԫ�صĸ���n=:");
				scanf("%d", &n);
				if (n <= 0) {
					printf("����������Ϸ������������룡\n");
					break;
				}
				else {
					printf("\n������%d������Ԫ�أ�", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &data[i]);
					}
					CreatLinklist(B, data, n);
					PrintLinklist(B);
				}
				MergeLinklist(A, B, C);
				PrintLinklist(C);
				break;
			}
			case 8: {
				printf("������ĳ���Ϊ��%d\n", LinklistLength(Linklist));
				break;
			}
			case 9: {
				DestroyLinklist(Linklist);
				break;
			}
			case 10: {
				ClearLinklist(Linklist);
				break;
			}
			case 11: {
				if (EmptyLinklist(Linklist)) {
					printf("������Ϊ�ա�\n");
				}
				else
					printf("������Ϊ�ա�\n");
				break;
			}
			case 12: {
				exit(-1);
			}
			default: {
				printf("\n������Ĳ����������\n");
			}
		}
	}
	return 0;
}