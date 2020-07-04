// 类似于递归输出移动顺序，根据当前情况判断移动到哪一步
#include<stdio.h>

int num[66];

int judge(int n, int from, int to)
{
	if (n==0)
	{
		return 1;
	}
	else if (num[n] == from)
	{
		return judge(n-1, from, 6-from-to);
	}
	else if (num[n] == to)
	{
		return judge(n-1, 6-from-to, to);
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int t, n, m, a;
	int i, j, k;

	while (scanf("%d", &t)!=EOF)
	{
		for (i=0; i<t; ++i)
		{
			scanf("%d", &n);
			for (j=1; j<=3; ++j)
			{
				scanf("%d", &m);
				for (k=0; k<m; ++k)
				{
					scanf("%d", &a);
					num[a] = j;
				}
			}
			
			printf("%s\n", judge(n, 1, 3) ? "true" : "false");
		}
	}
	
	return 0;
}
