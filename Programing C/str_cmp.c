str_cmp(const char* l, const char* r) // ����� �������� <0 ��� l � ����� r,
//�������� >0 ��� l � ���� r � 0 ��� �� �����.
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