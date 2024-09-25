void mem_move(char* dest, const char* src, int len)
{
	if (src < dest)
		while (--len >= 0)
			dest[len] = src[len];
	else
		for (int i = 0; i < len; i++)
			dest[i] = src[i];
}

void main()
{
	char str[100] = "gameboy";
	mem_move(str + 4, str + 2, 7);
}