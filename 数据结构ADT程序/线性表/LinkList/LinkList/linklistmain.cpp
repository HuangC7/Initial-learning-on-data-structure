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
		printf("1.初始化单链表，请输入1：\n");
		printf("2.建立单链表，请输入2：\n");
		printf("3.按值查找单链表，请输入3：\n");
		printf("4.按位查找单链表，请输入4：\n");
		printf("5.插入单链表内一个数据元素，请输入5：\n");
		printf("6.删除单链表内一个数据元素，请输入6：\n");
		printf("7.合并二个单链表，请输入7：\n");
		printf("8.查询单链表的长度，请输入8：\n");
		printf("9.销毁单链表，请输入9：\n");
		printf("10清空单链表，请输入10：\n");
		printf("11.确定单链表是否为空11：\n");
		printf("12.再见，请输入12：\n");
		printf("请输入操作序号(1---12)：");
		scanf("%d", &choice);
		switch (choice) {
			case 1: {
				InitLinklist(Linklist);
				break;
			}
			case 2: {
				printf("请输入数据元素的个数n=");
				scanf("%d", &n);
				if (n <= 0) {
					printf("输入个数不合法，请重新输入！\n");
				}
				else {
					printf("\n请输入%d个数据元素：", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &data[i]);
					}
					CreatLinklist(Linklist, data, n);
					PrintLinklist(Linklist);
				}
				break;
			}
			case 3: {
				printf("请输入要查找的数据元素值：");
				scanf("%d", &e);
				no = Locate(Linklist, e);
				if (no == -1) {
					printf("\n没有这个数据元素。\n");
				}
				else {
					printf("数据元素：%d在单链表中第%d位\n", e, no);
				}
				break;
			}
			case 4: {
				printf("请输入要查找的数据元素的序号：");
				scanf("%d", &no);
				if (no <= 0) {
					printf("查找位置非法,请重新输入!\n");
				}
				else {
					e = GetData(Linklist, no);
					if (e == -1) {
						printf("查找位置非法,请重新输入!\n");
					}
					else {
						printf("\n查找到的数据元素值是：%d\n", e);
					}		
				}	
				break;
			}
			case 5: {
				printf("\n插入数据元素前的单链表：\n");
				PrintLinklist(Linklist);
				printf("请输入要插入的数据元素的序号：");
				scanf("%d", &no);
				if (no <= 0) {
					printf("插入位置非法,请重新输入!\n");
				}
				else {
					printf("\n请输入要插入的数据元素：");
					scanf("%d", &e);
					InsLinklist(Linklist, no, e);
					printf("\n插入数据元素后的单链表:");
					PrintLinklist(Linklist);
				}
				break;
			}
			case 6: {
				printf("\n删除数据元素前的单链表：\n");
				PrintLinklist(Linklist);
				printf("请输入要删除的数据元素的序号：");
				scanf("%d", &no);
				if (no <= 0) {
					printf("插入位置非法,请重新输入!\n");
				}else {
					if (DelLinklist(Linklist, no, e)) {
						printf("\n删除的数据元素是：%d\n", e);
						printf("\n删除数据元素后的单链表:");
						PrintLinklist(Linklist);
					}else {
						printf("插入位置非法！\n");
					}
				}
				break;
			}
			case 7: {
				InitLinklist(A);
				InitLinklist(B);
				InitLinklist(C);
				printf("\n建立单链表A\n");
				printf("请输入数据元素的个数n=:");
				scanf("%d", &n);
				if (n <= 0) {
					printf("输入个数不合法，请重新输入！\n");
					break;
				}
				else {
					printf("\n请输入%d个数据元素：", n);
					for (i = 0; i < n; i++) {
						scanf("%d", &data[i]);
					}
					CreatLinklist(A, data, n);
					PrintLinklist(A);
				}
				printf("\n建立单链表B\n");
				printf("请输入数据元素的个数n=:");
				scanf("%d", &n);
				if (n <= 0) {
					printf("输入个数不合法，请重新输入！\n");
					break;
				}
				else {
					printf("\n请输入%d个数据元素：", n);
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
				printf("单链表的长度为：%d\n", LinklistLength(Linklist));
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
					printf("单链表为空。\n");
				}
				else
					printf("单链表不为空。\n");
				break;
			}
			case 12: {
				exit(-1);
			}
			default: {
				printf("\n您输入的操作序号有误。\n");
			}
		}
	}
	return 0;
}