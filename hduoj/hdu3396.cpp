// �����ȼ������ȱ����ʱ���Եõ�������������Ȼ��һ��һ��ȥ������ȥ���ܵõ�����Ŀ
// Ҫʹ���ݳ�ԭ��
// 1 2 3 4 5 6  7  8  9 10 11 12  13  14  15
//       1 2 4  6  9 12 16 20 25  30  36  42
//       1 3 7 13 22 34 50 70 95 125 161 203
// ��������������(n-1)(n-3)/4��ż������(n-2)(n-2)/4������ͳһΪ(n-1)/2*(n-2)/2�����������������
//
// ����Ϊm�İ��ӹ��ɵ��������У�
// mΪ��̵���((n-m-1) + (n-m-1)-(m-2))*(m-1)/2
// mΪ�м䳤�ȵ�Ϊ(m-1)(m-2)
// mΪ�����(m-1)/2*(m-2)/2
// ����ɵ�����Ϊ(m+o)-(m-o)-(o>m-o?3:2) (o<m)
// ������ɵı������ң�Ҳ������������
// �ܸ��Ӷ�O(m^2logm)
// AC��100��~

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
		
		// 1~n ��ɵĸ���
		long long p = (n - 2) / 2;
		long long q = (n - 1) / 2;
		long long all = 0;
		all += p*(p+1)%mod *(2*p+1)%mod *166666668%mod;
		all += (q-1)*q%mod *(q+1)%mod *333333336%mod;
		
		sort(miss, miss+m);
		// ʹ��һ��
		for (int i=0; i<m; ++i)
		{
			// miss[i] ����̱�
			all -= (max(n-miss[i]-1, 0ll) + max((n-miss[i]-1)-(miss[i]-2), 1ll)) * min(miss[i]-1, n-miss[i]-1) / 2 %mod;
			// �м䳤�ȱ�
			all -= (miss[i]-1) * (miss[i]-2) / 2 %mod - max(2*miss[i]-2 - n, 0ll) * max(2*miss[i]-1 - n, 0ll) / 2 %mod;
			// ���
			all -= ((miss[i]-1)/2) * ((miss[i]-2)/2) %mod;

			// ʹ������
			for (int j=i+1; j<m; ++j)
			{
				all += min(miss[i]+miss[j], n+1) - (miss[j]-miss[i]) - 1;
				--all; //miss[i] miss[j] miss[j]
				if (miss[i] > miss[j]-miss[i]) //miss[i] miss[i] miss[j]
				{
					--all;
				}
				
				// ʹ��������
				all -= lower_bound(miss, miss+m, miss[i]+miss[j]) - (miss+j+1);
			}
			all %= mod; // ע������
		}
		all = (all + mod) % mod;
		printf("Case %d: %I64d\n", i, all);
	}
 	return 0;
}
