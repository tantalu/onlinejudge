#include<stdio.h>

int fa[1005];
int num[1005];

int find(int n)
{
	if (n==fa[n])
	{
		return n;
	}
	else
	{
		return fa[n] = find(fa[n]);
	}
}

void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x!=y)
	{
		fa[y] = x;
		num[y] = 0;
	}
}

int main(void)
{
	int t, n, m;
	int re;
	int x, y, i;
	
	scanf("%d", &t);
	for (; t!=0; --t)
	{
		scanf("%d%d", &n, &m);
		for (i=1; i<=n; ++i)
		{
			fa[i] = i;
			num[i] = 1;
		}
		
		for (i=0; i<m; ++i)
		{
			scanf("%d%d", &x, &y);
			uni(x, y);
		}
		
		re = 0;
		for (i=1; i<=n; ++i)
		{
			re += num[i];
		}
		printf("%d\n", re);
	}

    return 0;
}
