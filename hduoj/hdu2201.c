// P(n, m) = C(n-1, m-1)/C(n, m-1) * 1/n-m+1 = 1/n
//           前面人空下自己的座位   自己坐对
#include<stdio.h>

int main(void)
{
	int n, m;
	
	while (scanf("%d%d", &n, &m)!=EOF)
	{
		printf("%.2f\n", 1.0/n);
	}

    return 0;
}
