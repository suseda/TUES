#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int solve(int arr[], int num, int colors)
{
	int combinations = 0, i = 1;
	
	while(i < num)
	{
		if (arr[i] == 0 && arr[i - 1] == 0 && arr[i + 1] == 0)
			combinations = colors * (colors - 1) * (colors - 1);
		else 
			combinations = (colors - 1) * (colors - 1);
		i = i + 2;
		combinations % (1000000000 + 7);
	}
	return combinations;
}


int main()
{
	int number, colors;
	int arr[16];
	printf("Number of the stones and number of the colors: ");
	scanf("%d %d", &number, &colors);

	for (int i = 0; i < number; i++)
		scanf("%d", &arr[i]);

	int res = solve(arr,number,colors);


	return 0;
}