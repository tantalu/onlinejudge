#include<stdio.h>

int main(void)
{
	int n;
	long long re, com;
	int i;
	
 	while (scanf("%d", &n)!=EOF)
	{
		re = 0;
		com = 1;
		for (i=1; i<=n; ++i)
		{
			com *= n+1-i;
			com /= i;// 两组共选出i个人，有C(n, i)中选法
			re += (i-1)*com;//分为两组，有i-1种分法
		}
		printf("%I64d\n", re);
	}
	
	return 0;
}
