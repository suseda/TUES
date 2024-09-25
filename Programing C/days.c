#define JAN 0
#define FEB (JAN+31)
#define MAR (FEB+28)
#define APR (MAR+31)
#define MAY (APR+30)
#define JUN (MAY+31)
#define JUL (JUN+30)
#define AUG (JUL+31)
#define SEP (AUG+31)
#define OCT (SEP+30)
#define NOV (OCT+31)
#define DEC (NOV+30)
int days(nd, m, y)
{
	static int md[12] = { JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC };
	nd += md[m - 1] - 1;
	nd += (400 * 365 + 24 * 4 + 1) * (--y / 400);
	y = y % 400;
	nd += (100 * 365 + 24) * (y / 100);
	y %= 100;
	nd += (4 * 365 + 1) * (y / 4);
	y %= 4;
	nd += 365 * y;
	return nd;
}

void main()
{
	days(27, 5, 2020);
}
