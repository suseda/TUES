#include <stdio.h>

struct time
{
	int h;
	int m;
	int s;
}

typedef time;

int is_valid_time(time t)
{
	return t.h >= 0 && t.h < 24 && t.m >= 0 && t.m < 60 && t.s >= 0 && t.s < 60;
}

int main()
{
	time a[] = {
	{ 12, 15, 25 },
	{ 22, 45, 0 },
	{ 10, 59, 43 },
	{ 11, 59, 43 },
	{ 10, 69, 43 }
	};
	int max_time = 0, current_time = 0, max_index;
	int len = (int)(sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < len; i++)
	{
		if (is_valid_time(a[i]))
		{
			current_time = a[i].h * 3600 + a[i].m * 60 + a[i].s;
			if (current_time > max_time)
			{
				max_time = current_time;
				max_index = i;
			}
		}
	}

	printf("%i:%i:%i\n", a[max_index].h, a[max_index].m, a[max_index].s);
	return 0;
}