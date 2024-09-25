#include<stdlib.h>
#include<stdio.h>
#define JAN 0
#define FEB (JAN+31)
#define MART (FEB+28)
#define AP (MART+31)
#define MAY (AP+30)
#define JUNE (MAY+31)
#define JULY (JUNE+30)
#define AUG (JULY+31)
#define SEP (AUG+31)
#define OCT (SEP+30)
#define NOV (OCT+31)
#define DEC (NOV+30)
date(d, m, y)
{
	static const int r[] = { 0,JAN,FEB,MART,AP,MAY,JUNE,JULY,AUG,SEP,OCT,NOV,DEC };
	d += r[m] - 1;
	d += (y - 1) * 365;
	if (m <= 2)
		y--;
	d += y / 4 - y / 100 + y / 400;
	return d;
}
week_day(d, m, y)
{

	return date(d, m, y) % 7;

}

int main(int argc, const char* argv[])
{
	static const char* const day_name[] = { "mon","tue","wed","thu","fri","sat","sun" };
	printf("week day=%s", day_name[week_day(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]))]);
}