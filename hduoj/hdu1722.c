#include<stdio.h>

int cut(int p, int q)
{
	int t;
	if (p>q)
	{
		t = p;
		p = q;
		q = t;
	}
	
	if (q%p==0)
	{
		return q;
	}
	else
	{
		return q/p*p+cut(q%p, p);
	}
}

int main(void)
{
	int p, q;

	while(scanf("%d%d", &p, &q) != EOF)	// 日了狗了这输入和输出
		printf("%d\n", cut(p, q));
	return 0;
}

