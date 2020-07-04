#include<algorithm>
#include<cstdio>

using namespace std;

int num[100005];

struct segment
{
	int l, r;
	int len;
	int s, e;
	int lenl, lenr;
} s[400005];

void refresh(int i)
{
	int mid = (s[i].l + s[i].r)/2;
	if (s[2*i].lenl == s[2*i].r-s[2*i].l+1 && num[mid] < num[mid+1])
	{
		s[i].lenl = s[2*i].lenl + s[2*i+1].lenl;
	}
	else
	{
		s[i].lenl = s[2*i].lenl;
	}
	if (s[2*i+1].lenr == s[2*i+1].r-s[2*i+1].l+1 && num[mid] < num[mid+1])
	{
		s[i].lenr = s[2*i+1].lenr + s[2*i].lenr;
	}
	else
	{
		s[i].lenr = s[2*i+1].lenr;
	}

	if (s[2*i].len < s[2*i+1].len)
	{
		s[i].len = s[2*i+1].len;
		s[i].s = s[2*i+1].s;
		s[i].e = s[2*i+1].e;
	}
	else
	{
		s[i].len = s[2*i].len;
		s[i].s = s[2*i].s;
		s[i].e = s[2*i].e;
	}
	if (num[mid] < num[mid+1] && s[i].len < s[2*i].lenr+s[2*i+1].lenl)
	{
		s[i].len = s[2*i].lenr+s[2*i+1].lenl;
		s[i].s = mid - s[2*i].lenr + 1;
		s[i].e = mid + 1 + s[2*i+1].lenl - 1;
	}
}

void build(int l, int r, int i=1)
{
	s[i].l = l;
	s[i].r = r;
	if (l == r)
	{
		s[i].len = 1;
		s[i].s = l;
		s[i].e = r;
		s[i].lenl = 1;
		s[i].lenr = 1;
		return;
	}
	
	int mid = (l + r)/2;
	build(l, mid, 2*i);
	build(mid+1, r, 2*i+1);
	refresh(i);
}

int query(int l, int r, int i=1)
{
	if (l <= s[i].l && r >= s[i].r)
	{
		return s[i].len;
	}
	
	int mid = (s[i].l + s[i].r)/2;
	if (r <= mid)
	{
		return query(l, r, 2*i);
	}
	else if (l >= mid+1)
	{
		return query(l, r, 2*i+1);
	}
	else
	{
		return max(max(query(l, mid, 2*i), query(mid+1, r, 2*i+1)),
		    num[mid]<num[mid+1] ? min(s[2*i].lenr, mid-l+1)+min(s[2*i+1].lenl, r-mid) : 0);
	}
}

void update(int n, int i=1)
{
	if (s[i].l==s[i].r)
	{
		return;
	}
	
	int mid = (s[i].l + s[i].r)/2;
	if (n<=mid)
	{
		update(n, 2*i);
	}
	else
	{
		update(n, 2*i+1);
	}
	
	refresh(i);
	return;
}


int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i)
		{
			scanf("%d", &num[i]);
		}
		build(0, n-1);

		for (int i=0; i<m; ++i)
		{
			char s[8];
			int a, b;
			scanf("%s%d%d", s, &a, &b);
			if (s[0]=='U')
			{
				num[a] = b;
				update(a);
			}
			else
			{
				printf("%d\n", query(a, b));
			}
		}
	}

	return 0;
}
