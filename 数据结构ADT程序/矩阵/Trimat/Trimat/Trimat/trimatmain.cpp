#include "trimat.h"

int main(void)
{
	Trimat trimat1[maxSize], trimat2[maxSize], trimat3[maxSize], trimat4[maxSize], trimat5[maxSize];
	ElemType A[][maxSize] = {
		{1, 0, 0, 2},
		{0, 2, 1, 0},
		{3, 0, 1, 0},
	};
	createtrimat(A, 3, 4, trimat1);
	print(trimat1);
	trstrimat(trimat1, trimat2);
	fasttrstrimat(trimat2, trimat3);
	addtrimat(trimat4, trimat1, trimat3);
	muttrimat(trimat5, trimat1, trimat2, 3, 4, 3);
	print(trimat2);
	print(trimat3);
	print(trimat4);
	print(trimat5);

	return 0;
}