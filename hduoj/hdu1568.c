#include<math.h>
#include<stdio.h>

int main(void)
{
	int n;
	double re;
	double sq = sqrt(5);
	int fibo[20] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};
	
	while (scanf("%d", &n)!=EOF)
	{
		if (n<20)
		{
			printf("%d\n", fibo[n]);
		}
		else
		{
			re = -log10(sq) + n*log10((1+sq)/2);`// 近似通项公式，把后面一项舍掉了
			printf("%d\n", (int)(1000*pow(10, re-(int)re)));
		}
	}

    return 0;
}
