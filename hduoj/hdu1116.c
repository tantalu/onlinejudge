// 有向图的欧拉通路问题，先要判断连通性，然后计算出入度的差
#include<stdio.h>
#include<string.h>

int father[128];

int find(int a)
{
	if (a==father[a])
	{
		return a;
	}
	else
	{
		return father[a] = find(father[a]);
	}
}

int Union(int a, int b)
{
	int fa = find(a);
	int fb = find(b);
	if (fa!=fb)
	{
		father[fb] = fa;
		return 1;
	}
	return 0;
}

int main(void)
{
	int count[128], visit[128], t, n;
	char str[1005];
	int a = 0, b = 0;
	int odd, flag, f;
	int i, j;
	
	scanf("%d", &t);
	for (i=0; i<t; ++i)
	{
		for (j=0; j<128; ++j)
		{
			count[j] = 0;
			father[j] = j;
			visit[j] = 0;
		}
		
		scanf("%d", &n);
		for (j=0; j<n; ++j)
		{
			scanf("%s", str);
			a = str[0];
			b = str[strlen(str)-1];
			count[a]--;
			count[b]++;
			visit[a] = 1;
			visit[b] = 1;
			Union(a, b);
		}
		
		odd = 0;
		flag = 0;
		f = find(a);
		for (j=0; j<128; ++j)
		{
			if (visit[j])
			{
				if (find(j)!=f)
				{
					flag = 1;
					break;
				}
				else
				{
					odd += count[j]>=0 ? count[j] : -count[j];
				}
			}
		}
		if (!flag && odd<=2)
		{
			printf("Ordering is possible.\n");
		}
		else
		{
			printf("The door cannot be opened.\n");
		}
	}

    return 0;
}
