#include "crosslist.h"

int createcrossListmat(ElemType A[][maxSize], int m, int n, int k, CrossList &M) {
	if (M.rhead)
		free(M.rhead);
	if (M.chead)
		free(M.chead);
	M.m = m;
	M.n = n;
	M.k = k;
	if (!(M.chead = (OLNode *)malloc(sizeof(OLNode) * m)))
		return 0;
	if (!(M.rhead = (OLNode *)malloc(sizeof(OLNode) * n)))
		return 0;
	for (int i = 0; i < m; ++i) {
		M.chead[i].right = NULL;
		M.chead[i].down = NULL;
	}
	for (int i = 0; i < n; ++i) {
		M.rhead[i].right = NULL;
		M.rhead[i].down = NULL;
	}
	OLNode * temp_c[maxSize];
	for (int j = 0; j < n; ++j)
		temp_c[j] = &(M.rhead[j]);
	for (int i = 0; i < m; ++i) {
		OLNode * r = &(M.chead[i]);
		for (int j = 0; j < n; ++j) {
			if (A[i][j] != 0) {
				OLNode * p = (OLNode *)malloc(sizeof(OLNode));
				p->col = i;
				p->row = j;
				p->val = A[i][j];
				p->down = NULL;
				p->right = NULL;
				r->right = p;
				r = p;
				temp_c[j]->down = p;
				temp_c[j] = p;
			}
		}
	}
	return 1;
}