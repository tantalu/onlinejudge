#include<stdio.h>
#include<math.h>

const double pi = 3.141592653589793;

int main(void)
{
	double x1, y1, x2, y2, x3, y3;
	double a, b, c;
	double d, s, p;
	
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) !=EOF)
	{
		a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		b = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		c = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
		p = (a+b+c)/2;
		
		s = sqrt(p*(p-a)*(p-b)*(p-c));            // helen
		d = a*b*c/2/s;                            // R = abc / 4s
		
		printf("%.2f\n", d*pi);
	}

	return 0;
}
