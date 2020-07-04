// 不是每条边都需要用
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	double r[25];
	while (scanf("%d", &n)!=EOF && n!=0)
	{
		for (int i=0; i<n; ++i)
		{
			scanf("%lf", &r[i]);
		}
		
		sort(r, r+n);
		double sum = 0.0;
		bool flag = false;
		for (int i=0; i<n; ++i)
		{
			if (sum-r[i]>-1e-6)
			{
				printf("YES\n");
				flag = true;
				break;
			}
			sum += r[i];
		}
		if (!flag)
		{
			printf("NO\n");
		}
	}
    return 0;
}
