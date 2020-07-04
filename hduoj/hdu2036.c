#include<stdio.h>

int main(void)
{
	int n;
	int x[105], y[105];
	int i;
	double sum;
	
	while (scanf("%d", &n)!=EOF && n!=0)
	{
		sum = 0.0;
		scanf("%d%d", &x[0], &y[0]);
		scanf("%d%d", &x[1], &y[1]);
		for (i=2; i<n; ++i)
		{
			scanf("%d%d", &x[i], &y[i]);
			sum += ((x[i-1]-x[0]) * (y[i]-y[0]) - (x[i]-x[0]) * (y[i-1]-y[0]))/2.0;     //向量外积
		}
		printf("%.1f\n", sum);
	}
	
    return 0;
}
