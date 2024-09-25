#include "tester.h"

int hash_func(char* str, size_t byte_count) 
{
		char byte = 0;
		unsigned hash = 0;
		while (*str)
		{
			hash ^= *str << byte;
			str++;
			byte += 8;
			if (byte == 32)
				byte = 0;
		}
		return hash % byte_count;
}

int main() 
{
    test_hf(4000, "input1.txt", &hash_func);
    return 0;
}