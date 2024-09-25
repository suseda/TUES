#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#define BLOCK_SIZE 4000
int main(int argc, const char* argv[])
{
	FILE* src = fopen(argv[1], "rb"); 
	FILE* dest = fopen(argv[2], "w+b"); 
	if (!dest || !src)
		return 0;
	size_t size;
	void* buffer = malloc(BLOCK_SIZE);
	if (!buffer)
		return 0;
	do
	{
		size = fread(buffer, 1, BLOCK_SIZE, src);
		fwrite(buffer, 1, size, dest);
	} while (size == BLOCK_SIZE);
	free(buffer);
	fclose(src);
	fclose(dest);
	return 1;
}