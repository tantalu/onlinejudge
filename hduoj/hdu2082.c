#include<stdio.h>
#include<string.h>

int main(void)
{
	int num[60];
	int x[30];
	int n;
	long long ans;
	int i, j, k;
	
	scanf("%d", &n);
	while (n--)
	{
		memset(num, 0, sizeof(num));
		num[0] = 1;
		for (i=1; i<27; ++i) // ��ĸ
		{
			scanf("%d", &x[i]);
			for (j=50; j>=i; --j) // ��ֵ
			{
				for (k=1; k<=x[i] && j>=i*k; ++k) // ѡ����
				{
					num[j] += num[j-i*k];
				}
			}
		}
		
		ans = 0;
		for (i=1; i<=50; ++i)
		{
			ans += num[i];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
