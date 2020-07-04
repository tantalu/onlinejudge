#include<cstdio>
#include<set>

using namespace std;

struct Point
{
	int x, y;
};
// setĞèÒªÖØÔØ<
bool operator<(const struct Point a, const struct Point b)
{
	if (a.x < b.x || (a.x==b.x && a.y < b.y))
	{
		return true;
	}
	return false;
}

int main(void)
{
	int m, n;
	set<struct Point> s;
	struct Point p, q;
	int re;
	
	scanf("%d", &m);
	for (int i=0; i<m; ++i)
	{
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
		{
			scanf("%d%d", &p.x, &p.y);
			s.insert(p);
		}
		
		re = 0;
		for (set<struct Point>::iterator it1=s.begin(); it1!=s.end(); ++it1)
		{
			for (set<struct Point>::iterator it2=it1; it1->x==it2->x; ++it2)
			{
				if (it1->y != it2->y)
				{
					int d = it2->y - it1->y;
					p.x = it1->x + d;
					p.y = it1->y;
					q.x = it1->x + d;
					q.y = it2->y;
					if (s.find(p)!=s.end() && s.find(q)!=s.end())
					{
						++re;
					}
				}
			}
		}
		printf("%d\n", re);
		s.clear();
	}
	
    return 0;
}
