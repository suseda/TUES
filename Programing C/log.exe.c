#include <stdio.h>
#include <stdlib.h>
int log(int x, int* y)
{
	if (x > * y)
		return 0;
	else
	{

		int n = 2 * log(x * x, y);

		if (*y >= x)
		{
			*y /= x;
			n++;
		}
		return n;
	}
}
int main(int argc, const char* argv[])
{
	int res = atoi(argv[2]);
	printf("log=%d", log(atoi(argv[1]), &res));
}