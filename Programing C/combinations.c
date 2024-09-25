#include <stdio.h>
#include <malloc.h>

void comb(int* arr, int j, int n, int index, int k)
{
	if (index != k)
	{
		for (int i = j; i <= n - 1; i++)
		{
			arr[index] = i + 1;
			comb(arr, i + 1, n, index + 1, k);
		}
	}
	else
	{
		for (int a = 0; a < k; a++)
			printf("%d ", arr[a]);
		printf("\n");
	}
}

void print_comb(n, k)
{
	int* array = malloc(k * sizeof * array);
	if (!*array)
		return;
	comb(array, 0, n, 0, k);
	free(array);
}

void main()
{
	print_comb(5, 3);
}