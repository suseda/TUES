pow(int x, int n)
{
	int y = 1;
	while (n != 0)
	{
		if (n & 1)
			y = y * x;
		x = x * x;
		n = n / 2;
	}
	return y;
}


void main()
{
	pow(2, 30);
}