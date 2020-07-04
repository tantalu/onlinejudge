#include<cstdio>
#include<map>

using namespace std;

const int mod = 2008;
int pow[60] = {1256};
map<int, int> ans;

int solve(int n)
{
	// ����map�У�ֱ�ӷ���
	map<int, int>::iterator it=ans.find(n);
	if (it!=ans.end())
	{
		return it->second;
	}

	// �ܴ���
	int re;
	if (n<5)
	{
		re = 1<<n;
	}
	else
	{
		re = pow[n%50];
	}
	re -= 2;     // �Ӵ�������1����Ϊ�������Ӵ�����Ϊn�����
	// ö���Ӵ����ȣ����Ʒֽ�������
	for (int i=2; i*i<=n; ++i)
	{
		if (n%i==0)
		{
			re -= solve(i);
			if (i!=n/i)    // ƽ�������������
			{
				re -= solve(n/i);
			}
		    re %= mod;
		}
	}
	re = re<0 ? mod+re : re;     // ��������
	ans.insert(make_pair(n, re));// ����map
	return re;
}

int main(void)
{
	// �������
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
