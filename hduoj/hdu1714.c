#include<stdio.h>
#include<math.h>

int main(void)
{
	int n;
	double a, b, x, y;
	double s;
	int i;
	
	scanf("%d", &n);
	for (i=0; i<n; ++i)
	{
		scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
		s = a*b/2*atan(fabs(y)/x*a/b);    // ×¢Òâ¸ººÅ
		printf("%.2f\n", s);
	}

	return 0;
}
