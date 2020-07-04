// a[n] = 2*a[n-1]+a[n-2]
#include<stdio.h>

int main(void)
{
	long long a[25][2] = {{1, 0}};
	int t, n, i;
	
	for (i=1; i<21; ++i)
	{
		a[i][0] = a[i-1][0] + a[i-1][1];
		a[i][1] = 2*a[i-1][0] + a[i-1][1];
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%I64d\n", a[n][0]+a[n][1]);
	}

	return 0;
}
