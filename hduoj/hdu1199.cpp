#include<cstdio>
#include<list>

using namespace std;
struct segment
{
	int l, r;
};

int main()
{
	list<struct segment> w;
	int n;
	struct segment s;
 	char c;
	int l, r, len, maxlen;
	
	while (scanf("%d", &n) !=EOF)
	{
		for (int i=0; i<n; ++i)
		{
			scanf("%d %d %c", &s.l, &s.r, &c);

			if (c=='w')
			{
				list<struct segment>::iterator it;
				for (it=w.begin(); it!=w.end(); ++it)
				{
					if (it->r+1 >= s.l)
					{
						if (it->l < s.l)
						{
							s.l = it->l;
						}
						break;
					}
				}
				w.insert(it, s);
				
				list<struct segment>::iterator now = it;
				--now;
				for (; it!=w.end(); ++it)
				{
					if (s.r+1 < it->l)
					{
						break;
					}
					now->r = s.r>it->r ? s.r : it->r;
					w.erase(it);
					it = now;
				}
			}
			else if (c=='b')
			{
				list<struct segment>::iterator it;
				for (it=w.begin(); it!=w.end(); ++it)
				{
					if (it->r >= s.l)
					{
						if (it->l < s.l)
						{
							w.insert(it, *it);
							--it;
							it->r = s.l-1;
							++it;
						}
						break;
					}
				}
				
				if (it==w.end())
				{
					continue;
				}
				else if (it==w.begin())
				{
					for (it=w.begin(); it!=w.end(); it=w.begin())
					{
						if (s.r < it->r)
						{
							if (s.r > it->l)
							{
								it->l = s.r+1;
							}
							break;
						}
						w.erase(it);
					}
				}
				else
				{
					list<struct segment>::iterator pre = it;
					for (--pre; it!=w.end(); ++it)
					{
						if (s.r < it->r)
						{
							if (s.r > it->l)
							{
								it->l = s.r+1;
							}
							break;
						}
						w.erase(it);
		 				it = pre;
					}
				}
			}
		}

		maxlen = -1;
		for (list<struct segment>::iterator it=w.begin(); it!=w.end(); ++it)
		{
			len = it->r - it->l;
			if (len > maxlen)
			{
				maxlen = len;
				l = it->l;
				r = it->r;
			}
		}
		if (maxlen != -1)
		{
			printf("%d %d\n", l, r);
		}
		else
		{
			printf("Oh, my god\n");
		}
		w.clear();
	}
	return 0;
}
