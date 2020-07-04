#include<cstdio>
#include<map>

using namespace std;

const int mod = 2008;
int pow[60] = {1256};
map<int, int> ans;

int solve(int n)
{
	// 已在map中，直接返回
	map<int, int>::iterator it=ans.find(n);
	if (it!=ans.end())
	{
		return it->second;
	}

	// 总串数
	int re;
	if (n<5)
	{
		re = 1<<n;
	}
	else
	{
		re = pow[n%50];
	}
	re -= 2;     // 子串长度是1，因为不存在子串长度为n的情况
	// 枚举子串长度，类似分解质因数
	for (int i=2; i*i<=n; ++i)
	{
		if (n%i==0)
		{
			re -= solve(i);
			if (i!=n/i)    // 平方数的特殊情况
			{
				re -= solve(n/i);
			}
		    re %= mod;
		}
	}
	re = re<0 ? mod+re : re;     // 负数处理
	ans.insert(make_pair(n, re));// 记入map
	return re;
}

int main(void)
{
	// 打表算幂
	for (int i=1; i<53; ++i)
	{
		pow[i] = pow[i-1]*2 % mod;
	}
	
	ans.insert(make_pair(1, 2));
	ans.insert(make_pair(2, 2));
	int n;
	while (scanf("%d", &n)!=EOF)
	{
		printf("%d\n", solve(n));
	}
	
    return 0;
}
