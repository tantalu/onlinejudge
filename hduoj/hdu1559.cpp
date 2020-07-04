#include<cstdio>
#include<cstring>

using namespace std;

int sum[1005][1005];

int main(void)
{
    int t;    
    scanf("%d", &t);
    for (int k=0; k<t; ++k)
    {
        int m, n, x, y; 
        scanf("%d%d%d%d", &m, &n, &x, &y);
        memset(sum, 0, sizeof(sum));
        for (int i=1; i<=m; ++i)
        {
            for (int j=1; j<=n; ++j)
            {
                scanf("%d", &cur);
                sum[i][j] = cur + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
            }
        }
        
        int maxx = 0;
        for (int i=x; i<=m; ++i)
        {
            for (int j=y; j<=n; ++j)
            {
                int cur = sum[i][j] - sum[i-x][j] - sum[i][j-x] + sum[i-x][j-y];
                if (cur > maxx)
                {
                    maxx = cur;
                }
            }
        }
        printf("%d\n", maxx);
    }

    return 0;
}