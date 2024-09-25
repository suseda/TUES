void swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void qsort(int* l, int* r)
{
	int *p = l, *q = r, m = l[(r-l)/2];
	if (l == r)
		return l;
	do {
		{
			while (*p < m)
				p++;
			while (*q > m)
				q--;
			if (p<=q)
				swap(p++, q--);
		}
	} while (p <= q);
	qsort(l, q);
	qsort(p, r);
}

void main()
{
	int a[5] = {20,10,30,50,0};
	int p[5] = { 10,10,30,10,10 };

	qsort(a, a + 4);
	qsort(p, p + 4);

}
