#include<stdio.h>

int fa[10005];
int num[10005];

int find(int n)
{
	if (n==fa[n])
	{
		return n;
	}
	else
	{
		return find(fa[n]);
	}
}

int tran(int n)
{
	if (n==fa[n])
	{
		return 0;
	}
	else
	{
		return 1+tran(fa[n]);
	}
}

void uni(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x!=y)
	{
		fa[x] = y;
		num[y] += num[x];
		num[x] = 0;
	}
}

int main(void)
{
	int t, n, q;
	char s[5];
	int a, b, city;
	int i, j;
	
	scanf("%d", &t);
	for (j=1; j<=t; ++j)
	{
		scanf("%d%d", &n, &q);
		for (i=1; i<=n; ++i)
		{
			fa[i] = i;
			num[i] = 1;
		}
		printf("Case %d:\n", j);
		
		for (i=0; i<q; ++i)
		{
			scanf("%s", s);
			if (s[0]=='T')
			{
				scanf("%d%d", &a, &b);
				uni(a, b);
			}
			else if(s[0]=='Q')
			{
				scanf("%d", &a);
				city = find(a);
				printf("%d %d %d\n", city, num[city], tran(a));
			}
		}
	}

    return 0;
}
