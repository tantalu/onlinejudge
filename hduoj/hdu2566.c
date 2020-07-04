#include<stdio.h>

int main(void)
{
	int t, n, m;
	int re;
	
	scanf("%d", &t);
	while(t-->0)
	{
		scanf("%d%d", &n, &m);
		if (m < n)
		{
			re = 0;
		}
		else
		{
			re = (m - n) / 4 + 1;
			// 计算至少要几个五分的
			if (m > 2*n)
			{
				if ((m-2*n) % 3 ==0)
				{
					re -= (m-2*n) / 3;
				}
				else
				{
					re -= (m-2*n) / 3 + 1;
				}
			}
		}
		printf("%d\n", re);
	}

	return 0;
}
