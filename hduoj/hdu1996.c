// 每个盘子可以放在三根柱子上，顺序只有一种，3^n
#include<stdio.h>

long long num[33] = {1};

int main(void)
{
	int t, n;
	int i;
	for (i=1; i<31; ++i)
	{
		num[i] = 3*num[i-1];
	}
	while (scanf("%d", &t)!=EOF)
	{
		for (i=0; i<t; ++i)
		{
			scanf("%d", &n);
			printf("%I64d\n", num[n]);
		}
	}
	
	return 0;
}
