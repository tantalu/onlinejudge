#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int f[100005];
	int n, l, r;
	int k, maxk;
	int i;
	
	while (scanf("%d", &n) != EOF)
	{
		maxk = 0;
		scanf("%d", &f[0]);
		for (i=1; i<n; ++i)
		{
			scanf("%d", &f[i]);
			k = abs(f[i]-f[i-1]); // 必然是相邻两个
			if (k > maxk)
			{
				maxk = k;
				l = i;
				r = i+1;
			}
		}
		printf("%d %d\n", l, r);
	}
	return 0;
}
