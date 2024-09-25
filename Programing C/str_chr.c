const char* strchr(const char* c, char s)
{
	while (*c)
	{
		if (*c == s)
			return c;
		c++;
	}
	return 0;
}

void main()
{
	strchr("abcfhg", 'h');
}