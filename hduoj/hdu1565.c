#include<stdio.h>

int state[20001];
int sum[25][20001];

int main(void)
{
	int n;
	int a[25][25];
	int states;
	int i, j, k, l;

	while (scanf("%d", &n)!=EOF)
	{
		// 预处理所有合法状态
		for (i=0, states=0; i < 1<<n; ++i)
		{
			if ((i&(i<<1))==0)
			{
				state[states] = i;
				++states;
			}
		}
		
		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				scanf("%d", &a[i][j]);
			}
		}

		for (i=1; i<=n; ++i)
		{
			for (j=0; j<states; ++j)
			{
				sum[i][j] = 0;
				for (k=0; k<states; ++k)
				{
					if ((state[j]&state[k]) == 0 && sum[i][j] < sum[i-1][k])
					{
						sum[i][j] = sum[i-1][k];
					}
				}
				
				for (k=state[j], l=1; k!=0; k>>=1, ++l)
				{
					if ((k&1) != 0)
					{
						sum[i][j] += a[i][l];
					}
				}
			}
		}
		
		sum[n+1][0] = 0;
		for (k=0; k<states; ++k)
		{
			if (sum[n+1][0] < sum[n][k])
			{
				sum[n+1][0] = sum[n][k];
			}
		}
		printf("%d\n", sum[n+1][0]);
	}
	
	return 0;
}
