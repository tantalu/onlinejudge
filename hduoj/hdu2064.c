// С��n-1���1��3����Ĵ�1��2��С��n-1���3��1����Ĵ�2��3��С��n-1���1��3��3^n-1
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
