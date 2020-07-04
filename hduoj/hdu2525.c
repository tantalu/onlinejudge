#include<stdio.h>
#include<string.h>

long long dp[105][105] = {{0}};

int main(void)
{
	int t, d, a, k, x;
	long long re;
	int i, j;
	
	scanf("%d", &t);
	while (t-- != 0)
	{
		re = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%I64d%d%d%d%d", &dp[0][0], &d, &a, &k, &x);
		for (i=1; i<=x; ++i)
		{
			for (j=1; j<=(d<x ? d : x); ++j)
			{
				dp[i][j] = dp[i-1][j-1];
			}
			for (j=1; i+k<=x&&j<=a; ++j)
			{
				dp[i+k][0] += dp[i][j];
			}
			for (j=1; j<=d; ++j)
			{
				re += dp[i][j];
			}
		}
		printf("%I64d\n", 5*re);
	}
	return 0;
}
