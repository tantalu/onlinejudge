#include<algorithm>
#include<cstdio>

using namespace std;

int row[2][200005] = {{0}};// 没限制行列，只限制总数，真是神坑
int col[2][200005] = {{0}};
		
int main(void)
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		for (int i=1; i<=m; ++i)
		{
			for (int j=1; j<=n; ++j)
			{
				int t;
				scanf("%d", &t);
				col[0][j] = max(col[0][j-1], col[1][j-1]);
				col[1][j] = col[0][j-1] + t;
			}
			row[0][i] = max(row[0][i-1], row[1][i-1]);
			row[1][i] = row[0][i-1] + max(col[0][n], col[1][n]);
		}
		printf("%d\n", max(row[0][m], row[1][m]));
	}
	return 0;
}
