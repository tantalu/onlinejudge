#include<stdio.h>
#include<string.h>

int U[505][505];
int W[505][505];
int maxU[505];
int maxW[505];

int main(void)
{
	int t, x, y;
	int i, j, k;
	int re, u, w;
	
	scanf("%d", &t);
	for (k=0; k<t; ++k)
	{
		memset(maxU, 0, sizeof(maxU));
		memset(maxW, 0, sizeof(maxW));
		
		scanf("%d%d", &x, &y);
		for (i=0; i<x; ++i)
		{
			for (j=0; j<y; ++j)
			{
				scanf("%d", &U[i][j]);
				if (U[i][j]>maxU[j])
				{
					maxU[j] = U[i][j];  // W做j决策时最大收益
				}
			}
		}
		for (i=0; i<y; ++i)
		{
			for (j=0; j<x; ++j)
			{
				scanf("%d", &W[i][j]);
				if (W[i][j]>maxW[j])
				{
					maxW[j] = W[i][j];
				}
			}
		}
		
		re = 0;
		for (i=0; i<x; ++i)
		{
			for (j=0; j<y; ++j)
			{
				if (maxU[j]==U[i][j] && maxW[i]==W[j][i])
				{
					++re;
					u = i;
					w = j;
				}
			}
		}
		
		if (re==1)
		{
			printf("%d %d\n", U[u][w], W[w][u]);
		}
		else
		{
			printf("Have %d Nash Points.\n", re);
		}
	}

    return 0;
}

