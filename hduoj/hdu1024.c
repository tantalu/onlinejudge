#include<stdio.h>
#include<limits.h>

#define Max(a, b) ((a)>(b)?(a):(b))

int a[1000005];
int s[1000005] = {0};
int max[1000005] = {0};

int main(void)
{
	int m, n;
	int i, j;
	int temp;
	
	while (scanf("%d%d", &m, &n) !=EOF)
	{
		for (i=1; i<=n; ++i)
		{
			scanf("%d", &a[i]);
			s[i] = max[i] = 0;
		}
		
		for (i=1; i<=m; ++i)
		{
			temp = max[i-1] = INT_MIN;
			for (j=i; j<=n; ++j)
			{
				s[j] = Max(temp, s[j-1])+a[j];
				temp = max[j];
				max[j] = Max(max[j-1], s[j]);
			}
		}
		printf("%d\n", max[n]);
	}
	return 0;
}
