#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

char s[110005];
char str[220010];
int p[220010];

int manacher(void)
{
	int len = strlen(s);
	for (int i=0; i<=len; ++i)
	{
		str[2*i+2] = s[i];
	}
	len = 2*len+2;

	int id = 0;
	int maxs = 0;
	int maxl = 0;
	for (int i=1; i<len; ++i)
	{
		if (maxs > i)
		{
			p[i] = min(p[2*id-i], maxs-i);
		}
		else
		{
            p[i] = 1;
		}
		
		while (str[i-p[i]] == str[i+p[i]])
		{
			++p[i];
		}
		maxl = max(maxl, p[i]);
		
		if (maxs < p[i]+i)
		{
			maxs = p[i] + i;
			id = i;
		}
	}
	
	return maxl-1;
}

int main(void)
{
	str[0] = '@';
	for (int i=1; i<220007; i+=2)
	{
		str[i] = '#';
	}
	
	while (scanf("%s", s)!=EOF)
	{
		printf("%d\n", manacher());
	}
	return 0;
}
