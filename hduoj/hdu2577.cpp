#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cstring>

using namespace std;

int dp[105][2] = {{0,1}};

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t-->0)
	{
		char str[105];
		scanf("%s", str+1);
		
		int len = strlen(str+1);
		for (int i=1; i<=len; ++i)
		{
			if (isupper(str[i]))
			{
				dp[i][0] = min(dp[i-1][0]+2, dp[i-1][1]+2);// shift+ch    ch+Capslock
				dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+1);// Capslock+ch ch
			}
			else
			{
				dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]+2);// ch          Capslock+ch
				dp[i][1] = min(dp[i-1][0]+2, dp[i-1][1]+2);// ch+Capslock shift+ch
			}
		}
		printf("%d\n", min(dp[len][0], dp[len][1]+1));
	}
	return 0;
}
