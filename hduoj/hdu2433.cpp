#include<cstdio>
#include<queue>

using namespace std;

int n, m;
int graph[105][105];        // �ڽӱ�

int DFS(int s)
{
	int dis[105];               // ��Դ��̾���
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

	// �����
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
	int edge[3005][2];          // ��
	int sum[105];               // ��Դ��̾����
	
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
			++graph[edge[i][0]][edge[i][1]];        // �᲻ֹһ����
			++graph[edge[i][1]][edge[i][0]];
		}
		
		int re = 0;
		for (int i=1; i<=n; ++i)
		{
			sum[i] = DFS(i);
			re += sum[i];
		}
		// ÿ����
		for (int i=1; i<=m; ++i)
		{
			const int l = edge[i][0];
			const int r = edge[i][1];
   			// ɾ��
			--graph[l][r];
			--graph[r][l];

			int suml = DFS(l);
			int sumr = DFS(r);
			// �ָ���
			++graph[l][r];
			++graph[r][l];
			if (suml==-1 || sumr==-1)
			{
				printf("INF\n");
			}
			else
			{
				printf("%d\n", re-sum[l]+suml-sum[r]+sumr);        // ֤������
			}
		}
	}

    return 0;
}
/*
		// ��ʼ״��
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
			
			// �����
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

		// ÿһ����
		for (int i=1; i<=m; ++i)
		{
			bool connected = true;	}
			const int r = edge[i][1];
   			// ɾ��
			--graph[l][r];
			--graph[r][l];
			int re = 0;
			// ÿһ����
			for (int j=1; j<=n; ++j)
			{
				// û�õ��ñߣ�ֱ�����
				if (pre[j][l]!=r && pre[j][r]!=l)
				{
					re += sum[j];
					continue;
				}
				// ���� DFS
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
				
				// �����
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
			// �ָ���
			++graph[l][r];
			++graph[r][l];
			
			// ����ͨ
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

