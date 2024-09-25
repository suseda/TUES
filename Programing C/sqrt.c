int sqrt(x)
{
	int r = x; 
	int l = 0;
	do
	{
		int m = (r + l) / 2;
		if (m * m <= x)
			l = m;
		else
			r = m;
	}
	while (r-l>1);

	return l;
}




void main()
{
	int res = sqrt(64);
}