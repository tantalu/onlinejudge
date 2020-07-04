#include<stdio.h>

int main(void)
{
	int bit[25];
	float a = 1;
	int n = 0;
	int year;
	int i, j;

	j = 1;
	for (i=0; i<22; ++i)
	{
		bit[i] = 4<<i;
		
		while (n<bit[i])
		{
			a *= ++j;
			while (a>2)
			{
				a /= 2;
				++n;
			}	// ½×Âë ((*(int*)&a & 0x7f800000)>>23)-0x7f  or  frexp(a, n); --n;
		}
		bit[i] = j-1;
	}

	while (scanf("%d", &year) && year)
	{
		printf("%d\n", bit[(year-1960)/10]);
	}
	return 0;
}

