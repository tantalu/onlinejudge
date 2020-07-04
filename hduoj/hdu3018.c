#include<stdio.h>

int a[100005];    // 度数
int fa[100005];   // 并查集
int odd[100005];  // 奇度数个数

int find(int i)
{
	if (i==fa[i])
	{
		return i;
	}
	else
	{
		return fa[i] = find(fa[i]);
	}
}

void uni(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if (a!=b)
	{
		fa[b] = a;
	}
}

int main(void)
{
	int n, m;
	int re;
	int x, y;
	int i;
	
	while (scanf("%d%d", &n, &m)!=EOF)
	{
		for (i=1; i<=n; ++i)
		{
			a[i] = 0;
			fa[i] = i;
			odd[i] = 0;
		}
		for (i=0; i<m; ++i)
		{
			scanf("%d%d", &x, &y);
			uni(x, y);
			a[x]++;
			a[y]++;
		}

		// 每个连通分支内奇度数个数
		for (i=1; i<=n; ++i)
		{
			odd[find(i)] += a[i]%2;
		}
		
		re = 0;
		for (i=1; i<=n; ++i)
		{
			if (i==find(i) && a[i]!=0)  // 没路的话就无视之
			{
				re += odd[i]==0 ? 1 : odd[i]/2;
			}
		}
		printf("%d\n", re);
	}

    return 0;
}
