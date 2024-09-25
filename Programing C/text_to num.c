#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
struct words { char* word; };
struct words number[] = { {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"},
						{"eleven"}, {"twelve"}, {"thirteen"}, {"fourteen"}, {"fifteen"}, {"sixteen"}, {"seventeen"}, {"eighteen"}, {"nineteen"},
						{"ten"}, {"twenty"}, {"thirty"}, {"forty"}, {"fifty"}, {"sixty"}, {"seventy"}, {"eighty"}, {"ninety"},
						{"hundred"}, {"thousand"}, {"million"}, {"billion"}, { "trillion" }, { "quadrillion" }, { "quintillion" } };
struct words* numbers = number;
long long int number_arr[] = { 100, 1000, 1000000, 1000000000, 1000000000000, 1000000000000000, 1000000000000000000 };
int cmp(const char* text, char* cmp_text)
{
	int i = 0;
	while (text[i] != ' ' && text[i] != 0)
	{
		if (text[i] != cmp_text[i] || cmp_text[i] == 0)
			return 0;
		i++;
	}
	return 1;
}
unsigned long long text2num(const char* text)
{
	unsigned int index = 0;
	long long int i = 0;
	long long int a = 0;
	long long int num = 0;
	while (index < strlen(text))
	{
		while (!(cmp(&text[index], numbers[i].word)))
		{
			i++;
			if (i > 33)
				break;
		}
		if (i >= 0 && i <= 8)
		{
			a += i + 1;
			index += strlen(numbers[i].word) + 1;
		}
		else if (i >= 9 && i <= 17)
		{
			a += i + 2;
			index += strlen(numbers[i].word) + 1;
		}
		else if (i >= 18 && i <= 26)
		{
			a += (i - 17) * 10;
			index += strlen(numbers[i].word) + 1;
		}
		else if (i >= 27 && i <= 33)
		{
			a *= number_arr[i - 27];
			index += strlen(numbers[i].word) + 1;
			if (i >= 28)
			{
				num += a;
				a = 0;
			}
		}
		else if (i > 32)
			index += 4;
		i = 0;
	}
	num += a;
	return num;
}
int main()
{
	const char text[] = { "two hundred" };
	text2num(&text[0]);
}