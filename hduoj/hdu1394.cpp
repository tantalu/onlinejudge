#include<cstdio>
#include<cstring>

using namespace std;

int num[5005];
int bit[5005];
int len;

void add(int i, int n)
{
	for (; i<=len; i+=i&-i)
	{
		bit[i] += n;
	}
}

int sum(int i)
{
	int re = 0;
	for (; i>0; i-=i&-i)
	{
		re += bit[i];
	}
	return re;
}

int main(void)
{
	while (scanf("%d", &len)!=EOF)
	{
		for (int i=1; i<=len; ++i)
		{
			scanf("%d", &num[i]);
		}
		
		// ÇóÄæÐòÊý
		memset(bit, 0, sizeof(bit));
		int ans = 0;
		for (int i=1; i<=len; ++i)
		{
			int inv = i-1-sum(num[i]+1);
			add(num[i]+1, 1);
			ans += inv;
		}

		int min = ans;
		for (int i=len; i>0; --i)
		{
			ans += 2*num[i]-len+1;
			if (min>ans)
			{
				min = ans;
			}
		}
		printf("%d\n", min);
	}
    return 0;
}
