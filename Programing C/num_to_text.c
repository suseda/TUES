#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
struct words { char* word; };
struct words over_hundreds[] = { {""}, {"hundred "}, {"thousand "}, {"million "}, {"billion "} };
struct words tenths[] = { {""}, {"ten "}, {"twenty "}, {"thirty "}, {"forty "}, {"fifty "}, {"sixty "}, {"seventy "}, {"eighty "}, {"ninety "} };
struct words teens[] = { {"eleven "}, {"twelve "}, {"thirteen "}, {"fourteen "}, {"fifteen "}, {"sixteen "}, {"seventeen "}, {"eighteen "}, {"nineteen "} };
struct words ones[] = { {""}, {"one "}, {"two "}, {"three "}, {"four "}, {"five "}, {"six "}, {"seven "}, {"eight "}, {"nine "} };
struct words* over_hundred = over_hundreds, * tenth = tenths, * one = ones, * teen = teens;
void subnum2text(char* out, unsigned num)
{
	char and_word[5] = { "and " };
	strcat(out, one[num / 100].word);
	if (num / 100)
	{
		strcat(out, over_hundred[1].word);
		if (num % 100)
			strcat(out, and_word);
	}
	if (!(num % 100 / 10 == 1 && num % 10 != 0))
	{
		strcat(out, tenth[(num % 100) / 10].word);
		strcat(out, one[num % 10].word);
	}
	else
	{
		strcat(out, teen[(num % 10) - 1].word);
	}
}
void num2text(char* out, unsigned num)
{
	static int i = 2;
	unsigned int numbers[] = { 1000, 1000000, 1000000000 };
	if (num < 1000 || i == -1)
	{
		subnum2text(&out[0], num);
	}
	else
	{
		if (num > numbers[i])
		{
			subnum2text(&out[0], num / numbers[i]);
			strcat(&out[0], over_hundred[i + 2].word);
		}
		i--;
		num2text(&out[0], num % numbers[i + 1]);
	}
}
int main()
{
	char out[100] = { 0 };
	num2text(&out[0], 1014970870);
}