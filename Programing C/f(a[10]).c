void swap(int* c, int* d)
{
	int x = *c;
	*c = *d;
	*d = x;
}




void f(int a[10])
{
	int b = 0;
	while (b < 5)
	{
		swap(&a[b], &a[9 - b]);
		++b;

	}
	
}


void main()
{
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
		f(a);
}


