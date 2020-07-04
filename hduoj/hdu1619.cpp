#include<cstdio>
#include<cstring>

using namespace std;

int ma[12][105];
int dp[12][105];
int next[12][105];

int main(void)
{
    int row, col;
    while (scanf("%d%d", &row, &col)!=EOF)
    {
    	for (int i=1; i<=row; ++i)
        {
        	for (int j=1; j<=col; ++j)
            {
            	scanf("%d", &ma[i][j]);
            }
        }

        // 反向DP，同时记录走向
    	memset(dp, 0, sizeof(dp));
    	for (int j=col; j>0; --j)
        {
        	if (dp[2][j+1]<dp[1][j+1])
            {
            	dp[1][j] = dp[2][j+1];
            	next[1][j] = 2;
            }
        	else
            {
            	dp[1][j] = dp[1][j+1];
            	next[1][j] = 1;
            }
        	if (dp[row][j+1]<dp[1][j])
            {
            	dp[1][j] = dp[row][j+1];
            	next[1][j] = row;
            }
        	dp[1][j] += ma[1][j];

        	for (int i=2; i<row; ++i)
            {
            	if (dp[i][j+1]<dp[i-1][j+1])
                {
                	dp[i][j] = dp[i][j+1];
                	next[i][j] = i;
                }
            	else
                {
                	dp[i][j] = dp[i-1][j+1];
                	next[i][j] = i-1;
                }
            	if (dp[i+1][j+1]<dp[i][j])
                {
                	dp[i][j] = dp[i+1][j+1];
                	next[i][j] = i+1;
                }
            	dp[i][j] += ma[i][j];
            }

        	if (dp[row-1][j+1]<dp[1][j+1])
            {
            	dp[row][j] = dp[row-1][j+1];
            	next[row][j] = row-1;
            }
        	else
            {
            	dp[row][j] = dp[1][j+1];
            	next[row][j] = 1;
            }
        	if (dp[row][j+1]<dp[row][j])
            {
            	dp[row][j] = dp[row][j+1];
            	next[row][j] = row;
            }
            dp[row][j] += ma[row][j];
        }

		// 找最小路径
    	int minpath = 1;
    	for (int i=1; i<=row; ++i)
        {
            if (dp[i][1]<dp[minpath][1])
            {
            	minpath = i;
            }
        }
        // 根据记录的路径走一遍输出，注意格式
    	int re = dp[minpath][1];
    	printf("%d", minpath);
    	for (int i=1; i<col; ++i)
        {
        	minpath = next[minpath][i];
        	printf(" %d", minpath);
        }
    	printf("\n%d\n", re);
    }
    return 0;
}
