#include<algorithm>
#include<cstdio>

using namespace std;

int main(void)
{
	int n;
	int a[1005];
	while (scanf("%d", &n)!=EOF)
	{
		for (int i=0; i<n; ++i)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		
		int re = 0;
		for (int i=0; i<n; ++i)
		{
			re = max(re, a[i]*(n-i));
		}
		printf("%d\n", re);
	}
    return 0;
}
