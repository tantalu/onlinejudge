#include<stdio.h>
#include<math.h>

int main(void)
{
	const double pi = 2*asin(1);
	double n, m, r, h, v;

	while (scanf("%lf%lf", &n, &m)!=EOF && (n||m))
	{
		v = 0;

		// d+c<b r==h/2时最大
		if (n<m/(1+pi))
		{
			r = n/2;
		}
		else
		{
			r = m/(2+2*pi);
		}
		h = n;
		v = pi*r*r*h;

		// d+h==b h==r时最大
		if (m/3<n/2/pi)
		{
			r = m/3;
		}
		else
		{
			r = n/2.0/pi;
		}
		h = m-2*r;
		if (pi*r*r*h>v)
		{
			v = pi*r*r*h;
		}
		printf("%.3lf\n", v);
	}

    return 0;
}
