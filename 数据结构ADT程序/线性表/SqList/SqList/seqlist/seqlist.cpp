#include "seqlist.h"

void InitSeqlist(SeqList &seqlist) {
	seqlist.last = 0;
}

void CreateSeqlist(SeqList &seqlist, ElemType data[], int n) {
	if (n > MAXSIZE) {
		printf("n is over\n");
		exit(-1);
	}
	for (int i = 0; i < n; i++) {
		seqlist.data[i] = data[i];
	}
	seqlist.last = n - 1;
}

void PrintSeqlist(SeqList seqlist) {
	if (seqlist.last < 0) {
		printf("线性表不存在");
		exit(-1);
	}
	for (int i = 0; i < seqlist.last + 1; i++) {
		printf("%d", seqlist.data[i]);
	}
	printf("\n");
}

ElemType GetData(SeqList seqlist, int i) {
	if (i < 1 || i > seqlist.last + 1) {
		printf("查找位置非法");
		exit(-1);
	}
	else
		return seqlist.data[i - 1];
}

int Locate(SeqList seqlist, ElemType e) {
	for (int i = 0; i < seqlist.last + 1; i++) {
		if (seqlist.data[i] == e)
			return i + 1;
	}
	return -1;
}

void InsSeqlist(SeqList &seqlist, int i, ElemType e) {
	if (i > seqlist.last + 2 || i < 1 || seqlist.last + 1 >= MAXSIZE) {
		printf("插入位置非法！");
		exit(-1);
	}
	for (int j = seqlist.last; j >= i - 1; j--) {
		seqlist.data[j + 1] = seqlist.data[j];
	}
	seqlist.data[i - 1] = e;
	seqlist.last++;
}

ElemType DelSeqlist(SeqList &seqlist, int i, ElemType &e) {
	if (seqlist.last == 0 || i < 1 || i > seqlist.last + 1) {
		printf("删除位置有误！");
		exit(-1);
	}
	e = seqlist.data[i];
	for (int j = i; j < seqlist.last; j++) {
		seqlist.data[j] = seqlist.data[j + 1];
	}
	seqlist.last--;
	return e;
}

void Merge2Seqlist(SeqList la, SeqList lb, SeqList &lc) {
	int i = 0, j = 0, k = 0;
	while (i <= la.last && j <= lb.last) {
		if (la.data[i] <= lb.data[j]) {
			lc.data[k] = la.data[i];
			i++;
			k++;
		}
		else {
			lc.data[k] = lb.data[j];
			j++;
			k++;
		}
	}
	while (i <= la.last) {
		lc.data[k] = la.data[i];
		i++;
		k++;
	}
	while (j <= lb.last) {
		lc.data[k] = lb.data[j];
		j++;
		k++;
	}
	lc.last = la.last + lb.last + 1;
}

int ListLength(SeqList seqlist) {
	if (seqlist.last == 0)
		return 0;
	else {
		return seqlist.last + 1;
	}
}

void DestroyList(SeqList& seqList) {
	if (seqList.data)
		free(seqList.data);
	else
		printf("销毁失败");
	exit(-1);
}

void ClearList(SeqList& seqlist) {
	seqlist.last = 0;
}

bool EmptyList(SeqList seqlist) {
	if (seqlist.last == 0)
		return true;
	else
		return false;
}

void Delxtoy(SeqList &seqlist, ElemType x, ElemType y) {
	for (int i = 0; i < seqlist.last + 1; ++i) {
		if (seqlist.data[i] >= x && seqlist.data[i] <= y) {
			for (int j = i; j < seqlist.last; ++j) {
				seqlist.data[j] = seqlist.data[j + 1];
			}
			--(seqlist.last);
			--i;
		}
	}
}

void Paixu(SeqList &seqlist) {
	int j = 0, k = 0;
	for (int i = 0; i < seqlist.last + 1; i++) {
		if (seqlist.data[i] % 2 == 1) {
			k = seqlist.data[j];
			seqlist.data[j] = seqlist.data[i];
			seqlist.data[i] = k;
			j++;
		}
		else continue;
	}
}

void Delequal(SeqList &seqlist) {
	int j = 0;
	for (int i = 0; i < seqlist.last; ++i) {
		if (seqlist.data[i + 1] != seqlist.data[i]){
			j++;
			seqlist.data[j] = seqlist.data[i + 1];	
		}
	}
	seqlist.last = j;
}