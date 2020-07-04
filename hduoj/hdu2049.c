#include<stdio.h>

int main(void)
{
	long long s[21][21] = {{0},{1}};
	int c, m, n;
	int i, j;

	for (i=2; i<21; ++i)
	{
		s[i][0] = 1;
		for (j=2; j<21; ++j)
		{
			s[i][j] = (i-j+1)*s[i-1][j-2] + (j-1)*s[i-1][j-1] + s[i-1][j];
		}
	}

	scanf("%d", &c);
	for (i=0; i<c; ++i)
	{
		scanf("%d%d", &n, &m);
		printf("%I64d\n", s[n][m]);
		// or Complex(m, n) * Derangenment(m)
	}
	return 0;
}
