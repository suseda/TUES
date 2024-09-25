pow(x, n)
{
	int s = x, res = 1;
	while(n)
		{
		if (n & 1)

			res = res * s;
		s *= s;
		n / 2;
		}
	return res;
}

int root(y,n)
{
int l = 0;
int r = 1;
while (pow(r,n) < y)
	r*= 2;
do
{
	int m = (r + l) / 2;
	if (pow(m, n) < y)
		l = m + 1;
	else
		r = m;
} while (l < r);
     return l;
}



void main()
{  
	root(276922881, 4);
	for(int n=1;n<100;n++)
		for(int x=0;x<1000;x++)
			if (x!= root(pow(x,n),n))
				root(pow(x,n),n);
}