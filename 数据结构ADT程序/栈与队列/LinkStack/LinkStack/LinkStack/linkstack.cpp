#include "linkstack.h"

void InitStack(LNode * &lst) {
	lst = (LNode *)malloc(sizeof(LNode));
	lst->next = NULL;
}

void ClearStack(LNode * &lst) {
	free(lst);
	lst->next = NULL;	
}

bool IsEmpty(LNode * lst) {
	if (lst->next == NULL)
		return true;
	else
		return false;
}

bool IsFull(LNode * lst) {
	int n = 0;
	while (lst->next != NULL) {
		lst = lst->next;
		++n;
	}
	if (n > MAXSIZE)
		return true;
	else
		return false;
		

}

bool Push(LNode * lst, ElemType x) {
	LNode *p;
	InitStack(p);
	if (p == NULL)
		return false;
	p->data = x;
	p->next = lst->next;
	lst->next = p;
	return true;
}

bool Pop(LNode * lst, ElemType &x) {
	LNode *p;
	if (lst->next == NULL)
		return false;
	p = lst->next;
	x = p->data;
	lst->next = p->next;
	free(p);
	return true;

}

bool GetTop(LNode * lst, ElemType &x) {
	if (IsEmpty(lst))
		return false;
	while (lst->next != NULL)
		lst = lst->next;
	x = lst->data;
	return true;
}