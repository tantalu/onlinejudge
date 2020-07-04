#include<stdio.h>
#include<string.h>

int IsPalindromes(char s[], int f, int b)
{
	while (f<b)
	{
		if (s[f++] != s[b--])
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	char s[105];
	int len;
	int n[105];
	int i, j;
	
	while (scanf("%s", s) != EOF)
	{
		len = strlen(s);
		memset(n, 0, sizeof(n));
		
		for (i=1; i<len; ++i)
		{
			n[i] = IsPalindromes(s, 0, i) ? 0 : i;
			
			for (j=0; j<=i; ++j)
			{
				if (IsPalindromes(s, j, i) && n[i] > n[j-1]+1)
				{
					n[i] = n[j-1]+1;
				}
			}
		}
		printf("%d\n", n[len-1]);
	}
	return 0;
}
