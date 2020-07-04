#include <cstdio>

using namespace std;

int num[10] = {0};
bool used[10] = {true, false};

bool solved(const int a, const int b, const int c)
{
	int ta=0, tb=0;
	bool cused[10] = {true, false};
	
	for (int i=1; i<=a; ++i)
	{
		ta *= 10;
		ta += num[i];
	}
	for (int i=1; i<=b; ++i)
	{
		tb *= 10;
		tb += num[a+i];
	}
	int tc = ta*tb;
	
	for (int i=0; i<c; ++i)
	{
		int bit = tc%10;
		if (used[bit]||cused[bit])
		{
			return false;
		}
		cused[bit] = true;
		tc /= 10;
	}
	return tc==0;
}

int main()
{
	int a, b, c;
	int count;
	int i, j;
	
	while (scanf("%d%d%d", &a, &b, &c)!=EOF && (a||b||c))
	{
		if (!a||!b||!c||(a+b!=c && a+b!=c+1))
		{
			printf("0\n");
			continue;
		}
		
		count = 0;
		i = 1;
		while (i!=0)
		{
			j = num[i];
			if (j!=0)
			{
				used[j] = false;
			}
			while (j<10)
			{
				++j;
				if (!used[j])
				{
					num[i] = j;
					used[j] = true;
					break;
				}
			}
			if (j==10)
			{
				num[i] = 0;
				--i;
				continue;
			}
			
			if (i==a+b)
			{
				if (solved(a, b, c))
				{
					++count;
				}
			}
			else
			{
				++i;
			}
		}
		
		printf("%d\n", count);
	}
	return 0;
}
