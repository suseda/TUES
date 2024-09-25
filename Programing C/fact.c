int fact(x)
{
	int f = x;
	while (x > 1)
	{
		x = x - 1;
		f = f * x;
	}
	return f;
}



void main()
{
	int res = fact(5);
}