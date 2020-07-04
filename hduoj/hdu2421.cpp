// �ֽ�a^b = p_1 ^ k_1 * ... * p_m ^ k_m��
// ��(����(1^3+2^3+...+(k_i+1)^3))%10007
// ��Ŀ����˼�����������������Ӹ���M(1^3+2^3+...+N^3)%10007
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
	vector<int> prime;
	// ɸ��С��1000��������
	int n[1000] = {0};
	for (int i=2; i<1000; ++i)
	{
		if (n[i]==0)
		{
			prime.push_back(i);
			for (int j=i; j<1000; j+=i)
			{
				n[j] = 1;
			}
		}
	}
	
	int a, b;
	const int mod = 10007;
	for (int index=1; scanf("%d%d", &a, &b)!=EOF; ++index)
	{
		long long ans = 1;
		for (size_t i=0; a!=1&&i<prime.size(); ++i)
		{
			int j;
			for (j=0; a%prime[i]==0; ++j)
			{
				a /= prime[i];
			}
			// ��ʽ�����
			long long re = (j*b+1) % mod;
			re = re*re*(re+1)*(re+1)/4 % mod;
			ans = ans*re % mod;
		}
		// ʣ���һ��������
		if (a!=1)
		{
			long long re = (b+1) % mod;
			re = re*re*(re+1)*(re+1)/4 % mod;
			ans = ans*re % mod;
		}
		printf("Case %d: %I64d\n", index, ans);
	}
    return 0;
}
