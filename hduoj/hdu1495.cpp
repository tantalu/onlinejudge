// 另附神奇解法，不明原理
// a%2==1 ? NO : a/gcd(b, c)-1
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int n[105][105];

int main(void)
{
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c)!=EOF && (a||b||c))
	{
		if (a%2!=0)
		{
			printf("NO\n");
			continue;
		}
		
		if (b<c)
		{
			swap(b, c);
		}
		deque<pair<int, int> > q;
		q.clear();
		memset(n, 0, sizeof(n));
		q.push_back(make_pair(0, 0));
		while (!q.empty())
		{
			pair<int, int> p;
			p = q.front();
			q.pop_front();
			if (p.first==a/2&&p.second==0)
			{
				break;
			}
			
			if (n[b][p.second]==0)  // a==>b
			{
				n[b][p.second] = n[p.first][p.second]+1;
				q.push_back(make_pair(b, p.second));
			}
			if (n[p.first][c]==0)  // a==>c
			{
				n[p.first][c] = n[p.first][p.second]+1;
				q.push_back(make_pair(p.first, c));
			}
			if (n[0][p.second]==0)  // b==>a
			{
				n[0][p.second] = n[p.first][p.second]+1;
				q.push_back(make_pair(0, p.second));
			}
			if (n[p.first][0]==0)  // c==>a
			{
				n[p.first][0] = n[p.first][p.second]+1;
				q.push_back(make_pair(p.first, 0));
			}
			if (p.first+p.second<c)  // b==>c
			{
				if (n[0][p.first+p.second]==0)
				{
					n[0][p.first+p.second] = n[p.first][p.second]+1;
					q.push_back(make_pair(0, p.first+p.second));
				}
			}
			else
			{
				if (n[p.first+p.second-c][c]==0)
				{
					n[p.first+p.second-c][c] = n[p.first][p.second]+1;
					q.push_back(make_pair(p.first+p.second-c, c));
				}
			}
			if (p.first+p.second<b)  // c==>b
			{
				if (n[p.first+p.second][0]==0)
				{
					n[p.first+p.second][0] = n[p.first][p.second]+1;
					q.push_back(make_pair(p.first+p.second, 0));
				}
			}
			else
			{
				if (n[b][p.first+p.second-b]==0)
				{
					n[b][p.first+p.second-b] = n[p.first][p.second]+1;
					q.push_back(make_pair(b, p.first+p.second-b));
				}
			}
		}
		if (n[a/2][0]!=0)
		{
			printf("%d\n", n[a/2][0]);
		}
		else
		{
			printf("NO\n");
		}
	}
	
    return 0;
}
