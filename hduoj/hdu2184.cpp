// 类似于递归输出移动顺序，根据当前情况判断移动到哪一步
#include<cstdio>
#include<vector>

using namespace std;

vector<int> v[4];

void judge(unsigned long long m, int n, int from, int to)
{
	if (n==0)
	{
		return;
	}
	if (m < 1ull<<(n-1))
	{
		v[from].push_back(n);
		judge(m, n-1, from, 6-from-to);
	}
	else
	{
		v[to].push_back(n);
		judge(m-(1ull<<(n-1)), n-1, 6-from-to, to);
	}
}

int main(void)
{
	int t, n;
	unsigned long long m;

	while (scanf("%d", &t)!=EOF)
	{
		for (int k=0; k<t; ++k)
		{
  			for (int i=1; i<4; ++i)
			{
				v[i].clear();
			}
			scanf("%d%I64d", &n, &m);
			judge(m, n, 1, 3);
			for (int i=1; i<4; ++i)
			{
				printf("%d", v[i].size());
				for (size_t j=0; j<v[i].size(); ++j)
				{
					printf(" %d", v[i][j]);
				}
				printf("\n");
			}
		}
	}

	return 0;
}
