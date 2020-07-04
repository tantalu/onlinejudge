#include<stdio.h>

const int mod = 200907;

long long qpow(long long a, long long n)
{
	long long re = 1;
	while (n!=0)
	{
		if (n%2==1)
		{
			re *= a;
			re %= mod;
		}
		a *= a;
		a %= mod;
		n /= 2;
	}
	return re;
}

int main(void)
{
	long long a, b, c;
	int n, t;
	
	scanf("%d", &t);
	while (t-- != 0)
	{
		scanf("%I64d%I64d%I64d%d", &a, &b, &c, &n);
		if (b-a==c-b)
		{
			printf("%I64d\n", (a+(b-a)%mod*(n-1)%mod)%mod);
		}
		else
		{
			printf("%I64d\n", a*qpow(b/a, n-1)%mod);
		}
	}
	return 0;
}
