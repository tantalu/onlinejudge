// x y 可以是负数
#include<cstdio>
#include<vector>

using namespace std;

int main(void)
{
	int pow[600];
	for (int i=0; i<580; ++i)
	{
		pow[i]=i*i*i;
	}
	
	int n;
	while (scanf("%d", &n)!=EOF && n!=0)
	{
		int s = 0, t = 0;
		bool flag = false;
		for (int i=577, j=578; !flag&&i>=0; )   // 578^3-577^3>1000000
		{
			if (pow[j]-pow[i]==n)
			{
				s = -i;
				t = j;
				flag = true;
			}
			else if (pow[j]-pow[i]>n)
			{
				--j;
			}
			else
			{
				--i;
			}
		}
		for (int i=0, j=100; !flag&&i<=j; )
		{
			if (pow[i]+pow[j]==n)
			{
				s = i;
				t = j;
				flag = true;
			}
			else if (pow[i]+pow[j]>n)
			{
				--j;
			}
			else
			{
				++i;
			}
		}
		if (!flag)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d %d\n", s, t);
		}
	}
	return 0;
}
