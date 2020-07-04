// ��4��������С��i-j�飬3���ƴ��j�飬DP
#include<stdio.h>
#include<limits.h>

long long num[66] = {0, 1};

int main(void)
{
	int n;
	int i, j;
	for (i=2; i<65; ++i)
	{
		num[i] = LONG_LONG_MAX;
	  	for (j=1; j<i; ++j)
	  	{
		   	if (num[i] >= 2*num[i-j] + (1ll<<j)-1)
		   	{
			    num[i] = 2*num[i-j] + (1ll<<j)-1;
	 	   	}
	 	   	else
	 	   	{
	 	   		break;
	 	   	}
	  	}
	}
	
	while (scanf("%d", &n)!=EOF)
	{
		printf("%I64d\n", num[n]);
	}
	
	return 0;
}
