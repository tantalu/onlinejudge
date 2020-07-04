// Calatan number
// C_n = C(2n, n) / (n+1)
//     = C_0*C_n-1 + C_1*C_n-2 + ... + C_n-1*C_0
#include<stdio.h>
#include<string.h>

int main(void)
{
	int n;
	int len[105] = {1};
	int c[105][60] = {{1}};
	int mul[60];
	int i, j, k, l;
	
	for (i=1; i<=100; ++i)
	{
		for (j=0; j<i; ++j)
		{
			memset(mul, 0, sizeof(mul));
			// mul = a[j] * a[i-1-j]
			for (k=len[j]-1; k>=0; --k)
			{
				for (l=len[i-1-j]-1; l>=0; --l)
				{
					mul[k+l] += c[j][k] * c[i-1-j][l];
				}
			}
			// a[i] += mul
			for (k=0; k<len[j]+len[i-1-j]; ++k)
			{
				c[i][k] += mul[k];
			}
		}
		for (k=0; c[i][k]!=0; ++k)
		{
			if (c[i][k]>9)
			{
				c[i][k+1] += c[i][k]/10;
				c[i][k] %= 10;
			}
		}
		len[i] = k;
		//for (k=len[i]-1; k>=0; --k)printf("%d", c[i][k]);printf(" %d\n", len[i]);
	}
	
	while (scanf("%d", &n) !=EOF)
	{
		for (i=len[n]-1; i>=0; --i)
		{
			printf("%d", c[n][i]);
		}
		printf("\n");
	}
    return 0;
}
