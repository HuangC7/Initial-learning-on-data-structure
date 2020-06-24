#include "linklist.h"
void PrintLinklist(Node * linklist) {
	Node *p;
	p = linklist->next;
	if (p == NULL) {
		printf("链表为空！\n");
	}else {
		printf("链表为：");
		while (p) {
				printf("%d ", p->data);
				p = p->next;
			}
			printf("\n");
	}
	
}

void InitLinklist(Node * &linklist) {
	linklist = (Node *)malloc(sizeof(Node));
	linklist->next = NULL;
}

void CreatLinklist(Node * &linklist, ElemType a[], int n) {
	Node *s, *r;
	int i;

	r = linklist;
	for (i = 0; i < n; ++i) {
		s = (Node*)malloc(sizeof(Node));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

int Locate(Node * linklist, ElemType e) {
	Node * p;
	ElemType i = 0;
	p = linklist;

	while(p){
		if (p->data == e) {
			return i;
		}
		p = p->next;
		i++;
	}
	return -1;
}

ElemType GetData(Node * linklist, int i) {
	int j = 0;
	Node * p;

	p = linklist;
	while(p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return -1;
	}
	else {
		return p->data;
	}
}
	
void InsLinklist(Node * &linklist, int i, ElemType e) {
	Node *p, *s;
	int j = 1;

	InitLinklist(s);
	s->data = e;
	p = linklist;
	while (p != NULL && j < i) {
		p = p->next;
		++j;
	}
	if (p == NULL) {
		printf("插入位置非法！\n");
		return;
	}
	else {
		s->next = p->next;
		p->next = s;
	}
}

ElemType DelLinklist(Node * &linklist, int i, ElemType &e) {
	Node *p, *q, *s;
	int j = 1;

	InitLinklist(q);
	p = linklist;
	while (p != NULL && j < i) {
		p = p->next;
		++j;
	}
	if (p == NULL) {
		return false;
	}else {
		q = p->next;
		p->next = p->next->next;
		e = q->data;
		free(q);
		return e;
	}
}

void MergeLinklist(Node * A, Node * B, Node * &C) {
	Node *p, *q, *s;

	p = A->next;
	q = B->next;
	C = A;
	C->next = NULL;
	free(B);
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		}else {
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	while (p != NULL) {
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL) {
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
}

int LinklistLength(Node * linklist) {
	Node *p;
	int i = 0;

	p = linklist->next;

	while (p) {
		i++;
		p = p->next;
	}

	return i;
}

void DestroyLinklist(Node * &linklist) {
	if (linklist)
		free(linklist);
	else
		printf("销毁失败");
	exit(-1);
}

void ClearLinklist(Node * &linklist)
{
	linklist->next = NULL;
}

bool EmptyLinklist(Node * linklist) {
	if (linklist->next)
		return true;
	else
		return false;
}