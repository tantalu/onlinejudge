#include<stdio.h>
#include<string.h>

int a[30][30];
int visit[30];

int DFS(int i)
{
	int j;
	
	visit[i] = 1;
	if (i=='m'-'a')
	{
		return 1;
	}
	for (j=0; j<26; ++j)
	{
		if (visit[j]==0 && a[i][j]==1 && DFS(j))
		{
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	char str[105];
	int len;
	
	memset(a, 0, sizeof(a));
	while (scanf("%s", str)!=EOF)
	{
		if (str[0]=='0')
		{
			memset(visit, 0, sizeof(visit));
   			if (DFS('b'-'a'))
			{
				printf("Yes.\n");
			}
			else
			{
				printf("No.\n");
			}
			memset(a, 0, sizeof(a));
		}
		else
		{
			len = strlen(str);
			a[str[0]-'a'][str[len-1]-'a'] = 1;
		}
	}

    return 0;
}
