#include<stdio.h>

int main(void)
{
	int n;
	long long re, com;
	int i;
	
 	while (scanf("%d", &n)!=EOF)
	{
		re = 0;
		com = 1;
		for (i=1; i<=n; ++i)
		{
			com *= n+1-i;
			com /= i;// ���鹲ѡ��i���ˣ���C(n, i)��ѡ��
			re += (i-1)*com;//��Ϊ���飬��i-1�ַַ�
		}
		printf("%I64d\n", re);
	}
	
	return 0;
}
