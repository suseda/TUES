int pow(x, n)
{
	int y;
	if (n == 0)
		return 1;
	else
		if (n % 2 == 0)
		{
			y = pow(x, n / 2);
			return y * y;
		}
		else
			return x * pow(x, n - 1);
}



void main()
{
	int res = pow(2, 4);
}