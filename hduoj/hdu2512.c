#include<stdio.h>

int dp[2005][2005] = {{0}};
int ans[2005] = {0};
const int mod = 1000;

int main(void)
{
	int n, x;
	int i, j;

	dp[0][0] = 1;
	for (i=1; i<2001; ++i)
	{
		for (j=1; j<=i; ++j)
		{
			dp[i][j] = (dp[i-1][j-1]+j*dp[i-1][j]) % mod;
			ans[i] = (ans[i]+dp[i][j]) % mod;
		}
	}
	
	while (scanf("%d", &n)!=EOF)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%d", &x);
			printf("%d\n", ans[x]);
		}
	}
	return 0;
}
