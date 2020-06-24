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
		printf("1.初始化顺序表，请输入1：\n");
		printf("2.建立顺序表，请输入2：\n");
		printf("3.按值查找顺序表，请输入3：\n");
		printf("4.按位查找顺序表，请输入4：\n");
		printf("5.插入顺序表内一个数据元素，请输入5：\n");
		printf("6.删除顺序表内一个数据元素，请输入6：\n");
		printf("7.合并二个顺序表，请输入7：\n");
		printf("8.查询顺序表的长度，请输入8：\n");
		printf("9.销毁顺序表，请输入9：\n");
		printf("10.清空顺序表，请输入10：\n");
		printf("11.确定顺序表是否为空11：\n");
		printf("12.删除介于a-b之间的所有元素12：\n");
		printf("13.将顺序表奇数元素排在前，偶数元素排在后13：\n");
		printf("14.删除非递减顺序表所有相同多余的元素14（要求顺序表非递减排列！）：\n");
		printf("15.再见，请输入12：\n");

		printf("...........................................\n");
		printf("请输入操作序号(1---15)：");
		scanf("%d", &nub);
		switch (nub) {
		case 1: {
			InitSeqlist(list);
			break;
		}
		case 2: {
			printf("请输入数据元素的个数n=:");
			scanf("%d", &n);
			printf("\n请输入%d个数据元素：", n);
			for (i = 0; i < n; i++) {
				scanf("%d", &data[i]);
			}
			CreateSeqlist(list, data, n);
			PrintSeqlist(list);
			break;
		}
		case 3: {
			printf("请输入要查找的数据元素值：");
			scanf("%d", &e);
			no = Locate(list, e);
			if (no == -1) {
				printf("\n没有这个数据元素。\n");
			}
			else {
				printf("数据元素：%d在顺序表中第%d位\n", e, no);
			}
			break;
		}
		case 4: {
			printf("请输入要查找的数据元素的序号：");
			scanf("%d", &no);
			e = GetData(list, no);
			printf("\n查找到的数据元素值是：%d\n", e);
			break;
		}
		case 5: {
			printf("\n插入数据元素前的顺序表：\n");
			PrintSeqlist(list);
			printf("请输入要插入的数据元素的序号：");
			scanf("%d", &no);
			printf("\n请输入要插入的数据元素：");
			scanf("%d", &e);
			InsSeqlist(list, no, e);
			printf("\n插入数据元素后的顺序表：\n");
			PrintSeqlist(list);
			break;
		}
		case 6: {
			printf("\n删除数据元素前的顺序表：\n");
			PrintSeqlist(list);
			printf("请输入要删除的数据元素的序号：");
			scanf("%d", &no);
			if (DelSeqlist(list, no, e)) {
				printf("\n删除的数据元素是：%d\n", e);
				printf("\n删除数据元素后的顺序表：\n");
				PrintSeqlist(list);
			}
			break;
		}
		case 7: {
			InitSeqlist(la);
			InitSeqlist(lb);
			InitSeqlist(lc);
			printf("\n建立顺序表LA\n");
			printf("请输入数据元素的个数n=:");
			scanf("%d", &n);
			printf("\n请输入%d个数据元素：", n);
			for (i = 0; i < n; i++) {
				scanf("%d", &data[i]);
			}
			CreateSeqlist(la, data, n);
			PrintSeqlist(la);

			printf("\n建立顺序表LB\n");
			printf("请输入数据元素的个数n=:");
			scanf("%d", &n);
			printf("\n请输入%d个数据元素：", n);
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
			printf("顺序表的长度为：%d\n", ListLength(list));
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
				printf("顺序表为空。\n");
			}
			else
				printf("顺序表不为空。\n");
			break;
		}
		case 12: {
			printf("请输入要删除的范围（a-b）：");
			scanf("%d%d", &a, &b);
			if (a >= b)
				printf("输入有误！");
			else
				Delxtoy(list, a, b);
				printf("删除后的顺序表为：");
				PrintSeqlist(list);
			break;
		}
		case 13: {
			printf("排序后的顺序表为：");
			Paixu(list);
			PrintSeqlist(list);
			break;
		}
		case 14: {
			printf("删除多余元素后的顺序表为：");
			Delequal(list);
			PrintSeqlist(list);
			break;
		}
		case 15: {
			exit(-1);
		}
		default: {
			printf("\n您输入的操作序号有误。\n");
		}
		}
	}
	return 0;
}