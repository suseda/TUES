int log(y, n)
{
	int x = 1;
	int a = x;
do {
		do {
			x = x * a;
			n = n - 1;
		} while (n > 0);
		a = a + 1;
		x = a;
   } while (x != y); 
   return x;
}


void main()
{
	int res=log( 1, 0);
}