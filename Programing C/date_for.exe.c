#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



void date_for(int dd)
{
	static int monthdays[12] = { 31, 28, 31, 30, 31, 30,
						   31, 31, 30, 31, 30, 31 };

	int d = 1, m = 1, y = 1;

	int i = dd / ((400 * 365) + (24 * 4) + 1);

	dd -= i * ((400 * 365) + (24 * 4) + 1);

	int j = dd / ((100 * 365) + 24);

	dd -= j * ((100 * 365) + 24);

	int n = dd / ((4 * 365) + 1);

	dd -= n * ((4 * 365) + 1);

	int b = dd / 365;

	dd -= b * 365;

	y += i * 400 + j * 100 + n * 4 + b;



	for (int i = 0; (dd - monthdays[i]) >= monthdays; i++)
		dd -= monthdays[i], m = i + 1;
	d += dd;

	printf("%02d.%02d.%04d", d, m, y);
}

void main(int argc, char* argv[]) {
	int day = atoi(argv[1]);
	if (argc == 2) {
		date_for(day);
	}
}

//не работи за месеци