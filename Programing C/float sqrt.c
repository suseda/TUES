float pow(float x, int n)
{
	float res = 1;
	while (n)
	{
		if (n & 1)
			res = res * x;
		x *= x;
		n /= 2;
	}
	return res;
}
float root(float y, int n)
{
	float p = y;
	if (y < 0)
	{
		p = -y;
		if (n % 2 == 0)
		{
			return 0;
		}
	}
		float l = 0;
		float r = p;
		while (pow(r, n) < p - 1)
			r *= 2;
		do
		{
			float m = (l + r) / 2;
			if (pow(m, n) <= p)
				l = m;
			else
				r = m;
		} while ((l < r) && (0.1 < r - l));
		if (y < 0)
			return -l;
		else
			return l;
}



void main()
{
	root(4, 2);
}

