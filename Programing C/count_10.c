#include <stdio.h>
unsigned int count_10(short data)
{
	unsigned int leftmost = 1<<31;
	unsigned int cnt = 0,cur_bit;
	unsigned int prev_bit = !!(data & leftmost);
	leftmost >>= 1;
	cur_bit = !!(data & leftmost);
	while( leftmost!=0 )
	{
		if (prev_bit == 1 && cur_bit == 0)
			cnt++;
		prev_bit = cur_bit;
		cur_bit = !!(data & leftmost);
		leftmost >>= 1;
		
	}
	return cnt;
}


void main()
{
	printf("%d ", count_10(10));
	printf("%d ", count_10(3));
	printf("%d ", count_10(21601));
}