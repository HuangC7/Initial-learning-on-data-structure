#include "string.h"

int main(void)
{
	Str str, v, t;
	char ch1[] = "abccabcabc";
	char ch2[] = "ab";
	char ch3[] = "cde";
	StrInit(str);
	StrInit(v);
	StrInit(t);
	StrAssign(str, ch1);
	StrAssign(t, ch2);
	StrAssign(v, ch3);
	StrReplace(str, t, v);
	StrPrint(str);
	return 0;
}