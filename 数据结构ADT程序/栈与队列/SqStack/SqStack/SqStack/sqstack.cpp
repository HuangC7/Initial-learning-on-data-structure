#include "sqstack.h"

void InitStack(SqStack &st) {
	st.top = -1;
}

void ClearStack(SqStack &st) {
	st.top = -1;
}

bool IsEmpty(SqStack st) {
	if (st.top == -1)
		return true;
	else
		return false;
}

bool IsFull(SqStack st) {
	if(st.top == MAXSIZE - 1)
		return true;
	else
	    return false;
}

bool Push(SqStack &st, ElemType x) {
	if (IsFull(st))
		return false;
	++(st.top);
	st.data[st.top] = x;
	return true;
}

bool Pop(SqStack &st, ElemType &x) {
	if (IsEmpty(st))
		return false;
	x = st.data[st.top];
	--(st.top);
	return true;
}

bool GetTop(SqStack st, ElemType &x) {
	if (IsEmpty(st))
		return false;
	x = st.data[st.top];
	return true;
}