str_cmp(const char* l, const char* r) // връща стойност <0 ако l е преди r,
//стойност >0 ако l е след r и 0 ако са равни.
{
	while (*l == *r & *l != 0)
	{
		l++;
		r++;
	}
	return *l - *r;
}

void main()
{
	int res = str_cmp("steak", "stake");
}