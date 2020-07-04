#include<stdio.h>
#include<string.h>

int main(void)
{
	char a[205], b[205], c[205];
	int la, lb, lc;
	int i;
	
	while (scanf("%s%s", a, b) != EOF)
	{
		memset(c, 0, sizeof(c));
		
		la = strlen(a);
		for (i=0; i<la; ++i)
		{
			c[la-1-i] += a[i] - 'A';
		}
		lb = strlen(b);
		for (i=0; i<lb; ++i)
 		{
			c[lb-1-i] += b[i] - 'A';
		}
		
		lc = (la>lb?la:lb) + 1;
		for (i=0; i<lc; ++i)
		{
			if (c[i]>25)
			{
				c[i+1] += c[i]/26;
				c[i] %= 26;
			}
		}
		for (; c[i]==0; --i)
			;
		for (; i>=0; --i)
		{
			printf("%c", 'A'+c[i]);
		}
		printf("\n");
	}
	return 0;
}
