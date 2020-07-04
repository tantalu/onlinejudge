#include<cstdio>
#include<queue>

using namespace std;

int n, m;
int graph[105][105];        // 邻接表

int DFS(int s)
{
	int dis[105];               // 单源最短距离
	bool visit[105];
	queue<int> q;
	
	for (int j=1; j<=n; ++j)
	{
		visit[j] = false;
	}
	q.push(s);
	visit[s] = true;
	dis[s] = 0;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();

		for (int j=1; j<=n; ++j)
		{
			if (graph[p][j]!=0 && !visit[j])
			{
				q.push(j);
				visit[j] = true;
				dis[j] = dis[p] + 1;
			}
		}
	}

	// 计算和
	int sum = 0;
	for (int j=1; j<=n; ++j)
	{
		if (!visit[j])
		{
			return -1;
		}
		sum += dis[j];
	}
	return sum;
}

int main(void)
{
	int edge[3005][2];          // 边
	int sum[105];               // 单源最短距离和
	
	while (scanf("%d%d", &n, &m) !=EOF)
	{
		for (int i=1; i<=n; ++i)
		{
			for (int j=1; j<=n; ++j)
			{
				graph[i][j] = 0;
			}
		}
		for (int i=1; i<=m; ++i)
		{
			scanf("%d%d", &edge[i][0], &edge[i][1]);
			++graph[edge[i][0]][edge[i][1]];        // 会不止一条边
			++graph[edge[i][1]][edge[i][0]];
		}
		
		int re = 0;
		for (int i=1; i<=n; ++i)
		{
			sum[i] = DFS(i);
			re += sum[i];
		}
		// 每条边
		for (int i=1; i<=m; ++i)
		{
			const int l = edge[i][0];
			const int r = edge[i][1];
   			// 删边
			--graph[l][r];
			--graph[r][l];

			int suml = DFS(l);
			int sumr = DFS(r);
			// 恢复边
			++graph[l][r];
			++graph[r][l];
			if (suml==-1 || sumr==-1)
			{
				printf("INF\n");
			}
			else
			{
				printf("%d\n", re-sum[l]+suml-sum[r]+sumr);        // 证明不能
			}
		}
	}

    return 0;
}
/*
		// 初始状况
  		for (int i=1; i<=n; ++i)
		{
			// DFS
			for (int j=1; j<=n; ++j)
			{
				visit[j] = false;
			}
			q.push(i);
			visit[i] = true;
			dis[i] = 0;
			pre[i][i] = 0;
			while (!q.empty())
			{
				int p = q.front();
				q.pop();
				
				for (int j=1; j<=n; ++j)
				{
					if (graph[p][j]!=0 && !visit[j])
					{
						q.push(j);
						visit[j] = true;
						dis[j] = dis[p] + 1;
						pre[i][j] = p;
					}
				}
			}
			
			// 计算和
			sum[i] = 0;
			for (int j=1; j<=n; ++j)
			{
				if (!visit[j])
				{
					break;
				}
				sum[i] += dis[j];
			}
		}

		// 每一条边
		for (int i=1; i<=m; ++i)
		{
			bool connected = true;	}
			const int r = edge[i][1];
   			// 删边
			--graph[l][r];
			--graph[r][l];
			int re = 0;
			// 每一顶点
			for (int j=1; j<=n; ++j)
			{
				// 没用到该边，直接相加
				if (pre[j][l]!=r && pre[j][r]!=l)
				{
					re += sum[j];
					continue;
				}
				// 否则 DFS
				for (int k=1; k<=n; ++k)
				{
					visit[k] = false;
				}
				q.push(j);
				visit[j] = true;
				dis[j] = 0;
				while (!q.empty())
				{
					int p = q.front();
					q.pop();
					for (int k=1; k<=n; ++k)
					{
						if (graph[p][k]!=0 && !visit[k])
						{
							q.push(k);
							visit[k] = true;
							dis[k] = dis[p] + 1;
						}
					}
				}
				
				// 计算和
				int sum = 0;
				for (int k=1; k<=n; ++k)
				{
					if (!visit[k])
					{
						connected = false;printf("**e:%ds:%dd:%d", i, j, k);
						break;
					}
					else
					{
						sum += dis[k];
					}
				}
				re += sum;
			}
			// 恢复边
			++graph[l][r];
			++graph[r][l];
			
			// 不连通
			if (!connected)
			{
				printf("INF\n");
			}
			else
			{
				printf("%d\n", re);
			}
		}
*/

