// DP+SegmentTree
#include<cstdio>
#include<algorithm>

using namespace std;

int dp[100005];

struct plank
{
    int h, l, r, v;
    int lnext, rnext;
} p[100005];
bool operator<(plank a, plank b)
{
    return a.h<b.h;
}

struct tree
{
     int l, r, v;
} t[300005];
void build(int p, int l, int r, int v)
{
    t[p].l = l;
    t[p].r = r;
    t[p].v = v;
    if (l!=r)
    {
        int mid = (l+r)/2;
        build(p*2, l, mid, v);
        build(p*2+1, mid+1, r, v);
    }
}

void insert(int p, int l, int r, int v)
{
     if (t[p].l==l && t[p].r==r)
    {
        t[p].v = v;
        return;
    }
    if (t[p].v!=-1)
    {
        t[2*p].v = t[2*p+1].v = t[p].v;
    }
    t[p].v = -1;
    int mid = (t[p].l+t[p].r)/2;
    if (l>mid)
    {
        insert(2*p+1, l, r, v);
    }
    else if (r<=mid)
    {
        insert(2*p, l, r, v);
    }
    else
    {
        insert(2*p, l, mid, v);
        insert(2*p+1, mid+1, r, v);
    }
}

int query(int p, int v)
{
    if (t[p].v!=-1)
    {
        return t[p].v;
    }
    int mid = (t[p].l+t[p].r)/2;
    if (v<=mid)
    {
        return query(2*p, v);
    }
    else
    {
        return query(2*p+1, v);
    }
}

int main(void)
{
    p[0].h = 0;
    p[0].l = 0;
    p[0].r = 100000;
    p[0].v = 0;
    int n;
    while (scanf("%d", &n)!=EOF)
    {        
        for (int i=1; i<=n; ++i)
        {
            scanf("%d%d%d%d", &p[i].h, &p[i].l, &p[i].r, &p[i].v);
        }

        // 自高到低排序，自底向上找出从两端下落到的板
        sort(p+1, p+n+1);
        build(1, 1, 100000, 0);
        for (int i=1; i<=n; ++i)
        {
            p[i].lnext = query(1, p[i].l);
            p[i].rnext = query(1, p[i].r);
            insert(1, p[i].l, p[i].r, i);
            dp[i] = 0;
        }

        // 自顶向下选路，注意<=0时就挂了
        dp[0] = 0;
        dp[n] = 100+p[n].v;
        for (int i=n; i>0; --i)
        {
            if (dp[i]>0)
            {
                dp[p[i].lnext] = max(dp[p[i].lnext], dp[i]+p[p[i].lnext].v);
                dp[p[i].rnext] = max(dp[p[i].rnext], dp[i]+p[p[i].rnext].v);
            }
        }
        printf("%d\n", dp[0]>0?dp[0]:-1);
    }
    return 0;
}