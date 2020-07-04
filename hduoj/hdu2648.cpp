#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

int main(void)
{
	int n;
	while (cin >> n)
	{
		map<string, int> shops;
		string str;
		for (int i=0; i<n; ++i)
		{
			cin >> str;
			shops.insert(make_pair(str, 0));
		}
		int m;
		cin >> m;
		for (int j=0; j<m; ++j)
		{
			int a[10005];
			int memory;
			for (int i=0; i<n; ++i)
			{
				cin >> a[i] >> str;
				map<string, int>::iterator it = shops.find(str);
				a[i] += shops.find(str)->second;  // 是涨价不是涨到= =
				it->second = a[i];                // 保存新价格
				if (str == "memory")
				{
					memory = a[i];
				}
			}
			sort(a, a+n);
			cout << (a+n+1) - upper_bound(a, a+n, memory) << endl;
		}
		shops.clear();
	}
	return 0;
}
