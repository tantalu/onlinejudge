// friend numbers = 2^x + 3^y - 1
// 找不了规律只好打表了
#include<cstdio>
#include<set>

using namespace std;

int main(void)
{
	set<long long> s;
	s.insert(1);
	s.insert(2);
	for (set<long long>::iterator it=s.begin(); *it<1<<30; ++it)
	{
		for (set<long long>::iterator it2=it; *it2<1<<30; ++it2)
		{
			s.insert((*it+1)*(*it2+1)-1);
		}
	}
	
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		printf("%s", s.find(n)!=s.end() ? "YES!\n" : "NO!\n");
	}
	return 0;
}
