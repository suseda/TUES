length(const char * s)
{
	const char * p = s;
	while (*p)
		p++;
	return p - s;
}


void main()
{
	char a[100] = "12345";
	length(a);
}