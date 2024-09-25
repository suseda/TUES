int* bsearch(int* l, int* r, int searched)// без рекурсия!
{
	do
	{
		int* m = l + (r - l) / 2;
		if (*m < searched)
			l = m + 1;
		else
			r = m;
	} while (l < r);
	return r;
}

void main()
{
	int a[] = { 11,12,13,40,50,60,700,800,900,1000 };
	int* res = bsearch(a, a + 9, 40); // res==a+3
}