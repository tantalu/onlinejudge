#include<stdio.h>

void judge(unsigned long long m, int n, int from, int to)
{
	if (m == 1ull<<(n-1))
	{
		printf("%d %d %d\n", n, from, to);
		return;
	}
	if (m < 1ull<<(n-1))
	{
		judge(m, n-1, from, 6-from-to);
	}
	else
	{
		judge(m-(1ull<<(n-1)), n-1, 6-from-to, to);
	}
}

int main(void)
{
	int t, n;
	unsigned long long m;
	int i;

	while (scanf("%d", &t)!=EOF)
	{
		for (i=0; i<t; ++i)
		{
			scanf("%d%I64d", &n, &m);
			judge(m, n, 1, 3);
		}
	}

	return 0;
}
