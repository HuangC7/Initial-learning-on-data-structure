#include "dlinklist.h"

void InitDLinklist(DLNode * &L) {
	L = (DLNode *)malloc(sizeof(DLNode));
	L->next = NULL;
	L->prior = NULL;
}

void CreateDLinklist(DLNode * &L, ElemType a[], int n) {
	DLNode *s, *r;
	int i;

	r = L;
	for (i = 0; i < n; ++i) {
		s = (DLNode *)malloc(sizeof(DLNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

void PrintDLinklist(DLNode * L) {
	DLNode *p = L->next;

	if (p == NULL) {
		printf("链表为空！\n");
	}
	else {
		printf("链表为：");
		while (p) {
			printf("%d ", p->data);
			p = p->next;
		}
		printf("\n");
	}
}