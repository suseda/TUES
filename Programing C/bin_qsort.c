void bin_qsort(unsigned* l, unsigned* r, unsigned mask)
{
	if (l < r && mask)
	{
		int* p = l, * q = r;
		do
		{
			while (~*p & mask && p < q)
				p++;
			while (*q & mask && p <= q)
				q--;
			if (p < q)
			{
				int t = *p;
				*p = *q;
				*q = t;
			}
		} while (p < q);
		bin_qsort(l, q, mask >> 1);
		bin_qsort(p, r, mask >> 1);
	}
}
void main()
{
	unsigned a[] = { 500, 20,30, 400, 300, 10 };
	bin_qsort(a, a + 5, 512);
}