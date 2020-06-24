#include "trimat.h"

void createtrimat(ElemType A[][maxSize], int m, int n, Trimat B[]) {
	int k = 1;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			if (A[i][j] != 0) {
				B[k].val = A[i][j];
				B[k].i = i;
				B[k].j = j;
				++k;
			}
		B[0].val = k - 1;
		B[0].i= m;
		B[0].j = n;
	}
}
void print(Trimat B[]) {
	int k = 1;
	cout << "¸Ã¾ØÕóÎª£º" << endl;
	for (int i = 0; i < B[0].i; ++i) {
		for (int j = 0; j < B[0].j; ++j) {
			if (i == (int)B[k].i && j == (int)B[k].j) {
				cout << B[k].val << " ";
				++k;
			}else
				cout << "0 ";
		}
		cout << endl;
	}
}
//¾ØÕóµ¹ÖÃ
void trstrimat(Trimat A[], Trimat B[]) {
	int i, j, k;

	B[0].i = A[0].j; B[0].j = A[0].i; B[0].val = A[0].val;
	if (B[0].val > 0) {
		j = 1;
		for (k = 0; k <= A[0].j; ++k) 
			for (i = 1; i <= A[0].val; ++i) 
				if (A[i].j == k) {
					B[j].i = A[i].j;
					B[j].j = A[i].i;
					B[j].val = A[i].val;
					++j;
				}
	}
}
//¾ØÕó¿ìËÙµ¹ÖÃ
void fasttrstrimat(Trimat A[], Trimat B[]) {
	int col, t, p, q;
	int num[maxSize], pos[maxSize];

	B[0].i = A[0].j; B[0].j = A[0].i; B[0].val = A[0].val;
	if (B[0].val) {
		for (col = 1; col <= A[0].j; ++col)
			num[col] = 0;
		for (t = 1; t <= A[0].val; ++t)
			++num[A[t].j + 1];
		pos[1] = 1;
		for (col = 2; col <= A[0].j; ++col)
			pos[col] = pos[col-1] + num[col-1];
		for (p = 1; p <= A[0].val; ++p) {
			col = A[p].j + 1;
			q = pos[col];
			B[q].i = A[p].j;
			B[q].j = A[p].i;
			B[q].val = A[p].val;
			++pos[col];
		}
	}
}
//¾ØÕóÏà¼Ó
void addtrimat(Trimat C[], Trimat A[], Trimat B[]) {
	int i = 1, j = 1, k = 1, m;
	while(i <= A[0].val && j <= B[0].val)
		if (A[i].i == B[j].i) {
			if (A[i].j < B[j].j) {
				C[k].val = A[i].val;
				C[k].i = A[i].i;
				C[k].j = A[i].j;
				++k;
				++i;
			}
			else if (A[i].j > B[j].j) {
				C[k].val = B[j].val;
				C[k].i = B[j].i;
				C[k].j = B[j].j;
				++k;
				++j;
			}
			else {
				m = A[i].val + B[j].val;
				if (m != 0) {
					C[k].i = B[j].i;
					C[k].j = B[j].j;
					C[k].val = m;
					++k;
				}
				++i;
				++j;
			}
		}else if (A[i].i < B[j].i) {
			C[k].val = A[i].val;
			C[k].i = A[i].i;
			C[k].j = A[i].j;
			++k;
			++i;
		}else {
			C[k].val = B[j].val;
			C[k].i = B[j].i;
			C[k].j = B[j].j;
			++k;
			++j;
		}
		while (i <= A[0].val) {
			C[k].val = A[i].val;
			C[k].i = A[i].i;
			C[k].j = A[i].j;
			++k;
			++i;
		}
		while (j <= B[0].val) {
			C[k].val = B[j].val;
			C[k].i = B[j].i;
			C[k].j = B[j].j;
			++k;
			++j;
		}
		C[0].val = k - 1;
		C[0].i = A[0].i;
		C[0].j = A[0].j;
}
int getvalue(Trimat D[], int i, int j) {
	int k = 1;
	while (k <= D[0].val && (D[k].i != i || D[k].j != j))
		k++;
	if (k <= D[0].val)
		return D[k].val;
	else
		return 0;
}
//¾ØÕóÏà³Ë
void muttrimat(Trimat C[], Trimat A[], Trimat B[], int m, int n, int k) {
	int i, j, l, p = 1, s;
	for (i = 0; i < m; ++i)
		for (j = 0; j < k; ++j) {
			s = 0;
			for (l = 0; l < n; ++l)
				s += getvalue(A, i, l) * getvalue(B, l, j);
			if (s != 0) {
				C[p].i = i;
				C[p].j = j;
				C[p].val = s;
				++p;
			}
		}
	C[0].i = m;
	C[0].j = k;
	C[0].val = p - 1;
}