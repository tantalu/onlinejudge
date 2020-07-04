#include<stdio.h>
int fa[100005];
int num[100005];	// 数据欺诈根本就没有10000000

int find(int a)
{
	if (a==fa[a])
	{
		return a;
	}
	else
	{
		return fa[a] = find(fa[a]);
	}
}

void uni(int a, int b)
{
	int ffa = find(a);
	int ffb = find(b);
	if (ffa!=ffb)
	{
		fa[ffb] = ffa;
		num[ffa] += num[ffb];
	}
}

int main(void)
{
	int n, boys;
	int l, r, max;
	int i;
	
	while (scanf("%d", &n)!=EOF)
	{
		if (n==0)               // 原来是因为这个坑
		{
			printf("1\n");
			continue;
		}
		
		for (i=1; i<100001; ++i)
		{
			fa[i] = i;
			num[i] = 1;
		}
		
		max = 0;
		for (i=0; i<n; ++i)
		{
			scanf("%d%d", &l, &r);
			uni(l, r);
			if (l>max)
			{
				max = l;
			}
			if (r>max)
			{
				max = r;
			}
		}

		boys = 0;
		for (i=1; i<=max; ++i)
		{
			if (num[i] > boys)
			{
				boys = num[i];
			}
		}
		printf("%d\n", boys);
	}

    return 0;
}
