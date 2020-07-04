// 次大的移动次数是最大的1/2，2^(n-k)
#include<stdio.h>

int main(void)
{
	int t, n, k;
	int i;
	while (scanf("%d", &t)!=EOF)
	{
		for (i=0; i<t; ++i)
		{
			scanf("%d%d", &n, &k);
			printf("%I64d\n", 1ll<<(n-k));
		}
	}
	
	return 0;
}
