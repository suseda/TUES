rotate(int* p, int len, int k)
{
	int i = len, save = p[0], n = k, control = 0;
	k %= len;
	while (i)
	{
		for (int save2; i && (control != n);)
		{
			save2 = p[n];
			p[n] = save;
			save = save2;
			--i;
			n = (n + k) % len;
		}
		p[n] = save;
		--i;
		++control;
		save = p[control];
		n = control + k;
	}
	return;
}
void main()
{
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	rotate(a, 10, 4);
}
