#include<cstdio>
#include<queue>

using namespace std;

bool visited[100005];
deque<int> qs;
deque<int> ql;

int BFS(int n, int k)
{
	for (int i=0; i<=100000; ++i)
	{
		visited[i] = false;
	}
	qs.clear();
	ql.clear();
	qs.push_back(n);
	ql.push_back(0);
	while (!qs.empty())
	{
		int s = qs.front();qs.pop_front();
		int l = ql.front();ql.pop_front();
		if (s<0||s>100000||visited[s])    // 这个条件网上各不相同，好害人啊
		{
			continue;
		}
		visited[s] = true;
		
		if (s==k)
		{
			return l;
		}
		else if(s>k)
		{
			qs.push_back(s-1);
			ql.push_back(l+1);
		}
		else
		{
			qs.push_back(s-1);
			ql.push_back(l+1);
			qs.push_back(s+1);
			ql.push_back(l+1);
			qs.push_back(s*2);
			ql.push_back(l+1);
		}
	}
	return -1;
}

int main(void)
{
	int n, k;
	while (scanf("%d%d", &n, &k)!=EOF)
	{
		if (n>k)
		{
			printf("%d\n", n-k);
		}
		else
		{
			printf("%d\n", BFS(n, k));
		}
	}
	
    return 0;
}
