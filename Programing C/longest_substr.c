#include <stdio.h>
int longest_substr(char str[], int* len)
{
	int current_len = 0, i = 0, pos = 0;
	for (; str[i]; i++)
	{
		for (int j = i + 1; str[j]; j++)
		{
			if (str[i] == str[j])
				current_len++, i++;
			else
				j -= current_len, i -= current_len, current_len = 0;
			if (current_len > * len)
				*len = current_len, pos = i - current_len;
		}
	}
	return pos;
}
void main()
{
	char str[] = "abcdeabcabdeabca";
	int len = 0;
	longest_substr(&str, &len);
}
