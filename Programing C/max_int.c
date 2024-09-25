#include <stdarg.h>
int max1(int cnt, ...) {
	va_list l;
	va_start(l, cnt);
	int buff = 0;

	while (cnt) {
		int buff2 = va_arg(l, int);
		if (buff < buff2)
			buff = buff2;

		cnt -= 1;
	}
	va_end(l);
	return buff;
}

void main()
{
	int res = max1(4, 1, 2, 3, 2);
}