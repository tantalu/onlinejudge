// 小的n-1块从1到3，大的从1到2，小的n-1块从3到1，大的从2到3，小的n-1块从1到3，3^n-1
#include<stdio.h>

long long num[40] = {0;

int main(void)
{
	int n;
	int i;
	for (i=1; i<36; ++i)
	{
		num[i] = 3*num[i-1]+2;
	}
	
	while (scanf("%d", &n)!=EOF)
	{
		printf("%I64d\n", num[n]);
	}
	
	return 0;
}
