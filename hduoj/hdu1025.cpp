#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct road
{
	int p, r;
} ro[500005];

bool operator<(struct road a, struct road b)
{
	return a.p<b.p;
}

int main(void)
{
	int n;
	vector<int> des;

	for (int j=1; scanf("%d", &n) !=EOF; ++j)
	{
		for (int i=0; i<n; ++i)
		{
			scanf("%d%d", &ro[i].p, &ro[i].r);
		}
		sort(ro, ro+n);

		des.clear();
		for (int i=0; i<n; ++i)
		{
			if (des.empty() || ro[i].r>des.back())
			{
				des.push_back(ro[i].r);
			}
			else
			{
				*upper_bound(des.begin(), des.end(), ro[i].r) = ro[i].r;
			}
		}
		// 这输出真特么恶心
		if (des.size()==1)
		{
			printf("Case %d:\nMy king, at most 1 road can be built.\n\n", j);
		}
		else
		{
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n", j, des.size());
		}
	}

    return 0;
}
