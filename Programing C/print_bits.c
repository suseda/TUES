#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void printbits(void* a)
{
	unsigned int leftmost = 1 << sizeof(int) * 8 - 1;
	for (int i = 0; i < sizeof(int)*8 ; i++)
	{
		printf("%d", !!(*(int*)a & leftmost));
		leftmost >>= 1;
	}
	puts("\n");
}


int main()
{
	int num = 6;
	printbits(&num);

	return 0;
}