#include <stdarg.h>
double vmax(int type, int cnt, ...) {
	va_list l;
	va_start(l, cnt);
	double buff = type ? va_arg(l, double) : va_arg(l, int);
	cnt--;
	if (type == 0) {
		while (cnt) {
			int buff2 = va_arg(l, int);
			if (buff < buff2)
				buff = buff2;

			cnt -= 1;
		}

	}
	else {
		while (cnt) {
			double buff2 = va_arg(l, double);
			if (buff < buff2)
				buff = buff2;
			cnt -= 1;
		}
	}
	va_end(l);
	return buff;
}

void main()
{
	double i;
	i = vmax(1, 4, -1., -3., -4.5, -4.);
}