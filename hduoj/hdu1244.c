#include<stdio.h>
#include<string.h>

#define Max(a, b) ((a)>(b)?(a):(b))

int l[25];
int a[1005][1005] = {{0}};
int dp[25][1005] = {{0}};

int main(void)
{
	int m, n;
	int i, j;
	int len;

	while (scanf("%d", &n) !=EOF && n!=0)
	{
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		
		scanf("%d", &m);
		for (i=1; i<=m; ++i)
		{
			scanf("%d", &l[i]);
		}
		for (i=1; i<=n; ++i)
		{
			scanf("%d", &a[i][1]);
		}

		for (i=1; i<n; ++i)
		{
			for (j=2; i+j-1<=n; ++j)
			{
				a[i][j] = a[i][j-1] + a[i+j-1][1];
			}
		}
		
		len = 0;
		for (i=1; i<=m; ++i)
		{
			len += l[i];
			for (j=len; j<=n; ++j)
			{
				dp[i][j] = Max(dp[i][j-1], dp[i-1][j-l[i]]+a[j-l[i]+1][l[i]]);
			}
		}
		printf("%d\n", dp[m][n]);
	}
	return 0;
}

