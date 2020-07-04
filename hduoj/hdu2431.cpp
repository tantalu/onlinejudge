#include<stdio.h>

int a[505][505] = {{1, 0}};

int main(void)
{
	int t, n;
	int i, j;
	
	for (i=2; i<501; ++i)
	{
		for (j=2; j<=i; ++j)
		{
			if (i-j < j)
			{
				a[i][j] = (a[i][j-1] + a[i-j][i-j]) %1000007;
			}
			else
			{
				a[i][j] = (a[i][j-1] + a[i-j][j]) %1000007;
			}
		}
	}
	
	scanf("%d", &t);
	for (i=0; i<t; ++i)
	{
		scanf("%d", &n);
		printf("%d\n", a[n][n]);
	}
	return 0;
}
