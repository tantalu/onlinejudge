#include<algorithm>
#include<climits>
#include<cstdio>
#include<cstring>

using namespace std;

int w[2005];
long long dp[1005][2005];

int main(void)
{
    int n, k;
    while (scanf("%d%d", &n, &k)!=EOF)
    {
    	for (int i=1; i<=n; ++i)
    	{
			scanf("%d", &w[i]);
    	}
    	sort(w+1, w+n+1);  // ע�ⷶΧ

    	memset(dp, 0, sizeof(dp));
    	for (int i=1; i<=k; ++i)
    	{
    		dp[i][2*i-1] = INT_MAX;
    		for (int j=2*i; j<=n; ++j)
    		{
    			dp[i][j] = min(dp[i][j-1], dp[i-1][j-2]+(w[j]-w[j-1])*(w[j]-w[j-1]));
    		}
    	}
    	printf("%I64d\n", dp[k][n]);
    }
    return 0;
}
