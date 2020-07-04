// 水水的最大子序列和，把所有和为正数的子序列都找出来就好了
#include<cstdio>

using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; ++i)
    {
        int n;
        scanf("%d", &n);
        long long sum = 0;
        int sub = 0;
        for (int j=0; j<n; ++j)
        {
            int m;
            scanf("%d", &m);
            // 大于0，开始一个新的子序列
            if (m <= 0)
            {
                continue;
            }
            ++sub;
            sum += m;
            for (++j; j<n; ++j)
            {
                scanf("%d", &m);
                // 满足最少，所以两个子序列间可以用0连接
                if (m < 0)
                {
                    break;
                }
                sum += m;
            }
        }
        printf("Case %d:\n%d %I64d%s", i, sub, sum, i==t?"\n":"\n\n");
    }
    return 0;
}
