#include<stdio.h>

int main(void)
{
	int n, k, l;
	char key[100], alph[100];
	int price[100][100];
	int sum[100][100];
	int index[100][100];
	int len[100];
	int i, j, p, q;
	
	scanf("%d", &n);
	for (i=1; i<=n; ++i)
	{
		scanf("%d%d", &k, &l);
		scanf("%s%s", key, alph);
		for (j=0; j<l; ++j)
		{
			scanf("%d", &sum[j][j]);
			for (p=0; p<j; ++p)
			{
				sum[p][j] = sum[p][j-1] + (j-p+1)*sum[j][j];
			}
		}
		
		for (p=0; p<l; ++p)
		{
			index[0][p] = p+1;
			price[0][p] = sum[0][p];
		}
		for (j=1; j<k; ++j)        	// 按键数
		{
			index[j][j] = 1;
			price[j][j] = price[j-1][j-1] + sum[j][j];
			for (p=j+1; p<l; ++p)    // 字母数
			{
				index[j][p] = index[j][p-1]+1;
				price[j][p] = price[j][p-1] + index[j][p]*sum[p][p];
				// 最后一组长度
				for (q=index[j][p-1]; q>0; --q)
				{
					if (price[j-1][p-q]+sum[p-q+1][p] < price[j][p])
					{
						index[j][p] = q;
						price[j][p] = price[j-1][p-q] + sum[p-q+1][p];
					}
				}
			}
		}

		for (j=k-1, p=l-1; j>=0; p-=index[j][p], --j)
		{
			len[j] = index[j][p];
		}
		printf("Keypad #%d:\n", i);
		for (j=0, q=0; j<k; ++j)
		{
			printf("%c: ", key[j]);
			for (p=0; p<len[j]; ++p)
			{
				printf("%c", alph[q]);
				++q;
			}
			printf("\n");
		}
		printf("\n");
	}
    return 0;
}
