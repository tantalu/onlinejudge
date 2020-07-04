#include<algorithm>
#include<climits>
#include<cstdio>


using namespace std;

struct subject
{
	char s[110];
	int d, c;
} homework[16];

struct state
{
	int pre, now;
	int time, reduced;
} state[33000];

void print(int s)
{
	if (s != 0)
	{
		print(state[s].pre);
		printf("%s\n", homework[state[s].now].s);
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
		{
			scanf("%s%d%d", homework[i].s, &homework[i].d, &homework[i].c);
		}
		
		for (int i=1; i<1<<n; ++i)
		{
			state[i].reduced = INT_MAX;
			for (int j=0; 1<<j<=i; ++j)
			{
				int k = 1<<j;
				if ((k&i) != 0 && state[i-k].reduced + max(state[i-k].time+homework[j].c-homework[j].d, 0)<=state[i].reduced)
				{
					state[i].reduced = state[i-k].reduced + max(state[i-k].time+homework[j].c-homework[j].d, 0);
					state[i].time = state[i-k].time+homework[j].c;
					state[i].pre = i-k;
					state[i].now = j;
				}
			}
		}
		printf("%d\n", state[(1<<n)-1].reduced);
		print((1<<n)-1);
	}
	return 0;
}
