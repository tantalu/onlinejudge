// 正解字典树，因为字符串长度小于60所以可以用位运算搞一搞
#include<algorithm>
#include<cstdio>
#include<map>

using namespace std;

int main(void)
{
    map<long long, int> m;
    int n, l, k;
    while (scanf("%d%d%d", &n, &l, &k)!=EOF)
    {
    	int re = 1;
        m.clear();
        for (int i=0; i<n; ++i)
        {
            char str[65];
            scanf("%s", str);
            
            long long s = 0;
            int j;
            for (j=0; j<=l; ++j)
            {
            	if (j >= k)
            	{
	            	map<long long, int>::iterator it = m.find(s & ((1ll<<k)-1));
	            	if (it == m.end())
	            	{
	            		m.insert(make_pair(s & ((1ll<<k)-1), 1));
	            	}
	            	else
	            	{
	            		++it->second;
	            		re = max(re, it->second);
	            	}
	            }
            	s = (s << 1) + (str[j]=='1' ? 1 : 0);
            }
        }
        printf("%d\n", re);
        for (map<long long, int>::iterator it=m.begin(); it!=m.end(); ++it)
        {
        	printf("%I64d %d\n", it->first, it->second);
        }
    }

    return 0;
}
