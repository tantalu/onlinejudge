#include<stdio.h>

int main(void)
{
	int n;
	double ax, ay, bx, by, cx, cy;

	while (scanf("%d", &n)!=EOF && n!=0)
	{
		while (n-- != 0)
		{
			scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
			printf("%.1f %.1f\n", (ax+bx+cx)/3, (ay+by+cy)/3);
		}
	}
	return 0;
}
