#include<stdio.h>

int re[25] = {0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
/*
int bit[25][25];
int count = 0;

void DFS(int n)
{
	int temp;
	int i, j;
	
	if (n>24)
	{
		return;
	}
	for (i=0; i<2; ++i)
	{
		bit[1][n] = temp = i;
		for (j=2; j<=n; ++j)
		{
			bit[j][n+1-j] = bit[j-1][n+1-j]^bit[j-1][n+2-j];
			temp += bit[j][n+1-j];
		}
		count += temp;

		if (count*2==(n+1)*n/2)
		{
			re[n]++;
		}
		DFS(n+1);

		count -= temp;
	}
}
*/
int main(void)
{
	int n;
	
	while (scanf("%d", &n)!=EOF && n!=0)
	{
		printf("%d %d\n", n, re[n]);
	}
    return 0;
}
