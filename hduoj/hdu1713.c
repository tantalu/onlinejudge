#include<stdio.h>
// 周期居然是圈数不是时间
int gcd(int a, int b)
{
	int t;
	if (a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	while ((t = a%b)!=0)
	{
		a = b;
		b = t;
	}
	return b;
}

int lcm(int a, int b)
{
	return a/gcd(a, b)*b;
}

int main(void)
{
	int n;
	int r1, r2, d1, d2;
	int a, b, t, i;
	
	scanf("%d", &n);
	for (i=0; i<n; ++i)
	{
		scanf("%d/%d %d/%d", &r1, &d1, &r2, &d2);

		if ((t=gcd(r1, d1) )!=1)
		{
			r1 /= t;
			d1 /= t;
		}
		if ((t=gcd(r2, d2) )!=1)
		{
			r2 /= t;
			d2 /= t;
		}
		
		a = lcm(r1, r2);
		b = gcd(d1, d2);
		if ((t=gcd(a, b) )!=1)
		{
			a /= t;
			b /= t;
		}
		if (b!=1)
		{
			printf("%d/%d\n", a, b);
		}
		else
		{
			printf("%d\n", a);
		}
	}

	return 0;
}
