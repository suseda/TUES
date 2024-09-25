#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <malloc.h>

char* str_cat_many(const char* from[], unsigned cnt)
{
	int size = 0;
	for (int i = cnt; --i >= 0;)
		size += strlen(from[i]);
	char* res = malloc(size);
	*res = 0;
	for (unsigned int n = 0; n < cnt;)
		strcat(res, from[n++]);
	return res;
}


void main()
{
	char* from[]={"2020", " finaly", " end!"};
	str_cat_many(from, 3);
}