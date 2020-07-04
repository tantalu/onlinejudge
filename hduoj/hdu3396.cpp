// 考虑先计算出不缺棒子时可以得到的三角形数，然后一根一根去掉，减去不能得到的数目
// 要使用容斥原理
// 1 2 3 4 5 6  7  8  9 10 11 12  13  14  15
//       1 2 4  6  9 12 16 20 25  30  36  42
//       1 3 7 13 22 34 50 70 95 125 161 203
// 增加量奇数项是(n-1)(n-3)/4，偶数项是(n-2)(n-2)/4，可以统一为(n-1)/2*(n-2)/2，容易求个和算总数
//
// 长度为m的棒子构成的三角形中，
// m为最短的有((n-m-1) + (n-m-1)-(m-2))*(m-1)/2
// m为中间长度的为(m-1)(m-2)
// m为最长的有(m-1)/2*(m-2)/2
// 由组成的两根为(m+o)-(m-o)-(o>m-o?3:2) (o<m)
// 三根组成的暴力查找，也可以排序后二分
// 总复杂度O(m^2logm)
// AC第100题~

#include<algorithm>
#include<cstdio>

using namespace std;

const long long mod = 1000000007;

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; ++i)
	{
		long long n;
		int m;
		scanf("%I64d%d", &n, &m);
		long long miss[1000];
		for (int j=0; j<m; ++j)
		{
			scanf("%I64d", &miss[j]);
		}
		
		// 1~n 组成的个数
		long long p = (n - 2) / 2;
		long long q = (n - 1) / 2;
		long long all = 0;
		all += p*(p+1)%mod *(2*p+1)%mod *166666668%mod;
		all += (q-1)*q%mod *(q+1)%mod *333333336%mod;
		
		sort(miss, miss+m);
		// 使用一根
		for (int i=0; i<m; ++i)
		{
			// miss[i] 做最短边
			all -= (max(n-miss[i]-1, 0ll) + max((n-miss[i]-1)-(miss[i]-2), 1ll)) * min(miss[i]-1, n-miss[i]-1) / 2 %mod;
			// 中间长度边
			all -= (miss[i]-1) * (miss[i]-2) / 2 %mod - max(2*miss[i]-2 - n, 0ll) * max(2*miss[i]-1 - n, 0ll) / 2 %mod;
			// 最长边
			all -= ((miss[i]-1)/2) * ((miss[i]-2)/2) %mod;

			// 使用两根
			for (int j=i+1; j<m; ++j)
			{
				all += min(miss[i]+miss[j], n+1) - (miss[j]-miss[i]) - 1;
				--all; //miss[i] miss[j] miss[j]
				if (miss[i] > miss[j]-miss[i]) //miss[i] miss[i] miss[j]
				{
					--all;
				}
				
				// 使用三根，
				all -= lower_bound(miss, miss+m, miss[i]+miss[j]) - (miss+j+1);
			}
			all %= mod; // 注意这里
		}
		all = (all + mod) % mod;
		printf("Case %d: %I64d\n", i, all);
	}
 	return 0;
}
