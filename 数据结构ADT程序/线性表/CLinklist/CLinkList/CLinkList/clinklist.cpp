#include "clinklist.h"

void InitCLinklist(CLNode * &CL) {
	CL = (CLNode *)malloc(sizeof(CLNode));
	CL->next = CL;
}

void CreateCLinklist(CLNode * &CL, ElemType a[], int n) {
	CLNode *s, *r;
	int i;

	r = CL;
	for (i = 0; i < n; i++) {
		s = (CLNode *)malloc(sizeof(CLNode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = CL;
}

void PrintCLinklist(CLNode * CL) {
	CLNode *p = CL->next;

	if (p == CL) {
		printf("链表为空！\n");
	}
	else {
		printf("链表为：");
		while (p != CL) {
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}
}