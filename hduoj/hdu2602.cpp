#include<algorithm>
#include<cstdio>

using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t-->0)
    {
        int n, v;
        scanf("%d%d", &n, &v);
        int value[1005];
        int volume[1005];
        for (int i=1; i<=n; ++i)
        {
            scanf("%d", &value[i]);
        }
        for (int i=1; i<=n; ++i)
        {
        	scanf("%d", &volume[i]);
        }

		int dp[1005];
		for (int i=0; i<=v; ++i)
		{
			dp[i] = 0;
		}
        for (int i=1; i<=n; ++i)
        {
        	for (int j=v; j>=volume[i]; --j)
        	{
        		dp[j] = max(dp[j], dp[j-volume[i]]+value[i]);
        	}
        }
        printf("%d\n", dp[v]);
    }
    return 0;
}
