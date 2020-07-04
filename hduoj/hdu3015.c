#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct t
{
	int x, h;
	int D, H;
} tree[100005];

long long numD[100005];
long long sumD[100005];
int n;

int cmph(const void* a, const void* b)
{
	return ((struct t*)a)->h - ((struct t*)b)->h;
}

int cmpx(const void* a, const void* b)
{
	return ((struct t*)a)->x - ((struct t*)b)->x;
}

void add(long long a[], int i, int num)
{
	while (i<=n)
	{
		a[i] += num;
		i += i&-i;
	}
}

long long find(long long a[], int i)
{
	long long re = 0;
	while (i>0)
	{
		re += a[i];
		i -= i&-i;
	}
	return re;
}

int main(void)
{
	long long re;
	int i;
	
	while (scanf("%d", &n)!=EOF)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%d%d", &tree[i].x, &tree[i].h);
		}
		
		qsort(tree, n, sizeof(struct t), cmpx);
		tree[0].D = 1;
		for (i=1; i<n; ++i)
		{
			if (tree[i].x==tree[i-1].x)
			{
				tree[i].D = tree[i-1].D;
			}
			else
			{
				tree[i].D = i+1;
			}
		}
		
		qsort(tree, n, sizeof(struct t), cmph);
		tree[0].H = 1;
		for (i=1; i<n; ++i)
		{
			if (tree[i].h==tree[i-1].h)
			{
				tree[i].H = tree[i-1].H;
			}
			else
			{
				tree[i].H = i+1;
			}
		}

		memset(numD, 0, sizeof(numD));
		memset(sumD, 0, sizeof(sumD));
		re = 0;
		for (i=n-1; i>=0; --i)
		{
			re += tree[i].H * (find(numD, tree[i].D) * tree[i].D - find(sumD, tree[i].D));
			re += tree[i].H * ((find(sumD, n) - find(sumD, tree[i].D)) - (find(numD, n) - find(numD, tree[i].D)) * tree[i].D);
			add(numD, tree[i].D, 1);
			add(sumD, tree[i].D, tree[i].D);
		}
		printf("%I64d\n", re);
	}
    return 0;
}
