// 凹凸性不变的函数三分法求极值
#include<stdio.h>

double f(double x, double y)
{
	return ((((6*x+8)*x*x*x+7)*x+5)*x-y)*x;
}

int main(void)
{
	int t;
	double y, l, r, ml, mr;
	int i;
	
	scanf("%d", &t);
	for (i=0; i<t; ++i)
	{
		scanf("%lf", &y);
		l = 0;
		r = 10;
		while (r-l>0.0000001)
		{
			ml = (l+r)/2;
			mr = (ml+r)/2;
			if (f(ml, y) < f(mr, y))
			{
				r = mr;
			}
			else
			{
				l = ml;
			}
		}
		printf("%.4f\n", f(l, y));
	}

	return 0;
}
