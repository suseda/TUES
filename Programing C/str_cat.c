void str_cat(char* out,  char* in)
{
	while (*out)
		*out++;
	while (*out++ = *in++);

}

void main()
{
	char buffer[100] = "Hello";
	str_cat(buffer, " world!"); // buffer=="Hello world!"
}