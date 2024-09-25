#include <stdio.h>
#include <math.h>
#define BYTE_SIZE 8

int count(unsigned int t)
{
	int count = 0;
	unsigned int leftmost = 1 << BYTE_SIZE - 1;
	while(leftmost!=0)
	{
		if (!(t & leftmost))
			count++;
		leftmost >>= 1;
	}
	return count;
}


unsigned int get_net_size(unsigned int mask[])
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
		cnt += count(mask[i]);
	if (cnt == 0)
		return 0;
	else
		return pow(2, cnt) - 2;
}

void main()
{
	unsigned int mask[] = { 255, 255,255,248 };
	//unsigned int mask[] = { 255, 255,255,255 };
	//unsigned int mask[] = { 255, 192,0,224 };
	//unsigned int mask[] = { 0, 0,0,0 };
	printf("%d ",get_net_size(mask));
}