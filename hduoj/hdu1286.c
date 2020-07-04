// 如果p整除n, 小于等于n的有n/p个数和n有公约数p

#include<stdio.h>

int main(void)
{
	int cn, n;
	int re;
	int prime[5000]={2};
	int i, j, k;
	
	k = 1;
	for (i=3; i<40000; ++i)
	{
		for (j=0; prime[j]*prime[j]<=i; ++j)
		{
			if (i%prime[j]==0)
			{
				break;
			}
		}
		if (prime[j]*prime[j]>i)
		{
			prime[k] = i;
			++k;
		}
	}

	scanf("%d", &cn);
	for (i=0; i<cn; ++i)
	{
		scanf("%d", &n);
		re = n;
		for (j=0; prime[j]<=n; ++j)
		{
			if (n%prime[j]==0)
			{
				re = re*(prime[j]-1)/prime[j];
			}
		}
		printf("%d\n", re);
	}

    return 0;
}
