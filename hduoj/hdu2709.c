#include<stdio.h>

int num[1000005] = {1, 1};

int main(void)
{
	int n;
	int i;
	for (i=2; i<1000001; i+=2)
	{
		num[i+1] = num[i] = (num[i-2] + num[i/2]) % 1000000000;
	}

	while (scanf("%d", &n)!=EOF)
	{
		printf("%d\n", num[n]);
	}
	return 0;
}
