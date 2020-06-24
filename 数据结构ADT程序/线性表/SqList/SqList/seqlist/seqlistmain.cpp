#include"seqlist.h"
int main(void) {
	SeqList list;
	int nub;
	int n;
	int i;
	int a, b;
	ElemType data[MAXSIZE] = { 0 };
	ElemType e;
	int no;
	SeqList la, lb, lc;

	while (1) {
		printf("...........................................\n");
		printf("1.��ʼ��˳���������1��\n");
		printf("2.����˳���������2��\n");
		printf("3.��ֵ����˳���������3��\n");
		printf("4.��λ����˳���������4��\n");
		printf("5.����˳�����һ������Ԫ�أ�������5��\n");
		printf("6.ɾ��˳�����һ������Ԫ�أ�������6��\n");
		printf("7.�ϲ�����˳���������7��\n");
		printf("8.��ѯ˳���ĳ��ȣ�������8��\n");
		printf("9.����˳���������9��\n");
		printf("10.���˳���������10��\n");
		printf("11.ȷ��˳����Ƿ�Ϊ��11��\n");
		printf("12.ɾ������a-b֮�������Ԫ��12��\n");
		printf("13.��˳�������Ԫ������ǰ��ż��Ԫ�����ں�13��\n");
		printf("14.ɾ���ǵݼ�˳���������ͬ�����Ԫ��14��Ҫ��˳���ǵݼ����У�����\n");
		printf("15.�ټ���������12��\n");

		printf("...........................................\n");
		printf("������������(1---15)��");
		scanf("%d", &nub);
		switch (nub) {
		case 1: {
			InitSeqlist(list);
			break;
		}
		case 2: {
			printf("����������Ԫ�صĸ���n=:");
			scanf("%d", &n);
			printf("\n������%d������Ԫ�أ�", n);
			for (i = 0; i < n; i++) {
				scanf("%d", &data[i]);
			}
			CreateSeqlist(list, data, n);
			PrintSeqlist(list);
			break;
		}
		case 3: {
			printf("������Ҫ���ҵ�����Ԫ��ֵ��");
			scanf("%d", &e);
			no = Locate(list, e);
			if (no == -1) {
				printf("\nû���������Ԫ�ء�\n");
			}
			else {
				printf("����Ԫ�أ�%d��˳����е�%dλ\n", e, no);
			}
			break;
		}
		case 4: {
			printf("������Ҫ���ҵ�����Ԫ�ص���ţ�");
			scanf("%d", &no);
			e = GetData(list, no);
			printf("\n���ҵ�������Ԫ��ֵ�ǣ�%d\n", e);
			break;
		}
		case 5: {
			printf("\n��������Ԫ��ǰ��˳���\n");
			PrintSeqlist(list);
			printf("������Ҫ���������Ԫ�ص���ţ�");
			scanf("%d", &no);
			printf("\n������Ҫ���������Ԫ�أ�");
			scanf("%d", &e);
			InsSeqlist(list, no, e);
			printf("\n��������Ԫ�غ��˳���\n");
			PrintSeqlist(list);
			break;
		}
		case 6: {
			printf("\nɾ������Ԫ��ǰ��˳���\n");
			PrintSeqlist(list);
			printf("������Ҫɾ��������Ԫ�ص���ţ�");
			scanf("%d", &no);
			if (DelSeqlist(list, no, e)) {
				printf("\nɾ��������Ԫ���ǣ�%d\n", e);
				printf("\nɾ������Ԫ�غ��˳���\n");
				PrintSeqlist(list);
			}
			break;
		}
		case 7: {
			InitSeqlist(la);
			InitSeqlist(lb);
			InitSeqlist(lc);
			printf("\n����˳���LA\n");
			printf("����������Ԫ�صĸ���n=:");
			scanf("%d", &n);
			printf("\n������%d������Ԫ�أ�", n);
			for (i = 0; i < n; i++) {
				scanf("%d", &data[i]);
			}
			CreateSeqlist(la, data, n);
			PrintSeqlist(la);

			printf("\n����˳���LB\n");
			printf("����������Ԫ�صĸ���n=:");
			scanf("%d", &n);
			printf("\n������%d������Ԫ�أ�", n);
			for (i = 0; i < n; i++) {
				scanf("%d", &data[i]);
			}
			CreateSeqlist(lb, data, n);
			PrintSeqlist(lb);

			Merge2Seqlist(la, lb, lc);
			PrintSeqlist(lc);
			break;
		}
		case 8: {
			printf("˳���ĳ���Ϊ��%d\n", ListLength(list));
			break;
		}
		case 9: {
			DestroyList(list);
			break;
		}
		case 10: {
			ClearList(list);
			break;
		}
		case 11: {
			if (EmptyList(list)) {
				printf("˳���Ϊ�ա�\n");
			}
			else
				printf("˳���Ϊ�ա�\n");
			break;
		}
		case 12: {
			printf("������Ҫɾ���ķ�Χ��a-b����");
			scanf("%d%d", &a, &b);
			if (a >= b)
				printf("��������");
			else
				Delxtoy(list, a, b);
				printf("ɾ�����˳���Ϊ��");
				PrintSeqlist(list);
			break;
		}
		case 13: {
			printf("������˳���Ϊ��");
			Paixu(list);
			PrintSeqlist(list);
			break;
		}
		case 14: {
			printf("ɾ������Ԫ�غ��˳���Ϊ��");
			Delequal(list);
			PrintSeqlist(list);
			break;
		}
		case 15: {
			exit(-1);
		}
		default: {
			printf("\n������Ĳ����������\n");
		}
		}
	}
	return 0;
}