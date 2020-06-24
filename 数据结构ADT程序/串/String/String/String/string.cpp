#include "string.h"

int StrAssign(Str &str, char * ch) {
	if (str.ch)
		free(str.ch);
	int len = 0;
	char * c = ch;
	while (*c) {
		++len;
		++c;
	}
	if (len == 0) {
		str.ch = NULL;
		str.length = 0;
		return 0;
	}
	else {
		str.ch = (char *)malloc(sizeof(char) * (len + 1));
		if (str.ch == NULL)
			return 0;
		else {
			c = ch;
			for (int i = 0; i <= len; ++i, ++c) 
				str.ch[i] = *c;
			str.length = len;
			return 1;
		}	
	}
}

int StrInsert(Str &str, int pos, Str t) {
	char * c;
	if (pos < 0 || pos > str.length || str.length == 0)
		return 0;
	c = (char *)malloc(sizeof(char) * (t.length + str.length + 1));
	if (c == NULL)
		return 0;
	for (int i = 0; i < pos; ++i)
		c[i] = str.ch[i];
	for (int i = 0; i < t.length; ++i)
		c[i + pos] = t.ch[i];
	for (int i = pos; i < str.length; ++i)
		c[i + t.length] = str.ch[i];
	str.length += t.length;
	free(str.ch);
	str.ch = c;
	return 1;
}

int StrDelete(Str &str, int pos, int len) {
	char * c;
	if (pos < 0 || pos >(str.length - len))
		return 0;
	c = (char *)malloc(sizeof(char) * (str.length - len + 1));
	if (c == NULL)
		return 0;
	for (int i = 0; i < pos; ++i)
		c[i] = str.ch[i];
	for (int i = pos; i < str.length - len; ++i)
		c[i] = str.ch[i + len];
	str.length -= len;
	free(str.ch);
	str.ch = c;
	return 1;
}

void StrCopy(Str &str, Str t) {
	if (str.ch)
		free(str.ch);
	str.length = t.length;
	for (int i = 0; i < t.length; ++i)
		str.ch[i] = t.ch[i];
}

bool StrEmpty(Str str) {
	if (str.length)
		return true;
	else
		return false;
}

int StrCompare(Str s1, Str s2) {
	for (int i = 0; i < s1.length && i < s2.length; ++i)
		if (s1.ch[i] != s2.ch[i])
			return s1.ch[i] - s2.ch[i];
	return s1.length - s2.length;
}

int StrLength(Str str) {
	return str.length;
}

int StrClear(Str &str) {
	if (str.ch) {
		free(str.ch);
		str.ch = NULL;
	}
	str.length = 0;
	return 1;
}

int StrCat(Str &str, Str t) {
	char * c;
	c = (char *)malloc(sizeof(char) * (str.length + t.length + 1));
	if (c == NULL)
		return 0;
	int i = 0;
	while (i <= str.length) {
		c[i] = str.ch[i];
		++i;
	}
	int j = 0;
	while (j < t.length + 1) {
		c[i + j] = t.ch[j];
		++j;
	}
	str.length += t.length;
	free(str.ch);
	str.ch = c;
	return 1;
}

int SubString(Str &sub, Str str, int pos, int len) {
	if (pos < 0 || pos >= str.length || len < 0 || len > str.length - pos)
		return 0;
	if (sub.ch) {
		free(sub.ch);
		sub.ch = NULL;
	}
	if (len == 0) {
		sub.ch = NULL;
		sub.length = 0;
		return 1;
	}else {
		sub.ch = (char *)malloc(sizeof(char) * (len + 1));
		int i = pos;
		int j = 0;
		while (i < pos + len) {
			sub.ch[j] = str.ch[i];
			++i;
			++j;
		}
		sub.ch[j] = '\0';
		sub.length = len;
		return 1;
	}
}

int StrIndex(Str str, int pos, Str t) {
	int i, j, start;
	if (t.length == 0) return 0;
	start = pos;
	i = start;
	j = 0;
	while(i < str.length && j < t.length)
		if (str.ch[i] == t.ch[j]) { i++; j++;}
		else {
			start++;
			i = start;
			j = 0;
		}
	if (j >= t.length) return start;
	else return -1;
	/*int i = pos, j = 1, k = i;
	if (pos < 0 || t.length == 0)
		return 0;
	while (i <= str.length && j <= t.length) {
		if (str.ch[i] == t.ch[j]) {
			++i;
			++j;
		}else {
			j = 1;
			i = ++k;
		}
	}
	if (j > t.length)
		return k;
	else return 0;
	*/
}

int StrReplace(Str &str, Str t, Str v) {
	if (t.length == 0 || v.length == 0)
		return 0;
	char *c;
	c = (char *)malloc(sizeof(char) * (str.length + 1));
	int pos1 = 0, n = 0, i = 0, pos = 0, k;
	while (pos1 <= str.length) {
		int k;
		k = StrIndex(str, pos1, t);
		if (k < 0)
			break;
		else {
			pos1 = (t.length + k);
			n++;
		}
	}
	if (n == 0)
		return 0;
	str.length += n * (v.length - t.length);
	while (i < n) {
		k = StrIndex(str, pos, t);
		for (int j = pos; j < k; ++j)
			c[j + (v.length - t.length) * i] = str.ch[j];
		for (int j = 0; j < v.length; ++j)
			c[k + j + (v.length - t.length) * i] = v.ch[j];
		pos = (t.length + k);
		++i;
	}
	if (k < str.length - t.length)
		for (int j = k + t.length; j < str.length; ++j)
			c[j + n * (v.length - t.length)] = str.ch[j];
	free(str.ch);
	str.ch = c;
	str.ch[str.length] = '\0';
	return 1;
}

bool StrDestroy(Str &str) {
	free(str.ch);
	str.length = 0;
	return true;
}

void StrPrint(Str str) {
	printf("¸Ã×Ö·û´®Îª£º%s\n", str.ch);
}

void StrInit(Str &str) {
	str.ch = (char *)malloc(sizeof(char));
	str.ch = NULL;
	str.length = 0;
}

int KMP(Str str, Str sub, int next[]) {
	int i = 1, j = 1;
	while (i <= str.length && j <= sub.length) {
		if (j == 0 || str.ch[i] == sub.ch[j]) {
			++i;
			++j;
		}else {
			j = next[j];
		}
	}
	if (j > sub.length)
		return i - sub.length;
	else
		return -1;
}

void getnext(Str sub, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < sub.length) {
		if (j == 0 || sub.ch[i] == sub.ch[j]) {
			++i;
			++j;
			next[i] = j;
		}else
			j = next[j];
	}
}

void getnextval(Str sub, int nextval[]) {
	int i = 1, j = 0;
	nextval[1] = 0;
	while (i < sub.length) {
		if (j == 0 || sub.ch[i] == sub.ch[j]) {
			++i;
			++j;
			if (sub.ch[i] != sub.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}else
			j = nextval[j];
	}
}