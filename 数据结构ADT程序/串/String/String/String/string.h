#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct Str {
	char * ch;
	int length;
}Str;
int StrAssign(Str &str, char * ch);
int StrInsert(Str &str, int pos, Str t);
int StrDelete(Str &str, int pos, int len);
void StrCopy(Str &str, Str t);
bool StrEmpty(Str str);
int StrCompare(Str s1, Str s2);
int StrLength(Str str);
int StrClear(Str &str);
int StrCat(Str &str, Str t);
int SubString(Str &sub, Str str, int pos, int len);
int StrIndex(Str str, int pos, Str t);
int StrReplace(Str &str, Str t, Str v);
bool StrDestroy(Str &str);
void StrPrint(Str str);
void StrInit(Str &str);
int KMP(Str str, Str sub, int next[]);
void getnext(Str sub, int next[]);
void getnextval(Str sub, int nextval[]);
