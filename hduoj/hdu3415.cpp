#include<cstdio>
#include<climits>
#include<deque>
// 单调队列
using namespace std;

int a[100005] = {0};
int sum[200005] = {0};
deque<int> q;

int main(void)
{
	int t, n, k;
	int maxsum, start, end;
	int i, j;
		
	scanf("%d", &t);
	for (i=0; i<t; ++i)
	{
		maxsum = INT_MIN;
		q.clear();
		q.push_back(0);
		scanf("%d%d", &n, &k);
		for (j=1; j<=n; ++j)
		{
			scanf("%d", &a[j]);
			sum[j] = sum[j-1] + a[j];

			if (!q.empty() && q.front()+k <= j)// 超范围
			{
				q.pop_front();
			}
			while (!q.empty() && sum[j]-sum[q.back()-1] <= a[j])   // 单调
			{
				q.pop_back();
			}
			q.push_back(j);

			if (!q.empty() && sum[j]-sum[q.front()-1] > maxsum)
			{
				maxsum = sum[j]-sum[q.front()-1];
				start = q.front();
				end = j;
			}
		}
		
		for (; j<n+k; ++j)
		{
			sum[j] = sum[j-1] + a[j-n];

			while (!q.empty() && q.front()+k <= j)// 超范围
			{
				q.pop_front();
			}

			if (!q.empty() && sum[j]-sum[q.front()-1] > maxsum)
			{
				maxsum = sum[j]-sum[q.front()-1];
				start = q.front();
				end = j;
			}
		}
		
		printf("%d %d %d\n", maxsum, start, end>n?end%n:end);
	}
	return 0;
}