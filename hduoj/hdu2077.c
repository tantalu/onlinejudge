// 分为从1到2从1到3两种，最后小的n-1块1-2，大的1-2-3，小的n块2-3，2*a[n-1]+2
// 1到2: 小的n-1块从1到3，大的从1到2，小的n-1块从3到2，(3^n-1)/2
// 1到3: 小的n-1块从1到3，大的从1到2，小的n-1块从3到1，大的从2到3，小的n-1块从1到3，3^n-1
#include<stdio.h>

long long b[22] = {0};
long long a[22] = {0};

int main(void)
{
	int t, n;
	int i;
	for (i=1; i<21; ++i)
	{
		b[i] = 3*b[i-1] + 2;
		a[i] = a[i-1] + b[i-1] + 1;
	}
	
	while (scanf("%d", &t)!=EOF)
	{
		for (i=0; i<t; ++i)
		{
			scanf("%d", &n);
			printf("%I64d\n", 2*a[n-1]+2);
		}
	}
	
	return 0;
}
