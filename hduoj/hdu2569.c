// all[n] = 2*a[n-1]+a[n-2]
#include<stdio.h>

int main(void)
{
	long long m[45][9]={{0}};
	long long all[45] = {0,3};
	int n, t, i, j;

	m[1][0] = m[1][4] = m[1][8] = 1;
	for (i=2; i<41; ++i)
	{
		m[i][0] = m[i-1][0] + m[i-1][3] + m[i-1][6];
		m[i][1] = m[i-1][0] + m[i-1][3];
		m[i][2] = m[i-1][0] + m[i-1][6];
		m[i][3] = m[i-1][1] + m[i-1][4];
		m[i][4] = m[i-1][1] + m[i-1][4] + m[i-1][7];
		m[i][5] = m[i-1][4] + m[i-1][7];
		m[i][6] = m[i-1][2] + m[i-1][8];
		m[i][7] = m[i-1][5] + m[i-1][8];
		m[i][8] = m[i-1][2] + m[i-1][5] + m[i-1][8];
		all[i] = 0;
		for (j=0; j<9; ++j)
		{
			all[i] += m[i][j];
		}
	}

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%I64d\n", all[n]);
	}

	return 0;
}
