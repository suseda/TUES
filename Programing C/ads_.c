#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 30

int number, minutes;
int A[MAX], B[MAX];



int solve()
{
	int K1 = 1, K2 = K1 + minutes, cur_cnt = 0, max_cnt = 0;
	while (K1 < number)
	{
		for (int i = 0; i < number; i++)
		{
			if (A[i] <= K1 && K1 + minutes <= B[i])
				cur_cnt++;
			if (A[i] <= K2 && K2 + minutes <= B[i])
				cur_cnt++;
		}

		if (cur_cnt > max_cnt)
			max_cnt = cur_cnt;

		cur_cnt = 0;
		K1++;
		K2++;
	}
	return max_cnt;
}



int main()
{
	printf("Enter number of customers and minutes for ads: ");
	scanf("%d %d", &number, &minutes);

	for (int i = 0; i < number; i++)
		scanf("%d %d", &A[i], &B[i]);

	int res = solve();
	printf(" Òhe maximum number of people who can hear the ads is: %d", res);

	return 0;
}
