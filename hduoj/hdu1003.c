#include<stdio.h>
#include<limits.h>

int main(void)
{
	int t, n, a;
	int sum, start, end;
	int maxsum, maxstart, maxend;
	int i, j;

	scanf("%d", &t);
	for (i=1; i<=t; ++i)
	{
		scanf("%d", &n);
		maxsum = INT_MIN;	// 全负情况修正
		sum = 0;
		start = 1;
		for (j=1; j<=n; ++j)
		{
			scanf("%d", &a);
			sum += a;
			end = j;

			if (sum > maxsum)
			{
				maxsum = sum;
				maxstart = start;
				maxend = end;
			}
			if (sum < 0)	// 两个判断不能颠倒，不能加else
			{
				sum = 0;
				start = j+1;
			}
		}
		printf("Case %d:\n%d %d %d\n", i, maxsum, maxstart, maxend);
		if (i!=t)
		{
			printf("\n");
		}
	}
	return 0;
}
