char f(char* str)
{
	int len;
	while (*str)
	{
		while (*str == ' ')
		{
			len++;
		}
		*str++;
	}
	return len;
}

int main()
{
	char str[] = "hello big world ";
	char res = f(str);
	return 0;
}

