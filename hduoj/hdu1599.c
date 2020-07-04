#include<stdio.h>
#include<string.h>

int map[105][105];
int dist[105][105];

int main(void)
{
	int n, m;
	int a, b, c;
	int mincircle;
	int i, j, k;
	
	while (scanf("%d%d", &n, &m)!=EOF)
	{
		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=n; ++j)
			{
				map[i][j] = dist[i][j] = 65535;
			}
		}
		for (i=0; i<m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (map[a][b]>c)
			{
				map[a][b] = map[b][a] = c;
				dist[a][b] = dist[b][a] = c;
			}
		}
		mincircle = 20000;
		for (k=1; k<=n; ++k)
		{
			// 过k点的环
			for (i=1; i<k; ++i)
			{
				for (j=i+1; j<k; ++j)
				{
					if (mincircle > dist[i][j]+map[j][k]+map[k][i])
					{
						mincircle = dist[i][j]+map[j][k]+map[k][i];
					}
				}
			}
			for (i=1; i<=n; ++i)
			{
				for (j=1; j<=n; ++j)
				{
					if (dist[i][j] > dist[i][k]+dist[k][j])
					{
						dist[i][j] = dist[i][k]+dist[k][j];
					}
				}
			}
		}
		if (mincircle==20000)
		{
			printf("It's impossible.\n");
		}
		else
		{
			printf("%d\n", mincircle);
		}
	}
	
    return 0;
}
