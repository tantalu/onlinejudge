// ������ʶ����Ŀ������֤������
#include<stdio.h>

int main(void)
{
	int t, n, a, sum;
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		sum = 0;
		while (n--)
		{
			scanf("%d", &a);
			sum += a;
		}
		printf("%d\n", sum>0?sum:0);
	}
	return 0;
}
