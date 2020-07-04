#include<cstdio>

using namespace std;

int vote[100005];
int fa[100005];

int find(int n)
{
	return n==fa[n] ? n : find(fa[n]);
}

void uni(int a, int b)
{
	// 投自己
	if (a == b)
	{
		++vote[a];
		return;
	}
	
	int n = find(b);
	// 成环，将票投到无效区
	if (a == n)
	{
		n = 100001;
	}
	vote[n] += vote[a]+1;
	vote[a] = 0;
	fa[a] = n;
}

int main(void)
{
	fa[100001] = 100001;
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		for (int i=0; i<n; ++i)
		{
			fa[i] = i;
			vote[i] = 0;
		}
		
		for (int i=0; i<n; ++i)
		{
			int m;
			scanf("%d", &m);
			uni(i, m);
		}
		
		int max = 0;
		int m = -1;
		for (int i=0; i<n; ++i)
		{
			if (max < vote[i])
			{
				max = vote[i];
				m = i;
			}
			else if (max == vote[i])
			{
				m = -1;
			}
		}
		if (m == -1)
		{
			printf("Trouble\n");
		}
		else
		{
			printf("%d\n", m);
		}
	}
	return 0;
}
