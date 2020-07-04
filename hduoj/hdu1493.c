#include<stdio.h>
#include<string.h>

int main(void)
{
	double p[10];
	int n;
	double dp[11][61];
	int ans[10] = {5, 12, 22, 29, 33, 38, 42, 46, 50, 55};
	double re;
	int i, j, k;
	
	while (scanf("%d", &n)!=EOF)
	{
		for (; n!=0; --n)
		{
			for (i=1; i<=6; ++i)
			{
				scanf("%lf", &p[i]);
			}

			for (i=0; i<11; ++i)
			{
				for (j=0; j<61; ++j)
				{
					dp[i][j] = 0.0;
				}
			}
			dp[0][0] = 1.0;
			for (i=0; i<10; ++i)
			{
				for (j=i; j<=6*i; ++j)
				{
					for (k=1; k<=6; ++k)
					{
						dp[i+1][j+k] += p[k]*dp[i][j];
					}
				}
			}
			for (i=0; i<10; ++i)
			{
				re = 0;
				for (j=1; j<=10; ++j)
				{
					re += dp[j][ans[i]];
				}
				printf("%d: %.1f%%\n", ans[i], 100*re);
			}
			if (n!=1)
			{
				printf("\n");
			}
		}
	}
    return 0;
}
