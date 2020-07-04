// 对离恐怖分子的距离二分枚举 O(n^2logn)
// 首先，查询连通性不需要比较长度，一个点只过一次，没有通路时到的范围也很小，相当于做了剪枝
// 而裸的BFS对于每一点会有大量重复搜索，以查找最优值，一个极限测试用例：
// 1
// 1 1000 1000
// 0 0 999 0
// 998 0
// output:
// 1 1001
// hint:
// 0,0 -> 1,0 -> 1,999 -> 0,999
#include<cstdio>
#include<queue>

using namespace std;

struct point
{
	int x, y, dis;
};
int map[1005][1005];
int len[1005][1005];
bool visit[1005][1005];

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t-->0)
	{
		int n, x, y;
		int xi, yi, xr, yr;
		scanf("%d%d%d%d%d%d%d", &n, &x, &y, &xi, &yi, &xr, &yr);
		for (int i=0; i<x; ++i)
		{
			for (int j=0; j<y; ++j)
			{
				map[i][j] = 0xffff;
			}
		}
		
		deque<point> qp;
		point p;
		// 预处理
		for (int i=0; i<n; ++i)
		{
			scanf("%d%d", &p.x, &p.y);
			p.dis = 0;
			qp.push_back(p);
		}
		while (!qp.empty())
		{
			p = qp.front();
			qp.pop_front();
			if (p.x<0 || p.x>=x || p.y<0 || p.y>=y || p.dis>=map[p.x][p.y])
			{
				continue;
			}
			map[p.x][p.y] = p.dis;
			point po;
			po.dis = p.dis+1;
			po.y = p.y;
			po.x = p.x-1;
			qp.push_back(po);
			po.x = p.x+1;
			qp.push_back(po);
			po.x = p.x;
			po.y = p.y-1;
			qp.push_back(po);
			po.y = p.y+1;
			qp.push_back(po);
		}
		
		// 二分枚举
		int left = 0, right = x+y;
		while (left <= right)
		{
			int mid = (left+right)/2;
			// BFS
			for (int i=0; i<x; ++i)
			{
				for (int j=0; j<y; ++j)
				{
					visit[i][j] = false;
				}
			}
			bool flag = false;
			deque<point> q;
			point p;
			p.x = xi;
			p.y = yi;
			p.dis = 0;
			q.push_back(p);
			while (!q.empty())
			{
				p = q.front();
				q.pop_front();
				if (p.x<0 || p.x>=x || p.y<0 || p.y>=y || map[p.x][p.y]<mid || visit[p.x][p.y])
				{
					continue;
				}
				len[p.x][p.y] = p.dis;
				visit[p.x][p.y] = true;
				if (p.x==xr && p.y==yr)
				{
					q.clear();
					flag = true;
				}
				point po;
				po.dis = p.dis+1;
				po.x = p.x;
				po.y = p.y+1;
				q.push_back(po);
				po.y = p.y-1;
				q.push_back(po);
				po.y = p.y;
				po.x = p.x+1;
				q.push_back(po);
				po.x = p.x-1;
				q.push_back(po);
			}
			if (flag)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		printf("%d %d\n", right, len[xr][yr]);
	}
	return 0;
}
