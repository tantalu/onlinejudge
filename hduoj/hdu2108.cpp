#include<cstdio>
#include<vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> x, y;
	int xx, yy;
	int flag;
	int i;

	while (scanf("%d", &n)!=EOF && n!=0)
	{
		x.clear();
		y.clear();
		for (i=0; i<n; ++i)
		{
			scanf("%d%d", &xx, &yy);
			x.push_back(xx);
			y.push_back(yy);
		}
		x.push_back(x[0]);
		y.push_back(y[0]);
		x.push_back(x[1]);
		y.push_back(y[1]);

		flag = 0;
		for (i=1; i<=n; ++i)
		{
			flag |= ((x[i+1]-x[i])*(y[i-1]-y[i]) - (x[i-1]-x[i])*(y[i+1]-y[i])< 0);
		}
		if (flag==0)
		{
			printf("convex\n");
		}
		else
		{
			printf("concave\n");
		}
	}

    return 0;
}
