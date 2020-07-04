#include<stdio.h>
#include<string.h>

int main(void)
{
	int n;
	int len, re[50];
	int sum, mul[100], bit;
	int i, j;

	while (scanf("%d", &n)!=EOF)
	{
		// 用2.3.4...测长度
  		sum = 0;
		for (len=0; sum+len+2<=n; ++len)
		{
			re[len] = len+2;
			sum += re[len];
		}
		if (len==1)        // 3和4的特殊情况
		{
			len = 2;
			sum = 3;
			re[0] = 1;
			re[1] = 2;
		}
		printf("%d", len);

		// 从后往前加，输出排列
		for (i=len-1; sum<n; --i)
		{
			++re[i];
			++sum;
			if (i==0)
			{
				i = len;
			}
		}
		for (i=0; i<len; ++i)
		{
			printf(" %d", re[i]);
		}
		printf("\n");
		
		// 高精度乘积
		memset(mul, 0, sizeof(mul));
		mul[0] = 1;
		bit = 1;
		for (i=0; i<len; ++i)
		{
			for (j=0; j<bit; ++j)
			{
				mul[j] *= re[i];
			}
			for (j=0; j<bit||mul[j]!=0; ++j)
			{
				mul[j+1] += mul[j]/10;
				mul[j] %= 10;
			}
			bit = j;
		}
		for (i = bit-1; i>=0; --i)
		{
			printf("%d", mul[i]);
		}
		printf("\n");
	}

    return 0;
}
