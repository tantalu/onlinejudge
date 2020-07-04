#include<algorithm>
#include<cstdio>

using namespace std;

struct edge
{
	int u, v, c;
}e[100005];

bool cmp(edge a, edge b)
{
	return a.c>b.c;
}

int fa[10005];
bool loop[10005];

int find(int n)
{
	if (n==fa[n])
	{
		return n;
	}
	return fa[n] = find(fa[n]);
}

int main(void)
{
	int n, m;
	while (scanf("%d%d", &n, &m)&&(n||m))
	{
		for (int i=0; i<n; ++i)
		{
			fa[i] = i;
			loop[i] = false;
		}
		for (int i=0; i<m; ++i)
		{
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
		}
		sort(e, e+m, cmp);
		
		int re = 0;
		for (int i=0; i<m; ++i)
		{
			int x = find(e[i].u);
			int y = find(e[i].v);
			// 连通但没有形成圈
			if (x==y&&!loop[x])
			{
				loop[x] = true;
				re += e[i].c;
			}
			// 未连通，两端都没有圈
			if (x!=y&&!(loop[x]&&loop[y]))
			{
				fa[y] = x;
				loop[x] = loop[x]||loop[y];
				re += e[i].c;
			}
		}
		printf("%d\n", re);
	}
    return 0;
}
