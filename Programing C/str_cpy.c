void str_cpy(char* out, const char* in)
{
	while (*out++ = *in++);
}


void main()
{
	char buffer[100];
	str_cpy(buffer, "test string");
}