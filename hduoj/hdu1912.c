#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct s
{
	double l, r;
};

int cmp(const void* a, const void* b)
{
	struct s* pa = (struct s*)a;
	struct s* pb = (struct s*)b;
	if (pa->r < pb->r)
	{
		return -1;
	}
	return 1;
}

int main(void)
{
	int len, d, n;
	struct s s[50005];
	int re;
	int x, y;
	double e;
	int i;
	
	while (scanf("%d%d%d", &len, &d, &n)!=EOF)
	{
		for (i=0; i<n; ++i)
		{
			scanf("%d%d", &x, &y);
			s[i].r = x+sqrt(d*d-y*y);
			s[i].l = x-sqrt(d*d-y*y);

		}

		qsort(s, n, sizeof(struct s), cmp);
		re = 0;
		for (i=0; i<n; )
		{
			e = s[i].r;
			++re;
			for (++i; i<n&&s[i].l<=e&&s[i].r>=e; ++i)
			{
				;
			}
		}
		printf("%d\n", re);
	}

    return 0;
}
